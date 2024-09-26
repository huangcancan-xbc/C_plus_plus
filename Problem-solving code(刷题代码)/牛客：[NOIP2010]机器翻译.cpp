#define _CRT_SECURE_NO_WARNINGS 1
//牛客：[NOIP2010]机器翻译
//https://ac.nowcoder.com/acm/contest/20960/1003

//思路：核心思想是维护一个容量为 m 的窗口（数组 a[]），每次处理一个输入数字。
// 如果数字已经在窗口中，就跳过，不做处理；如果数字不在窗口中，就将其插入窗口。
// 如果窗口的容量已经达到上限（超过 m），则将最早插入的数字移出窗口（释放空间）。
//arr[] 数组用来标记某个元素是否在窗口中，方便快速判断。
//count 记录了插入窗口的总数，最终输出这个值。

#include <stdio.h>

int vis[1010] = { 0 };
int a[1010] = { 0 };
int m, n;

int main()
{
	int count = 0;
	int x = 0;
	scanf("%d %d", &m, &n);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);

		if (vis[x] == 1)//用1判断数是否重复
		{
			continue;
		}
		else
		{
			a[++count] = x;//插入窗口
			vis[a[count]] = 1;//并将插入的数用1标记为已存在
			if (count > m)
			{
				vis[a[count - m]] = 0;//当窗口满了，则将最早插入的数移出窗口
			}
		}
	}

	printf("%d\n", count);

	return 0;
}