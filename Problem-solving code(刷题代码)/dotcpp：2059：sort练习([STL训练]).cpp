// dotcpp£∫2059£∫sort¡∑œ∞([STL—µ¡∑])
//https://www.dotcpp.com/oj/problem2059.html

#include<iostream>
#include <vector>
#include <set>
using namespace std;
int main()
{
    int n = 0, m = 0;
    cin >> n >> m;
    multiset<int> s;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }

    vector<int> v(s.begin(), s.end());

    for (int i = 0; i < m; i++)
    {
        cout << v[v.size() - 1 - i]<< " ";
    }

    cout << endl;
    return 0;
}