#include <iostream>         // 包含头文件。
using namespace std;        // 指定缺省的命名空间。

int main()
{
    // 使用转义的方法
    string path = "C:\\Program Files\\Microsoft OneDrive\\tail\\nation";
    cout << "path is " << path << endl;
    // c++11原始字面量方法 语法：R"(字符串的内容)"
    string path2 = R"(D:\RivaTuner Statistics Server\Profiles)";
    cout << "path2 is " << path2 << endl;

    string str = R"(
        <no>0001</no>
        <name>西施</name>
        <sc>火树银花</sc>
        <yz>沉鱼</yz>
        <age>23</age>
        <weight>48.5</weight>
        <height>170</height>)";
    // 原始字面量方法加上后可以对字符串换行

}
