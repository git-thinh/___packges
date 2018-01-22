Tutorial build: 
	> mingw32-make makefile.in 
	> make makefile.in

*MingW: mingw-w64-x86_64-gcc7.2.0-win32-sjlj

*Build: 
	> cd && git clone https://github.com/c-ares/c-ares.git
	> mkdir _build && cd _build 
	> cmake .. -G "MinGW Makefiles"
	> mingw32-make
	> mingw32-make install