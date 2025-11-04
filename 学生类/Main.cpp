#include "Student.hpp"

void test1()
{
    // 创建默认学生对象
    Student s1; // 默认值：姓名未知，年龄0，ID 0，性别未知
    cout << "默认学生信息：";
    s1.print();
}

void test2()
{
    // 创建指定信息的学生对象
    Student s2("张三", 20, 1001, "男"), s1;
    cout << "指定信息学生：";
    s2.print();

    // 使用赋值操作符复制信息
    s1 = s2; // s1的所有信息变为和s2一样
    cout << "赋值后s1信息：";
    s1.print();

    // 使用字符串赋值修改姓名
    s1 = "李四"; // 只修改姓名
    cout << "修改姓名后：";
    s1.print();

    // 使用整数赋值修改年龄
    s1 = 22; // 只修改年龄
    cout << "修改年龄后：";
    s1.print();

    // 使用长整数赋值修改ID
    s1 = 1002L; // 只修改ID
    cout << "修改ID后：";
    s1.print();

    // 使用字符串赋值修改性别
    //s1 = "女"; // 只修改性别
    //cout << "修改性别后：";
    //s1.print();

    // 使用设置函数修改单个属性
    s1.setName("王五");
    s1.setAge(25);
    s1.setId(1003);
    s1.setGender("男");
    cout << "使用设置函数修改后：";
    s1.print();

    // 比较两个学生
    if (s1 != s2)
    {
        cout << "s1和s2不相同" << endl;
    }

    // 检查学生有效性
    if (s1.isValid())
    {
        cout << "s1是有效学生" << endl;
    }

    // 比较年龄
    if (s1.isOlderThan(s2))
    {
        cout << "s1比s2年龄大" << endl;
    }

    // 增加年龄
    s2.addAge(1);
    cout << "s2增加1岁后：";
    s2.print();

    // 显示基本信息
    s1.showBasicInfo();
}

int main()
{
    test1();
    test2();


    return 0;
}