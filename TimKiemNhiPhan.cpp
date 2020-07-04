#include <iostream>
using namespace std;
//Ham tim kiem nhi phan, tra ve 1 neu tim thay, 0 neu khong tim thay
int BinarySearch(int a[], int n, int key)
{
    int left,right,mid;
    left=0;
    right=n-1;
    do
    {
        mid=(left+right)/2;
        if (a[mid]==key) return 1;
        else if (a[mid]<key) left=mid+1;
        else right=mid-1;
    } while (left<=right);
    return 0;
}
//Main
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
    cout<<"Nhap gia tri can tim kiem: ";
    int key;
    cin>>key;
    if (BinarySearch(arr,n,key)) cout<<"Da tim thay gia tri trong mang!"<<endl;
    else cout<<"Khong tim thay gia tri trong mang"<<endl;
    cout<<endl;
}