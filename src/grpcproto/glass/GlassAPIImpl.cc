#include "GlassAPIImpl.h"
#include "grpc_basicParameters.pb.h"
#include "GLogHelper.h"
#include "FactoryApi.h"

//using Xproject::BasicParameters;

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

		//1 Create glass instence
		glassInstance=FactoryApi::Instance()->CreateCalItem(OneGlassCalItem);

		//2 Create parameters

		params=new BasicParameters();
		//3 Calculate
		result=glassInstance->Calculate(params);
		if(result->m_status==ResultBase::OK)
		{
			response->set_result("Ok");

			LOG(INFO)<<"glass calculate success!";
			return Status::OK;
		}
		else
		{
			LOG(ERROR)<<"glass calculate failed!";
			return Status::CANCELLED;
		}
		FreeCalculate(params,glassInstance,result);

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
