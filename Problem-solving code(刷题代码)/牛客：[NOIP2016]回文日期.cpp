//牛客：[NOIP2016]回文日期
//https://ac.nowcoder.com/acm/contest/20960/1015


#include <iostream>
#include <string>
using namespace std;

// 判断闰年
int isLeapYear(int year)
{
    // 如果年份能被4整除但不能被100整除，或者能被400整除，则为闰年
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        return 1; // 是闰年
    }
    else
    {
        return 0; // 不是闰年
    }
}

int main()
{
    int begin = 0, end = 0; // 定义起始和结束日期
    cin >> begin >> end; // 输入起始和结束日期

    // 计算起始和结束年份
    int n = begin / 10000; // 起始年份
    int m = end / 10000; // 结束年份
    int ans = 0; // 用于记录回文日期的数量

    // 遍历年份，从起始年份到结束年份
    for (int i = n; i <= m; i++)
    {
        int tmp = i; // 临时变量存储当前年份
        int palindrome = i; // 初始化回文年份为当前年份

        // 生成回文日期
        while (tmp)
        {
            palindrome = palindrome * 10 + tmp % 10; // 反转当前年份以生成回文
            tmp /= 10; // 移除最后一位
        }

        // 获取回文日期的年、月、日
        int year = palindrome / 10000; // 获取年份
        int mouth = (palindrome / 100) % 100; // 获取月份
        int day = palindrome % 100; // 获取日期

        // 判断回文年月份是否合法
        if (mouth == 1 || mouth == 3 || mouth == 5 || mouth == 7 || mouth == 8 || mouth == 10 || mouth == 12)
        {
            // 31天的月份
            if (day >= 1 && day <= 31 && palindrome >= begin && palindrome <= end) // 检查日期是否合法
            {
                ans++; // 统计合法的回文日期
            }
        }
        else if (mouth == 4 || mouth == 6 || mouth == 9 || mouth == 11)
        {
            // 30天的月份
            if (day >= 1 && day <= 30 && palindrome >= begin && palindrome <= end)
            {
                ans++; // 统计合法的回文日期
            }
        }
        else if (mouth == 2)
        {
            // 2月的处理
            if (isLeapYear(year)) // 判断是否为闰年
            {
                // 闰年2月最多29天
                if (day >= 1 && day <= 29 && palindrome >= begin && palindrome <= end)
                {
                    ans++; // 统计合法的回文日期
                }
            }
            else
            {
                // 非闰年2月最多28天
                if (day >= 1 && day <= 28 && palindrome >= begin && palindrome <= end)
                {
                    ans++; // 统计合法的回文日期
                }
            }
        }
    }

    // 输出回文日期的总数量
    cout << ans << endl;

    return 0; // 程序结束
}



//一个非常巧妙的构造回文串的方法
#include<iostream>
#include<string>

using namespace std;

int main()
{
    // 1. 定义数组来存储每个月的天数，从下标1开始，方便访问
    int month[13] = { 0,31,29,30,31,30,31,31,31,30,31,30,31 };

    // 注意：我们只考虑闰年2月的29天，因此可以用29来构造回文日期

    int x, y; // 定义输入的日期范围
    scanf("%d%d", &x, &y); // 输入范围的起始和结束日期

    int count = 0; // 用于计数符合条件的回文日期

    // 2. 构造回文日期
    for (int i = 1; i <= 12; i++) // 遍历每个月
    {
        for (int j = 1; j <= month[i]; j++) // 遍历每个月的天数
        {
            // 将日期拼接成回文格式
            // 例如：对于日期10月12日（10/12），j=12, i=10
            // 先构建回文的一半（年、日的末位和月的末位）
            int k = (j % 10) * 1000 + (j / 10) * 100 + (i % 10) * 10 + (i / 10);
            // k现在代表日期的前半部分（例如 21 01）
            
            // 详细过程：
            //(j % 10) * 1000：获取日期的个位数（例如12的个位是2），并将其放在千位。
            //(j / 10) * 100：获取日期的十位数（例如12的十位是1），并将其放在百位。
            //(i % 10) * 10：获取月份的个位数（例如10的个位是0），并将其放在十位。
            //(i / 10)：获取月份的十位数（例如10的十位是1），并直接放在个位。

            // 然后拼接回文的后半部分
            k = k * 10000 + i * 100 + j; // 完成回文日期（例如 10 12）

            // 3. 检查构造的回文日期是否在范围内
            if (x <= k && k <= y)
            {
                count++; // 如果符合条件，计数加一
            }
        }
    }

    cout << count; // 输出符合条件的回文日期总数
}
