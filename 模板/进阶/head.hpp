#pragma once
#include <iostream>
#include <string>
#include <cstring>
using namespace std;


// 非类型模板参数
// 模板参数：类型 T + 非类型参数 N (必须是编译期常量整型)
//将值（而不是类型）作为模板参数传入。这个值在编译时必须是常量表达式
//它必须是整型家族（包括 bool, char, int, size_t 等）或指向对象/函数的指针/引用，不能是 float, double, std::string 等。
//template <class T, double N>// 错误！double不是整型家族
//template <typename T, int N>
template <class T, size_t N> // 使用 size_t 更常见，因为它用于表示大小
class t1
{
public:
    t1() = default; // 默认构造函数

    void fill(T val);
    void print() const;
    size_t size() const; // 返回数组大小

private:
    T data[N]; // 数组大小由模板参数 N 在编译时决定
};



// 定义 t1 的成员函数 (类外定义，必须在头文件中)
template <class T, size_t N>
void t1<T, N>::fill(T val)
{
    for (size_t i = 0; i < N; ++i)
    {
        data[i] = val;
    }
}

template <class T, size_t N>
void t1<T, N>::print() const
{
    for (size_t i = 0; i < N; ++i)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}

template <class T, size_t N>
size_t t1<T, N>::size() const
{
    return N;
}



//类模板特化:
//全特化:完全指定所有模板参数。
//偏特化:只指定部分参数，或对参数加限制。理解偏特化有助于理解一些高级库的实现。
//注意: 特化必须和原始模板在同一个命名空间。特化不是重载，它是在模板匹配后，选择最特化的实现。


//// 通用模板
//template <typename T>
//void print(T val)
//{
//    cout << "通用版本: " << val << endl;
//}
//
//// 特化版本（string类型）
//template <>
//inline void print<string>(string val)
//{
//    cout << "特化版本: " << val << endl;
//}


// 通用模板：比较两个相同类型的值是否相等
template <typename T>
bool t2(const T& x, const T& y)
{
    cout << "通用 t2 版本: ";
    return x == y;
}

// 函数模板全特化：针对 char* 类型进行特殊处理
// 注意：全特化时，template<> 后面的尖括号为空，函数名后跟具体类型
template <>
inline bool t2<string>(const string& x, const string& y) // 使用 const& 避免不必要的复制
{
    cout << "特化 t2 版本 (string): ";
    return strcmp(x.c_str(), y.c_str()) == 0;
}

// 也可以直接定义一个普通函数，它会优先于模板实例化被调用
// bool t2(char* x, char* y) { ... } 也是可以的，效果类似。


// 类模板特化
// 通用类模板
template <class T1, class T2>
class t3
{
public:
    t3(const T1& a, const T2& b)
        : first(a), second(b)
    {
        cout << "通用 t3<T1, T2> 构造函数被调用。" << endl;
    }

    void print() const
    {
        cout << "通用 t3: (" << first << ", " << second << ")" << endl;
    }

private:
    T1 first;
    T2 second;
};

// 类模板全特化：完全指定所有模板参数 (T1=int, T2=double)
template <>
class t3<int, double>
{
public:
    t3(const int& a, const double& b)
        : first(a), second(b)
    {
        cout << "全特化 t3<int, double> 构造函数被调用。" << endl;
    }

    void print() const
    {
        cout << "全特化 t3: (" << first << ", " << second << ") [类型已固定]" << endl;
    }

private:
    int first;
    double second;
};

// 类模板偏特化：部分指定参数，或对参数加限制 (这里偏特化为指针类型)
template <class T1, class T2>
class t3<T1*, T2*>
{
public:
    t3(T1* a, T2* b) : first(a), second(b)
    {
        cout << "偏特化 t3<T1*, T2*> 构造函数被调用。" << endl;
    }

    void print() const
    {
        cout << "偏特化 t3 (指针): (" << *first << ", " << *second << ") [解引用打印]" << endl;
    }

private:
    T1* first;
    T2* second;
};

// 类模板偏特化：进一步限制参数 (这里偏特化为相同类型)
template <class T>
class t3<T, T>
{
public:
    t3(const T& a, const T& b) : first(a), second(b)
    {
        cout << "偏特化 t3<T, T> 构造函数被调用。" << endl;
    }

    void print() const
    {
        cout << "偏特化 t3<T, T>: (" << first << ", " << second << ") [相同类型]" << endl;
    }

private:
    T first;
    T second;
};