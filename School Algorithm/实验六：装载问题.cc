#include <iostream>
#include <vector>
using namespace std;

vector<int> w = { 2,9,5,6,3 };
int n = 5, W;

bool dfs(int idx, int sum)
{
    if (sum == W) return true;
    if (idx >= n || sum > W) return false;
    if (dfs(idx + 1, sum + w[idx])) return true;
    if (dfs(idx + 1, sum)) return true;
    return false;
}

int main()
{
    while (1)
    {
        cin >> W;
        cout << (dfs(0, 0) ? "true" : "false") << endl;
    }
    return 0;
}