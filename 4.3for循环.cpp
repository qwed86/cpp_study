/*
for (语句一 ; 表达式 ; 语句二)
{
    语句块
}
1）循环开始的时候，先执行语句一，在整个循环过程中语句一只会被执行一次。
2）计算表达式的值，如果为真，就执行一次循环体中的语句块。
3）执行完语句块后，执行一次语句二。
4）重复第2）步和第3），直到表达式的值不为真才结束for循环。
for(;;) 等价于 while(1)
*/
# include <iostream>
using namespace std;
int main()
{
    // int no;
    for (int no=1; no<=10; no++)
    { 
      if (no%2==0) continue; //跳过本次循环，继续下一次循环
      cout<<"这是"<<no<<"号超女"<<endl;
    }
}
