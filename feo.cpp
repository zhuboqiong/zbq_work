#include<iostream>
#include<assert.h>
#include<stack>
#include<queue>
#include<string>

using namespace std;

#if 0
//两个栈实现一个队列
template<typename T>
class CQueue
{
public:
	CQueue(void);
	~CQueue(void);
	void appendTail(const T& node);
	T deleteHead();
private:
	stack<T> stack1;
	stack<T> stack2;
};
template<typename T>
CQueue<T>::CQueue(void){}
template<typename T>
CQueue<T>::~CQueue(void){}
template<typename T>
void CQueue<T>::appendTail(const T& node)
{
	stack1.push(node);
}
template<typename T>
T CQueue<T>::deleteHead()
{
	if(stack2.size()<=0)//s2不为空
	{
		while(stack1.size()>0)//s1不为空
		{
			T& p=stack1.top();
			stack1.pop();
			stack2.push(p);
		}
	}
	if(stack2.size()==0)//s2为空,抛出异常
	{
		throw new exception("queue is empty!");
	}
	T& head=stack2.top();
	stack2.pop();
	return head;
}
int main()
{
	CQueue<int> que;
	que.appendTail(1);
	que.appendTail(2);
	que.appendTail(3);
	que.appendTail(4);
	int head=que.deleteHead();
	cout<<head<<endl;
	int head1=que.deleteHead();
	cout<<head1<<endl;
	int head2=que.deleteHead();
	cout<<head2<<endl;
	int head3=que.deleteHead();
	cout<<head3<<endl;
}

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
//从尾到头打印链表
void ReservePrint(List head)
{
	stack<Node* > st;
	Node* p=head->next;
	while(p!=NULL)
	{
		st.push(p);
		p=p->next;
	}
	while(!st.empty())//判断栈不为空
	{
		p=st.top();
		cout<<p->data<<" ";
		st.pop();
	}
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
int main()
{
	Node head;
	InitList(&head);
	Insert_Tail(&head,1);
	Insert_Tail(&head,2);
	Insert_Tail(&head,3);
	Insert_Tail(&head,4);
	Insert_Tail(&head,5);
	ReservePrint(&head);
	//Show(&head);
}

//力扣
//给定一个仅包含小写字母的字符串，去除字符串中重复的字母，
//使得每个字母只出现一次。需保证返回结果的字典序最小（要求不能打乱其他字符的相对位置）
 string removeDuplicateLetters(string s)
{
	int m[256]={0};
	int visit[256]={0};//标记字母是否出现过
	string res="0";
	for(auto a : m) //auto匹配适合的类型//a下标
	{
		m[a]++;
	}
	for(auto a : s)//a字符型
	{
		--m[a];
		if(visit[a])
		{
			continue;
		}
		while(a<res.back() && m[res.back()])
		{
			visit[res.back()]=0;
			res.pop_back();
		}
		res+=a;
		visit[a]=1;
	}
	return res.substr(1);//0位置放的0,所以从1开始提取字符	
}
 int main()
 {
	 string s="bcabc";
	 string t=removeDuplicateLetters(s);
	 cout<< t <<endl;
 }

//两个队列模拟一个栈
template<typename T>
class CStack
{
public:
	CStack(void);
	~CStack(void);
	void Append(const T& node);
	T deleteHead();
private:
	queue<T> que1;
	queue<T> que2;
};
template<typename T>
CStack<T>::CStack(void){}
template<typename T>
CStack<T>::~CStack(void){}
template<typename T>
void CStack<T>::Append(const T& node)
{
	if(!que1.empty())
	{
		que1.push(node);
	}
	else
	{
		que2.push(node);
	}
}
template<typename T>
T CStack<T>::deleteHead()
{
	int r=0;
	if(!que1.empty())
	{
		int num=que1.size();
		while(num>1)
		{
			que2.push(que1.front());
			que1.pop();
			--num;
		}
		r=que1.front();
		que1.pop();
	}
	else
	{
		int num=que2.size();
		while(num>1)
		{
			que1.push(que2.front());
			que2.pop();
			--num;
		}
		r=que2.front();
		que2.pop();
	}
	return r;
}
int main()
{
	CStack<int> st;
	st.Append(1);
	st.Append(2);
	st.Append(3);
	st.Append(4);
	int head1=st.deleteHead();
	cout<<head1<<endl;
	int head2=st.deleteHead();
	cout<<head2<<endl;
	int head3=st.deleteHead();
	cout<<head3<<endl;
	int head4=st.deleteHead();
	cout<<head4<<endl;
}
#endif 
//旋转数组中的最小数字
int MidOrder(int *arr,int left,int right)//顺序遍历
{
	int r=arr[left];
	for(int i=left+1;i<=right;i++)
	{
		if(r>arr[i])
		{
			r=arr[i];
		}
	}
	return r;
}
int Mid(int *arr,int len)
{
	if(arr==NULL||len<=0)
	{
		throw exception("error");
	}
	int left=0;
	int right=len-1;
	int mid=left;
	while(arr[left]>=arr[right])
	{
		if(right-left==1)//如果差值为1,则说明找到了,right所指向的即为最小的元素
		{
			mid=right;
			break;
		}
		mid=(left+right)/2;
		if( arr[left]==arr[right] && arr[mid]==arr[left])//如果三个数字相等,就只能顺序查找
		{
			return MidOrder(arr,left,right);
		}
		if(arr[mid]>=arr[left])//缩小范围
		{
			left=mid;
		}
		else if(arr[mid]<=arr[right])//缩小范围
		{
			right=mid;
		}
	}
	return arr[mid];
}
int main()
{
	//int arr[5]={3,4,5,1,2};
	int arr[5]={1,0,1,1,1};
	int len=sizeof(arr)/sizeof(arr[0]);
	int a=Mid(arr,len);
	cout<<a<<endl;
}

	
