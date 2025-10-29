#include <iostream>
#include <string>
#include <functional>
#include <sstream>
using namespace std;

void print1()
{
	cout << "Hello, World!" << endl;
}
void test1(int n, function<void()> callback)
{
	for (int i = 0; i < n; i++)
	{
		callback();
	}
}


void print2(string s)
{
	cout << s << endl;
}
void test2(int n, function<void(string)> callback)
{
	for (int i = 0; i < n; i++)
	{
		callback("hello, callback!");
	}
}


void test3(int n, function<void(string)> callback)
{
	for (int i = 0; i < n; i++)
	{
		stringstream ss;
		ss << "这是第 " << i << " 次调用";
		callback(ss.str());
	}
}


int main()
{
	test1(3, print1);
	test2(3, print2);
	test3(3, print2);

	return 0;
}