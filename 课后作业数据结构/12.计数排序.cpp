#include <iostream>
using std::cout;
using std::endl;

void countsort(int arr[], int len)
{
    int MinIndex = 0, MaxIndex = 0;
    for (int i = 0; i < len; i++)
    {
        if (arr[i] < arr[MinIndex])
            MinIndex = i;
        if (arr[i] > arr[MaxIndex])
            MaxIndex = i;
    }

    int minVal = arr[MinIndex];
    int maxVal = arr[MaxIndex];
    int range = maxVal - minVal + 1;

    int tmp[range] = {0};

    //  统计每个值的出现次数（要减去最小值）否则越界：
    //如果数组为100，101，102，103...其中101对应第101-100=1个元素，要减去偏移量
    for (int i = 0; i < len; i++)
        tmp[arr[i] - minVal]++; 

    //  正确的输出逻辑（去掉多余的 k）
    int j = 0;
    for (int i = 0; i < range; i++)
    {
        while (tmp[i] > 0)
        {
            arr[j] = i + minVal;
            tmp[i]--;
            j++;
        }
    }
}

int main()
{
    int arr[20] = {2, 3, 8, 7, 1, 2, 2, 2, 7, 3, 9, 8, 2, 1, 4, 2, 4, 6, 9, 2};
    int len = sizeof(arr) / sizeof(int);

    countsort(arr, len);

    for (int i = 0; i < len; i++)
        cout << arr[i] << " ";
    cout << endl;
}
