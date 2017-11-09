#pragma once
#include <fstream>
#include <string>

#ifndef LOGGER_H
#define LOGGER_H

class Logger
{
public:
	Logger();

	void saveToFile(std::string data);
	void destroy();

private:
	std::ofstream out_file;
	std::string sLogs = "";
};

#endif