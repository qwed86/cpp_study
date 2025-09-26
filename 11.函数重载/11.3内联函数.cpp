#include <iostream>         // 包含头文件。
using namespace std;
/*
C++将内联函数的代码组合到程序中，可以提高程序运行的速度。
语法：在函数声明和定义前加上关键字inline。
通常的做法是将函数声明和定义写在一起。
注意：
	内联函数节省时间，但消耗内存。
	如果函数过大，编译器可能不将其作为内联函数。
	内联函数不能递归。
*/ 
inline void show(const short bh, const string message)   // 表白函数。
{
	cout << "亲爱的" << bh << "号：" << message << endl;
}

int main()
{
	show(3, "我是一只傻傻鸟。");
	// {
	// 	int bh = 3;
	// 	string message = "我是一只傻傻鸟。";
	// 	cout << "亲爱的" << bh << "号：" << message << endl;
	// }
	show(8, "我有一只小小鸟。");
	// {
	// 	int bh = 8;
	// 	string message = "我有一只小小鸟。";
	// 	cout << "亲爱的" << bh << "号：" << message << endl;
	// }
	 show(5, "我是一只小小鸟。");
	// {
	// 	int bh = 5;
	// 	string message = "我是一只小小鸟。";
	// 	cout << "亲爱的" << bh << "号：" << message << endl;
	// }
}
