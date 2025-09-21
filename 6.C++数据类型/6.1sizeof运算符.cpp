// sizeof运算符用于求数据类型或变量占用的内存空间。
// 用于数据类型：sizeof(数据类型)
// 用于变量：sizeof(变量名) 或 sizeof 变量名
#include <typeinfo>
# include<iostream>
using namespace std;

int main()
{   // 用于数据类型：sizeof(数据类型)
    cout<<"sizeof(int)="<<sizeof(int)<<endl;
    cout<<"sizeof(float)="<<sizeof(float)<<endl;
    cout<<"sizeof(double)="<<sizeof(double)<<endl;
    cout<<"sizeof(char)="<<sizeof(char)<<endl;
    // cout<<"sizeof(string)="<<sizeof(string)<<endl;
    cout<<"sizeof(bool)="<<sizeof(bool)<<endl;

    int i; cout<<"sizeof(i)="<<sizeof(i)<<endl; //用于变量：sizeof(变量名) 或 sizeof 变量名
    cout<<"sizeof(5.1)="<<sizeof(5.1)<<endl;
    cout<< typeid(5.1).name() << endl;
}
