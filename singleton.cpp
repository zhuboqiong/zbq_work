#include<iostream>
using namespace std;

class Singleton
{
public:
	static Singleton* getInstance()//����Ψһ�ӿ�,����Ϊstatic
	{
		if(psing==NULL)
		{
			psing=new Singleton();
		}
		return psing;
	}
private:
	Singleton(){}                    //���캯��
	Singleton(const Singleton&);     //�������캯��
	static Singleton* psing;         //��̬��Ա����,�����ʼ��
};
Singleton* Singleton::psing=NULL;
int main()
{
	Singleton* p1=Singleton::getInstance();
	Singleton* p2=Singleton::getInstance();
	Singleton* p3=Singleton::getInstance();
	return 0;
}

