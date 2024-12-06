//�����ַ�����ʽ��

//��������
//СM�ڹ���ʱ������һ�����⣬����Ҫ���û�����Ĳ���ǧ��λ���ŵ������ַ���ת��Ϊ��ǧ��λ���ŵĸ�ʽ�����ұ���С�����֡�
//СM�����֣���ʱ������������ַ���ǰ��������õ� 0����ЩҲ��Ҫ��������������СM��д��������������
//
//��������
//
//����1��
//���룺s = "1294512.12412"
//�����'1,294,512.12412'
//
//����2��
//���룺s = "0000123456789.99"
//�����'123,456,789.99'
//
//����3��
//���룺s = "987654321"
//�����'987,654,321'


std::string solution(const std::string& s) 
{
    
    if (s.empty())
    {
        return "";                                                  // ��������Ƿ���Ч
    }

    // �����������ֺ�С������
    size_t pos = s.find('.');
    string left = (pos == string::npos) ? s : s.substr(0, pos);     // ��������
    string right = (pos == string::npos) ? "" : s.substr(pos);      // С�����֣�����С���㣩

    size_t first_nonzero = left.find_first_not_of('0');             // ȥ���������ֵ�ǰ���㣨ע�⣺���� "0" Ӧ������
    if (first_nonzero == string::npos)                              // ���ȫ���㣬��������ӦΪ "0"
    {
        left = "0";
    }
    else 
    {
        left = left.substr(first_nonzero);
    }

    // �������ִ��� - ����ǧ��λ�ָ���
    string temp;
    int count = 0;
    for (int i = left.size() - 1; i >= 0; --i) 
    {
        temp += left[i];
        count++;
        if (count % 3 == 0 && i > 0) 
        {
            temp += ',';
        }
    }
    reverse(temp.begin(), temp.end());

    string ret = temp + right;                                      // ���ƴ��
    return ret;
}
