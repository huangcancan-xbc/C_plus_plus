//洛谷：P8195 [传智杯 #4 决赛] 小智的疑惑
//https://www.luogu.com.cn/problem/P8195


#include <iostream>
#include <string>
using namespace std;

int Substrings(string s, string sub)
{
	int ans = 0;
	int pos = 0;											// 开始查找的位置
	while ((pos = s.find(sub, pos)) != string::npos)		// 循环查找子串，直到找不到为止
	{
		ans++;												// 找到一个子串更新结果
		pos += 8;											// 更新到子串长度的后面一个位置
	}

	return ans;
}

int main()
{
	string s;
	cin >> s;

	string sub = "chuanzhi";
	int ret = Substrings(s, sub);

	cout << ret << endl;
	return 0;
}