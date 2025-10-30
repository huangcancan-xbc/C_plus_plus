#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;

namespace minbit
{
	class string
	{
	public:
		typedef char* iterator;						// 普通迭代器（可读可写）
		typedef const char* const_iterator;			// 常量迭代器（只读）

		static const size_t npos = -1;				// 静态成员变量，表示未找到的值

		iterator begin()							// 返回字符串起始位置
		{
			return _str;
		}

		iterator end()								// 返回字符串的结束位置
		{
			return _str + _size;
		}

		const_iterator begin() const				// 返回字符串起始位置（只读）
		{
			return _str;
		}

		const_iterator end() const					// 返回字符串的结束位置（只读）
		{
			return _str + _size;
		}


		string(const char* str = "")				// 带默认参数的构造函数，即默认构造函数
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		string(const string& s)						// 拷贝构造函数
		{
			_str = new char[s._capacity + 1];
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;
		}

		~string()									// 析构函数
		{
			delete[] _str;
			_str = nullptr;
			_capacity = _size = 0;
		}

		const char* c_str() const					// 以const char*形式返回字符串
		{
			return _str;
		}

		size_t size() const							// 返回字符串的长度
		{
			return _size;
		}

		size_t length() const						// 返回字符串的长度，同size()函数
		{
			return _size;
		}

		size_t capacity() const						// 返回字符串的容量
		{
			return _capacity;
		}

		char& operator[](size_t index)				// 重载[]运算符，获取字符串的第index个字符，可修改
		{
			assert(index < _size);
			return _str[index];
		}

		const char& operator[](size_t index) const	// 重载[]运算符，获取字符串的第index个字符，只读
		{
			assert(index < _size);
			return _str[index];
		}

		void reserve(size_t new_capacity)			// 预留字符串容量
		{
			if (new_capacity > _capacity)
			{
				char* new_str = new char[new_capacity + 1];
				strcpy(new_str, _str);
				delete[] _str;
				_str = new_str;
				_capacity = new_capacity;
			}
		}

		void push_back(char c)						// 尾插字符
		{
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}

			_str[_size++] = c;
			_str[_size] = '\0';
		}

