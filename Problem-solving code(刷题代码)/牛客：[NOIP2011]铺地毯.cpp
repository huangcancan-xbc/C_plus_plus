#define _CRT_SECURE_NO_WARNINGS 1

//牛客：[NOIP2011]铺地毯
//https://ac.nowcoder.com/acm/contest/20960/1016
//参考：https://www.bilibili.com/video/BV1p34y1D7fC/?spm_id_from=333.1007.top_right_bar_window_history.content.click&vd_source=47fe2fe2f10c4e806e38c62553037767

#include <iostream>
using namespace std;

int main()
{
    int n = 0; // 定义变量n，用于存储输入的地毯数量
    cin >> n; // 从标准输入读取地毯数量

    int arr[10010][5]; // 定义一个二维数组arr，用于存储每块地毯的坐标

    // 读取每块地毯的左下角和右上角坐标
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i][1] >> arr[i][2] >> arr[i][3] >> arr[i][4];
        arr[i][3] += arr[i][1]; // 计算右上角x坐标
        arr[i][4] += arr[i][2]; // 计算右上角y坐标
    }

    int x = 0, y = 0; // 定义目标点坐标x和y
    cin >> x >> y; // 从标准输入读取目标点的坐标

    int flag = -1; // 定义标志变量flag，用于判断是否找到符合条件的地毯
    // 从后往前遍历地毯数组，寻找包含目标点的地毯
    for (int i = n; i >= 1; i--)
    {
        // 检查目标点是否在当前地毯范围内
        if (arr[i][1] <= x && arr[i][3] >= x && arr[i][2] <= y && arr[i][4] >= y)
        {
            cout << i; // 输出符合条件的地毯编号
            flag = 1; // 更新flag标志，表示找到了符合条件的地毯
            break; // 找到后退出循环
        }
    }

    // 如果没有找到符合条件的地毯，输出-1
    if (flag == -1)
    {
        cout << -1;
    }
    return 0; // 程序结束
}



//两个版本的思想是一样的，但是代码实现上有些区别。
//第一个版本使用二维数组存储地毯的坐标，然后从后往前遍历地毯数组，寻找包含目标点的地毯。
//第二个版本使用结构体存储地毯的坐标和尺寸，然后从最后一块地毯开始往前检查，直到找到覆盖目标点的地毯。


#include <iostream>
using namespace std;

struct Carpet {
    int a, b, g, k; // 地毯左下角(a, b) 和宽高(g, k)
};

int main() {
    int n;
    cin >> n; // 读取地毯数量
    Carpet carpets[10010]; // 最多10000块地毯

    // 读取每块地毯的坐标和尺寸
    for (int i = 1; i <= n; i++) {
        cin >> carpets[i].a >> carpets[i].b >> carpets[i].g >> carpets[i].k;
    }

    int x, y;
    cin >> x >> y; // 读取需要检查的点 (x, y)

    int result = -1; // 默认结果为 -1，表示未找到覆盖的地毯

    // 从最后一块地毯开始往前检查
    for (int i = n; i >= 1; i--) {
        // 检查点 (x, y) 是否在第 i 块地毯内
        if (carpets[i].a <= x && x <= carpets[i].a + carpets[i].g &&
            carpets[i].b <= y && y <= carpets[i].b + carpets[i].k) {
            result = i; // 找到覆盖该点的地毯
            break;      // 因为是从后往前检查的，找到后立即退出
        }
    }

    cout << result << endl; // 输出结果
    return 0;
}
