//牛客：[NOIP2005]校门外的树
//https://ac.nowcoder.com/acm/contest/20960/1017
//参考：https://www.bilibili.com/video/BV14B4y1w7GT/?spm_id_from=333.337.search-card.all.click&vd_source=47fe2fe2f10c4e806e38c62553037767

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int l = 0, m = 0; // l 表示路的长度，m 表示需要移除树的区间数量
    cin >> l >> m;

    // 初始化数组 `arr`，大小为 l + 10（数组稍微开大一些，防止边界溢出，如果大小刚好为l是过不了测试样例的），初始值都为 1，表示每个位置都有树
    vector<int> arr(l + 10, 1); // 注意，数组如果刚好是 l 大小的话不够用，初始化数组全部为 1 表示所有位置都有树

    int left = 0, right = 0; // left 和 right 分别表示要移除树的区间的左右端点
    for (int i = 0; i < m; i++) // 遍历输入的 m 个区间
    {
        cin >> left >> right; // 输入区间的左右端点
        for (int j = left; j <= right; j++) // 将这个区间内的树移走
        {
            arr[j] = 0; // 将数组中对应位置的树移走，即设置为 0
        }
    }

    int ans = 0; // 统计剩余树的数量
    for (int i = 0; i <= l; i++) // 遍历整个数组
    {
        if (arr[i] == 1) // 如果当前位置的树还在
        {
            ans++; // 计数器加一
        }
    }

    cout << ans; // 输出剩余的树的数量
    return 0;
}





//差分数组的思路（此法与区间的数量没有关系）
//先初始化差分数组，大小为 l+10，初始值都为 0，表示每个位置都没有树
//然后按照输入的 m 个区间，更新差分数组，将对应区间内的树移走，即差分数组对应位置的值加 1
//最后遍历整个差分数组，统计剩余的树的数量
#include<iostream>
using namespace std;

int main() {
    int l, m, x, y;
    int chafen[10010] = { 0 }; // 初始化差分数组，大小为 10010

    cin >> l >> m;

    // 读取 m 个区间，更新差分数组
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        chafen[x]++; // 起点加 1
        chafen[y + 1]--; // 终点+1的位置减 1
    }

    int a = 0, count = 0; // a 用于计算前缀和，count 用于统计未被移除的树
    // 遍历所有位置，计算前缀和，判断该位置是否有树
    for (int j = 0; j <= l; j++) {
        a += chafen[j]; // 计算当前位置的前缀和

        if (a == 0) { // 如果前缀和为 0，表示该位置的树没有被移除
            count++;
        }
    }

    // 输出剩余的树的数量
    cout << count;
    return 0;
}
//改进点:
//
//注释强调了差分数组的工作原理：通过差分数组快速标记要移除的区间。
//前缀和的解释加详细，让初学者更容易理解差分与前缀和之间的联系。





//区间合并的思路（此法与区间的数量有关）
//先按照输入的 m 个区间的左端点进行排序，然后初始化一个变量 count，初始值为 l+1，表示有 l+1 个树
//然后遍历剩余的 m 个区间，对于每个区间，如果它与前一个区间有交集，则合并区间，否则更新剩余的树数量，并更新当前区间
//最后处理最后一个区间，更新剩余的树数量
#include<iostream>
#include<algorithm>
using namespace std;

// 定义一个结构体表示区间
struct ty {
    int x, y; // x 表示区间左端点，y 表示右端点
} a[10010];

// 自定义比较函数，用于 sort 排序，按区间左端点升序排序
bool comp(ty a, ty b) {
    return a.x < b.x; // 按照区间的左端点从小到大排序
}

int main() {
    int l, m;
    cin >> l >> m;

    // 读取 m 个区间
    for (int i = 1; i <= m; i++) {
        cin >> a[i].x >> a[i].y;
    }

    // 使用 sort 对区间按左端点排序
    sort(a + 1, a + 1 + m, comp);

    int count = l + 1; // 初始树的数量为 l + 1
    int left = a[1].x, right = a[1].y; // 初始化第一个区间的左右端点

    // 遍历剩余的区间，进行区间合并操作
    for (int j = 2; j <= m; j++) {
        if (right >= a[j].x) { // 当前区间与前一区间有交集
            right = max(right, a[j].y); // 合并区间
        }
        else {
            // 没有交集，更新剩余的树数量
            count -= (right - left + 1); // 移除当前区间内的树
            // 更新当前区间
            left = a[j].x;
            right = a[j].y;
        }
    }

    // 处理最后一个区间
    count -= (right - left + 1);

    // 输出剩余的树的数量
    cout << count;
    return 0;
}
//改进点:
//
//注释解释了如何利用结构体存储区间，并使用自定义排序函数进行排序。
//对区间合并的逻辑进行了详细解释，帮助理解如何通过合并区间减少计算量。



//差分数组法利用了前缀和思想，适合处理大量区间操作的情况。
//区间合并法通过排序和合并区间减少重复计算，适合区间数目相对较少的情况。
//直接模拟法简单易懂，但处理大规模数据时效率较低。



//技巧汇总;
//1.可以使用结构体数组来存储一次性输入的一组多个数据
//2.在使用sort()进行排序时，一定要定义好排序的规则，否则会出错（比如这里是严格的小于排序）
//3.存储数据时，可以从下标为1的位置开始存储，便于访问与操作