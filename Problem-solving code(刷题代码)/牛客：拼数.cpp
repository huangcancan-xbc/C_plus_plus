#include <iostream>
#include <string>
//ţ�ͣ�ƴ��
//https://ac.nowcoder.com/acm/problem/16783

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// �Զ���ȽϺ�������������
bool sort1(const string& a, const string& b)
{
    // �Ƚ������ַ���ƴ�ӵĽ�����������ǵ�˳��
    return a + b > b + a; // ���a+b��b+a����a����bǰ��
}

int main()
{
    int n; // �����ַ���������
    cin >> n; // �ӱ�׼�����ȡ����
    vector<string> arr(n); // ����һ���ַ������飬��СΪn

    // ��ȡn���ַ���
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // �������ж�ȡÿ���ַ���
    }

    // ʹ���Զ����sort1�����������������
    sort(arr.begin(), arr.end(), sort1);

    // ���ƴ�Ӻ�Ľ��
    for (int i = 0; i < n; i++)
    {
        cout << arr[i]; // ��������������ַ�������ƴ�Ӻ�����ս�����𰸣�
    }
    return 0; // �������
}
