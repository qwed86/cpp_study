#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    double arr[3][4];
    memset(arr, 0, sizeof(arr));
    double sum = 0, count = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << "输入第" << i + 1 << "组第" << j + 1 << "名超女体重：";
            cin >> arr[i][j];
            sum = sum + arr[i][j];
        }
        cout << "第" << i + 1 << "组平均体重：" << sum / 4 << endl;
        sum = 0;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            count = arr[i][j] + count;
        }
    }
    cout << "全体平均体重：" << count / 12 << endl;
}
