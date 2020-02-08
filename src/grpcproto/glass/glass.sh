
#protoc --proto_path=./src/protobufDemo/demo1/ --proto_path=./src/protobufDemo/demo2 --
protoc --cpp_out=./ glassAPI.proto
protoc --grpc_out=./ --plugin=protoc-gen-grpc=/usr/local/bin/grpc_cpp_plugin glassAPI.proto
