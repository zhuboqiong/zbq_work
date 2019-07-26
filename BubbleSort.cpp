#include<iostream>
using namespace std;

//冒泡排序
void BubbleSort(int *arr,int len)
{
	for(int i=0;i<len;i++)
	{
		for(int j=0;j<len-i-1;j++)
		{
			if(arr[j]<arr[j+1])
			{
				int tmp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=tmp;
			}
		}
	}
}
//优化1//加flag标志位,如果没有交换数据,说明有序,flag设为0,交换数据的话设为1
void BubbleSort1(int *arr,int len)
{
	int flag=0;
	for(int i=0;i<len;i++)
	{
		flag=0;
		for(int j=0;j<len-i-1;j++)
		{
			if(arr[j]<arr[j+1])
			{
				flag=1;
				int tmp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=tmp;
			}
		}
		if(flag==0)
		{
			break;
		}
	}
}
//优化二//用一个变量记录下最后一个发生交换的位置，后面没有发生交换的已经有序
 //可以用这个值来作为下一次比较结束的位置
void BubbleSort2(int *arr,int len)
{
	int flag=len;//记录最后一个发生交换的位置
	int k=0;
	for(int i=0;i<flag;i++)
	{
		k=flag;
		flag=0;
		for(int j=0;j<k;j++)
		{
			if(arr[j]<arr[j+1])
			{
				flag=j;
				int tmp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=tmp;
			}
		}
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
	int arr[]={3,4,5,1,2};
	int len=sizeof(arr)/sizeof(arr[0]);
	//BubbleSort(arr,len);
	//BubbleSort1(arr,len);
	BubbleSort2(arr,len);
	Show(arr,len);
}

