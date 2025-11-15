#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "test.hpp"
using namespace std;

// 关于 unique_ptr 的常用操作：
// reset():释放当前内存，重置为 nullptr（可选传新指针，要求类型要一样）
// release():返回原生指针，并且彻底释放所有权（智能指针不管了），必须手动delete，否则内存泄漏。
// get():返回原生指针，但不释放所有权（智能指针仍管着内存，会自动释放），只能临时用（比如传给 C 风格函数当参数），别去手动delete，也别改它指的内容（容易出问题）。
// swap():交换两个 unique_ptr 的所有权，类型要一样。
// operator bool():判断是否指向有效内存（非 nullptr）

// move()：move 不是 unique_ptr 的方法，它是标准库的一个函数，作用是把对象的所有权 "交出去"（转移所有权）。
// 对 unique_ptr 来说：它独占资源，不能直接拷贝，所以要用 std::move 显式告诉编译器 "我要把这个指针的所有权转移给另一个指针”。

// 测试unique_ptr的基本创建和访问操作
void test1()
{
	// 1. 创建 unique_ptr
	unique_ptr<int> p1(new int(10));			// 旧方式
	unique_ptr<int> p2 = make_unique<int>(10);	// 更推荐

	// 数组和容器
	unique_ptr<int[]> p3 = make_unique<int[]>(10);                                    // 创建int数组
	unique_ptr<vector<int>> p4 = make_unique<vector<int>>(10, 5);                     // 创建vector容器，10个元素，每个为5
	unique_ptr<string> p5 = make_unique<string>("hello");                             // 创建string对象

	// 类、结构体
	unique_ptr<t1> p6 = make_unique<t1>();                                            // 创建结构体对象
	unique_ptr<t2> p7 = make_unique<t2>(2, "world");                                  // 创建类对象


	// 2. 访问与修改
	cout << "p1的值:" << *p1 << " \"修改\"后的值:" << *p1 * 10 << endl << endl;     // 输出p1指向的值和乘10后的结果
	cout << "p2的值:" << *p2 << " \"修改\"后的值:" << *p2 * 10 << endl << endl;     // 输出p2指向的值和乘10后的结果

	cout << "p3的值:";                                                                // 输出p3数组的值
	int* begin = p3.get();
	int* end = p3.get() + 10;
	for (int* p = begin; p != end; p++)
	{
		cout << *p << " ";
	}
	cout << endl << "p3 \"修改\"后的值:";                                            // 输出p3数组"修改"后的值
	for (int i = 0; i < 10; i++)
	{
		cout << p3[i] + i << " ";	// 直接用下标（清晰），p3是unique_ptr<int[]>，支持[]
		//cout << *(p3.get() + i) + i << " ";  // 指针偏移（等价）
	}
	cout << endl << endl;


	cout << "p4的值:";                                                                // 输出p4容器的值
	for (auto x : *p4)
	{
		cout << x << " ";
	}
	cout << endl << "p4 \"修改\"后的值:";                                            // 输出p4容器"修改"后的值
	for (int i = 0; i < 10; i++)
	{
		cout << (*p4)[i] + i << " ";// 注意：p4是unique_ptr<vector<int>>，不能直接用[]
	}
	cout << endl << endl;


	cout << "p5 现在的值:" << *p5 << endl;                                          // 输出p5字符串的当前值
	*p5 = "world";                                                                  // 修改p5指向的字符串内容
	cout << "p5 现在的值:" << *p5 << endl;
	(*p5)[2] = '!';                                                                 // 修改p5字符串中索引为2的字符
	cout << "p5 现在的值:" << *p5 << endl;
	*p5 += "!!!!!!";                                                                // 在p5字符串末尾追加内容
	cout << "p5 现在的值:" << *p5 << endl;
	cout << endl;


	cout << "p6（结构体）现在的值：key=" << p6->key << ",val=" << p6->val << endl;  // 输出p6结构体的值
	p6->key = 100;                                                                  // 修改p6结构体的key值
	p6->val = "小米里的大麦";                                                       // 修改p6结构体的val值
	cout << "p6（结构体）现在的值：key=" << p6->key << ",val=" << p6->val << endl;
	cout << endl;


	cout << "p7（类）现在的值：";                                                    // 输出p7类对象的值
	p7->print();                                                                    // 调用p7对象的print方法
	p7->set(100, "小米里的大麦");                                                   // 调用p7对象的set方法修改值
	cout << "p7（类）现在的值：";
	p7->print();
	cout << endl;
}

