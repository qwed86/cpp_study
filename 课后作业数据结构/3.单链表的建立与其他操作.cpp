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
    Node *tmp ;
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

    Node *tmp = head->next;
    while (tmp->next->next != nullptr)
    {
        tmp = tmp->next;
    }
    Node *tail = tmp->next; // 用临时变量保存尾节点
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
        return 0 ;
    } // 判断链表是否存在。
    Node *p = head->next;
    while (p != 0)
    {
        if (p->data == ee) {return p;}
        else {p=p->next;} 
    }
    return 0;
}
// 获取链表中第n个结点，成功返回结点的地址，失败返回nullptr。
// 注意，n可以取值为0，表示头结点。
Node* LocateNode(Node* head, unsigned int n)
{
    if(head==0) {cout << "链表不存在。\n"; return 0 ;}
    Node* tmp=head; int i=0;
    if (n>ListLength(head)) return nullptr;
    while(i<n)
    {tmp=tmp->next; i++;}
    return tmp;
}

// 在指定结点pp之后插入元素ee。
bool InsertNextNode(Node* pp, const ElemType& ee)
{
    if (pp == nullptr) { cout << "结点pp不存在。\n";  return false; }
    Node* tmp=new Node;
    tmp->data=ee;
    tmp->next = pp->next;
    pp->next=tmp;
    return 1;
}

// 在指定结点pp之前插入元素ee:先把新节点插到pp后，将pp的内容赋予新节点，再将ee赋予pp
bool InsertPriorNode(Node* pp, const ElemType& ee)
{
    if (pp==nullptr){cout<<"节点pp不存在"; return 0;}
    InsertNextNode(pp,pp->data);
    pp->data=ee;
    return 1;
}
// 删除指定结点。
bool DeleteNode1(Node* pp)
{
    if (pp == nullptr || pp->next == nullptr) { 
        cout << "节点不存在或无法删除尾节点\n"; 
        return false; 
    }
    Node* tmp = pp->next;
    pp->data=tmp->data;
    pp->next=tmp->next;
    delete tmp;
    return 1;
}

void TestLinkedList()
{
    cout << "=== 初始化链表 ===\n";
    Node* LL = InitList();
    if (!LL) { cout << "初始化失败！\n"; return; }

    cout << "\n=== 头插法插入 1, 2, 3 ===\n";
    PushFront(LL, 1);
    PushFront(LL, 2);
    PushFront(LL, 3);
    PrintList(LL);
    cout << "链表长度：" << ListLength(LL) << "\n";

    cout << "\n=== 尾插法插入 4, 5, 6 ===\n";
    PushBack(LL, 4);
    PushBack(LL, 5);
    PushBack(LL, 6);
    PrintList(LL);
    cout << "链表长度：" << ListLength(LL) << "\n";

    cout << "\n=== 测试 LocateElem ===\n";
    Node* p = LocateElem(LL, 4);
    if (p) cout << "找到元素 4: " << p->data << "\n";
    else cout << "未找到元素 4\n";

    cout << "\n=== 测试 LocateNode ===\n";
    Node* node2 = LocateNode(LL, 2); // 第2个数据结点
    if (node2) cout << "第2个节点的值：" << node2->data << "\n";

    cout << "\n=== 测试 InsertNextNode ===\n";
    InsertNextNode(node2, 99);
    PrintList(LL);

    cout << "\n=== 测试 InsertPriorNode ===\n";
    InsertPriorNode(node2, 77);
    PrintList(LL);

    cout << "\n=== 测试 PopFront ===\n";
    PopFront(LL);
    PrintList(LL);

    cout << "\n=== 测试 PopBack ===\n";
    PopBack(LL);
    PrintList(LL);

    cout << "\n=== 测试 DeleteNode1 (删除指定节点) ===\n";
    Node* delNode = LocateElem(LL, 4);
    if (delNode) DeleteNode1(delNode);
    PrintList(LL);

    cout << "\n=== 测试 ClearList ===\n";
    ClearList(LL);
    PrintList(LL);
    cout << "链表长度：" << ListLength(LL) << "\n";

    cout << "\n=== 测试 DestroyList ===\n";
    DestroyList(LL);
    LL = nullptr;
    cout << "链表已销毁。\n";
}

int main()
{
   TestLinkedList();
}