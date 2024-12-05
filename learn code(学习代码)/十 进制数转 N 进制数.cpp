//十 进制转 N 进制

//支持从 2 进制到 36 进制（由于 'A'~'Z' 的字母范围）
//如果要支持更高的进制，比如 62 进制（含大小写字母），需要扩展字符表，例如添加 'a'~'z'：
//char ch[63] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";


#include <iostream>
using namespace std;
long long n, base, len;     // n: 要转换的数, base: 目标进制, len: 保存转换结果的长度
char s[260];                // 用于存储转换后的字符结果（十进制数为最大 10 ^ 77，其二进制表示长度约为 256 位）
int main()
{
    cin >> n >> base;                       // 输入要转换的数和目标进制

    // 进制转换核心逻辑
    while (n)                               // 当 n 不为 0 时继续循环
    {
        if (n % base < 10)                  // 处理结果小于 10 的情况
        {
            s[len] = n % base + '0';        // 将数字转换为对应字符
        }
        else                                // 处理结果大于等于 10 的情况
        {
            s[len] = n % base - 10 + 'A';   // 将结果转换为大写字母 (A~Z)
        }

        len++;                              // 记录当前长度
        n /= base;                          // 更新 n 的值
    }

    // 翻转字符串
    for (int i = 0; i < len / 2; i++)       // 只需交换一半字符即可完成翻转，如果到 len 就相当于没有翻转
    {
        int temp = s[i];                    // 暂存当前字符
        s[i] = s[len - 1 - i];              // 将后面的字符移到前面
        s[len - 1 - i] = temp;              // 将暂存的字符移到后面
    }

    cout << s << endl;                      // 输出转换后的结果

    return 0;
}



#include <iostream>
using namespace std;
long long n, base, len;                     // n: 要转换的数, base: 目标进制, len: 保存转换结果的长度
char s[260];                                // 用于存储转换后的字符结果（十进制数为最大 10 ^ 77，其二进制表示长度约为 256 位）

int main()
{
    cin >> n >> base;                       // 输入要转换的数和目标进制

    char ch[50] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";   // 预定义的字符表，用于快速查找对应字符

    // 进制转换核心逻辑
    while (n)                               // 当 n 不为 0 时继续循环
    {
        s[len] = ch[n % base];              // 使用字符表直接获取对应字符
        len++;                              // 更新结果字符串长度
        n /= base;                          // 更新 n 的值
    }

    // 翻转字符串
    for (int i = 0; i < len / 2; i++)       // 只需交换一半字符即可完成翻转
    {
        int temp = s[i];                    // 暂存当前字符
        s[i] = s[len - 1 - i];              // 将后面的字符移到前面
        s[len - 1 - i] = temp;              // 将暂存的字符移到后面
    }

    cout << s << endl;                      // 输出转换后的结果

    return 0;
}




//**封装成函数模板进行记忆**：

// 第一种：

//#include <iostream>
//using namespace std;
long long n, base, len;
char s[260];
void Base_conversion(long long n, int base, char s[])
{
    while (n)
    {
        if (n % base < 10)
        {
            s[len] = n % base + '0';
        }
        else
        {
            s[len] = n % base - 10 + 'A';
        }

        len++;
        n /= base;
    }

    for (int i = 0; i < len / 2; i++)
    {
        int temp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = temp;
    }
}
//int main()
//{
//    cin >> n >> base;
//    Base_conversion（n, base, s);
//    cout << s << endl;
//
//    return 0;
//}


// 第二种：

//#include <iostream>
//using namespace std;
long long n, base, len;
char s[260];
void Base_conversion(long long n, int base, char s[])
{
    char ch[50] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    while (n)
    {
        s[len] = ch[n % base]; 
        len++;
        n /= base;
    }

    for (int i = 0; i < len / 2; i++)
    {
        int temp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = temp;
    }
}
//int main()
//{
//    cin >> n >> base;
//    Base_conversion（n, base, s);
//    cout << s << endl;
//
//    return 0;
//}







// 第三种（推荐）：
#include <algorithm>//reverse()
long long n, base, len;
char s[260];
void Base_conversion(long long n, int base, char s[])
{
    if (n == 0)
    {
        cout << "0";
        return;
    }

    while (n)
    {
        if (n % base < 10)
        {
            s[len++] = n % base + '0';
        }
        else
        {
            s[len++] = n % base - 10 + 'A';
        }
        n /= base;
    }

    reverse(s, s + len);
}


// 第四种（推荐）：
#include <algorithm>//reverse()
#include <vector>
long long n, base, len;
vector<char> s;
void Base_conversion(long long n, int base, vector<char>& s)
{
    if (n == 0)
    {
        s.push_back('0');
        return;
    }

    while (n)
    {
        if (n % base < 10)
        {
            s.push_back(n % base + '0');
        }
        else
        {
            s.push_back(n % base - 10 + 'A');
        }
        n /= base;
    }

    reverse(s.begin(), s.end());
}




// 其他：
// 字符集，用于表示 1 到 64 进制
const string ch = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz+/";

// 转换函数：将十进制数转换为任意 1 到 64 进制
string Base_conversion(long long n, int base)           // n:十进制数，base:目标进制数
{
    string result = "";

    if (n == 0)
    {
        return "0";
    }

    // 进行除法取余操作
    while (n > 0)
    {
        result = ch[n % base] + result;                 // 余数对应字符
        n = n / base;                                   // 商继续作为下次除数
    }

    return result;
}