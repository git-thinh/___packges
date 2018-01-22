Tutorial build: 

	> mingw32-make makefile.in 
	> make makefile.in

*MingW: mingw-w64-x86_64-gcc7.2.0-win32-sjlj
*zlib:
	- https://zlib.net/
	- unzip source
	> cd zlib-1.2.11
	> mkdir _build && cd _build && cmake .. -G "MinGW Makefiles"
	> gcc --version && mingw32-make