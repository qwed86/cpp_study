# include<iostream>
using namespace std;
// 使用函数指针的三个步骤：
    // a）声明函数指针；
    // b）让函数指针指向函数的地址；
    // c）通过函数指针调用函数。

void zs(int a) //张三的个性化表白函数
{
  cout<<a<<"翻跟头表白"<<endl;
}

void ls(int a) //李四的个性化表白函数
{
  cout<<a<<"跳舞表白"<<endl;
}

void show(void(*pf)(int)) //回调函数无参数列表
{  int c=2;
  cout<<"准备工作"<<endl;
  pf(c); //通过函数指针调用函数。调用函数的时候声明函数指针
  cout<<"收尾工作"<<endl;
}

int main()
{
   show(ls); //传入个性化表白函数名就可以
             //传入时相当于令 pf=ls
}