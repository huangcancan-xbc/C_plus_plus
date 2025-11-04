class Base
{
public:
    void publicFunc() {}      // 公有成员
protected:
    void protectedFunc() {}   // 保护成员  
private:
    void privateFunc() {}     // 私有成员 - 子类也无法访问
};

class Derived : public Base   // 公有继承
{
    // publicFunc() -> 仍然是 public
    // protectedFunc() -> 仍然是 protected
    // privateFunc() -> 无法访问（原本就无法访问）
};

class Derived2 : private Base // 私有继承
{
    // publicFunc() -> 变成 private
    // protectedFunc() -> 变成 private  
    // privateFunc() -> 无法访问
};