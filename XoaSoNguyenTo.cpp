#include <iostream>
#include <math.h>
using namespace std;

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

void xuat(List &l)
{
    for (node* i=l.pHead;i!=NULL;i=i->pNext)
    {
        cout<<i->info<<" ";
    }
    cout<<endl;
}

bool ktsnt(int x)       //Ham kiem tra so nguyen to
{
    if (x<2) return false;
    for (int i=2;i<=sqrt(x);i++)
    {
        if (x%i==0) return false;
    }
    return true;
}

void XoaSoNguyenTo(List &l)     //Ham xoa cac so nguyen to trong danh sach
{
    node* i=l.pHead;
    node* prevnode = i;
    while (i!=NULL)
    {
        if (ktsnt(i->info))
        {
            if (i==l.pHead)
            {
                node* g;
                g=i;
                i=i->pNext;
                l.pHead=i;
                delete g;
            }
            else
            {
                prevnode->pNext=i->pNext;
                delete i;
                i=prevnode;
            }
        }
        else
        {
            prevnode=i;
            i=i->pNext;    
        }
        
    }
}

int main()
{
    List l;
    CreateList(l);      //Khoi tao danh sach lien ket don
    nhap(l);
    xuat(l);
    if (l.pHead==NULL) cout<<"Danh sach rong."<<endl;       //Neu danh sach rong thi thong bao rong va ket thuc
    else
    {
        XoaSoNguyenTo(l);       //Xoa cac so nguyen to trong danh sach
        if (l.pHead==NULL) cout<<"Danh sach sau khi xoa rong!"<<endl;
        else
        {
            cout<<"Danh sach sau khi xoa la: ";
            xuat(l);
        }
    }
    return 0;
}
