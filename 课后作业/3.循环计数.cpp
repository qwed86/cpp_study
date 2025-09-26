#include <iostream>
using namespace std;
// 用一个while循环，把1到100之间的数值累加起来
// for循环把用户每次从键盘输入的值加起来，总和超过5000退出循环
int main()
{
    int i = 0, sum = 0;
    while (i <= 100)
    {
        sum = sum + i;
        i++;
    }
    cout << "1+2+3+...+100=" << sum << endl;

    double count = 0;

    for (double j = 0; count <= 5000;)
    {
        cout << "请输入数字:";
        cin >> j;
        count = j + count;
        cout << "count=" << count << endl;
    }
}