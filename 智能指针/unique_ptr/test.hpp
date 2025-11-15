#pragma once

#include <iostream>
#include <string>
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