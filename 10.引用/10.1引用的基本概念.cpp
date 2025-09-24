#include <iostream>
using namespace std;
// 引用是已定义的变量的别名。
// 引用的主要用途是用作函数的形参和返回值。

int main()
{
    // 声明/创建引用的语法：数据类型 &引用名=原变量名;
    int a = 9;
    int &ra = a;

    // 引用名和原变量名可以互换，它们值和内存单元是相同的。
    cout << "a的地址：" << &a << " a的值：" << a << endl;
    cout << "ra的地址：" << &ra << " ra的值：" << ra << endl;

    int b = 5;
    ra = b; // 必须在声明引用的时候初始化，初始化后不可改变,ra不会成为b的别名。

    cout << "b的地址：" << &b << " b的值：" << b << endl;
    cout << "a的地址：" << &a << " a的值：" << a << endl;
    cout << "ra的地址：" << &ra << " ra的值：" << ra << endl;
}