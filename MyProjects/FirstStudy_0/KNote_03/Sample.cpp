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
		// const �Ӽ��� ����ó��
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
	float d = (float)i / j; //c��� ������ ĳ����
	//�⺻ ���������� ����ȯ
	float e = static_cast<float>(i) / j; //c++��� ������ ĳ����

	KParent* f = new KParent();
	//KParent* c = (KParent*)f;
	//KClass* f = new KClass();
	//KParent* c = (KParent*)f;
	//KClass* c = dynamic_cast<KClass*>(f); // UPĳ����
	/*if (c != NULL){	}*/

	// �ƹ��� ���� ���� �� ��ȯ
	// å�Ӿ���. ��Ÿ�ӿ��� ������ �߻��� �� �ִ�.
	// ��Ÿ�ӿ��� �˻����� �ʴ´�.
	//KParent2* w = static_cast<KParent2*>(f); //���� Down ĳ����
	KParent2* w = reinterpret_cast<KParent2*>(f);// ������ ĳ����
	w->Set(100);
	w->print();

	int iData = 100;
	w->Set(iData);
	const char name[] = "kgca";
	w->SetName(const_cast<char*>(name));
	
}