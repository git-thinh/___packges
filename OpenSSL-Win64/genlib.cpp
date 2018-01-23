#include <windows.h>
#include <stdio.h>

enum arch
{
    invalid,
    x32,
    x64
};

arch GetFileArchitecture(const char* szFileName)
{
    HANDLE hFile=CreateFileA(szFileName, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, 0, 0);
    if(hFile==INVALID_HANDLE_VALUE)
        return invalid;
    unsigned char data[0x1000];
    DWORD read=0;
    if(!ReadFile(hFile, data, sizeof(data), &read, 0))
    {
        CloseHandle(hFile);
        return invalid;
    }
    CloseHandle(hFile);
    IMAGE_DOS_HEADER* pdh=(IMAGE_DOS_HEADER*)data;
    if(pdh->e_magic!=IMAGE_DOS_SIGNATURE)
        return invalid;
    if((size_t)pdh->e_lfanew>=sizeof(data))
        return invalid;
    IMAGE_NT_HEADERS* pnth=(IMAGE_NT_HEADERS*)(data+pdh->e_lfanew);
    if(pnth->Signature!=IMAGE_NT_SIGNATURE)
        return invalid;
    if((pnth->FileHeader.Characteristics&IMAGE_FILE_DLL)!=IMAGE_FILE_DLL) //only DLL files are allowed
        return invalid;
    if(pnth->FileHeader.Machine==IMAGE_FILE_MACHINE_I386) //x32
        return x32;
    else if(pnth->FileHeader.Machine==IMAGE_FILE_MACHINE_AMD64) //x64
        return x64;
    return invalid;
}

//genlib file.dll
int main(int argc, char* argv[])
{
    if(argc<2)
    {
        puts("usage: genlib.exe file.dll");
        return 0;
    }
    arch fileArch=GetFileArchitecture(argv[1]);
    if(fileArch==invalid)
    {
        puts("invalid dll...");
        return 0;
    }
    char szNewPath[MAX_PATH]="";
    int i=GetModuleFileNameA(GetModuleHandleA(0), szNewPath, MAX_PATH);
    while(szNewPath[i]!='\\' && i)
        i--;
    if(!i)
    {
        puts("path problem...");
        return 0;
    }
    szNewPath[i]='\0';
    strcat(szNewPath, "\\tools");
    SetEnvironmentVariableA("PATH", szNewPath);
    char szBaseFileName[MAX_PATH]="";
    strcpy(szBaseFileName, argv[1]);
    const char* basefile=strrchr(szBaseFileName, '\\');
    if(basefile)
        strcpy(szBaseFileName, basefile+1);
    char szFile[256]="";
    strcpy(szFile, szBaseFileName);
    char* ext=strrchr(szBaseFileName, '.');
    if(ext)
        *ext='\0';
    char command[256]="";
    sprintf(command, "gendef %s %s", argv[1], szBaseFileName);
    system(command);
    char szDefPath[MAX_PATH]="";
    sprintf(szDefPath, "%s.def", szBaseFileName);
    HANDLE hFile=CreateFileA(szDefPath, GENERIC_READ|GENERIC_WRITE, 0, 0, OPEN_EXISTING, 0, 0);
    if(hFile==INVALID_HANDLE_VALUE)
    {
        puts("gendef failed...");
        return 0;
    }
    unsigned int filesize=GetFileSize(hFile, 0);
    char* data=(char*)malloc(filesize+1);
    if(!data)
    {
        CloseHandle(hFile);
        puts("malloc failed...");
        return 0;
    }
    memset(data, 0, filesize+1);
    DWORD read=0;
    if(!ReadFile(hFile, data, filesize, &read, 0))
    {
        free(data);
        CloseHandle(hFile);
        puts("ReadFile failed...");
        return 0;
    }
    const char* newdata=strstr(data, "EXPORTS");
    if(!newdata)
    {
        free(data);
        CloseHandle(hFile);
        puts("invalid .def format...");
        return 0;
    }
    filesize=strlen(newdata);
    SetFilePointer(hFile, 0, 0, FILE_BEGIN);
    SetEndOfFile(hFile);
    DWORD written=0;
    char libText[2048]="";
    sprintf(libText, "LIBRARY \"%s\"\r\n", szBaseFileName);
    if(!WriteFile(hFile, libText, strlen(libText), &written, 0))
    {
        free(data);
        CloseHandle(hFile);
        puts("WriteFile failed...");
        return 0;
    }
    if(!WriteFile(hFile, newdata, filesize, &written, 0))
    {
        free(data);
        CloseHandle(hFile);
        puts("WriteFile failed...");
        return 0;
    }
    free(data);
    CloseHandle(hFile);
    if(fileArch==x32)
        sprintf(command, "dlltool --as-flags=--32 -m i386 -k --output-lib %s.a --input-def %s.def", szBaseFileName, szBaseFileName);
    else
        sprintf(command, "dlltool --as-flags=--64 -m i386:x86-64 -k --output-lib %s.a --input-def %s.def", szBaseFileName, szBaseFileName);
    system(command);
    sprintf(command, "del %s.def", szBaseFileName);
    //system(command);
    return 0;
}
