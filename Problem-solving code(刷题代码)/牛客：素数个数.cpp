//牛客：素数个数
//https://ac.nowcoder.com/acm/contest/97845/N
//参赛密码：517acm


#include <iostream>
#include <math.h>
using namespace std;

bool is(int x)
{
    if (x < 1)                              // 小于1的数不是素数
    {
        return false;
    }

    for (int i = 2; i <= sqrt(x); i++)      // 遍历2到sqrt(x)
    {
        if (x % i == 0)                     // 如果x能被i整除，则不是素数，直接返回false
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int t = 0;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int count = 0;

        for (int i = 2; i <= n; i++)
        {
            if (is(i))
            {
                count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}