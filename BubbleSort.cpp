#include<iostream>
using namespace std;

//ð������
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
//�Ż�1//��flag��־λ,���û�н�������,˵������,flag��Ϊ0,�������ݵĻ���Ϊ1
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
//�Ż���//��һ��������¼�����һ������������λ�ã�����û�з����������Ѿ�����
 //���������ֵ����Ϊ��һ�αȽϽ�����λ��
void BubbleSort2(int *arr,int len)
{
	int flag=len;//��¼���һ������������λ��
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

