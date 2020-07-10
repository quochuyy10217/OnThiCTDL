#include <iostream>
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

void AddHead(List &l, node* p)
{
    if (l.pHead==NULL)
    {
        l.pHead=l.pTail=p;
    }
    else
    {
        p->pNext=l.pHead;
        l.pHead=p;
    }
    
}

void Input(List &l)
{
    int x;
    while (1)
    {
        cin>>x;
        if (x==0) break;
        node* p = CreateNode(x);
        AddHead(l,p);
    }
}

void Output(List l)
{
    for (node* i=l.pHead;i!=NULL;i=i->pNext)
        cout<<i->info<<" ";
    cout<<endl;
}

void XoaTrungLap(List &l)
{
    node* prevnode= l.pHead;
    node* i=l.pHead;
    node* j=i->pNext;
    while (i!=l.pTail)
    {
        while (j!=NULL)
        {
            if (i->info==j->info)
            {
                prevnode->pNext=j->pNext;
                if (j==l.pTail) l.pTail=prevnode;
                delete j;
                j=prevnode->pNext;
            }
            else
            {
                prevnode=j;
                j=j->pNext;
            }
        }
        i=i->pNext;
        prevnode=i;
        if (i==NULL) break;
        j=i->pNext;
    }

}

int main()
{
    List l;
    CreateList(l);
    Input(l);
    Output(l);
    XoaTrungLap(l);
    Output(l);
    return 0;
}
