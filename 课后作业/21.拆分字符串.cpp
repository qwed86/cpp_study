#define _CRT_SECURE_NO_WARNINGS // 使用C风格字符串操作的函数需要定义这个宏
#include <iostream>
using namespace std;
#include <string.h>
// 字符串"aa,bb,cc,dd"，中间用逗号分隔，把它拆分到字符串维数组中，拆分后有4个数据项，分别是  "aa"、"bb"、"cc"、"dd"
//  str：目标串，需要拆分的字符串。
//  splitstr：分隔符字符串。
//  values：拆分后的结果存放的字符串数组。

#include <iostream>
#include <cstring>
using namespace std;

size_t splitstr(const char *str, const char *splitstr, char values[][51])
{
    if (str == nullptr || splitstr == nullptr)
        return 0;

    size_t count = 0;
    int sublen = 0;
    const char *start = str; // 记录子串的起始位置

    while (*str != '\0')
    {
        if (*str == *splitstr)
        {
            if (sublen > 0)
            {
                // 拷贝当前子串到 values[count]
                memcpy(values[count], start, sublen);
                values[count][sublen] = '\0'; // 添加字符串结束符
                count++;
            }
            start = str + 1; // 此时str指向分隔符，+1让start指向下一个子串的开始位置
            sublen = 0;      // 重置子串长度
        }
        else
        {
            sublen++; // 当前子串的长度加1
        }
        str++;
    }

    // *str != '\0'到字符串末尾跳出循环，额外补上最后一个substr
    if (sublen > 0)
    {
        memcpy(values[count], start, sublen);
        values[count][sublen] = '\0';
        count++;
    }

    return count;
}

int main()
{
    char values[10][51] = {0};
    size_t count = splitstr("aa,bsb,cc,dd,faf", ",", values);

    // 输出拆分后的结果
    for (size_t i = 0; i < count; i++)
    {
        cout << "values[" << i << "] = " << values[i] << endl;
    }

    return 0;
}
