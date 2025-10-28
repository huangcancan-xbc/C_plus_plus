#pragma once
#include <iostream>
#include <cassert>
#include <type_traits>
#include <algorithm>
#include <iterator>
using namespace std;

namespace minbit
{
	template<class T>										// ��ģ��
	class vector
	{
	public:
		typedef T* iterator;								// �ɶ�д������
		typedef const T* const_iterator;					// ֻ��������

		// Ĭ�ϳ�Ա����
		vector();                                           // �޲ι��캯��
        vector(size_t n);                                   // �вι��캯��
		vector(size_t n, const T& val);                     // �вι��캯��
		

        // ���乹�캯����ʹ�� SFINAE �ų��������� (C++11/14/17 ��ʽ - ��Ҫʹ�� enable_if_t �������ϣ������ڶ���ʱʡ�Է������Ͳ���)
        // ע�⣺�������ڶ���ĳ�Ա����ģ�壬���ʹ�� enable_if ��Ϊ���������͡����ᵼ�� C2533 ����
        // ��ȷ������ʹ�� C++11 �� SFINAE ���ɣ��� enable_if ���ڲ����б��л�ʹ������������
        // ��򵥼����ұ�׼�ķ����ǽ� enable_if ���ں���ǩ���У�����Ϊģ�������Ĭ��ֵ������ SFINAE����
        // ���ߣ��������������� enable_if ���ڲ�����Ĭ��ֵ��ģ�����Ĭ��ֵ�ϣ�������������ʹ�� C++17 �� if constexpr (�����ﲻ��) �� C++11/14 �� SFINAE ���ɡ�

        // C++11/14 SFINAE ��׼���ɣ��� enable_if ��Ϊ����ģ��ĸ���ģ�����
        template<class InputIterator>
        vector(InputIterator first, InputIterator last,     // ���乹�캯��
            typename std::enable_if<!std::is_integral<InputIterator>::value, int>::type* = 0) // SFINAE Լ��
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
        
        vector(const vector<T>& v);                         // �������캯��
		vector<T>& operator=(const vector<T>& v);           // ��ֵ��������غ���
		~vector();                                          // ��������

		// ��������غ���
		iterator begin();
		iterator end();
		const_iterator begin()const;
		const_iterator end()const;

		// �����ʹ�С��غ���
		size_t size()const;
		size_t capacity()const;
		void reserve(size_t n);
		void resize(size_t n, const T& val = T());
		bool empty()const;

		// �޸�����������غ���
		void push_back(const T& x);
		void pop_back();
		void insert(iterator pos, const T& x);
		iterator erase(iterator pos);
		void swap(vector<T>& v);
		void clear();

		// ����������غ���
		T& operator[](size_t i);
		const T& operator[](size_t i)const;

	private:
		iterator _start;									// ָ�������ĵ�һ��Ԫ�أ�ͷ��
		iterator _finish;									// ָ����Ч���ݵ�β
		iterator _endofstorage;								// ָ��������ĩβ

		static const size_t DEFAULT_CAPACITY;				// Ĭ�ϳ�ʼ����
		static const double GROWTH_FACTOR;					// ���ݱ���
	};
}



namespace minbit
{
    template<class T>
    const size_t vector<T>::DEFAULT_CAPACITY = 4;

    template<class T>
    const double vector<T>::GROWTH_FACTOR = 2.0;

    //1. ��������غ���
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




    // 2. Ĭ�ϳ�Ա����
    template<class T>
    vector<T>::vector()                         // �޲ι��캯��
        : _start(nullptr),
        _finish(nullptr),
        _endofstorage(nullptr)
    {

    }

    template<class T>
    vector<T>::vector(size_t n)                 // �޲ι��캯��
        : _start(nullptr),
        _finish(nullptr),
        _endofstorage(nullptr)
    {
        resize(n);                              // ʹ��resize��ʵ�ֹ���
    }

    template<class T>
    vector<T>::vector(size_t n, const T& val)   // �вι��캯��
        : _start(nullptr),
        _finish(nullptr),
        _endofstorage(nullptr)
    {
        resize(n, val);                         // ʹ��resize��ʵ�ֹ���
    }

    template<class T>
    vector<T>::vector(const vector<T>& v)       // �������캯��
        : _start(nullptr),
        _finish(nullptr),
        _endofstorage(nullptr)
    {
        reserve(v.capacity());                  // �ȷ����㹻�Ŀռ�
        for (size_t i = 0; i < v.size(); i++)
        {
            _start[i] = v._start[i];            // �ٿ���Ԫ��
        }

        _finish = _start + v.size();
        _endofstorage = _start + v.capacity();  // ����Ҫ��¼һ������
    }

    template<class T>                           // ��ֵ��������غ���
    vector<T>& vector<T>::operator=(const vector<T>& v)
    {
        if (*this != v)                         // �Ը�ֵ���
        {
            vector<T> temp(v);                  // ���ƹ�����ʱ����
            swap(temp);                         // ����
        }

        return *this;
    }

    template<class T>
    vector<T>::~vector()
    {
        if (_start)                             // ����пռ䣬�ͷſռ�
        {
            delete[] _start;                    // �ͷ������洢���ݵĿռ�
            _start = nullptr;
            _finish = nullptr;
            _endofstorage = nullptr;
        }
    }




