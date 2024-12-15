//牛客：abb（A组，B组）（2023年第六届传智杯程序设计挑战赛初赛）
//https://ac.nowcoder.com/acm/contest/71300/E


#include <bits/stdc++.h>
using namespace std;
int ci[100001];
int main()
{
    long long  n;
    cin >> n;
    long long ret = 0;

    unordered_map<char, long long> map;

    string s;
    cin >> s;

    for (long long i = n - 1; i >= 0; i--)              // 倒序遍历字符串
    {
        ++map[s[i]];                                    // 统计字符频率
        ci[i] = map[s[i]];                              // 记录字符频率的累积数组
    }

    for (long long i = n - 1; i >= 0; i--)
    {
        if (ci[i] > 1)
        {
            ret += (i - (map[s[i]] - ci[i])) * (ci[i] - 1);// 计算 "abb" 型子序列数量
        }
    }

    cout << ret;
    return 0;
}




#include <bits/stdc++.h>
using namespace std;

const int MAXN = 101010;                            // 字符串最大长度
long long sum[MAXN][26];                            // 记录字符频率的累积数组

// 主函数
int main() 
{
    int n, i, j;                                    // `n` 是字符串长度，`i` 和 `j` 是循环变量
    string s;                                       // 输入的字符串

    cin >> n;
    cin >> s;

    // 检查输入的合法性
    if (n != s.size()) 
    {
        return 1;                                   // 返回错误码
    }

    // 计算每个位置字符的累积频率
    for (i = n - 1; i >= 0; i--) 
    {
        for (j = 0; j < 26; j++) 
        {
            sum[i][j] = sum[i + 1][j];              // 继承后续频率
        }
        sum[i][s[i] - 'a']++;                       // 更新当前字符的频率
    }

    // 计算符合条件的组合数
    long long res = 0;                              // 结果变量
    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < 26; j++) 
        {
            if (j != s[i] - 'a')                    // 跳过与当前字符相同的字符
            { 
                res += sum[i + 1][j] * (sum[i + 1][j] - 1) / 2; // 组合公式
            }
        }
    }

    cout << res << endl;

    return 0; 
}




#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    unordered_map<char, long long> prefix;              // 统计前缀中每种字符出现的次数

    unordered_map<char, long long> count;               // 统计后缀中每种字符出现的次数

    // 预处理每种字符的总出现次数
    for (char c : s)
    {
        count[c]++;
    }

    long long result = 0;

    // 遍历字符串计算子序列数量
    for (char c : s)
    {
        count[c]--;                                     // 当前字符从后缀中移除

        // 计算以当前字符为尾的 "abb" 型子序列
        for (auto& p : prefix)
        {
            if (p.first != c)                           // 确保前两个字符不同
            {
                result += p.second * count[c];          // 计算子序列数量
            }
        }

        prefix[c]++;                                    // 将当前字符加入前缀统计
    }

    cout << result << endl;
    return 0;
}