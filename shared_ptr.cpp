#include<iostream>
using namespace std;
class RefManage
{
public:
	static RefManage* getInstance()
	{
		return &rm;
	}
private:
	static RefManage rm;

	RefManage():length(0)
	{}
	RefManage(const RefManage& rhs);
public:
	void addRef(void* ptr)
	{
		if(ptr!=NULL)
		{
			int index=find(ptr);
			if(index<0)
			{
				arr[length].addr=ptr;
				arr[length++].refcount++;
			}
			else
			{
				arr[index].refcount++;
			}
		}
	}
	void delRef(void* ptr)
	{
		if(ptr!=NULL)
		{
			int index=find(ptr);
			if(index<0)
			{
				throw exception("addr is not exist");
			}
			else
			{
				if(getRef(ptr)!=0)
				{
					arr[index].refcount--;
				}
			}
		}
	}
	int getRef(void* ptr)
	{
		if(ptr==NULL)
		{
			return 0;
		}
		int index=find(ptr);
		if(index<0)
		{
			return -1;
		}
		else
		{
			return arr[index].refcount;
		}
	}
private:
	int find(void* ptr)
	{
		for(int i=0;i<length;++i)
		{
			if(arr[i].addr==ptr)
			{
				return i;
			}
		}
		return -1;
	}
	class Node
	{
	public:
		Node(void* ptr=NULL,int ref=0):addr(ptr),refcount(ref)
		{}
	public:
		void* addr;
		int refcount;
	};
	Node arr[10];
	int length;//数组元素的有效长度 当前可以插入的数组下标
};
template<typename T>
class Shared_ptr
{
public:
	Shared_ptr(T* ptr):mptr(ptr)
	{
		AddRef();
	}
	Shared_ptr(const Shared_ptr<T>& rhs):mptr(rhs.mptr)//拷贝构造函数
	{
		AddRef();
	}
	Shared_ptr<T>& operator=(const Shared_ptr<T>& rhs)
	{
		if(this!=&rhs)
		{
			DelRef();
			if(GetRef()==0)
			{
				delete mptr;
			}
			mptr=rhs.mptr;
			AddRef();
		}
		return *this;
	}
	~Shared_ptr()
	{
		DelRef();
		if(GetRef()==0)
		{
			delete mptr;
		}
		mptr=NULL;
	}
	T& operator*()
	{
		return *mptr;
	}
	T* operator->()
	{
		return mptr;
	}
private:
	void AddRef()
	{
		rm->addRef(mptr);
	}
	void DelRef()
	{
		rm->delRef(mptr);
	}
	int GetRef()
	{
		return rm->getRef(mptr);
	}
	T* mptr;
	static RefManage* rm;
};
template<typename T>
RefManage* Shared_ptr<T>::rm=new RefManage();
int main()
{
	int* p=new int;
	Shared_ptr<int> sp1(p);
	Shared_ptr<int> sp2(p);
	Shared_ptr<int> sp3(p);
	Shared_ptr<int> sp4(p);
	return 0;

}