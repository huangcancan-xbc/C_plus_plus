#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> w = { 50,65,58,72,78,53,82 };
    int C;
    cin >> C;
    sort(w.begin(), w.end());
    int i = 0, j = w.size() - 1, cnt = 0;
    while (i <= j)
    {
        if (w[i] + w[j] <= C)
        {
            i++;
            j--;
        }
        else
        {
            j--;
        }
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}