#include <iostream>
using namespace std;

int l(const char* s)
{
    if (*s == '\0') return 0;
    return 1 + l(s + 1);
}

int main()
{
    char str[100];
    cin >> str;
    cout << "字符个数:" << l(str) << endl;
    return 0;
}