#include <iostream>
using namespace std;

// 参数arr是待排序数组的首地址，len是数组元素的个数。
void insertsort(int arr[], int len)
{ //< ：不包括右边 → 次数 = 右边 - 起始值
    //<= ：包括右边 → 次数 = 右边 - 起始值 + 1
    for (int i = 1; i < len; i++) // 从第二个元素开始排序
    {                             // 先挪动位置，最后再排序
        int key = arr[i];
        int j = i - 1;
        while (arr[j] > key && j >= 0) // 向前扫描，找到比key大的元素就往后移一格
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

int main()
{ int arr[] = { 44,3,38,5,47,15,36,26,27,2,46,4,19,50,48 };   // 待排序的数组。
    int len = sizeof(arr) / sizeof(int);    // 求数组长度。

    insertsort(arr, len);    

    // 显示排序结果。
    for (int ii = 0; ii < len; ii++) cout << arr[ii] << " ";

    cout << endl;
}