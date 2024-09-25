#include <iostream>
#include <string>
//ţ�ͣ�tb���ַ�������
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
//ԭ��������ˣ����Ǵ����е����࣬����ʱ�临�Ӷ�Ϊ O(n^2)�����׳�ʱ�������Ż�һ�¡�
//�Ż�������
//1. ջ����ջ���洢 'f' �� 't'������ 'c' �� 'b' ʱ������ջ��Ԫ�أ�ֱ��ջΪ�ջ�ջ��Ԫ�ز��� 'f' �� 't'��
//2. �ַ����������ַ��������� 'f' �� 't' ʱ��ѹ��ջ������ 'c' �� 'b' ʱ������ջ��Ԫ�أ�ֱ��ջΪ�ջ�ջ��Ԫ�ز��� 'f' �� 't'��
//3. ʱ�临�Ӷȣ�O(n)����Ϊ�����ַ���һ�Σ�ջ����һ�Ρ�
//�Ż���Ĵ������£�

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    stack<char> sta; // ���ڴ洢�ַ���ջ
    int n = 0;       // �ַ�������
    cin >> n;

    string s;
    cin >> s;

    // �����ַ����е�ÿ���ַ�
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'f' || s[i] == 't') // ����� 'f' �� 't'��ѹ��ջ
        {
            sta.push(s[i]);
        }
        else if (s[i] == 'c' && !sta.empty() && sta.top() == 'f') // ����� 'c' ����ջ���� 'f'������ջ��
        {
            sta.pop();
        }
        else if (s[i] == 'b' && !sta.empty() && sta.top() == 't') // ����� 'b' ����ջ���� 't'������ջ��
        {
            sta.pop();
        }
        else
        {
            sta.push(s[i]); // ������������� 'c' û��ƥ��� 'f'��'b' û��ƥ��� 't'����ѹ��ջ
        }
    }

    // ����ջ�Ĵ�С����ʣ��û�б��Ƴ����ַ�����
    cout << sta.size() << endl;

    return 0;
}
