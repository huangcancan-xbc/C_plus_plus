// 有参有返回值的回调函数（add、sub、mul、divi 都是回调函数）
#include <iostream>
using namespace std;

int add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

int mul(int a, int b)
{
	return a * b;
}

int divi(int a, int b)
{
	if (b == 0)
	{
		cout << "除 0 错误！" << endl;
		return -1;
	}

	return a / b;
}

void calculate(int a, int b, int (*callback)(int x, int y))
{
	cout << "开始计算" << a << "和" << b << "的运算结果:" << endl;
	cout << "结果为：" << callback(a, b) << endl;
}

int main()
{
	calculate(10, 5, add);
	calculate(10, 5, sub);
	calculate(10, 5, mul);
	calculate(10, 5, divi);
	calculate(10, 0, divi);

	//输出：
	//开始计算10和5的运算结果:
	//结果为：15
	//	开始计算10和5的运算结果 :
	//结果为：5
	//	开始计算10和5的运算结果 :
	//结果为：50
	//	开始计算10和5的运算结果 :
	//结果为：2
	//	开始计算10和0的运算结果 :
	//除 0 错误！
	//	结果为： - 1

	return 0;
}