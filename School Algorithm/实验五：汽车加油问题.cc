#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int d = 70;
    vector<int> a = { 20,70,30,60 };
    int curr = d - 20;
    int cnt = 0;
    for (int i = 0; i < a.size() - 1; i++)
    {
        if (curr < a[i])
        {
            cnt++;
            curr = d;
        }
        curr -= a[i];
    }
    cout << cnt << endl;
    return 0;
}