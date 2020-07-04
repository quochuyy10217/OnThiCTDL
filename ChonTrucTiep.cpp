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
// Ham sap xep chon truc tiep
void SelectionSort(int arr[], int n)
{
    int min, i,j;
    for (i=0;i<n-1;i++)
    {
        min=i;
        for (j=i+1;j<n;j++)
        {
            if (arr[min]>arr[j]) min=j; //Thay dau > thanh dau < khi muon sap xep giam dan
        }
        if (min!=i) Swap(arr[i],arr[min]);
    }
}
// Chuong trinh chinh
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
    cout<<"Day so cua ban sau khi sap xep la: "<<endl;
    SelectionSort(arr,n);
    for (int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}