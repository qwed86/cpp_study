# include<iostream>
using namespace std;
int main()
{
    int i=6;
    int j=6;
    int a=++i; // 先自增1，再赋值
    int b=j++; // 先赋值，再自增1
    cout<<a<<endl; // 7
    cout<<b<<"\t"<<j<<endl; 

 int x = 3;
    int y = x++ + ++x;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    return 0;
}
