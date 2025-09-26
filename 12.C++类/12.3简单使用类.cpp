#include <iostream>  // 包含头文件。
using namespace std; // 指定缺省的命名空间。
// 用结构体描述纯粹的数据，用类描述对象。
class CGirl // 超女类CGirl。
{
public:
    string name;                          // 姓名
    int age;                              // 年龄。
    int sex=20;

    enum {girl=1, boy=2};
    void setvalue(string name1, int age1) // 设置成员变量的值。
    {
        name = name1;
        age = age1;
    }
    void show() // 显示超女的自我介绍。
    {
        cout << "姓名：" << name << "，年龄：" << age << endl;
        //show();可以递归
        
    }
};

int main()
{
    CGirl girl;                // (实例化)创建超女对象。
    girl.setvalue("西施", 26); // 设置成员变量的值。
    girl.show(); // 显示超女的自我介绍。
    girl.sex=girl.boy;
    //在类的外部，一般不直接访问（读和写）对象的成员，而是用成员函数。数据隐藏是面向对象编程的思想之一。
}
