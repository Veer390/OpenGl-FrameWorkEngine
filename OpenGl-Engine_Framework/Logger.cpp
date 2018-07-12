#include "Logger.h"

void Logger::WriteToFile(std::string ToWrite)
{
	file.open(path, std::ios::app);
	for (auto i : ToWrite)
	{
		file.put(i);
	}
	file.close();
	

}
