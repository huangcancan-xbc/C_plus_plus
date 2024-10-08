//to_stringģ��ʵ���Լ�lambda���ʽ���Զ���ȽϺ���

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// �Զ��彫����ת��Ϊ�ַ����ĺ���
string intToString(int num) 
{
    string result;
    // ���� 0 �����
    if (num == 0) 
        return "0";

    // ������ת��Ϊ�ַ���
    while (num > 0) 
    {
        char digit = '0' + num % 10;  // ��ȡ���һλ���ֲ�ת��Ϊ�ַ�
        result = digit + result;  // �����ַ���������ǰ��
        num /= 10;  // �Ƴ����һλ����
    }

    return result;
}

// �Զ���ıȽϺ�������� Lambda ���ʽ
bool customCompare(const string& s1, const string& s2) 
{
    return s1 + s2 > s2 + s1;  // ����ƴ�Ӻ��ֵ���Ƚ�
}

string largestNumber(vector<int>& nums) 
{
    // �����е�����ת��Ϊ�ַ���
    vector<string> strs;
    for (int x : nums) 
    {
        strs.push_back(intToString(x));  // �ֶ�ת��
    }

    // ʹ���Զ���ıȽϺ�����������
    sort(strs.begin(), strs.end(), customCompare);

    // ��ȡ�����
    string ret;
    for (const string& s : strs) 
    {
        ret += s;
    }

    // �����һ���ַ���'0'�����������ж���0
    if (ret[0] == '0') 
        return "0";

    return ret;
}

int main() 
{
    vector<int> nums = { 3, 30, 34, 5, 9 };
    cout << largestNumber(nums) << endl;

    return 0;
}