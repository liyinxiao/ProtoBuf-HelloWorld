Protocol Buffers - Hello World
==========

- brew install protobuf
- compile protocol
```shell
export SRC_DIR=.
export DST_DIR=.
protoc -I=$SRC_DIR --cpp_out=$DST_DIR $SRC_DIR/hello.proto
```
- compile cpp
```shell
clang++ -std=c++11 main.cpp hello.pb.cc -I /usr/local/include -L /usr/local/lib -lprotobuf
```
- run
```shell
./a.out
```
- output
```shell
100
200
12345
```
- serialized file: ./test_data.log
