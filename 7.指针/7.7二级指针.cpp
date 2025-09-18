# include<iostream>
using namespace std;

void func(int **pp)
{
	*pp = new int(3);
	cout << "pp=" << pp << ",*pp=" << *pp << endl;
}

int main()
{
// 指针用于存放普通变量的地址。
// 二级指针用于存放指针变量的地址。
// 声明二级指针的语法：数据类型** 指针名;
int i = 8;        cout<<"i="<<i<<" i的地址是："<<&i<<endl;
int *pi = &i;     cout<<"pi="<<pi<<" pi的地址是："<<&pi<<" *pi="<<*pi<<endl;
int **ppi = &pi;  cout<<"ppi="<<ppi<<" ppi的地址是："<<&ppi<<" *ppi="<<*ppi<<endl;
cout<<"**ppi="<<**ppi<<endl; //对ppi解引用两次结果为8

// 在函数中，如果传递普通变量的地址，形参用指针；传递指针的地址，形参用二级指针。
//把普通变量的地址传入函数后可以在函数中修改变量的值；把指针的地址传入函数后可以在函数中指针的值。

int*p=0;
func(&p);
	
cout << "p=" << p << ",*p=" << *p << endl;

}