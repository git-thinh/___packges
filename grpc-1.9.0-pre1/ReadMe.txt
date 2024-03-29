These instructions only cover building grpc C and C++ libraries under
typical unix systems. If you need more information, please try grpc's
wiki pages:

  https://github.com/google/grpc/wiki


*************************
* If you are in a hurry *
*************************

 $ git clone https://github.com/grpc/grpc.git
 $ cd grpc
 $ git submodule update --init
 $ make 
 $ sudo make install

You don't need anything else than GNU Make, gcc and autotools. Under a Debian
or Ubuntu system, this should boil down to the following packages:

  $ apt-get install build-essential autoconf libtool

Building the python wrapper requires the following:

  # apt-get install python-all-dev python-virtualenv

If you want to install in a different directory than the default /usr/lib, you can
override it on the command line:

  # make install prefix=/opt


*******************************
* More detailled instructions *
*******************************

Setting up dependencies
=======================

Dependencies to compile the libraries
-------------------------------------

grpc libraries have few external dependencies. If you need to compile and
install them, they are present in the third_party directory if you have
cloned the github repository recursively. If you didn't clone recursively,
you can still get them later by running the following command:

  $ git submodule update --init

Note that the Makefile makes it much easier for you to compile from sources
if you were to clone recursively our git repository: it will automatically
compile zlib and OpenSSL, which are core requirements for grpc. Note this
creates grpc libraries that will have zlib and OpenSSL built-in inside of them,
which significantly increases the libraries' size.

In order to decrease that size, you can manually install zlib and OpenSSL on
your system, so that the Makefile can use them instead.

Under a Debian or Ubuntu system, one can acquire the development package
for zlib this way:

  # apt-get install zlib1g-dev

To the best of our knowledge, no distribution has an OpenSSL package that
supports ALPN yet, so you would still have to depend on installing from source
for that particular dependency if you want to reduce the libraries' size.

The recommended version of OpenSSL that provides ALPN support is available
at this URL:

  https://www.openssl.org/source/openssl-1.0.2.tar.gz


Dependencies to compile and run the tests
-----------------------------------------

Compiling and running grpc plain-C tests dont't require any more dependency.


Compiling and running grpc C++ tests depend on protobuf 3.0.0, gtest and
gflags. Although gflags is provided in third_party, you will need to manually
install that dependency on your system to run these tests.

Under a Debian or Ubuntu system, you can install the gtests and gflags packages
using apt-get:

  # apt-get install libgflags-dev libgtest-dev

However, protobuf 3.0.0 isn't in a debian package yet, but the Makefile will
automatically try and compile the one present in third_party if you cloned the
repository recursively, and that it detects your system is lacking it.

Compiling and installing protobuf 3.0.0 requires a few more dependencies in
itself, notably the autoconf suite. If you have apt-get, you can install
these dependencies this way:

  # apt-get install autoconf libtool

If you want to run the tests using one of the sanitized configurations, you
will need clang and its instrumented libc++:

  # apt-get install clang libc++-dev

Mac-specific notes:
-------------------

For a Mac system, git is not available by default. You will first need to
install Xcode from the Mac AppStore and then run the following command from a
terminal:

  $ sudo xcode-select --install

You should also install "port" following the instructions at
https://www.macports.org . This will reside in /opt/local/bin/port for
most Mac installations. Do the "git submodule" command listed above.

Then execute the following for all the needed build dependencies

  $ sudo /opt/local/bin/port install autoconf automake libtool gflags cmake
  $ mkdir ~/gtest
  $ svn checkout http://googletest.googlecode.com/svn/trunk/ gtest-svn
  $ mkdir mybuild
  $ cd mybuild
  $ cmake ../gtest-svn
  $ make
  $ make gtest.a gtest_main.a
  $ sudo cp libgtest.a libgtest_main.a /opt/local/lib
  $ sudo mkdir /opt/local/include/gtest
  $ sudo cp -pr ../gtest-svn/include/gtest /opt/local/include/gtest 

We will also need to make openssl and install it appropriately

  $ cd <git directory>
  $ cd third_party/openssl
  $ sudo make install
  $ cd ../../

If you are going to make changes and need to regenerate the projects file,
you will need to install certain modules for python.

  $ sudo easy_install simplejson mako

Mingw-specific notes:
---------------------

While gRPC compiles properly under mingw, some more preparation work is needed.
The recommendation is to use msys2. The installation instructions are available
at that address: http://msys2.github.io/

Once this is installed, make sure you are using the following: MinGW-w64 Win64.
You'll be required to install a few more packages:

  $ pacman -S make mingw-w64-x86_64-gcc mingw-w64-x86_64-zlib autoconf automake libtool

Please also install OpenSSL from that website:

  http://slproweb.com/products/Win32OpenSSL.html

The package Win64 OpenSSL v1.0.2a should do. At that point you should be able
to compile gRPC with the following:

  $ export LDFLAGS="-L/mingw64/lib -L/c/OpenSSL-Win64"
  $ export CPPFLAGS="-I/mingw64/include -I/c/OpenSSL-Win64/include"
  $ make

A word on OpenSSL
-----------------

