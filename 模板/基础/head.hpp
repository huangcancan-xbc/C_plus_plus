#pragma once
#include <iostream>

template<typename T>
void Swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>
T Add(T a, T b)
{
	return a + b;
}
// 非模板函数可以和一个同名的函数模板同时存在，而且该函数模板还可以被实例化为这个非模板函数。当调用函数时，编译器会按照以下优先级进行匹配：
//最佳匹配的普通函数：如果存在一个不需要模板实例化就能完全匹配参数类型的普通函数，编译器会优先选择它。
//最佳匹配的函数模板实例：如果普通函数无法完美匹配，或者匹配度不如某个模板实例，编译器会尝试实例化合适的函数模板。
//最佳匹配的函数模板（显式指定模板参数）：使用 Add<long>(a, b) 这种方式显式指定模板参数时，会强制实例化对应的模板版本。
//
//static long Add(long a, long b)
//{
//	std::cout << "现在调用的是非模板函数！" << std::endl;
//	return a + b;
//}
// 
//注意上面这个写法会报链接错误：是因为符号重复定义导致的：
//编译器在编译 head.cpp 时，会将 head.hpp 的内容展开，生成 Swap 模板、Add 模板和 long Add(long, long) 函数的定义，生成 head.obj。
//编译器在编译 Main.cpp 时，同样会将 head.hpp 的内容展开，再次生成 Swap 模板、Add 模板和 long Add(long, long) 函数的定义，生成 Main.obj。
//链接器尝试将 head.obj 和 Main.obj 合并成最终的可执行文件。
//它发现 long Add(long, long) 这个函数的实现（符号 ? Add@@YAJJJ@Z）在两个.obj 文件中都存在，这就违反了单一定义规则（One Definition Rule, ODR），导致链接失败。


//有3种解决方案：将非模板函数定义标记为 inline 或 static；此文件中只写声明，实现放到Main.cpp文件中


// inline long Add(long a, long b)
static long Add(long a, long b)
{
	std::cout << "现在调用的是非模板函数！" << std::endl;
	return a + b;
}
//long Add(long a, long b);// 声明




// 类模板：
template<typename T>
//template<class T>	// C++11 起，class 关键字可以代替 typename,2种写法等价
class t1
{
private:
	T a;
public:
	t1(T x) : a(x) {}
	void print() { std::cout << a << std::endl; }
};



//类模板不支持分离编译，即声明在xxx.h文件中，而定义却在xxx.cpp文件中。类外定义时，需要加模板参数列表。
template <class T>
class t2
{
private:
	T a;
public:
	t2();              // 声明默认构造函数
	t2(T value);       // 声明带参构造函数
	void print();
};

// 默认构造函数定义 (类外)
template <class T>
t2<T>::t2() : a{} // 使用 T 的默认值初始化 a (例如 int 为 0, double 为 0.0, string 为空字符串)
{

}
// 带参构造函数定义 (类外)
template <class T>
t2<T>::t2(T value) : a(value)
{

}
// print 函数定义 (类外)
template <class T>
void t2<T>::print()
{
	std::cout << a << std::endl;
}