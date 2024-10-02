//ţ�ͣ�Captcha Cracker
//https://ac.nowcoder.com/acm/contest/20960/1007

#include <iostream>
#include <string>
using namespace std;
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        string copy;

        cin >> s;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0' || s[i] == '2' || s[i] == '4' || s[i] == '6' || s[i] == '9')
            {
                copy += s[i];
            }
            else if (s[i] == 'z' && s[i + 1] == 'e' && s[i + 2] == 'r' && s[i + 3] == 'o')
            {
                copy += '0';
                i += 3;
            }
            else if (s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o')
            {
                copy += '2';
                i += 2;
            }
            else if (s[i] == 'f' && s[i + 1] == 'o' && s[i + 2] == 'u' && s[i + 3] == 'r')
            {
                copy += '4';
                i += 3;
            }
            else if (s[i] == 's' && s[i + 1] == 'i' && s[i + 2] == 'x')
            {
                copy += '6';
                i += 2;
            }
            else if (s[i] == 'n' && s[i + 1] == 'i' && s[i + 2] == 'n' && s[i + 3] == 'e')
            {
                copy += '9';
                i += 3;
            }
        }

        cout << copy << endl;
    }
    return 0;
}





#include <iostream>
#include <string>
using namespace std;

int main()
{
    int T;
    cin >> T;  // ��ȡ������������

    while (T--)  // ѭ������ÿһ���������
    {
        string s;
        cin >> s;  // ��ȡ�ַ���
        string result;  // �洢����ַ���

        for (int i = 0; i < s.size(); i++)
        {
            // ��鵥���ַ�����
            if (s[i] == '0' || s[i] == '2' || s[i] == '4' || s[i] == '6' || s[i] == '9')
            {
                result += s[i];  // �������ַ���ӵ������
            }

            // ���4���ַ��ĵ���
            if (i + 3 < s.size())  // ȷ������Խ��
            {
                string c = s.substr(i, 4);
                if (c == "zero")
                {
                    result += '0';  // ��� '0'
                    i += 3;  // ����������ַ�
                    continue;  // �������ѭ��
                }
                else if (c == "four")
                {
                    result += '4';  // ��� '4'
                    i += 3;  // ����������ַ�
                    continue;  // �������ѭ��
                }
                else if (c == "nine")
                {
                    result += '9';  // ��� '9'
                    i += 3;  // ����������ַ�
                    continue;  // �������ѭ��
                }
            }

            // ���3���ַ��ĵ���
            if (i + 2 < s.size())  // ȷ������Խ��
            {
                string c = s.substr(i, 3);
                if (c == "two")
                {
                    result += '2';  // ��� '2'
                    i += 2;  // ����������ַ�
                    continue;  // �������ѭ��
                }
                else if (c == "six")
                {
                    result += '6';  // ��� '6'
                    i += 2;  // ����������ַ�
                    continue;  // �������ѭ��
                }
            }
        }

        cout << result << endl;  // ������
    }

    return 0;
}






#include <iostream>
#include <string>
#include <unordered_map> // ����unordered_map
using namespace std;

int main()
{
    int t;
    cin >> t;

    // ʹ��unordered_map�洢���ֶ�Ӧ���ַ���
    unordered_map<string, char> numMap = {
        {"zero", '0'},
        {"two", '2'},
        {"four", '4'},
        {"six", '6'},
        {"nine", '9'}
    };

    while (t--)
    {
        string s;
        string copy; // �洢���

        cin >> s;

        for (int i = 0; i < s.size(); i++)
        {
            // ��鵥������
            if (s[i] == '0' || s[i] == '2' || s[i] == '4' || s[i] == '6' || s[i] == '9')
            {
                copy += s[i]; // ֱ�Ӽ���
            }
            else
            {
                // �������ֵĵ�����ʽ
                // ����Ҫ���ÿ������
                for (const auto& pair : numMap)
                {
                    const string& word = pair.first; // ����
                    char digit = pair.second;         // ��Ӧ������

                    // �����ǰ�ַ��뵥�ʵĵ�һ���ַ�ƥ��
                    if (s.substr(i, word.size()) == word)
                    {
                        copy += digit; // �����Ӧ������
                        i += word.size() - 1; // �ƶ�������word.size() ����ƥ���ַ����ĳ��ȡ�
                        //�����ֱ�Ӽ���������ȣ���һ��ѭ��ʱ i ��ָ��ǰƥ���ַ�������һ���ַ��������� for ѭ�������� i 1��
                        //������Ҫ��ȥ 1��ȷ���� for ѭ���� i ��ֵָ����һ��δ�����ַ���
                        //���д����ʵ��Ч���ǽ� i ����Ϊ��ǰ�ַ�����ƥ���ַ�֮���λ�ã�ʹ������һ��ѭ��ʱ�������Ѿ�ƥ��Ĳ��֣�����������һ���ַ���
                        break; // �˳�ѭ��
                    }
                }
            }
        }

        cout << copy << endl; // ������
    }
    return 0;
}
