#pragma once
#include <string>
#include <mutex>

// 单例（加锁懒汉）
//懒加载，同时用锁保护第一次创建
//线程安全
//每次调用都加锁，性能一般
//写法麻烦
//仍然要处理释放问题
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
	static std::mutex _mutex;
};