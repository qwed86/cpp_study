#include <iostream>
using namespace std;
/*
1）用一个while循环，接受从键盘输入的整数，如果输入的整数不在1到100之间（包括1和100），认为无效，丢弃；
   如果输入的整数在1到100之间，则把每次输入的值累加起来；如果输入的整数为0，跳出循环。最后，显示有效数据的个数和总和。
2）输出1到100之间（包括1和100）的能整除5的数字。
*/

int main()
{
    int i = 0, sum = 0, count = 0, j = 1;
    while (1)
    {
        cout << "请输入整数：";
        cin >> i;
        if (i >= 1 && i <= 100)
        {
            sum = i + sum;
            count++;
        }
        else if (i == 0)
        {
            cout << "有效数据个数：" << count << " 总和" << sum<<endl;
            break;
        }
    }
    while (j <= 100)
    {
        if (j % 5 == 0)
        {
            cout << j << " ";
        }
        j++;
    }
}
