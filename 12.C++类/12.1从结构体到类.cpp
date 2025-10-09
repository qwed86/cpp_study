#include <iostream>  // 包含头文件。
using namespace std; // 指定缺省的命名空间。

class Girl // 结构体就是类
{
public: // 类的访问权限
    string name;    // 姓名。
    int age;        // 年龄。
    int height;     // 身高（cm）。
    double weight;  // 体重（kg）。
    char sex = 'X'; // 性别：X-女；Y-男。
    int yz;         // 颜值：1-漂亮；2-一般；3-歪瓜裂枣。
    string special; // 特长。
    string memo;    // 备注。

    // 结构体成员函数可以直接访问成员变量，无需传参
    void setvalue(string name1, int age1)
    {
        name = name1;
        age = age1;
    }
    void show() // 不需要修改实参的值且实参是较大的结构，则使用const指针或const引用。
    {
        cout << "姓名：" << name << "，年龄：" << age << endl;
    }
    
};

int main()
{
    Girl girl; //用类创建一个/实例化一个对象girl
    girl.setvalue("西施", 26);
    girl.show();
}