// 测试unique_ptr的reset操作
void test2()
{
	unique_ptr<vector<int>> p1 = make_unique<vector<int>>(5, 5);                      // 创建vector容器，5个元素，每个为5

	cout << "p1 现在的值:";                                                         // 输出p1容器的当前值
	for (auto x : *p1)
	{
		cout << x << " ";
	}
	cout << endl;

	if (p1)                                                                         // 检查p1是否有效
	{
		cout << "p1 指针有效！" << endl;
	}
	else
	{
		cout << "p1 指针无效！" << endl;
	}

	p1.reset();                                                                     // 释放p1管理的内存，p1变为nullptr

	if (p1)                                                                         // 检查p1是否有效
	{
		cout << "p1 指针有效！" << endl;
	}
	else
	{
		cout << "p1 指针无效！" << endl;
	}

	// make_unique<T>(...) 返回的是 unique_ptr<T> 对象，而 reset 函数需要的是原生指针（如 t2*）。
	// 直接将 make_unique 的返回值传给 reset 会导致类型不匹配（unique_ptr<string> 无法转换为 t2*）。
	p1.reset(new vector<int>(10, 10));                                              // 重新分配内存，创建新的vector容器
	if (p1)
	{
		cout << "p1 指针有效！" << endl;
	}
	else
	{
		cout << "p1 指针无效！" << endl;
	}

	cout << "p1 现在的值:";                                                         // 输出p1容器的新值
	for (auto x : *p1)
	{
		cout << x << " ";
	}
	cout << endl << endl;
}

// 测试unique_ptr的get和release操作
void test3()
{
	unique_ptr<t2> p1 = make_unique<t2>(108, "minbit");                               // 创建t2类对象

	t2* pp1 = p1.get();                                                             // 获取p1管理的原始指针（不转移所有权）
	cout << "pp1 现在的值：";                                                        // 输出pp1指向对象的值
	pp1->print();
	cout << endl;
	if (p1)                                                                         // 检查p1是否有效
	{
		cout << "p1 指针有效！" << endl;
	}
	else
	{
		cout << "p1 指针无效！" << endl;
	}

	t2* pp2 = p1.release();                                                         // 释放p1的所有权，返回原始指针
	cout << "pp2 现在的值：";                                                        // 输出pp2指向对象的值
	pp2->print();
	cout << endl;
	if (p1)                                                                         // 检查p1是否有效（此时应该无效）
	{
		cout << "p1 指针有效！" << endl;
	}
	else
	{
		cout << "p1 指针无效！" << endl;
	}

	delete pp2;                                                                     // 手动释放pp2指向的内存
}

// 测试unique_ptr的swap操作
void test4()
{
	unique_ptr<int> p1 = make_unique<int>(10);                                      // 创建int类型的unique_ptr
	unique_ptr<int> p2 = make_unique<int>(20);                                      // 创建int类型的unique_ptr
	unique_ptr<double> p3 = make_unique<double>(30.0);                              // 创建double类型的unique_ptr

	cout << "p1 现在的值：" << *p1 << " ,p2 现在的值：" << *p2 << " ,p3 现在的值：" << *p3 << endl;
	p1.swap(p2);                                                                    // 交换p1和p2的所有权
	cout << "p1 现在的值：" << *p1 << " ,p2 现在的值：" << *p2 << " ,p3 现在的值：" << *p3 << endl;
	//p1.swap(p3);// 注意：类型不同，不能交换！

	cout << endl << endl;
}

// 测试unique_ptr的move操作
void test5()
{
	unique_ptr<t2> p1 = make_unique<t2>(108, "minbit");                               // 创建t2类对象的unique_ptr
	//unique_ptr<t2> p2(p1);// 注意：unique_ptr 不能直接拷贝，只能通过 move 转移所有权。

	unique_ptr<t2> p3 = move(p1);                                                   // 将p1的所有权转移给p3
	if (p1 == nullptr)                                                              // 检查p1是否变为nullptr
	{
		cout << "p1 已经变成 nullptr" << endl;
	}
	cout << "p3 现在的值：";                                                        // 输出p3指向对象的值
	p3->print();
}

int main()
{
	test1();
	test2();
	test3();
	test4();
	test5();

	return 0;
}