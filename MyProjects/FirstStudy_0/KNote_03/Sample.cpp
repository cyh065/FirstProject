//Cast
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class KParent2
{
public:
	int		m_iValue;
};

class KParent
{
public:
	int		m_iValue;
	/*void SetName(char* pName)
	{
	}
	void Set(const int iValue)
	{
	}
	void print()const
	{
	}*/
	KParent() {}
	~KParent() {};
};

class KClass : public KParent
{
private:
	int		m_iNumber;
	char*	m_pName;
public:
	void	SetName(char* pName)
	{

		strcpy(m_pName, pName);
		cout << m_pName << endl;
	}
	void	Set(const int iValue)
	{
		m_iNumber = iValue;
	}
	void print()const
	{
		// const 속성을 예외처리
		const_cast<KClass*>(this)->m_iNumber = 100;;
		//this->m_iNumber = 100;
		cout << m_iNumber << endl;
	}
	void Delete()
	{
		delete m_pName;
	}
	void SetNew()
	{
		m_pName = new char[20];
	}
	KClass() { m_pName = new char[20];  }
	virtual~KClass() { delete m_pName; }
};

void main()
{
	int i = 100;
	int j = 200;
	float d = (float)i / j; //c언어 형식의 캐스팅
	//기본 데이터형의 형변환
	float e = static_cast<float>(i) / j; //c++언어 형식의 캐스팅

	KParent* f = new KParent();
	//KParent* c = (KParent*)f;
	//KClass* f = new KClass();
	//KParent* c = (KParent*)f;
	//KClass* c = dynamic_cast<KClass*>(f); // UP캐스팅
	/*if (c != NULL){	}*/

	// 아무런 조건 없이 형 변환
	// 책임없다. 런타임에서 오류가 발생할 수 있다.
	// 런타임에서 검사하지 않는다.
	//KParent2* w = static_cast<KParent2*>(f); //강제 Down 캐스팅
	KParent2* w = reinterpret_cast<KParent2*>(f);// 무조건 캐스팅
	w->Set(100);
	w->print();

	int iData = 100;
	w->Set(iData);
	const char name[] = "kgca";
	w->SetName(const_cast<char*>(name));
	
}