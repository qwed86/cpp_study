#include <iostream>         // 包含头文件。
using namespace std;        // 指定缺省的命名空间。

int main()
{
	char a;      cout << "sizeof(char)=" <<  sizeof(char) << endl;            // 1字节
	short b;    cout << "sizeof(short)=" <<  sizeof(short) << endl;         // 2字节
	int c;         cout << "sizeof(int)=" << sizeof(int) << endl;                  // 4字节
	double d; cout << "sizeof(double)=" <<   sizeof(double) << endl;   // 8字节

	// 将指针变量（地址的值）加1后，增加的量等于它指向的数据类型的字节数。	
	cout << "a的地址是：" << (void *)&a << endl;  
	cout << "a的地址+1是：" << (void*)( &a + 1) << endl;

	cout << "b的地址是：" << (void*)&b << endl;
	cout << "b的地址+1是：" << (void*)(&b + 1) << endl;

	cout << "c的地址是：" << (void*)&c << endl;
	cout << "c的地址+1是：" << (void*)(&c + 1) << endl;

	cout << "d的地址是：" << (void*)&d << endl;
	cout << "d的地址+1是：" << (void*)(&d + 1) << endl;

    double e[5]={1,3.5,45,26.6,-0.5};
    cout<<"e的值是:"<<(long long)e<<endl;  //C++将数组名解释为数组第0个元素的地址
    cout<<"e[0]的地址是:"<<(long long)&e[0]<<endl;
    cout<<"e[1]的地址是:"<<(long long)&e[1]<<endl;
    cout<<"e[2]的地址是:"<<(long long)&e[2]<<endl;
    cout<<"e[3]的地址是:"<<(long long)&e[3]<<endl;
    cout<<"e[4]的地址是:"<<(long long)&e[4]<<endl<<endl;

    double *p=e;
    cout<<"p的值是:"<<(long long)p<<endl;
    cout<<"p+0的值是:"<<(long long)(p+0)<<endl;
    cout<<"p+1的值是:"<<(long long)(p+1)<<endl;//指针 + 1”不是把地址加 1 个字节，而是加 1 个“元素”，也就是跳过 sizeof(元素类型) 个字节。
    cout<<"p+2的值是:"<<(long long)(p+2)<<endl;
    cout<<"p+3的值是:"<<(long long)(p+3)<<endl;
    cout<<"p+4的值是:"<<(long long)(p+4)<<endl<<endl;

    cout<<"*(p+0)的值是:"<<*(p+0)<<endl;
    cout<<"*(p+1)的值是:"<<*(p+1)<<endl;
    cout<<"*(p+2)的值是:"<<*(p+2)<<endl;
    cout<<"*(p+3)的值是:"<<*(p+3)<<endl;
    cout<<"*(p+4)的值是:"<<*(p+4)<<endl;
// 总结：数组是占用连续空间的一块内存，数组名被解释为数组第0个元素的地址。
// C++操作这块内存有两种方法：数组解释法和指针表示法，它们是等价的。
}
