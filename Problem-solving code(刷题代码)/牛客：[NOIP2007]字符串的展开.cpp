//牛客：[NOIP2007]字符串的展开
//https://ac.nowcoder.com/acm/contest/20960/1001
//思路：
//1. 遍历字符串，遇到减号时，检查它是否符合展开条件，如果符合，则进行展开操作。
//2. 展开操作：
//   2.1 根据 p3 判断是正序展开还是逆序展开。
//   2.2 正序展开：
//      2.2.1 遍历减号两侧的字符，从 begin+1 到 end-1 逐个展开字符。
//      2.2.2 对于每个字符，根据 p1 判断是填充小写字母、大写字母还是星号，并根据 p2 进行字符重复填充。
//   2.3 逆序展开：
//      2.3.1 遍历减号两侧的字符，从 end-1 到 begin+1 逆序逐个展开字符。
//      2.3.2 对于每个字符，根据 p1 判断是填充小写字母、大写字母还是星号，并根据 p2 进行字符重复填充。
//3. 输出展开后的结果字符串。
//实际就是将一个字符串按照要求拷贝到另一个字符串中，遇到减号时，根据条件进行拷贝。


//放到这里，是为了方便阅读。不用再来回看题目了。
//p1 控制字符的大小写：1 表示小写，2 表示大写，3 表示用* 替代。
//p2 控制展开时每个字符重复的次数。
//p3 控制字符的顺序：1 表示顺序展开，2 表示逆序展开。

#include <iostream>
#include <string>
using namespace std;

int main()
{
    // 读取三个参数：p1, p2, p3 和字符串 s
    int p1 = 0, p2 = 0, p3 = 0;
    string s;
    string result;  // 用来存储最终展开后的结果字符串
    cin >> p1 >> p2 >> p3 >> s;

    // 获取输入字符串的长度
    int n = (int)s.size();

    // 遍历字符串的每个字符
    for (int i = 0; i < n; i++)
    {
        // 当遇到减号时，检查它是否符合展开条件
        if (s[i] == '-' && i > 0 && i < n - 1) // 确保减号不在字符串的开头或结尾
        {
            char begin = s[i - 1]; // 减号前的字符
            char end = s[i + 1];   // 减号后的字符

            // 判断减号两侧的字符是否是符合条件的字母或数字，且 begin < end
            if ((isdigit(begin) && isdigit(end) && begin < end) || (islower(begin) && islower(end) && begin < end))
            {
                // 如果两个字符相邻如 'd-e' 或 '3-4'，直接跳过减号
                if (begin + 1 == end)
                {
                    continue;
                }

                // 根据 p3 判断是正序展开还是逆序展开
                if (p3 == 1)
                {
                    // 正序展开
                    for (char c = begin + 1; c < end; c++) // 从 begin+1 到 end-1 逐个展开字符
                    {
                        char fillchar = c; // 默认是当前的字符 c

                        // 根据 p1 判断是填充小写字母、大写字母还是星号
                        if (p1 == 2 && islower(c))
                        {
                            fillchar = toupper(c); // 若 p1 为 2 并且是小写字母，转换为大写
                        }
                        else if (p1 == 3)
                        {
                            fillchar = '*'; // 若 p1 为 3，填充星号 '*'
                        }

                        // 根据 p2 进行字符重复填充
                        for (int j = 0; j < p2; j++)
                        {
                            result += fillchar; // 将填充的字符加入结果字符串
                        }
                    }
                }
                else
                {
                    // 逆序展开
                    for (char c = end - 1; c > begin; c--) // 从 end-1 到 begin+1 逆序逐个展开字符
                    {
                        char fillchar = c; // 默认是当前的字符 c

                        // 根据 p1 判断是填充小写字母、大写字母还是星号
                        if (p1 == 2 && islower(c))
                        {
                            fillchar = toupper(c); // 若 p1 为 2 并且是小写字母，转换为大写
                        }
                        else if (p1 == 3)
                        {
                            fillchar = '*'; // 若 p1 为 3，填充星号 '*'
                        }

                        // 根据 p2 进行字符重复填充
                        for (int j = 0; j < p2; j++)
                        {
                            result += fillchar; // 将填充的字符加入结果字符串
                        }
                    }
                }
            }
            else
            {
                // 如果减号两侧的字符不符合条件，直接保留减号
                result += '-';
            }
        }
        else
        {
            // 如果不是减号，直接将当前字符加入结果字符串
            result += s[i];
        }
    }

    // 输出展开后的结果字符串
    cout << result;
    return 0;
}







