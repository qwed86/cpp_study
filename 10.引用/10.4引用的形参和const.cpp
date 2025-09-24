#include <iostream>         // 包含头文件。
using namespace std;        // 指定缺省的命名空间。

void func1(int no, string str)    // 传值。
{
	cout << "亲爱的" << no << "号：" << str << endl;
}

void func2(const int* no,const string* str)    // 传地址。
{
	cout << "亲爱的" << *no << "号：" << *str << endl;
}
// const除了防止修改实参还有其他功能：使用const使函数能够处理const和非const实参
void func3(const int& no, const string& str)    // 传引用。
{
	cout << "亲爱的" << no << "号：" << str << endl;
}

int main()
{
	
	//func1(bh, message);                  // 传值。
	//func2(&bh, &message);            // 传地址。
	func3('p', "515");                  // 传引用。

	//cout << "亲爱的" << bh << "号：" << message << endl;
}
