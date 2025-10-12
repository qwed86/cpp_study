#include <iostream>  // 包含头文件。
using namespace std; // 指定缺省的命名空间。

class CGirl // 超女类CGirl。
{
public:
    mutable string m_name; // 姓名属性。void show1() const中可修改m_name的值
    int m_age;             // 年龄属性。

    // 两个参数的普通构造函数。
    CGirl(const string &name, int age) 
    {
        m_name = name;
        m_age = age;
        cout << "调用了CGirl(name,age)构造函数。\n";
    }

    // 超女自我介绍的方法，显示姓名、年龄。
    void show1() const
    {
        m_name = "西施show1"; // 想要赋值需要mutable
        cout << "姓名：" << m_name << "，年龄：" << m_age << endl;
    }
    void show2() const
    {
        m_name = "西施show2";
        cout << "姓名：" << m_name << "，年龄：" << m_age << endl;
    }
    void show3()
    {
        m_name = "西施show3";
        cout << "姓名：" << m_name << "，年龄：" << m_age << endl;
        show2();
    }
    void show4()
    {
        m_name = "西施show4";
        cout << "姓名：" << m_name << "，年龄：" << m_age << endl;
    }
};

int main()
{
    const CGirl g1("冰冰", 18); //const修饰的对象只能调用const修饰的成员函数，不能调用非cosnt修饰的成员函数。

    //g1.show3();无法调用非const修饰的show3()
    g1.show2();
}
