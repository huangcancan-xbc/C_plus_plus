//牛客：最后DISCO（牛客小白月赛106）
//https://ac.nowcoder.com/acm/contest/97439/A


#include <iostream>
using namespace std;
int main()
{
    long long a = 0, b = 0, c = 0, d = 0;
    cin >> a >> b >> c >> d;
    long long sum = 1;
    if (a % 2 == 0)
    {
        sum = 2;
    }

    if (b == 0)
    {
        sum = 1;
    }

    sum=sum*c+d;

    if(sum%2==0)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES";
    }

    return 0;
}