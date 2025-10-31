#include "Mystack.hpp"

void test1()
{
	minbit::Mystack<int> st;
	for (int i = 0; i < 5; i++)
	{
		st.push(i);
	}


	while (!st.empty())
	{
		cout << st.top() << " " << endl;
		st.pop();
	}

	cout << endl << endl;
}


void test2()
{
	minbit::Mystack<double> st;
	for (int i = 0; i < 5; i++)
	{
		st.push(i * 1.6);
	}

	if (!st.empty())
	{
		cout << "栈不是空的！" << endl;
	}
	else
	{
		cout << "栈是空的！" << endl;
	}


	while (!st.empty())
	{
		cout << st.top() << " " << endl;
		st.pop();
	}

	cout << "st.size=" << st.size() << endl;
	//cout << "st.top=" << st.top() << endl;//放开会报错，因为栈是空的！
	if (!st.empty())
	{
		cout << "栈不是空的！" << endl;
	}
	else
	{
		cout << "栈是空的！" << endl;
	}

	cout << st.size() << endl;

	cout << endl << endl;
}

void test3()
{
	minbit::Mystack<double> st, temp;
	for (int i = 0; i < 5; i++)
	{
		st.push(i * 1.6);
	}

	cout << "st栈的大小：" << st.size() << endl;
	cout << "temp栈的大小：" << temp.size() << endl;

	swap(st, temp);

	cout << endl << "交换后的各自容量：" << endl;
	cout << "st栈的大小：" << st.size() << endl;
	cout << "temp栈的大小：" << temp.size() << endl;

	cout << endl << endl;
}


int main()
{
	test1();
	test2();
	test3();

	return 0;
}