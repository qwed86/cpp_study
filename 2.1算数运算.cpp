# include<iostream>
using namespace std;
int main()
{
    int a=7,b=4;
    cout<<a/(double)b<<endl;
    double c=6;
    cout<<c/b<<endl;
    int x= a+b+c;
    cout<<x<<endl;  
    cout<<a;
} 
// % 取模运算符只能用于整数，/ 除法运算符可以用于整数和浮点数
// int 声明a=7.5时，a=7