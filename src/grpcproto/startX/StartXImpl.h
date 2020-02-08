#pragma once
#include <grpcpp/grpcpp.h>
#include "startX.grpc.pb.h"
#include <string>

using grpc::Status;
using grpc::ServerContext;
using Xproject::StartX;
using Xproject::CoreStatusRequest;
using Xproject::CoreStatusReply;

class StartXImpl:public StartX::Service
{
	Status GetCoreStatus(ServerContext *context,const CoreStatusRequest *request,CoreStatusReply *reply) override;
	
};
