#include <iostream>
#include <string.h>
using namespace std;

class CGirl
{
public:
    int m_bh;       // 编号属性
    char m_name[3]; // 姓名属性
    static int m_age;

    // 默认构造函数和析构函数。
    CGirl()
    {
        memset(m_name, 0, sizeof(m_name));
        m_age = 0;
    }
    ~CGirl() {}
    // 显示超女的姓名。
    void showname()
    {
       // if (this == nullptr)
            //return;
        cout << "姓名：" <<" m_name" << endl;
    }
    // 显示超女的年龄。
    void showage() { cout << "年龄：" << m_age << endl; }
};
int CGirl::m_age;
int a;
void func() {}
int main()
{
    CGirl g;
    cout << "对象g占用内存大小：" << sizeof(g) << endl;
    cout << "成员变量m_bh的地址：" << &g.m_bh << endl;
    cout << "成员变量m_name的地址：" << &g.m_name << endl;
    // 下面两个地址连续
    cout << "静态成员变量m_age的地址：" << &g.m_age << endl;
    cout << "全局变量a的地址：" << &a << endl;

    // 下面三个地址是一起的
    printf("成员函数showname的地址是：%p\n", &CGirl::showname);
    printf("成员函数showage的地址是：%p\n", &CGirl::showage);
    printf("函数func()的地址是：%p\n", func);

    // 用空指针可以调用没有用到this指针的非静态成员函数。
    CGirl *g1 = nullptr;
    g1->showname();

    // 对象的地址是第一个非静态成员变量的地址，如果类中没有非静态成员变量，编译器会隐含的增加一个1字节的占位成员。
    cout<<"对象g地址为："<<&g<<endl;
    cout << "成员变量m_bh的地址：" << &g.m_bh << endl;
}