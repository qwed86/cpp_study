# include<iostream>
using namespace std;

// 5）函数内部用static修饰的是静态局部变量。


void func2();

int main()
{
  func2();
  func2();
  func2();
  
}


void func2()
{
   int a=10  ;      // a为局部变量，函数结束后a值被初始化
   static int b=10; // 用static修饰的局部变量生命周期和程序相同，并且只会被初始化一次。其作用域为局部，当定义它的函数或语句块结束时，其作用域随之结束。

   cout<<"func2 a="<<a++<<endl;
   cout<<"func2 b="<<b++<<endl;

}
// for循环初始化语句中定义的变量的作用域是for语句块。