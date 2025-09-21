#include <iostream>         // 包含头文件。
using namespace std;        // 指定缺省的命名空间。

int f(int x)                            // 递归函数。
{
	if (x == 0) return 0;        // 递归终止的条件。

	return x + f(x - 1);          // 在函数体中调用了自己。
}

int main()
{
	cout << "f(10)=" << f(10) << endl;
	// 100+99+98+....+1+0          
	// 嵌套的调用函数  进入函数的过程是递去  函数返回的过程是归来

	// 计算从1加到100的和。
	int sum = 0;         //  存放累加的值。
	for (int i = 1; i <= 10; i++)
		sum = sum + i;

	cout << "sum=" << sum << endl;
}
