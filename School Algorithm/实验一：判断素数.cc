#include <iostream>
#include <cmath>
using namespace std;

bool check1(int n)
{
    if (n <= 1)
    {
        return false;
    }

    for (int i = 2; i < n; ++i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

bool cherck2(int n)
{
    if (n <= 1)
    {
        return false;
    }

    for (int i = 2; i <= sqrt(n); ++i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int x;
    while(cin>>x)
    {
        if(check1(x))
        {
            cout << x << "是素数" << endl;
        }
        else
        {
            cout << x << "不是素数" << endl;
        }
    }

    return 0;
}