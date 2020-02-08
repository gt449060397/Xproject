#include "GlassAPIImpl.h"
#include "LogManager.h"
#include "basicParameters.pb.h"

using Xparameters::BasicParameters;

Status GlassAPIImpl::Calculate(ServerContext* context, const GlassRequest *request, GlassCalReply* response)
{
	BasicParameters params=request->parameters();

	//GLOGD(("main VGBSAPP_SendGBSecurityLoadPrivateCertByPathRequest ret=%d", params.w0()));

	response->set_result("Ok");

	return Status::OK;

}
