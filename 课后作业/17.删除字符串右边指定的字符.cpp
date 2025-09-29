// "abcyxyxy"   	"abc"
// "西施  "   	"西施"
// 方法二：遍历1次字符串，写1次内存。
// 方法一：遍历1-2次字符串（调用strlen()函数算一次），写n次内存。
// 示例：
#define _CRT_SECURE_NO_WARNINGS // 使用C风格字符串操作的函数需要定义这个宏
#include <iostream>
#include <string.h>
using namespace std;

// 删除字符串右边指定的连续字符。方法一
void deleterchr(char *str, const int cc = ' ')
{
    if (str == 0)
        return; // 如果传进来的是空地址，直接返回，防止程序崩溃。

    char *p = str;   // 指向字符串的首地址。
    char *piscc = 0; // 右边全是字符cc的第一个位置。

    while (*p != 0) // 遍历字符串。
    {
        if (*p == cc && piscc == 0)
            piscc = p; // 记下字符cc的第一个位置。
        if (*p != cc)
            piscc = 0; // 只要当前字符不是cc，清空piscc。
        p++;
    }
    if (piscc != 0)
        *piscc = 0;
}
int main()
{
    char str[] = "12340000";
    deleterchr(str, '0');
    cout << str;
}
