# include<iostream>
using namespace std;
//一维数组用于函数的参数时，只能传数组的地址，并且必须把数组长度也传进去
// void func(int arr[], int len);
void func(int arr[], int len)
{
    for(int i=0; i<len; i++)
    {
        cout<<"arr["<<i<<"]的值是："<< arr[i]<<endl;
    }
}
int main()
{
    // int a[5]={2,6,-9,4,45};
    // // 用数组表示法操作数组
    // for (int i=0; i<5; i++)
    // {
    //     cout<<"a["<<i<<"]的值为："<<a[i]<<endl;
    // }

    // cout<<(&a[2])[1]<<endl;  //地址[下标] 解释为 *(地址+下标): 相当于索引a[2+1]
    // 用指针表示法操作数组
    // int *p=a;
    // for (int j=0; j<5; j++)
    // {
    //     cout<<"*(p+"<<j<<")的值为："<<*(p+j)<<endl; //数组名[下标]  解释为  *(数组首地址+下标)
    //     cout<<"p["<<j<<"]的值为："<<p[j]<<endl; //地址[下标]  解释为  *(地址+下标)
    // }

    // char b[20]; //占用内存为20字节
    // int *p= (int*)b; //转化为整型后数组长度变20/4=5
    // for (int k=0; k<6; k++)
    // {
    //     p[k]=k+300;
    //     cout<<*(p+k)<<endl;
    
    // }
    int a[] = {2,8,4,6,7,1,9,-9};
    func(a, sizeof(a)/sizeof(int));

}