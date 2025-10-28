#include "MyVector.h"
using namespace std;

// �����޲ι��캯��
void test1()
{
	minbit::vector<int> v;
	cout << "���� V �Ĵ�СΪ: " << v.size() << endl;
	cout << "���� V ������Ϊ: " << v.capacity() << endl;

	cout << endl << endl;
}


// �����вι��캯��
void test2()
{
	minbit::vector<double> v(10);
	cout << "���� V �Ĵ�СΪ: " << v.size() << endl;
	cout << "���� V ������Ϊ: " << v.capacity() << endl;
	for (int i = 0; i < 10; i++)
	{
		v[i] = i * 1.5;
	}

	for (auto x : v)
	{
		cout << x << " ";
	}

	cout << endl << endl;
}


void test3()
{
	minbit::vector<double> v(10, 1);
	cout << "���� V �Ĵ�СΪ: " << v.size() << endl;
	cout << "���� V ������Ϊ: " << v.capacity() << endl;

	for (auto x : v)
	{
		cout << x << " ";
	}

	cout << endl << endl;
}


// �������乹�캯��
void test4()
{
	minbit::vector<int> v(10);
	for (int i = 1; i <= 10; i++)
	{
		v[i - 1] = i;
	}

	minbit::vector<int> v2(v.begin() + 2, v.end() - 2);
	cout << "���� V2 �Ĵ�СΪ: " << v2.size() << endl;
	cout << "���� V2 ������Ϊ: " << v2.capacity() << endl;

	for (auto x : v2)
	{
		cout << x << " ";
	}

	cout << endl << endl;
}


// ���Կ������캯��
void test5()
{
	minbit::vector<int> v(10);
	for (int i = 1; i <= 10; i++)
	{
		v[i - 1] = i;
	}

	minbit::vector<int> v2(v);
	cout << "���� V2 �Ĵ�СΪ: " << v2.size() << endl;
	cout << "���� V2 ������Ϊ: " << v2.capacity() << endl;

	for (auto x : v2)
	{
		cout << x << " ";
	}

	cout << endl << endl;
}


// ���Ը�ֵ��������غ���
void test6()
{
	minbit::vector<int> v(10);
	for (int i = 1; i <= 10; i++)
	{
		v[i - 1] = i;
	}

	minbit::vector<int> v2 = v;
	cout << "���� V2 �Ĵ�СΪ: " << v2.size() << endl;
	cout << "���� V2 ������Ϊ: " << v2.capacity() << endl;

	for (auto x : v2)
	{
		cout << x << " ";
	}

	cout << endl << endl;
}


// ���Ե�������غ���
void test7()
{
	//iterator begin();
	//iterator end();
	//const_iterator begin()const;
	//const_iterator end()const;
	minbit::vector<int> v(10);
	for (int i = 1; i <= 10; i++)
	{
		v[i - 1] = i * 5;
	}

	minbit::vector<int>::iterator begin = v.begin();
	minbit::vector<int>::iterator end = v.end();
	for (minbit::vector<int>::iterator it = begin; it != end; it++)
	{
		*it = 1;
		cout << *it << " ";
	}
	cout << endl;

	minbit::vector<int>::const_iterator cbegin = v.begin();
	minbit::vector<int>::const_iterator cend = v.end();
	for (minbit::vector<int>::const_iterator cit = cbegin; cit != cend; cit++)
	{
		//*cit = 1;		// ��ͼ�޸�Ԫ�أ����������� const �ģ������޷��޸�Ԫ�أ����лᱨ������Ԥ��
		cout << *cit << " ";
	}
	cout << endl;

	cout << endl << endl;
}


// ���������ʹ�С��غ���
void test8()
{
	minbit::vector<int> v;
	if (v.empty())
	{
		cout << "���� V �ǿյ�" << endl;
	}
	else
	{
		cout << "���� V ���ǿյ�" << endl;
	}

	v.reserve(10);
	cout << "���� V �Ĵ�СΪ: " << v.size() << endl;
	cout << "���� V ������Ϊ: " << v.capacity() << endl;

	v.resize(20);
	cout << "���� V �Ĵ�СΪ: " << v.size() << endl;
	cout << "���� V ������Ϊ: " << v.capacity() << endl;

	if (v.empty())
	{
		cout << "���� V �ǿյ�" << endl;
	}
	else
	{
		cout << "���� V ���ǿյ�" << endl;
	}

	cout << endl << endl;
}


// �����޸�����������غ���
void test9()
{
	minbit::vector<int> v;
	//v.pop_back();	// ��ͼ���������飬�ᴥ�����ԣ����лᱨ������Ԥ��

	for (int i = 0; i < 5; i++)
	{
		v.push_back(i);
	}

	for (auto x : v)
	{
		cout << x << " ";
	}
	cout << endl;

	v.pop_back();
	v.pop_back();
	for (auto x : v)
	{
		cout << x << " ";
	}
	cout << endl;

	v.insert(v.begin() + 1, 1111);
	v.insert(v.begin() + 100, 222);
	for (auto x : v)
	{
		cout << x << " ";
	}
	cout << endl;

	v.erase(v.begin() + 1);
	v.erase(v.begin() + 2);
	for (auto x : v)
	{
		cout << x << " ";
	}
	cout << endl;

	minbit::vector<int> v1(10, 66);
	v.swap(v1);
	cout << "ԭʼ����������齻����" << endl;
	cout << "ԭʼ�����ɣ�";
	for (auto x : v)
	{
		cout << x << " ";
	}
	cout << endl;
	cout << "�������ɣ�";
	for (auto x : v1)
	{
		cout << x << " ";
	}
	cout << endl;

	v.clear();
	cout << "���� V �����" << endl;
	if (v.empty())
	{
		cout << "���� V �ǿյ�" << endl;
	}
	else
	{
		cout << "���� V ���ǿյ�" << endl;
	}

	cout << endl << endl;
}


// ���Է���������غ���
void test10()
{
	//T& operator[](size_t i);
	//const T& operator[](size_t i)const;

	minbit::vector<int> v(10);
	for (int i = 0; i < 10; i++)
	{
		v[i] = i * 12;
	}
	for (auto x : v)
	{
		cout << x << " ";
	}
	cout << endl;

	cout << "���� V �ĵ� 2 ��Ԫ��Ϊ��" << v[1] << endl;
	cout << "���� V �ĵ� 5 ��Ԫ��Ϊ��" << v[4] << endl;
	v[0] = -100;
	cout << "���� V �ĵ� 1 ��Ԫ���޸ĺ�Ϊ��" << v[0] << endl;
	for (auto x : v)
	{
		cout << x << " ";
	}
	cout << endl;

	const minbit::vector<int> cv(10, 20);
	for (auto x : cv)
	{
		cout << x << " ";
	}
	cout << endl;

	//cv[1] = 30;		// ��ͼ�޸�Ԫ�أ����������� const �ģ������޷��޸�Ԫ�أ����лᱨ������Ԥ��

	cout << endl << endl;
}


int main()
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	test9();
	test10();


	return 0;
}