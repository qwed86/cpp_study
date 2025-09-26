#include <iostream>  // 包含头文件。
using namespace std; // 指定缺省的命名空间。
/*
类的成员有三种访问权限：public、private和protected，分别表示公有的、私有的和受保护的。
在类的内部（类的成员函数中），无论成员被声明为 public还是private，都可以访问。
在类的外部（定义类的代码之外），只能访问public成员，不能访问 private、protected成员。
在一个类体的定义中，private 和 public 可以出现多次。
结构体的成员缺省为public，类的成员缺省为private。
private的意义在于隐藏类的数据和实现，把需要向外暴露的成员声明为public。
*/
class CGirl // 超女类CGirl。
{
public:
    string name; // 姓名。
private:
    int age;                               // 年龄。
    void setvalue(string name1, int age1); // 设置成员变量的值。
public:
    void show() // 显示超女的自我介绍。
    {
        cout << "姓名：" << name << "，年龄：" << age << endl;
    }
};

void CGirl::setvalue(string name1, int age1) // 设置成员变量的值。
{
    name = name1;
    age = age1;
}

int main()
{
    CGirl girl;                // 创建超女对象。
    //girl.setvalue("西施", 26); // 设置成员变量的值。
    girl.show();               // 显示超女的自我介绍。
}
