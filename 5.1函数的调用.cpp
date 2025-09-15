# include<iostream>
using namespace std;


//写一个函数，比较两整数大小返回大的那个
int max(int a, int b); //函数声明一定要加分号

//写一个函数，给它一个字符串，让它在控制台显示出来。
void print(string str1);

//写一个函数，输出99乘法表
void print99();

int main()
{ // 函数调用语法：函数名(参数一,参数二,……)

    cout<<"max(8,9)="<<max(8,9)<<endl;
    print("爱莉希雅");
    print99();
}

int max(int a, int b)  //函数声明一定不加分号
{
    return a>b? a:b;   //在函数体中，return语句可以多次使用。
} 
// if (a>b) return a;
// return b;

void print(string str1)
{
    cout<<str1<<endl;
    return;
}
 
void print99()
{
     for(int i=1; i<=9; i++)
    {
        for (int j=1; j<=i; j++)
        {
            cout<<j<<"*"<<i<<"="<<i*j<<" ";
        }
        cout<<endl;
       
  
    } 
    return;
}