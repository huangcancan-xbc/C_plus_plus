//牛客：Captcha Cracker
//https://ac.nowcoder.com/acm/contest/20960/1007

#include <iostream>
#include <string>
using namespace std;
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        string copy;

        cin >> s;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0' || s[i] == '2' || s[i] == '4' || s[i] == '6' || s[i] == '9')
            {
                copy += s[i];
            }
            else if (s[i] == 'z' && s[i + 1] == 'e' && s[i + 2] == 'r' && s[i + 3] == 'o')
            {
                copy += '0';
                i += 3;
            }
            else if (s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o')
            {
                copy += '2';
                i += 2;
            }
            else if (s[i] == 'f' && s[i + 1] == 'o' && s[i + 2] == 'u' && s[i + 3] == 'r')
            {
                copy += '4';
                i += 3;
            }
            else if (s[i] == 's' && s[i + 1] == 'i' && s[i + 2] == 'x')
            {
                copy += '6';
                i += 2;
            }
            else if (s[i] == 'n' && s[i + 1] == 'i' && s[i + 2] == 'n' && s[i + 3] == 'e')
            {
                copy += '9';
                i += 3;
            }
        }

        cout << copy << endl;
    }
    return 0;
}





#include <iostream>
#include <string>
using namespace std;

int main()
{
    int T;
    cin >> T;  // 读取测试用例数量

    while (T--)  // 循环处理每一组测试数据
    {
        string s;
        cin >> s;  // 读取字符串
        string result;  // 存储结果字符串

        for (int i = 0; i < s.size(); i++)
        {
            // 检查单个字符数字
            if (s[i] == '0' || s[i] == '2' || s[i] == '4' || s[i] == '6' || s[i] == '9')
            {
                result += s[i];  // 将数字字符添加到结果中
            }

            // 检查4个字符的单词
            if (i + 3 < s.size())  // 确保不会越界
            {
                string c = s.substr(i, 4);
                if (c == "zero")
                {
                    result += '0';  // 添加 '0'
                    i += 3;  // 跳过后面的字符
                    continue;  // 继续外层循环
                }
                else if (c == "four")
                {
                    result += '4';  // 添加 '4'
                    i += 3;  // 跳过后面的字符
                    continue;  // 继续外层循环
                }
                else if (c == "nine")
                {
                    result += '9';  // 添加 '9'
                    i += 3;  // 跳过后面的字符
                    continue;  // 继续外层循环
                }
            }

            // 检查3个字符的单词
            if (i + 2 < s.size())  // 确保不会越界
            {
                string c = s.substr(i, 3);
                if (c == "two")
                {
                    result += '2';  // 添加 '2'
                    i += 2;  // 跳过后面的字符
                    continue;  // 继续外层循环
                }
                else if (c == "six")
                {
                    result += '6';  // 添加 '6'
                    i += 2;  // 跳过后面的字符
                    continue;  // 继续外层循环
                }
            }
        }

        cout << result << endl;  // 输出结果
    }

    return 0;
}






#include <iostream>
#include <string>
#include <unordered_map> // 引入unordered_map
using namespace std;

int main()
{
    int t;
    cin >> t;

    // 使用unordered_map存储数字对应的字符串
    unordered_map<string, char> numMap = {
        {"zero", '0'},
        {"two", '2'},
        {"four", '4'},
        {"six", '6'},
        {"nine", '9'}
    };

    while (t--)
    {
        string s;
        string copy; // 存储结果

        cin >> s;

        for (int i = 0; i < s.size(); i++)
        {
            // 检查单个数字
            if (s[i] == '0' || s[i] == '2' || s[i] == '4' || s[i] == '6' || s[i] == '9')
            {
                copy += s[i]; // 直接加入
            }
            else
            {
                // 处理数字的单词形式
                // 这里要检查每个单词
                for (const auto& pair : numMap)
                {
                    const string& word = pair.first; // 单词
                    char digit = pair.second;         // 对应的数字

                    // 如果当前字符与单词的第一个字符匹配
                    if (s.substr(i, word.size()) == word)
                    {
                        copy += digit; // 加入对应的数字
                        i += word.size() - 1; // 移动索引，word.size() 返回匹配字符串的长度。
                        //如果你直接加上这个长度，下一次循环时 i 会指向当前匹配字符串的下一个字符，但由于 for 循环会增加 i 1，
                        //所以需要减去 1，确保在 for 循环中 i 的值指向下一个未处理字符。
                        //这行代码的实际效果是将 i 更新为当前字符串中匹配字符之后的位置，使得在下一次循环时，跳过已经匹配的部分，继续处理下一个字符。
                        break; // 退出循环
                    }
                }
            }
        }

        cout << copy << endl; // 输出结果
    }
    return 0;
}
