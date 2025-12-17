#include "priority_queue.hpp"
#include <iostream>
using namespace std;
using namespace minbit;

void test1()
{
	priority_queue<int> q;
	q.push(1);
	cout << "堆顶元素：" << q.top() << endl;
	q.push(2);
	cout << "堆顶元素：" << q.top() << endl;
	q.push(3);
	cout << "堆顶元素：" << q.top() << endl;
	q.push(4);
	cout << "堆顶元素：" << q.top() << endl;
	q.push(5);
	cout << "堆顶元素：" << q.top() << endl;

	cout << "堆顶的大小:" << q.size() << endl;
	q.pop();
	cout << "堆顶元素：" << q.top() << endl;
	cout << "堆顶的大小:" << q.size() << endl;
	
	while (q.size())
	{
		q.pop();
	}

	cout << "堆大小：" << q.size() << endl;
	if (q.empty())
	{
		cout << "空堆" << endl;
	}
	else
	{
		cout << "非空堆" << endl;
	}
}

void test2()
{
	priority_queue<double, vector<double>, Greator<double>> q;
	for (int i = 10; i >= 0; i--)
	{
		q.push(i * 0.12);
		cout << "堆顶元素：" << q.top() << endl;
	}

	cout << "堆的大小：" << q.size() << endl;
}

void test3()
{
	vector<int> v = { 9, 2, 7, 1, 6 };
	priority_queue<int, vector<int>, Greator<int>> q(v.begin(), v.end());
	cout << "小根堆的堆顶元素：" << q.top() << endl;
	cout << "堆大小：" << q.size() << endl;

	q.pop();
	cout << "堆顶元素：" << q.top() << endl;
	cout << "堆大小：" << q.size() << endl;
}


int main()
{
	test1();
	test2();
	test3();


	return 0;
}