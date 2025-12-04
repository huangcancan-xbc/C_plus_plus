#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> A = { 3,4,3,1 };
    vector<int> B = { 1,2,2,6 };
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    int a = 0, b = 0, res = 0;
    while (a < A.size() && b < B.size())
    {
        if (A[a] <= B[b])
        {
            res++;
            a++;
            b++;
        }
        else
        {
            a++;
        }
    }
    cout << res << endl;
    return 0;
}