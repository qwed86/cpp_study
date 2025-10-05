#include <iostream>
using namespace std;

typedef int ElemType; // 自定义队列的数据元素为整数。

struct Node
{
    ElemType data;     // 存储队列中的元素。
    struct Node *next; // next指针。
};

struct LinkQueue
{
    Node *head, *tail; // 队列的头指针和尾指针。
};

// 分配头节点让头指针和尾指针都指向头节点
LinkQueue* InitQueue()
{
    LinkQueue *Q = new LinkQueue;
    Q->head = new Node; 
    if (Q->head == nullptr) return 0;  
    Q->tail = Q->head;
    Q->head->next=nullptr;
    return Q; //返回的是队列
}

// 销毁队列Q。
void DestroyQueue(LinkQueue* Q)
{
    Node* tmp;
    while(Q->head!=nullptr)
    {
        tmp = Q->head;
        Q->head = tmp->next;
        delete tmp;
    }
    Q->tail=nullptr;
}

// 元素入队（尾插）。
bool InQueue(LinkQueue* QQ, const ElemType& ee)
{
    Node* tmp = new Node;
    if(tmp==nullptr) {return 0;}
    tmp->data=ee; tmp->next=nullptr; //暂时让新节点的next指向空
    QQ->tail->next=tmp; // 尾节点的next指针指向新节点
    QQ->tail=tmp;
    return 1;
}

// 元素出队（先进先出）。
bool OutQueue(LinkQueue* Q, ElemType& ee)
{
    if (Q->head == nullptr)
    {
        cout << "队列不存在。\n";
        return false;
    }

    if (Q->head->next == nullptr)
    {
        cout << "队列为空，没有结点。\n";
        return false;
    }
    // tmp指向要删除的节点(从第一个节点开始删除)
    Node* tmp=Q->head->next; //tmp保存头节点后面节点的地址
    Q->head->next=tmp->next; //头节点指向tmp后的节点
    
    // 如果出队的是尾节点，那么要将tail指向头节点
    if(tmp==Q->tail) {Q->tail=Q->head;}
    ee=tmp->data;
    delete tmp; //删除tmp
    return 1;
}

// 显示队列中全部的元素。
void PrintQueue(LinkQueue* Q)
{
    if(Q->head==nullptr) {cout << "队列不存在"; return;}
    if(Q->head->next==nullptr) {cout << "队列为空"; return;}
    Node* tmp=Q->head->next;
    while (tmp!=nullptr)
    {   cout<<tmp->data<<" "; 
        tmp=tmp->next;
    }cout<<endl;
}

// 求队列的长度。
int  Length(LinkQueue* Q)
{   if(Q->head==nullptr){cout<<"队列为空"; return 0;}
    Node* tmp=Q->head->next; //让tmp指向第一个节点
    int length=0;
    while(tmp!=nullptr)
    {
        tmp=tmp->next;
        length++;
    }
    return length;
}
// 清空队列。
void Clear(LinkQueue* Q)
{
    if(Q->head==nullptr){cout<<"队列为空"; return;}
    Node* tmp=Q->head->next; //让tmp指向第一个节点
    Node* pp=tmp;
    while(tmp!=nullptr)
    {   
        tmp=tmp->next;
        delete pp; //pp指向的内存被释放但指针pp还在
        pp=tmp; 
    }
    Q->head->next=nullptr;
    Q->tail=Q->head;
}
 

int main() {
    cout << "=== 链式队列测试 ===" << endl;

    // 初始化队列
    LinkQueue* Q = InitQueue();
    if (!Q) {
        cout << "队列初始化失败！" << endl;
        return -1;
    }
    cout << "队列初始化完成。" << endl;

    // 入队测试
    cout << "入队元素: 10, 20, 30" << endl;
    InQueue(Q, 10);
    InQueue(Q, 20);
    InQueue(Q, 30);
    PrintQueue(Q);
    cout << "队列长度: " << Length(Q) << endl;

    // 出队测试
    ElemType e;
    OutQueue(Q, e);
    cout << "出队元素: " << e << endl;
    PrintQueue(Q);
    cout << "队列长度: " << Length(Q) << endl;

    OutQueue(Q, e);
    cout << "出队元素: " << e << endl;
    PrintQueue(Q);
    cout << "队列长度: " << Length(Q) << endl;

    // 再入队测试
    cout << "入队元素: 40, 50" << endl;
    InQueue(Q, 40);
    InQueue(Q, 50);
    PrintQueue(Q);
    cout << "队列长度: " << Length(Q) << endl;

    // 清空队列
    cout << "清空队列..." << endl;
    Clear(Q);
    PrintQueue(Q);
    cout << "队列长度: " << Length(Q) << endl;

    // 入队测试清空后是否可用
    cout << "清空后再入队元素: 100" << endl;
    InQueue(Q, 100);
    PrintQueue(Q);
    cout << "队列长度: " << Length(Q) << endl;

    // 销毁队列
    DestroyQueue(Q);
    cout << "队列销毁完成。" << endl;

    return 0;
}

