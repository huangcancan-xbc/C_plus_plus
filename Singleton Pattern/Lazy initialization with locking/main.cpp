#include "Logger.h"
#include <iostream>
#include <thread>

void create_thread()
{
    Logger* log = Logger::getInstance();
    log->log("线程创建成功！");

    std::cout << "当前 log 实例地址：" << log << std::endl;
}

int main()
{
    for (int i = 0; i < 5; i++)
    {
        std::thread p(create_thread);
        p.join();
    }

    return 0;
}
