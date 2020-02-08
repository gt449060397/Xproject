

protoc --cpp_out=./ startX.proto
protoc --grpc_out=./ --plugin=protoc-gen-grpc=/usr/local/bin/grpc_cpp_plugin startX.proto
