#include <iostream>
#include <string.h>
using namespace std;

// 功能：将src字符串拼接到dest所指的字符串尾部。
// 返回值：返回dest字符串起始地址。
// dest最后原有的结尾字符0会被覆盖掉，并在连接后的字符串的尾部再增加一个0。
// 如果参数dest所指的内存空间不够大，会导致数组的越界。

char *mystrcat(char *dest, const char *src)
{
    char *pdest = dest;
    char *psrc = (char *)src;
    while (*pdest) // 让指针pdest指向字符串末尾0
    {
        pdest++;
    }
    while (*psrc)
    {
        *pdest++ = *psrc++; // 此时pdest已经指向末尾0可以直接赋值
    }
    *(pdest) = 0;
    return dest;
}
// 功能：将src字符串的前n个字符拼接到dest所指的字符串尾部。
// 返回值：返回dest字符串的起始地址。
// 如果n大于等于字符串src的长度，那么将src全部追加到dest的尾部。
// 如果n小于字符串src的长度，只追加src的前n个字符。
// strncat会将dest字符串最后的0覆盖掉，字符追加完成后，再追加0。
// 如果参数dest所指的内存空间不够大，会导致数组的越界。

char *mystrncat(char* dest, const char* src, const size_t n)
{ // 利用memcpy实现
    size_t len = strlen(dest);
    memcpy((dest + len), src, n);
    *(dest + len+n)=0;
    return dest;
}

int main()
{
    char dest[21] = "爱莉希雅";
    mystrncat(dest, "1234",5);
    cout << dest << endl;
}