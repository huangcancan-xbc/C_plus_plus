#include <iostream>
#include <string>
using namespace std;

//C++11 引入using后，支持直接将using与template结合，定义 “模板类型别名”，无需嵌套类，使用时也无需额外语法。
//实现步骤：
//直接用 “template <模板参数> using 别名 = 目标类型” 的语法，一步定义模板化的类型别名。
//使用时，直接用 “别名<具体类型>” 调用，和普通类型别名的使用逻辑一致。
template <typename T>
using callback = void (*)(T);  // 模板化回调类型

void printI(int x)
{
	cout << "Int: " << x << endl;
}

void printS(string s)
{
	cout << "String: " << s << endl;
}

void printD(double d)
{
	cout << "Double: " << d << endl;
}

int main()
{
	// 多种写法：
	callback<int> intCb = printI;
	callback<string> strCb(printS);         // 用构造方式初始化（函数指针的初始化）
	callback<double> doubleCb = &printD;    // 与原写法等价，&可省略
	// auto ……也可以

	intCb(100);         // 输出：Int: 100
	(*strCb)("test");   // 输出：String: test
	doubleCb(3.14);     // 输出：Double: 3.14

	return 0;
}





#include <iostream>
#include <string>
using namespace std;

//typedef本身不能直接跟模板参数结合，但可以把它放在一个类模板内部，通过类模板的参数间接实现 “模板化的类型别名”。
//实现步骤：
//定义一个类模板，在类内部用typedef定义目标类型别名。
//使用时，必须通过 “类模板名<具体类型>::type” 的语法调用，不能直接用类模板名简化。
// 用类模板嵌套 typedef 实现模板化回调类型（间接支持模板）
template <typename T>
struct callback
{
	typedef void (*Type)(T);        // 在类内部用 typedef 定义函数指针类型
};

void printI(int x)
{
	cout << "Int: " << x << endl;
}

void printS(string s)
{
	cout << "String: " << s << endl;
}

void printD(double d)
{
	cout << "Double: " << d << endl;
}

int main()
{
	// 必须通过 "类模板名<类型>::Type" 访问 typedef 定义的类型
	callback<int>::Type intCb = printI;
	callback<string>::Type strCb(printS);  // 构造方式初始化
	callback<double>::Type doubleCb = &printD;  // & 可省略

	intCb(100);         // 输出：Int: 100
	(*strCb)("test");   // 输出：String: test
	doubleCb(3.14);     // 输出：Double: 3.14

	return 0;
}


// 观察上面2段代码：
// typedef 对模板支持较弱，需要依赖类模板嵌套，使用繁琐。
// using是 C++11 为解决这个问题设计的方案，能直接定义模板类型别名，在模板场景下（包括模板化回调函数）完全优于typedef。
// 实际开发中，只要环境支持 C++11 及以上，涉及模板化的类型别名（如通用回调、容器别名），都应该优先用using。