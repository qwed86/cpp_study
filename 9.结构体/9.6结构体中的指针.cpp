#include <iostream> // 包含头文件。
#include <string.h>
using namespace std; // 指定缺省的命名空间。

struct st_t
{
    int a;
    int *p;
};

int main()
{
    st_t stt;                     // 创建结构体变量。
    memset(&stt, 0, sizeof(stt)); // 没有动态分配内存之前可以清空
    stt.a = 10;
    stt.p = new int[100]; // 动态创建一个长度为100的整型数组，让指针stt.p指向数组的地址。
    cout << "sizeof(stt)=" << sizeof(stt) << endl;
    cout << "调用前：stt.a=" << stt.a << ",stt.p=" << stt.p << endl;
    // memset(&stt, 0,sizeof(stt));
    stt.a = 0;
    memset(stt.p, 0, sizeof(int) * 100);
    cout << "调用后：stt.a=" << stt.a << ",stt.p=" << stt.p << endl;
    delete[] stt.p;
}