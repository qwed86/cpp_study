#include <iostream>
using std::cout;
using std::endl;
using std::string;

class CGirl
{
public:
    string m_name;
    int m_yz; // 颜值：1-沉鱼落雁；2-漂亮；3-一般；4-歪瓜裂枣。
    // 两个参数的普通构造函数。
    CGirl(const string &name, int yz)
    {
        m_name = name;
        m_yz = yz;
    }

    // 超女自我介绍的方法
    void show() const
    {
        cout << "我是：" << m_name << ",最漂亮超女。" << endl;
    }
    const CGirl &pk(const CGirl &g) const
    {
        if (g.m_yz < m_yz)
            return g;
        return* this;
    }
};

// const CGirl& pk(const CGirl& g1, const CGirl& g2)
// {
//     if (g1.m_yz < g2.m_yz)
//         return g1;
//     return g2;
// }

// this指针存放了对象的地址，它被作为隐藏参数传递给了成员函数，
// 指向调用成员函数的对象（谁调用了成员函数指向谁）。
int main()
{
    CGirl g1("西施", 4), g2("西瓜", 3), g3("东施", 2);
    // const CGirl& g = g2.pk(g1).pk(g3); //this指向g2
    // g.show();
    g2.pk(g1).pk(g3).show();
}