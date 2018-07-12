#pragma once
#include <iostream>
#include <fstream>
#include <string>

class Logger
{
public:
	Logger() = delete;
	Logger(std::string LogFileLocation)
		:
		path(LogFileLocation),
		file(LogFileLocation, std::ofstream::out)
	{}

	
private:
	std::string path;
	std::fstream file;

public:
	void WriteToFile(std::string ToWrite);

};