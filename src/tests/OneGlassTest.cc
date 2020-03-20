#include "OneGlassTest.h"
#include "grpc_checkResult.pb.h"
#include "GLogHelper.h"
using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;

bool OneGlassTest::Test() 
{
	LOG(INFO)<<"Test() ";
	replyVec_.clear();

	bool isDataReady=Test_DataPrepare();
	if(isDataReady)
	{
		for(auto temp:dataVec_)
		{
			Xproject::GlassCalReply *reply=new Xproject::GlassCalReply();

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
	LOG(INFO)<<"Test_DataPrepare() ";
	for(auto i=0;i<2;i++)
	{
		Xproject::grpc_BasicParameters *basiceParams=new Xproject::grpc_BasicParameters();
		basiceParams->set_w0(0.3);
		basiceParams->set_m_edesignyears(Xproject::grpc_BasicParameters::FIFTY);
		basiceParams->set_m_esitetype(Xproject::grpc_BasicParameters::A);
		basiceParams->set_m_ecalarea(Xproject::grpc_BasicParameters::Wall);
		basiceParams->set_m_ewindcalmethod(Xproject::grpc_BasicParameters::LOADCODE);
		basiceParams->set_m_eseismicfort(Xproject::grpc_BasicParameters::STANDARD);
		basiceParams->set_m_eseismicsitetype(Xproject::grpc_BasicParameters::I0);
		basiceParams->set_m_u_sl(1.0);
		basiceParams->set_m_windloadnominalvalue(1.0);
		basiceParams->set_m_alpha_max(0.08);
		basiceParams->set_m_calheight(50);

		Xproject::GlassRequest request;
		request.set_allocated_parameters(basiceParams);
		request.set_width(600);
		request.set_height(800);
		request.set_mat(Xproject::GlassRequest::TEMPERED);
		request.add_thickness(10);
		request.set_type(Xproject::ONE);


		dataVec_.push_back(request);

		auto res=new Xproject::GlassCalReply();
		//test
		correctResults_.push_back(res);
	}
	
	return true;
}
