#include <iostream>         // 包含头文件。
using namespace std;        // 指定缺省的命名空间。

int main()
{
    // 字符型（char）占用的内存空间是1个字节，书写用单引号包含。
    char a = '\'';
    cout << "a=" << a << endl;

    // 换行符 ASCII值是10  书写用\n
    cout << "我是一'只傻傻鸟！\n";

    // 水平制表符用于对齐输出的内容。
    cout << "1\t西施\n";
    cout << "100\t西瓜\n";
    cout << "10000\t冰冰\n";
}
