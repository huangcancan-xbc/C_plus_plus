// 蓝桥·算法双周赛：打开石门
//https://www.lanqiao.cn/problems/19868/learning/?contest_id=209

//思路：代码通过遍历字符串统计 Q 和 L 的数量，并处理连续的相同字符，计算两种组合的总数，最后输出最小值。

#include <iostream> 
#include <string>    
using namespace std; 

int main() 
{
    string s; // 定义字符串 s 用于存储输入
    cin >> s; // 从标准输入读取字符串

    int q = 0, l = 0; // 初始化计数器 q 和 l，分别用于记录 'Q' 和 'L' 的出现次数
    int ans1 = 0, ans2 = 0; // 初始化 ans1 和 ans2 用于存储计算结果

    // 遍历字符串，统计 'Q' 和 'L' 的数量
    for (int x : s)
    {
        if (x == 'Q') // 如果字符是 'Q'
        {
            q++; // 'Q' 计数器加一
        }
        else if (x == 'L') // 如果字符是 'L'
        {
            l++; // 'L' 计数器加一
        }
    }

    // 在 ans1 中计算 'Q' 和 'L' 的组合，考虑到连续的 'Q'
    int q1 = q, l1 = l; // 复制原始计数值
    for (int i = 1; i < s.size(); i++) // 从第二个字符开始遍历字符串
    {
        if (s[i] == 'Q' && s[i - 1] == 'Q') // 如果当前字符和前一个字符都是 'Q'
        {
            q1--; // 减去一个 'Q'，表示这两个连续的 'Q' 只算一个
        }
    }
    ans1 = q1 + l; // ans1 = 剩余的 'Q' + 所有的 'L'

    // 在 ans2 中计算 'Q' 和 'L' 的组合，考虑到连续的 'L'
    for (int i = 1; i < s.size(); i++) // 从第二个字符开始遍历字符串
    {
        if (s[i] == 'L' && s[i - 1] == 'L') // 如果当前字符和前一个字符都是 'L'
        {
            l1--; // 减去一个 'L'，表示这两个连续的 'L' 只算一个
        }
    }
    ans2 = q + l1; // ans2 = 所有的 'Q' + 剩余的 'L'

    int outcome = min(ans1, ans2); // 计算 ans1 和 ans2 的最小值

    cout << outcome; // 输出结果

    return 0; // 返回 0，表示程序成功结束
}






// 优化后的代码
// 优化思路：
// 1. 遍历字符串，统计 'Q' 和 'L' 的数量，并处理连续的相同字符
// 2. 计算两种组合的总数，最后输出最小值

//假设输入字符串为 "LLQQQLLQ"：
//
//当 i 为 0，str[i] 是 'L'，进入 while 循环，j 依次增加，直到 j 等于 2（指向 'Q'）。
//while 循环结束时：
//j = 2，所以 i = j - 1，即 i = 1（指向最后一个 'L'）。
//外层 for 循环的下一次迭代时，i 会增加 1，变成 2，这样 for 循环会从 'Q' 开始处理，而不会重复统计连续的 'L'。

#include<iostream> 
using namespace std; 

#define int long long 

signed main() 
{ 
    string str; 
    cin >> str; 

    int ansL, ansQ; // 计数变量，分别用于 'L' 和 'Q'
    ansL = ansQ = 0; // 初始化为 0

    // 计算 'L' 的连续段数
    for (int i = 0; i < str.length(); i++) 
    { 
        if (str[i] == 'L') // 如果是 'L'
        { 
            int j = i; // 记录当前位置
            
            while (j < str.length() && str[j] == 'L')// 找到下一个不是 'L' 的字符，当 while 循环结束时，j 会指向下一个不同字符的位置
            {
                j++;
            }

            i = j - 1; // 跳过所有连续的 'L'，它指向当前处理的最后一个相同字符的索引
            ansL++; // 计数增加
        }
        else 
        {
            ansL++; // 不是 'L'，增加计数
        }
    }

    // 计算 'Q' 的连续段数
    for (int i = 0; i < str.length(); i++) 
    { 
        if (str[i] == 'Q') // 如果是 'Q'
        { 
            int j = i; // 记录当前位置
           
            while (j < str.length() && str[j] == 'Q') // 找到下一个不是 'Q' 的字符，当 while 循环结束时，j 会指向下一个不同字符的位置
            {
                j++;
            }

            i = j - 1; // 跳过所有连续的 'Q'，它指向当前处理的最后一个相同字符的索引
            ansQ++; // 计数增加
        }
        else 
        {
            ansQ++; // 不是 'Q'，增加计数
        }
    }

    cout << min(ansL, ansQ); // 输出 'L' 和 'Q' 段数的最小值
    return 0; // 程序结束
}
