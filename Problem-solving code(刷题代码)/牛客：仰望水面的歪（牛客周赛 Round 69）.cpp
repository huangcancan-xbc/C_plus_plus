//牛客：仰望水面的歪（牛客周赛 Round 69）
//https://ac.nowcoder.com/acm/contest/96115/C


//#include <bits/stdc++.h>
#include <iostream>                         // 标准输入输出库
#include <cmath>                            // 数学函数库
using namespace std;

int main()
{
    long long n = 0, h = 0;
    cin >> n >> h;

    while (n--)
    {
        long long x = 0, y = 0, z = 0;
        cin >> x >> y >> z;

        z = h - z + h;                      // 调整 z 的坐标，计算 "仰望水面" 所需的镜像高度

        long long a = __gcd(x, y);          // 计算 x 和 y 的最大公约数（GCD）

        long long b = __gcd(y, z);          // 计算 y 和 z 的最大公约数

        long long c = __gcd(a, b);          // 计算 x, y, z 三者的最大公约数

        // 输出化简后的 x, y, z
        cout << x / c << " " << y / c << " " << z / c << endl;
    }

    return 0;
}
