#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <utility>


template <class T>
struct hashNode
{
	T _data;				// 存储的数据
	hashNode<T>* _next;		// 指向下一个节点的指针

	// 构造函数
	hashNode(const T& data)
		:_data(data),
		_next(nullptr)
	{

	}

	// 移动构造
	hashNode(const T&& data)
		:_data(std::move(data)),
		_next(nullptr)
	{

	}
};