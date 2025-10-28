#include "MyVector.h"
using namespace std;

// 测试无参构造函数
void test1()
{
	minbit::vector<int> v;
	cout << "数组 V 的大小为: " << v.size() << endl;
	cout << "数组 V 的容量为: " << v.capacity() << endl;

	cout << endl << endl;
}


// 测试有参构造函数
void test2()
{
	minbit::vector<double> v(10);
	cout << "数组 V 的大小为: " << v.size() << endl;
	cout << "数组 V 的容量为: " << v.capacity() << endl;
	for (int i = 0; i < 10; i++)
	{
		v[i] = i * 1.5;
	}

	for (auto x : v)
	{
		cout << x << " ";
	}

	cout << endl << endl;
}


void test3()
{
	minbit::vector<double> v(10, 1);
	cout << "数组 V 的大小为: " << v.size() << endl;
	cout << "数组 V 的容量为: " << v.capacity() << endl;

	for (auto x : v)
	{
		cout << x << " ";
	}

	cout << endl << endl;
}


// 测试区间构造函数
void test4()
{
	minbit::vector<int> v(10);
	for (int i = 1; i <= 10; i++)
	{
		v[i - 1] = i;
	}

	minbit::vector<int> v2(v.begin() + 2, v.end() - 2);
	cout << "数组 V2 的大小为: " << v2.size() << endl;
	cout << "数组 V2 的容量为: " << v2.capacity() << endl;

	for (auto x : v2)
	{
		cout << x << " ";
	}

	cout << endl << endl;
}


// 测试拷贝构造函数
void test5()
{
	minbit::vector<int> v(10);
	for (int i = 1; i <= 10; i++)
	{
		v[i - 1] = i;
	}

	minbit::vector<int> v2(v);
	cout << "数组 V2 的大小为: " << v2.size() << endl;
	cout << "数组 V2 的容量为: " << v2.capacity() << endl;

	for (auto x : v2)
	{
		cout << x << " ";
	}

	cout << endl << endl;
}


// 测试赋值运算符重载函数
void test6()
{
	minbit::vector<int> v(10);
	for (int i = 1; i <= 10; i++)
	{
		v[i - 1] = i;
	}

	minbit::vector<int> v2 = v;
	cout << "数组 V2 的大小为: " << v2.size() << endl;
	cout << "数组 V2 的容量为: " << v2.capacity() << endl;

	for (auto x : v2)
	{
		cout << x << " ";
	}

	cout << endl << endl;
}


// 测试迭代器相关函数
void test7()
{
	//iterator begin();
	//iterator end();
	//const_iterator begin()const;
	//const_iterator end()const;
	minbit::vector<int> v(10);
	for (int i = 1; i <= 10; i++)
	{
		v[i - 1] = i * 5;
	}

	minbit::vector<int>::iterator begin = v.begin();
	minbit::vector<int>::iterator end = v.end();
	for (minbit::vector<int>::iterator it = begin; it != end; it++)
	{
		*it = 1;
		cout << *it << " ";
	}
	cout << endl;

	minbit::vector<int>::const_iterator cbegin = v.begin();
	minbit::vector<int>::const_iterator cend = v.end();
	for (minbit::vector<int>::const_iterator cit = cbegin; cit != cend; cit++)
	{
		//*cit = 1;		// 试图修改元素，但迭代器是 const 的，所以无法修改元素，运行会报错，符合预期
		cout << *cit << " ";
	}
	cout << endl;

	cout << endl << endl;
}


// 测试容量和大小相关函数
void test8()
{
	minbit::vector<int> v;
	if (v.empty())
	{
		cout << "数组 V 是空的" << endl;
	}
	else
	{
		cout << "数组 V 不是空的" << endl;
	}

	v.reserve(10);
	cout << "数组 V 的大小为: " << v.size() << endl;
	cout << "数组 V 的容量为: " << v.capacity() << endl;

	v.resize(20);
	cout << "数组 V 的大小为: " << v.size() << endl;
	cout << "数组 V 的容量为: " << v.capacity() << endl;

	if (v.empty())
	{
		cout << "数组 V 是空的" << endl;
	}
	else
	{
		cout << "数组 V 不是空的" << endl;
	}

	cout << endl << endl;
}


// 测试修改容器内容相关函数
void test9()
{
	minbit::vector<int> v;
	//v.pop_back();	// 试图弹出空数组，会触发断言，运行会报错，符合预期

	for (int i = 0; i < 5; i++)
	{
		v.push_back(i);
	}

	for (auto x : v)
	{
		cout << x << " ";
	}
	cout << endl;

	v.pop_back();
	v.pop_back();
	for (auto x : v)
	{
		cout << x << " ";
	}
	cout << endl;

	v.insert(v.begin() + 1, 1111);
	v.insert(v.begin() + 100, 222);
	for (auto x : v)
	{
		cout << x << " ";
	}
	cout << endl;

	v.erase(v.begin() + 1);
	v.erase(v.begin() + 2);
	for (auto x : v)
	{
		cout << x << " ";
	}
	cout << endl;

	minbit::vector<int> v1(10, 66);
	v.swap(v1);
	cout << "原始数组和新数组交换后：" << endl;
	cout << "原始数组变成：";
	for (auto x : v)
	{
		cout << x << " ";
	}
	cout << endl;
	cout << "新数组变成：";
	for (auto x : v1)
	{
		cout << x << " ";
	}
	cout << endl;

	v.clear();
	cout << "数组 V 已清空" << endl;
	if (v.empty())
	{
		cout << "数组 V 是空的" << endl;
	}
	else
	{
		cout << "数组 V 不是空的" << endl;
	}

	cout << endl << endl;
}


// 测试访问容器相关函数
void test10()
{
	//T& operator[](size_t i);
	//const T& operator[](size_t i)const;

	minbit::vector<int> v(10);
	for (int i = 0; i < 10; i++)
	{
		v[i] = i * 12;
	}
	for (auto x : v)
	{
		cout << x << " ";
	}
	cout << endl;

	cout << "数组 V 的第 2 个元素为：" << v[1] << endl;
	cout << "数组 V 的第 5 个元素为：" << v[4] << endl;
	v[0] = -100;
	cout << "数组 V 的第 1 个元素修改后为：" << v[0] << endl;
	for (auto x : v)
	{
		cout << x << " ";
	}
	cout << endl;

	const minbit::vector<int> cv(10, 20);
	for (auto x : cv)
	{
		cout << x << " ";
	}
	cout << endl;

	//cv[1] = 30;		// 试图修改元素，但迭代器是 const 的，所以无法修改元素，运行会报错，符合预期

	cout << endl << endl;
}


int main()
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	test9();
	test10();


	return 0;
}