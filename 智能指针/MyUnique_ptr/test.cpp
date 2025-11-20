#include <iostream>
#include "unique_ptr.hpp"
#include <string>
#include <vector>
using namespace std;


// 定义一个简单的结构体，包含一个整型key和字符串val
struct t1
{
	int key;      // 整型键
	string  val;  // 字符串值
};

// 定义一个简单的类，用于测试unique_ptr
class t2
{
public:
	// 构造函数，初始化key和val
	t2(int k, string v)
		: key(k), val(v)
	{

	}

	// 设置函数，修改key和val的值
	void set(int k, string v)
	{
		key = k;
		val = v;
	}

	// 打印函数，输出key和val的值
	void print()
	{
		cout << "key: " << key << " val: " << val << endl;
	}

private:
	int key;      // 私有成员变量：键
	string val;   // 私有成员变量：值
};


// 展示std::exchange函数的功能
void test1()
{
	int a = 100;
	// 将a的值替换为500，并返回a的旧值
	int b = std::exchange(a, 500);
	std::cout << "交换前a的值（b）: " << b << std::endl;
	std::cout << "交换后a的值: " << a << std::endl;

	cout << endl << endl;
}


// 测试unique_ptr对不同类型对象的管理及访问方式
void test2()
{
	// 1. 创建不同类型的unique_ptr
	minbit::unique_ptr<int> p1(new int(10));                  // 管理int类型
	minbit::unique_ptr<int> p2(new int(10));                  // 管理int类型

	// 数组和容器类型
	minbit::unique_ptr<int[]> p3(new int[10]());              // 管理int数组（10个元素，值初始化）
	minbit::unique_ptr<vector<int>> p4(new vector<int>(10, 5));// 管理vector容器（10个元素，每个为5）
	minbit::unique_ptr<string> p5(new string("hello"));       // 管理string对象

	// 结构体和类类型
	minbit::unique_ptr<t1> p6(new t1());                      // 管理结构体t1对象
	minbit::unique_ptr<t2> p7(new t2(2, "hello"));            // 管理类t2对象（初始值key=2, val="hello"）


	// 2. 访问与修改unique_ptr指向的对象
	std::cout << "p1的值: " << *p1 << "，乘以10后的值: " << *p1 * 10 << std::endl << std::endl;
	std::cout << "p2的值: " << *p2 << "，乘以10后的值: " << *p2 * 10 << std::endl << std::endl;

	// 访问数组类型的unique_ptr（支持下标运算符[]）
	std::cout << "p3数组初始值: ";
	int* begin = p3.get();
	int* end = p3.get() + 10;
	for (int* p = begin; p != end; p++)
	{
		std::cout << *p << " ";
	}
	std::cout << std::endl << "p3数组元素+i后的值: ";
	for (int i = 0; i < 10; i++)
	{
		std::cout << p3[i] + i << " ";  // 数组类型unique_ptr直接用下标访问
	}
	std::cout << std::endl << std::endl;


	// 访问容器类型的unique_ptr（需先解引用获取容器对象）
	std::cout << "p4容器初始值: ";
	for (auto x : *p4)  // *p4获取vector对象
	{
		std::cout << x << " ";
	}
	std::cout << std::endl << "p4容器元素+i后的值: ";
	for (int i = 0; i < 10; i++)
	{
		std::cout << (*p4)[i] + i << " ";  // 先解引用再用下标访问容器元素
	}
	std::cout << std::endl << std::endl;


	// 访问string类型的unique_ptr
	std::cout << "p5字符串初始值: " << *p5 << std::endl;
	*p5 = "world";                        // 修改字符串内容
	std::cout << "p5修改后的值: " << *p5 << std::endl;
	(*p5)[2] = '!';                       // 修改字符串指定位置字符
	std::cout << "p5替换索引2字符后: " << *p5 << std::endl;
	*p5 += "!!!!!!";                      // 字符串追加内容
	std::cout << "p5追加后的值: " << *p5 << std::endl;
	std::cout << std::endl;


	// 访问结构体类型的unique_ptr（用->访问成员）
	std::cout << "p6结构体初始值：key=" << p6->key << ", val=" << p6->val << std::endl;
	p6->key = 100;                        // 修改结构体成员
	p6->val = "小米里的大麦";
	std::cout << "p6结构体修改后：key=" << p6->key << ", val=" << p6->val << std::endl;
	std::cout << std::endl;


	// 访问类类型的unique_ptr（用->调用成员函数）
	std::cout << "p7类对象初始值：";
	p7->print();                          // 调用类的成员函数
	p7->set(100, "小米里的大麦");         // 调用set函数修改成员
	std::cout << "p7类对象修改后：";
	p7->print();
	std::cout << std::endl;

	cout << endl << endl;
}

