# include<iostream> 
#include <string>
#include <io.h>
#include <fcntl.h>
using namespace std; 
int main() 
{   
    string name; 
    int age; 
    double weight; 
    char gender; 
    bool appreance;
     cout<<"输入姓名:";
      cin>>name; 
     cout<<"输入姓名是："<<name<<endl; 
     cout<<"输入年龄"; 
     cin>>age; 
     cout<<"输入年龄是："<<age<<endl;
      cout<<"输入体重"; 
      cin>>weight; 
      cout<<"输入体重是："<<weight<<endl; 
      cout<<"输入性别(女-X,男-Y)"; 
      cin>>gender; 
      cout<<"输入性别:"<<gender<<endl;
       cout<<"输入颜(1-漂亮0-不漂)";
        cin>>appreance; 
        cout<<"输入颜值是:"<<appreance<<endl;
}