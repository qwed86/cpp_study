/*
1）从界面上输入一个字母，显示该字母后面的字母，如果后面没有字母，给出提示。
   不允许用if…else if…和switch语句。a b A B
2）自定义一个函数，把字符的'0'、'1'、'2'、'3'、'4'、'5'、'6'、'7'、'8'、'9'
   转换为整数的0、1、2、3、4、5、6、7、8、9。不允许用if…else if…和switch语句。
*/
#include <iostream>
using namespace std;

int transfer(const char num)
{
    if (!(num>='0' && num<='9'))
    {
        cout << "不是数字" << endl;
       return  0;  
    }
    return num - 48;
}

int tolower1(int ch)
{
    return (ch+'a'-'A');
}
int touper1(int ch)
{
    return ch-('a'-'A');
}
int isalpha1(int ch)
{
    if ((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z'))
    {return 1;}
    return 0;
}
int isalnum1(int ch)
{
    if ((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z')||(ch>='0'&&ch<='9'))
    {return 1;}
    return 0;
}
int main()
{
    char i = 'A';
    // 利用ascii A-Z对应65-90 a-z对应97-97+25
    cout << "输入一个大写或小写字母：" << endl;
    cin >> i;
    if (!((i >= 'A' && i <= 'Z') || (i >= 'a' && i <= 'z')))
    {
        cout << "不是字母" << endl;
        return 0; // return 0 退出主程序
    }
    if (i == 'z' || i == 'Z')
    {
        cout << "后面没有字母了" << endl;
        return 0;
    }
    cout << "下一个字母是：" << char(i + 1) << endl;

    cout<<"'x'="<<transfer('x')<<endl;
    cout<<(char)tolower1('A');cout<<(char)touper1('a');
    cout<<isalpha1('s');
}
