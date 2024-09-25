#include <iostream>
#include <string>
//牛客：tb的字符串问题
//https://ac.nowcoder.com/acm/contest/91393/B

using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	
	string s;
	cin >> s;

	while (true)
	{
		bool flag = false;
		for (int i = 0; i < s.size() - 1; i++)
		{
			if ((s[i] == 'f' && s[i + 1] == 'c') || (s[i] == 't' && s[i + 1] == 'b'))
			{
				s.erase(i, 2);

				flag = true;
				break;
			}
		}

		if (!flag)
		{
			break;
		}
	}

	cout << s.size() << endl;
	return 0;
}
//原则基本对了，但是代码有点冗余，并且时间复杂度为 O(n^2)，容易超时，可以优化一下。
//优化方法：
//1. 栈：用栈来存储 'f' 和 't'，遇到 'c' 和 'b' 时，弹出栈顶元素，直到栈为空或栈顶元素不是 'f' 或 't'。
//2. 字符串：遍历字符串，遇到 'f' 或 't' 时，压入栈，遇到 'c' 和 'b' 时，弹出栈顶元素，直到栈为空或栈顶元素不是 'f' 或 't'。
//3. 时间复杂度：O(n)，因为遍历字符串一次，栈操作一次。
//优化后的代码如下：

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    stack<char> sta; // 用于存储字符的栈
    int n = 0;       // 字符串长度
    cin >> n;

    string s;
    cin >> s;

    // 遍历字符串中的每个字符
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'f' || s[i] == 't') // 如果是 'f' 或 't'，压入栈
        {
            sta.push(s[i]);
        }
        else if (s[i] == 'c' && !sta.empty() && sta.top() == 'f') // 如果是 'c' 并且栈顶是 'f'，弹出栈顶
        {
            sta.pop();
        }
        else if (s[i] == 'b' && !sta.empty() && sta.top() == 't') // 如果是 'b' 并且栈顶是 't'，弹出栈顶
        {
            sta.pop();
        }
        else
        {
            sta.push(s[i]); // 其他情况（比如 'c' 没有匹配的 'f'，'b' 没有匹配的 't'），压入栈
        }
    }

    // 最终栈的大小就是剩下没有被移除的字符数量
    cout << sta.size() << endl;

    return 0;
}
