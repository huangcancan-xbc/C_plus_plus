//牛客：兔子的序列
//https://ac.nowcoder.com/acm/contest/98498/H


#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n), ret;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];                        // 输入序列

        int root = (int)sqrt(v[i]);         // 计算根号
        if (root * root != v[i])            // 如果平方不等于原数，则不是完全平方数
        {
            ret.push_back(v[i]);            // 若不是完全平方数，则不是兔子数，加入ret
        }
    }

    sort(ret.begin(), ret.end());           // 排序
    cout << ret[ret.size() - 1];            // 输出最后一个兔子数

    return 0;
}