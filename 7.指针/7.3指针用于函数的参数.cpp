# include<iostream>
using namespace std;

void func1(int *no, string *str) //超女表白函数
{
    cout<<"亲爱的"<<*no<<"号超女:"<<*str<<endl;
    *no =8;
    *str="845654";
} 

// 传地址的意义如下：
// 可以在函数中修改实参的值。
// 减少内存拷贝，提升性能。

void func2(int a, int b, int c, int *max, int *min)
{
   *max= a>b? (a>c?a:c) : (b>c?b:c);
   *min= a<b? (a<c?a:c) : (b<c?b:c);
}

int main()
{
   int num=3;
   string bb="我是一只傻傻鸟"; 
   
   func1(&num, &bb);
   cout<<"亲爱的"<<num<<"号超女:"<<bb<<endl;  //num和bb的值被func1函数修改了

   int a=180,b=175,c=174,max,min;
   func2(a,b,c,&max,&min);
   cout<<"max="<<max<<" min="<<min<<endl;  // max和min的值被func2函数修改了,原来没赋值
} 

