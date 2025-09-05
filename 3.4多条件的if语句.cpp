# include<iostream>
using namespace std;
int main()
{
    int body;
    cout<<"请输入身材代码（火辣1，丰满2，苗条3, 强壮4，肥胖5，未知6）：";
    cin>>body;
    if(body==1)       cout<<"火辣"<<endl;
    else if (body==2) cout<<"丰满"<<endl;
    else if (body==3) cout<<"苗条"<<endl;
    else if (body==4) cout<<"强壮"<<endl;
    else if (body==5) cout<<"肥胖"<<endl;
    else              cout<<"未知"<<endl; 
}
// else if 语句可以有多个，表示多种情况的判断,本质是嵌套的if语句