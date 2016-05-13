#include "T_Region.h"

void	T_Region::UnionRegion(const T_Region& r1,
		const T_Region& r2)
{
	m_iLeft = (r1.m_iLeft < r2.m_iLeft) ? r1.m_iLeft : r2.m_iLeft;
	m_iRight = (r1.m_iRight > r2.m_iRight) ? r1.m_iRight : r2.m_iRight;

	m_iTop = (r1.m_iTop < r2.m_iTop) ? r1.m_iTop : r2.m_iTop;
	m_iLeft = (r1.m_iBottom > r2.m_iBottom) ? r1.m_iBottom : r2.m_iBottom;
}

bool	T_Region::IntersectRegion(
		const T_Region& r1,
		const T_Region& r2)
{
	m_iLeft = (r1.m_iLeft >  r2.m_iLeft) ? r1.m_iLeft : r2.m_iLeft;
	m_iRight = (r1.m_iRight < r2.m_iRight) ? r1.m_iRight : r2.m_iRight;

	m_iTop = (r1.m_iTop > r2.m_iTop) ? r1.m_iTop : r2.m_iTop;
	m_iLeft = (r1.m_iBottom < r2.m_iBottom) ? r1.m_iBottom : r2.m_iBottom;

	if (m_iLeft >= m_iRight || m_iTop >= m_iBottom)
	{
		m_iLeft = m_iRight = m_iTop = m_iBottom = 0;
		return false;
	}
	return true;
}

void	T_Region::Show()
{
	std::cout	<< " left: " << m_iLeft 
				<< " top: "  << m_iTop
				<< " right: " << m_iRight 
				<<" bottom: " << m_iBottom 
				<< std::endl;
}

void	T_Region::GetCenterPoint(int& iX, int& iY) const
{
	iX = (m_iRight + m_iLeft) / 2;
	iY = (m_iBottom + m_iTop) / 2;
}
void	T_Region::ReSize(int iWidth, int iHeight)
{
	int iCenterX;
	int iCenterY;
	GetCenterPoint(iCenterX, iCenterY);
	/*int iRadiusX = (m_iRight - m_iLeft) / 2;
	int iRadiusY = (m_iBottom - m_iTop) / 2;*/
	m_iLeft = iCenterX - iWidth / 2;
	m_iTop = iCenterY - iHeight / 2;
	m_iRight = m_iLeft + iWidth;//iCenterX + iWidth / 2
	m_iBottom = m_iTop + iHeight;//iCenterY + iHeight / 2;
}

void	T_Region::Move(int iX, int iY)
{
	m_iLeft += iX;
	m_iRight += iX;
	m_iTop += iY;
	m_iBottom += iY;
}

void	T_Region::SetRect(int iL, int iT, int iR, int iB)
{
	m_iLeft = iL;
	m_iRight = iR;
	m_iTop = iT;
	m_iBottom = iB;
}
int T_Region::GetWidth() const
{
	//point
	int iWidth = m_iRight - m_iLeft;
	return iWidth;
}

int T_Region::GetHeight() const
{
	//point
	int iHeigt = m_iBottom - m_iTop;
	return iHeigt;
}

T_Region::T_Region()
{
}


T_Region::~T_Region()
{
}

