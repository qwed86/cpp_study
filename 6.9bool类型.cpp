#include <iostream>         // 包含头文件。
using namespace std;        // 指定缺省的命名空间。

int main()
{
	bool b = 1;

	cout << "b+b=" << b+b << endl;       // 将显示2。
	
	// 如果对bool型变量赋非0的值，将转换成1。
	b = 30;
	cout << "b=" << b << endl;                 // 将显示1。

	// 找到布尔变量b的内存，把里面的数据强制为8。
	char* c = (char *) & b; 
	*c = 255;
	cout << "b=" << b << endl;                 // 将显示8。
}
// bool类型本质上是1字节的整数（unsigned char），取值只有1和0。
// 在程序中，书写的时候可以用true和false，编译器把它们解释为1和0。
// 如果对bool型变量赋非0的值，将转换成1。
// 用cin输入和cout输出的时候，仍是1和0，不会被解释为true和false。
