/*
从界面上输入一个C风格的字符串，如果输入的是"abc"，反转后"cba"。
要求：
1）反转的结果存放在另一字符串中。
2）原地反转，不借助其它的字符串。
*/
#include <iostream>
#include <string.h>
using namespace std;

void inverse(char *p, int len)
{
    char *p1 = new char[31];      // 申请内存暂存原数组
    for (int i = 0; i < len; i++) // 把原数组先搬入新内存中
    {
        *(p1 + i) = *(p + i);
    }
    for (int i = len - 1, j = 0; i >= 0; i--, j++) // 将新内存数组逆序读取再赋予原数组中
    {
        *(p + j) = *(p1 + i);
    }
}

void inverse1(char *arr, int len) // 思路二：直接交换字符串头尾数据到中间位置
{
    for (int i = 0; i < len / 2; i++)
    {
        char a;
        a = arr[len-i-1];
        arr[len-i-1] = arr[i];
        arr[i] = a;
    }
}

int main()
{

    char str[31], arr[31];
    memset(str, 0, sizeof(str));
    memset(arr, 0, sizeof(arr));
    cout << "输入字符串:";
    cin >> str;
    int len = strlen(str);
    for (int i = len - 1, j = 0; i >= 0; i--, j++)
    {
        arr[j] = str[i];
    }
    // inverse(str, len);
    inverse1(str, len);
    //cout << "arr=" << arr << endl;
    cout << "str=" << str;
}
