#include "GlassAPIImpl.h"
#include "basicParameters.pb.h"
#include "GLogHelper.h"

using Xparameters::BasicParameters;

Status GlassAPIImpl::Calculate(ServerContext* context, const GlassRequest *request, GlassCalReply* response)
{
	BasicParameters params=request->parameters();


	LOG(INFO)<<"params w0= "<<params.w0();
	LOG(INFO)<<"params m_edesignyears= "<<params.m_edesignyears();
	LOG(INFO)<<"params m_esitetype= "<<params.m_esitetype();
	LOG(INFO)<<"params m_ecalarea= "<<params.m_ecalarea();
	LOG(INFO)<<"params m_ewindcalmethod= "<<params.m_ewindcalmethod();
	LOG(INFO)<<"params m_eseismicfort= "<<params.m_eseismicfort();
	LOG(INFO)<<"params m_eseismicsitetype= "<<params.m_eseismicsitetype();
	LOG(INFO)<<"params height= "<<request->height();
	LOG(INFO)<<"params width= "<<request->width();
	LOG(INFO)<<"params thickness= "<<request->thickness();
	LOG(INFO)<<"params mat= "<<request->mat();
	response->set_result("Ok");

	return Status::OK;

}
