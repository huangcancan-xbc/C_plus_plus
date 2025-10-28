#pragma once
#include <iostream>
#include <cassert>
#include <type_traits>
#include <algorithm>
#include <iterator>
using namespace std;

namespace minbit
{
	template<class T>										// 类模板
	class vector
	{
	public:
		typedef T* iterator;								// 可读写迭代器
		typedef const T* const_iterator;					// 只读迭代器

		// 默认成员函数
		vector();                                           // 无参构造函数
        vector(size_t n);                                   // 有参构造函数
		vector(size_t n, const T& val);                     // 有参构造函数
		

        // 区间构造函数：使用 SFINAE 排除整数类型 (C++11/14/17 方式 - 需要使用 enable_if_t 在声明上，但类内定义时省略返回类型部分)
        // 注意：对于类内定义的成员函数模板，如果使用 enable_if 作为“返回类型”，会导致 C2533 错误。
        // 正确做法是使用 C++11 的 SFINAE 技巧，将 enable_if 放在参数列表中或使用其他方法。
        // 最简单兼容且标准的方法是将 enable_if 放在函数签名中，但作为模板参数的默认值（利用 SFINAE）。
        // 或者，像下面这样，将 enable_if 用在参数的默认值或模板参数默认值上，但最清晰的是使用 C++17 的 if constexpr (但这里不行) 或 C++11/14 的 SFINAE 技巧。

        // C++11/14 SFINAE 标准技巧：将 enable_if 作为函数模板的附加模板参数
        template<class InputIterator>
        vector(InputIterator first, InputIterator last,     // 区间构造函数
            typename std::enable_if<!std::is_integral<InputIterator>::value, int>::type* = 0) // SFINAE 约束
            : _start(nullptr)
            , _finish(nullptr)
            , _endofstorage(nullptr)
        {
            while (first != last)
            {
                push_back(static_cast<T>(*first));
                ++first;
            }
        }
        
        vector(const vector<T>& v);                         // 拷贝构造函数
		vector<T>& operator=(const vector<T>& v);           // 赋值运算符重载函数
		~vector();                                          // 析构函数

		// 迭代器相关函数
		iterator begin();
		iterator end();
		const_iterator begin()const;
		const_iterator end()const;

		// 容量和大小相关函数
		size_t size()const;
		size_t capacity()const;
		void reserve(size_t n);
		void resize(size_t n, const T& val = T());
		bool empty()const;

		// 修改容器内容相关函数
		void push_back(const T& x);
		void pop_back();
		void insert(iterator pos, const T& x);
		iterator erase(iterator pos);
		void swap(vector<T>& v);
		void clear();

		// 访问容器相关函数
		T& operator[](size_t i);
		const T& operator[](size_t i)const;

	private:
		iterator _start;									// 指向容器的第一个元素（头）
		iterator _finish;									// 指向有效数据的尾
		iterator _endofstorage;								// 指向容器的末尾

		static const size_t DEFAULT_CAPACITY;				// 默认初始容量
		static const double GROWTH_FACTOR;					// 扩容倍数
	};
}



namespace minbit
{
    template<class T>
    const size_t vector<T>::DEFAULT_CAPACITY = 4;

    template<class T>
    const double vector<T>::GROWTH_FACTOR = 2.0;

    //1. 迭代器相关函数
    template<class T>
    typename vector<T>::iterator vector<T>::begin()
    {
        return _start;
    }

    template<class T>
    typename vector<T>::iterator vector<T>::end()
    {
        return _finish;
    }

    template<class T>
    typename vector<T>::const_iterator vector<T>::begin()const
    {
        return _start;
    }

    template<class T>
    typename vector<T>::const_iterator vector<T>::end()const
    {
        return _finish;
    }




    // 2. 默认成员函数
    template<class T>
    vector<T>::vector()                         // 无参构造函数
        : _start(nullptr),
        _finish(nullptr),
        _endofstorage(nullptr)
    {

    }

    template<class T>
    vector<T>::vector(size_t n)                 // 无参构造函数
        : _start(nullptr),
        _finish(nullptr),
        _endofstorage(nullptr)
    {
        resize(n);                              // 使用resize来实现构造
    }

    template<class T>
    vector<T>::vector(size_t n, const T& val)   // 有参构造函数
        : _start(nullptr),
        _finish(nullptr),
        _endofstorage(nullptr)
    {
        resize(n, val);                         // 使用resize来实现构造
    }

    template<class T>
    vector<T>::vector(const vector<T>& v)       // 拷贝构造函数
        : _start(nullptr),
        _finish(nullptr),
        _endofstorage(nullptr)
    {
        reserve(v.capacity());                  // 先分配足够的空间
        for (size_t i = 0; i < v.size(); i++)
        {
            _start[i] = v._start[i];            // 再拷贝元素
        }

        _finish = _start + v.size();
        _endofstorage = _start + v.capacity();  // 还需要记录一下容量
    }

    template<class T>                           // 赋值运算符重载函数
    vector<T>& vector<T>::operator=(const vector<T>& v)
    {
        if (*this != v)                         // 自赋值检查
        {
            vector<T> temp(v);                  // 复制构造临时对象
            swap(temp);                         // 交换
        }

        return *this;
    }

