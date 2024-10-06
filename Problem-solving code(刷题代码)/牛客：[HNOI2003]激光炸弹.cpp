//牛客：[HNOI2003]激光炸弹
//https://ac.nowcoder.com/acm/contest/20960/1024

//解决思路：
//1.输入处理：首先读取目标的数量和正方形的边长，并初始化目标位置的价值数组。
//      *使用一个二维数组 tmparr 来存储每个目标位置的价值。这是为了方便后续计算。
//      *使用前缀和数组 sumarr 来快速计算任意正方形区域内的目标总价值。
//2.前缀和计算：构建 sumarr，每个元素都包含从原点到该点的所有目标的总价值，便于后续快速查询。
//      *遍历整个坐标系，将每个目标的位置价值累加到 tmparr 中。
//      *通过 tmparr 生成 sumarr，以便能快速求出任意区域的总价值。
//3.暴力搜索：遍历每个可能的正方形的左下角，利用前缀和快速计算正方形内的目标价值，并更新最大值。


#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n = 0, r = 0;
    cin >> n >> r;  // 输入目标数量 n 和正方形边长 R

    int sumarr[5010][5010] = { 0 };  // 存储前缀和的数组
    int tmparr[5010][5010] = { 0 };   // 存储每个目标位置的价值

    // 输入目标信息
    for (int i = 0; i < n; i++) 
    {
        int x, y, v; // 目标的坐标和价值
        cin >> x >> y >> v;
        tmparr[x][y] += v;  // 将目标价值累加到目标位置
    }

    // 计算前缀和数组
    for (int i = 0; i < 5010; i++) 
    {
        for (int j = 0; j < 5010; j++) 
        {
            sumarr[i][j] = tmparr[i][j];  // 初始化前缀和

            if (i > 0) 
            {
                sumarr[i][j] += sumarr[i - 1][j];  // 加上上方的值
            }

            if (j > 0) 
            {
                sumarr[i][j] += sumarr[i][j - 1];  // 加上左侧的值
            }

            if (i > 0 && j > 0) 
            {
                sumarr[i][j] -= sumarr[i - 1][j - 1];  // 减去重复加上的左上角值
            }
        }
    }

    int maxval = 0;  // 用于存储最大价值

    // 遍历所有可能的正方形左下角坐标
    for (int x1 = 0; x1 + r <= 5010; x1++) 
    {
        for (int y1 = 0; y1 + r <= 5010; y1++) 
        {
            int x2 = x1 + r - 1;  // 正方形的右上角x坐标
            int y2 = y1 + r - 1;  // 正方形的右上角y坐标
            int temp = sumarr[x2][y2];  // 计算当前正方形内的总价值

            // 使用前缀和计算当前正方形的价值
            if (x1 > 0) 
            {
                temp -= sumarr[x1 - 1][y2];  // 减去左边的部分
            }

            if (y1 > 0) 
            {
                temp -= sumarr[x2][y1 - 1];  // 减去上边的部分
            }

            if (x1 > 0 && y1 > 0) 
            {
                temp += sumarr[x1 - 1][y1 - 1];  // 加上左上角重叠的部分
            }

            maxval = max(maxval, temp);  // 更新最大价值
        }
    }

    cout << maxval;  // 输出最大价值

    return 0;
}







#include <stdio.h>
#include <iostream> 
#include <math.h>
using namespace std;

int map[5005][5005] = { 0 }; // 初始化一个 5005x5005 的二维数组来记录权重

int main()
{
    int N, R;
    cin >> N >> R; // 输入 N 表示炸弹的数量，R 表示炸弹的作用范围

    int n = R, m = R; // 初始化 n 和 m 为 R，用于后续确定地图的最大边界
    for (int i = 0; i < N; i++) // 循环读取每个炸弹的信息
    {
        int x, y, w;
        cin >> x >> y >> w; // 输入炸弹的圆心坐标 (x, y) 和权重 w
        x++; y++; // 坐标自增 1，以避免数组下标为 0 的情况
        map[x][y] += w; // 将炸弹的权重 w 加到 (x, y) 位置
        n = max(n, x); // 更新地图横坐标的最大边界
        m = max(m, y); // 更新地图纵坐标的最大边界
    }

    // 使用二维前缀和算法来加速计算矩形区域的权重和
    for (int i = 1; i <= n; i++) // 从 (1,1) 开始计算二维前缀和
    {
        for (int j = 1; j <= m; j++)
        {
            // 前缀和公式：当前点的值 = 自身 + 上方 + 左方 - 左上角重复部分
            map[i][j] += map[i - 1][j] + map[i][j - 1] - map[i - 1][j - 1];
        }
    }

    int ans = 0; // 初始化最大权重和为 0
    // 在地图中查找一个 R×R 的区域的最大权重和
    for (int i = R; i <= n; i++) // 从 R 行开始查找
    {
        for (int j = R; j <= m; j++) // 从 R 列开始查找
        {
            // 计算以 (i, j) 为右下角的 R×R 区域的权重和
            // 左上角坐标为 (i-R+1, j-R+1)
            int tmp = map[i][j] - map[i - R][j] - map[i][j - R] + map[i - R][j - R];
            ans = max(ans, tmp); // 更新最大权重和
        }
    }

    cout << ans << endl; // 输出最大权重和
}
//注释说明：
//1.二维前缀和：这个算法通过累加矩形区域的权重和，避免每次都重新遍历一个矩形区域。
//  公式 map[i][j] += map[i - 1][j] + map[i][j - 1] - map[i - 1][j - 1] 确保每个点(i, j) 上累加了其上方、左方的值，同时减去左上角重复累加的部分。
//2.坐标转换：输入的炸弹坐标(x, y) 在原题中是从 0 开始计数的，但为了便于数组处理，将它们都加 1，避免数组下标越界的风险。
//3.最大权重和的查找：在前缀和处理之后，可以快速计算出任意 R×R 矩形区域的总权重，并用 ans = max(ans, tmp) 来更新当前的最大权重和。
//这段代码使用了高效的二维前缀和算法，极大地优化了对炸弹权重影响区域的计算。
