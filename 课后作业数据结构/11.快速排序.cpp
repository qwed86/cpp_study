#include <iostream>
using std::cout;
using std::endl;

// 先写一次快排分出左右两组再分别递归调用自己
void QuickSort(int arr[], int len)
{
    if (len < 2)
        return;         // 数组长度小于2无需排序
    int pivot = arr[0]; // 基准值
    int left = 0;
    int right = len - 1;

    while (left < right)
    {

        while ((left < right) && (arr[right] >= pivot))
        {
            right--; // 有可能直接right被减到right<left,加上(left < right)
        }
        if (arr[right] < pivot)
        {
            arr[left] = arr[right]; left++;
        }

        while ((left < right) && (arr[left] <= pivot))
        {
            left++;
        }
        if (arr[left] > pivot)
        {
            arr[right] = arr[left]; right--;
        }
    }
    arr[left] = pivot;
    QuickSort(arr, left);
    QuickSort(arr + left + 1, len - left - 1);
}

int main()
{
    int test1[] = {6, 3, 7, 2, 8, 1, 5, 4};
    QuickSort(test1, 8);
    for (int i = 0; i < 8; i++)
    {
        cout << test1[i] << " ";
    }
}
