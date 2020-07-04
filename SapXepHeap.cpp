#include <iostream>
using namespace std;
// Ham doi cho 2 so nguyen
void Swap( int &a, int &b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
}

void shift(int arr[], int left, int right)
{
    int x, i, j;
    i=left;
    j=2*i+1;  
    x=arr[i];
    while (j<=right)
    {
        if (j<right)
        if (arr[j]<arr[j+1]) j++;   
        if (arr[j]<=x) return;  //Thay dau < bang dau > de sap xep giam dan
        else
        {
            arr[i]=arr[j];
            arr[j]=x;
            i=j;
            j=2*i+1;
            x=arr[i];
        }
    }
}
// Ham tao heap
void CreateHeap(int arr[], int n)
{
    int left=n/2-1;
    while (left>=0)
    {
        shift(arr,left,n-1);
        left--;
    }
}

void HeapSort(int arr[], int n)
{
    int right;
    CreateHeap(arr,n);
    right=n-1;
    while (right>0)
    {
        Swap(arr[0],arr[right]);
        right--;
        if (right>0) shift(arr,0,right);
    }
}
/// Main
int main()
{
    int n;
    cout<<"Nhap n: ";
    cin>>n;
    int* arr = new int[n];
    for (int i=0;i<n;i++)
    {
        cout<<"Nhap gia tri thu "<<i<<": ";
        cin>>arr[i];
    }
    cout<<"Day so ban vua nhap la: "<<endl;
    for (int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Day so sau khi sap xep la: "<<endl;
    HeapSort(arr,n);
    for (int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}