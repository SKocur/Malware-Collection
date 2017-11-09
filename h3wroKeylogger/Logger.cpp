#include "Logger.h"

#include <fstream>

Logger::Logger(){
	out_file.open("logs.html", std::ios_base::app);
}

void Logger::saveToFile(std::string data) {
	out_file << data;
}

void Logger::destroy() {
	out_file.close();
}
