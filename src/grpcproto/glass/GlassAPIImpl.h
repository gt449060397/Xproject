#pragma once

#include <grpcpp/grpcpp.h>
#include "glassAPI.grpc.pb.h"

using grpc::Status;    
using grpc::ServerContext;
using Xproject::GlassAPI;                                      
using Xproject::GlassRequest;	
using Xproject::GlassCalReply;

class GlassAPIImpl:public GlassAPI::Service
{
	Status Calculate(ServerContext* context, const GlassRequest *request, GlassCalReply* response) override;
};

