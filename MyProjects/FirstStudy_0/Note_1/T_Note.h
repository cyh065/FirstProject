#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <tchar.h>

using namespace std;

#define SAFE_ZERO( p){p = 0;}
#define SAFE_NEW( p, type){ if(!p){p = new type;}}
#define SAFE_DEL( p){ if(p){delete p; p = NULL;}}
#define SAFE_NEW_ARRAY( p, type, size){ if(!p){p = new type[size+1];}}
#define SAFE_DEL_ARRAY( p ){ if(p){delete[] p; p = NULL;}}

class Point
{
public:
	int		m_iX;
	int		m_iY;
	char*	m_pszData;
	static int g_iCount;
public:
	static int GetCount();
	bool SetPosition(int iX, int iY);
	int GetX() { return m_iX; }
	int GetY() { return m_iY; }
	void SetString(char* pData);
	char* GetString() { return m_pszData; }
	void Show();
	void Delete();
public:
	Point();
	Point(int x, int y);
	Point(int x, int y, char* pData);
	Point(Point& data);
	~Point();
};

