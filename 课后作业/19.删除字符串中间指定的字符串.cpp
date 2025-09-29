#define _CRT_SECURE_NO_WARNINGS // 使用C风格字符串操作的函数需要定义这个宏
#include <iostream>
#include <string.h>
using namespace std;

// 删除字符串中间的字符串。
// aaxyzaa  aaaa
// aaxyxyzzaa   aaxyzaa   aaaa

// 返回子串substr在目标串str中第一次出现的位置，如果找不到，返回0。
void deletestr(char *str, const char *substr)
{
    if (str == 0)
        return;
    char *p = strstr(str, substr);
    int len =strlen(substr);
    memmove(p,str+len,);
}

int main()
{
    char str[] = "000012340000";
    deletestr(str, "1234");
    cout << str;
}