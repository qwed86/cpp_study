# include<iostream>
using namespace std;
int main()
{
    int body;
    cout<<"请输入身材代码（火辣1，丰满2，苗条3, 强壮4，肥胖5，未知6）：";
    cin>>body;
    // if(body==1)       cout<<"火辣"<<endl;
    // else if (body==2) cout<<"丰满"<<endl;
    // else if (body==3) cout<<"苗条"<<endl;
    // else if (body==4) cout<<"强壮"<<endl;
    // else if (body==5) cout<<"肥胖"<<endl;
    // else              cout<<"未知"<<endl;
    switch(body) 
    {   // case后面必须是整型或者字符，或结果为整数和字符的表达式，不能为变量或字符串
        // 如果一个case匹配成功，则从该case开始执行，直到遇到break语句为止
        case 1: cout<<"火辣"<<endl; break;
        case 2: cout<<"丰满"<<endl; break;
        case 3: cout<<"苗条"<<endl; break;
        case 4: cout<<"强壮"<<endl; break;
        case 5: cout<<"肥胖"<<endl; break;
        default:cout<<"未知"<<endl;
    }
}