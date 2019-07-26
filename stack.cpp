#include<iostream>
#include<stack>
using namespace std;

class Queue
{
public:
	int front();
	void Push(int val);
	void Pop();
private:
	stack<int> s1;
	stack<int> s2;
};
int Queue::front()
{
	if(s2.empty())
	{
		if(s1.size()==0)//s1,s2都为空
		{
			throw exception("error");
		}
		while(!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}
	}
	return s2.top();
}
void Queue::Push(int val)//入队列
{
	s1.push(val);
}
void Queue::Pop()//出队列
{
	if(s2.empty())
	{
		while(!s1.empty())
		{
			int p=s1.top();
			s2.push(p);//把s1的数据放到s2里
			s1.pop();
		}
	}
	if(!s2.empty())//s2不为空,直接出
	{
		s2.pop();
	}
}
int main()
{
	Queue que;
	int i;
	for(i=1;i<10;i++)
	{
		que.Push(i);//9,8,7,6,5,4,3,2,1
	}
	for(i=1;i<10;i++)
	{
		cout<<que.front()<<endl;
		que.Pop();//1,2,3,4,5,6,7,8,9
	}
}