# include <iostream>
using namespace std;
int main()
{
    bool a =true, b= false;
    bool c =a&&b; // && 逻辑与
    bool d =a||b; // || 逻辑或
    bool e =!a;    // ! 逻辑非
    cout<<"!a="<<e<<endl;
    cout<<"a||b="<<d<<endl;
    cout<<"a&&b="<<c<<endl;
    // 成为超女的条件：年龄小于25岁，并且身高大于165cm，体重小于50，颜值要漂亮
    int age=22, height=170, weight=48;
    bool pretty=true;
    bool supergirl= age<25 && height>165 && weight <50 && pretty;
    
    if (supergirl == true)
    {cout<<"恭喜你，你是超女！"<<endl;}
    else
        cout<<"很遗憾，你不是超女！"<<endl;

}