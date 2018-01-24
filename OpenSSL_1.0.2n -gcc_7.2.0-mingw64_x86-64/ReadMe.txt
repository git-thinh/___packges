Welcome to OpenSSL!
OpenSSL is a robust, commercial-grade, and full-featured toolkit for the Transport Layer Security (TLS) and Secure Sockets Layer (SSL) protocols. It is also a general-purpose cryptography library. For more information about the team and community around the project, or to start making your own contributions, start with the  community page. To get the latest news, download the source, and so on, please see the sidebar or the buttons at the top of every page.

	$ sudo apt-get install autoconf automake libtool curl make g++ unzip git cmake golang-go perl zlib
			
	$ git clone git://git.openssl.org/openssl.git
	$ git submodule update --init
	
	$ cd openssl
	$ CROSS_COMPILE=/c/mingw-w64-x86_64-gcc7.2.0-win32-sjlj/mingw64/bin/ ./Configure mingw64 no-shared no-asm --prefix=/c/OpenSSL-x64
	$ PATH=$PATH:/c/mingw-w64-x86_64-gcc7.2.0-win32-sjlj/mingw64/bin make depend
	$ PATH=$PATH:/c/mingw-w64-x86_64-gcc7.2.0-win32-sjlj/mingw64/bin make >> /c/log.txt 2>&1
	$ PATH=$PATH:/c/mingw-w64-x86_64-gcc7.2.0-win32-sjlj/mingw64/bin make install