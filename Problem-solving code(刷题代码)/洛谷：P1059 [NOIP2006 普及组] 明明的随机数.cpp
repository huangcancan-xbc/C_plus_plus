#define _CRT_SECURE_NO_WARNINGS 1

//洛谷：P1059 [NOIP2006 普及组] 明明的随机数
//https://www.luogu.com.cn/problem/P1059

#include <iostream>  // 引入标准输入输出库
#include <vector>    // 引入动态数组库（vector）
#include <set>       // 引入集合库（set）
using namespace std;

int main()
{
    int n;
    // 读取整数 n，表示将要输入的整数个数
    cin >> n;

    // 定义一个集合 set，用于存储输入的整数，且自动去重
    set<int> vis;

    // 循环读取 n 个整数
    for (int i = 0; i < n; i++)
    {
        int x;
        // 读取当前输入的整数 x
        cin >> x;
        // 将 x 插入到集合 vis 中，集合会自动去除重复元素
        vis.insert(x);
    }

    // 输出集合 vis 中元素的个数，这个个数是去重后的数量
    cout << vis.size() << endl;

    // 使用集合 vis 的元素初始化一个 vector 动态数组 arr
    vector<int> arr(vis.begin(), vis.end());

    // 遍历动态数组 arr 并输出其中的元素
    for (auto i = arr.begin(); i != arr.end(); i++)
    {
        // 输出每个元素，并以空格分隔
        cout << *i << " ";
    }

    // 程序正常结束
    return 0;
}
