#include <iostream>
using namespace std;
// 枚举是一种创建常量的方法,是整型常量
int main()
{
    enum colors // 默认赋值0，1，2...
    {
        red,
        blue,
        yellow,
        white,
        black
    };
    colors cc = red;
    colors dd = colors(1);
        cout << "red=" << red << "blue=" << blue << "yellow=" << yellow << "white=" << white << "black=" << black << endl;

    switch (dd)
    {
    case red:
        cout << "红色";
        break;
    case blue:
        cout << "蓝色";
        break;
    case yellow:
        cout << yellow;
        break;
    case white:
        cout << white;
        break;
    case black:
        cout << black;
        break;

    default:
        cout << "unknow";
        break;
    }
}
