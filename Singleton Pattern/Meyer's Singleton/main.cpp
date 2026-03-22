#include "Logger.h"
#include <iostream>

int main()
{
    Logger& log1 = Logger::getInstance();
    Logger& log2 = Logger::getInstance();

    if (&log1 == &log2)
    {
        std::cout << "log1 和 log2 是同一个实例！" << std::endl;
    }
    else
    {
        std::cout << "log1 和 log2 不是同一个实例！" << std::endl;
    }

    std::cout << "log1的地址：" << &log1 << std::endl << "log2的地址：" << &log2 << std::endl;

    log1.log("这是一条测试日志！");
    log2.log("这也是一条测试日志！");

    Logger& log3 = Logger::getInstance();
    std::cout << "log3的地址：" << &log3 << std::endl;

    return 0;
}
