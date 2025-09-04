# include<iostream>
using namespace std;
int main()
{
    int a, b;
    a=10, b=20;
    cout<<b<<endl, cout<<a<<endl;
    // 逗号运算是从左到右依次计算各个表达式，运算级别最低。
    int c,d;
    d=c=2, c*2;
    cout<<d<<endl;
    d=(c=2, c*2); // d=4
    cout<<d<<endl;
    return 0;
}