#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace chrono;

// 希尔排序
void groupsort(int arr[], int len, int num, int step)
{
    for (int i = step + num; i < len; i += step)
    {
        int key = arr[i];
        int j = i - step;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + step] = arr[j];
            j -= step;
        }
        arr[j + step] = key;
    }
}

void shellsort(int arr[], unsigned int len)
{
    for (int step = len / 2; step > 0; step /= 2)
    {
        for (int num = 0; num < step; num++)
        {
            groupsort(arr, len, num, step);
        }
    }
}

int main()
{
    const int N = 1000000; // 一百万个元素
    vector<int> data(N);
    srand(time(0));
    for (int i = 0; i < N; ++i) data[i] = rand();

    // 测试希尔排序
    vector<int> data_shell = data;
    auto t1 = high_resolution_clock::now();
    shellsort(data_shell.data(), data_shell.size());
    auto t2 = high_resolution_clock::now();
    cout << "Shell sort time: " << duration_cast<milliseconds>(t2 - t1).count() << " ms\n";

    // 测试内置排序
    vector<int> data_std = data;
    auto t3 = high_resolution_clock::now();
    sort(data_std.begin(), data_std.end());
    auto t4 = high_resolution_clock::now();
    cout << "std::sort time: " << duration_cast<milliseconds>(t4 - t3).count() << " ms\n";

    return 0;
}
