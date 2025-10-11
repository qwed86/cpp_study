#include <iostream> // 包含头文件。
using std::cout;
using std::endl;
using std::string;
/*
初始化列表的语法：
类名(形参列表):成员一(值一), 成员二(值二),..., 成员n(值n)
{......}
*/
class CBoy // 男朋友类。
{
public:
    string m_xm; // 男朋友的姓名。
    CBoy()       // 没有参数的普通构造函数，默认构造函数。
    {
        m_xm.clear();
        cout << "调用了CBoy()构造函数。\n";
    }

    CBoy(string xm) // 有一个参数的普通构造函数。
    {
        m_xm = xm;
        cout << "调用了CBoy(string xm)构造函数。\n";
    }

    CBoy(const CBoy &bb) // 默认拷贝构造函数。
    {
        m_xm = bb.m_xm;
        cout << "调用了CBoy(const CBoy &bb)拷贝构造函数。\n";
    }
};

class CGirl
{
public:
    string m_name;
    int m_age;
    CBoy m_boy;                             // 男朋友的信息
    CGirl() : m_name("爱莉希雅"), m_age(17) // 没有参数的普通构造函数，默认构造函数
    {
        cout << "调用了CGirl()构造函数。\n";
    }
    // 初始化列表的括号中可以是具体的值，也可以是构造函数的形参名，还可以是表达式。
    CGirl(string name, int age, CBoy boy) : m_name(name), m_age(age), m_boy(boy) // 两个参数的构造函数
    {
        //m_boy.m_xm = boy.m_xm;
        cout << "调用了CGirl(string name, int age,CBoy boy)构造函数。\n";
    }
    // 超女自我介绍的方法，显示姓名和年龄。
    void show()
    {
        cout << "姓名：" << m_name << "，年龄：" << m_age << "，男朋友：" << m_boy.m_xm << endl;
    }
};

int main()
{
    CBoy b1("sdw");
    CGirl g1("爱莉希雅", 17, b1);
    g1.show();
}