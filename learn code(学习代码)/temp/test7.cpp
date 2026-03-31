#include <iostream>
#include <fstream>
#include <string>
#include <mutex>
using namespace std;

// 使用宏简化调用
#define LOG_INFO(msg) Log::getInstance().info(msg)
#define LOG_ERROR(msg) Log::getInstance().error(msg)

class Log
{
public:
	// 静态方法，获取唯一实例，（懒汉，C++11起线程安全）
	static Log& getInstance()
	{
		static Log instance;
		return instance;
	}

	// 禁用拷贝构造和赋值运算符
	Log(const Log&) = delete;
	Log operator=(const Log&) = delete;

	// 参数：日志级别，日志信息
	void log(const string& level, const string& message)
	{
		lock_guard<mutex> lock(log_mtx);

		time_t now = time(nullptr);		// 获取当前时间
		//tm* ltm = localtime(&now);		// 转换为本地时间（微软认为这个接口线程不安全，建议用下面的）
		tm ltm;
		localtime_s(&ltm, &now);

		w_file << "[" << 1900 + ltm.tm_year << "-"		// 从1900年开始计数
			<< 1 + ltm.tm_mon << "-"					// 月份从0开始计数
			<< ltm.tm_mday << " "						// 日
			<< ltm.tm_hour << ":"						// 时
			<< ltm.tm_min << ":"						// 分
			<< ltm.tm_sec << "] "						// 秒
			<< "[" << level << "] "						// 日志级别
			<< message << endl;							// 日志信息
	}

	void info(const string& msg)
	{
		log("INFO", msg);
	}

	void error(const string& msg)
	{
		log("ERROR", msg);
	}

	void debug(const string& msg)
	{
		log("DEBUG", msg);
	}
private:
	// 私有构造函数（单例的核心）
	Log()
	{
		w_file.open("log.txt", ios::app);	// 追加写入指定文件
	}

	fstream w_file;		// 写文件
	mutex log_mtx;		// 互斥锁
};


int main()
{
	Log& log = Log::getInstance();	// 获取唯一实例
	log.info("这是一条正常的日志信息");
	log.error("这是一条错误的日志信息");
	log.debug("这是一条调试的日志信息");


	LOG_INFO("程序启动");    // 写入 INFO 级日志
	LOG_ERROR("这是一个错误测试");  // 写入 ERROR 级日志
	LOG_INFO("程序结束");    // 写入 INFO 级日志

	return 0;
}