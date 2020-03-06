#include "GlassAPIImpl.h"
#include "grpc_basicParameters.pb.h"
#include "grpc_checkResult.pb.h"
#include "GLogHelper.h"
#include "ICalItemRegistrar.h"
#include "OneGlassPanel.h"
#include <memory>
#include "CommonCalResult.h"
#include "Utils.h"

Status GlassAPIImpl::Calculate(ServerContext* context, const GlassRequest *request, GlassCalReply* response)
{
	try
	{
		Xproject::grpc_BasicParameters requestparams=request->parameters();

		LOG(INFO)<<"glassType: "<<GlassParameters::GlassTypeStrs[request->type()];
		//1 Create glass instence
		std::shared_ptr<CalculateItem>glassInstance(CalItemFactory<CalculateItem>::Instance().GetCalItem(GlassParameters::GlassTypeStrs[request->type()]));

		Status grpcStatus;
		if(!glassInstance)
		{
			response->set_description("failed!");
			LOG(ERROR)<<"glass calculate instance create  failed!";
			grpcStatus=  Status::OK;
		}
		else
		{
			//2 Create parameters
			std::shared_ptr<BasicParameters>params(new GlassParameters(request));
			params->print();

			//3 Calculate
			std::shared_ptr<ResultBase>result(glassInstance->Calculate(params));
			if(result)
			{
				response->set_description("Ok");
				response->set_type(request->type());
				//results
				std::shared_ptr<CommonCalResult> oneGlassResult=std::dynamic_pointer_cast<CommonCalResult>(result);

				//print results
				oneGlassResult->print();
				Xproject::grpc_CommonCalResult *pCommonResult=new Xproject::grpc_CommonCalResult();
				Xproject::grpc_CheckResults *check;
				for(auto iter:oneGlassResult->m_CheckResults)
				{
					check=pCommonResult->add_m_checkresults();
					check->set_m_eresult(Xproject::grpc_CheckResults_eResult((int)iter.m_eResult));
					check->set_m_designvalue(Utils::Round(iter.m_DesignValue,3));
					check->set_m_calvalue(Utils::Round(iter.m_CalValue,3));
					check->set_m_surplus(Utils::Round(iter.m_Surplus,3));
					check->set_m_checktpye(iter.m_CheckType);
				}

				response->set_allocated_calresults(pCommonResult);

				for(auto i=0;i<response->calresults().m_checkresults_size();i++)
				{
					LOG(INFO)<<"m_eresult="<<response->calresults().m_checkresults(i).m_eresult();
					LOG(INFO)<<"m_designvalue="<<response->calresults().m_checkresults(i).m_designvalue();
					LOG(INFO)<<"m_calvalue="<<response->calresults().m_checkresults(i).m_calvalue();
					LOG(INFO)<<"surplus="<<response->calresults().m_checkresults(i).m_surplus();
					LOG(INFO)<<"checktpye="<<response->calresults().m_checkresults(i).m_checktpye();

				}


				LOG(INFO)<<"glass calculate success!";
				grpcStatus= Status::OK;
			}
			else
			{
				response->set_description("failed!");
				LOG(ERROR)<<"glass calculate failed!";
				grpcStatus=  Status::OK;
			}
		}

		LOG(INFO)<<"glass calculate finish!";
		return grpcStatus;
	}
	catch(...)
	{
		LOG(ERROR)<<"glass calculate exception!";
		return Status::CANCELLED;
	}

}



