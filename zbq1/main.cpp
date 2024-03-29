#include<stdio.h>
#include<string.h>
//二维数组中的查找
/*int Bin_Search(int *arr,int len,int key)
{
	int left=0;
	int right=len-1;
	int mid=0;
	while(left<=right)
	{
		mid=(right+left)/2;
		if(arr[mid]==key)
		{
			return mid;
		}
		else if(arr[mid]<key)
		{
			left=mid+1;
		}
		else
		{
			right=mid-1;
		}
	}
	return mid;
}  
bool Search(int (*arr)[4],int key)
{
	int row=4;
	int col=4;
	int j=0;
	for(int i=0;i<row;i++)
	{
		j=Bin_Search(arr[i],col,key);
		if(arr[i][j]==key)
		{
			return true;
		}
		else
		{
			col=j+1;
		}
	}
	return false;
}
int main()
{
	int arr[4][4]={1,2,8,9,2,4,9,12,4,7,10,13,6,8,11,15};
	if(Search(arr,7))
	{
		printf("找到\n");
	}
	else
	{
	printf("没找到\n");
	}
}*/
//替换空格
/*void Replace(char str[],int len)
{
	if(str==NULL || len<=0)
	{
		return ;
	}
	int len1=0;//原来的字符串长度
	int number=0;//空格总数
	int i=0;
	while(str[i]!='\0')
	{
		++len1;
		if(str[i]==' ')
		{
			++number;
		 }
		++i; 
   } 
	 int len3=len1+(number*2);//现在的字符串长度 
	 if(len3 > len)
	 {
	    return ;
	 }
	 int index=len3;//现在的数组下标 
	 int index1=len1;//原来的数组下标 
	 while(index1 >= 0 && index > index1)
	 {
	 	 if(str[index1]==' ')
		  {
		     str[index--]='0';
			 str[index--]='2';
			 str[index--]='%';	
		  } 
		  else
		  {
		  	str[index]=str[index1];
			index--;
		  }
		 index1--;
     }
}
int main()
{
	char  str[30]= "we are happy.";
	printf("%s\n",str); 
	Replace(str,30);
	printf("%s\n",str); 
}*/
//斐波拉切数列
/*int Fibonacci(int n)//O(n)
{
	int r[2]={0,1};
	if(n<2)
	{
		return r[n];
	}
	int first=1;
	int second=0;
	int fn=0;
	for(int i=2;i<=n;i++)
	{
		fn=first+second;
		second=first;
		first=fn;
	}
	return fn;
}
int main()
{
	int a=Fibonacci(0);
	printf("%d\n",a);
	int b=Fibonacci(1);
	printf("%d\n",b);
	int c=Fibonacci(2);
	printf("%d\n",c);
	int d=Fibonacci(3);
	printf("%d\n",d);
	int e=Fibonacci(4);
	printf("%d\n",e);
	int f=Fibonacci(5);
	printf("%d\n",f);
}*/
//二进制中一的个数
/*int Count(int n)
{
	int count=0;
	while(n)//判断1的个数：n&(n-1)
	{
		count++;
		n=n&(n-1);
	}
	return count;
}
int main()
{
    int a=Count(9);
	printf("%d\n",a);
	int b=Count(-1);
	printf("%d\n",b);
	int c=Count(0);
	printf("%d\n",c);
}*/
//数值的整数次方
/*double Power(double base,unsigned int exponent)
{
	if(exponent==0)//任何数的0次方都是1
	{
		return 1;
	}
	if(exponent==1)//任何数的1次方都是任何数
	{
		return base;
	}
	double result=Power(base,exponent >> 1);//右移代替除2
	result*=result;
	if((exponent&(0x1)) == 1 )//判断是否为奇数
	{
		result*=base;
	}
	return result;
}
bool equal(double num1,double num2)//浮点数判断大小
{
	if((num1-num2>-0.0000001) && (num1-num2<0.0000001))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool input=false;
double Power1(double base,int exponent)
{
	input=false;
	if(equal(base,0.0) && exponent<0 )
	{
		input=true;
		return 0.0;
	}
	unsigned int exponent1=(unsigned int)(exponent);
	if(exponent<0)
	{
		exponent1=(unsigned int)(-exponent);//负数求绝对值
	}
	double result=Power(base,exponent1);
	if(exponent<0)
	{
		result=1.0 / result;//求倒数
	}
	return result;
}
int main()
{
	double a=Power1(2.0,5);
	printf("%f\n",a);
	double a1=Power1(2.0,-5);
	printf("%f\n",a1);
	double a2=Power1(-2.0,-5);
	printf("%f\n",a2);
	double b=Power1(5.0,-1);
	printf("%f\n",b);
	double b1=Power1(5.0,0);
	printf("%f\n",b1);
	double b2=Power1(0.0,-1);
	printf("%f\n",b2);
}*/
//奇数放在偶数的前面
/*void Adjust(int *arr,int len)
{
	if(arr==NULL||len==0)
	{
		return ;
	}
	int *start=arr;
	int *end=arr+len-1;
	while(start<end)
	{
		while(start<end && (*start&0x1)!=0)
		{
			start++;
		}
		while(start<end && (*end&0x1)==0)
		{
			end--;
		}
		if(start<end)
		{
			int temp=*start;
			*start=*end;
			*end=temp;
		}
	}
}
void Show(int *arr,int len)
{
	for(int i=0;i<len;i++)
	{
		printf("%d ",arr[i]);
	}
}
int main()
{
    int arr[]={1,2,3,4,5};
	Show(arr,sizeof(arr)/sizeof(arr[0]));
	Adjust(arr,sizeof(arr)/sizeof(arr[0]));
	Show(arr,sizeof(arr)/sizeof(arr[0]));
}*/
//旋转数组的最小数字
/*int Middle(int *arr,int len)
{
	if(arr==NULL||len<=0)
	{
		return -1;
	}
	int head=0;
	int tail=len-1;
	int mid=head;
	while(arr[head]>=arr[tail])
	{
		if(tail-head==1)
		{
			mid=tail;
			break;
		}
		mid=(head+tail)/2;
		if(arr[mid]>=arr[head])
		{
			head=mid;
		}
		else  if(arr[mid]<=arr[tail])
		{
			tail=mid;
		}
	}
	return arr[mid];
}
int main()
{
	int arr[5]={3,4,5,1,2};
	int a=Middle(arr,5);
	printf("%d\n",a);
}*/
//两个栈实现一个队列
#include<iostream>
#include<stack>
#include<queue>
/*template <typename T>
class CQueue
{
public:
	CQueue(void);
	~CQueue(void);
	void appendTail(const T&  node);
	T deleteHead();
private:
	std::stack<T> s1;
	std::stack<T> s2;
};
template<typename T>
CQueue<T>::CQueue(void)
{
}
template<typename T> 
CQueue<T>::~CQueue(void)
{
}
template<typename T> 
void CQueue<T>::appendTail(const T& node)
{
	s1.push(node);
}
template<typename T> 
T CQueue<T>::deleteHead()
{
	if(s2.size()<=0)
	{
		while(!s1.empty())
		{
			T& data=s1.top();
			s1.pop();
			s2.push(data);
		}
	}
	if(s2.size()==0)
	{
		printf("queue is empty!");
	}
	T& head=s2.top();
	s2.pop();
	return head;
}
 
int main()
{
	CQueue<int> queue;
	queue.appendTail(1);
	queue.appendTail(2);
	queue.appendTail(3);
	int head=queue.deleteHead();
	std::cout<<head<<std::endl;
	head=queue.deleteHead();
	std::cout<<head<<std::endl;
	queue.appendTail(4);
	head=queue.deleteHead();
	std::cout<<head<<std::endl;
	head=queue.deleteHead();
	std::cout<<head<<std::endl;
}*/
//两个队列实现一个栈
/*template <typename T>
class CStack
{
public:
	CStack(void);
	~CStack(void);
	void appendTail(const T&  node);
	T deleteHead();
private:
	std::queue<T> q1;
	std::queue<T> q2;
};
template<typename T>
CStack<T>::CStack(void)
{
}
template<typename T> 
CStack<T>::~CStack(void)
{
}
template<typename T> 
void CStack<T>::appendTail(const T& node)
{
	if(!q1.empty())
	{
	q1.push(node);
	}
	else
	{
		q2.push(node);
	}
}
template<typename T> 
T CStack<T>::deleteHead()
{
	int r=0;
	if(!q1.empty())
	{
		int num=q1.size();
		while(num>1)
		{
			q2.push(q1.front());
			q1.pop();
			--num;
		}
		r=q1.front();
		q1.pop();
	}
	else
	{
       int num=q2.size();
		while(num>1)
		{
			q1.push(q2.front());
			q2.pop();
			--num;
		}
		r=q2.front();
		q2.pop();
	}
	return r;
}
int main()
{
	CStack<int> stack;
	stack.appendTail(1);
	stack.appendTail(2);
	stack.appendTail(3);
	stack.appendTail(4);
	stack.appendTail(5);
	int head=stack.deleteHead();
	std::cout<<head<<std::endl;
	head=stack.deleteHead();
	std::cout<<head<<std::endl;
	head=stack.deleteHead();
	std::cout<<head<<std::endl;
	head=stack.deleteHead();
	std::cout<<head<<std::endl;
	head=stack.deleteHead();
	std::cout<<head<<std::endl;
}*/
//从尾到头打印链表
/*class CLink;
class Node
{
public:
	Node(int data)
	{
		val=data;
		next=NULL;
	}
	~Node(){}
public:
	int val;
	Node * next;
};
class CLink
{
public:
	CLink()
	{
		head=new Node(0);
	};
	~CLink()
	{
		Node* pCur = head;
		Node* pNext = pCur;
		while (pCur != NULL)
		{
			pNext = pCur->next;
			delete pCur;
			pCur = pNext;
		}
		head= NULL;
	}
	void Insert(int val)
	{
		Node* pnewnode = new Node(val);
		Node* ptail = head;
		while (ptail->next != NULL)
		{
			ptail = ptail->next;
		}
		ptail->next = pnewnode;

	}
	void PrintReverse()
	{
		std::stack<Node *> nodes;
		Node *pNode=head->next;
		while(pNode!=NULL)
		{
			nodes.push(pNode);
			pNode=pNode->next;
		}
		while(!nodes.empty())
		{
			pNode=nodes.top();
			printf("%d\n",pNode->val);
			nodes.pop();
		}
	}
	Node * head;
};
int main()
{
	CLink n1;
	for (int i = 0; i < 10; i++)
	{
		n1.Insert(i + 1);
	}
	n1.PrintReverse();
}*/
//O(1)删除结点  
/*struct ListNode  
{  
    int m_nValue;  
    ListNode* m_pNext;  
};   
ListNode* CreateListNode(int value)  
{
	ListNode *pNode=new ListNode();  
    pNode->m_nValue=value;  
    pNode->m_pNext=NULL;  
    return pNode;  
}   
void PrintList(ListNode* pHead)  
{  
    ListNode *pNode=pHead;  
    while(pNode!=NULL)  
    {  
        std::cout<<pNode->m_nValue<<" ";  
        pNode=pNode->m_pNext;  
    }  
    std::cout<<std::endl;  
}    
void ConnectListNode(ListNode* pCur,ListNode* pNext)  
{  
    if(pCur==NULL)  
    {
		std::cout<<"前一个结点不为空"<<std::endl;  
    }  
    else  
    {
		pCur->m_pNext=pNext;  
    }  
}  
void DeleteNode(ListNode** pListHead,ListNode* pToBeDeleted)  
{  
    if(pToBeDeleted->m_pNext!=NULL)//如果要删除结点后面还有结点  
    {  
        ListNode* pNext=pToBeDeleted->m_pNext;  
        pToBeDeleted->m_nValue=pNext->m_nValue;  
        pToBeDeleted->m_pNext=pNext->m_pNext;  
        delete pNext;  
        pNext=NULL;  
    }  
    else if(*pListHead==pToBeDeleted)//如果链表只有一个结点  
    {  
        delete pToBeDeleted;  
        pToBeDeleted=NULL;  
        *pListHead=NULL;  
    }  
    else//如果链表有多个结点，且删除最后一个结点，那么只能遍历链表  
    {  
        ListNode *pNode=*pListHead;  
        while(pNode->m_pNext!=pToBeDeleted)
		{
			pNode=pNode->m_pNext;
		}
        pNode->m_pNext=NULL;  
        delete pToBeDeleted;  
        pToBeDeleted=NULL;  
    }  
}    
int main()  
{ 
    ListNode* pNode1=CreateListNode(1); 
    ListNode* pNode2=CreateListNode(2);  
    ListNode* pNode3=CreateListNode(3);  
    ListNode* pNode4=CreateListNode(4);  
    ConnectListNode(pNode1,pNode2);
    ConnectListNode(pNode2,pNode3);  
    ConnectListNode(pNode3,pNode4);  
    PrintList(pNode1);  
    DeleteNode(&pNode1,pNode3); 
    PrintList(pNode1);
}*/  


                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  