#include <iostream>
#include <string.h>
#pragma pack(8)
using namespace std;
/*
struct 结构体名
{
成员一的数据类型  成员名一;
成员二的数据类型  成员名二;
成员三的数据类型  成员名三;
......
成员n的数据类型  成员名n;
};
*/
// 结构体（struct） 是一种可以把多个不同类型的数据“打包”在一起的复合类型。
// 定义结构体描述的代码可以放在程序的任何地方，一般放在main函数的上面或头文件中。
struct stu_girl
{
  char name[21] = "爱莉希雅";
  int age = 17;
  double weight = 54.8;
  char gender = 'X';
  bool appreance = -0.2;
};

int main()
{

  // 创建结构体变量
  stu_girl info_girl; // stu_girl是一种新的数据类型，不能当成变量使用但可以声明变量
  //   也可以为结构体成员赋初始值。
  // struct 结构体名 结构体变量名={成员一的值, 成员二的值,......, 成员n的值};

  // 如果大括号内未包含任何东西或只写一个0，全部的成员都将被设置为0。
  // struct 结构体名 结构体变量名={0};

  /*在C++程序中，用成员运算符（.）来访问结构体的每个成员。结构体中的每个成员具备普通变量的全部特征。
    语法：结构体变量名.结构体成员名 */

  cout << "姓名：" << info_girl.name << "，年龄：" << info_girl.age << ",体重：" << info_girl.weight << "kg(不许四舍五入)，"
       << "性别：" << info_girl.gender << "，颜值：" << info_girl.appreance << endl;

  cout << sizeof(info_girl) << endl; // 整个结构体占用内存的大小不一定等于全部成员占用内存之和。用内存对齐规则调整
  // 用memset()函数可以把结构体中全部的成员清零。（只适用于C++基本数据类型）
  memset(&info_girl, 0, sizeof(info_girl));
  cout << "姓名：" << info_girl.name << "，年龄：" << info_girl.age << ",体重：" << info_girl.weight << "kg(不许四舍五入)，"
       << "性别：" << info_girl.gender << "，颜值：" << info_girl.appreance << endl
       << endl;

  // 用memcpy()函数把结构体中全部的元素复制到另一个相同类型的结构体（只适用于C++基本数据类型）。
  // 也可以直接用等于号（只适用于C++基本数据类型）。
  stu_girl info_girl1;
  info_girl1 = info_girl;
  cout << "姓名：" << info_girl1.name << "，年龄：" << info_girl1.age << ",体重：" << info_girl1.weight << "kg(不许四舍五入)，"
       << "性别：" << info_girl1.gender << "，颜值：" << info_girl1.appreance << endl;
}
