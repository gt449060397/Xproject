#ifndef __LOG_MANAGER_H__
#define __LOG_MANAGER_H__

#include <string>
#include <map>
#include <vector>
#include "Logger.h"

typedef std::map<std::string,Logger*> LoggerMap;
typedef std::vector<Logger*> LoggerList;

class LogManager
{
private:
	LogManager(const char* fileName);
	~LogManager(void);
public:
	static bool Initial(const char* fileName);
	static void Destroy();
	static LogManager* GetInstance(){return m_pInstance;}

	void ReloadConfig();
	Logger* GetLogger(const char* name);
	Logger* GetRootLogger(){return m_pRootLogger;}
	Logger* GetTraceLogger(){return m_pTraceLogger;}
	LoggerList GetAllLogger();
private:
	static LogManager* m_pInstance;

	Logger* m_pRootLogger;
	Logger* m_pTraceLogger;
	LoggerMap m_LoggerMap;
	string m_ConfigFile;
};

std::string FormatString(const char* format,...);

#if defined(__GNUC__)
#	define __GFUNCTION__ __PRETTY_FUNCTION__
#elif defined(_MSC_VER)
#	define __GFUNCTION__ __FUNCSIG__
#else
#	define __GFUNCTION__ ""
#endif

#define GLOG_TRACE(logger,parameter) {if(logger->IsEnable(GLEVEL_TRACE)) logger->Log(GLEVEL_TRACE,(FormatString parameter).c_str(),__FILE__,__GFUNCTION__,__LINE__);}
#define GLOG_DEBUG(logger,parameter) {if(logger->IsEnable(GLEVEL_DEBUG)) logger->Log(GLEVEL_DEBUG,(FormatString parameter).c_str(),__FILE__,__GFUNCTION__,__LINE__);}
#define GLOG_INFO(logger,parameter) {if(logger->IsEnable(GLEVEL_INFO)) logger->Log(GLEVEL_INFO,(FormatString parameter).c_str(),__FILE__,__GFUNCTION__,__LINE__);}
#define GLOG_WARN(logger,parameter) {if(logger->IsEnable(GLEVEL_WARN)) logger->Log(GLEVEL_WARN,(FormatString parameter).c_str(),__FILE__,__GFUNCTION__,__LINE__);}
#define GLOG_ERROR(logger,parameter) {if(logger->IsEnable(GLEVEL_ERROR)) logger->Log(GLEVEL_ERROR,(FormatString parameter).c_str(),__FILE__,__GFUNCTION__,__LINE__);}
#define GLOG_FATAL(logger,parameter) {if(logger->IsEnable(GLEVEL_FATAL)) logger->Log(GLEVEL_FATAL,(FormatString parameter).c_str(),__FILE__,__GFUNCTION__,__LINE__);}

#define GLOGT(parameter) GLOG_TRACE(LogManager::GetInstance()->GetRootLogger(),parameter)
#define GLOGD(parameter) GLOG_DEBUG(LogManager::GetInstance()->GetRootLogger(),parameter)
#define GLOGI(parameter) GLOG_INFO(LogManager::GetInstance()->GetRootLogger(),parameter)
#define GLOGW(parameter) GLOG_WARN(LogManager::GetInstance()->GetRootLogger(),parameter)
#define GLOGE(parameter) GLOG_ERROR(LogManager::GetInstance()->GetRootLogger(),parameter)
#define GLOGF(parameter) GLOG_FATAL(LogManager::GetInstance()->GetRootLogger(),parameter)

#define GTRACE_ENABLE() (LogManager::GetInstance()->GetRootLogger()->IsEnable(GLEVEL_TRACE))
#define GDEBUG_ENABLE() (LogManager::GetInstance()->GetRootLogger()->IsEnable(GLEVEL_DEBUG))
#define GINFO_ENABLE() (LogManager::GetInstance()->GetRootLogger()->IsEnable(GLEVEL_INFO))
#define GWARN_ENABLE() (LogManager::GetInstance()->GetRootLogger()->IsEnable(GLEVEL_WARN))
#define GERROR_ENABLE() (LogManager::GetInstance()->GetRootLogger()->IsEnable(GLEVEL_ERROR))
#define GFATAL_ENABLE() (LogManager::GetInstance()->GetRootLogger()->IsEnable(GLEVEL_FATAL))

#define GTRACE_FUNCTION(parameter) TraceLogger __trace((FormatString parameter).c_str(),__FILE__,__GFUNCTION__,__LINE__)
#define GTRACE() GTRACE_FUNCTION((""))

#endif
