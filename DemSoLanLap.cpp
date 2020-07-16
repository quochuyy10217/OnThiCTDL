#include <iostream>
using namespace std;
//De Bai: Nhap vao 1 danh sach lien ket don, viec nhap ket thuc khi gia tri x = 0. In ra cac phan tu xuat hien nhieu lan nhat trong mang
struct node
{
    int info;
    int appear=1;
    node* pNext;
};

struct List
{
    node* pHead;
    node* pTail;
};

void CreateList(List &l)
{
    l.pHead=l.pTail=NULL;
}

node* CreateNode(int x)
{
    node* p = new node;
    p->info=x;
    p->pNext=NULL;
    return p;
}

void AddTail(List &l, node* p)
{
    if (l.pHead==NULL)
    {
        l.pHead=l.pTail=p;
    }
    else
    {
        l.pTail->pNext=p;
        l.pTail=p;
    }
}

void nhap(List &l)
{
    int x;
    while (1)
    {
        cin>>x;
        if (x==0) break;
        node* p = CreateNode(x);
        AddTail(l,p);
    }
}

void xuat(List l)
{
    for (node* i=l.pHead;i!=NULL;i=i->pNext)
    {
        cout<<i->info<<" ";
    }
    cout<<endl;
}

void DeleteNode(List &l, node* p, node* q)
{
    q->pNext=p->pNext;
    if (p==l.pTail) l.pTail=q;
    delete p;
}

void TimSoLanLap(List &l)
{
    int max=0;
    node* i=l.pHead;
    node* j=i->pNext;
    node* prevnode=l.pHead;
    while (i!=NULL)
    {
        while (j!=NULL)
        {
            if (j->info==i->info)
            {
                i->appear++;
                DeleteNode(l,j,prevnode);
                j=prevnode->pNext;
            }
            else
            {
                prevnode=j;
                j=j->pNext;
            }            
        }
        if (j==NULL)
        {
            if (i->appear>max) max=i->appear;
            if (i==l.pTail) break;
            i=i->pNext;
            prevnode=i;
            j=i->pNext;
        }
    }
    cout<<"Nhung phan tu lap lai nhieu lan nhat trong mang la: "<<endl;
    for (node* k=l.pHead;k!=NULL;k=k->pNext)
    {
        if (k->appear==max) cout<<k->info<<": "<<max<<endl;
    }
}

int main()
{
    List l;
    CreateList(l);
    nhap(l);
    if (l.pHead==NULL) cout<<"Danh sach rong."<<endl;
    else
    {
        xuat(l);
        TimSoLanLap(l);
    }
}