#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string str;
    getline(cin, str);
    vector<string> words;
    size_t start = 0;
    size_t pos = str.find(' ');

    while (pos != string::npos)
    {
        if (pos > start)
        {
            words.push_back(str.substr(start, pos - start));
        }
        start = pos + 1;
        pos = str.find(' ', start);
    }

    if (start < str.size())
    {
        words.push_back(str.substr(start));
    }

    for (const auto& word : words)
    {
        cout << word << endl;
    }

    return 0;
}