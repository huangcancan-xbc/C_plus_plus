#include <iostream>
using namespace std;

int g(int x, int y)
{
    if (y == 0) return x;
    return g(y, x % y);
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << a << "和" << b << "的最大公约数为" << g(a, b) << endl;
    return 0;
}