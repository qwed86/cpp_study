#include <iostream>
using namespace std;
// 用静态成员变量可实现多个对象之间的数据共享，比全局变量更安全性。
class CGirl
{
public:
    string m_name;
    static int m_age;
    // 两个参数的普通构造函数
    CGirl(const string &name, int age)
    {
        m_name = name;
        m_age = age;
    }
    // 显示超女名字
    void showname() { cout << "姓名：" << m_name << endl; }
    // 显示超女年龄。
    static void showage() { cout << "年龄：" << m_age << endl; }
};

// 静态成员变量不会在创建对象的时候初始化，
// 必须在程序的全局区用代码清晰的初始化（用范围解析运算符 ::）。
int CGirl::m_age; // 缺省初始化为0

int main()
{
    cout << CGirl::m_age << endl; // 不初始化对象也可访问
    CGirl::showage();
    CGirl g1("西施1", 23);
    CGirl g2("西施2", 24);
    CGirl g3("西施3", 25);
    g1.showname();
    g1.showage();
    g2.showname();
    g2.showage();
    g3.showname();
    g3.showage(); // 年龄都是25，共享一个静态变量，最后一次赋值有效
    cout << CGirl::m_age << endl;
    CGirl::showage();
}