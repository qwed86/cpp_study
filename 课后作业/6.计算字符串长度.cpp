#include <iostream>
using namespace std;
#include <string.h>
/*从界面上输入一个字符串（C风格），计算字符串的长度。如果输入的是"abcde"，显示的结果是5。
其它要求：
1）把计算字符串长度的功能封装成一个函数。
2）采用for循环，用数组表示法和临时变量计数。
3）采用while循环，用指针表示法和临时变量计数。
4）不用临时变量计数，用递归实现（奇巧淫技）。
*/
// int count(const char arr[])
// {
//     int len = 0;
//     for (int i = 0; arr[i] != 0; i++) // c风格字符串以空字符结尾对应十进制0
//     {
//         len++;
//     }
//     return len;
// }
int count1(char arr[])
{
    int len = 0;
    while (*arr != 0)
    {
        arr++; // 指针+1 不是把地址加 1 个字节，而是加 1 个“元素”
        len++;
    }
    return len;
}

int count3(char* p)
{
    if (*p==0) return 0;
    p++;
    int len ; 
    return len= count3(p)+1; // 递归调用自己，递归每增加一层，字符串长度加1。
}

int main()
{
    char arr1[51];
    memset(arr1, 0, sizeof(arr1));
    cout << "输入字符串：" << endl;
    cin >> arr1;
    // cout << count(arr1);
    cout << count1(arr1);
}