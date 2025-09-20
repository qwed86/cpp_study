# include<iostream>
using namespace std;

// void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));
// 第一个参数：数组的起始地址。
// 第二个参数：数组元素的个数（数组长度）。
// 第三个参数：数组元素的大小（sizeof(数组的数据类型)）。
// 第四个参数：回调函数的地址。
// 回调函数决定了排序的顺序，声明如下：
// int compar(const void *p1, const void *p2);
// 1）如果函数的返回值< 0 ，那么p1所指向元素会被排在p2所指向元素的前面。
// 2）如果函数的返回值==0，那么p1所指向元素与p2所指向元素的顺序不确定。
// 3）如果函数的返回值> 0 ，那么p1所指向元素会被排在p2所指向元素的后面。

int compar(const void *p1, const void *p2)
{
  return *((int*)p1)-*((int*)p2); // 如果p1指向值大于p2，p1排p2后面相当于从小到大排序
}
int compar1(const void *p1, const void *p2)
{
  return *((int*)p2)-*((int*)p1); // 如果p2指向值大于p1，p1排p2后面相当于降序排列
}

int main()
{
    int a[5]={1,9,-9,5,0};

    qsort(a, sizeof(a)/sizeof(a[0]), sizeof(a[0]), compar1);

    for(unsigned i=0; i<sizeof(a)/sizeof(a[0]); i++)
    {
        cout<<"a["<<i<<"]="<<a[i]<<endl;
    }

}