
	$ pacman -S mingw-w64-x86_64-qt5
	
	$ PATH=$PATH:/c/msys2/mingw64/bin	
	
	$ pacman -S mingw-w64-x86_64-go
	$ pacman -S mingw-w64-x86_64-opencv
	$ pacman -S mingw-w64-x86_64-boost
	$ pacman -Sy mingw-w64-i686-toolchain
	$ pacman -Sy mingw-w64-x86_64-zlib
	$ pacman -Sy mingw-w64-x86_64-grpc
	
	
	
	
	$ /c/msys2/mingw64/bin/go.exe -env
	$ go env
	$ pacman -S mingw-w64-x86_64-clang
	$ where clang++
	$ pacman -S mingw-w64-x86_64-cmake
	
	
	
	
	$ git clone --recursive https://github.com/Microsoft/bond.git bond
	$ git submodule update --init

	$ pacman -S mingw-w64-x86_64-ninja
	$ cmake -DBOND_ENABLE_GRPC=FALSE ..
	
	cmake -GNinja -DgRPC_INSTALL=ON -DgRPC_BUILD_TESTS=OFF -DgRPC_PROTOBUF_PROVIDER=package -DgRPC_ZLIB_PROVIDER=package -DgRPC_CARES_PROVIDER=package -DgRPC_SSL_PROVIDER=package -DCMAKE_BUILD_TYPE=Release
	rm CMakeCache.txt
	cmake -G "Unix Makefiles" -DgRPC_INSTALL=ON -DgRPC_BUILD_TESTS=OFF -DgRPC_PROTOBUF_PROVIDER=package -DgRPC_ZLIB_PROVIDER=package -DgRPC_CARES_PROVIDER=package -DgRPC_SSL_PROVIDER=package -DCMAKE_BUILD_TYPE=Release
	make && make install
	
	
	
	$ PATH=$PATH:/c/msys2/mingw64/bin	
	$ pacman -S patch
	
	$ pacman -S mingw-w64-x86_64-sfml
	$ pacman -S mingw-w64-x86_64-opencv
	
	
	
	git clone https://github.com/Alexpux/MINGW-packages.git mpack
	$ cd mpack/
	$ cd mingw-w64-boost/
	$ MINGW_INSTALLS=mingw64 makepkg-mingw -sLf
	$ pacman -U mingw-w64-x86_64-boost-1.66.0-1-any.pkg.tar.xz
	
	
	
	
	
