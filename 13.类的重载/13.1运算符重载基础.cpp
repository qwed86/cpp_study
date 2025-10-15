#include <iostream>
using namespace std;

class CGirl
{
    friend CGirl &operator+(CGirl &g, int score);

private:
    int m_xw;    // 胸围
    int m_score; // 分数
public:
    string m_name; // 姓名
    // 默认构造函数。
    CGirl()
    {
        m_name = "西施";
        m_xw = 87;
        m_score = 30;
    }
    void show() { cout << "姓名：" << m_name << ", 胸围：" << m_xw << ", 评分：" << m_score << endl; }
   
};

CGirl &operator+(CGirl &g, int score)
{
    g.m_score += score;
    return g;
}

int main()
{
    // 导演的要求：每轮表演后，给超女加上得分
    CGirl g;
    // operator+(g, 15);
    g = g + 100 + 1 + 1 + 2; //重载函数参数列表中的顺序决定了操作数的位置。
   // g=10+g; 会报错，因为参数先(CGirl &g, int score)

    g.show();
}