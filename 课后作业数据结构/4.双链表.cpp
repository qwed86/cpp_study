#include <iostream>
using namespace std;
typedef int ElemType;
/*双链表处理指针处理顺序:
插入节点：
1、先处理新节点的指针
2、再处理前驱节点的next指针
3、最后处理后继节点的prior指针
删除节点：
1、处理前驱节点的next指针
2、处理后继节点的prior指针
考虑后继节点不存在的情况*/

// 利用结构体建立链表节点Node包括数据和指向前后节点的指针
struct Node
{
    ElemType data; // 存放结点的数据元素。
    Node *next;    // 指向下一个结点的指针。
    Node *prior;   // 指向上一个结点的指针。
};

// 初始化链表函数：分配头节点，将头节点指针暂时置空，最后返回头节点地址
// 注意分配头节点要用new动态分配，否则无法返回局部变量
Node *InitList()
{
    Node *head = new Node; // 分配头节点
    if (head == nullptr)
        return 0;          // 内存不足，返回失败。
    head->next = nullptr;  // 头节点指针置零
    head->prior = nullptr; // 头节点指针置零
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
    // 先让新节点的next指向原来头节点后面那个节点,
    // 再让头节点后面那个节点的prior指向新节点
    tmp->next = head->next;
    if (head->next != 0)
        head->next->prior = tmp; // 空指针保护

    // 再让头节点next指向新节点
    // 新节点prior指向头节点
    head->next = tmp;
    tmp->prior = head;
    return true;
}

// 显示链表所有元素：利用临时指针存储next，再指向下一个next
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
    tail->prior = point;  // 让尾插节点tail的prior指向前面节点
    tail->next = nullptr; // 把尾插节点tail的next置空
    return true;
}

// 求链表的表长，返回值：>=0-表LL结点的个数。
size_t ListLength(Node *head)
{
    if (head == nullptr)
    {
        cout << "链表不存在。\n";
        return 0;
    }
    size_t length = 0;
    Node *p = head;
    while (p != nullptr)
    {
        p = p->next;
        length++;
    }
    return length - 1; // 头节点不算节点数
}

// 删除链表第一个结点（头节点后面那个）。
bool PopFront(Node *head)
{
    if (head == nullptr)
    {
        cout << "链表不存在。\n";
        return false;
    }

    if (head->next == nullptr)
    {
        cout << "链表为空，没有结点。\n";
        return false;
    }
    // 用临时变量记住第一个节点的地址，头节点next指向第二个节点，再删除临时变量的节点
    Node *tmp = head->next;
    head->next = head->next->next;
    head->next->prior = head;
    delete tmp;
    return true;
}

// 删除链表最后一个结点:找到倒数第二个节点，倒数第二个节点next指向空指针，然后删掉最后节点
bool PopBack(Node *head)
{
    if (head == nullptr)
    {
        cout << "链表不存在。\n";
        return false;
    }
    // 必须加上这个判断，否则下面的循环tmp->next->next不成立。
    if (head->next == nullptr)
    {
        cout << "链表为空，没有结点。\n";
        return false;
    }

    if (head->next->next == nullptr)
    { // 只有一个数据节点
        delete head->next;
        head->next = nullptr;
        return true;
    }
    Node *tmp = head->next;
    while (tmp->next->next != nullptr)
        tmp = tmp->next;
    Node *tail = tmp->next;
    tmp->next = nullptr;
    delete tail;
    return true;
}

// 清空链表，清空链表是指释放链表全部的结点，但是，不释放头结点。
void ClearList(Node *head)
{
    if (head == nullptr)
    {
        cout << "链表不存在。\n";
        return;
    } // 判断链表是否存在。

    Node *tmp1;
    Node *tmp2 = head->next; // 从头结点的下一个结点开始释放。

    while (tmp2 != nullptr)
    {
        tmp1 = tmp2->next;
        delete tmp2;
        tmp2 = tmp1;
    }

    head->next = nullptr; // 这行代码一定不能少，否则会留下野指针。
}

