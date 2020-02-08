#pragma once

#include "logging.h"
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <time.h>


class GLogHelper
{

	public:
		GLogHelper();
		~GLogHelper();


		void InitLogger(const char *program="Xproject",const uint32_t log_level=google::INFO,const char *log_dir="./log");
	private:

};
