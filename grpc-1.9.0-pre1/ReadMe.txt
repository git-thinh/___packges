Tutorial build: 

	> mingw32-make makefile.in 
	> make makefile.in

*MingW: mingw-w64-x86_64-gcc7.2.0-win32-sjlj

*zlib:
	> cd && git clone https://github.com/grpc/grpc.git
	> mkdir _build
	> cd _build
	> cmake .. -G "MinGW Makefiles"
	
	> git submodule init
	> git submodule update
	
	> cmake .. -G "MinGW Makefiles"
	
	> mingw32-make install