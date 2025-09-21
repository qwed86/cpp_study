# include<iostream>
using namespace std;

void func(int p[][3], int len)
{
    for (int i=0; i<len; i++)
    {
        for (int j=0; j<3; j++)
        {cout<<"p["<<i<<"]["<<j<<"]="<<p[i][j]<<" ";}
        cout<<endl;
    }
    
}

int main()
{
    int bh[2][3] = { {11,12,13},{21,22,23} };

    //bh被解释为数组长度为3的整型数组类型的行地址。
    //如果存放bh的值，要用数组长度为3的整型数组类型的行指针。

    int (*p)[3] = bh;

    //如果要把bh传给函数，函数的声明如下：
    // void func(int (*p)[3],int len);
    // void func(int p[][3],int len);
    func(bh, 2);

}
