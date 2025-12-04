#include <iostream>
using namespace std;

void solve()
{
    for (int y = 1; y <= 100; ++y)
    {
        int x = 10 * y - 2;

        for (int z = 0; z < 12; ++z)
        {
            int ret = 12 * (y - 1) - z;

            if (x == ret)
            {
                cout << "找到解:" << endl;
                cout << "  -> 船数 y = " << y << endl;
                cout << "  -> 年级人数 x = " << x << endl;
                cout << "  -> 条件2中最后一船剩余座位 z = " << z << endl;
                cout << "验证: " << x << " 人" << endl;
                cout << "按 10 人/船: " << y << " 船 * 10 座 - 2 座 = " << 10 * y - 2 << " 人" << endl;
                cout << "按 12 人/船: (" << y - 1 << " 船 * 12 座) - " << z << " 座 = " << 12 * (y - 1) - z << " 人" << endl;

                // break;
            }
        }
    }
}

int main()
{
    solve();
    return 0;
}