#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;

#if 0
//合并两个有序数组
vector<int> Merge(vector<int> arr,vector<int> brr)
{
	int arrlen=arr.size();
	int brrlen=brr.size();
	int i=arrlen-1;
	int j=brrlen-1;
	int m=arrlen+brrlen-1;
	vector<int> vec(m+1);
	while(i>=0&&j>=0)
	{
		if(arr[i]>brr[j])
		{
			vec[m]=arr[i];
			i--;
			m--;
		}
		else if(arr[i]<brr[j])
		{
			vec[m]=brr[j];
			j--;
			m--;
		}
	}
	while(j>=0)
	{
		vec[m]=brr[j];
		j--;
		m--;
	}
	while(i>=0)
	{
		vec[m]=arr[i];
		i--;
		m--;
	}
	return vec;
}
int main()
{
	int m;
	cin>>m;
	vector<int> arr;
	vector<int> brr;
	for(int i=0;i<m;i++)
	{
		int tmp;
		cin>>tmp;
		arr.push_back(tmp);
	}
	for(int i=0;i<m;i++)
	{
		int temp;
		cin>>temp;
		brr.push_back(temp);
	}
	vector<int> vec=Merge(arr,brr);
	for(int i=0;i<vec.size();i++)
	{
		cout<<vec[i]<<" ";
	}
}
#endif 

//三元组x+y+z=0
//vector<vector<int>>  ThreeSum(vector<int> arr)
//{
//	int len=arr.size();
//	vector<vector<int>> res;
//	for(int i=0;i<len;i++)
//	{
//		int sum=-1*arr[i];//x+y=-z
//		
//		int left=i+1;
//		int right=len-1;
//		while(left<right)
//		{
//			int sum1=arr[left]+arr[right];
//			if(sum==sum1)
//			{
//				vector<int> brr(3);//把三元组放在这个里面
//				brr[0]=arr[i];//把三元组放在里面
//				brr[1]=arr[left];
//				brr[2]=arr[right];
//				res.push_back(brr);
//				while(left<right&&arr[left]==brr[1])
//				{
//					left++;
//				}
//				while(left<right&&arr[right]==brr[2])
//				{
//					right--;
//				}
//			}
//			else if(sum<sum1)
//			{
//				left++;
//			}
//			else if(sum>sum1)
//			{
//				right--;
//			}
//		}
//		while(i+1<len&&arr[i+1]==arr[i])//1,1,-2   -2,1,1
//		{
//			++i;
//		}
//	}
//	return res;
//}
//int main()
//{
//	vector<int> arr;
//	for(int i=0;i<5;i++)
//	{
//		int tmp;
//		cin>>tmp;
//		arr.push_back(tmp);
//	}
//	vector<vector<int>> res=ThreeSum(arr);
//	int l=res.size();
//	for(int i=0;i<l;i++)
//	{
//		for(int j=0;j<3;j++)
//		{
//			cout<<res[i][j];
//		}
//		cout<<endl;
//	}
//}