Secure HTTP2 requires the TLS extension ALPN (see rfc 7301 and
http://http2.github.io/http2-spec/ section 3.3). Our HTTP2 implementation
relies on OpenSSL's implementation. OpenSSL 1.0.2 is the first released version
of OpenSSL that has ALPN support, and this explains our dependency on it.

Note that the Makefile supports compiling only the unsecure elements of grpc,
and if you do not have OpenSSL and do not want it, you can still proceed
with installing only the elements you require. However, we strongly recommend
the use of encryption for all network traffic, and discourage the use of grpc
without TLS.


Compiling
=========

If you have all the dependencies mentioned above, you should simply be able
to go ahead and run "make" to compile grpc's C and C++ libraries:

  $ make


Testing
=======

To build and run the tests, you can run the command:

  $ make test

If you want to be able to run them in parallel, and get better output, you can
also use the python tool we have written:

  $ ./tools/run_tests/run_tests.py


Installing
==========

Once everything is compiled, you should be able to install grpc C and C++
libraries and headers:

  # make install


















# Build & install GRPC:

	git clone https://boringssl.googlesource.com/boringssl


	pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-ninja mingw-w64-x86_64-cmake git
	pacman -S clang mingw-w64-x86_64-clang mingw-w64-x86_64-clang-analyzer mingw-w64-x86_64-clang-tools-extra
	

	$ export CC=/c/mingw-w64-x86_64-gcc7.2.0-win32-sjlj/MinGW64-GCC_7.2/gcc.exe && export CXX=/c/mingw-w64-x86_64-gcc7.2.0-win32-sjlj/MinGW64-GCC_7.2/g++.exe
	$ cmake -G "MinGW Makefiles" ..
	
	cmake -GNinja
	$ mingw32-make

	cmake -DCMAKE_TOOLCHAIN_FILE=util/32-bit-toolchain.cmake -GNinja
	cmake -DCMAKE_CXX_COMPILER=clang++ -GNinja

	$ git clone https://go.googlesource.com/go
	$ cd go
	$ git checkout go1.9.3

	$ git checkout master

	$ cd src
	$ ./all.bash

	> cmake -G "MinGW Makefiles" -DgRPC_INSTALL=ON -DgRPC_BUILD_TESTS=OFF -DgRPC_PROTOBUF_PROVIDER=package -DgRPC_ZLIB_PROVIDER=package -DgRPC_CARES_PROVIDER=package -DgRPC_SSL_PROVIDER=package -DCMAKE_BUILD_TYPE=Release

	$ pacman -S autoconf automake gcc libtool mingw-w64-x86_64-toolchain perl pkg-config zlib curl make g++ unzip git cmake
	
	
	
	$ pacman -S autoconf automake libtool perl pkg-config zlib curl make unzip git cmake
	
	$ pacman -S golang-go
	$ pacman -S mingw-w64-x86_64-gflags

	cmake -G "MinGW Makefiles" CPPFLAGS="-D_WIN32_WINNT=0x0600"
	
	
	
	$ pacman -S autoconf automake libtool perl pkg-config zlib curl make unzip git cmake
	
	$ git clone https://github.com/grpc/grpc.git && cd grpc
	$ git submodule update --init
	
	$ export CPPFLAGS="-D_WIN32_WINNT=0x0600"
	$ make
	
	$ mkdir Configure
	$ CROSS_COMPILE=/c/mingw-w64-x86_64-gcc7.2.0-win32-sjlj/MinGW64-GCC_7.2/bin/ ./Configure mingw64 no-shared no-asm --prefix=/c/grpc_1.9.0-pre1
	$ export CPPFLAGS="-D_WIN32_WINNT=0x0600 -DgRPC_INSTALL=ON -DgRPC_BUILD_TESTS=OFF -DgRPC_PROTOBUF_PROVIDER=package -DgRPC_ZLIB_PROVIDER=package -DgRPC_CARES_PROVIDER=package -DgRPC_SSL_PROVIDER=package -DCMAKE_BUILD_TYPE=Release"
	
	./gyp/gyp grpc.gyp --depth=. --generator-output=./.build --format=make -Dcomponent=static_library -Dtarget_arch=x64
	
	$ PATH=$PATH:/c/mingw-w64-x86_64-gcc7.2.0-win32-sjlj/MinGW64-GCC_7.2/bin && clear && echo && gcc --version
	$ PATH=$PATH:/c/mingw-w64-x86_64-gcc7.2.0-win32-sjlj/MinGW64-GCC_7.2/bin && mingw32-make
	$ PATH=$PATH:/c/Go/bin && clear && echo && go help
	
	$ export CPPFLAGS="-D_WIN32_WINNT=0x0600"
	$ export CPPFLAGS="-D_WIN32_WINNT=0x0600 -DgRPC_INSTALL=ON -DgRPC_BUILD_TESTS=OFF -DgRPC_PROTOBUF_PROVIDER=package -DgRPC_ZLIB_PROVIDER=package -DgRPC_CARES_PROVIDER=package -DgRPC_SSL_PROVIDER=package -DCMAKE_BUILD_TYPE=Release"

	$ cmake -G "Unix Makefiles" -DCMAKE_LEGACY_CYGWIN_WIN32=1
	
	$ make
	$ make >> /c/log.txt 2>&1
	$ make install
	
	
	
	
	
	
	
	
	
	
	
	