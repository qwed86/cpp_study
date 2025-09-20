# include<iostream>
using namespace std;
 
int mid_search(int arr[],int len, int key)
{
    int low=0, high=len-1, mid;
    while (low<=high)
    {
        mid= (high+low)/2;
        if (arr[mid]==key)
        {return mid;}

        else if (arr[mid]<key)
        {high=mid-1;}

        else if (arr[mid]>key)
        {low=mid+1;}
        

    }
    return -1;
}

int main()
{
    int a[]={-1,-2,-3,-4,-6,-9}; //一定要排序完再查找
    int key =-9, len=sizeof(a)/sizeof(a[0]);
    if (mid_search(a,len, key)>=0) 
    cout<<"查找成功"<<"a["<<mid_search(a, len, key)<<"]="<<key<<endl;
    else cout<<"查找失败"<<endl;
    
}