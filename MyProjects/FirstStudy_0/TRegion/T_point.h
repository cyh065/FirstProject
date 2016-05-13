#pragma once
#include "Tstd.h"

class T_Region;
struct Point2
{
	union{
		struct {
			int		m_iX;
			int		m_iY;
		};
		int		v[2];
	};
};
//��ü
class Point : public Point2
{
	//////////////// ��� ���� ////////////////
	//�������� ������
public://Ŭ���� �ܺη� ������Ѵ�.
	const Point* Get() const { return this; }
	const Point& GetRef() const { return *this; }
public:
	//������ ������ �Լ� ����
	Point	operator ++(void); // ++p1
	Point	operator ++(int); //p1++
	Point	operator +(const Point& pt)const; //c= a+pt
	Point	operator +(int iValue) const;
	friend	Point operator +(int Value, const Point& p);
	Point&	operator=(const Point& pt);
	Point&	operator+=(const Point& pt);
	bool	operator ==(const Point& pt);

	int& operator[](int iIndex);

	void* operator new (size_t size)
	{
		return malloc(size);
	}
	void operator delete (void* p)
	{
		free(p);
	}
	friend ostream& operator << (ostream &os, const Point& p);
	friend istream& operator >> (istream &is, Point& p);
public:
	static int	g_iCount;
	T_Region * m_pRegion;
	void	Set(T_Region* a);
public:
	void	Compute(const T_Region* a);
	
	int		 GetX() const { return m_iX; }
	int		 GetY() const { return m_iY; }
	//////////////// ��� �Լ� ////////////////
public://Ŭ���� �ܺη� �����Ѵ�.
	static int	GetCount();
	// iX, iY �� 0~100������ �����Ѵ�.
	// ������ ���� ���� ��� 0���� ���õȴ�.
	// ���� ����
	const bool	SetPosition(int iX, int iY);
	void SetPosition(Point p1)
	{
		m_iX = p1.m_iX;
		m_iY = p1.m_iY;
	}
	// �б� ����
	const int		GetX() { return m_iX; }
	const int		GetY() { return m_iY; }
	void	Show();
	void	Delete();
	//////////////������ / ������ /////////////
public:
	// �⺻ ������
	Point();
	// �Լ� �����ε�
	Point(int x, int y);
	Point(int x, int y, char* pData);
	//���� ������
	Point(Point& data);
	// ������
	~Point();
};
