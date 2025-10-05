#include <iostream>
using namespace std;
typedef int ElemType;

// 利用结构体建立链栈节点Node包括数据和指向下一节点的指针
struct Node
{
    ElemType data; // 存放结点的数据元素。
    Node *next;    // 指向下一个结点的指针。
};

// 初始化链栈函数：分配头节点，将头节点指针暂时置空，最后返回头节点地址
// 注意分配头节点要用new动态分配，否则无法返回局部变量
Node *InitList()
{
    Node *head = new Node; // 分配头节点
    if (head == nullptr)
        return 0;         // 内存不足，返回失败。
    head->next = 0; // 头节点指针置零
    return head;
}

// 销毁链栈函数：delete链栈全部节点，需要遍历所有节点
void DestroyList(Node *head)
{
    Node *tmp ;
    while (tmp != 0)
    {
        tmp = head->next; // 先把head里面next指针指向tmp,再删除head,否则下一节点地址消失
        delete head;
        head = tmp; // 相当于让head指向下一节点
    }
}

// 单链栈头插法：在头节点后插入新节点，新节点的next指向原来头节点后面的节点，再让头节点指向新节点
// 在链栈的头部插入元素（头插法），返回值：false-失败；true-成功。
bool PushFront(Node *head, const ElemType &ee)
{
    Node *tmp = new Node;
    if (tmp == 0)
        return 0;
    tmp->data = ee; // 把数据装入新节点
    // 先让新节点next指向原来头节点后面那个节点
    tmp->next = head->next;
    // 再让头节点next指向新节点
    head->next = tmp;
    return true;
}

// 显示链栈所以元素：利用临时指针存储next，再指向下一个next
void PrintList(const Node *head)
{
    if (head == 0)
    {
        cout << "链栈不存在";
        return;
    }
    Node *tmp = head->next; // head中无数据无需显示
    while (tmp != 0)
    {
        cout << tmp->data << endl;
        tmp = tmp->next;
    }
}


// 求链栈的表长，返回值：>=0-表Stack结点的个数。
size_t ListLength(Node *head)
{
    if (head == 0)
    {
        cout << "链栈不存在。\n";
        return 0;
    }
    size_t length = 0;
    Node *p = head;
    while (p != 0)
    {
        p = p->next;
        length++;
    }
    return length - 1; // 头节点不算节点数
}

// 出栈。
bool PopFront(Node *head, ElemType ee)
{
    if (head == 0)
    {
        cout << "链栈不存在。\n";
        return false;
    }

    if (head->next == 0)
    {
        cout << "链栈为空，没有结点。\n";
        return false;
    }
    // 用临时变量记住第一个节点的地址，头节点next指向第二个节点，再删除临时变量的节点
    Node *tmp = head->next;
    head->next = head->next->next;
    ee=tmp->data;
    delete tmp;
    return true;
}


void TestLinkedList()
{
    cout << "=== 初始化栈 ===\n";
    Node* Stack = InitList();
    if (!Stack) { cout << "初始化失败！\n"; return; }

    cout << "\n=== 入栈元素 1, 2, 3 ===\n";
    PushFront(Stack, 1);
    PushFront(Stack, 2);
    PushFront(Stack, 3);
    PrintList(Stack);
    cout << "链栈长度：" << ListLength(Stack) << "\n";

    

    cout << "\n=== 元素出栈 PopFront ===\n";
    ElemType ee=0;
    PopFront(Stack,ee);
    PrintList(Stack);

    cout << "\n=== 测试 DestroyList ===\n";
    DestroyList(Stack);
    Stack = 0;
    cout << "链栈已销毁。\n";
}

int main()
{
   TestLinkedList();
}