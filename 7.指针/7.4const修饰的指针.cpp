# include<iostream>
using namespace std;
//常量指针：指针指向可以改，指针指向的值不可以更改。

void func1(const int *no, const string *str) //一般用于修饰函数的形参，表示不希望在函数里修改内存地址中的值。
                                             //如果形参的值不需要改变，建议加上const修饰，程序可读性更好。
{  
    // *no =8;
    // *str="我有一只小鸟";  编译报错
    cout<<"亲爱的"<<*no<<"号超女:"<<*str<<endl;  
} 

int main()
{   // 语法：const 数据类型 *变量名;
    int a=10, b=20;
    const int* pa=&a;
    /*不能通过解引用的方法修改内存地址中的值（用原始的变量名是可以修改的）*/
    // *pa=8; 编译报错
    a=8;
    cout<<"a="<<a<<",*pa="<<*pa<<endl;
    pa=&b;
    cout<<"b="<<b<<",*pa="<<*pa<<endl;
    
}