// 查找元素ee在链表中的结点地址，如果没找到返回nullptr，否则返回结点的地址。
Node *LocateElem(const Node *head, const ElemType &ee)
{
    if (head == nullptr)
    {
        cout << "链表不存在。\n";
        return 0;
    } // 判断链表是否存在。
    Node *p = head->next;
    while (p != 0)
    {
        if (p->data == ee)
        {
            return p;
        }
        else
        {
            p = p->next;
        }
    }
    return 0;
}
// 获取链表中第n个结点，成功返回结点的地址，失败返回nullptr。
// 注意，n可以取值为0，表示头结点。
Node *LocateNode(Node *head, unsigned int n)
{
    if (head == 0)
    {
        cout << "链表不存在。\n";
        return 0;
    }
    Node *tmp = head;
    int i = 0;
    if (n > ListLength(head))
        return nullptr;
    while (i < n)
    {
        tmp = tmp->next;
        i++;
    }
    return tmp;
}

// 在指定结点pp之后插入元素ee。
bool InsertNextNode(Node *pp, const ElemType &ee)
{
    if (pp == nullptr)
    {
        cout << "结点pp不存在。\n";
        return false;
    }

    Node *tmp = new Node;
    tmp->data = ee;

    tmp->next = pp->next;
    tmp->prior = pp;
    pp->next=tmp;
    if (tmp->next) // 注意尾节点情况
        tmp->next->prior = tmp;
    
    return true;
}

// 在指定结点pp之前插入元素ee:双链表中通过pp节点的prior可以找到前一个节点
bool InsertPriorNode(Node *pp, const ElemType &ee)
{
    if (pp == nullptr)
    {
        cout << "节点pp不存在";
        return 0;
    }
    Node *tmp = new Node;
    tmp->data = ee;
    // 双链表插入时，通常先连接新节点的指针，再修改相邻节点的指针
    tmp->prior = pp->prior;
    tmp->next = pp;
    tmp->prior->next = tmp;
    tmp->next->prior = tmp;

    return 1;
}

// 删除指定结点。
bool DeleteNode1(Node *pp)
{
    if (pp == nullptr)
        return false;
    if (pp->prior) pp->prior->next = pp->next;
    if (pp->next)  pp->next->prior = pp->prior;
    delete pp;
    return true;
}

int main() {
    // 1. 初始化链表
    Node* LL = InitList();
    if (!LL) { cout << "链表初始化失败\n"; return 1; }

    cout << "== 头插法插入 3,2,1 ==" << endl;
    PushFront(LL, 1);
    PushFront(LL, 2);
    PushFront(LL, 3);
    PrintList(LL); // 3 2 1

    cout << "== 尾插法插入 4,5,6 ==" << endl;
    PushBack(LL, 4);
    PushBack(LL, 5);
    PushBack(LL, 6);
    PrintList(LL); // 3 2 1 4 5 6

    cout << "链表长度: " << ListLength(LL) << endl;

    cout << "== 在第2个节点之后插入 99 ==" << endl;
    Node* node2 = LocateNode(LL, 2); // 注意：0是头节点
    InsertNextNode(node2, 99);
    PrintList(LL); // 3 2 1 99 4 5 6

    cout << "== 在第3个节点之前插入 88 ==" << endl;
    Node* node3 = LocateNode(LL, 3);
    InsertPriorNode(node3, 88);
    PrintList(LL); // 3 2 1 88 99 4 5 6

    cout << "== 删除第2个节点 ==" << endl;
    Node* delNode = LocateNode(LL, 2);
    DeleteNode1(delNode);
    PrintList(LL); // 3 2 88 99 4 5 6

    cout << "== 删除头节点后第一个节点 ==" << endl;
    PopFront(LL);
    PrintList(LL); // 3 88 99 4 5 6

    cout << "== 删除最后一个节点 ==" << endl;
    PopBack(LL);
    PrintList(LL); // 3 88 99 4 5

    cout << "== 清空链表 ==" << endl;
    ClearList(LL);
    PrintList(LL); // 空

    cout << "== 再插入几个节点测试销毁 ==" << endl;
    PushBack(LL, 10);
    PushBack(LL, 20);
    PrintList(LL); // 10 20

    cout << "== 销毁链表 ==" << endl;
    DestroyList(LL);
    LL = nullptr;

    cout << "链表销毁完成" << endl;
    return 0;
}
