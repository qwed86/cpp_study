// 返回子串substr在目标串str中第一次出现的位置，如果找不到，返回0。
// BF算法，即暴力(Brute Force)算法。
// KMP（看毛片）算法是一种改进的字符串匹配算法，由D.E.Knuth，J.H.Morris和V.R.Pratt提出（简称KMP算法）。
// 示例：
#define _CRT_SECURE_NO_WARNINGS // 使用C风格字符串操作的函数需要定义这个宏
#include <iostream>
using namespace std;

// 返回子串substr在目标串str中第一次出现的位置，如果找不到，返回0。
const char *mystrstr(const char *str, const char *substr)
{
    int mark;
    for (int i = 0; str[i];)
    {
        if (str[i] == substr[0])
        {
            mark = i;
            int j = 0;
            while (str[i++] == substr[j++])
            {
                if (substr[j] == 0)
                {
                    return str + mark;
                }
            }
            i--;
        }
    }
    return 0;
}

int main()
{
    cout << mystrstr("aaaaa", "aab");
}