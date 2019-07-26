//赋值运算符函数
#include<iostream>

class CMyString
{
    public:
		CMyString(char *pData=NULL)
		{
			if(m_pData==NULL)
			{
				return ;
			}
			m_pData=new char[strlen(pData)+1]();
			strcpy(m_pData,pData);
			std::cout << "CMyString()"<<std::endl; 
		}
		CMyString(const CMyString & str)
		{
			m_pData=new char[strlen(str.m_pData)+1]();
			strcpy(m_pData,str.m_pData);
			std::cout << "CMyString(const CMyString str)"<<std::endl; 
		}
		~CMyString(void)
		{
            delete [] m_pData;
			m_pData=NULL;
			std::cout << "~CMyString()"<<std::endl; 
		}
		void operator=(const CMyString &src)
		{
			if(this==&src)
			{
				return ;
			}
			delete [] m_pData;
		    m_pData=new char[strlen(src.m_pData)+1]();
			memcpy(m_pData,src.m_pData,strlen(src.m_pData)+1);
			std::cout << "operator=(const CMyString src)"<<std::endl; 
		}
		char *GetString()
		{
			return m_pData;
		}
private:
	char * m_pData;
};

int main()
{
	CMyString str1("hello");
	CMyString str2("abc");
	str2=str1;
	std::cout << str2.GetString()<< std::endl;
}
//二维数组中的查找
/*#include<stdio.h>
bool Search(int arr[][4],int rows,int cols,int num)
{
	if(arr != NULL && rows > 0 && cols > 0)
	{
		int row=0;
		int col=cols-1;
		while(row<rows && col>=0)
		{
			if(arr[row][col]==num)
			{
				return true;
			}
			else if(arr[row][col]>num)
			{
				--col;
			}
			else
			{
				++row;
			}	
		}
		return false;
	}
	return false;
}
int main()
{
	int arr[4][4]={{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
	if(Search(arr,4,4,7))
	{
		printf("find\n");
	}
	printf("not find\n");
}*/


