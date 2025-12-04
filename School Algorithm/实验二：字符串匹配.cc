#include <iostream>
#include <string>
using namespace std;

int solve(const string& s, const string& ss)
{
    int slen = s.size();
    int sslen = ss.size();

    if (sslen > slen)
    {
        return -1;
    }

    for (int i = 0; i <= slen - sslen; ++i)
    {
        int j = 0;

        while (j < sslen && s[i + j] == ss[j])
        {
            j++;
        }

        if (j == sslen)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    string s = "ABABCABABA";
    string ss = "ABABA";

    int index = solve(s, ss);

    if (index != -1)
    {
        cout << "模式串 \"" << ss << "\" 在主串中的起始位置是: " << index << endl;
    } 
    else
    {
        cout << "未在主串中找到模式串 \"" << ss << "\"。" << endl;
    }

    return 0;
}