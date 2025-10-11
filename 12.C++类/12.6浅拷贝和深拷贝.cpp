#include <iostream>         // 包含头文件。
using namespace std;        // 指定缺省的命名空间。

class CGirl                 // 超女类CGirl。
{
public:
    string    m_name;                                  // 姓名属性。
    int         m_age;                                     // 年龄属性。
    int*       m_ptr;                                       // 指针成员，计划使用堆内存。

    // 没有参数的普通构造函数。  
    CGirl() { m_name.clear(); m_age = 0;  m_ptr = nullptr;  cout << "调用了CGirl()构造函数。\n"; }

    // 没有重载的拷贝构造函数（默认拷贝构造函数）。  
    CGirl(const CGirl& gg) //深拷贝：新分配一块内存，让原本内存中的数据复制过去
    { 
        m_name = gg.m_name; m_age = gg.m_age;  
        m_ptr = new int;         // 分配内存。
        // *m_ptr = *gg.m_ptr;   // 拷贝数据。
        memcpy(m_ptr, gg.m_ptr, sizeof(int));   // 拷贝数据。
        cout << "调用了CGirl(const CGirl &gg)拷贝构造函数。\n"; 
    }
    // CGirl(const CGirl& gg) //浅拷贝
    // { 
    //     m_name = gg.m_name; m_age = gg.m_age;  
    //     m_ptr = gg.m_ptr;
    //     cout << "调用了CGirl(const CGirl &gg)拷贝构造函数。\n"; 
    // }

    // 析构函数。  
    ~CGirl() { delete m_ptr; m_ptr = nullptr; cout << "调用了~CGirl()\n";  }

    // 超女自我介绍的方法，显示姓名和年龄。
    void show() { cout << "姓名：" << m_name << "，年龄：" << m_age << "，m_ptr="<< m_ptr<<"，*m_ptr="<<*m_ptr<<endl; }
};

int main()
{
    CGirl g1;
    g1.m_name = "西施"; g1.m_age = 23; g1.m_ptr = new int(3);
    g1.show();

    CGirl g2(g1);  *g2.m_ptr = 8; //内存出现了变化
    g1.show();
    g2.show();
}
