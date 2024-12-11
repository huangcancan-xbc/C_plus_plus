//P10424 [蓝桥杯 2024 省 B] 好数
//https://www.luogu.com.cn/problem/P10424


#include <iostream>
using namespace std;

int main()
{
    int n, ret = 0;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int k = 1, temp = i, flag = 0;                  // flag = 1 表示不是好数
        while (temp)                                    // 计算每位数字的奇偶性
        {
            if (k % 2 == 1 && temp % 2 != 1)            // 如果该位是奇数，数字不是奇数，则不是好数
            {
                flag = 1;                               // 标记为不是好数，跳出循环
                break;
            }
            if (k % 2 == 0 && temp % 2 != 0)            // 如果该位是偶数，数字不是偶数，则不是好数
            {
                flag = 1;                               // 标记为不是好数，跳出循环
                break;
            }
            
            k++, temp /= 10;                            // 计算下一位
        }

        if (flag)                                       // 如果不是好数，跳过
        {
            continue;
        }
        else                                            // 如果是好数，计数
        {
            ret++;
        }
    }

    cout << ret;

    return 0;
}