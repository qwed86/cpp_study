#include <iostream>
#include <string.h>
using namespace std;

// 结构体数组创建流程：
// 1️⃣ 定义结构体类型
// 2️⃣ 声明数组：struct 结构体类型 数组名[数组长度];
// 3️⃣ 初始化 / 访问

// 超女基本信息结构体st_girl，存放了超女全部的数据项。
struct st_girl
{
    char name[21]; // 姓名。
    int age;       // 年龄。
    double weight; // 体重（kg）。
    char sex;      // 性别：X-女；Y-男。
    bool yz;       // 颜值：true-漂亮；false-不漂亮。
};

int main()
{
    st_girl girls[3];                // 声明
    memset(girls, 0, sizeof(girls)); // 清空数组
    strcpy(girls[0].name, "西施");
    girls[0].age = 17;
    girls[0].weight = 54.7;
    girls[0].sex = 'X';
    girls[0].yz = 1;
    // 一次性赋值 c++11
    girls[1] = {"西瓜", 25, 56, 'X', 0};
    girls[2] = {"哈密瓜", 24, 51, 'Y', 0};

    for (int i = 0; i < 3; i++)
    {
        cout << "姓名：" << girls[i].name << "age:" << girls[i].age << "weight:"
             << girls[i].weight << "gender:" << girls[i].sex << "颜值：" << girls[i].yz << endl;
        
    }

}
