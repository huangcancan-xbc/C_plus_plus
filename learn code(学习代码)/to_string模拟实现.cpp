//to_string模拟实现以及lambda表达式的自定义比较函数

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// 自定义将整型转换为字符串的函数
string intToString(int num) 
{
    string result;
    // 处理 0 的情况
    if (num == 0) 
        return "0";

    // 将数字转换为字符串
    while (num > 0) 
    {
        char digit = '0' + num % 10;  // 获取最后一位数字并转换为字符
        result = digit + result;  // 将该字符加入结果的前面
        num /= 10;  // 移除最后一位数字
    }

    return result;
}

// 自定义的比较函数，替代 Lambda 表达式
bool customCompare(const string& s1, const string& s2) 
{
    return s1 + s2 > s2 + s1;  // 按照拼接后字典序比较
}

string largestNumber(vector<int>& nums) 
{
    // 将所有的数字转化为字符串
    vector<string> strs;
    for (int x : nums) 
    {
        strs.push_back(intToString(x));  // 手动转换
    }

    // 使用自定义的比较函数进行排序
    sort(strs.begin(), strs.end(), customCompare);

    // 提取出结果
    string ret;
    for (const string& s : strs) 
    {
        ret += s;
    }

    // 如果第一个字符是'0'，则整个数列都是0
    if (ret[0] == '0') 
        return "0";

    return ret;
}

int main() 
{
    vector<int> nums = { 3, 30, 34, 5, 9 };
    cout << largestNumber(nums) << endl;

    return 0;
}