#define _CRT_SECURE_NO_WARNINGS // 使用C风格字符串操作的函数需要定义这个宏
#include <iostream>
using namespace std;

// 功能：比较str1和str2的大小。
// 返回值：相等返回0，str1大于str2返回1，str1小于str2返回 - 1；
int mystrcmp(const char *str1, const char *str2)
{
    while (1)
    {
        if (*str1 > *str2)
            return 1;
        if (*str1 < *str2)
            return -1;
        if (*str1 == 0 && *str2 == 0)
            return 0;
        str1++;
        str2++;
    }
}
// 功能：比较str1和str2前n个字符的大小。
// 返回值：相等返回0，str1大于str2返回1，str1小于str2返回 - 1；
int mystrncmp(const char *str1, const char *str2, const size_t n)
{
    size_t i = 0;
    while (i < n)
    {
        if (str1[i] > str2[i])
            return 1;
        if (str1[i] < str2[i])
            return -1;

        i++;
    }
        return 0;// 前面循环都跳出说明相等直接返回0
}

int main()
{
    cout << mystrncmp("123", "1245", 4);
}