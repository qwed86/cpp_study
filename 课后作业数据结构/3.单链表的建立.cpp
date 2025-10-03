#include <iostream>
using namespace std;
typedef int ElemType;

// 利用结构体建立链表节点Node包括数据和指向下一节点的指针
struct Node
{
    ElemType data; // 存放结点的数据元素。
    Node *next;    // 指向下一个结点的指针。
};

// 初始化链表函数：分配头节点，将头节点指针暂时置空，最后返回头节点地址
// 注意分配头节点要用new动态分配，否则无法返回局部变量
Node *InitList()
{
    Node *head = new Node; // 分配头节点
    if (head == nullptr)
        return 0;         // 内存不足，返回失败。
    head->next = nullptr; // 头节点指针置零
    return head;
}

// 销毁链表函数：delete链表全部节点，需要遍历所有节点
void DestroyList(Node *head)
{
    Node *tmp;
    while (tmp != nullptr)
    {
        tmp = head->next; // 先把head里面next指针指向tmp,再删除head,否则下一节点地址消失
        delete head;
        head = tmp; // 相当于让head指向下一节点
    }
}

// 单链表头插法：在头节点后插入新节点，新节点的next指向原来头节点后面的节点，再让头节点指向新节点
// 在链表的头部插入元素（头插法），返回值：false-失败；true-成功。
bool PushFront(Node *head, const ElemType &ee)
{
    Node *tmp = new Node;
    if (tmp == nullptr)
        return 0;
    tmp->data = ee; // 把数据装入新节点
    // 先让新节点next指向原来头节点后面那个节点
    tmp->next = head->next;
    // 再让头节点next指向新节点
    head->next = tmp;
    return true;
}

// 显示链表所以元素：利用临时指针存储next，再指向下一个next
void PrintList(const Node *head)
{
    if (head == nullptr)
    {
        cout << "链表不存在";
        return;
    }
    Node *tmp = head->next; // head中无数据无需显示
    while (tmp != nullptr)
    {
        cout << tmp->data << endl;
        tmp = tmp->next;
    }
}

// 在链表的尾部插入元素（尾插法），返回值：false-失败；true-成功。
bool PushBack(Node *head, const ElemType &ee)
{
    if (head == nullptr)
    {
        cout << "链表不存在。\n";
        return false;
    }
    // 需要从head遍历找到最后一个节点
    Node *point = head;
    while (point->next != nullptr) // 循环完成后point指向当前最后一个节点
    {
        point = point->next;
    }
    // 创建一个新节点作为尾插节点
    Node *tail = new Node;
    if (tail == nullptr)
        return false;
    tail->data = ee;      // 把数据装入新节点
    point->next = tail;   // 让前面节点next指向新节点
    tail->next = nullptr; // 把尾插节点tail的next置空
    return true;
}

// 求链表的表长，返回值：>=0-表LL结点的个数。
size_t ListLength(Node *head)
{
    if (head == nullptr) { cout << "链表不存在。\n"; return 0; }
    size_t length = 0;
    Node *p = head;
    while (p != 0)
    {
        p = p->next;
        length++;
    }
    return length-1; //头节点不算节点数
}

int main()
{
    Node *LL = InitList();
    cout << "用头插法向链表中插入元素（1、2、3）。\n";
    PushFront(LL, 1);
    PushFront(LL, 2);
    PushFront(LL, 3);
    PrintList(LL); // 把链表中全部的元素显示出来。
    cout << "用尾插法向链表中插入元素（4、5、6）。\n";
    PushBack(LL, 4);
    PushBack(LL, 5);
    PushBack(LL, 6);
    PrintList(LL); // 把链表中全部的元素显示出来
    DestroyList(LL);
    cout<<ListLength(LL);
}