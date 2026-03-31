#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

class Fraction
{
public:
    Fraction(int up = 0, int down = 1)
        : numerator(up),
        denominator(down)
    {
        if (down == 0)
        {
            cout << "分数的分母不能为0！" << endl;
            denominator = 1;
        }

        reduce();   // 约分
    }

    // 加法
    Fraction operator+(const Fraction& other) const
    {
        // 返回一个新的 Fraction 实例会触发 Fraction 的构造函数即自动约分
        return Fraction(numerator * other.denominator + other.numerator * denominator,
            denominator * other.denominator);
    }

    // 减法
    Fraction operator-(const Fraction& other) const
    {
        return Fraction(numerator * other.denominator - other.numerator * denominator,
            denominator * other.denominator);
    }

    // 乘法
    Fraction operator*(const Fraction& other) const
    {
        return Fraction(numerator * other.numerator,
            denominator * other.denominator);
    }

    // 除法
    Fraction operator/(const Fraction& other) const
    {
        return Fraction(numerator * other.denominator,
            denominator * other.numerator);
    }

    // 判断是否相等
    bool operator==(const Fraction& other) const
    {
        return (numerator == other.numerator &&
            denominator == other.denominator);
    }

    // 判断是否不等
    bool operator!=(const Fraction& other) const
    {
        return (numerator != other.numerator ||
            denominator != other.denominator);
    }

    // 判断是否小于
    bool operator<(const Fraction& other) const
    {
        return (numerator * other.denominator < other.numerator * denominator);
    }

    // 重载输出运算符
    friend ostream& operator<<(ostream& os, const Fraction& f)
    {
        os << f.numerator;          // 先输出分子
        if (f.denominator != 1)     // 分母为1时，仅输出分子（如 2/1 → 2）
        {
            os << "/" << f.denominator;
        }

        return os;
    }

private:
    // 约分
    void reduce()
    {
        if (denominator < 0)
        {
            numerator = -numerator;
            denominator = -denominator;
        }

        int g = gcd(abs(numerator), denominator);
        numerator /= g;
        denominator /= g;
    }

    int numerator;      // 分子
    int denominator;    // 分母
};



int main()
{
    Fraction f1(1, 2);
    Fraction f2(1, 3);


    cout << f1 << " + " << f2 << " = " << (f1 + f2) << endl;
    cout << f1 << " - " << f2 << " = " << (f1 - f2) << endl;
    cout << f1 << " * " << f2 << " = " << (f1 * f2) << endl;
    cout << f1 << " / " << f2 << " = " << (f1 / f2) << endl;


    if (f1 < f2)
    {
        cout << f1 << " < " << f2 << endl;
    }
    if (f1 == f2)
    {
        cout << f1 << " == " << f2 << endl;
    }
    if (f1 != f2)
    {
        cout << f1 << " != " << f2 << endl;
    }



    return 0;
}