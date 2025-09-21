# include <iostream>
using namespace std;
# include <string.h>

int main()
{ //声明二维数组的语法：数据类型 数组名[行数][列数]
    int a[2][3];
    // int bh[2][3] = { {11,12,13},{21,22,23} }; 初始化二维数组
  //利用嵌套的for处理二维数组
  for(int i=0; i<2; i++)
  {
    for(int j=0; j<3; j++)
    {
        a[i][j] = i+j;
        cout<<"a["<<i<<"]["<<j<<"]="<<a[i][j]<<endl;
        cout<<"&a["<<i<<"]["<<j<<"]="<<(long long)&a[i][j]<<endl;
    }
  }
    //int *p=a; //a是包含两个元素的一维数组，每个元素为长度为3的一维数组,当它作为右值出现在表达式里时，会衰变为指向首元素的指针
    int *p = (int *)a; //把整个二维数组当作一段连续的 int 内存来访问
    for(int i=0; i<6; i++)
    {
        cout<<"p["<<i<<"]="<<p[i]<<endl;
    }
  // 用memset()函数可以把二维数组中全部的元素清零。（只适用于C++基本数据类型）
  // 函数原型：void *memset(void *s, int c, size_t n);
    memset(a, 0, sizeof(a));
    for(int i=0; i<2; i++)
  {
    for(int j=0; j<3; j++)
    {
        cout<<"a["<<i<<"]["<<j<<"]="<<a[i][j]<<endl;
    }
  }
  // 用memcpy()函数可以把二维数组中全部的元素复制到另一个数组（没说多少维）。
  // 把一段连续内存里的内容，按字节复制到另一段连续内存 （只适用于C++基本数据类型）
  // memcpy(目标地址, 源地址, 拷贝字节长度);
  int bh[][3] = { 11,12,13,21,22,23 };
  int bh1[6] = {0};
  memcpy(bh1, bh, sizeof(bh));
  for(int l=0; l<6; l++){cout<<"bh1["<<l<<"]="<<bh1[l]<<endl;}
}