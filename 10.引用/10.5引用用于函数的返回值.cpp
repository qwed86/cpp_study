#include <iostream>
using namespace std;

// 如果返回引用不会拷贝内存。
// 返回值的数据类型& 函数名(形参列表);
int func1()
{
    int i = 4;
    return i;
}

int &func2()  //返回的是引用
{
    static int  i = 4;
    return i;
}
int &func3(int &ra)
{
    ra++;
    cout<<"ra地址："<<&ra<<"ra="<<ra<<endl;
    return ra;
}

int main()
{
    int a = func1();  cout << "a=" << a << endl;
    int &b = func2(); cout << "b=" << b << endl;// 如果返回局部变量的引用，其本质是野指针，后果不可预知
    int c=5;
    int &d=func3(c);
    cout<<"c地址："<<&c<<"c="<<c<<endl;
    cout<<"d地址："<<&d<<"d="<<c<<endl;

}