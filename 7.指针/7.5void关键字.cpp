# include<iostream>
using namespace std;

// 显示变量的十六进制地址的函数：varname-变量名，p-变量的地址。
// 用void *可以存放任意类型的地址。
void func(string varname, void* p)
{
	cout << varname<< "的地址是：" << p << endl;
	//cout << varname << "的值是：" << *p << endl; 不能对void *指针直接解引用（需要转换成其它类型的指针）。
    cout<< varname<<"的值是："<< *(char*)p<<endl;
}

int main()
{
    int  a=89;
	char b='X';
	
	cout << "a的地址是：" <<  & a << endl;
	cout << "b的地址是：" <<  & b << endl;

	func("a", &a);
	func("b", &b);


}