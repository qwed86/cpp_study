#include <iostream>  // 包含头文件。
using namespace std; // 指定缺省的命名空间。

// 超女基本信息结构体st_girl，存放了超女全部的数据项。
struct st_girl
{
    char name[21]; // 姓名。
    int score[2][3] = {11, 12, 13, 21, 22, 23};
    ;              // 存放评委的打分。
    int age;       // 年龄。
    double weight; // 体重（kg）。
    char sex;      // 性别：X-女；Y-男。
    bool yz;       // 颜值：true-漂亮；false-不漂亮。
};

void func(st_girl *pst)
{
    for (int ii = 0; ii < 2; ii++)
        for (int jj = 0; jj < 3; jj++)
            cout << "pst->score[" << ii << "][" << jj << "]=" << pst->score[ii][jj] << endl;
}

int main()
{
    st_girl girl;
    func(&girl);

    // for (int i = 0; i < 3; i++)
    //     girl.score[i] = 100 + i;
    // for (int i = 0; i < 3; i++)
    //     cout << "girl.score[" << i << "]=" << girl.score[i] << endl;
}