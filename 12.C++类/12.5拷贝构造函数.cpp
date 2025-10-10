#include <iostream>
using std::cout;
using std::endl;
using std::string;

class CGirl
{
public:
    string m_name;
    int m_age;
    // 没有参数的普通构造函数
    CGirl()
    {
        m_name.clear();
        m_age = 0;
        cout << "调用了CGirl()构造函数。\n";
    }
    // 没有重载的的拷贝构造函数
    // 拷贝构造函数的语法：
    // 类名(const 类名& 对象名){......}
    CGirl(const CGirl &gg)
    {
        m_name = "漂亮的" + gg.m_name;
        m_age = gg.m_age - 1;
        cout << "调用了CGirl(const CGirl& gg)构造函数。\n";
    }
    // 析构函数
    ~CGirl() { cout << "调用了~CGirl()\n"; }

    // 超女自我介绍方法，显示姓名和年龄
    void show() { cout << "姓名：" << m_name << "，年龄：" << m_age << endl; }
};

// 以值传递的方式调用函数时，如果实参为对象，会调用拷贝构造函数。
void func(CGirl g)
{g.show();}

CGirl func1()
{
    CGirl gg;
    gg.m_name="aili";gg.m_age=19;
    cout<<&gg;
    return gg;
}
int main()
{ /*
 用一个已存在的对象创建新的对象，不会调用（普通）构造函数，而是调用拷贝构造函数。
 如果类中没有定义拷贝构造函数，编译器将提供一个拷贝构造函数，它的功能是把已存在对象的成员变量赋值给新对象的成员变量。
 */
    // 用一个已存在的对象创建新的对象语法：
    // 类名 新对象名(已存在的对象名);
    // 类名 新对象名 = 已存在的对象名;
    // CGirl g1;
    // g1.m_age = 20;
    // g1.m_name = "西施";
    //CGirl g2 = g1;
    //g2.show();
    //func(g1);cout<<endl;

    CGirl g3=func1();//函数以值的方式返回对象时，可能会调用拷贝构造函数（VS会调用，Linux不会，g++编译器做了优化）。
    g3.show();cout<<&g3; //vscode没有调用拷贝构造函数，gg与g3地址相同
}