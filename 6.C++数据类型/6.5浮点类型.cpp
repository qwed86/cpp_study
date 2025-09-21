#include <stdio.h>           // 使用printf函数需要包含这个头文件。
#include <iostream>         // 包含头文件。
using namespace std;        // 指定缺省的命名空间。


int main()
{ 
  cout<<"sizeof(float)="<<sizeof(float)<<endl;
  cout<<"sizeof(double)="<<sizeof(double)<<endl;
  cout<<"sizeof(long double)="<<sizeof(long double)<<endl;

  // float 7位有效数字；double 15～16位有效数字；long double	不低于double
    float aa = 1234.45f;    cout << "aa=" << aa << endl;
    double bb = 12345123056789.45;    cout << "bb=" << bb << endl;
    long double cc = 12345126789.459;    cout << "cc=" << cc << endl;

    printf("aa=%lf\n", aa);
    printf("bb=%lf\n", bb);
    printf("cc=%lf\n", cc);

    //在实际开发中，用整数代替浮点数，整数的运算更快，精度更高。
}

