# include<iostream>
using namespace std;
int main()
{
// 使用堆区的内存有四个步骤：
// 1）声明一个指针；
// 2）用new运算符向系统申请一块内存，让指针指向这块内存；
// 3）通过对指针解引用的方法，像使用变量一样使用这块内存；
// 4）如果这块内存不用了，用delete运算符释放它。

// 申请内存的语法：new 数据类型(初始值); 
// 释放内存的语法：delete 地址;

int *p= new int{6};

cout << "*p=" << *p <<endl;

*p=7;

cout << "*p=" << *p <<endl;

delete p;  // 不释放内存后果很严重


}