    template<class T>
    vector<T>::~vector()
    {
        if (_start)                             // 如果有空间，释放空间
        {
            delete[] _start;                    // 释放容器存储数据的空间
            _start = nullptr;
            _finish = nullptr;
            _endofstorage = nullptr;
        }
    }




    // 3. 容量和大小相关函数
    template<class T>
    size_t vector<T>::size()const
    {
        return _finish - _start;
    }

    template<class T>
    size_t vector<T>::capacity()const
    {
        return _endofstorage - _start;
    }

    template<class T>
    bool vector<T>::empty()const
    {
        return _start == _finish;
    }

    template<class T>
    void vector<T>::reserve(size_t n)
    {
        if (n > capacity())                 // 扩容大小到 n（直接选用异地扩容）
        {
            size_t old_size = size();
            T* new_vec = new T[n];

            for (size_t i = 0; i < old_size; i++)
            {
                new_vec[i] = _start[i];     // _start[i] === *(_start + i)  // 指针算术运算（等价）
            }

            delete[] _start;
            _start = new_vec;
            _finish = _start + old_size;
            _endofstorage = _start + n;
        }
    }

    // val = T() 必须在声明中：这是C++语法要求
    // 实现中不能重复默认参数：实现中只写 const T& val
    template<class T>
    void vector<T>::resize(size_t n, const T& val)
    {
        //已有的元素保持不变
        //新增的位置用指定值填充
        //删除的位置不再访问（通过移动 _finish 指针实现）
        if (n < size())                     // 情况1：如果要缩小容量，需要删除多余的元素
        {
            _finish = _start + n;
        }
        else if (n > size())                // 情况2：如果要扩容，需要确保容量足够
        {
            if (n > capacity())
            {
                reserve(n);                 // 扩容大小到 n
            }

            // 对扩容后的元素进行赋值
            while (_finish < _start + n)
            {
                *_finish = val;
                _finish++;
            }
        }
        else
        {
            // 情况3：如果大小没有变化，什么都不做
        }
    }





    // 4. 修改容器内容相关函数
    template<class T>
    void vector<T>::push_back(const T& x)   // push_back 尾插元素
    {
        if (_finish == _endofstorage)       // 先看看容量是否足够，要不要扩容
        {
            size_t newCapacity = capacity() == 0 ? DEFAULT_CAPACITY : static_cast<size_t>(GROWTH_FACTOR * capacity());  // 将容量扩大为原来的两倍
            reserve(newCapacity);
        }

        *_finish = x;                       // 直接将元素放入尾端
        _finish++;                          // 移动尾端指针
    }

    template<class T>
    void vector<T>::pop_back()              // pop_back 尾删元素
    {
        //!empty();等价于 !this->empty() 或 !(*this).empty()
        assert(!empty());                   // 注意数组不能为空
        _finish--;                          // 移动尾端指针
    }

    template<class T>                       // insert 插入元素
    void vector<T>::insert(iterator pos, const T& x)
    {
        // 注意：我们使用的是异地扩容，pos指针指向旧内存可能失效！这里需要计算/保存一下其相对位置
        if (_finish == _endofstorage)       // 先看看容量是否足够，要不要扩容
        {
            size_t len = pos - _start;      // 记录相对位置
            size_t newCapacity = capacity() == 0 ? DEFAULT_CAPACITY : static_cast<size_t>(GROWTH_FACTOR * capacity());  // 将容量扩大为原来的两倍
            reserve(newCapacity);
            pos = _start + len;             // 重新计算pos指针
        }

        // 如果插入位置在最后一个位置还要后面就直接尾插
        if (pos > _finish)
        {
            push_back(x);
            return;
        }

        iterator it = _finish - 1;          // 从后往前移动元素，为新元素腾出位置
        while (it >= pos)
        {
            *(it + 1) = *it;                // 元素向后移动一位
            --it;
        }

        *pos = x;                           // 插入新元素
        ++_finish;                          // 数据个数增加一个，_finish后移
    }

    template<class T>                       // erase 删除 pos 位置的元素
    typename vector<T>::iterator vector<T>::erase(iterator pos)
    {
        assert(!empty());                   // 注意数组不能为空

        for (iterator it = pos; it != _finish; it++)
        {
            *it = *(it + 1);                // 元素向前移动一位
        }

        _finish--;                          // 数据个数减少一个，_finish前移
        return pos;                         // 返回删除元素的位置
    }

    template<class T>
    void vector<T>::swap(vector<T>& v)      // 交换两个容器的数据
    {
        std::swap(_start, v._start);
        std::swap(_finish, v._finish);
        std::swap(_endofstorage, v._endofstorage);
    }

    //"垃圾数据"还在存在内存中
    //为什么不清理：性能考虑，标准库也是这样
    //数据最终去向：被新数据覆盖，或程序结束时被OS回收
    template<class T>
    void vector<T>::clear()
    {
        _finish = _start;                   // 重置指针
    }






    // 访问容器相关函数
    template<class T>
    T& vector<T>::operator[](size_t i)      // 重载 [] 运算符，进行下标访问
    {
        assert(i < size());                 // 注意下标越界

        return _start[i];
    }

    template<class T>
    const T& vector<T>::operator[](size_t i)const
    {
        assert(i < size());                 // 注意下标越界

        return _start[i];
    }
}