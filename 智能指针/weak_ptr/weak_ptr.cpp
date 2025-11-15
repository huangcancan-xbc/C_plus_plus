#include <iostream>
#include <memory>
#include <string>
#include "test.hpp"
using namespace std;

// 关于weak_ptr的常用方法：
// weak_ptr是弱引用，而shared_ptr是强引用，weak_ptr的使用需要结合shared_ptr一起使用。
// 
// lock：尝试从一个弱引用中获取强引用（而非 “添加弱引用”），如果对象存在可以创建强引用会返回一个非空的shared_ptr（引用计数+1），否则返回nullptr的shared_ptr。
// use_count()：获取关联shared_ptr的引用计数（不增加计数）
// expired：判断weak_ptr是否已经失效，如果失效则返回true，否则返回false。
// reset：让 weak_ptr 本身放弃对对象的弱引用，置为 "空状态"（指向 nullptr），不会减少强引用计数。
// 若shared_ptr计数归 0，对象会被释放。此时，所有关联的弱引用都会变成 “空引用”（但弱引用本身仍存在，只是指向的对象没了）。

// 测试weak_ptr的基本使用：安全访问对象
void test1()
{
    auto p1 = make_shared<int>(10); // 创建int对象，p1是强引用，计数=1
    weak_ptr<int> wp(p1);           // wp是弱引用，指向p1管理的对象，但不增加引用计数

    cout << "此时强引用计数：" << p1.use_count() << endl; // 输出1，因为只有p1一个强引用

    // 从弱引用获取强引用（安全访问对象）
    if (auto temp = wp.lock())      // temp 是通过lock()获取的强引用，如果对象存在则引用计数变为2
    {
        *temp = 20;                 // 安全修改对象的值
        cout << "此时强引用计数：" << p1.use_count() << endl; // 输出2，因为现在有p1和temp两个强引用

    } // temp 在这里销毁，引用计数减1，变回1

    cout << "此时强引用计数：" << p1.use_count() << endl; // 输出1，temp已销毁
}

// 测试weak_ptr失效的情况
void test2()
{
    auto p1 = make_shared<int>(10); // 强引用 p1，引用计数=1
    weak_ptr<int> wp1(p1);          // 弱引用 wp1，指向p1管理的对象
    weak_ptr<int> wp2(p1);          // 弱引用 wp2，也指向p1管理的对象

    p1.reset(); // p1 放弃所有权，引用计数减1变为0 → 对象被释放

    // 此时所有关联的弱引用都失效（因为它们指向的对象已被销毁）
    if (wp1.lock() == nullptr)      // 尝试从wp1获取强引用，应该失败
    {
        cout << "wp1 失效" << endl; // 输出：wp1 失效
    }

    if (wp2.lock() == nullptr)      // 尝试从wp2获取强引用，应该失败
    {
        cout << "wp2 失效" << endl; // 输出：wp2 失效
    }
}

// 测试weak_ptr的基本操作和状态检查
void test3()
{
    // 创建两个Node对象的shared_ptr
    shared_ptr<Node> p1 = make_shared<Node>(10);  // p1管理值为10的Node对象
    shared_ptr<Node> p2 = make_shared<Node>(20);  // p2管理值为20的Node对象

    cout << "p1的引用计数：" << p1.use_count() << endl;  // 输出1，只有p1指向该对象
    cout << "p2的引用计数：" << p2.use_count() << endl;  // 输出1，只有p2指向该对象

    // 创建weak_ptr指向p1管理的对象
    weak_ptr<Node> wp1 = p1;  // wp1是弱引用，指向p1的对象，但不增加p1的引用计数
    cout << "p1的引用计数：" << p1.use_count() << endl;  // 仍然输出1，因为wp1是弱引用不影响计数

    // 检查weak_ptr是否还有效（对象是否还存在）
    if (!wp1.expired())  // expired()返回true表示对象已被销毁，false表示对象还存在
    {
        cout << "wp1指向的对象仍然有效" << endl;  // 因为对象存在，所以输出这行
    }

    // 使用lock()方法安全获取shared_ptr（尝试从弱引用创建强引用）
    // 注意：wp1的类型始终是weak_ptr，创建新的强引用要赋给一个shared_ptr对象！
    // weak_ptr也不能直接解引用访问对象，必须通过lock()生成一个shared_ptr来操作。
    shared_ptr<Node> temp = wp1.lock();  // 如果对象存在，lock()返回有效的shared_ptr；否则返回nullptr
    if (temp)  // 检查temp是否有效（不是nullptr）
    {
        cout << "通过lock()获取成功，对象值：" << temp->value << endl;  // 输出对象的值10
    }

    // 重置p1，释放p1管理的对象（引用计数变为0，对象被销毁）
    p1.reset();
    cout << "p1重置后，wp1是否过期：" << wp1.expired() << endl;  // 输出1（true），因为对象已被销毁

    // 尝试lock()，此时会返回nullptr（因为对象已被销毁）
    shared_ptr<Node> temp2 = wp1.lock();  // 尝试获取强引用，但对象已不存在
    if (!temp2)  // 检查temp2是否为空（nullptr）
    {
        cout << "wp1已过期，lock()返回nullptr" << endl;  // 因为对象不存在，所以输出这行
    }
}

// 测试weak_ptr解决循环引用问题
void test4()
{
    // 创建两个Node对象
    shared_ptr<Node> node1 = make_shared<Node>(1);  // node1指向值为1的Node对象
    shared_ptr<Node> node2 = make_shared<Node>(2);  // node2指向值为2的Node对象

    // 创建循环引用：node1->next指向node2，node2->parent指向node1
    node1->next = node2;           // node1的next成员是shared_ptr，指向node2，所以node2的引用计数变为2
    node2->parent = node1;         // node2的parent成员是weak_ptr，指向node1，不增加node1的引用计数

    cout << "node1引用计数：" << node1.use_count() << endl;  // 输出1，因为只有node1本身和node2->parent（弱引用）指向它
    cout << "node2引用计数：" << node2.use_count() << endl;  // 输出2，因为node1->next和node2本身都指向它

    // 检查node2的父节点（安全地从弱引用获取强引用）
    shared_ptr<Node> parent = node2->parent.lock();  // 尝试从node2->parent获取强引用
    if (parent)  // 检查是否获取成功
    {
        cout << "node2的父节点值：" << parent->value << endl;  // 输出1，因为node2的父节点是node1
    }

    // 重置node1，由于node2的parent是weak_ptr（不是强引用），不会阻止node1被销毁
    node1.reset();  // 释放node1，node1对象被销毁
    cout << "重置node1后，node2的parent是否过期：" << node2->parent.expired() << endl;  // 输出1（true），因为node1已销毁

    cout << "函数结束，局部变量将被销毁" << endl;  // 函数结束后node2析构，weak_ptr自动失效，所有对象安全释放
}

int main()
{
    test1();
    test2();
    test3();
    test4();

    return 0;
}