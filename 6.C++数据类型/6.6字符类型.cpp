# include<iostream>
using namespace std;
int main()
{
// 字符型（char）占用的内存空间是1个字节，书写用单引号包含。
// 在内存中，不存放字符本身，而是存放与它对应的编码，即ASCII码。
char a='X';
cout<<"sizeof(a)="<<sizeof(a)<<endl;
cout<<"'X'对应的ASCII码:"<<(int)a<<endl;
// char本质是整数,取值0-127
int b=88;
cout<<"88对应的ASCII码:"<<(char)b<<endl;

//可以与整数进行任何运算，运算的时候，书写方式可以用字符，也可以用整数
cout<<(char)('X'+3);
}