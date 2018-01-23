

::g++.exe -c main.cpp -o main.o -I"C:/Program Files (x86)/Dev-Cpp/MinGW64/include" -I"C:/Program Files (x86)/Dev-Cpp/MinGW64/x86_64-w64-mingw32/include" -I"C:/C++/protobuf.3.5.1-gcc.4.9.2/include" -m32 -std=gnu++11

::g++.exe -c addressbook.pb.cc -o addressbook.pb.o -I"C:/Program Files (x86)/Dev-Cpp/MinGW64/include" -I"C:/Program Files (x86)/Dev-Cpp/MinGW64/x86_64-w64-mingw32/include" -I"C:/C++/protobuf.3.5.1-gcc.4.9.2/include" -m32 -std=gnu++11

::g++.exe main.o addressbook.pb.o -o main.exe -L"C:/Program Files (x86)/Dev-Cpp/MinGW64/x86_64-w64-mingw32/lib32" -static-libgcc -L"C:/C++/protobuf.3.5.1-gcc.4.9.2/lib" -L"lib/libprotoc.a" -L"lib/libprotobuf.a" -m32


::g++ -I"C:/C++/protobuf.3.5.1-gcc.4.9.2/include" -L"C:/C++/protobuf.3.5.1-gcc.4.9.2/lib" main.cpp addressbook.pb.cc -lprotobuf -pthread



g++ -I"H:/___packges/grpc-1.9.0-pre1-gcc-4.9.0/include" -L"H:/___packges/grpc-1.9.0-pre1-gcc-4.9.0/lib" main.cpp addressbook.pb.cc -lprotobuf -pthread
