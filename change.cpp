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
		sum1+=arr[i];//���������1�ĺ�
	}
	for(int j=0;j<len2;j++)
	{
		sum2+=brr[j];//���������2�ĺ�
		se.insert(brr[j]);//Ϊ�˱���˫��ѭ��,��brr��������set��
	}
	int avg=(sum1+sum2)/2;
	for(int k=0;k<len1;k++)
	{
		int t=avg-(sum1-arr[k]);//(avg+arr[k]-sum1)//ƽ��ֵ��ȥ��1�н�������ʣ���ֵ�Ľ������brr��Ҫ�����Ľ��  
		it=se.find(t);//�õ�����������2���ҵ���ֵ

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

	
