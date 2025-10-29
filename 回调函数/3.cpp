#include <iostream>
#include <string>
using namespace std;

// 定义一个函数指针类型：返回 string，参数 (int, string)
// 格式：typedef 返回值类型 (*类型名)(参数列表)
typedef string(*callback)(int, string);

// 回调函数：把字符串 s 拼接 x 次
string append(int x, string s)
{
    string res;
    for (int i = 0; i < x; ++i)
    {
        res += s;    // 拼接 x 次
    }
    return res;
}

// 测试函数：接收字符串 + 回调函数 + 次数
void test(string s, int x, callback cb)
{
    string ret = s + cb(x, "World");// 调用回调函数，得到拼接结果

    cout << ret << endl;
}

int main()
{
    test("Hello", 3, append);
    // 输出：HelloWorldWorldWorld

    return 0;
}