		void append(const char* str)				// 尾插字符串
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_capacity == 0 ? len : _capacity + len);
			}

			strcpy(_str + _size, str);
			_size += len;
			_str[_size] = '\0';
		}

		string& operator+= (char c)					// 重载+=运算符，尾插字符
		{
			push_back(c);
			return *this;
		}

		string& operator+= (const char* str)		// 重载+=运算符，尾插字符串
		{
			append(str);
			return *this;
		}

		void insert(size_t pos, size_t len, const char c)			// 在指定位置插入多个字符
		{
			assert(pos <= _size);

			if (_size + len > _capacity)
			{
				reserve(_capacity == 0 ? len : _capacity + len);
			}

			for (size_t i = _size; i >= (int)pos; --i)
			{
				_str[i + len] = _str[i];
			}

			for (size_t i = 0; i < len; ++i)
			{
				_str[pos + i] = c;
			}

			_size += len;
			_str[_size] = '\0';
		}

		void insert(size_t pos, const char* str)					// 插入字符串
		{
			assert(pos <= _size);

			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_capacity == 0 ? len : _capacity + len);
			}

			size_t end = _size;
			while (end >= pos && end != npos)
			{
				_str[end + len] = _str[end];
				--end;
			}

			for (size_t i = 0; i < len; ++i)
			{
				_str[pos + i] = str[i];
			}

			_size += len;
		}

		void erase(iterator p)										// 删除字符串中 p 所指向的字符
		{
			assert(p >= _str && p < _str + _size);

			for (size_t i = p - _str; i < _size - 1; ++i)
			{
				_str[i] = _str[i + 1];
			}
			//for (char* q = p; q < _str + _size - 1; ++q)
			//{
			//	*q = *(q + 1);
			//}

			--_size;
			_str[_size] = '\0';
		}

		void erase(iterator first, iterator last)					// 删除字符串中的指定范围 [first,last) 的字符
		{
			assert(first >= _str && first <= last && last <= _str + _size);
			size_t len = last - first;
			for (size_t i = first - _str; i < _size - len; i++)
			{
				_str[i] = _str[i + len];
			}

			_size -= len;
			_str[_size] = '\0';
		}

		void erase(size_t pos, size_t len)							// 删除字符串中从指定位置 pos 开始的 len 个字符
		{
			assert(pos >= 0 && pos <= _size);
			for (size_t i = pos; i < _size - len; i++)
			{
				_str[i] = _str[i + len];
			}

			_size -= len;
			_str[_size] = '\0';
		}

		void clear()												// 清空字符串
		{
			_size = 0;
			_str[_size] = '\0';
		}

		size_t find(const char ch, size_t pos = 0)					// 在当前字符串从 pos 指定位置（默认为 0）开始查找字符 c，返回找到的位置，-1 表示未找到字符
		{
			assert(pos < _size);

			for (size_t i = pos; i < _size; i++)
			{
				if (_str[i] == ch)
				{
					return i;
				}
			}

			return npos;
		}

		size_t find(const char* str, size_t pos = 0)				// 在当前字符串从 pos 指定位置（默认为 0）开始查找子串 str，返回找到的位置，-1 表示未找到子串
		{
			assert(pos < _size);

			const char* p = strstr(_str + pos, str);
			if (p == nullptr)
			{
				return npos;
			}
			else
			{
				return p - _str;
			}
		}

		string substr(size_t pos = 0, size_t len = npos)				// 截取子字符串
		{
			assert(pos < _size);

			size_t n = len;
			if (len == npos || pos + len > _size)
			{
				n = _size - pos;
			}

			string ret;
			ret.reserve(n);
			for (size_t i = pos; i < pos + n; i++)
			{
				ret += _str[i];
			}

			return ret;
		}



		int operator<(const string& s) const						// 重载<运算符，比较两个字符串的大小
		{
			// 注意：strcmp 会一直比较直到遇到字符串的某个位置 \0 才会停止，可能会越界，这里使用 memcmp + 长度判断更安全
			int ret = memcmp(_str, s._str, _size < s._size ? _size : s._size);
			return ret == 0 ? (int)(_size < s._size) : ret < 0;
		}

		int operator>(const string& s) const						// 重载>运算符，比较两个字符串的大小
		{
			int ret = memcmp(_str, s._str, _size < s._size ? _size : s._size);
			return ret == 0 ? (int)(_size > s._size) : ret > 0;
		}

		bool operator==(const string& s) const						// 重载==运算符，比较两个字符串是否相等
		{
			return _size == s._size && memcmp(_str, s._str, _size) == 0;
		}

		bool operator>= (const string& s) const						// 重载>=运算符，比较两个字符串的大小
		{
			return !(*this < s);
		}

		bool operator<= (const string& s) const						// 重载<=运算符，比较两个字符串的大小
		{
			return !(*this > s);
		}

		bool operator!=(const string& s) const						// 重载!=运算符，比较两个字符串是否不相等
		{
			return !(*this == s);
		}

		string& operator=(const string& s)							// 重载赋值运算符
		{
			if (this != &s)
			{
				delete[] _str;
				_size = s._size;
				_capacity = s._capacity;
				_str = new char[_capacity + 1];
				strcpy(_str, s._str);
			}

			return *this;
		}


	private:
		char* _str;					// 存储字符串
		size_t _size;				// 记录当前字符串长度
		size_t _capacity;			// 记录当前字符串容量
	};

	// 头文件中使用 inline 关键字，否则会出现重定义错误
	inline ostream& operator<<(ostream& out, const string& s)
	{
		for (auto x : s)
		{
			out << x;
		}
		return out;
	}

	inline istream& operator>>(istream& in, string& s)
	{
		s.clear();

		char ch = in.get();
		// 过滤掉前面的空格和换行
		while (ch == ' ' || ch == '\n')
		{
			ch = in.get();
		}

		char buffer[128];
		size_t i = 0;

		while (ch != ' ' && ch != '\n' && ch != EOF)
		{
			buffer[i++] = ch;

			if (i == 127)
			{
				buffer[i] = '\0';
				s += buffer;
				i = 0;
			}

			ch = in.get();
		}

		if (i != 0)
		{
			buffer[i] = '\0';
			s += buffer;
		}

		return in;
	}
};

// 静态成员变量的定义
//const size_t string::npos = -1;



