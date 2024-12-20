//ţ�ͣ�С����ݱ�ţ������ Round 64��
//https://ac.nowcoder.com/acm/contest/92662/B

#include <iostream> 
#include <cmath> 
using namespace std;

int main()
{
    int x;                                                      // �������� x ���ڴ洢����ֵ
    cin >> x;                                                   // �ӱ�׼�����ȡ���� x
    cout << x << endl << "=" << x << "^1" << endl;              // ��� x ��������� 1 ����

    // �� x ��ƽ������ʼ���±�����Ѱ�ҿ��ܵĵ��� a
    for (int a = (int)sqrt(x); a >= 2; --a)
    {
        int temp = a;                                           // temp ���ڴ洢 a ���ݴη�ֵ
        int b = 1;                                              // b ���ڼ�����ǰ�Ǽ�����

        // ���� a ���ݴΣ�ֱ�� temp ���� x
        while (temp <= x)
        {
            temp *= a;                                          // temp ���� a����ʾ a �Ĵ���
            ++b;                                                // ���ݼ���������

            // ��� temp ���� x�������Ӧ�ĵ�����ָ��
            if (temp == x)
            {
                cout << "=" << a << "^" << b << endl;           // ��� a �� b ���ݵ��� x
                break;
            }
        }
    }

    return 0;
}
