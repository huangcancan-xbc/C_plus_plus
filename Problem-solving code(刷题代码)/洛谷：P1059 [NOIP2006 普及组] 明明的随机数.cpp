#define _CRT_SECURE_NO_WARNINGS 1

//��ȣ�P1059 [NOIP2006 �ռ���] �����������
//https://www.luogu.com.cn/problem/P1059

#include <iostream>  // �����׼���������
#include <vector>    // ���붯̬����⣨vector��
#include <set>       // ���뼯�Ͽ⣨set��
using namespace std;

int main()
{
    int n;
    // ��ȡ���� n����ʾ��Ҫ�������������
    cin >> n;

    // ����һ������ set�����ڴ洢��������������Զ�ȥ��
    set<int> vis;

    // ѭ����ȡ n ������
    for (int i = 0; i < n; i++)
    {
        int x;
        // ��ȡ��ǰ��������� x
        cin >> x;
        // �� x ���뵽���� vis �У����ϻ��Զ�ȥ���ظ�Ԫ��
        vis.insert(x);
    }

    // ������� vis ��Ԫ�صĸ��������������ȥ�غ������
    cout << vis.size() << endl;

    // ʹ�ü��� vis ��Ԫ�س�ʼ��һ�� vector ��̬���� arr
    vector<int> arr(vis.begin(), vis.end());

    // ������̬���� arr ��������е�Ԫ��
    for (auto i = arr.begin(); i != arr.end(); i++)
    {
        // ���ÿ��Ԫ�أ����Կո�ָ�
        cout << *i << " ";
    }

    // ������������
    return 0;
}
