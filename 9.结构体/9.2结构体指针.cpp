#include <iostream> // 包含头文件。
#include <string.h>
using namespace std; // 指定缺省的命名空间。

struct st_girl
{
    char name[21]; // 姓名。
    int age;       // 年龄。
    double weight; // 体重（kg）。
    char sex;      // 性别：X-女；Y-男。
    bool yz;       // 颜值：true-漂亮；false-不漂亮。
};

void func(st_girl const *pst)
{
    cout << "5姓名：" << pst->name << "，年龄：" << pst->age << "，体重：" << pst->weight
         << "，性别：" << pst->sex << "，颜值：" << pst->yz << endl;
}

int main()
{
    st_girl stgirl = {"爱莉希雅", 17, 54.7, 'X', true};
    cout << "1姓名：" << stgirl.name << " age:" << stgirl.age << " weight:" << stgirl.weight
         << " gender:" << stgirl.sex << " appreance:" << stgirl.yz << endl;
    st_girl *pst = &stgirl;           // st_girl相当于数据类型
    st_girl *pst1 = new st_girl({0}); // 申请出来内存要初始化
    // 通过结构体指针访问结构体成员，有两种方法：
    //  (*指针名).成员变量名    // (*pst).name和(*pst).age
    // 或者：
    // 指针名->成员变量名    // pst->name和*pst->age
    cout << "2姓名：" << (*pst).name << " age:" << (*pst).age << " weight:" << (*pst).weight
         << " gender:" << (*pst).sex << " appreance:" << (*pst).yz << endl;

    cout << "3姓名：" << pst->name << " age:" << pst->age << " weight:" << pst->weight
         << " gender:" << pst->sex << " appreance:" << pst->yz << endl;
    cout << "4姓名：" << pst1->name << " age:" << pst1->age << " weight:" << pst1->weight
         << " gender:" << pst1->sex << " appreance:" << pst1->yz << endl;

    func(&stgirl);
}