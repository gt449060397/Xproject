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

	std::string target_str;
	std::string arg_str("--target");
	if (argc > 1) {
		std::string arg_val = argv[1];
		size_t start_pos = arg_val.find(arg_str);
		if (start_pos != std::string::npos) {
			start_pos += arg_str.size();
			if (arg_val[start_pos] == '=') {
				target_str = arg_val.substr(start_pos + 1);
			} else {
				std::cout << "The only correct argument syntax is --target=" << std::endl;
				return 0;
			}
		} else {
			std::cout << "The only acceptable argument is --target=" << std::endl;
			return 0;
		}
	} else {
		target_str = "localhost:50051";
	}
	//one glass test
	auto channel_creds=grpc::SslCredentials(grpc::SslCredentialsOptions());
	auto channel =grpc::CreateChannel(target_str,channel_creds);

	//OneGlassTest oneGlassTest(grpc::CreateChannel(target_str,grpc::InsecureChannelCredentials()));
	OneGlassTest oneGlassTest(channel);

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
