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
        cout << tmp->data << " ";
        tmp = tmp->next;
    }cout<<endl;
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
    pp->next = tmp;
    return 1;
}

// 在指定结点pp之前插入元素ee:先把新节点插到pp后，将pp的内容赋予新节点，再将ee赋予pp
bool InsertPriorNode(Node *pp, const ElemType &ee)
{
    if (pp == nullptr)
    {
        cout << "节点pp不存在";
        return 0;
    }
    InsertNextNode(pp, pp->data);
    pp->data = ee;
    return 1;
}

// 删除指定结点。
bool DeleteNode1(Node *pp)
{
    if (pp == nullptr || pp->next == nullptr)
    {
        cout << "节点不存在或无法删除尾节点\n";
        return false;
    }
    Node *tmp = pp->next;
    pp->data = tmp->data;
    pp->next = tmp->next;
    delete tmp;
    return 1;
}

// 把元素有序的插入链表中，返回值：false-失败；true-成功。
bool PushOrder(Node *head, const ElemType &ee)
{
    if (head == nullptr)
    {
        cout << "链表不存在。\n";
        return false;
    }

    Node *tail = head;
    Node *tmp = head->next;

    while (tmp != nullptr)
    {
        if (tmp->data > ee)
        {
            InsertPriorNode(tmp, ee);
            return true;
        }
        tail = tmp;
        tmp = tmp->next;
    }

    // 没找到比ee大的结点 => 插到尾部
    return InsertNextNode(tail, ee);
}

// 采用归并的方法，将两个升序的链表La和Lb，合并成一个升序的链表Lc。
// 合并后，链表La和Lb将不再拥有结点（只有头结点）。
// 把pa和pb合并到Lc中。
void MergeList(Node *La, Node *Lb, Node *Lc)
{
    Node *pa = La->next;
    Node *pb = Lb->next;
    Node *p;
    while ((pa != nullptr) && (pb != nullptr))
    {
        if (pa->data >= pb->data)
        {
            p = pb, pb = pb->next;
        }
        else if (pa->data < pb->data)
        {
            p = pa, pa = pa->next;
        }
        // 把Lc.next指向p,每次循环Lc指向较小的p，Lc不断链接节点
        Lc->next = p;
        Lc = Lc->next;
    }

    if (pa != 0)
        Lc->next = pa;
    if (pb != 0)
        Lc->next = pb;
    // 链表La和Lb的结点已全部转移给了Lc，需置空，否则DestroyList()时会引起重复释放结点。
    La->next = Lb->next = nullptr;
}

// 桶排序主函数，参数arr是待排序数组的首地址，len是数组元素的个数，bucketnum是桶的个数。
void bucketsort(int arr[], int len, int bucketnum)
{
    Node *buckets = new Node[bucketnum];
    for (int i = 0; i < bucketnum; i++)
    {
        buckets[i].next = nullptr;//(*(buckets+i)).next=nullptr;
    }
    // 把数组arr全部的元素放入桶中。
    for (int i = 0; i < len; i++)
    {
        PushOrder(&buckets[arr[i] % bucketnum], arr[i]);
    }
    // 显示每个桶中的元素。
    cout << "每个桶中的元素如下：\n";
    for (int ii = 0; ii < bucketnum; ii++)
        PrintList(&buckets[ii]);

    Node LL;
    LL.next = nullptr;
    Node tmp;
    tmp.next = nullptr;
    for (int i = 0; i < bucketnum; i++)
    {
        MergeList(&LL, &buckets[i], &tmp);// 运行完后LL.next=nullptr
        swap(LL.next, tmp.next); // tmp.next指向头节点，交换后LL.next指向新归并链表的头节点
    }
    // 把合并后的结果保存到数组arr中。
    Node *pp = LL.next;
    for (int ii = 0; ii < len; ii++)
    {
        arr[ii] = pp->data;
        pp = pp->next;
    }

    DestroyList(LL.next); // 释放链表LL的数据结点。
    delete[] buckets;     // 释放桶的结构体数组（头结点们）。
}

int main()
{ // 链表语义是动态分配内存，包括头节点，也是动态分配出来的。
    // 以下代码用于测试PushOrder()函数的功能。
    // LNode LL; LL.next = nullptr;  //  = InitList();     // 初始化链表LL。
    // cout << "有序的插入元素（5、8、7、4、1、3、9、3、6）。\n";
    // PushOrder(&LL, 5);
    // PushOrder(&LL, 8);
    // PushOrder(&LL, 7);
    // PushOrder(&LL, 4);
    // PushOrder(&LL, 1);
    // PushOrder(&LL, 3);
    // PushOrder(&LL, 9);
    // PushOrder(&LL, 3);
    // PushOrder(&LL, 6);
    // PrintList(&LL);			        // 把链表中全部的元素显示出来。
    // DestroyList(LL.next);           // 销毁链表LL的数据结点。
    ////////////////////////////////////////////////////

    // 以下代码用于测试MergeList()函数的功能。
    // LNode La; La.next = nullptr;
    // LNode Lb; Lb.next = nullptr;
    // LNode Lc; Lc.next = nullptr;
    // PushOrder(&La, 5);
    // PushOrder(&La, 8);
    // PushOrder(&La, 7);
    // PushOrder(&La, 4);
    // PushOrder(&Lb, 1);
    // PushOrder(&Lb, 3);
    // PushOrder(&Lb, 9);
    // PushOrder(&Lb, 2);
    // PushOrder(&Lb, 6);
    // MergeList(&La, &Lb, &Lc);  // 把链表La和Lb合并成Lc。
    // PrintList(&Lc);			     // 把链表Lc中全部的元素显示出来。
    ////DestroyList(La.next);
    ////DestroyList(Lb.next);
    // DestroyList(Lc.next);
    //////////////////////////////////////////////////////

    //// 以下代码用于测试桶排序的功能。
    int arr[] = {44, 3, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48}; // 待排序的数组。
    int len = sizeof(arr) / sizeof(int);                                  // 求数组长度。

    bucketsort(arr, len, 3);

    // 显示排序结果。
    for (int ii = 0; ii < len; ii++)
        cout << arr[ii] << " ";

    cout << endl;
}