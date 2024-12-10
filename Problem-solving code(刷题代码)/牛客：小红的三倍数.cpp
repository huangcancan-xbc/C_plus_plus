//牛客：小红的三倍数
//https://ac.nowcoder.com/acm/contest/97845/S
//参赛密码：517acm


#include <iostream>
using namespace std;

int main() 
{
    int n;
    cin >> n;

    long long ret = 0;

    for (int i = 0; i < n; ++i) 
    {
        string s;
        cin >> s;

        long long sum = 0;
        for (char c : s) 
        {
            sum += c - '0';
        }

        ret += sum % 3;
    }

    if (ret % 3 == 0) 
    {
        cout << "YES" << endl;
    }
    else 
    {
        cout << "NO" << endl;
    }

    return 0;
}