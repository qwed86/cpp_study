# include<iostream>
using namespace std;
int main()
{
 char gender;
 bool yz;
 int body;
    cout<<"请输入性别（男Y，女X）"<<endl;
    cin>>gender;
    if (gender=='X')   
    {
        cout<<"请输入颜值（漂亮1，一般0）"<<endl;
        cin>>yz;
        if(yz==1)
        {
            cout<<"请输入身材（火辣1，丰满2，苗条3）"<<endl;
            cin>>body;

            if(body==1||body==3) cout<<"你可以参加比赛"<<endl;
            else cout<<"待定"<<endl;
        }
        else cout<<"不够漂亮"<<endl;
    }
    else {cout<<"你不是女生，不能参加比赛"<<endl;}
}