

::gcc -shared -o testdll.dll testdll.c -Wl,--output-def,testdll.def,--out-implib,libtestdll.a

g++ -I"E:/___packges/protobuf-lx_ming/include" -L"E:/___packges/protobuf-lx_ming/" main.cpp addressbook.pb.cc -lprotobuf -pthread -static-libgcc -std=c++11
:: dlltool -U -d libprotobuf.def -l libprotobuf.a

:: reimp libprotobuf.lib | sed 's/_//' >> libprotobuf.def
:: dlltool -k --def libprotobuf.def --output-lib libprotobuf.a --dllname libprotobuf.dll

:: reimp libprotobuf.lib          # this generates several .o or .obj files.
:: ar rcs libprotobuf.a *.obj  # add them to library

::gendef libprotobuf.dll
::dlltool --as-flags=--64 -m i386:x86-64 -k --output-lib libprotobuf.a --input-def libprotobuf.def

