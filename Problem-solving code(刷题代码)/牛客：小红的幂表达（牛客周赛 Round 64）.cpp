//牛客：小红的幂表达（牛客周赛 Round 64）
//https://ac.nowcoder.com/acm/contest/92662/B

#include <iostream> 
#include <cmath> 
using namespace std;

int main()
{
    int x;                                                      // 声明整数 x 用于存储输入值
    cin >> x;                                                   // 从标准输入读取整数 x
    cout << x << endl << "=" << x << "^1" << endl;              // 输出 x 及其自身的 1 次幂

    // 从 x 的平方根开始向下遍历，寻找可能的底数 a
    for (int a = (int)sqrt(x); a >= 2; --a)
    {
        int temp = a;                                           // temp 用于存储 a 的幂次方值
        int b = 1;                                              // b 用于计数当前是几次幂

        // 计算 a 的幂次，直到 temp 超过 x
        while (temp <= x)
        {
            temp *= a;                                          // temp 乘以 a，表示 a 的次幂
            ++b;                                                // 次幂计数器增加

            // 如果 temp 等于 x，输出对应的底数和指数
            if (temp == x)
            {
                cout << "=" << a << "^" << b << endl;           // 输出 a 的 b 次幂等于 x
                break;
            }
        }
    }

    return 0;
}
