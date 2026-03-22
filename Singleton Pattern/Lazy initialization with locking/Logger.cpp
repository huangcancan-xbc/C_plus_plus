#include "Logger.h"

#include <iostream>

// 声明完记得定义
Logger* Logger::_instance = nullptr;
std::mutex Logger::_mutex;

Logger::Logger()
{
	// 简化初始化
}

Logger* Logger::getInstance()
{
	std::lock_guard<std::mutex> lock(_mutex);
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