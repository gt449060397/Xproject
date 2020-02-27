#pragma once

#include <grpcpp/grpcpp.h>
#include "grpc_glass.grpc.pb.h"
#include "CalculateItem.h"
#include "ResultBase.h"
#include "BasicParameters.h"

using grpc::Status;    
using grpc::ServerContext;
using Xproject::grpc_Glass;                                      
using Xproject::GlassRequest;	
using Xproject::GlassCalReply;

class GlassAPIImpl:public grpc_Glass::Service
{
	public:

		Status Calculate(ServerContext* context, const GlassRequest *request, GlassCalReply* response) override;


	private:
};


