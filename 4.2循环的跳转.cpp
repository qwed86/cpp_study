# include<iostream>
using namespace std;
int main()
{ // break跳出当前循环语句，continue回到当前循环首部
  bool once=1;

  while(1)
  {
    if (once==false)
    { 
        cout<<"是否继续筛选（1继续，0不继续）"<<endl;
        bool flag;
        cin>>flag;
        if (flag==0) break;
    }
    once=false;

    cout<<"输入超女的颜值（1漂亮，0不漂亮）"<<endl;
    int beauty;
    cin>>beauty;
    if (beauty==1) 
    {
        cout<<"成功晋级"<<endl;
        continue;
    }

    cout<<"输入超女的身材（1火辣，0不火辣）"<<endl;
    int body;
    cin>>body;
    if (body==1) 
    {
        cout<<"成功晋级"<<endl;
    }
  }
}