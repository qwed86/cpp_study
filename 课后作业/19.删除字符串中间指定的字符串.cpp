#define _CRT_SECURE_NO_WARNINGS // 使用C风格字符串操作的函数需要定义这个宏
#include <iostream>
#include <string.h>
using namespace std;

// 删除字符串中间的字符串。
// aaxyzaa/0  aaaa
// aaxyxyzzaa   aaxyzaa   aaaa 需要多次删除xyz用while循环

// 返回子串substr在目标串str中第一次出现的位置，如果找不到，返回0。
void deletestr(char *str, const char *substr)
{
    int slen = strlen(substr);
    int len = strlen(str);
    while (1)
    {
        if (str == 0 || substr == 0)
            return;
        char *p = strstr(str, substr);
        if (p == 0) // 目标串是否包含子串
            return; 
        // 用substr后面的内容覆盖substr位置
        memmove(p, p + slen, len - (p - str) - slen + 1);
    }
}

int main()
{
    char str[] = "124545454521";
    deletestr(str, "45");
    cout << str;
}