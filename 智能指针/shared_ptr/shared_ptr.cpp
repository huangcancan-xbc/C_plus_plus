#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "test.hpp"
using namespace std;

// 关于 shared_ptr 的常用操作：
// use_count():返回引用计数，即当前 shared_ptr 实例的引用数量（debug 用，避免依赖）
// unique()：判断是否独占所有权（use_count () == 1）
// reset():释放当前持有对象的所有权（引用计数减1），当计数为0时自动释放资源。可选参数：新的原生指针(T*)或nullptr，不能传入另一个shared_ptr（类型要一致）
// get():返回原生指针，获取原生指针（不影响引用计数，谨慎使用）
// swap():交换两个 shared_ptr 的所有权，类型要一样。
// operator bool():判断是否指向有效内存（非 nullptr）

// 测试shared_ptr的基本创建和访问操作
void test1()
{
	// 1. 创建 shared_ptr
	shared_ptr<int> p1(new int(10));			// 旧方式
	shared_ptr<int> p2 = make_shared<int>(10);	// 更推荐

	// 数组和容器
	// 注意：不能使用 make_shared 创建数组类型对象（标准库未提供 make_shared<T[]> 特化）
	shared_ptr<int[]> p3(new int[10]());                                              // 创建int数组并初始化（shared_ptr不能用make_shared创建数组）
	shared_ptr<vector<int>> p4 = make_shared<vector<int>>(10, 5);                   // 创建vector容器，10个元素，每个为5
	shared_ptr<string> p5 = make_shared<string>("hello");                           // 创建string对象

	// 类、结构体
	shared_ptr<t1> p6 = make_shared<t1>();                                          // 创建结构体对象
	shared_ptr<t2> p7 = make_shared<t2>(2, "world");                                // 创建类对象


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
	cout << endl << "p3 修改后的值:";                                            // 输出p3数组修改后的值
	for (int i = 0; i < 10; i++)
	{
		p3[i] = i;
		cout << p3[i] << " ";	// 直接用下标（清晰），p3是shared_ptr<int[]>，支持[]
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
		cout << (*p4)[i] + i << " ";// 注意：p4是shared_ptr<vector<int>>，不能直接用[]
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

// 测试shared_ptr的reset操作
void test2()
{
	shared_ptr<t2> p1 = make_shared<t2>(108, "minbit");
	cout << "p1的引用计数：" << p1.use_count() << endl;
	if (p1.unique())
	{
		cout << "现在p1 独占 所有权！" << endl;
	}
	else
	{
		cout << "现在p1 共享 所有权！" << endl;
	}
	shared_ptr<t2> p2 = p1;// 合法，p1和p2都是shared_ptr<t2>，共享同一个t2对象

	// 错误：类型不同，不可共享
	shared_ptr<t2> p3 = make_shared<t2>(10, "小米里的大麦");
	//shared_ptr<double> p4 = p3;  // 编译报错！int和double类型不匹配

	cout << "p1的引用计数：" << p1.use_count() << endl;
	if (p1.unique())
	{
		cout << "现在p1 独占 所有权！" << endl;
	}
	else
	{
		cout << "现在p1 共享 所有权！" << endl;
	}

	shared_ptr<t2> p4 = p1;

	p1.reset();
	if (p1 == nullptr)
	{
		cout << "p1 已经变成 nullptr" << endl;
	}
	cout << "p1的引用计数：" << p1.use_count() << endl;
	cout << "p2的引用计数：" << p2.use_count() << endl;
	cout << "p4的引用计数：" << p4.use_count() << endl;
	p2.reset();
	if (p2 == nullptr)
	{
		cout << "p2 已经变成 nullptr" << endl;
	}
	cout << "p1的引用计数：" << p1.use_count() << endl;
	cout << "p2的引用计数：" << p2.use_count() << endl;
	cout << "p4的引用计数：" << p4.use_count() << endl;
	// 创建一个新对象，然后用reset传入新对象的指针
	// 注意：reset() 方法的参数只能是原生指针（T*） 或 nullptr，不能直接传入另一个 shared_ptr 对象
	t2* p5 = new t2(666, "我是新的对象");
	p4.reset(p5);
	if (p4 == nullptr)
	{
		cout << "p4 已经变成 nullptr" << endl;
	}
	cout << "p1的引用计数：" << p1.use_count() << endl;
	cout << "p2的引用计数：" << p2.use_count() << endl;
	cout << "p4的引用计数：" << p4.use_count() << endl;

	p4->print();

	cout << endl;
}


void test3()
{
	shared_ptr<t2> p1 = make_shared<t2>(108, "minbit");
	shared_ptr<t2> p2 = make_shared<t2>(666, "小米里的大麦");
	if (p1 && p2)
	{
		cout << "p1 和 p2 都有效！" << endl;
	}

	cout << "此时p1的数据：";
	p1->print();
	cout << "此时p2的数据：";
	p2->print();

	p1.swap(p2);

	cout << "此时p1的数据：";
	p1->print();
	cout << "此时p2的数据：";
	p2->print();
}

// 少用
void test4()
{
	shared_ptr<int> p1 = make_shared<int>(10);
	shared_ptr<int> p2 = p1;  // 正常拷贝，计数变为 2（无需 move）

	// 特殊场景：用 move 转移后，原指针 p1 会变成 nullptr
	shared_ptr<int> p3 = move(p1);
	// 此时 p1 是 nullptr（计数 0），p3 持有资源（计数 1）
}

int main()
{
	test1();
	test2();
	test3();
	test4();

	return 0;
}