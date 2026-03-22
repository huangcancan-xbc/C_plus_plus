#include "Logger.h"

#include <iostream>

Logger* Logger::_instance = nullptr;	// 初始化

Logger::Logger()
{
	// 简化初始化
}

Logger* Logger::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new Logger();
	}

	return _instance;
}

void Logger::log(const std::string& msg)
{
	std::cout << "[log] " << msg << std::endl;
}