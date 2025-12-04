#include <iostream>
#include <string>
using namespace std;

void solve()
{
    for (int num = 100; num <= 999; ++num)
    {
        int a = num / 100;
        int b = (num / 10) % 10;
        int c = num % 10;

        if (c > a && a > b)
        {
            int sum = a + b + c;
            int ji = a * b * c;

            if (sum == ji)
            {
                cout << "找到满足条件的三位数: " << num << endl;
                cout << "  -> 百位 a = " << a << endl;
                cout << "  -> 十位 b = " << b << endl;
                cout << "  -> 个位 c = " << c << endl;
                cout << "  -> 和 a+b+c = " << sum << endl;
                cout << "  -> 积 a*b*c = " << ji << endl;
            }
        }
    }
}

int main()
{
    solve();
    return 0;
}