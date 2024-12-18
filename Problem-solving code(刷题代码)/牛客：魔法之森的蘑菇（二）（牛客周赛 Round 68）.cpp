//牛客：魔法之森的蘑菇（二）（牛客周赛 Round 68）
//https://ac.nowcoder.com/acm/contest/95928/B


#include <bits/stdc++.h>
using namespace std;

char s[31][31];          // 定义一个字符二维数组表示森林
int n, m;                // n表示行数，m表示列数

// 判断给定区域是否全为空地（' . '）
int judgment(int l1, int r1, int l2, int r2)
{
    for (int i = l1; i <= l2; i++)
    {
        for (int j = r1; j <= r2; j++)
        {
            if (s[i][j] == '*')    // 如果区域中有蘑菇，则返回0
            {
                return 0;
            }
        }
    }

    return 1;                      // 如果区域全为空地，则返回1
}

int main()
{
    cin >> n >> m;                 // 读取森林的行数和列数

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> s[i][j];        // 输入森林的地图，字符' . '代表空地，'*'代表蘑菇
        }
    }

    int MAX = 0;                                                            // 存储最大空地面积
    int x1 = 0, y1 = 0;                                                     // 存储最大空地左上角坐标
    int x2 = 0, y2 = 0;                                                     // 存储最大空地右下角坐标

    for (int l1 = 0; l1 < n; l1++)                                          // 遍历所有可能的左上角行坐标
    {
        for (int r1 = 0; r1 < m; r1++)                                      // 遍历所有可能的左上角列坐标
        {
            for (int l2 = l1; l2 < n; l2++)                                 // 遍历所有可能的右下角行坐标
            {
                for (int r2 = r1; r2 < m; r2++)                             // 遍历所有可能的右下角列坐标
                {
                    if (judgment(l1, r1, l2, r2) == 1)                      // 判断当前区域是否为空地
                    {
                        int tmp = (l2 - l1 + 1) * (r2 - r1 + 1);            // 计算当前空地面积

                        if (tmp > MAX)                                      // 更新最大面积和对应坐标
                        {
                            MAX = tmp;
                            x1 = l1, y1 = r1, x2 = l2, y2 = r2;
                        }
                    }
                }
            }
        }
    }

    cout << x1 + 1 << " " << y1 + 1 << " " << x2 + 1 << " " << y2 + 1;     // 输出最大空地区域的坐标（按1-based索引）
    return 0;
}
