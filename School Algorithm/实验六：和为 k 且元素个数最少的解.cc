#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> a = { 2,9,5,6,3 };
vector<int> best, path;
int n = 5, k, min_len = INT_MAX;

void topk(int idx, int sum, int cnt)
{
    if (sum == k)
    {
        if (cnt < min_len)
        {
            min_len = cnt;
            best = path;
        }
        return;
    }
    if (idx >= n || sum > k || cnt >= min_len) return;
    path.push_back(a[idx]);
    topk(idx + 1, sum + a[idx], cnt + 1);
    path.pop_back();
    topk(idx + 1, sum, cnt);
}

int main()
{
    k = 10;
    topk(0, 0, 0);
    for (int num : best) cout << num << " ";
    cout << endl;
    return 0;
}