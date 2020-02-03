#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <string>

using std::string;

#define GLEVEL_TRACE 5000
#define GLEVEL_DEBUG 10000
#define GLEVEL_INFO  20000
#define GLEVEL_WARN  30000
#define GLEVEL_ERROR 40000
#define GLEVEL_FATAL 50000

class Logger
{
	friend class LogManager;
public:
	bool IsEnable(int level);
	void Log(int level,const char* message,const char* file,const char* function,long line);
	void Log(int level,const char* message);
	int GetLevel();
	void SetLevel(int level);
	string GetLevelString();
	void SetLevel(const char* level);
	string GetName();
private:
	Logger(void* pHandle);
	~Logger(void);
private:
	void* m_pHandle;
};

class TraceLogger
{
public:
	TraceLogger(const char* message,const char* file,const char* function,long line);
	~TraceLogger();
private:
	string m_Function;
};

#endif
