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
// Ham chen truc tiep
void InsertionSort(int arr[], int n)
{
    int pos, i;
    int x;
    for (i=1;i<n;i++)
    {
        x=arr[i];
        pos=i-1;
        while (pos>=0&&arr[pos]>x)  //Thay arr[pos]>x thanh arr[pos]<x de sap xep giam dan
        {
            arr[pos+1]=arr[pos];
            pos--;
        }
        arr[pos+1]=x;
    }
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
    InsertionSort(arr,n);
    for (int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}