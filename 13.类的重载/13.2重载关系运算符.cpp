#include <iostream>
using namespace std;

class CGirl
{
    string m_name;
    int m_yz;
    int m_sc;
    int m_acting;

public:
    // 四个参数的构造函数
    CGirl(string name, int yz, int acting, int sc)
    {
        m_name = name;
        m_yz = yz, m_acting = acting;
        m_sc = sc;
    }
    // 关系运算符重载
    bool operator==(const CGirl &g)
    {
        if ((m_sc + m_yz + m_acting) == (g.m_yz + g.m_acting + g.m_sc))
            return true;
        return false;
    }
    bool operator>(const CGirl &g)
    {
        if ((m_sc + m_yz + m_acting) < (g.m_yz + g.m_acting + g.m_sc))
            return true;
        return false;
    }
    bool operator<(const CGirl &g)
    {
        if ((m_sc + m_yz + m_acting) > (g.m_yz + g.m_acting + g.m_sc))
            return true;
        return false;
    }
};

int main()
{
    CGirl g1("vdv", 1, 2, 3), g2("爱莉希雅", 1, 1, 1);
    if (g1 == g2)
    {
        cout << "商业价值相同" << endl;
    }
    if (g1 > g2)
    {
        cout << "vdv商业价值大" << endl;
    }
    if (g1 < g2)
    {
        cout << "爱莉希雅商业价值大" << endl;
    }
}