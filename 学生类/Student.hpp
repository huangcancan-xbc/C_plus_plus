#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student
{
public:
    // 默认构造函数：创建一个默认的学生对象
    Student() : _name("未知"), _age(0), _id(0), _gender("未知")
    {
    }

    // 带参数的构造函数：创建指定信息的学生对象
    Student(const string& n, int a, int i, const string& g)
        : _name(n), _age(a), _id(i), _gender(g)
    {
    }

    // 拷贝构造函数：用一个已有的学生对象创建新的学生对象
    Student(const Student& other)
        : _name(other._name), _age(other._age), _id(other._id), _gender(other._gender)
    {
    }

    // 赋值操作符重载：支持用=直接修改信息，如：a是张三，b是李四，a=b会将a的所有信息改为b的信息
    Student& operator=(const Student& other)
    {
        if (this != &other) // 防止自己赋值给自己
        {
            _name = other._name;
            _age = other._age;
            _id = other._id;
            _gender = other._gender;
        }
        return *this; // 返回当前对象的引用，支持链式赋值
    }

    // 字符串赋值操作符：支持用字符串直接修改姓名，如：a="王五"，会将a的姓名改为王五
    void operator=(const string& newName)
    {
        _name = newName;
    }

    // 整数赋值操作符：支持用整数直接修改年龄，如：a=20，会将a的年龄改为20
    void operator=(int newAge)
    {
        _age = newAge;
    }

    // 长整数赋值操作符：支持用长整数直接修改ID，如：a=1001L，会将a的ID改为1001
    void operator=(long newId)
    {
        _id = newId;
    }

    // 字符串赋值操作符（性别）：支持用字符串直接修改性别，如：a="女"，会将a的性别改为女
    //Student& operator=(const char* newGender)
    //{
    //    _gender = newGender;
    //    return *this;
    //}

    // 相等比较操作符：支持用==比较两个学生是否完全相同
    bool operator==(const Student& other) const
    {
        return (_name == other._name && _age == other._age &&
            _id == other._id && _gender == other._gender);
    }

    // 不等比较操作符：支持用!=比较两个学生是否不相同
    bool operator!=(const Student& other) const
    {
        return !(*this == other);
    }

    // 设置姓名：将学生姓名修改为指定值
    void setName(const string& n)
    {
        _name = n;
    }

    // 设置年龄：将学生年龄修改为指定值
    void setAge(int a)
    {
        _age = a;
    }

    // 设置ID：将学生ID修改为指定值
    void setId(int i)
    {
        _id = i;
    }

    // 设置性别：将学生性别修改为指定值
    void setGender(const string& g)
    {
        _gender = g;
    }

    // 获取姓名：返回学生的姓名
    string getName() const
    {
        return _name;
    }

    // 获取年龄：返回学生的年龄
    int getAge() const
    {
        return _age;
    }

    // 获取ID：返回学生的ID
    int getId() const
    {
        return _id;
    }

    // 获取性别：返回学生的性别
    string getGender() const
    {
        return _gender;
    }

    // 打印学生信息：在屏幕上显示学生的完整信息
    void print() const
    {
        cout << "姓名：" << _name << ", 年龄：" << _age
            << ", ID：" << _id << ", 性别：" << _gender << endl;
    }

    // 检查学生是否有效：年龄在合理范围内且ID大于0
    bool isValid() const
    {
        return _age > 0 && _age < 100 && _id > 0;
    }

    // 更新学生信息：一次性修改所有信息
    void updateInfo(const string& n, int a, int i, const string& g)
    {
        _name = n;
        _age = a;
        _id = i;
        _gender = g;
    }

    // 比较年龄：判断当前学生是否比另一个学生年龄大
    bool isOlderThan(const Student& other) const
    {
        return _age > other._age;
    }

    // 比较ID：判断当前学生ID是否比另一个学生ID大
    bool hasHigherId(const Student& other) const
    {
        return _id > other._id;
    }

    // 增加年龄：将学生年龄增加指定数值
    void addAge(int years)
    {
        _age += years;
    }

    // 显示基本信息：只显示姓名和ID
    void showBasicInfo() const
    {
        cout << "学生：" << _name << " (ID: " << _id << ")" << endl;
    }

private:
    string _name;   // 学生姓名
    int _age;       // 学生年龄
    int _id;        // 学生ID
    string _gender; // 学生性别
};