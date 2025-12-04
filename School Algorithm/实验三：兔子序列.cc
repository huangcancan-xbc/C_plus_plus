#include <iostream>
using namespace std;

int f(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    return f(n - 1) + f(n - 2);
}

int main()
{
    int n;
    while (cin >> n)
    {
        cout << "第" << n << "月的兔子数：" << f(n) << endl;
    }
    return 0;
}