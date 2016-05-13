#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <tchar.h>
using namespace std;

#define SAFE_ZERO( p){p = 0;}
#define SAFE_NEW( p, type ) { if(!p) {p = new type;}}
#define SAFE_DEL( p, type ) { if(p) {delete p; p = NULL;}}
#define SAFE_NEW_ARRAY( p, type, size) { if(!p) {p = new type[size];}}
#define SAFE_DEL_ARRAY( p, type ) { if(p) {delete[] p; p = NULL;}}

//��ü
class Point
{
	//////////////// ��� ���� ////////////////
//�������� ������
public://Ŭ���� �ܺη� ������Ѵ�.
	int		m_iX;
	int		m_iY;
	char*	m_pszData;
	static int	g_iCount;
	//////////////// ��� �Լ� ////////////////
public://Ŭ���� �ܺη� �����Ѵ�.
	static int	GetCount();
	// iX, iY �� 0~100������ �����Ѵ�.
	// ������ ���� ���� ��� 0���� ���õȴ�.
	// ���� ����
	bool	SetPosition(int iX, int iY);
	// �б� ����
	int		GetX() { return m_iX; }
	int		GetY() { return m_iY; }
	void	SetString(char* pData);
	char*	GetString() { return m_pszData; }
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
