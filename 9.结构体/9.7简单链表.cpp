#include <iostream>
using namespace std;

struct st_girl
{
    int no;
    string name;
    st_girl *next;
};

int main()
{
    st_girl *head = nullptr, *tail = nullptr, *temp = nullptr;

    temp = new st_girl({1, "西施", nullptr}); // 分配第一个节点,新分配节点的next指针一般为空
    head = tail = temp;                       // head存放第一个节点的地址

    temp = new st_girl({6, "冰冰", nullptr});
    tail->next = temp; // 把上一个节点的next指针指向新节点(冰冰)。
    tail = temp;       // 移动尾指针，让尾指针指向刚分配出来的新节点。

    temp = new st_girl({8, "Katie", nullptr});
    tail->next = temp; // 把上一个节点的next指针指向新节点(Katie)。
    tail = temp;       // 移动尾指针，让尾指针指向最后节点。

    //遍历链表
    temp=head; 
    while(temp!=nullptr)
    {
        cout<<"no="<<temp->no<<" name="<<temp->name<<"temp->next="<<temp->next<<endl;
        temp=temp->next;
    }

    while(head!=nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
        
    } 
}