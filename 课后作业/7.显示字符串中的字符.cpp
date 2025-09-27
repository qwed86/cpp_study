/*
从界面上输入一个字符串（C风格），把字符串中的每个字符显示出来，如果输入的是"abc"，要求：
1）正序显示：a b c
2）逆序显示：c b a
求字符串的长度可以利用上一题的成果，也可以直接用strlen()函数，关注性能的细节。
*/
#include <iostream>
#include <string.h>
using namespace std;
void print(char* arr)
{

    while (*arr != 0)
    {
        cout << *(arr) << " ";
        arr++;
    }
    cout << endl;
}

void in_print(char* arr, int len)
{
    while (len > 0)
    {
        cout << *(arr + len - 1) << " ";
        len--;
    }
}
int main()
{
    char str[101];
    memset(str, 0, sizeof(str));
    cout << "输入字符串：" << endl;
    cin >> str;
    print(str);

    int len = strlen(str);
    in_print(str, len);
}