// 测试unique_ptr的reset方法（重置指针所有权）
void test3()
{
	minbit::unique_ptr<vector<int>> p1(new vector<int>(5, 5));  // 初始管理含5个5的vector

	cout << "p1管理的vector值: ";
	for (auto x : *p1)
	{
		cout << x << " ";
	}
	cout << endl;

	// 测试指针有效性（operator bool()）
	if (p1)
	{
		cout << "p1指针有效！" << endl;
	}
	else
	{
		cout << "p1指针无效！" << endl;
	}

	p1.reset();  // 释放当前管理的对象，重置为nullptr

	if (p1)
	{
		cout << "p1指针有效！" << endl;
	}
	else
	{
		cout << "p1指针无效！" << endl;
	}

	// 重置为新的对象（管理含10个10的vector）
	p1.reset(new vector<int>(10, 10));
	if (p1)
	{
		cout << "p1指针有效！" << endl;
	}
	else
	{
		cout << "p1指针无效！" << endl;
	}

	cout << "p1重置后的值: ";
	for (auto x : *p1)
	{
		cout << x << " ";
	}
	cout << endl << endl;
}

// 测试unique_ptr的get和release方法
void test4()
{
	minbit::unique_ptr<t2> p1(new t2(108, "minbit"));  // 初始管理t2对象（key=108, val="minbit"）

	// get()：获取原生指针（不释放所有权）
	t2* pp1 = p1.get();
	cout << "pp1指向的对象值：";
	pp1->print();
	cout << endl;
	// 此时p1仍持有所有权
	if (p1)
	{
		cout << "p1指针有效！" << endl;
	}
	else
	{
		cout << "p1指针无效！" << endl;
	}

	// release()：释放所有权，返回原生指针（p1变为nullptr）
	t2* pp2 = p1.release();
	cout << "pp2指向的对象值：";
	pp2->print();
	cout << endl;
	// 此时p1已释放所有权
	if (p1)
	{
		cout << "p1指针有效！" << endl;
	}
	else
	{
		cout << "p1指针无效！" << endl;
	}

	// 手动释放release返回的指针（避免内存泄漏）
	delete pp2;
	cout << endl << endl;
}

// 测试unique_ptr的swap方法（交换所有权）
void test5()
{
	minbit::unique_ptr<int> p1(new int(10));       // 管理int(10)
	minbit::unique_ptr<int> p2(new int(20));       // 管理int(20)
	minbit::unique_ptr<double> p3(new double(30.0));// 管理double(30.0)

	cout << "交换前：p1=" << *p1 << " ,p2=" << *p2 << " ,p3=" << *p3 << endl;
	p1.swap(p2);  // 交换p1和p2的所有权（类型需相同）
	cout << "交换后：p1=" << *p1 << " ,p2=" << *p2 << " ,p3=" << *p3 << endl;
	// p1.swap(p3);  // 错误：类型不同（int和double），无法交换

	cout << endl << endl;
}

// 测试unique_ptr的移动语义（move操作转移所有权）
void test6()
{
	minbit::unique_ptr<t2> p1(new t2(108, "minbit"));  // 初始所有权在p1
	// minbit::unique_ptr<t2> p2(p1);  // 错误：unique_ptr禁止拷贝构造

	// 通过move转移所有权（p1失去所有权，变为nullptr）
	minbit::unique_ptr<t2> p3 = move(p1);
	if (p1 == nullptr)
	{
		cout << "p1已变为nullptr（失去所有权）" << endl;
	}
	cout << "p3获取所有权后的值：";
	p3->print();
}

int main()
{
	test1();  // 测试std::exchange
	test2();  // 测试unique_ptr对不同类型的管理与访问
	test3();  // 测试reset方法
	test4();  // 测试get和release方法
	test5();  // 测试swap方法
	test6();  // 测试移动语义

	return 0;
}