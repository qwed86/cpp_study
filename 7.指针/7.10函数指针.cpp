# include<iostream>
using namespace std;

void func(int no, string str)
{
  cout<<"dear"<<no<<"号:"<<str<<endl;
}

int main()
{
    int bh=3;
    string message = "我是一只小小鸟";
    func(bh,message); //普通调用函数

    // 用函数指针调用：
    // 使用函数指针的三个步骤：
    // a）声明函数指针；
    // b）让函数指针指向函数的地址；
    // c）通过函数指针调用函数。
    void (*pfunc)(int, string); //a)
    pfunc = func;               //b) 对函数指针赋值，语法是函数指针名=函数
    pfunc(bh, message);         //c) 用函数指针名调用函数。
}