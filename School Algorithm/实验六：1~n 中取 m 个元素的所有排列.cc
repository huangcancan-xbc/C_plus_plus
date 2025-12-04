#include <iostream>
#include <vector>
using namespace std;

int n = 3, m = 2;
vector<int> path;
vector<bool> used(n + 1, false);

void dfs()
{
    if (path.size() == m)
    {
        for (int num : path) cout << num << " ";
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!used[i])
        {
            used[i] = true;
            path.push_back(i);
            dfs();
            path.pop_back();
            used[i] = false;
        }
    }
}

int main()
{
    dfs();
    return 0;
}