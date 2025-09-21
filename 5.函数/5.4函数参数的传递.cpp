#include <iostream>         // 包含头文件。
using namespace std;        // 指定缺省的命名空间。

// 调用函数的时候，调用者把数值赋给了函数的参数。
// 实参：调用者程序中书写的在函数名括号中的参数，可以是常量、变量和表达式。
// 形参：函数的参数列表。
// 在函数定义的代码中，修改形参的值，会不会影响实参？ 答：不会影响实参的值

void func1(int no, string str);

int main()
{
   int num=3;
   string bb="我是一只傻傻鸟"; 
   func1(num, bb);
   cout<<"亲爱的"<<num<<"号超女:"<<bb<<endl; //发现func1输出为5，"2123e" ，cout输出为3，"我是一只傻傻鸟"
}

void func1(int no, string str)
{
    no=5;
    str="2123e";
    cout<<"亲爱的"<<no<<"号超女:"<<str<<endl;
}

// 函数调用过程：先声明形参变量再把实参赋值给形参，再之后执行函数体中代码
// {
//     int no=num;
//     string str =bb;

//     no =5;
//     str ="2123e";
//     cout<<"亲爱的"<<no<<"号超女:"<<str<<endl;
// }