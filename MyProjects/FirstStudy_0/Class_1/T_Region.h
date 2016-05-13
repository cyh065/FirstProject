#pragma once
#include <iostream>
//	0,0		100,0//point
//
//0,200		200,200// size

//100,0	->	100
//
//
class T_Region
{
public:
	enum { POINT_POINT, POINT_SIZE };
private:
	int		m_iLeft;
	int		m_iTop;
	int		m_iRight; // m_iWidth
	int		m_iBottom;// m_iHeight
public:
	void	SetRect(int iL, int iT, int iR, int iB);
	void	Move(int iX, int iY);
	void	ReSize(int iWidth, int iHeight);
	void	GetCenterPoint(int& iX, int& iY) const;
	bool	IntersectRegion(const T_Region& r1,
							const T_Region& r2);
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

