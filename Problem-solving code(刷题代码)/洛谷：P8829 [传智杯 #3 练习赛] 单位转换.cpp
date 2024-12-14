//洛谷：P8829 [传智杯 #3 练习赛] 单位转换
// https://www.luogu.com.cn/problem/P8829

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;

	int llabel = 0, rlabel = 0;
	llabel = (int)s.find("=") - 2;
	rlabel = (int)s.find("=") + 2;
	
	//分步提取信息
	double val = (double)stoi(s.substr(0, s.size() - llabel));
	string lsymbol = s.substr(llabel, 2);
	string rsymbol = s.substr(rlabel);

	//// 调试信息
	//cout << "Debug: lsymbol = " << lsymbol << ", rsymbol = " << rsymbol << endl;

	//// 转换为统一大小写以避免大小写问题
	//transform(lsymbol.begin(), lsymbol.end(), lsymbol.begin(), ::toupper);
	//transform(rsymbol.begin(), rsymbol.end(), rsymbol.begin(), ::toupper);


	if (lsymbol == "MB")
	{
		if (rsymbol == "KB")
		{
			printf("%6lf", val * 1024);
		}
		else if (rsymbol == "GB")
		{
			printf("%6lf", val / 1024);
		}
		else if (rsymbol == "B")
		{
			printf("%6lf", val * 1048576);
		}
		else
		{
			printf("%6lf", val);			//单位一样的情况
		}
	}
	else if (lsymbol == "KB")
	{
		if (rsymbol == "MB")
		{
			printf("%6lf", val / 1024);
		}
		else if (rsymbol == "GB")
		{
			printf("%6lf", val / 1048576);
		}
		else if (rsymbol == "B")
		{
			printf("%6lf", val * 1024);
		}
		else
		{
			printf("%6lf", val);			//单位一样的情况
		}
	}
	else if (lsymbol == "GB")
	{
		if (rsymbol == "MB")
		{
			printf("%6lf", val * 1024);
		}
		else if (rsymbol == "KB")
		{
			printf("%6lf", val * 1048576);
		}
		else if (rsymbol == "B")
		{
			printf("%6lf", val * 1073741824);
		}
		else
		{
			printf("%6lf", val);			//单位一样的情况
		}
	}
	//else if (lsymbol == rsymbol)		//警示后人：如果两个单位一样，则直接输出,但是前面每组判断都加了单位一样的情况，这里就不需要了
	//{
	//	printf("%6lf", val);
	//}
	else
	{
		if (rsymbol == "MB")
		{
			printf("%6lf", val / 1048576);
		}
		else if (rsymbol == "KB")
		{
			printf("%6lf", val / 1024);
		}
		else if (rsymbol == "GB")
		{
			printf("%6lf", val / 1073741824);
		}
		else
		{
			printf("%6lf", val);			//单位一样的情况
		}
	}

	return 0;
}