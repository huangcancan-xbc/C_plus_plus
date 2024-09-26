#include <iostream>
#include <string>
//牛客：拼数
//https://ac.nowcoder.com/acm/problem/16783

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 自定义比较函数，用于排序
bool sort1(const string& a, const string& b)
{
    // 比较两个字符串拼接的结果，决定它们的顺序
    return a + b > b + a; // 如果a+b比b+a大，则a排在b前面
}

int main()
{
    int n; // 输入字符串的数量
    cin >> n; // 从标准输入读取数量
    vector<string> arr(n); // 创建一个字符串数组，大小为n

    // 读取n个字符串
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // 从输入中读取每个字符串
    }

    // 使用自定义的sort1函数对数组进行排序
    sort(arr.begin(), arr.end(), sort1);

    // 输出拼接后的结果
    for (int i = 0; i < n; i++)
    {
        cout << arr[i]; // 依次输出排序后的字符串，即拼接后的最终结果（答案）
    }
    return 0; // 程序结束
}
