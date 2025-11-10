#include "head.hpp"
#include <iostream>
using namespace std;


//测试非类型模板参数
void test1()
{
    // 实例化时指定 N=5
    t1<int, 5> arr1; // 创建一个大小为 5 的 int 数组
    cout << "arr1 size: " << arr1.size() << endl; // 输出: 5
    arr1.fill(10);
    arr1.print(); // 输出: 10 10 10 10 10

    t1<double, 3> arr2; // 创建一个大小为 3 的 double 数组
    cout << "arr2 size: " << arr2.size() << endl; // 输出: 3
    arr2.fill(3.14);
    arr2.print(); // 输出: 3.14 3.14 3.14

    cout << endl << endl;
}

//测试函数模板特化
void test2()
{
    int a = 10, b = 20;
    cout << "t2(10, 20): " << t2(a, b) << endl; // 调用通用版本
    cout << "t2(10, 10): " << t2(a, a) << endl; // 调用通用版本

    string str1 = "Hello";
    string str2 = "World";
    string str3 = "Hello";
    cout << "t2(str1, str2): " << t2(str1, str2) << endl; // 调用特化版本 (string)
    cout << "t2(str1, str3): " << t2(str1, str3) << endl; // 调用特化版本 (string)

    cout << endl << endl;
}

//测试类模板特化
void test3()
{
    // 通用模板
    t3<int, string> p1(1, "Generic");
    p1.print();

    // 全特化
    t3<int, double> p2(2, 2.5);
    p2.print();

    // 偏特化 (指针)
    int val1 = 100;
    double val2 = 200.5;
    t3<int*, double*> p3(&val1, &val2);
    p3.print(); // 注意这里打印的是指针指向的值

    // 偏特化 (相同类型)
    t3<float, float> p4(1.1f, 2.2f);
    p4.print();

    cout << endl << endl;
}

int main()
{
    test1();
    test2();
    test3();

    return 0;
}