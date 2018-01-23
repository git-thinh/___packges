
Download and carefully unzip it somewhere else and add a "-mingw" suffix to the directory name. https://github.com/google/protobuf/archive/v3.0.0-beta-2.tar.gz

git clone https://github.com/google/protobuf.git
cd protobuf
mkdir install_dir
mkdir cmake_build
cd cmake_build
cmake -DCMAKE_INSTALL_PREFIX=../install_dir -DCMAKE_INSTALL_LIBDIR=lib -Dprotobuf_BUILD_TESTS=OFF -DCMAKE_CXX_FLAGS="-std=c++11" -DCMAKE_BUILD_TYPE=Release -G "MinGW Makefiles" ../cmake
mingw32-make
mingw32-make install



syntax = "proto3";

package tutorial;

message Person {
  required string name = 1;
  required int32 id = 2;
  optional string email = 3;

  enum PhoneType {
    MOBILE = 0;
    HOME = 1;
    WORK = 2;
  }

  message PhoneNumber {
    required string number = 1;
    optional PhoneType type = 2 [default = HOME];
  }

  repeated PhoneNumber phones = 4;
}

message AddressBook {
  repeated Person people = 1;
}

protoc -I=./ --cpp_out=./ addressbook.proto


g++ -I"C:/C++/protobuf.3.5.1-gcc.4.9.2/include" -L"C:/C++/protobuf.3.5.1-gcc.4.9.2/lib" main.cpp addressbook.pb.cc -lprotobuf -pthread



