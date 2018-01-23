Tutorial build: 
	> cd && git clone https://github.com/GRPC/GRPC.git 
	> mingw32-make
	> mingw32-make install
	
	> cmake -G "MinGW Makefiles" -DgRPC_INSTALL=ON -DgRPC_BUILD_TESTS=OFF -DgRPC_PROTOBUF_PROVIDER=package -DgRPC_ZLIB_PROVIDER=package -DgRPC_CARES_PROVIDER=package -DgRPC_SSL_PROVIDER=package -DCMAKE_BUILD_TYPE=Release
		
	> cmake -G "MSYS Makefiles" -DCMAKE_INSTALL_PREFIX=C:/mingw-w64-x86_64-7.2.0-win32-sjlj/mingw64 -DCMAKE_BUILD_TYPE=DEBUG
		
	> mingw32-make makefile.in 
	> make makefile.in

*MingW: mingw-w64-x86_64-gcc7.2.0-win32-sjlj

*zlib:	
	> @rem You can also do just "git clone --recursive -b THE_BRANCH_YOU_WANT https://github.com/grpc/grpc"
	> powershell git clone --recursive -b ((New-Object System.Net.WebClient).DownloadString(\"https://grpc.io/release\").Trim()) https://github.com/grpc/grpc
	> cd grpc
	> @rem To update submodules at later time, run "git submodule update --init"
	
	> git clone https://github.com/grpc/grpc.git && cd grpc
	
	> git submodule init
	> git submodule update
	
	> mkdir _build
	> cd _build
	
	> cmake .. -G "MinGW Makefiles"
	
	$ mkdir _build && cd _build
	$ CROSS_COMPILE="x86_64-w64-mingw32-" ./_build mingw64 no-asm shared --prefix=/usr/mw64
	$ PATH=$PATH:/usr/mw64/bin make
	$ PATH=$PATH:/usr/mw64/bin make install
	
	> cmake .. -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release
	> cmake .. -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release
	
	> mingw32-make install
	
	mingw-w64-x86_64-grpc-1.7.2-1