//#define _CRT_SECURE_NO_WARNINGS
//#pragma once
//#include <iostream>
//#include <cstring>
//#include <cassert>
//using namespace std;
//
//namespace minbit
//{
//	class string
//	{
//	public:
//		typedef char* iterator;						// ���������Ͷ��壨�ɶ���д��
//		typedef const char* const_iterator;			// ���������Ͷ��壨ֻ����
//
//		static const size_t npos = -1;				// ��̬��Ա�������������ֵ��
//
//		iterator begin()							// ����������ʼλ��
//		{
//			return _str;
//		}
//
//		iterator end()								// �������Ľ���λ��
//		{
//			return _str + _size;
//		}
//
//		const_iterator begin() const				// ����������ʼλ�ã�ֻ����
//		{
//			return _str;
//		}
//
//		const_iterator end() const					// �������Ľ���λ�ã�ֻ����
//		{
//			return _str + _size;
//		}
//
//
//		string(const char* str = "")				// ȫȱʡ�����Ĺ��캯������Ĭ�Ϲ��캯��
//		{
//			_size = strlen(str);
//			_capacity = _size;
//			_str = new char[_capacity + 1];
//			strcpy(_str, str);
//		}
//
//		string(const string& s)						// �������캯��
//		{
//			_str = new char[s._capacity + 1];
//			strcpy(_str, s._str);
//			_size = s._size;
//			_capacity = s._capacity;
//		}
//
//		~string()									// ��������
//		{
//			delete[] _str;
//			_str = nullptr;
//			_capacity = _size = 0;
//		}
//
//		const char* c_str() const					// ������const char*��ʽ���ַ���
//		{
//			return _str;
//		}
//
//		size_t size() const							// �����ַ����ĳ���
//		{
//			return _size;
//		}
//
//		size_t length() const						// �����ַ����ĳ��ȣ�ͬsize()��
//		{
//			return _size;
//		}
//
//		size_t capacity() const						// �����ַ���������
//		{
//			return _capacity;
//		}
//
//		char& operator[](size_t index)				// ����[]������������ַ����ĵ�index���ַ������޸ģ�
//		{
//			assert(index < _size);
//			return _str[index];
//		}
//
//		const char& operator[](size_t index) const	// ����[]������������ַ����ĵ�index���ַ���ֻ����
//		{
//			assert(index < _size);
//			return _str[index];
//		}
//
//		void reserve(size_t new_capacity)			// �����ַ���������
//		{
//			if (new_capacity > _capacity)
//			{
//				char* new_str = new char[new_capacity + 1];
//				strcpy(new_str, _str);
//				delete[] _str;
//				_str = new_str;
//				_capacity = new_capacity;
//			}
//		}
//
//		void push_back(char c)						// β���ַ�
//		{
//			if (_size == _capacity)
//			{
//				reserve(_capacity == 0 ? 4 : _capacity * 2);
//			}
//
//			_str[_size++] = c;
//			_str[_size] = '\0';
//		}
//
//		void append(const char* str)				// β���ַ���
//		{
//			size_t len = strlen(str);
//			if (_size + len > _capacity)
//			{
//				reserve(_capacity == 0 ? len : _capacity + len);
//			}
//
//			strcpy(_str + _size, str);
//			_size += len;
//			_str[_size] = '\0';
//		}
//
//		string& operator+= (char c)					// ����+=�������β���ַ�
//		{
//			push_back(c);
//			return *this;
//		}
//
//		string& operator+= (const char* str)		// ����+=�������β���ַ���
//		{
//			append(str);
//			return *this;
//		}
//
//		void insert(size_t pos, size_t len, const char c)			// �������ɸ��ַ�
//		{
//			assert(pos <= _size);
//
//			if (_size + len > _capacity)
//			{
//				reserve(_capacity == 0 ? len : _capacity + len);
//			}
//
//			for (size_t i = _size; i >= (int)pos; --i)
//			{
//				_str[i + len] = _str[i];
//			}
//
//			for (size_t i = 0; i < len; ++i)
//			{
//				_str[pos + i] = c;
//			}
//
//			_size += len;
//			_str[_size] = '\0';
//		}
//
//		void insert(size_t pos, const char* str)					// �����ַ���
//		{
//			assert(pos <= _size);
//
//			size_t len = strlen(str);
//			if (_size + len > _capacity)
//			{
//				reserve(_capacity == 0 ? len : _capacity + len);
//			}
//
//			size_t end = _size;
//			while (end >= pos && end != npos)
//			{
//				_str[end + len] = _str[end];
//				--end;
//			}
//
//			for (size_t i = 0; i < len; ++i)
//			{
//				_str[pos + i] = str[i];
//			}
//
//			_size += len;
//		}
//
//		void erase(iterator p)										// ɾ���ַ����� p ��ָ���ַ�
//		{
//			assert(p >= _str && p < _str + _size);
//
//			for (size_t i = p - _str; i < _size - 1; ++i)
//			{
//				_str[i] = _str[i + 1];
//			}
//			//for (char* q = p; q < _str + _size - 1; ++q)
//			//{
//			//	*q = *(q + 1);
//			//}
//
//			--_size;
//			_str[_size] = '\0';
//		}
//
//		void erase(iterator first, iterator last)					// ɾ���ַ����е��������� [first,last) �������ַ�
//		{
//			assert(first >= _str && first <= last && last <= _str + _size);
//			size_t len = last - first;
//			for (size_t i = first - _str; i < _size - len; i++)
//			{
//				_str[i] = _str[i + len];
//			}
//
//			_size -= len;
//			_str[_size] = '\0';
//		}
//
//		void erase(size_t pos, size_t len)							// ɾ���ַ����д�����λ�� pos ��ʼ�� len ���ַ�
//		{
//			assert(pos >= 0 && pos <= _size);
//			for (size_t i = pos; i < _size - len; i++)
//			{
//				_str[i] = _str[i + len];
//			}
//
//			_size -= len;
//			_str[_size] = '\0';
//		}
//
//		void clear()												// ����ַ���
//		{
//			_size = 0;
//			_str[_size] = '\0';
//		}
//
//		size_t find(const char ch, size_t pos = 0)					// �ڵ�ǰ�ַ����� pos ����λ�ã�Ĭ��Ϊ 0����ʼ�������ַ� c�������ҵ���λ��������-1 ��ʾ���Ҳ����ַ�
//		{
//			assert(pos < _size);
//
//			for (size_t i = pos; i < _size; i++)
//			{
//				if (_str[i] == ch)
//				{
//					return i;
//				}
//			}
//
//			return npos;
//		}
//
//		size_t find(const char* str, size_t pos = 0)				// �ڵ�ǰ�ַ����� pos ����λ�ã�Ĭ��Ϊ 0����ʼ�������Ӵ� str�������ҵ���λ��������-1 ��ʾ���Ҳ����Ӵ�
//		{
//			assert(pos < _size);
//
//			const char* p = strstr(_str + pos, str);
//			if (p == nullptr)
//			{
//				return npos;
//			}
//			else
//			{
//				return p - _str;
//			}
//		}
//
//		string substr(size_t pos = 0, size_t len = npos)
//		{
//			assert(pos < _size);
//
//			size_t n = len;
//			if (len == npos || pos + len > _size)
//			{
//				n = _size - pos;
//			}
//
//			string ret;
//			ret.reserve(n);
//			for (size_t i = pos; i < pos + n; i++)
//			{
//				ret += _str[i];
//			}
//
//			return ret;
//		}
//
//
//
//		int operator<(const string& s) const						// ����<��������Ƚ������ַ����Ĵ�С
//		{
//			// ע�⣺strcmp ��һֱ�������ֱ�������ڴ���ĳ������� \0�����ܵ��£���Խ�磨���������ȽϽ������
//			// ���Ա����� memcmp + ��ʽ����
//			int ret = memcmp(_str, s._str, _size < s._size ? _size : s._size);
//			return ret == 0 ? (int)(_size < s._size) : ret < 0;
//		}
//
//		int operator>(const string& s) const						// ����>��������Ƚ������ַ����Ĵ�С
//		{
//			int ret = memcmp(_str, s._str, _size < s._size ? _size : s._size);
//			return ret == 0 ? (int)(_size > s._size) : ret > 0;
//		}
//
//		bool operator==(const string& s) const						// ����==��������Ƚ������ַ����Ƿ����
//		{
//			return _size == s._size && memcmp(_str, s._str, _size) == 0;
//		}
//
//		bool operator>= (const string& s) const						// ����>=��������Ƚ������ַ����Ĵ�С
//		{
//			return !(*this < s);
//		}
//
//		bool operator<= (const string& s) const						// ����<=��������Ƚ������ַ����Ĵ�С
//		{
//			return !(*this > s);
//		}
//
//		bool operator!=(const string& s) const						// ����!=��������Ƚ������ַ����Ƿ����
//		{
//			return !(*this == s);
//		}
//
//		string& operator=(const string& s)
//		{
//			if (this != &s)
//			{
//				delete[] _str;
//				_size = s._size;
//				_capacity = s._capacity;
//				_str = new char[_capacity + 1];
//				strcpy(_str, s._str);
//			}
//
//			return *this;
//		}
//
//
//	private:
//		char* _str;					// �洢�ַ���
//		size_t _size;				// ��¼��ǰ�ַ�������
//		size_t _capacity;			// ��¼��ǰ�ַ�������
//	};
//
//	// ��ͷ�ļ���ʹ�� inline ���庯����������ض���
//	inline ostream& operator<<(ostream& out, const string& s)
//	{
//		for (auto x : s)
//		{
//			out << x;
//		}
//		return out;
//	}
//
//	inline istream& operator>>(istream& in, string& s)
//	{
//		s.clear();
//
//		char ch = in.get();
//		// ����ǰ������ǰ��Ŀո���߻���
//		while (ch == ' ' || ch == '\n')
//		{
//			ch = in.get();
//		}
//
//		char buffer[128];
//		size_t i = 0;
//
//		while (ch != ' ' && ch != '\n' && ch != EOF)
//		{
//			buffer[i++] = ch;
//
//			if (i == 127)
//			{
//				buffer[i] = '\0';
//				s += buffer;
//				i = 0;
//			}
//
//			ch = in.get();
//		}
//
//		if (i != 0)
//		{
//			buffer[i] = '\0';
//			s += buffer;
//		}
//
//		return in;
//	}
//};
//
//// ��̬��Ա�����Ķ���
////const size_t string::npos = -1;