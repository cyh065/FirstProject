#include "T_point.h"

int Point::g_iCount = 0;

ostream& operator << (ostream &os, const Point& p)
{
	os << "x=" << p.m_iX << "," << "y=" << p.m_iY << endl;
}

istream& operator >> (istream &is, Point& p)
{
	is >> p.m_iX;
	is >> p.m_iY;
	return is;
}
int& Point::operator[](int iIndex)
{
	return v[iIndex];
}

Point Point::operator ++(void)  //++p1
{
	++m_iX;
	++m_iY;
	return *this;
}
Point Point::operator ++(int)  //p1++
{
	Point temp = *this;
	m_iX++;
	m_iY++;
	return temp;
}
Point Point::operator +(const Point& pt) const
{
	Point temp;
	m_iX = m_iX + pt.m_iX;
	m_iY = m_iY + pt.m_iY;
	return temp;
}
Point Point::operator +(int iValue) const
{
	Point temp;
	m_iX = m_iX + iValue;
	m_iY = m_iY + iValue;
	return temp;
}
Point operator +(int Value, const Point& p)
{
	return Point(p.m_iX+Value,p.m_iY+Value);
}
Point& Point::operator=(const Point& pt)
{
	m_iX = pt.m_iX;
	m_iY = pt.m_iY;
	return *this;
}
Point& Point::operator+=(const Point& pt)
{
	m_iX += pt.m_iX;
	m_iY += pt.m_iY;
	return *this;
}
bool Point::operator ==(const Point& pt)
{
	return(m_iX == pt.m_iX && m_iY == pt.m_iY);
}
void	Point::Set(T_Region* a)
{
	m_pRegion = a;
	
}
void	Point::Compute(const T_Region* a)
{
	//T_Region* b = new T_Region();
	//m_iX = a->m_iValue;
}
int		Point::GetCount()
{
	return Point::g_iCount;
}
void	Point::Delete()
{
}
bool	const Point::SetPosition(int iX, int iY)
{
	if (iX < 0 || iX > 100)
	{
		std::cout << "\nX 0~100사이로 범위를 설정하세요." << std::endl;
		return false;
	}
	if (iY < 0 || iY > 100)
	{
		std::cout << "\nY 0~100사이로 범위를 설정하세요." << std::endl;
		return false;
	}
	m_iX = iX;
	this->m_iY = iY;
	return true;
}

void	Point::Show()
{
	printf("\n%d,%d", this->m_iX, this->m_iY);
}
Point::Point()
{
	g_iCount++;
	m_iX = 5, m_iY = 50;
	cout << "생성자 호출" << endl;
}
Point::Point(int x, int y)
{
	g_iCount++;
	m_iX = x, m_iY = y;
	cout << "생성자 호출" << endl;
}
Point::Point(int x, int y, char* pData)
{
	g_iCount++;
	m_iX = x, m_iY = y;
	std::cout << "생성자 호출" << std::endl;

}
Point::Point(Point& data)
{
	g_iCount++;
	m_iX = data.GetX();
	m_iY = data.GetY();
	//this->m_pszData = data.GetString();
	std::cout << "복사생성자 호출" << std::endl;
}
Point::~Point()
{
	Delete();
	std::cout << "해제자 호출" << std::endl;
}

