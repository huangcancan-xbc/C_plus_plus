#pragma once
#include <string>

// 单例（Meyer's Singleton）
//懒加载：第一次调用时创建
//C++11 起线程安全
//不需要手动 new
//不用手动释放内存
class Logger
{
public:
	static Logger& getInstance();		// 提供访问

	void log(const std::string& msg);	// 日志函数

private:

	Logger();	// 私有构造

	// 禁用拷贝
	Logger(const Logger&) = delete;
	Logger& operator=(const Logger&) = delete;
};