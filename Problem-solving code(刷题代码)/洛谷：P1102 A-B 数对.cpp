#define _CRT_SECURE_NO_WARNINGS 1

//洛谷：P1102 A-B 数对
//https://www.luogu.com.cn/problem/P1102
//思路：
//1. 读入n、c、a数组
//2. 建立映射表mp，统计a数组中每个数出现的次数
//3. 遍历a数组，将每个数减去c，并查询映射表mp中该数出现的次数，累加到count中
//4. 输出count

#include <iostream>  // 引入标准输入输出库
#include <vector>    // 引入动态数组库（vector）
#include <algorithm> // 引入算法库（algorithm）
#include <map>       // 引入映射库（map）
using namespace std;

int main()
{
    long long n, c;
    cin >> n >> c;
    vector<long long> a(n);
    map<long long, long long > mp;
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;//统计a数组中每个数出现的次数
        a[i] -= c;//A-B=C变成A-C=B
    }

    long long count = 0;

    for (long long i = 0; i < n; i++)
    {
        count += mp[a[i]];//精华所在，将映射表中该数出现的次数累加到count中，
        //如果a[i]存在，则count+=1，如果不存在，返回 0，对结果没有影响。
    }

    cout << count << endl;
    // 程序正常结束
    return 0;
}
