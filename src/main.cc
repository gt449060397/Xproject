#include <algorithm>
#include <chrono>
#include <cmath>
#include <iostream>
#include <memory>
#include <string>

#include <grpc/grpc.h>
#include <grpcpp/server.h>
#include <grpcpp/server_builder.h>
#include <grpcpp/server_context.h>
#include <grpcpp/security/server_credentials.h>

#include "grpcproto/startX/startX.grpc.pb.h"
#include "grpcproto/startX/StartXImpl.h"
#include "LogManager.h"
#include "grpcproto/glass/GlassAPIImpl.h"


using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

void RunServer()
{
	std::string server_address("0.0.0.0:50051");
        StartXImpl service;

	GlassAPIImpl glassService;

	ServerBuilder builder;

	builder.AddListeningPort(server_address,grpc::InsecureServerCredentials());

	builder.RegisterService(&service);
	builder.RegisterService(&glassService);

	std::unique_ptr<Server> server(builder.BuildAndStart());

	std::cout<<"Server listening on "<<server_address<<std::endl;


	 server->Wait();

}

int main(int argc,char**argv)
{
	std::cout<<"Welcome! Core Computing Program start..."<<std::endl;
//	GLOGD(("Welcome! Core Computing Program start..."));
	RunServer();

	return 0;
}
