#include <iostream>
#include <string.h>
using namespace std;
// 增加3个函数：初始化分配数组、销毁时释放数组、扩展数组空间
// 修改插入元素函数：如果空间不够，扩展数组空间
#define INTSIZE 5 // 顺序表的初始大小
#define EXTSIZE 3 // 每次扩展元素的个数

typedef int ElemType; // 给数据元素的数据类型起个别名。

struct SeqList // 静态顺序表的结构体：数据结构
{
    ElemType *data;       // 用静态数组存储顺序表中的元素。
    unsigned int maxsize; // 顺序表的当前容量
    size_t length;        // 顺序表的表长（有效元素的个数）。
};

// 首先清空顺序表： 算法
void ClearList(SeqList &LL)
{
    LL.length = 0;                                     // 表长置为0。
    memset(LL.data, 0, sizeof(ElemType) * LL.maxsize); // 清空数组。
                                                       // memset(&LL, 0, sizeof(SeqList));	// 清空结构体,会把指针清空。
}

// 初始化顺序表
void InitList(SeqList &LL)
{
    LL.maxsize = INTSIZE;               // 指定顺序表的容量为缺省值。
    LL.data = new ElemType[LL.maxsize]; // 给数组分配内存空间。
    ClearList(LL);                      // 清空顺序表。
}

// 销毁顺序表LL。
void DestroyList(SeqList &LL)
{
    delete[] LL.data;  // 释放数组的内存空间。
    LL.data = nullptr; // 指针置空。
    LL.maxsize = 0;    // 顺序表的容量置为0。
    LL.length = 0;     // 顺序表的表长置为0。
}

// 扩展顺序表的内存空间，返回值：false-失败；true-成功。
bool ExtList(SeqList &LL)
{
    // 分配新的内存空间。
    ElemType *newdata = new (std::nothrow) ElemType[LL.maxsize + EXTSIZE];

    // 如果分配失败，返回0。
    if (newdata == nullptr)
        return false;

    // 把新分配的内存清空。
    memset(newdata, 0, sizeof(ElemType) * (LL.maxsize + EXTSIZE));

    // 把顺序表中原来的内容复制到新分配的内存空间中。
    memcpy(newdata, LL.data, sizeof(ElemType) * LL.length);

    // 释放原来的内存空间。
    delete[] LL.data;

    // 把顺序表数据元素的指针指向新分配的内存空间。
    LL.data = newdata;

    // 重置顺序表的maxsize变量。
    LL.maxsize = LL.maxsize + EXTSIZE;

    return true;
}

// 在顺序表LL的第pos个位置插入元素ee，返回值：true-成功；false-失败。
// 注意：在数据结构中，位置pos从1开始，不是从0开始。
//  6   8   2   1 12   4   5   3   7              // 顺序表中的元素。
//  1   2   3   4   5   6   7   8   9  10       // 位置。
//  0   1   2   3   4   5   6   7   8    9       // 数组下标。
bool InsertList(SeqList &LL, const size_t pos, const ElemType &ee)
{ // 如果空间不够了，就扩展内存空间。
    if (LL.length == LL.maxsize)
    {
        if (ExtList(LL) == false)
        {
            cout << "护展顺序表失败。\n";
            return false;
        }
    }

    if (LL.length == LL.maxsize)
    {
        cout << "顺序表已满，不能插入。\n";
        return false;
    }

    // 判断位置pos是否合法。
    if ((pos < 1) || (pos > LL.length + 1))
    {
        cout << "插入位置" << pos << "不合法，应该在1-" << LL.length + 1 << "之间。\n";
        return false;
    }

    // 把pos和pos之后的元素后移。
    if (pos < LL.length + 1)
        memmove(LL.data + pos, LL.data + pos - 1, (LL.length - pos + 1) * sizeof(ElemType));

    // 把元素ee的值赋值给顺序表的第pos个元素。
    memcpy(&LL.data[pos - 1], &ee, sizeof(ElemType)); // 采用memcpy是为了兼容ee为结构体的情况。
    // LL.data[pos - 1] = ee; // 在C++中，结构体也可以用=赋值。

    LL.length++; // 表长加1。

    return true;
}

// 求顺序表的表长，返回值表LL中元素的个数。
size_t LengthList(const SeqList &LL)
{
    return LL.length;
}

