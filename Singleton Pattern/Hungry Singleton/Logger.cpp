#include "Logger.h"

#include <iostream>

Logger Logger::_instance;

Logger::Logger()
{
	// 简化初始化
}

Logger& Logger::getInstance()
{
	return _instance;	// 不创建新的对象实例，直接返回现有的唯一实例
}

void Logger::log(const std::string& msg)
{
	std::cout << "[log] " << msg << std::endl;
}