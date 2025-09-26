#include <iostream>
#include <string.h>
using namespace std;
/*
在界面上输入数字的月份（1-12）,输出对应月份的英文单词的全称，如果输入的数字不合法，给出提示。
其它要求：
1）用if … else if …实现;
2）用switch实现
3）用字符串数组（C风格和C++风格）实现。
*/
int main()
{
    string months[12] = {"January", "February", "March", "April", "May", "June",
                         "July", "Auhust", "September", "October", "November", "December"};
    char Months[12][10] = {"January", "February", "March", "April", "May", "June",
                           "July", "Auhust", "September", "OCtober", "November", "December"}; // 二维数组存放

    int num;
    cout << "输入月份的数字：";
    cin >> num;
    if (num > 12 || num < 1)
    {
        cout << "超过范围" << endl;
    }
    else
    {
        cout << months[num - 1] << endl;
        cout << Months[num - 1] << endl;
    }
}