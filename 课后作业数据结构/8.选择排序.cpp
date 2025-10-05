#include <iostream>
using namespace std;

void ChooseSort(int arr[], int len)
{
    if (len < 2)
        return;
    int MinIndex, MaxIndex;
    int turn = 0, n = 0; // 记录排序轮次，每轮交换次数

    for (int i = 0; i < len / 2; i++)
    {
        MinIndex = i;
        MaxIndex = i;

        // 一趟同时找到最小值和最大值
        for (int j = i + 1; j < len - i; j++)
        {
            if (arr[j] < arr[MinIndex])
                MinIndex = j;
            if (arr[j] > arr[MaxIndex])
                MaxIndex = j;
        }

        // 交换最小值到前面
        if (MinIndex != i)
        {
            swap(arr[i], arr[MinIndex]);
            n++;
            // 若最大值原本在i处，被交换走了
            if (MaxIndex == i)
                MaxIndex = MinIndex;
        }

        // 交换最大值到后面
        if (MaxIndex != len - i - 1)
        {
            swap(arr[len - i - 1], arr[MaxIndex]);
            n++;
        }
        turn++;
    }

    cout << "turn=" << turn << " n=" << n << endl;
}

void PrintArray(int arr[], int len)
{
    cout << "[";
    for (int i = 0; i < len; i++)
        cout << arr[i] << " ";
    cout << "]" << endl;
}

int main()
{
    int arr[] = {1, 5, 3, 4, 50, 6};
    int len = sizeof(arr) / sizeof(arr[0]);

    cout << "排序前数组：";
    PrintArray(arr, len);

    ChooseSort(arr, len);

    cout << "排序后数组：";
    PrintArray(arr, len);

    return 0;
}
