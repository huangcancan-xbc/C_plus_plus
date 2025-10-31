#pragma once

#include <iostream>
#include <deque>
using namespace std;

namespace minbit
{
	template<class T, class Container = deque<T>>
	class Mystack
	{
	public:
		Mystack() {}
		~Mystack() {}

		T& top()		// 允许进行修改
		{
			return _con.front();
		}

		const T& top() const	// 不允许进行修改且不会修改类的任何成员变量
		{
			return _con.front();
		}

		void push(const T& val)
		{
			_con.push_front(val);
		}

		void pop()
		{
			_con.pop_front();
		}

		bool empty() const
		{
			return _con.empty();
		}

		void clear()
		{
			_con.clear();
		}

		int size() const
		{
			return _con.size();
		}

		void swap(Mystack<T, Container>& other)noexcept
		{
			_con.swap(other._con);	// 不拷贝数据，只交换底层容器的内部指针
		}

	private:
		Container _con;
	};
}