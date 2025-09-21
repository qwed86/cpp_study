# include<iostream>
using namespace std;
int main()
{ // 超女分4个小组，每个小组有3名超女，在控制台显示每个超女的小组编号和组内编号。
   for (int i=1;  i<=4; i++)
   {
    for (int j=1;  j<=3; j++)
    {
        cout<<"第"<<i<<"组第"<<j<<"号超女"<<endl;
    }
   } 

}