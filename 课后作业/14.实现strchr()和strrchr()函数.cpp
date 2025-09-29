#define _CRT_SECURE_NO_WARNINGS // 使用C风格字符串操作的函数需要定义这个宏
#include <iostream>
#include <string.h>
using namespace std;

// 返回在字符串s中第一次出现c的位置，如果找不到，返回0。
// babcddefae    a
const char *mystrchr(const char *s, int c)
{
    while (*s != 0)
    {
        if (*s == c)
        {
            return s;
        }
        s++;
    }

    return 0;
}

int main()
{
    cout << mystrchr("94185156", '0');
}
