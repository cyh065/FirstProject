#include <iostream>
#include <cstdarg>
using namespace std;

void OutString(char* str, ...)
{
	va_list ap;
	va_start(ap, str);
		vfprintf(stderr, str, ap);
	va_end(ap);
}
int g_Array[10];
void OutString(int num, ...)
{
	va_list ap;
	va_start(ap, num);
	for (int i = 0; i < num; i++)
	{
		g_Array[i] = va_arg(ap, int);
		cout << g_Array[i];
	}
	va_end(ap);
}
class KClass
{
private:
	int m_iValue;
public:
	int Get() { return m_iValue; }
	KClass( int iValue) : m_iValue(iValue)
	{}
	KClass(KClass& copy) : m_iValue(copy.m_iValue)
	{}
	~KClass() {};
};
class KClassExplicit
{
private:
	int m_iValue;
public:
	int Get() { return m_iValue; }
	explicit KClassExplicit(int iValue) : m_iValue(iValue)
	{}
	KClassExplicit(KClassExplicit& copy) : m_iValue(copy.m_iValue)
	{}
	~KClassExplicit() {};
};
class KClassMutable
{
private:
	mutable int m_iValue;
public:
	int Get() const
	{ 
		m_iValue = 9;
		return m_iValue;
	}
	KClassMutable(int iValue) : m_iValue(iValue)
	{}
	KClassMutable(KClassMutable& copy) : m_iValue(copy.m_iValue)
	{}
	~KClassMutable() {};
};
void main()
{
	OutString("%d %d %d %f",1,2,3,4.0f);
	OutString("%d", 1);
	OutString("%d %f", 1, 4.0f);
	OutString( 3 , 1, 2, 3);

	KClass kA(3);
	KClass kB = 3; // 묵시적 
	KClass kC = kA;
	cout << kA.Get();
	cout << kB.Get();
	cout << kC.Get();

	KClassExplicit kD(3.0f);
	//KClassExplicit kE= 3; // 묵시적 형변환 방지
	KClassExplicit kF = kD;
	cout << kD.Get();
	//cout << kE.Get();
	cout << kF.Get();

	KClassMutable kG(3.0f);
	KClassMutable kH = 3; // 묵시적 형변환 방지
	KClassMutable kI = kG;
	cout << kG.Get();
	cout << kH.Get();
	cout << kI.Get();
}