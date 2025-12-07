#include <iostream>
#include <string>
#include "hash.hpp"

void test1()
{
    HashBucket<int> hb;
    
    // 插入测试
    hb.Insert(10);
    hb.Insert(20);
    hb.Insert(30);
    hb.Insert(15);
    hb.Insert(25);
    
    std::cout << "元素个数: " << hb.Size() << std::endl;
    std::cout << "负载因子: " << hb.getLF() << std::endl;
    
    // 查找测试
    auto node = hb.Find(20);
    if (node)
    {
        std::cout << "找到元素: " << node->_data << std::endl;
    }
    
    // 查找/包含测试
    std::cout << "包含15: " << (hb.Contains(15) ? "是" : "否") << std::endl;
    std::cout << "包含99: " << (hb.Contains(99) ? "是" : "否") << std::endl;
    
    // 删除测试
    bool ret = hb.Erase(20);
    std::cout << "删除20: " << (ret ? "成功" : "失败") << std::endl;
    std::cout << "删除后元素个数: " << hb.Size() << std::endl;
    std::cout << "删除后包含20: " << (hb.Contains(20) ? "是" : "否") << std::endl;
    
    std::cout << std::endl;
}

void test2()
{
    HashBucket<std::string> hb;
    
    hb.Insert("hello");
    hb.Insert("world");
    hb.Insert("test");
    hb.Insert("hash");
    
    std::cout << "字符串元素个数: " << hb.Size() << std::endl;
    
    // 查找测试
    auto node = hb.Find("world");
    if (node)
    {
        std::cout << "找到字符串: " << node->_data << std::endl;
    }
    
    // 删除测试
    hb.Erase("test");
    std::cout << "删除test后元素个数: " << hb.Size() << std::endl;
    
    std::cout << std::endl;
}

void test3()
{
    HashBucket<int> hb;
    
    for (int i = 1; i <= 10; i++)
    {
        hb.Insert(i * 10);
    }
    
    std::cout << "使用迭代器遍历: ";
    for (auto it = hb.begin(); it != hb.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    std::cout << "使用范围for遍历: ";
    for (const auto& val : hb)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    
    std::cout << std::endl;
}

void test4()
{
    HashBucket<int> hb(3, 0.7);  // 小初始容量，低负载因子
    
    std::cout << "初始桶数量: " << hb.BucketCount() << std::endl;
    
    // 插入足够多元素触发扩容
    for (int i = 0; i < 20; i++)
    {
        hb.Insert(i);
        std::cout << "插入" << i << "后，元素数: " << hb.Size() << "，桶数量: " << hb.BucketCount() << "，负载因子: " << hb.getLF() << std::endl;
    }
    
    std::cout << "扩容后数据验证:" << std::endl;
    for (int i = 0; i < 20; i++)
    {
        if (!hb.Contains(i))
        {
            std::cout << "错误: 找不到元素 " << i << std::endl;
        }
    }
    std::cout << "所有元素验证通过!" << std::endl;
    
    std::cout << std::endl;
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    
    return 0;
}