#include <iostream>

using namespace std;
int main()
{
    int p1, p2, p3;

    cin >> p1 >> p2 >> p3;  // 读取参数 p1, p2, p3

    char s[105];
    cin >> s;  // 读取字符串 s

    // 遍历字符串 s
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] != '-')
        {
            cout << s[i];  // 直接输出非 '-' 字符
        }
        else  // 处理 '-' 字符的展开情况
        {
            // 判断 '-' 左右字符是否为连续的字符或数字
            if (s[i - 1] < s[i + 1] &&
                ((s[i - 1] >= 'a' && s[i - 1] <= 'z' && s[i + 1] >= 'a' && s[i + 1] <= 'z') ||
                    (s[i - 1] >= '0' && s[i - 1] <= '9' && s[i + 1] >= '0' && s[i + 1] <= '9')))
            {
                // p1 == 1 时，小写字母
                if (p1 == 1)
                {
                    if (p3 == 1)  // 顺序展开
                    {
                        for (char c = s[i - 1] + 1; c < s[i + 1]; c++)
                        {
                            for (int j = 0; j < p2; j++)
                            {
                                if (c >= 'A' && c <= 'Z')  // 如果是大写字母，转换为小写
                                {
                                    char t = c + 32;
                                    cout << t;  // 输出转换为小写的字母
                                }
                                else
                                {
                                    cout << c;  // 输出原字符
                                }
                            }
                        }
                    }
                    else  // 逆序展开
                    {
                        for (char c = s[i + 1] - 1; c > s[i - 1]; c--)
                        {
                            for (int j = 0; j < p2; j++)
                            {
                                if (c >= 'A' && c <= 'Z')  // 如果是大写字母，转换为小写
                                {
                                    char t = c + 32;
                                    cout << t;  // 输出转换为小写的字母
                                }
                                else
                                {
                                    cout << c;  // 输出原字符
                                }
                            }
                        }
                    }
                }
                // p1 == 2 时，大写字母
                else if (p1 == 2)
                {
                    if (p3 == 1)  // 顺序展开
                    {
                        for (char c = s[i - 1] + 1; c < s[i + 1]; c++)
                        {
                            for (int j = 0; j < p2; j++)
                            {
                                if (c >= 'a' && c <= 'z')  // 如果是小写字母，转换为大写
                                {
                                    char t = c - 32;
                                    cout << t;  // 输出转换为大写的字母
                                }
                                else
                                {
                                    cout << c;  // 输出原字符
                                }
                            }
                        }
                    }
                    else  // 逆序展开
                    {
                        for (char c = s[i + 1] - 1; c > s[i - 1]; c--)
                        {
                            for (int j = 0; j < p2; j++)
                            {
                                if (c >= 'a' && c <= 'z')  // 如果是小写字母，转换为大写
                                {
                                    char t = c - 32;
                                    cout << t;  // 输出转换为大写的字母
                                }
                                else
                                {
                                    cout << c;  // 输出原字符
                                }
                            }
                        }
                    }
                }
                // p1 == 3 时，输出 *
                else
                {
                    for (int k = 0; k < s[i + 1] - s[i - 1] - 1; k++)
                    {
                        for (int j = 0; j < p2; j++)
                        {
                            cout << "*";  // 按需输出 '*' 代替字符
                        }
                    }
                }
            }
            // 如果左右字符不满足连续性条件，直接输出 '-'
            else
            {
                cout << s[i];
            }
        }
    }

    return 0;
}