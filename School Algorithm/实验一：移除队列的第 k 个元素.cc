#include <iostream>
#include <queue>
using namespace std;

bool slove(queue<int>& qu, int k)
{
    if (k <= 0 || k > qu.size())
    {
        cout << "无效的k值（k必须在1到队列长度之间）" << endl;
        return false;
    }

    queue<int> tmpqu;
    for (int i = 1; i < k; ++i)
    {
        tmpqu.push(qu.front());
        qu.pop();
    }

    int removed = qu.front();
    qu.pop();

    while (!qu.empty())
    {
        tmpqu.push(qu.front());
        qu.pop();
    }

    while (!tmpqu.empty())
    {
        qu.push(tmpqu.front());
        tmpqu.pop();
    }

    cout << "成功移除第" << k << "个元素: " << removed << endl;
    return true;
}

void print(const queue<int>& qu)
{
    queue<int> tmp = qu;
    cout << "队列元素（队头->队尾）：";
    while (!tmp.empty())
    {
        cout << tmp.front() << " ";
        tmp.pop();
    }
    cout << endl;
}

int main()
{
    queue<int> qu;
    for (int i = 1; i <= 5; ++i)
    {
        qu.push(i);
    }

    cout << "初始状态：";
    print(qu);

    int k;
    cout << "请输入要移除的元素位置k：";
    cin >> k;
    slove(qu, k);

    cout << "移除第" << k << "个元素后：";
    print(qu);

    return 0;
}