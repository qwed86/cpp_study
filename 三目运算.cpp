# include <iostream>
using namespace std;
 int main()
 {
    // 语法：表达式一？表达式二：表达式三
    // 如果表达式一为真，执行表达式二，否则执行表达式三
    int a=100, b=10, c;
    c=a>b? a:b; // a和b中较大的值赋值给c
    cout<<"c="<<c<<endl;
 }