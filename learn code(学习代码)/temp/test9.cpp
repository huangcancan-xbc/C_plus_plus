#include <iostream>
using namespace std;

int test()
{
	// static 局部变量 = 生命周期全局，作用域局部
	static int x = 10;
	x += 10;

	return x;
}


int main()
{
	cout << test() << endl;
	//cout << x << endl;	// 无法访问，因为 x 是 static 局部变量，生命周期全局，作用域局部

	return 0;
}