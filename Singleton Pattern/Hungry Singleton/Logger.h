#pragma once
#include <string>

// 经典单例（饿汉）
// 程序一开始就把单例对象创建好，不用等第一次调用
// 不管用不用，程序启动时就创建
// 如果对象很重，或者依赖别的初始化顺序，可能不合适
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

	static Logger _instance;			// 声明唯一实例，程序开始就创建
};