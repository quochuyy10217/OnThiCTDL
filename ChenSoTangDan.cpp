#include <iostream>
using namespace std;
// De bai: Nhap vao 1 danh sach lien ket don gom nhieu gia tri ngau nhien, viec nhap ket thuc khi gia tri nhap vao la 0
// Chen vao 1 gia tri sao cho khi chen xong thi in ra danh sach theo thu tu tang dan
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

void SapXepList(List &l)
{
    node* i=l.pHead;
    node*j=i->pNext;
    while (i!=l.pTail)
    {
        while (j!=NULL)
        {
            if (i->info>j->info)
            {
                int temp=i->info;
                i->info=j->info;
                j->info=temp;
            }
            j=j->pNext;
        }
        i=i->pNext;
        j=i->pNext;
    }
}

void ChenVaoList(List &l, int x)
{
    if (x<=l.pHead->info)
    {
        node* p = CreateNode(x);
        p->pNext=l.pHead;
        l.pHead=p;
    }
    else
    {
        node* p =l.pHead->pNext;
        node* q=l.pHead;
        while (p!=NULL)
        {
           node* g = CreateNode(x);
           if (x>l.pTail->info)
           {
               AddTail(l,g);
               break;
           }
           else if (x<=p->info)
           {
                g->pNext=q->pNext;
                q->pNext=g;
                break;              
           } 
           else
           {
               q=p;
               p=p->pNext;
           }
           
        }
    }
    
}

void xuat(List &l)
{
    for (node* i=l.pHead;i!=NULL;i=i->pNext)
    {
        cout<<i->info<<" ";
    }
    cout<<endl;
}

int main()
{
    List l;
    CreateList(l);
    cout<<"Nhap danh sach lien ket: "<<endl;
    nhap(l);
    cout<<"Danh sach ban vua nhap: ";
    xuat(l);
    int x;
    cout<<"Nhap gia tri ban muon chen vao: ";
    cin>>x;
    SapXepList(l);
    ChenVaoList(l,x);
    cout<<"Danh sach tang dan sau khi chen vao la: ";
    xuat(l);
    return 0;
}