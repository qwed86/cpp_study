# include<iostream>
using namespace std;
int main()
{
    //假设准备好爱莉希雅数据
    int age = 18;
    int height = 170;
    string body = "pump";
    string face = "beautiful";

    if ((25>=age && age>=18)          && //年龄
        (175>=height && height>=160)  && //身高
        (body=="pump"||body=="spicy") && //身材
        (face=="beautiful"))             //脸蛋
    cout<<"I want to date with her!"<<endl;
    else
    cout<<"I don't want to date with her!"<<endl;
   

}