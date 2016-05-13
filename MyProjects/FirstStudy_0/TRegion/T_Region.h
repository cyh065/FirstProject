#pragma once
#include <iostream>
#include "T_point.h"

//	0,0		100,0//point
//
//0,200		200,200// size

//100,0	->	100
//
//
struct Rect
{
	int		m_iLeft;
	int		m_iTop;
	int		m_iRight; // m_iWidth
	int		m_iBottom;// m_iHeight
};
class T_Region :public Rect
{
public:
	enum { POINT_POINT, POINT_SIZE };
	int		m_iValue;
private:
	Point	m_Center;
	
public:
	// 인라인화 된 함수
	int	GetLeft() const { return m_iLeft; }
	int	GetTop() const { return m_iTop; }

	void	SetRect(int iL, int iT, int iR, int iB);
	void	SetRect(Point& p1,Point& p2);
	void	SetRect(const Point& p1,
					const Point& p2);
	void	SetRect(const Point* const p1,
					const Point* const p2);
	void	Move(int iX, int iY);
	void	ReSize(int iWidth, int iHeight);
	void	GetCenterPoint(int& iX, int& iY) const;
	Point	GetCenterPoint();
	bool	IntersectRegion(const T_Region& r1,
			const T_Region& r2);
	friend bool	operator^(const T_Region& r1,
			const T_Region& r2);
	//bool	IntersectRegion2(const T_Region & r1,
			//const T_Region& r2);
	void	UnionRegion(const T_Region& r1,
		const T_Region& r2);
	//멤버 변수를 수정 할 수 없다.
	int		GetWidth() const;
	int		GetHeight() const;

	void Show();
public:
	T_Region();
	~T_Region();
};
