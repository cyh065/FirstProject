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
//객체
class Point : public Point2
{
	//////////////// 멤버 변수 ////////////////
	//접근제어 연산자
public://클래스 외부로 비공개한다.
	const Point* Get() const { return this; }
	const Point& GetRef() const { return *this; }
public:
	//연산자 재정의 함수 선언
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
	//////////////// 멤버 함수 ////////////////
public://클래스 외부로 공개한다.
	static int	GetCount();
	// iX, iY 은 0~100범위로 제한한다.
	// 범위를 벗어 났을 경우 0으로 세팅된다.
	// 쓰기 전용
	const bool	SetPosition(int iX, int iY);
	void SetPosition(Point p1)
	{
		m_iX = p1.m_iX;
		m_iY = p1.m_iY;
	}
	// 읽기 전용
	const int		GetX() { return m_iX; }
	const int		GetY() { return m_iY; }
	void	Show();
	void	Delete();
	//////////////생성자 / 해제자 /////////////
public:
	// 기본 생성자
	Point();
	// 함수 오버로딩
	Point(int x, int y);
	Point(int x, int y, char* pData);
	//복사 생성자
	Point(Point& data);
	// 해제자
	~Point();
};
