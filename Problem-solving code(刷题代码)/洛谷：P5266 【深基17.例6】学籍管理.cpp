#include <iostream>
#include <string>
//��ȣ�P5266 �����17.��6��ѧ������
//https://www.luogu.com.cn/problem/P5266

#include <iostream>
#include <map>
using namespace std;

int main()
{
    // ����һ��map����Ϊstring���ͣ�ֵΪlong long����
    map<string, long long> mp;
    string name; // �洢����
    int n = 0;   // ����Ĳ�������
    cin >> n;    // ��ȡ��������
    int ans = 0; // �û���������
    long long score = 0; // �洢����

    while (n--) // ���ݲ�����������ѭ��
    {
        cin >> ans; // ��ȡ�û���������
        if (ans == 1) // �������������1����ʾ��Ӽ�¼
        {
            cin >> name >> score; // ��ȡ�����ͷ���
            mp[name] = score; // ��map�в������¼�¼

            cout << "OK" << endl; // ��������ɹ�
        }
        else if (ans == 2) // �������������2����ʾ��ѯ����
        {
            cin >> name; // ��ȡ����
            if (mp.find(name) == mp.end()) // �������������
            {
                cout << "Not found" << endl; // ���δ�ҵ�
            }
            else
            {
                cout << mp[name] << endl; // �������
            }
        }
        else if (ans == 3) // �������������3����ʾɾ����¼
        {
            cin >> name; // ��ȡ����
            if (mp.find(name) == mp.end()) // �������������
            {
                cout << "Not found" << endl; // ���δ�ҵ�
            }
            else
            {
                mp.erase(name); // ɾ����¼
                cout << "Deleted successfully" << endl; // ���ɾ���ɹ�
            }
        }
        else if (ans == 4) // �������������4����ʾ��ѯ��¼��
        {
            cout << mp.size() << endl; // ���map��Ԫ�ص�����
        }
    }

    return 0; // �������
}




#include <iostream>
#include <map>
using namespace std;

int main() {
    // ����һ��map����Ϊstring���ͣ�ֵΪint����
    map<string, int> mp;
    string name; // �洢����
    int n = 0;   // ����Ĳ�������
    cin >> n;    // ��ȡ��������
    int ans = 0; // �û���������
    int score = 0; // �洢����

    while (n--) { // ���ݲ�����������ѭ��
        cin >> ans; // ��ȡ�û���������
        if (ans == 1) { // �������������1����ʾ��Ӽ�¼
            cin >> name >> score; // ��ȡ�����ͷ���
            mp[name] = score; // ��map�в������¼�¼

            cout << "OK" << endl; // ��������ɹ�
        }
        else if (ans == 2) { // �������������2����ʾ��ѯ����
            cin >> name; // ��ȡ����
            if (mp.find(name) == mp.end()) { // �������������
                cout << "Not found" << endl; // ���δ�ҵ�
            }
            else {
                cout << mp[name] << endl; // �������
            }
        }
        else if (ans == 3) { // �������������3����ʾɾ����¼
            cin >> name; // ��ȡ����
            if (mp.find(name) == mp.end()) { // �������������
                cout << "Not found" << endl; // ���δ�ҵ�
            }
            else {
                mp.erase(name); // ɾ����¼
                cout << "Deleted successfully" << endl; // ���ɾ���ɹ�
            }
        }
        else if (ans == 4) { // �������������4����ʾ��ѯ��¼��
            cout << mp.size() << endl; // ���map��Ԫ�ص�����
        }
    }

    return 0; // �������
}
