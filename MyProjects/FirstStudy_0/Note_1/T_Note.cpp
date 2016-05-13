#include "T_Note.h"

int Point::g_iCount = 0;

void Point::Delete()
{
	SAFE_DEL_ARRAY(m_pszData);
}
int Point::GetCount()
{
	return Point::g_iCount;
}
void Point::SetString(char* pData)
{
	int iSize = strlen(pData);
	if (m_pszData == NULL)
	{
		SAFE_NEW_ARRAY(this->m_pszData, char, iSize);
	}
	strcpy(m_pszData, pData);
}
bool Point::SetPosition(int iX,int iY)
{
	if (iX < 0 || iX > 100)
	{
		std::cout << "X���� 0~100���̷� �����Ͻÿ�" << std::endl;
		return false;
	}
	if (iY < 0 || iY > 100)
	{
		std::cout << "Y���� 0~100���̷� �����Ͻÿ�" << std::endl;
		return false;
	}
	m_iX = iX;
	m_iY = iY;
	return true;
}
void Point::Show()
{
	cout << this->m_iX << ", " << this->m_iY << endl;
}

Point::Point()
{
	SAFE_ZERO(m_pszData);
	g_iCount++;
	m_iX = 5, m_iY = 50;
	cout << "������ ȣ��1" << endl;
}

Point::Point(int iX, int iY)
{
	SAFE_ZERO(m_pszData);
	g_iCount++;
	m_iX = iX, m_iY = iY;
	cout << "������ ȣ��2" << endl;
}

Point::Point(int iX, int iY,char* pData)
{
	SAFE_ZERO(m_pszData);
	g_iCount++;
	m_iX = iX, m_iY = iY;
	SetString(pData);
	cout << "������ ȣ��3" << endl;
}
Point::Point(Point& data)
{
	SAFE_ZERO(m_pszData);
	g_iCount++;
	m_iX = data.GetX();
	m_iY = data.GetY();
	SetString(data.GetString());
	std::cout << "��������� ȣ��" << endl;
}


Point::~Point()
{
	Delete();
	std::cout << "������ ȣ��" << std::endl;
}
