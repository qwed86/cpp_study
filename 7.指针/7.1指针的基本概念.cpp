# include <iostream>
using namespace std;

int main()
{
   // 获取变量在内存中起始地址：&变量名
   int a;
   char b;
   bool c;
   string d;
   // cout<<"变量a的地址为："<<&a<<endl;
   // cout<<"变量b的地址为："<<&b<<endl; // cout有bug会用字符串显示地址
   // cout<<"变量c的地址为："<<&c<<endl;
   // cout<<"变量d的地址为："<<&d<<endl<<endl;

   // cout<<"变量a的地址为："<<&a<<endl;
   // cout<<"变量b的地址为："<<(void*)&b<<endl; // 用void*强制转换
   // cout<<"变量c的地址为："<<&c<<endl;
   // cout<<"变量d的地址为："<<&d<<endl<<endl;

   // 可转化为整数显示
   cout<<"变量a的地址为："<<(long long)&a<<endl;
   cout<<"变量b的地址为："<<(long long)&b<<endl; // 转化为long long类型
   cout<<"变量c的地址为："<<(long long)&c<<endl;
   cout<<"变量d的地址为："<<(long long)&d<<endl;

   // 指针变量简称指针，用于存放变量的起始地址
   // 声明指针变量：数据类型 *指针变量名;
   // 对指针变量赋值：指针变量名 = &变量名;

   int *pa = &a; // pa是一个指向a的指针变量
   char *pb = &b;
   bool *pc = &c;
   string *pd= &d;
   cout<<"变量a的地址为："<<(long long)pa<<endl;
   cout<<"变量b的地址为："<<(long long)pb<<endl; 
   cout<<"变量c的地址为："<<(long long)pc<<endl;
   cout<<"变量d的地址为："<<(long long)pd<<endl;

   // 64位系统中，所有指针变量的长度都是8个字节
   cout<<"指针变量pa的长度为："<<sizeof(pa)<<endl;
   cout<<"指向int的指针int *的长度为："<<sizeof(int *)<<endl;
   // 指针是复合数据类型：基于其他数据类型而定义的数据类型
   // 例如：int *、char *、bool *、string *,把他们当作一种数据类型
  
}