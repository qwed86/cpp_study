/*
// 统计字符串的字数，汉字、全角的符号算一个字，字母、数字、半角的符号也算一个字。
int sumwords(const char* str);
一个字符的取值围是0-255。
ASCII码为标准符号、数字、英文等进行了保留，取值范围是0～127。
汉字用扩展ASCII码表示，取值范围是128～255，常用的16000个汉字以双字节为主，不常用的汉字可能使用3或4字节（甲骨文、战国时期各国的文字、不同版本的繁体字）。
本任务只考虑汉字是双字节的情况。*/

#define _CRT_SECURE_NO_WARNINGS // 使用C风格字符串操作的函数需要定义这个宏
#include <iostream>
#include <string.h>
using namespace std;

int sumwords(const char *str)
{
    int sum = 0;
    while (*str != 0)
    {
        if (0 <= (unsigned char)*str && (unsigned char)*str <= 127)
        {
            sum++;
            str++;
        }
        else if (128 <= (unsigned char)*str && (unsigned char)*str <= 255)
        {
            sum++;
            str = str + 3;
        }
    }
    return sum;
}

int main()
{ // char str1[] = "我是一只a傻傻鸟。";
    cout << strlen("我是一只a傻傻鸟。") << endl;
    //     cout << (int)(unsigned char)str1[0]  << endl;
    cout << sumwords("我是一只a傻傻鸟。") << endl;
}