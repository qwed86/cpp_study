#include <iostream>
#include <cstring>
using namespace std;

#define MAXSIZE 100 // 顺序表的最大长度

// 数据元素结构体
struct ElemType {
    int bh;
    char name[21]; // 20字符+1结束符
};

// 顺序表结构体
struct SeqList {
    ElemType data[MAXSIZE];
    size_t length;
};

// 清空顺序表
void ClearList(SeqList &LL) {
    memset(&LL, 0, sizeof(SeqList));
}

// 插入元素到顺序表的第pos个位置（从1开始）
bool InsertList(SeqList &LL, const size_t pos, const ElemType &ee) {
    if (LL.length == MAXSIZE) {
        cout << "顺序表已满\n";
        return false;
    }
    if (pos < 1 || pos > LL.length + 1) {
        cout << "插入位置" << pos << "不合法，应该在1-" << LL.length + 1 << "之间。\n";
        return false;
    }
    if (pos <= LL.length) {
        // 后移元素
        memmove(LL.data + pos, LL.data + (pos - 1), (LL.length - pos + 1) * sizeof(ElemType));
    }
    // 拷贝新元素
    memcpy(LL.data + pos - 1, &ee, sizeof(ElemType));
    LL.length++;
    return true;
}

// 获取顺序表长度
size_t LengthList(const SeqList &LL) {
    return LL.length;
}

// 获取第pos个元素（从1开始）
bool GetElem(const SeqList &LL, const size_t pos, ElemType &ee) {
    if (pos < 1 || pos > LL.length) {
        cout << "POS位置不合法\n";
        return false;
    }
    ee = LL.data[pos - 1];
    return true;
}

// 表头插入
bool PushFront(SeqList &LL, const ElemType &ee) {
    return InsertList(LL, 1, ee);
}

// 表尾插入
bool PushBack(SeqList &LL, const ElemType &ee) {
    return InsertList(LL, LL.length + 1, ee);
}

// 查找元素bh在表中的位置
size_t FindElem(const SeqList &LL, const ElemType &ee) {
    for (size_t i = 0; i < LL.length; i++) {
        if (LL.data[i].bh == ee.bh) {
            return i + 1; // 返回从1开始的位置
        }
    }
    return 0; // 未找到
}

// 删除第pos个元素（从1开始）
bool DeleteElem(SeqList &LL, const size_t pos) {
    if (pos < 1 || pos > LL.length) {
        cout << "删除位置" << pos << "不合法，应该在1-" << LL.length << "之间。\n";
        return false;
    }
    memmove(LL.data + pos - 1, LL.data + pos, (LL.length - pos) * sizeof(ElemType));
    LL.length--;
    return true;
}

// 表头删除
bool PopFront(SeqList &LL) {
    return DeleteElem(LL, 1);
}

// 表尾删除
bool PopBack(SeqList &LL) {
    return DeleteElem(LL, LL.length);
}

// 判断是否为空表
bool IsEmpty(const SeqList &LL) {
    return LL.length == 0;
}

// 显示顺序表
void PrintList(const SeqList &LL) {
    if (LL.length == 0) {
        cout << "空表\n";
        return;
    }
    cout << "顺序表元素：\n";
    for (size_t i = 0; i < LL.length; i++) {
        cout << "[" << i + 1 << "] bh=" << LL.data[i].bh 
             << ", name=" << LL.data[i].name << "\n";
    }
}

int main() {
    SeqList LL;
    ClearList(LL);

    ElemType ee;

    // 插入10个元素
    for (int i = 1; i <= 10; i++) {
        ee.bh = i;
        snprintf(ee.name, sizeof(ee.name), "Girl%02d", i); // 初始化名字
        InsertList(LL, 1, ee); // 每次插入表头
    }
    PrintList(LL);

    // 表头插入11，表尾插入12
    ee.bh = 11;  snprintf(ee.name, sizeof(ee.name), "Girl11");
    PushFront(LL, ee);
    ee.bh = 12;  snprintf(ee.name, sizeof(ee.name), "Girl12");
    PushBack(LL, ee);
    PrintList(LL);

    // 第5个位置插入13
    ee.bh = 13; snprintf(ee.name, sizeof(ee.name), "Girl13");
    InsertList(LL, 5, ee);
    PrintList(LL);

    // 删除第7个元素
    DeleteElem(LL, 7);
    PrintList(LL);

    // 删除表头和表尾
    PopFront(LL);
    PrintList(LL);
    PopBack(LL);
    PrintList(LL);

    // 获取第5个元素
    if (GetElem(LL, 5, ee)) {
        cout << "第5个元素：bh=" << ee.bh << ", name=" << ee.name << "\n";
    }

    // 查找元素bh=8
    ee.bh = 8;
    size_t pos = FindElem(LL, ee);
    if (pos) {
        cout << "元素bh=8的位置：" << pos << "\n";
    } else {
        cout << "元素bh=8不存在\n";
    }

    return 0;
}
