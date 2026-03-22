#pragma once
#include <string>

// 单例（原始懒汉）
//第一次用的时候再创建对象
//用到时才创建
//线程不安全
//还要考虑释放内存
class Logger
{
public:
	static Logger* getInstance();		// 提供访问

	void log(const std::string& msg);	// 日志函数

private:

	Logger();	// 私有构造

	// 禁用拷贝
	Logger(const Logger&) = delete;
	Logger& operator=(const Logger&) = delete;

	static Logger* _instance;
};