#include <iostream>  // 包含头文件。
using namespace std; // 指定缺省的命名空间。

void func1(int no, string str) // 传值。
{
    no = 8;
    str = "我有一只小小鸟。";
    cout << "亲爱的" << no << "号：" << str << endl;
}

void func2(int *no, string *str) // 传地址。
{
    *no = 8;
    *str = "我有一只小小鸟。";
    cout << "亲爱的" << *no << "号：" << *str << endl;
}

void func3(int &no, string &str) // 传引用。
{
    no = 8;
    str = "我有一只小小鸟。";
    cout << "亲爱的" << no << "号：" << str << endl;
}


int main()
{
    int bh = 3;                          // 超女的编号。
    string message = "我是一只傻傻鸟。"; // 向超女表白的内容。

    //func1(bh, message);                 // 传值：无法改变实参。
    // func2(&bh, &message);            // 传地址: 修改了实参。
     func3(bh, message);                  // 传引用: 修改了实参

    cout << "亲爱的" << bh << "号：" << message << endl;
}
