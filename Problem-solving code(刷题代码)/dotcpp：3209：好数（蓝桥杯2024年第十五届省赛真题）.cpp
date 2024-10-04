//dotcpp：3209：好数（蓝桥杯2024年第十五届省赛真题）
//https://www.dotcpp.com/oj/problem3209.html

#include <iostream>
using namespace std;

// 函数：判断一个数是否为好数
bool isgoodnumber(long long n)
{
    int count = 0; // 记录数字的位数
    long long temp = n; // 保存原始数字以便后续使用
    int good = 0; // 记录符合条件的位数数量

    // 计算数字 n 的总位数
    while (n != 0)
    {
        count++; // 位数加一
        n /= 10; // 将 n 除以 10，去掉最后一位
    }

    n = temp; // 重置 n，以便再次遍历每一位

    // 遍历每一位数字
    for (long long i = 1; i <= count; i++) // 从第一位到最后一位
    {
        int current = n % 10; // 获取当前位的数字

        // 判断当前位应该是奇数还是偶数
        if (i % 2 == 0 && current % 2 == 0) // 如果是偶数位且当前数字为偶数
        {
            good++; // 计数器加一，表示符合条件
        }
        else if (i % 2 == 1 && current % 2 == 1) // 如果是奇数位且当前数字为奇数
        {
            good++; // 计数器加一，表示符合条件
        }

        n /= 10; // 移到下一位
    }

    // 如果符合条件的位数数量等于总位数，则返回 true（表示是好数）
    return (good == count);
}

int main()
{
    long long n = 0; // 声明变量 n
    cin >> n; // 从标准输入读取一个正整数 n

    long long ans = 0; // 用于计数的变量，记录好数的数量

    // 遍历从 1 到 n 的每一个整数
    for (long long i = 1; i <= n; i++)
    {
        if (isgoodnumber(i)) // 判断当前数 i 是否为好数
        {
            ans++; // 如果是好数，计数器加一
        }
    }

    cout << ans; // 输出好数的总数量
    return 0; // 程序结束
}
