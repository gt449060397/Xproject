#pragma once

#include <grpcpp/grpcpp.h>
#include "glassAPI.grpc.pb.h"


using grpc::Status;    
using grpc::ServerContext;
using Xglass::GlassAPI;                                      
using Xglass::GlassRequest;	
using Xglass::GlassCalReply;


class GlassAPIImpl:public GlassAPI::Service
{
	Status Calculate(ServerContext* context, const GlassRequest *request, GlassCalReply* response) override;
};

