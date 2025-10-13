#include <iostream>  // 包含头文件。
using namespace std; // 指定缺省的命名空间。

class CGirl // 超女类CGirl。
{
    // friend void func();
    friend class boy;

public:
    string m_name; // 姓名。
    // 默认构造函数。
    CGirl()
    {
        m_name = "西施";
        m_xw = 87;
    }
    // 显示姓名的成员函数。
    void showname() { cout << "姓名：" << m_name << endl; }

private:
    int m_xw; // 胸围。
    // 显示胸围的成员函数。
    void showxw() const { cout << "胸围：" << m_xw << endl; }
};

class boy
{
public:
    void func1(const CGirl &g) { cout << "1女朋友胸围是：" << g.m_xw << endl; }
    void func2(const CGirl &g) { cout << "2女朋友胸围是：" << g.m_xw << endl; }
};

// void func()
// {
//     CGirl g;
//     g.showname();
//     g.showxw(); // 将main()声明为class的友元函数才可以访问
// }
int main()
{
    CGirl g;
    boy b;
    b.func1(g);
}
