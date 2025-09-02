# include <iostream>
using namespace std;
int main()
{
    int a=1, b=2;
    double c=1.0000000000000000000000000001;   //此时c与整数1被判断为相等
    char e = 'x';
    bool d=true ;
    bool result1 ;
    bool result2 ;
    result1 = b>e;
    result2 = c==d;
    cout<<result1<<endl ;
    cout<<result2<<endl ;
    
}
