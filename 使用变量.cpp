# include <iostream>
using namespace std;
int main()
{
  //整数int，实数float，双精度实数double（常用），
  //字符char,字符串string，布尔bool
    string name="爱莉希雅";
    int age=17;
    double weight=54.8;
    char gender='X';
    bool appreance= -0.2 ;       //true表示真, false表示假, 实际所有非0的数都为true
    cout << "姓名："<<name<<"，年龄："<<age<<",体重："<<weight<<"kg(不许四舍五入)，"
         << "性别："<<gender<<"，颜值："<<appreance << endl;
    
}
