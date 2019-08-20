#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

vector<int> Change(vector<int> arr,vector<int> brr)
{
	vector<int> res(2);
	int len1=arr.size();
	int len2=brr.size();
	int sum1=0;
	int sum2=0;
	set<int> se;
	set<int>::iterator it;
	for(int i=0;i<len1;i++)
	{
		sum1+=arr[i];//先求出数组1的和
	}
	for(int j=0;j<len2;j++)
	{
		sum2+=brr[j];//再求出数组2的和
		se.insert(brr[j]);//为了避免双层循环,把brr的数放入set中
	}
	int avg=(sum1+sum2)/2;
	for(int k=0;k<len1;k++)
	{
		int t=avg-(sum1-arr[k]);//(avg+arr[k]-sum1)//平均值减去把1中交换数字剩余的值的结果就是brr中要交换的结果  
		it=se.find(t);//用迭代器接收在2中找到的值

		if(it!=se.end())
		{
			res[0]=arr[k];
			res[1]=t;
			break;
		}
	}
	return res;
}
int main()
{
	int m;
	cin>>m;
	vector<int> arr;
	for(int i=0;i<m;i++)
	{
		int tmp;
		cin>>tmp;
		arr.push_back(tmp);
	}
	int n;
	cin>>n;
	vector<int> brr;
	for(int i=0;i<n;i++)
	{
		int tmp1;
		cin>>tmp1;
		brr.push_back(tmp1);
	}
	vector<int> res=Change(arr,brr);
	for(int i=0;i<res.size();i++)
	{
		cout<<res[i]<<" ";
	}
	cout<<endl;		
}

	
