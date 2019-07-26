#include<iostream>
#include<stack>
using namespace std;

//快速排序
//递归
int Partition(int *arr,int low,int high)
{
	int tmp=arr[low];
	while(low<high)
	{
		while(low<high && tmp<=arr[high])//从右边开始找
		{
			high--;
		}
		if(low==high)//判断边界
		{
			break;
		}
		else
		{
			arr[low]=arr[high];
		}
		while(low<high && tmp>=arr[low])
		{
			low++;
		}
		if(arr[low]>tmp)
		{
			arr[high]=arr[low];
		}
		else
		{
			break;
		}
	}
	arr[low]=tmp;
	return low;
}
//void QuickSort(int *arr,int low,int high)
//{
//	int len=sizeof(arr)/sizeof(arr[0]);
//	int a=Partition(arr,low,high);
//	if(low+1<a)
//	{
//		QuickSort(arr,0,a-1);
//	}
//	if(a+1<high)
//	{
//		QuickSort(arr,a+1,high);
//	}
//}
//非递归
void QuickSort(int *arr,int low,int high)
{
	stack<int> st;
	st.push(low);//先入左
	st.push(high);//入右
	while(!st.empty())
	{
		int right=st.top();
		st.pop();
		int left=st.top();
		st.pop();

		int index=Partition(arr,left,right);
		if((index-1)>left)
		{
			st.push(left);
			st.push(index-1);
		}
		if((index+1)<right)
		{
			st.push(index+1);
			st.push(right);
		}
	}
}
//堆排序
void Adjust(int *arr,int n,int i)//调整堆//大根堆
{
	if(i>=n)
	{
		return ;
	}
	int c1=2*i+1;
	int c2=2*i+2;
	int max=i;
	if(c1<n && arr[c1]>arr[max])
	{
		max=c1;
	}
	if(c2<n && arr[c2]>arr[max])
	{
		max=c2;
	}
	if(max != i)
	{
		int tmp=arr[max];
		arr[max]=arr[i];
		arr[i]=tmp;
		Adjust(arr,n,max);
	}
}
//void Adjust(int *arr,int n,int i)//调整堆//小根堆
//{
//	if(i>=n)
//	{
//		return ;
//	}
//	int c1=2*i+1;
//	int c2=2*i+2;
//	int min=i;
//	if(c1<n && arr[c1]<arr[min])
//	{
//		min=c1;
//	}
//	if(c2<n && arr[c2]<arr[min])
//	{
//		min=c2;
//	}
//	if(min != i)
//	{
//		int tmp=arr[min];
//		arr[min]=arr[i];
//		arr[i]=tmp;
//		Adjust(arr,n,min);
//	}
//}
void BuildHeap(int *arr,int n)//建堆
{
	int last=n-1;
	int parent=(last-1)/2;
	for(int i=parent;i>=0;i--)
	{
		Adjust(arr,n,i);
	}
}
void HeapSort(int *arr,int n)//堆排序
{
	BuildHeap(arr,n);
	for(int i=n-1; i>=0; i--) 
	{
		int tmp=arr[i];
		arr[i]=arr[0];
		arr[0]=tmp;
		Adjust(arr,i,0);
	}
}
void Show(int *arr,int len)
{
	for(int i=0;i<len;i++)
	{
		cout<<arr[i]<<" ";
	}
}
int main()
{
	int arr[]={3,4,5,2,1};
	int len=sizeof(arr)/sizeof(arr[0]);
	QuickSort(arr,0,len-1);
	//HeapSort(arr,len);
	Show(arr,len);
}


