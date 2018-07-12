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
	{
		file.open(path,std::ios::app);
		for (int i = 0; i < 3; i++)
		{
			file.put('\n');
		}
		for (int i = 0; i < 20; i++)
		{
			file.put('-');
		}
		file.close();
	}

	
private:
	std::string path;
	std::fstream file;

public:
	void WriteToFile(std::string ToWrite);

};