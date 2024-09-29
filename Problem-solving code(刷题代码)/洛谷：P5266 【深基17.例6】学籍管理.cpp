#include <iostream>
#include <string>
//洛谷：P5266 【深基17.例6】学籍管理
//https://www.luogu.com.cn/problem/P5266

#include <iostream>
#include <map>
using namespace std;

int main()
{
    // 创建一个map，键为string类型，值为long long类型
    map<string, long long> mp;
    string name; // 存储姓名
    int n = 0;   // 输入的操作次数
    cin >> n;    // 读取操作次数
    int ans = 0; // 用户操作类型
    long long score = 0; // 存储分数

    while (n--) // 根据操作次数进行循环
    {
        cin >> ans; // 读取用户操作类型
        if (ans == 1) // 如果操作类型是1，表示添加记录
        {
            cin >> name >> score; // 读取姓名和分数
            mp[name] = score; // 在map中插入或更新记录

            cout << "OK" << endl; // 输出操作成功
        }
        else if (ans == 2) // 如果操作类型是2，表示查询分数
        {
            cin >> name; // 读取姓名
            if (mp.find(name) == mp.end()) // 如果姓名不存在
            {
                cout << "Not found" << endl; // 输出未找到
            }
            else
            {
                cout << mp[name] << endl; // 输出分数
            }
        }
        else if (ans == 3) // 如果操作类型是3，表示删除记录
        {
            cin >> name; // 读取姓名
            if (mp.find(name) == mp.end()) // 如果姓名不存在
            {
                cout << "Not found" << endl; // 输出未找到
            }
            else
            {
                mp.erase(name); // 删除记录
                cout << "Deleted successfully" << endl; // 输出删除成功
            }
        }
        else if (ans == 4) // 如果操作类型是4，表示查询记录数
        {
            cout << mp.size() << endl; // 输出map中元素的数量
        }
    }

    return 0; // 程序结束
}




#include <iostream>
#include <map>
using namespace std;

int main() {
    // 创建一个map，键为string类型，值为int类型
    map<string, int> mp;
    string name; // 存储姓名
    int n = 0;   // 输入的操作次数
    cin >> n;    // 读取操作次数
    int ans = 0; // 用户操作类型
    int score = 0; // 存储分数

    while (n--) { // 根据操作次数进行循环
        cin >> ans; // 读取用户操作类型
        if (ans == 1) { // 如果操作类型是1，表示添加记录
            cin >> name >> score; // 读取姓名和分数
            mp[name] = score; // 在map中插入或更新记录

            cout << "OK" << endl; // 输出操作成功
        }
        else if (ans == 2) { // 如果操作类型是2，表示查询分数
            cin >> name; // 读取姓名
            if (mp.find(name) == mp.end()) { // 如果姓名不存在
                cout << "Not found" << endl; // 输出未找到
            }
            else {
                cout << mp[name] << endl; // 输出分数
            }
        }
        else if (ans == 3) { // 如果操作类型是3，表示删除记录
            cin >> name; // 读取姓名
            if (mp.find(name) == mp.end()) { // 如果姓名不存在
                cout << "Not found" << endl; // 输出未找到
            }
            else {
                mp.erase(name); // 删除记录
                cout << "Deleted successfully" << endl; // 输出删除成功
            }
        }
        else if (ans == 4) { // 如果操作类型是4，表示查询记录数
            cout << mp.size() << endl; // 输出map中元素的数量
        }
    }

    return 0; // 程序结束
}
