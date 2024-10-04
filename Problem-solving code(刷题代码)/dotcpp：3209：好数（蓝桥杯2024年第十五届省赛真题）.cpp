//dotcpp��3209�����������ű�2024���ʮ���ʡ�����⣩
//https://www.dotcpp.com/oj/problem3209.html

#include <iostream>
using namespace std;

// �������ж�һ�����Ƿ�Ϊ����
bool isgoodnumber(long long n)
{
    int count = 0; // ��¼���ֵ�λ��
    long long temp = n; // ����ԭʼ�����Ա����ʹ��
    int good = 0; // ��¼����������λ������

    // �������� n ����λ��
    while (n != 0)
    {
        count++; // λ����һ
        n /= 10; // �� n ���� 10��ȥ�����һλ
    }

    n = temp; // ���� n���Ա��ٴα���ÿһλ

    // ����ÿһλ����
    for (long long i = 1; i <= count; i++) // �ӵ�һλ�����һλ
    {
        int current = n % 10; // ��ȡ��ǰλ������

        // �жϵ�ǰλӦ������������ż��
        if (i % 2 == 0 && current % 2 == 0) // �����ż��λ�ҵ�ǰ����Ϊż��
        {
            good++; // ��������һ����ʾ��������
        }
        else if (i % 2 == 1 && current % 2 == 1) // ���������λ�ҵ�ǰ����Ϊ����
        {
            good++; // ��������һ����ʾ��������
        }

        n /= 10; // �Ƶ���һλ
    }

    // �������������λ������������λ�����򷵻� true����ʾ�Ǻ�����
    return (good == count);
}

int main()
{
    long long n = 0; // �������� n
    cin >> n; // �ӱ�׼�����ȡһ�������� n

    long long ans = 0; // ���ڼ����ı�������¼����������

    // ������ 1 �� n ��ÿһ������
    for (long long i = 1; i <= n; i++)
    {
        if (isgoodnumber(i)) // �жϵ�ǰ�� i �Ƿ�Ϊ����
        {
            ans++; // ����Ǻ�������������һ
        }
    }

    cout << ans; // ���������������
    return 0; // �������
}
