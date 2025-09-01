# include <iostream>
using namespace std;
# define MONTH 12 //不可有分号
# define PI 3.14 
const double E=2.71828182845904523536; //const修饰的常量在任何地方可以定义,有分号
int main()
{
    cout<<"一年有"<<MONTH<<"个月"<<endl;
    cout<<"圆周率是"<<PI<<endl;
    //PI=2 //常量不可以修改
    const int year=2025;
    cout<<"今年是"<<year<<endl;
    //year=2024; //const修饰的变量不可以修改
    cout<<E*PI<<"\n"<<E/PI<<endl;
   
}