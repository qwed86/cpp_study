# include<iostream>
# include<string.h> // for memset
using namespace std;
// 数据类型 数组名[数组长度];
int main()
{
    int num[3];
    string name[3];
    // 可以通过下标访问数组中元素，数组下标从0开始。
    // 数组中每个元素的特征和使用方法与单个变量完全相同。
    num[0] = 8;
    num[1] = 256;
    num[2] = 485;
    cout<<"num[0]="<<num[0]<<endl;
    cout<<"num[1]="<<num[1]<<endl;
    cout<<"num[2]="<<num[2]<<endl;
    cout<<num[3]<<endl;  // 自动补0

    //常用循环来处理数组
    for(int i=0; i<3; i++)
    {
        num[i]=30+i;
        cout<<"num["<< i <<"]="<<num[i]<<endl;
    }
    cout<<"数组占用的空间是"<<sizeof(num)<<endl; // 3*4=12

    // 数组的初始化 
    //int bh[5] = {15,515,51,5,6};
    int bh[] = {15,515,51,5,6,45,4,15,15,9};

    // 清空数组用memset()函数可以把数组中全部的元素清零。（只适用于C++基本数据类型）
    // 函数原型：void *memset(void *s, int c, size_t n);
    // memset(数组名,填充的数据,数组大小)
    memset(bh, 0, sizeof(bh));
    for(unsigned int i=0; i<sizeof(bh)/sizeof(int); i++)
    {
        cout<<"bh["<< i <<"]="<<bh[i]<<endl;
    }

    //复制数组: memcpy(目标数组名, 原数组名, 数组大小)
    int bh1[sizeof(bh)/sizeof(int)];
    memcpy(bh1, bh , sizeof(bh));
    for(unsigned int i=0; i<sizeof(bh1)/sizeof(int); i++)
    {
        cout<<"bh1["<< i <<"]="<<bh1[i]<<endl;
    }

}