#include <iostream>
#include <vector>
using namespace std;

int n = 5, r = 3;
vector<int> path;

void dfs(int start)
{
    if (path.size() == r)
    {
        for (int num : path) cout << num << " ";
        cout << endl;
        return;
    }
    for (int i = start; i <= n; i++)
    {
        path.push_back(i);
        dfs(i + 1);
        path.pop_back();
    }
}

int main()
{
    dfs(1);
    return 0;
}