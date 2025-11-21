#include <iostream>
#include "shared_ptr.hpp"
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

// 测试shared_ptr的基本创建和访问操作
void test1()
{
	// 1. 创建 shared_ptr
	minbit::shared_ptr<int> p1(new int(10));			// 旧方式

	// 数组和容器
	minbit::shared_ptr<vector<int>> p2(new vector<int>(10, 5));                   // 创建vector容器，10个元素，每个为5
	minbit::shared_ptr<string> p3(new string("hello world"));                           // 创建string对象

	// 类、结构体
	minbit::shared_ptr<t1> p4(new t1());                                          // 创建结构体对象
	minbit::shared_ptr<t2> p5(new t2(20, "hello"));                                // 创建类对象


	// 2. 访问与修改
	cout << "p1的值:" << *p1 << " \"修改\"后的值:" << *p1 * 10 << endl << endl;     // 输出p1指向的值和乘10后的结果

	cout << "p2的值:";                                                                // 输出p2容器的值
	for (auto x : *p2)
	{
		cout << x << " ";
	}
	cout << endl << "p2 \"修改\"后的值:";                                            // 输出p2容器"修改"后的值
	for (int i = 0; i < 10; i++)
	{
		cout << (*p2)[i] + i << " ";// 注意：p2是shared_ptr<vector<int>>，不能直接用[]
	}
	cout << endl << endl;


	cout << "p3 现在的值:" << *p3 << endl;                                          // 输出p3字符串的当前值
	*p3 = "world";                                                                  // 修改p3指向的字符串内容
	cout << "p3 现在的值:" << *p3 << endl;
	(*p3)[2] = '!';                                                                 // 修改p3字符串中索引为2的字符
	cout << "p3 现在的值:" << *p3 << endl;
	*p3 += "!!!!!!";                                                                // 在p3字符串末尾追加内容
	cout << "p3 现在的值:" << *p3 << endl;
	cout << endl;


	cout << "p4（结构体）现在的值：key=" << p4->key << ",val=" << p4->val << endl;  // 输出p4结构体的值
	p4->key = 100;                                                                  // 修改p4结构体的key值
	p4->val = "小米里的大麦";                                                       // 修改p4结构体的val值
	cout << "p4（结构体）现在的值：key=" << p4->key << ",val=" << p4->val << endl;
	cout << endl;


	cout << "p5（类）现在的值：";                                                    // 输出p5类对象的值
	p5->print();                                                                    // 调用p5对象的print方法
	p5->set(100, "小米里的大麦");                                                   // 调用p5对象的set方法修改值
	cout << "p5（类）现在的值：";
	p5->print();
	cout << endl;

	cout << endl << endl;
}


void test2()
{
	minbit::shared_ptr<vector<int>> p1(new vector<int>(5, 5));  // 初始管理含5个5的vector

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

void test3()
{
	minbit::shared_ptr<t2> p1(new t2(108, "minbit"));
	cout << "p1的引用计数：" << p1.use_count() << endl;
	if (p1.unique())
	{
		cout << "现在p1 独占 所有权！" << endl;
	}
	else
	{
		cout << "现在p1 共享 所有权！" << endl;
	}
	minbit::shared_ptr<t2> p2 = p1;// 合法，p1和p2都是shared_ptr<t2>，共享同一个t2对象

	// 错误：类型不同，不可共享
	minbit::shared_ptr<t2> p3(new t2(10, "小米里的大麦"));
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

	minbit::shared_ptr<t2> p4 = p1;

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

void test4()
{
	minbit::shared_ptr<t2> p1(new t2(108, "minbit"));
	minbit::shared_ptr<t2> p2(new t2(666, "小米里的大麦"));
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

int main()
{
	test1();
	test2();
	test3();
	test4();

	return 0;
}