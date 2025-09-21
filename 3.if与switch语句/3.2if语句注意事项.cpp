# include<iostream>
using namespace std;
int main()
{
    bool yanzhi;
    cout<<"漂亮输入1，否则输入0"<<endl;
    cin>>yanzhi;
    if (yanzhi==true);
     //注意这里的分号，表示if语句到此结束，下面的语句不受if控制,如果条件为真就执行空语句
    // c++中多行语句写在大括号内表示他们是一个整体，不影响语句功能
    {
        cout<<"成功晋级"<<endl;
    }
    
}