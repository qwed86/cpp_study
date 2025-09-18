# include<iostream>
using namespace std;

int main()
{
    int *p=nullptr; //空指针定义
    cout<<"p="<<p<<" *p="<<*p<<endl; //p=0 如果对空指针解引用，程序会崩溃。
}