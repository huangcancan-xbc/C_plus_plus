#pragma once
#include <string>
#include <mutex>

// 单例（双重检查锁）
// 第一次创建时加锁
// 后面已经创建好了，就不必每次加锁

// 注意：
// 加锁懒汉本身是线程安全的，因为整个创建过程被互斥锁保护了。
// 双重检查锁不是为了解决虚假唤醒，也不是因为加锁懒汉不安全，而是为了减少对象创建完成后每次访问都加锁的性能开销。
// 虚假唤醒通常出现在条件变量 condition_variable 的等待场景，不是单例模式里互斥锁初始化的问题。
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