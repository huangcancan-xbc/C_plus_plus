#pragma once
#include <iostream>
using namespace std;

class Member_functions
{
private:
	int _val;
public:

	// 构造函数包含：
	// 1. 无参构造函数
	// 2. 有参构造函数
	// 3. 拷贝构造函数
	// 4. 移动构造函数（C++11）
	// 5. 转换构造函数（单参数构造函数）
	// 常用度：有参构造函数 > 无参构造函数 > 移动构造函数 > 拷贝构造函数 > 转换构造函数
	// 编译器会自动给的：默认构造、拷贝构造、拷贝赋值、析构函数
	// 编译器不会给的：有参构造、转换构造（C++11起只有当没写析构、拷贝、移动中的任何一个，才会自动生成移动构造和移动赋值）

	// 1. 无参构造函数：函数名与类名相同，没有参数
	Member_functions()
	{
		cout << "1. 无参构造函数 被调用！" << endl;
	}


	// 2. 有参构造函数：函数名与类名相同，带参数
	Member_functions(int a)
	{
		_val = a;
		cout << "2. 有参构造函数 被调用！" << endl;
	}


	// 3. 拷贝构造函数：参数类型必须是 const 类名&（引用），否则无限递归
	Member_functions(const Member_functions& obj)
	{
		_val = obj._val;
		cout << "3. 拷贝构造函数 被调用！" << endl;
	}


	// 4. 移动构造函数（C++11）：参数类型是 类名&&（右值引用）
	// noexcept（可选但建议）：它用于保证不会抛异常，否则 STL 不敢用该移动构造
	Member_functions(Member_functions&& obj) noexcept
	{
		_val = obj._val;
		cout << "4. 移动构造函数 被调用！" << endl;
	}


	// 5. 转换构造函数：只有一个参数，可以让其他类型隐式/显式转换成该类对象
	// explicit（可选但建议）：它会禁止编译器偷偷做隐式转换
	explicit Member_functions(double a)
	{
		_val = (int)a;
		cout << "5. 转换构造函数 被调用！" << endl;
	}



	// 析构函数包含：
	// 1. 普通析构函数
	// 2. 虚析构函数（继承、多态中）

	// 1. 普通析构函数：~类名()，没有参数
	// 用于“自动”回收对象占用的内存，不会自动释放自己申请的资源（new 等），需要手动调用 delete 释放。
	~Member_functions()
	{
		cout << "析构函数 被调用！" << endl;
	}


	// 继承、多态中，虚析构函数是必须的，后面说明。
	//virtual ~Member_functions()
	//{
	//	cout << "虚析构函数 被调用！" << endl;
	//}
};



void test1();
void test2();
void test3();
void test4();
void test5();







// #include <iostream>
// using namespace std;

// class A
// {
// public:
//     // 如果不写任何构造函数，编译器会生成一个默认构造函数
// };

// class B
// {
// public:
//     B(int x) { }        // 有参构造函数
//     // 这时编译器不会再自动生成无参构造函数
// };

// class C
// {
// public:
//     C() = default;      // 强制让编译器生成默认构造函数
// };

// int main()
// {
//     A a;   // OK，使用编译器合成的默认构造函数
//     // B b; // 错误，没有无参构造函数
//     C c;   // OK，显示指定生成默认构造函数
// }