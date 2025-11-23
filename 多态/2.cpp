#include <iostream>
using namespace std;

class Shape
{
public:
    virtual void draw() = 0;  // 纯虚函数，子类必须实现
    virtual ~Shape() {}
};

class Circle : public Shape
{
public:
    void draw() override { cout << "画圆\n"; }
};

class Rectangle : public Shape
{
public:
    void draw() override { cout << "画矩形\n"; }
};

void render(Shape* s)       // 这里传父类指针
{
    s->draw();              // 多态调用
}


int main()
{
    Circle c; 
    Rectangle r;
    render(&c);  // 输出：画圆
    render(&r);  // 输出：画矩形
}