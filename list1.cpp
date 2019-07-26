#include<iostream>
#include<assert.h>
using namespace std;

typedef struct LinkList
{
	int data;
	struct LinkList *next;
}Node,*List;
void InitList(List head)
{
	assert(head!=NULL);
	if(head==NULL)
	{
		return ;
	}
	head->next=NULL;
}
static Node *BuyNode(int val)
{
	Node* p=(Node *)malloc(sizeof(Node));
	assert(p!=NULL);
	p->data=val;
	p->next=NULL;
	return p;
}
int Length(List head)
{
	Node* p=head->next;
	int count=0;
	while(p!=NULL)
	{
		count++;
		p=p->next;
	}
	return count;
}
bool Insert_Head(List head,int val)
{
	Node* p=BuyNode(val);
	p->next=head->next;
	head->next=p;
	return true;
}
bool Insert_Tail(List head,int val)
{
	Node* p=BuyNode(val);
	Node* q=head;
	while(q->next!=NULL)
	{
		q=q->next;
	}
	q->next=p;
	return true;
}
static Node * SearchPri(List list,int key)
{
	Node* p=list;
	while(p->next!=NULL)
	{
		if(p->next->data==key)
		{
			return p;
		}
	}
	return NULL;
}
bool Delete(List head,int val)
{
	Node* p=SearchPri(head,val);
	if(p==NULL)
	{
		return false;
	}
	Node* q=p->next;
	p->next=p->next->next;
	free(q);
	return true;
}
void Show(List head)
{
	Node* p=head->next;
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
}
//µ¥Á´±íÄæÖÃ
void Reserve(List head)
{
	assert(head!=NULL);
	if(head==NULL||head->next==NULL)
	{
		return ;
	}
	Node* p=head->next;
	Node* q;
	head->next=NULL;
	while(p!=NULL)
	{
		q=p->next;
		p->next=head->next;
		head->next=p;
		p=q;
	}
}
int main()
{
	Node head;
	InitList(&head);
	Insert_Head(&head,1);
	Insert_Head(&head,5);
	Insert_Tail(&head,3);
	Insert_Tail(&head,2);
	Insert_Tail(&head,6);
	Show(&head);
	Reserve(&head);
	Show(&head);
}