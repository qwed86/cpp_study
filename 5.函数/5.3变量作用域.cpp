# include<iostream>
using namespace std;
// 1）在全部函数(包括main函数)外面定义的是全局变量。
// 2）在头文件中定义的是全局变量。
// 3）在函数和语句块内部定义的是局部变量。
// 4）函数的参数是该函数的局部变量。
// 5）函数内部用static修饰的是静态局部变量。
int aa;
void func1(int b);
void func2();

int main()
{
 aa=10;
 func1(23); //函数的参数是该函数的局部变量。
 func2();
 cout<<"main aa="<<aa<<endl;
  //  b=20; b在func1定义属于参数为局部变量
}

void func1(int b)
{   b=30;
    int xx=10; //在函数和语句块内部定义的是局部变量。局部变量在函数返回或语句块结束时由系统收回内存空间
    cout<<"xx="<<xx<<endl;
    cout<<"func1 aa="<<aa++<<endl;
}
void func2()
{
    cout<<"func2 aa="<<aa++<<endl;
}
