#include <iostream>
using namespace std;

void rrand(int arr[], const size_t len, const size_t min, const size_t max)
{
    srand(time(0));
    arr[0] = min + rand() % (max - min + 1);
    for (size_t i = 1; i < len; i++)
    {

        arr[i] = min + rand() % (max - min + 1);
        size_t j = 0;
        while (j < i)
        {
            if (arr[i] == arr[j]) // 如果第i个随机数与前面第i-1，i-2,....个重复则重新生成并从头检查
            {
                while (arr[i] == arr[j]) // 保证当前两个相等的随机数不相等
                {
                    arr[i] = min + rand() % (max - min + 1);
                }
                j = 0; // 从头开始
            }
            else // 不重复才进行下一个对比，千万要放到else内部
            {
                j++;
            }
        }
    }
}

void dealcards(int arr[][13])
{
    int tmp[52] = {0}, j = 0; //将牌打乱随机顺序存放于数组中
    rrand(tmp, 52, 1, 52);
    // 13轮发牌，每轮次按数组tmp顺序抽4张牌发给4个玩家即可
    for (int i = 0; i < 13; i++)
    {
        
        arr[0][i] = tmp[j++];
        arr[1][i] = tmp[j++];
        arr[2][i] = tmp[j++];
        arr[3][i] = tmp[j++];
    }
}

int main()
{
    int arr[4][13] = {0};
    dealcards(arr);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            cout << "arr[" << i << "]=" << arr[i][j] << " ";
        }
        cout << endl;
    }
}