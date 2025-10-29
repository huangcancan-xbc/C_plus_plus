// 无参无值的回调函数：
#include <iostream>
using namespace std;

// 无参无值的回调函数
void print()
{
	cout << "Hello, world!" << endl;
}

void test(int x, void (*callback)())
{
	for (int i = 0; i < x; i++)
	{
		callback();
	}
}

int main()
{
	test(3, print);

	// 输出：
	//Hello, world!
	//Hello, world!
	//Hello, world!

	return 0;
}