#include "Logger.h"

#include <iostream>


Logger::Logger()
{
	// 简化初始化
}

Logger& Logger::getInstance()
{
	static Logger _instance;		// 把单例对象放到函数内部作为 局部 static 变量
	return _instance;
}

void Logger::log(const std::string& msg)
{
	std::cout << "[log] " << msg << std::endl;
}