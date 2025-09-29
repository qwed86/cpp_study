#define _CRT_SECURE_NO_WARNINGS // 使用C风格字符串操作的函数需要定义这个宏
#include <iostream>
#include <string.h>
using namespace std;

// 删除字符串左边指定的连续字符。
void deletelchr(char *str, const int cc = ' ')
{
    if (str == 0)
        return;    // 如果传进来的是空地址，直接返回，防止程序崩溃。
    char *p = str; // 指向字符串的首地址。
    while (*p == cc) //循环终止p指向第一个不是cc的位置
    {
        p++;
    }

    memmove(str, p, strlen(str) - (p - str) + 1);
}
int main()
{
    char str[] = "000012340000";
    deletelchr(str, '0');
    cout << str;
}