#define _CRT_SECURE_NO_WARNINGS 1

//牛客：[NOIP2006]明明的随机数
//https://ac.nowcoder.com/acm/contest/20960/1014


#include <iostream>
#include <set> // 引入set头文件，提供集合功能
#include <vector> // 引入vector头文件，但在此代码中未使用

using namespace std;

int main()
{
    int n; // 定义变量n，用于存储输入的数字个数
    cin >> n; // 从标准输入中读取n

    set<int> arr; // 使用set来存储整数，set会自动去重

    // 循环n次以读取输入的数字
    for (int i = 0; i < n; i++)
    {
        int x; // 定义变量x，用于存储每次输入的数字
        cin >> x; // 从标准输入中读取数字x
        arr.insert(x); // 将x插入到集合arr中，set会自动处理重复元素
    }

    // 输出集合的大小，即不同元素的数量
    cout << arr.size() << endl;

    // 迭代集合并输出所有元素
    for (set<int>::iterator it = arr.begin(); it != arr.end(); ++it)
    {
        cout << *it << ' '; // 输出当前元素，后面跟一个空格
    }

    return 0; // 程序结束
}
