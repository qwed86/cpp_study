#include <iostream>  // 包含头文件。
using namespace std; // 指定缺省的命名空间。

// 超女宠物基本信息结构体st_pet
struct st_pet // 宠物结构体。
{
    char name[21]; // 宠物的名字。
    char type[21]; // 宠物的物种。
};

// 超女基本信息结构体st_girl，存放了超女全部的数据项。
struct st_girl
{
    char name[21]; // 姓名。
    int age;       // 年龄。
    double weight; // 体重（kg）。
    char sex;      // 性别：X-女；Y-男。
    bool yz;       // 颜值：true-漂亮；false-不漂亮。
    st_pet pet;
};

int main()
{
    // 赋值
    st_girl girl = {"aili", 25, 45.9, 'X', true, {"5531", "cat"}};
    // 赋值法二：
    girl = {"aili", 25, 45.9, 'X', true};
    girl.pet = {"5531", "cat"};
    cout << "姓名：" << girl.name << "的宠物是一只" << girl.pet.type
         << "，名字叫" << girl.pet.name << "。" << endl;
}