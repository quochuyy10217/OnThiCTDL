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
	l.pHead = l.pTail = NULL;
}

node* CreateNode(int x)
{
	node* p = new node;
	p->info = x;
	p->pNext = NULL;
	return p;
}

void AddTail(List &l, node* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}

void SortIncrease(List &l)      //Ham sap xep tang dan
{
	node* i = l.pHead;
	node* j = i->pNext;
	while (i != l.pTail)
	{
		while (j != NULL)
		{
			if (i->info > j->info)
			{
				int temp = i->info;
				i->info = j->info;
				j->info = temp;
			}
			j = j->pNext;
		}
		i = i->pNext;
		j = i->pNext;
	}
}

void Tron2List(List &l1, List &l2, List &l3)    //Ham tron 2 danh sach lien ket don l1, l2 thanh danh sach moi l3
{
	node* p;
	while (l1.pHead != NULL&&l2.pHead != NULL)
	{
		if (l1.pHead->info < l2.pHead->info)
		{
			p = l1.pHead;
			l1.pHead = l1.pHead->pNext;
			p->pNext = NULL;
		}
		else
		{
			p = l2.pHead;
			l2.pHead = l2.pHead->pNext;
			p->pNext = NULL;
		}
		AddTail(l3, p);
	}
	if (l1.pHead != NULL)
	{
		l3.pTail->pNext = l1.pHead;
		l3.pTail = l1.pTail;
	}
	if (l2.pHead != NULL)
	{
		l3.pTail->pNext = l2.pHead;
		l3.pTail = l2.pTail;
	}
}

void nhap(List &l)
{
	int x;
	while (1)
	{
		cin >> x;
		if (x == 0) break;
		node* p = CreateNode(x);
		AddTail(l, p);
	}
}

void xuat(List &l)
{
	for (node* i = l.pHead; i != NULL; i = i->pNext)
		cout << i->info << " ";
	cout << endl;
}

int main()
{
	List l1,l2;
	CreateList(l1);
	CreateList(l2);
	nhap(l1);   //Nhap gia tri danh sach l1, ket thuc khi nhap gia tri = 0
	nhap(l2);   //Nhap gia tri danh sach l2, ket thuc khi nhap gia tri = 0
	bool check = true;
	if (l1.pHead == NULL)
	{
		cout << "Danh sach l1 rong." << endl;
		check = false;
	}
	else
	{
		cout << "Danh sach l1 vua nhap la: ";
		xuat(l1);
	}
	if (l2.pHead == NULL)
	{
		cout << "Danh sach l2 rong." << endl;
		check = false;
	}
	else
	{
		cout << "Danh sach l2 vua nhap la: ";
		xuat(l2);
	}
	if (check == false) cout << "Khong tron duoc." << endl;
	else
	{
		SortIncrease(l1);       //Sap xep tang dan danh sach l1
		SortIncrease(l2);       //Sap xep tang dan danh sach l2
		List l3;
		CreateList(l3);
		Tron2List(l1, l2, l3);  //Tron 2 danh sach
		xuat(l3);
	}
	return 0;
}