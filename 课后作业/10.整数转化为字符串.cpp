#include <iostream>
#include <string.h>
using namespace std;
// 从界面上输入一个整数，把它转换为十进制和二进制的C风格的字符串。
// 整数 + '0'变为字符，字符 - '0'变为整数

void inverse1(char *arr, int len) // 思路二：直接交换字符串头尾数据到中间位置

{
    for (int i = 0; i < len / 2; i++)
    {
        char a;
        a = arr[len - i - 1];
        arr[len - i - 1] = arr[i];
        arr[i] = a;
    }
}

void ten(int a)
{
    int i = 0;
    char str[31] = {0};

    while ((10 * a) / 10 != 0)
    {
        str[i] = (a % 10) + '0';
        // cout << (a % 10);
        a = a / 10;
        i++;
    }

    inverse1(str, strlen(str));
    cout << str;
}
void two(int a)
{
    int i = 0;
    char str[31] = {0};

    while ((2 * a) / 2 != 0)
    {
        str[i] = (a % 2) + '0';
        // cout << (a % 10);
        a = a / 2;
        i++;
    }

    inverse1(str, strlen(str));
    cout << str;
}

int main()
{   int a;
    cout << "输入一个整数：";
    cin >> a;
    two(a);cout<<endl;
    ten(a);
}