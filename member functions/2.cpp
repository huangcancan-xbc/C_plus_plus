#include "1.h"

// 1. 调用无参构造函数
void test1()
{
    Member_functions obj1;                           // 显式调用无参构造
    Member_functions obj2 = Member_functions();      // C++11/14：构造 + 拷贝构造

    // C++17 起：拷贝省略，只调用无参构造

    Member_functions obj3{};                         // C++11 起统一初始化，调用无参构造
    Member_functions obj4 = Member_functions{};      // 同上，C++17 起强制省略拷贝
}


// 2. 调用有参构造函数
void test2()
{
    Member_functions obj1(10);                       // 有参构造
    Member_functions obj2 = Member_functions(20);    // C++11/14：有参构造 + 拷贝/移动构造

    // C++17 起：强制拷贝省略，只调用有参构造

    Member_functions obj3{ 30 };                     // C++11 起统一初始化，有参构造
    Member_functions obj4 = Member_functions{ 40 };  // 同上，C++17 起强制省略拷贝
}


// 3. 调用拷贝构造函数
void test3()
{
    Member_functions obj1(10);                       // 有参构造
    Member_functions obj2(obj1);                     // 拷贝构造（obj1 是左值）

    Member_functions obj3 = obj1;                    // 拷贝构造（拷贝初始化）

    Member_functions obj4{ obj1 };                   // C++11 起统一初始化，拷贝构造
    Member_functions obj5 = { obj1 };                // 同上，拷贝构造

    Member_functions obj6 = obj2;                    // 拷贝构造（注意：obj2 仍然是左值）
}


// 4. 调用移动构造函数
void test4()
{
    // C++17 起：拷贝省略（RVO），只调用有参构造
    Member_functions obj1 = Member_functions(300);   // C++11/14：有参构造 + 移动构造
    Member_functions obj2(Member_functions(400));    // 同上（区别只在语法形式）


    // 如果类里没写移动构造 → 会退化成拷贝构造
    Member_functions obj3(500);                      // 有参构造
    Member_functions obj4 = std::move(obj3);         // 显式调用移动构造
    
    Member_functions obj5(std::move(obj3));          // 同上
    //能放在等号左边的是左值，不能的是右值
    //左值：有名字 / 能取地址 / 能复用。
    //右值：临时 / 没名字 / 用完就丢
    //意义：区分左右值后，C++ 可以对右值“偷资源”而不是复制，从而优化性能。
    //std::move：把左值伪装成右值，强行触发“移动”版本。
}


// 5. 调用转换构造函数
void test5()
{
    Member_functions obj1(15.7);                     // 显式调用转换构造（double -> int）
    Member_functions obj2 = Member_functions(25.8);  // 显式调用转换构造
    Member_functions obj3{ 35.9 };                     // 显式调用转换构造（统一初始化）
    Member_functions obj4 = Member_functions{ 45.6 };  // 显式调用转换构造

    // 注意：因为 explicit，不能写 Member_functions obj5 = 55.5;
}