// 获取顺序表中第pos个元素的值，存放在ee中，返回值：false-失败；true-成功。
bool GetElem(const SeqList LL, const size_t pos, ElemType &ee)
{
    // 判断位置pos是否合法。
    if ((pos < 1) || (pos > LL.length))
        return false;

    ee = LL.data[pos - 1];

    return true;
}

// 在顺序表LL的头部插入元素ee。
bool PushFront(SeqList &LL, const ElemType &ee)
{
    return InsertList(LL, 1, ee);
}

// 在顺序表LL的尾部插入元素ee。
bool PushBack(SeqList &LL, const ElemType &ee)
{
    return InsertList(LL, LL.length + 1, ee);
}

// 查找ee在顺序表LL中的位置，返回值：0-元素ee在表LL中不存在，>0元素ee在表LL中的位置。
size_t FindElem(const SeqList &LL, const ElemType &ee)
{
    for (size_t ii = 0; ii < LL.length; ii++)
    {
        // 如果元素ee为结构体，以下代码要修改（比较数据元素的关键字）。
        if (LL.data[ii] == ee)
            return ii + 1;
    }

    return 0;
}

// 删除顺序表LL中的第pos个元素，返回值：0-位置pos不合法；1-成功。
bool DeleteElem(SeqList &LL, const size_t pos)
{
    // 判断位置pos是否合法，注意，pos从1开始，不是从0开始，0不符合人类的习惯。
    if ((pos < 1) || (pos > LL.length))
    {
        cout << "删除位置" << pos << "不合法，应该在1-" << LL.length << "之间。\n";
        return false;
    }

    // 把pos之后的元素前移。
    memmove(&LL.data[pos - 1], &LL.data[pos], sizeof(ElemType) * (LL.length - pos));

    LL.length--; // 表长减1。

    return true;
}

// 删除顺序表LL中头元素。
bool PopFront(SeqList &LL)
{
    return DeleteElem(LL, 1);
}

// 删除顺序表LL中尾元素。
bool PopBack(SeqList &LL)
{
    return DeleteElem(LL, LL.length);
}

// 判断顺序表是否为空，返回值：true-空，false-非空。
bool IsEmpty(const SeqList &LL)
{
    if (LL.length == 0)
        return true;

    return false;
}

// 显示顺序表中全部的元素。
void PrintList(const SeqList &LL)
{
    if (LL.length == 0)
    {
        cout << "表为空。\n";
        return;
    }

    for (size_t ii = 0; ii < LL.length; ii++)
    {
        cout << LL.data[ii] << " ";
    }

    cout << endl;
}

int main()
{
    SeqList LL;    // 创建顺序表。
    InitList(LL); // 清空顺序表。

    ElemType ee; // 创建一个数据元素。

    cout << "在表中插入元素（1、2、3、4、5、6、7、8、9、10）。\n";
    ee = 1;
    InsertList(LL, 1, ee);
    ee = 2;
    InsertList(LL, 1, ee);
    ee = 3;
    InsertList(LL, 1, ee);
    ee = 4;
    InsertList(LL, 1, ee);
    ee = 5;
    InsertList(LL, 1, ee);
    ee = 6;
    InsertList(LL, 1, ee);
    ee = 7;
    InsertList(LL, 1, ee);
    ee = 8;
    InsertList(LL, 1, ee);
    ee = 9;
    InsertList(LL, 1, ee);
    ee = 10;
    InsertList(LL, 1, ee);

    PrintList(LL);

    cout << "在表头插入元素（11），表尾插入元素（12）。\n";
    ee = 11;
    PushFront(LL, ee);
    ee = 12;
    PushBack(LL, ee);

    PrintList(LL);

    cout << "在第5个位置插入元素（13）。\n";
    ee = 13;
    InsertList(LL, 5, ee);

    PrintList(LL);

    cout << "删除表中第7个元素。\n";
    DeleteElem(LL, 7);
    PrintList(LL);

    cout << "删除表头元素。\n";
    PopFront(LL);
    PrintList(LL);

    cout << "删除表尾元素。\n";
    PopBack(LL);
    PrintList(LL);

    GetElem(LL, 5, ee);
    cout << "第5个元素的值是" << ee << "。\n";

    ee = 8;
    cout << "元素值为8的位置是=" << FindElem(LL, ee) << endl;
    DestroyList(LL);
}
