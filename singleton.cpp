#include<iostream>
using namespace std;

class Singleton
{
public:
	static Singleton* getInstance()//生成唯一接口,设置为static
	{
		if(psing==NULL)
		{
			psing=new Singleton();
		}
		return psing;
	}
private:
	Singleton(){}                    //构造函数
	Singleton(const Singleton&);     //拷贝构造函数
	static Singleton* psing;         //静态成员变量,类外初始化
};
Singleton* Singleton::psing=NULL;
int main()
{
	Singleton* p1=Singleton::getInstance();
	Singleton* p2=Singleton::getInstance();
	Singleton* p3=Singleton::getInstance();
	return 0;
}

