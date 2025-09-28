#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;

void jinzhi(char str[], int radix, int len)
{
    int i = 0, result = 0;
    if (radix == 10)
    {
        while (str[i] != 0)
        {
            if (!(str[i] >= '0' && str[i] <= '9'))
            {
                cout << "输入非法字符"<<endl;
                return;
            }
            result = 10 * result;
            result = result + (str[i] - '0');
            i++;
        }
    }
    else if (radix == 2)
    {
        while (len > 0)
        {
            if (!(str[len-1] == '0' || str[len-1] == '1'))
            {
                cout << "输入非法字符"<<endl;
                return;
            }
            result = result + (str[len - 1] - '0') * pow(2, len - 1);
            len--;
        }
    }

    cout << result << endl;
}

int main()
{
    char arr[31] = {0};
    int radix;
    cout << "输入要转化的C字符串：";
    cin >> arr;
    cout << "输入字符串内容的进制：";
    cin >> radix;
    jinzhi(arr, radix, strlen(arr));
}