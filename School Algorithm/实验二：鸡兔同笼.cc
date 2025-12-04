#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool check(int num)
{
    string s = to_string(num);
    for (char c : s)
    {
        if (c < '0' || c > '5')
        {
            return false;
        }
    }
    
    return true;
}

void solve()
{
    for (int n = 50; n <= 249; ++n)
    {
        int ji = 2 * n;
        int tu = 4 * n;

        if (ji >= 100 && ji <= 999 && tu >= 100 && tu <= 999)
        {
            if (check(ji) && check(tu))
            {
                cout << "找到解: 鸡和兔的数量 n = " << n << endl;
                cout << "  -> 鸡脚数 (2n) = " << ji << endl;
                cout << "  -> 兔脚数 (4n) = " << tu << endl;
            }
        }
    }
}

int main()
{
    solve();
    return 0;
}