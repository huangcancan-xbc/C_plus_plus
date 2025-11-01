#include "Myqueue.hpp"

void test1()
{
	minbit::Myqueue<int> q;
	for (int i = 0; i < 5; i++)
	{
		q.push(i);
	}

	cout << "末尾元素的值是：" << q.back() << endl;

	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl << "q队列的大小：" << q.size() << endl;
	cout << endl << endl;
}


void test2()
{
	minbit::Myqueue<double> st;
	for (int i = 0; i < 5; i++)
	{
		st.push(i * 1.6);
	}

	if (!st.empty())
	{
		cout << "队列不是空的！" << endl;
	}
	else
	{
		cout << "队列是空的！" << endl;
	}


	while (!st.empty())
	{
		cout << st.front() << " " << endl;
		st.pop();
	}

	cout << "st.size=" << st.size() << endl;
	//cout << "st.top=" << st.top() << endl;//放开会报错，因为队列是空的！
	if (!st.empty())
	{
		cout << "队列不是空的！" << endl;
	}
	else
	{
		cout << "队列是空的！" << endl;
	}

	cout << st.size() << endl;

	cout << endl << endl;
}

void test3()
{
	minbit::Myqueue<double> q, temp;
	for (int i = 0; i < 5; i++)
	{
		q.push(i * 1.6);
	}

	cout << "q队列的大小：" << q.size() << endl;
	cout << "temp队列的大小：" << temp.size() << endl;

	swap(q, temp);

	cout << endl << "交换后的各自容量：" << endl << endl;
	cout << "q队列的大小：" << q.size() << endl;
	cout << "temp队列的大小：" << temp.size() << endl;

	cout << endl << endl;
}


int main()
{
	test1();
	test2();
	test3();

	return 0;
}