#include <iostream>  // 包含头文件。
using namespace std; // 指定缺省的命名空间。
/*特殊的成员函数
构造函数：在创建对象时，自动的进行初始化工作。
语法：主类名(){...}
析构函数：在销毁对象前，自动的完成清理工作。
语法：~主类名(){...}
	没有参数，不能重载。
	销毁对象前只会自动调用一次，但是可以手工调用。

*/
class CGirl // 超女类CGirl。
{
public:
    string name;                          // 姓名
    int age;                              // 年龄。
    CGirl() //构造函数名必须与类名相同
    {name.clear(); name="西施"; age=20;
    cout<<"调用了CGirl构造函数"<<endl;}
    ~CGirl()
    {cout<<"调用了析构函数"<<endl;}
    enum {girl=1, boy=2};
    void setvalue(string name1, int age1) // 设置成员变量的值。
    {name = name1;age = age1;}
    void show() // 显示超女的自我介绍。
    {cout << "姓名：" << name << "，年龄：" << age << endl;}
};

int main()
{
    CGirl girl;                // (实例化)创建超女对象。
    //girl.setvalue("西施", 26); // 设置成员变量的值。
    girl.show(); // 显示超女的自我介绍。
}
    
