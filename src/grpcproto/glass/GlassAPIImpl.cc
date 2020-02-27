#include "GlassAPIImpl.h"
#include "grpc_basicParameters.pb.h"
#include "GLogHelper.h"
#include "ICalItemRegistrar.h"
#include "OneGlassPanel.h"
#include <memory>

Status GlassAPIImpl::Calculate(ServerContext* context, const GlassRequest *request, GlassCalReply* response)
{
	//BasicParameters *params=nullptr;
	//ResultBase *result=nullptr;
	//CalculateItem* glassInstance=nullptr;
	try
	{
		Xproject::grpc_BasicParameters requestparams=request->parameters();

		LOG(INFO)<<"requestparams w0= "<<requestparams.w0();
		LOG(INFO)<<"requestparams m_edesignyears= "<<requestparams.m_edesignyears();
		LOG(INFO)<<"requestparams m_esitetype= "<<requestparams.m_esitetype();
		LOG(INFO)<<"requestparams m_ecalarea= "<<requestparams.m_ecalarea();
		LOG(INFO)<<"requestparams m_ewindcalmethod= "<<requestparams.m_ewindcalmethod();
		LOG(INFO)<<"requestparams m_eseismicfort= "<<requestparams.m_eseismicfort();
		LOG(INFO)<<"requestparams m_eseismicsitetype= "<<requestparams.m_eseismicsitetype();
		LOG(INFO)<<"requestparams m_u_sl= "<<requestparams.m_u_sl();
		LOG(INFO)<<"requestparams m_alpha_max= "<<requestparams.m_alpha_max();
		LOG(INFO)<<"requestparams m_windloadnominalvalue= "<<requestparams.m_windloadnominalvalue();
		LOG(INFO)<<"requestparams height= "<<request->height();
		LOG(INFO)<<"requestparams width= "<<request->width();
		LOG(INFO)<<"requestparams thickness= "<<request->thickness();
		LOG(INFO)<<"requestparams mat= "<<request->mat();
		LOG(INFO)<<"requestparams type= "<<request->type();

		LOG(INFO)<<"glassType: "<<GlassParameters::GlassTypeStrs[request->type()];
		//1 Create glass instence
		std::shared_ptr<CalculateItem>glassInstance(CalItemFactory<CalculateItem>::Instance().GetCalItem(GlassParameters::GlassTypeStrs[request->type()]));

		Status grpcStatus;
		if(!glassInstance)
		{
			response->set_result("failed!");
			LOG(ERROR)<<"glass calculate instance create  failed!";
			grpcStatus=  Status::OK;
		}
		else
		{
			//2 Create parameters
			std::shared_ptr<BasicParameters>params(new GlassParameters(request));

			//3 Calculate
			std::shared_ptr<ResultBase>result(glassInstance->Calculate(params));
			if(result)
			{
				response->set_result("Ok");

				LOG(INFO)<<"glass calculate success!";
				grpcStatus= Status::OK;
			}
			else
			{
				response->set_result("failed!");
				LOG(ERROR)<<"glass calculate failed!";
				grpcStatus=  Status::OK;
			}
		}

		return grpcStatus;
	}
	catch(...)
	{
		LOG(ERROR)<<"glass calculate exception!";
		return Status::CANCELLED;
	}
}


