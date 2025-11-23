#include <iostream>
using namespace std;

class Base
{
public:
    virtual void speak()          // 虚函数：允许被重写
    {
        cout << "Base 说话\n";
    }

    virtual ~Base() {}            // 虚析构，防止内存泄漏
};

class Derived : public Base
{
public:
    void speak() override         // 重写父类函数
    {
        cout << "Derived 说话\n";
    }
};

int main()
{
    Base* p = new Derived();      // 父类指针指向子类对象
    p->speak();                   // 输出：Derived 说话（多态效果）

    Derived d;
    d.Base::speak();              // 指定调用父类版本

    delete p;                     // 析构安全（因为虚析构）
    return 0;
}