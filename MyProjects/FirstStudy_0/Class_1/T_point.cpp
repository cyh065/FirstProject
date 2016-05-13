#include "T_point.h"

int Point::g_iCount = 0;

int Point::GetCount()
{
	return Point::g_iCount;
}
void Point::Delete()
{
	SAFE_DEL_ARRAY(m_pszData);
	/*if (m_pszData != NULL) 
	{
		delete m_pszData;
		m_pszData = NULL;
	}*/
}
void Point::SetString(char* pData)
{
	int iSize = strlen(pData);
	if (m_pszData == NULL)
	{
		SAFE_NEW_ARRAY(this->m_pszData, char, iSize);
		this->m_pszData = new char[iSize + 1];
	}
	strcpy(m_pszData, pData);
}
bool Point::SetPosition(int iX, int iY)
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

void Point::Show()
{
	printf("\n%d,%d", this->m_iX, this->m_iY);
}
Point::Point()
{
	SAFE_ZERO(m_pszData);
	g_iCount++;
	m_iX = 5, m_iY = 50;
	cout << "생성자 호출" << endl;
}
Point::Point(int x, int y)
{
	SAFE_ZERO(m_pszData);
	g_iCount++;
	m_iX = x, m_iY = y;
	cout << "생성자 호출" << endl;
}
Point::Point(int x, int y,char* pData)
{
	SAFE_ZERO(m_pszData);
	g_iCount++;
	m_iX = x, m_iY = y;
	SetString(pData);
	std::cout << "생성자 호출" << std::endl;

}
Point::Point(Point& data)
{
	SAFE_ZERO(m_pszData);
	g_iCount++;
	m_iX = data.GetX();
	m_iY = data.GetY();
	//this->m_pszData = data.GetString();
	SetString(data.GetString());
	std::cout << "복사생성자 호출" << std::endl;
}
Point::~Point()
{
	Delete();
	std::cout << "해제자 호출" << std::endl;
}

