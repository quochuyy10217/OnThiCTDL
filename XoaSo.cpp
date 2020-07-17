#include <iostream>
using namespace std;
// De bai: nhap vao 1 danh sach lien ket don, viec nhap ket thuc khi gia tri nhap vao bang 0. 
// Nhap vao 1 so nguyen x. Hay xoa tat ca cac so nguyen co gia tri bang x trong danh sach
struct node
{
    int info;
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

void XoaNode(List &l, int x)
{
    while (l.pHead!=NULL)       //Kiem tra xem cac gia tri dau list co bang x khong, neu co thi xoa
    {
        if (l.pHead->info==x)
        {
            node* g =l.pHead;
            l.pHead=l.pHead->pNext;
            delete g;
        }
        else break;
    }
    if (l.pHead==NULL) return;
    node* p=l.pHead->pNext;
    node* q=l.pHead;
    while (p!=NULL)         //Kiem tra xem co gia tri nao bang x khong, co thi xoa
    {
        if (p->info==x)
        {
            q->pNext=p->pNext;
            if (l.pTail==p) l.pTail=q;
            delete p;
            p=q;
        }
        else
        {
            q=p;
        }
        p=p->pNext;
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
        int x;
        cout<<"Nhap gia tri x: ";
        cin>>x;
        XoaNode(l,x);
        if (l.pHead==NULL) cout<<"Danh sach sau khi xoa rong."<<endl;
        else xuat(l);
    }
    return 0;
}