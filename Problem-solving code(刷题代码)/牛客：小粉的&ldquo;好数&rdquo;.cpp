//牛客：小粉的&ldquo;好数&rdquo;
//https://ac.nowcoder.com/acm/contest/97845/E
//参赛密码：517acm



#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool is(int x, vector<int>& dp) 
{
    if (dp[x] != -1) // 动态规划缓存结果
    { 
        return dp[x];
    }

    // 计算数字各个位数的和
    int sum = 0;
    int temp = x;
    while (temp > 0) 
    {
        sum += temp % 10;
        temp /= 10;
    }

    // 条件 1：各位数之和是偶数
    if (sum % 2 != 0) 
    {
        return dp[x] = false;
    }

    // 条件 2：若 sum < x，则 sum 也必须是好数
    if (sum < x && !is(sum, dp)) 
    {
        return dp[x] = false;
    }

    return dp[x] = true;
}

int main() {
    int n;
    cin >> n;

    // 动态规划数组，初始化为 -1 表示未计算
    vector<int> dp(n + 1, -1);

    int ret = 0;
    for (int i = 1; i <= n; i++) 
    {
        if (is(i, dp)) 
        {
            ret++;
        }
    }

    cout << ret << endl;
    return 0;
}
