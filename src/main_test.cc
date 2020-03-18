#include "GLogHelper.h"
#include <string>
#include <grpcpp/grpcpp.h>
#include "OneGlassTest.h"


using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;



int main(int argc,char **argv)
{
	GLogHelper logHelper;
	logHelper.InitLogger("Xproject_test",google::INFO,"./log_test");
	LOG(INFO)<<"Automated test start...";


	//one glass test
	std::string targetAddressIpPort="localhost:50051";
	
	OneGlassTest oneGlassTest(grpc::CreateChannel(targetAddressIpPort,grpc::InsecureChannelCredentials()));

	auto isPass=oneGlassTest.Test();

	if(isPass)
	{
		LOG(INFO)<<"oneGlassTest test pass!";
	}
	else
	{
		LOG(ERROR)<<"oneGlassTest test not pass!";

	}

	

	return 0;
}
