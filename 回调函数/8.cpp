#include <iostream>
#include <functional>
using namespace std;
//using namespace std::placeholders;

void show(int a, int b, int c)
{
    cout << a << " " << b << " " << c << endl;
}

// 
int main()
{
    auto f1 = bind(show, std::placeholders::_1, 20, 30);            // 绑定两个参数
    f1(10);                                                         // show(10,20,30)

    auto f2 = bind(show, placeholders::_2, placeholders::_1, 30);   // 绑定三个参数（注意这里的顺序！）
    // f2(10);  // 报错！
    f2(10, 20);                                                     // show(20,10,30)
    // 补充的顺序默认就是第一个，第二个，第三个...第一个参数会补充给placeholders::_1，第二个参数会补充给placeholders::_2，以此类推

    auto f3 = bind(show, 10, 20, 30);       // 没有占位符
    f3();                                   // show(10,20,30)
}