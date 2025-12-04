#include <iostream>
using namespace std;

int h(int n)
{
    if (n == 1) return 1;
    return 2 * h(n - 1) + 1;
}

int main()
{
    int n;
    cin >> n;
    cout << n << "个盘片需要移动" << h(n) << "步" << endl;
    return 0;
}