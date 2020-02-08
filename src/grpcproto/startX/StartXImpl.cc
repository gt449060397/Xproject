#include "StartXImpl.h"



Status StartXImpl::GetCoreStatus(ServerContext *context,const CoreStatusRequest *request,CoreStatusReply *reply)  
{
	std::string coreStatus(": sever start,Core status Ok!");

	reply->set_message(request->name()+coreStatus);

	return Status::OK;
}
