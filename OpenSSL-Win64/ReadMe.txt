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
	
	https://slproweb.com/products/Win32OpenSSL.html

Cmake Openssl And Mingw On Windows Linker 
	
If you found this you are probably having issues linking OpenSSL to MinGW-w64 using CMake (or CLion) on Windows. In this post I will give a quick overview on how to get this to work on a clean Windows machine…

The distribution I used to get it to work is Win64OpenSSL-1_2_2k.exe. The issue was that there are no MinGW-compatible link libaries. To solve this you can use my genlib tool to generate them:

	cd c:\OpenSSL-Win64
	set PATH=%PATH%;c:\genlib

	genlib ssleay32.dll
	genlib libeay32.dll

	copy *.a lib\

The CMakeLists.txt looks like this:

	# Project configuration
	cmake_minimum_required(VERSION 2.7)
	project(OpenSSLTest)

	# Use C++11
	set(CMAKE_CXX_STANDARD 11)

	# Project source files
	set(SOURCE_FILES main.cpp)
	add_executable(OpenSSLTest ${SOURCE_FILES})

	# OpenSSL (find, include, link) 
	find_package(OpenSSL REQUIRED)
	include_directories(${OPENSSL_INCLUDE_DIR})
	target_link_libraries(${PROJECT_NAME} ${OPENSSL_LIBRARIES})

And some simple test code:

	#include <iostream>
	#include <openssl/ssl.h>

	int main() {
		std::cout << "SSLeay Version: " << SSLeay_version(SSLEAY_VERSION) << std::endl;
		SSL_library_init();
		auto ctx = SSL_CTX_new(SSLv23_client_method());
		if (ctx) {
			auto ssl = SSL_new(ctx);
			if (ssl) {
				std::cout << "SSL Version: " << SSL_get_version(ssl) << std::endl;
				SSL_free(ssl);
			} else {
				std::cout << "SSL_new failed..." << std::endl;
			}
			SSL_CTX_free(ctx);
		} else {
			std::cout << "SSL_CTX_new failed..." << std::endl;
		}
	}
	
If everything is configured correctly this should print:

SSLeay Version: OpenSSL 1.0.2k  26 Jan 2017
SSL Version: TLSv1.2
If you cannot be bothered to run genlib yourself, you can find a copy the required files here and get started immediately.

Hope this helped,

Duncan