// 示例1：
#include <iostream>
#include <functional>
using namespace std;

void print(int x)
{
    cout << "普通函数: " << x << endl;
}

void test(int n, function<void(int)> cb)
{
    for (int i = 0; i < n; ++i)
    {
        cb(i);
    }
}

int main()
{
    test(3, print);   // 直接传函数名
}




// 示例2：
#include <iostream>
#include <functional>
using namespace std;
// 语法格式：using 别名 = std::function<返回值类型(参数类型...)>;
using func_t = function<void(int)>;

void test(int n, func_t cb)
{
    for (int i = 0; i < n; ++i)
    {
        cb(i);   // 调用回调函数，这个 i 会传递给 lambda 表达式，即下面的 int x 部分
    }
}

int main()
{
    // 理解：将 lambda 表达式作为参数传递给 test 函数，test 函数将 lambda 表达式作为回调函数调用。
    // 可以理解为：这里的 lambda 表达式就是回调函数。
    // lambda 表达式拿到上面传过来的 i 值，然后输出。
    test(3, [](int x) {
        cout << "Lambda 回调: " << x << endl;
        });
}




// 示例3：
// std::function 的本质是一个 “函数包装器”，可以存储任何可调用对象（函数、lambda、函数对象等）。
// 它内部会管理这些可调用对象的拷贝或引用，就像一个 “函数指针的升级版”，但更灵活。
#include <functional>
#include <iostream>
using namespace std;
using Callback = function<void(int)>;

class Server
{
    // 注意：_onMessage 就像一个 “函数容器”（本身是 std::function 类型，专门用来存放函数），初始时这个容器是空的。
    // 可以理解成 _onMessage 是一个回调函数类型，初始是空的，不包含任何逻辑
    Callback _onMessage;
public:
    void set(Callback cb)
    {
        _onMessage = cb;    // 这里就会将 lambda 表达式（的逻辑）拷贝给 _onMessage，从而拥有和下面lambda一样的效果
    }

    void simulateMessage(int data)
    {
        if (_onMessage)     // 初始_onMessage是空的，所以这里不会执行，后续拥有lambda一样的逻辑效果才会进入
        {
            _onMessage(data);   // 走到这里才会将传进来的42导向回调逻辑，即_onMessage（lambda的逻辑）
        }
    }
};

int main()
{
    Server s;

    // 注册回调
    // lambda[](int x) { ... } 本质上是一个 “匿名函数”，它有明确的参数（int x）和返回值（void），
    // 正好匹配 Callback 类型（function<void(int)>）。
    // set 方法调用时，这个 lambda 会被拷贝到 _onMessage 中（std::function 会负责存储这个拷贝）。
    s.set([](int x) {
        cout << "收到消息：" << x << endl;
        });

    // 模拟事件触发
    s.simulateMessage(42);  // 当把42传给 _onMessage 时，_onMessage拥有和lambda一样的效果
}