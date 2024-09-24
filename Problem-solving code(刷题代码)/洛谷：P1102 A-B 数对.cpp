#define _CRT_SECURE_NO_WARNINGS 1

//��ȣ�P1102 A-B ����
//https://www.luogu.com.cn/problem/P1102
//˼·��
//1. ����n��c��a����
//2. ����ӳ���mp��ͳ��a������ÿ�������ֵĴ���
//3. ����a���飬��ÿ������ȥc������ѯӳ���mp�и������ֵĴ������ۼӵ�count��
//4. ���count

#include <iostream>  // �����׼���������
#include <vector>    // ���붯̬����⣨vector��
#include <algorithm> // �����㷨�⣨algorithm��
#include <map>       // ����ӳ��⣨map��
using namespace std;

int main()
{
    long long n, c;
    cin >> n >> c;
    vector<long long> a(n);
    map<long long, long long > mp;
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;//ͳ��a������ÿ�������ֵĴ���
        a[i] -= c;//A-B=C���A-C=B
    }

    long long count = 0;

    for (long long i = 0; i < n; i++)
    {
        count += mp[a[i]];//�������ڣ���ӳ����и������ֵĴ����ۼӵ�count�У�
        //���a[i]���ڣ���count+=1����������ڣ����� 0���Խ��û��Ӱ�졣
    }

    cout << count << endl;
    // ������������
    return 0;
}
