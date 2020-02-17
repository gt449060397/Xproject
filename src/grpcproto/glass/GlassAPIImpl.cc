#include "GlassAPIImpl.h"
#include "grpc_basicParameters.pb.h"
#include "GLogHelper.h"
#include "ICalItemRegistrar.h"
#include "OneGlassPanel.h"

Status GlassAPIImpl::Calculate(ServerContext* context, const GlassRequest *request, GlassCalReply* response)
{
	BasicParameters *params=nullptr;
	ResultBase *result=nullptr;
	CalculateItem* glassInstance=nullptr;
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
		glassInstance=CalItemFactory<CalculateItem>::Instance().GetCalItem(GlassParameters::GlassTypeStrs[request->type()]);

		Status grpcStatus;
		if(glassInstance==nullptr)
		{
			response->set_result("failed!");
			LOG(ERROR)<<"glass calculate instance create  failed!";
			grpcStatus=  Status::OK;
		}
		else
		{
			//2 Create parameters
			params=new GlassParameters(request);

			//3 Calculate
			result=glassInstance->Calculate(params);
			if(result!=nullptr&&result->m_status==ResultBase::OK)
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

		FreeCalculate(params,glassInstance,result);
		return grpcStatus;
	}
	catch(...)
	{
		LOG(ERROR)<<"glass calculate exception!";
		FreeCalculate(params,glassInstance,result);
		return Status::CANCELLED;
	}
}


void GlassAPIImpl::FreeCalculate(BasicParameters *param,CalculateItem *calItem,ResultBase *result)
{
	if(param)
	{
		delete param;
		param=nullptr;
	}
	if(calItem)
	{
		delete calItem;
		calItem=nullptr;
	}

	if(result)
	{
		delete result;
		result=nullptr;
	}
}

