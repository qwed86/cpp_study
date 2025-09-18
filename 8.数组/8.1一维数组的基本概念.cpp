# include<iostream>
using namespace std;
// 数据类型 数组名[数组长度];
int main()
{
    int num[3];
    string name[3];
    // 可以通过下标访问数组中元素，数组下标从0开始。
    // 数组中每个元素的特征和使用方法与单个变量完全相同。
    num[0] = 8;
    num[1] = 256;
    num[2] = 485;
    cout<<"num[0]="<<num[0]<<endl;
    cout<<"num[1]="<<num[1]<<endl;
    cout<<"num[2]="<<num[2]<<endl;
    cout<<num[3]<<endl;

}