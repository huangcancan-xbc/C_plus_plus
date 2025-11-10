#include <iostream>
#include "head.hpp"
using namespace std;

// 定义（和声明分开避免链接错误）：
//long Add(long a, long b)
//{
//	std::cout << "现在调用的是非模板函数！" << std::endl;
//	return a + b;
//}

//t2<T>::print() 的定义物理上写在了 Main.cpp 里，但在编译 Main.cpp 这个翻译单元时，
//它通过 #include 看到了 t2 的完整声明和 print 的完整定义，所以满足了模板实例化的要求。
//这并不违反“定义必须可见”的规则，因为定义确实在使用点的同一编译单元（经过 #include 后）被看到了。
//template <class T>
//void t2<T>::print()
//{
//	std::cout << a << std::endl;
//}
//
//但是，如果类模板的声明在 1.h，定义在 2.cpp，然后在 3.cpp 中使用，3.cpp 编译时找不到函数定义，会报错。


void test1()
{
	int a = 10;
	int b = 20;
	Swap(a, b);

	cout << "a = " << a << ", b = " << b << endl;
	cout << endl << endl;
}

//void test2()
//{
//	int a = 10;
//	double b = 20.5;
//	Swap(a, b);// 模板的参数必须是相同类型，否则编译器会报错，比如这里不能将int和double类型进行交换
//
//	cout << "a = " << a << ", b = " << b << endl;
//	cout << endl << endl;
//}

void test3()
{
	long a = 10000;
	long b = 20000;

	long c = Add<long>(a, b);// 显示调用模板函数，并传入long类型参数
	//long c = Add<int>(a, b);// 如果传入的参数类型与模板参数类型不匹配，编译器会尝试进行隐式类型转换，如果无法转换成功，则编译器将会报错。
	//long c = Add<double>(a, b);
	//char c = Add<char>(a, b);

	cout << "a = " << a << ", b = " << b << endl;
	cout << "a+b=" << c << endl;

	cout << endl << endl;
}

void test4()
{
	long a = 5;
	long b = 5;
	long c = Add(a, b);// 这里调用的是非模板函数
	cout << "a+b=" << c << endl;

	cout << endl;

	long d = Add<long>(a, b);// 这里调用的是模板函数，并传入long类型参数
	cout << "a+b=" << d << endl;


	cout << endl << endl;
}



void test5()
{
	// 使用类模板时，必须显式指定模板参数（即类型），编译器无法像函数模板那样自动推导类模板的类型参数。
	//t1 a;        // 错误！编译器不知道 T 是什么类型，无法实例化 t1 类
	//t1 b(10);    // 错误！即使传入了参数 10，编译器也无法自动推导出 T 应该是 int

	// 1. 显式指定模板参数类型
	t1<int> a(10);      // 创建一个 T 为 int 类型的 t1 对象
	t1<double> b(3.14); // 创建一个 T 为 double 类型的 t1 对象
	t1<string> c("Hello"); // 创建一个 T 为 string 类型的 t1 对象

	// 2. 调用对象的方法
	cout << "a: ";
	a.print(); // 输出: 10

	cout << "b: ";
	b.print(); // 输出: 3.14

	cout << "c: ";
	c.print(); // 输出: Hello


	cout << endl << endl;
}

void test6()
{
	t2<int> a;
	a.print();

	t2<double> b(2.5);
	b.print();

	t2<string> c("World");
	c.print();

	cout << endl << endl;
}

int main()
{
	test1();
	//test2();
	test3();
	test4();
	test5();
	test6();

	return 0;
}