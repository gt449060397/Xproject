#pragma once
#include <grpcpp/grpcpp.h>
#include "grpc_basicParameters.pb.h"
#include "grpc_glass.pb.h"
#include <vector>
#include "grpc_glass.grpc.pb.h"

class OneGlassTest
{

	public:
		OneGlassTest(std::shared_ptr<grpc::Channel>channel)
			:stub_(Xproject::grpc_Glass::NewStub(channel)){}
		bool Test();

	private:

		bool Test_DataPrepare();
	



	private:
		std::vector<Xproject::GlassRequest> dataVec_;
		std::vector<Xproject::GlassCalReply*> correctResults_;
		std::vector<Xproject::GlassCalReply*>replyVec_;

		std::unique_ptr<Xproject::grpc_Glass::Stub> stub_;

};
