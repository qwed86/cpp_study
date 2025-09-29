// #define _CRT_SECURE_NO_WARNINGS  // 使用C风格字符串操作的函数需要定义这个宏
#include <iostream>
#include <string.h>
using namespace std;

// 功 能 : 将参数src字符串拷贝至参数dest所指的地址。
// 返回值 : 返回参数dest的字符串起始地址。
// 复制完字符串后，会在dest后追加0。
// 如果参数dest所指的内存空间不够大，会导致数组的越界。

char *mystrcpy1(char *dest, const char *src)
{
    int len = 0;
    for (int i = 0; src[i] != 0; i++, len++)
    {
        dest[i] = src[i];
    }
    dest[len + 1] = 0;
    return dest;
}

// 功能：把src前n个字符的内容复制到dest中。
// 返回值：dest字符串起始地址。
// 如果src字符串长度小于n，则拷贝完字符串后，在dest后追加0，直到n个。
// 如果src的长度大于等于n，就截取src的前n个字符，不会在dest后追加0。
// 如果参数dest所指的内存空间不够大，会导致数组的越界。
char *mystrncpy(char *dest, const char *src, const size_t n)
{
    size_t i = 0;
    for (; i < n && src[i] != '\0'; i++)
    {
        dest[i] = src[i];   // 正常拷贝
    }
    dest[n]=0;
    // 如果 src 提前结束，剩下的补 0
    for (; i < n; i++)
    {
        dest[i] = '\0';
    }
    return dest;
}


int main()
{
    char str[100] = "hello", arr[100] ;
    // cout<<arr<<endl;
    // mystrcpy1(arr, str);
    mystrncpy(arr, "111111111111111", 3);
    cout << arr << endl;
   
}