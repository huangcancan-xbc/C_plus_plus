//转换偶数

#include <iostream>
#include <string>
using namespace std;

long long replace(long long x)
{
    if (x % 2 == 0)                             // 如果 x 是偶数，直接返回
    {
        return x;
    }

    string s = to_string(x);
    long long len = s.size();                   // 原数字的长度
    s += s;                                     // 拼接成 s + s

    // 滑动窗口，窗口大小为原始数字的长度
    for (long long left = 0; left < len; ++left) 
    {
        string sub = s.substr(left, len);       // 从 left 开始，长度为 len 的子串
        if (sub[sub.size() - 1] % 2 == 0)       // 检查子串的最后一位是否为偶数
        {  
            return stoll(sub);                  // 返回该子串转化成数字
        }
    }
    return -1;                                  // 如果没有找到偶数，返回 -1
}

int main()
{
    long long q = 0;
    cin >> q;

    while (q--) 
    {
        long long a = 0;
        cin >> a;

        long long ret = replace(a);
        cout << ret << endl;
    }

    return 0;
}
