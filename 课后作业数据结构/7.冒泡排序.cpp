#include <iostream>
using namespace std;

void Bubblesort(int arr[], int len)
{
    if (len < 2)
        return;
    bool ifswap;
    int turn = 0, n = 0; // 记录排序轮次，每轮次数
    for (int i = len - 1; i > 0; i--)
    {
        ifswap = false;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                n++;
                ifswap = true;
            }
        }
        turn++;
        if (ifswap == false)
        {
            cout << "排序提前完成：turn=" << turn << " n=" << n << endl;
            return;
        } // 如果本轮没有交换说明已经排序完成
    }
    cout << "turn=" << turn << " n=" << n;
}

// 打印数组函数
void PrintArray(int arr[], int len)
{
    cout << "[";
    for (int i = 0; i < len; i++)
        cout << arr[i] << " ";
    cout << "]" << endl;
}

int main()
{
    int arr[] = {8, 7, 6, 5, 4, 3, 2, 1};
    int len = sizeof(arr) / sizeof(arr[0]);

    cout << "排序前数组：";
    PrintArray(arr, len);

    Bubblesort(arr, len);

    cout << "排序后数组：";
    PrintArray(arr, len);

    return 0;
}