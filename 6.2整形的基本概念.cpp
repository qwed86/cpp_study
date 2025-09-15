# include<iostream>
using namespace std;

int main()
{
    cout<<"sizeof(short)="<<sizeof(short)<<endl;
    cout<<"sizeof(unsigned short)="<<sizeof(unsigned short)<<endl;
    cout<<"sizeof(int)="<<sizeof(int)<<endl;
    cout<<"sizeof(unsigned int)="<<sizeof(unsigned int)<<endl;
    cout<<"sizeof(long)="<<sizeof(long)<<endl;
    cout<<"sizeof(unsigned long)="<<sizeof(unsigned long)<<endl;
}
//一个字节有8个位，表示的数据的取值范围是2^8-1，即255
//如果占用的内存是两个字节，无符号型取值范围是2^8*2^8-1
//如果是有符号，取值范围减半，因为符号占一个位。
//计算机用最高位1位来表达符号（0-正数，1-负数），
//unsigned修饰过的正整数不需要符号位，在表达正整数的时候比signed修饰的正整数取值大一倍。
