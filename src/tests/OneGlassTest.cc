#include "OneGlassTest.h"
#include "grpc_checkResult.pb.h"
#include "GLogHelper.h"
#include "grpc_basicParameters.pb.h"
using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;

bool OneGlassTest::Test() 
{
	replyVec_.clear();

	bool isDataReady=Test_DataPrepare();
	if(isDataReady)
	{
		for(auto temp:dataVec_)
		{
			Xproject::GlassCalReply *reply;

			ClientContext context;

			Status status=stub_->Calculate(&context,temp,reply);
			if (status.ok())
			{
				replyVec_.push_back(reply);
			}
			else
			{
				//log
				LOG(ERROR)<<"Calculate return status error Status="<<status.error_message();
			}
		}
		if(replyVec_.size()!=correctResults_.size())
		{
			LOG(ERROR)<<"results size not equal,replyVec_.size()= "<<replyVec_.size()<<"correctResults_.size()= "<<correctResults_.size();
			return false;
		}
		//check results
		for(auto rees:correctResults_)
		{
			
		}
		
	}
	else
	{
		LOG(ERROR)<<"Data prepare fail! ";
	}
	return false;
}



bool OneGlassTest::Test_DataPrepare()
{

	Xproject::grpc_BasicParameters *basiceParams=new Xproject::grpc_BasicParameters();
	basiceParams->set_w0(0.3);
	basiceParams->set_m_edesignyears(Xproject::grpc_BasicParameters::FIFTY);
	basiceParams->set_m_esitetype(Xproject::grpc_BasicParameters::A);


	return false;
}
