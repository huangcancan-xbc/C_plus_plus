#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(vector<int>& v)
{
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    if (n % 2 == 0)
    {
        cout << "偶数个中偶数按升序排序：" << endl;
        vector<int> temp;
        for (int i = 0; i < n; i++)
        {
            if (v[i] % 2 == 0)
            {
                temp.push_back(v[i]);
            }
        }
        sort(temp.begin(), temp.end());
        print(temp);
    }
    else
    {
        cout << "奇数个中奇数按降序排序：" << endl;
        vector<int> temp;
        for (int i = 0; i < n; i++)
        {
            if (v[i] % 2 != 0)
            {
                temp.push_back(v[i]);
            }
        }
        sort(temp.begin(), temp.end(), greater<int>());
        print(temp);
    }

    return 0;
}