    // 3. �����ʹ�С��غ���
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
        if (n > capacity())                 // ���ݴ�С�� n��ֱ��ѡ��������ݣ�
        {
            size_t old_size = size();
            T* new_vec = new T[n];

            for (size_t i = 0; i < old_size; i++)
            {
                new_vec[i] = _start[i];     // _start[i] === *(_start + i)  // ָ���������㣨�ȼۣ�
            }

            delete[] _start;
            _start = new_vec;
            _finish = _start + old_size;
            _endofstorage = _start + n;
        }
    }

    // val = T() �����������У�����C++�﷨Ҫ��
    // ʵ���в����ظ�Ĭ�ϲ�����ʵ����ֻд const T& val
    template<class T>
    void vector<T>::resize(size_t n, const T& val)
    {
        //���е�Ԫ�ر��ֲ���
        //������λ����ָ��ֵ���
        //ɾ����λ�ò��ٷ��ʣ�ͨ���ƶ� _finish ָ��ʵ�֣�
        if (n < size())                     // ���1�����Ҫ��С��������Ҫɾ�������Ԫ��
        {
            _finish = _start + n;
        }
        else if (n > size())                // ���2�����Ҫ���ݣ���Ҫȷ�������㹻
        {
            if (n > capacity())
            {
                reserve(n);                 // ���ݴ�С�� n
            }

            // �����ݺ��Ԫ�ؽ��и�ֵ
            while (_finish < _start + n)
            {
                *_finish = val;
                _finish++;
            }
        }
        else
        {
            // ���3�������Сû�б仯��ʲô������
        }
    }





    // 4. �޸�����������غ���
    template<class T>
    void vector<T>::push_back(const T& x)   // push_back β��Ԫ��
    {
        if (_finish == _endofstorage)       // �ȿ��������Ƿ��㹻��Ҫ��Ҫ����
        {
            size_t newCapacity = capacity() == 0 ? DEFAULT_CAPACITY : static_cast<size_t>(GROWTH_FACTOR * capacity());  // ����������Ϊԭ��������
            reserve(newCapacity);
        }

        *_finish = x;                       // ֱ�ӽ�Ԫ�ط���β��
        _finish++;                          // �ƶ�β��ָ��
    }

    template<class T>
    void vector<T>::pop_back()              // pop_back βɾԪ��
    {
        //!empty();�ȼ��� !this->empty() �� !(*this).empty()
        assert(!empty());                   // ע�����鲻��Ϊ��
        _finish--;                          // �ƶ�β��ָ��
    }

    template<class T>                       // insert ����Ԫ��
    void vector<T>::insert(iterator pos, const T& x)
    {
        // ע�⣺����ʹ�õ���������ݣ�posָ��ָ����ڴ����ʧЧ��������Ҫ����/����һ�������λ��
        if (_finish == _endofstorage)       // �ȿ��������Ƿ��㹻��Ҫ��Ҫ����
        {
            size_t len = pos - _start;      // ��¼���λ��
            size_t newCapacity = capacity() == 0 ? DEFAULT_CAPACITY : static_cast<size_t>(GROWTH_FACTOR * capacity());  // ����������Ϊԭ��������
            reserve(newCapacity);
            pos = _start + len;             // ���¼���posָ��
        }

        // �������λ�������һ��λ�û�Ҫ�����ֱ��β��
        if (pos > _finish)
        {
            push_back(x);
            return;
        }

        iterator it = _finish - 1;          // �Ӻ���ǰ�ƶ�Ԫ�أ�Ϊ��Ԫ���ڳ�λ��
        while (it >= pos)
        {
            *(it + 1) = *it;                // Ԫ������ƶ�һλ
            --it;
        }

        *pos = x;                           // ������Ԫ��
        ++_finish;                          // ���ݸ�������һ����_finish����
    }

    template<class T>                       // erase ɾ�� pos λ�õ�Ԫ��
    typename vector<T>::iterator vector<T>::erase(iterator pos)
    {
        assert(!empty());                   // ע�����鲻��Ϊ��

        for (iterator it = pos; it != _finish; it++)
        {
            *it = *(it + 1);                // Ԫ����ǰ�ƶ�һλ
        }

        _finish--;                          // ���ݸ�������һ����_finishǰ��
        return pos;                         // ����ɾ��Ԫ�ص�λ��
    }

    template<class T>
    void vector<T>::swap(vector<T>& v)      // ������������������
    {
        std::swap(_start, v._start);
        std::swap(_finish, v._finish);
        std::swap(_endofstorage, v._endofstorage);
    }

    //"��������"���ڴ����ڴ���
    //Ϊʲô���������ܿ��ǣ���׼��Ҳ������
    //��������ȥ�򣺱������ݸ��ǣ���������ʱ��OS����
    template<class T>
    void vector<T>::clear()
    {
        _finish = _start;                   // ����ָ��
    }






    // ����������غ���
    template<class T>
    T& vector<T>::operator[](size_t i)      // ���� [] ������������±����
    {
        assert(i < size());                 // ע���±�Խ��

        return _start[i];
    }

    template<class T>
    const T& vector<T>::operator[](size_t i)const
    {
        assert(i < size());                 // ע���±�Խ��

        return _start[i];
    }
}