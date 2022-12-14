#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>

using namespace std;

class Logger
{
public:
	Logger() {
	}
	
	~Logger() {
	}
	
	static void log(const string &msg, int logType);
	static void log(const string &msg, const string &file, bool header = true);

	static const int ERROR;
	static const int DEBUG;
	
	static string timestamp();
private:
	static bool openLog(fstream &file, const string &name);
	static void closeLog(fstream &file);
};

#endif
