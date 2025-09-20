# include<iostream>
using namespace std;
//普通数组在栈上分配内存，栈很小；如果需要存放更多的元素，必须在堆上分配内存。
//动态创建一维数组的语法：数据类型 *指针=new 数据类型[数组长度];
//   释放一维数组的语法：delete [] 指针;

int main()
{
  int *arr = new int[8];
  for (int i=0; i<8; i++)
  {
    arr[i]=100-i;
    cout<<"arr["<<i<<"]的值为："<<*(arr+i)<<endl;
  }
  delete []arr; //用delete释放内存只能释放arr[0]的内存 

//   如果内存不足，调用new会产生异常，导致程序中止；
//   如果在new关键字后面加(std::nothrow)选项，则返回nullptr，不会产生异常。
//   int b[1000001];
//   b[1000000]=3;
//   cout<<b[1000000]<<endl; //数组过长，程序异常

    int *b = new (nothrow) int[10000000001];
    if (b==nullptr) cout<<"内存分配失败"<<endl;
    else {b[10000000000]=8; cout<<b[10000000000]<<endl; delete []b;}
}