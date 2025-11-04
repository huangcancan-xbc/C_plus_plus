#include <iostream>
using namespace std;

class Base
{
public:    int pub;      // 公有
protected: int prot;     // 保护  
private:   int priv;     // 私有
};

class pub_Base : public Base
{
public:
    void test1()
    {
        pub = 10;    // 子类内部可以访问基类public
        prot = 20;   // 子类内部可以访问基类protected
        //priv = 30; // 不能访问基类private
    }

    void print()
    {
        cout << "pub: " << pub << endl;
        cout << "prot: " << prot << endl;
        //cout << "priv: " << priv << endl;
    }
};

class prot_Base : protected Base
{
public:
    void test2()
    {
        pub = 10;    // 子类内部可以访问基类public
        prot = 20;   // 子类内部可以访问基类protected
        //priv = 30; // 不能访问基类private
    }

    void print()
    {
        cout << "pub: " << pub << endl;
        cout << "prot: " << prot << endl;
        //cout << "priv: " << priv << endl;
    }
};

class priv_Base : private Base
{
public:
    void test3()
    {
        pub = 10;    // 子类内部可以访问基类public
        prot = 20;   // 子类内部可以访问基类protected
        //priv = 30; // 不能访问基类private
    }

    void print()
    {
        cout << "pub: " << pub << endl;
        cout << "prot: " << prot << endl;
        //cout << "priv: " << priv << endl;
    }
};

void test1()
{
    pub_Base pb;
    pb.test1();
    cout << pb.pub << endl;    // OK：public继承，pub仍然是public
    //cout << pb.prot << endl; // 错误：prot现在是protected
    //cout << pb.priv << endl; // 错误：priv现在是private
}

void test2()
{
    prot_Base pb;
    pb.test2();
    //cout << pb.pub << endl;   // 错误：protected继承，pub变成了protected
    //cout << pb.prot << endl;  // 错误：prot现在是protected
    //cout << pb.priv << endl;  // 错误：priv现在是private
}

void test3()
{
    priv_Base pb;
    pb.test3();
    //cout << pb.pub << endl;   // 错误：private继承，pub变成了private
    //cout << pb.prot << endl;  // 错误：prot现在是private
    //cout << pb.priv << endl;  // 错误：priv现在是private
}

int main()
{
    test1();  // 只有这个能正常运行
    //test2();  // 会报错
    //test3();  // 会报错
    return 0;
}