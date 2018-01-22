Tutorial build: 

	> mingw32-make makefile.in 
	> make makefile.in

*MingW: mingw-w64-x86_64-gcc7.2.0-win32-sjlj

*zlib:	
	> @rem You can also do just "git clone --recursive -b THE_BRANCH_YOU_WANT https://github.com/grpc/grpc"
	> powershell git clone --recursive -b ((New-Object System.Net.WebClient).DownloadString(\"https://grpc.io/release\").Trim()) https://github.com/grpc/grpc
	> cd grpc
	> @rem To update submodules at later time, run "git submodule update --init"
	
	> cd && git clone https://github.com/grpc/grpc.git
	> mkdir _build
	> cd _build
	
	> git submodule init
	> git submodule update
	
	> cmake .. -G "MinGW Makefiles"
	
	> cmake .. -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release
	> cmake .. -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release
	
	> mingw32-make install