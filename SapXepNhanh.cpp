#include <iostream>
using namespace std;
// Ham doi cho 2 so nguyen
void Swap(int &a, int &b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
}
// Ham sap xep nhanh
void QuickSort(int arr[], int left, int right)
{
    int i,j,x;
    x=arr[(left+right)/2];
    i=left;
    j=right;
    while (i<=j)
    {
        while (arr[i]<x) i++;       //Doi chieu 2 dau < va > o 2 cau lenh arr[i] va arr[j] de sap xep giam dan
        while (arr[j]>x) j--;
        if (i<=j)
        {
            Swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    if (left<j) QuickSort(arr,left,j);
    if (i<right) QuickSort(arr,i,right);
}
// Main
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
    QuickSort(arr,0,n-1);
    for (int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}