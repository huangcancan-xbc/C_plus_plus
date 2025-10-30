#include "MyString.h"
#include <iostream>
using namespace std;
using namespace minbit;

void test()
{
    minbit::string s1("Hello,world!");
    cout << s1.c_str() << endl;
    cout << s1.length() << endl;
    cout << s1.size() << endl;

    for (int i = 0; i < s1.size(); i++)
    {
        cout << s1[i];
    }

    for (minbit::string::const_iterator it = s1.begin(); it != s1.end(); ++it)
    {
        cout << *it;
    }

    // 这里并没有手动实现范围for，但是运行没有任何问题，原因是它天然支持迭代器的行为
    // 实现了 begin() 和 end()，返回的 char* 天然支持迭代操作，范围 for 本质就是基于这两个函数实现的。
    // 注意：需要严格遵循 begin 和 end 的返回值类型和小写的写法，底层其实就是"傻瓜式的替换"
    for (auto c : s1)
    {
        cout << c;
    }

    for (minbit::string::iterator it = s1.begin(); it != s1.end(); ++it)
    {
        *it += 2;
        cout << *it;
    }

    cout << endl;
    minbit::string s2("123321");
    s2.push_back('s');
    s2.append("你好");
    s2 += "世界";
    s2.insert(2, 4, 'x');
    cout << s2.c_str() << "  " << s2.length() << "  " << s2.size() << endl;

    cout << endl << endl;
}


// 测试 1: 默认构造、拷贝构造、析构（基本功能）
void test1_basic()
{
    minbit::string s1;              // 默认构造 ""
    minbit::string s2("hello");     // 构造 "hello"
    minbit::string s3 = s2;         // 拷贝构造

    cout << "s1: \"" << s1 << "\"" << endl;
    cout << "s2: \"" << s2 << "\"" << endl;
    cout << "s3: \"" << s3 << "\"" << endl;

    s1 = "world";
    cout << "赋值后 s1: \"" << s1 << "\"" << endl;

    cout << endl << endl;
}

// 测试 2: operator[], at, size
void test2_indexing()
{
    minbit::string s("abc");
    cout << "s[0] = " << s[0] << endl;
    s[0] = 'X';
    cout << "修改后: " << s << endl;

    // 尝试越界（应 assert 失败）
    // s[10] = 'x';  // 取消注释会 crash（符合预期）

    cout << endl << endl;
}

// 测试 3: push_back, +=, append
void test3_append()
{
    minbit::string s;
    s.push_back('a');
    s += 'b';
    s += "cd";
    s.append("efg");
    cout << "结果: " << s << " (长度=" << s.size() << ")" << endl;

    cout << endl << endl;
}

// 测试 4: substr
void test4_substr()
{
    minbit::string s("hello world");
    minbit::string sub1 = s.substr(0, 5);
    minbit::string sub2 = s.substr(6);

    cout << "子串1: \"" << sub1 << "\"" << endl;
    cout << "子串2: \"" << sub2 << "\"" << endl;

    cout << endl << endl;
}

// 测试 5: 比较运算符
void test5_comparison()
{
    minbit::string s1("abc");
    minbit::string s2("abcd");
    minbit::string s3("abx");

    cout << "s1 < s2: " << (s1 < s2) << " (应为 1)" << endl; // 应为 true
    cout << "s1 < s3: " << (s1 < s3) << " (应为 1)" << endl; // 应为 true
    cout << "s1 == s1: " << (s1 == s1) << " (应为 1)" << endl;

    cout << endl << endl;
}

// 测试 6: find
void test6_find()
{
    minbit::string s("hello world");
    size_t pos1 = s.find('o');
    size_t pos2 = s.find("world");
    size_t pos3 = s.find('z');

    cout << "查找 'o': " << pos1 << endl;        // 应为 4
    cout << "查找 \"world\": " << pos2 << endl;  // 应为 6
    cout << "查找 'z': " << pos3 << endl;        // 应为 npos，但是由于 size_t 类型会显示一个很大的数字，原理是对的，但是预期输出存在一点问题
    cout << "查找 'z': " << (pos3 == minbit::string::npos ? -1 : (int)pos3) << endl;        // 使用这样的输出就会正确显示为 -1 了

    cout << endl << endl;
}

// 测试 7: insert / erase
void test7_insert_erase()
{
    minbit::string s("abc");
    s.insert(1, 2, 'x'); // 应为 "axxbc"
    cout << "插入后: " << s << endl;

    s.erase(1, 2); // 删除 "xx" → "abc"
    cout << "删除后: " << s << endl;

    cout << endl << endl;
}

// 测试 8: 空字符串和边界
void test8_edge_cases()
{
    minbit::string empty;
    cout << "空字符串: \"" << empty << "\"" << endl;
    cout << "长度: " << empty.size() << ", 容量: " << empty.capacity() << endl;

    cout << endl << endl;
}

// 测试 9: operator>> 输入
void test9_input()
{
    minbit::string s;
    cout << "请输入一个单词: ";
    cin >> s;  // 输入 "test"
    cout << "你输入的是: \"" << s << "\"" << endl;

    cout << endl << endl;
}

int main()
{
    test();
    test1_basic();
    test2_indexing();
    test3_append();
    test4_substr();
    test5_comparison();
    test6_find();
    test7_insert_erase();
    test8_edge_cases();
    //test9_input();
    return 0;
}