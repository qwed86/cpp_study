# include<iostream>
using namespace std;
//函数重载（函数多态）是指设计一系列同名函数，让它们完成相同（似）的工作。
//C++允许定义名称相同的函数，条件是它们的特征（形参的个数、数据类型和排列顺序）不同。

void myswap(int& a, int& b) //交换两个整型的值
{
    int temp=a;a=b;b=temp;
}

void myswap(string& a, string& b) //交换两个字符串的值
{
    string temp=a;a=b;b=temp;
}

int main()
{   int a=5,b=98;
    myswap(a,b);
    cout << "a=" << a << ",b=" << b << endl;

    string c="dsv",d="dmk";
    cout << "c=" << c << ",d=" << d << endl;
}
//调用重载函数的时候，在代码中我们用相同的函数名，但是，后面的实参不一样，
//编译器根据实参与重载函数的形参进行匹配，然后决定调用具体的函数，如果匹配失败，编译器将视为错误。