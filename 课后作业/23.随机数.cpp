#include <iostream>
using namespace std;
// 写一个函数，随机生成n个整数，不允许重复。
// size_t len数组长度 const int minvalue=0随机数最小值

void rrand(int arr[], const size_t len)
{
    arr[0] = rand() % 5;
    for (size_t i = 1; i < len; i++)
    {

        arr[i] = rand() % 5;
        size_t j = 0;
        while (j < i)
        {
            if (arr[i] == arr[j]) // 如果第i个随机数与前面第i-1，i-2,....个重复则重新生成并从头检查
            {
                while (arr[i] == arr[j]) // 保证当前两个相等的随机数不相等
                {
                    arr[i] = rand() % 5;
                }
                j = 0; //从头开始
            }
            else //不重复才进行下一个对比，千万要放到else内部
            {
                j++;
            }
        }
    }
}

int main()
{
    srand(time(0)); // 初始化随机数种子，得到不同的随机数，用tiem(0)作为种子
    // for(int i=0; i<10; i++)
    // {cout<<rand()<<endl;}

    // 生产0-20之间的随机数
    // for (int i = 0; i < 10; i++)
    // {
    //     cout << rand() % 20 << endl;
    // }

    // // 生产30-50之间的随机数
    // for (int i = 0; i < 10; i++)
    // {
    //     cout << rand() % 20 + 30 << endl;
    // }

    srand(time(0)); // ✅ 只调用一次
    const int N = 5;
    int arr[N];
    rrand(arr, N);

    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}