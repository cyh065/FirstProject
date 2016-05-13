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

//객체
class Point
{
	//////////////// 멤버 변수 ////////////////
//접근제어 연산자
public://클래스 외부로 비공개한다.
	int		m_iX;
	int		m_iY;
	char*	m_pszData;
	static int	g_iCount;
	//////////////// 멤버 함수 ////////////////
public://클래스 외부로 공개한다.
	static int	GetCount();
	// iX, iY 은 0~100범위로 제한한다.
	// 범위를 벗어 났을 경우 0으로 세팅된다.
	// 쓰기 전용
	bool	SetPosition(int iX, int iY);
	// 읽기 전용
	int		GetX() { return m_iX; }
	int		GetY() { return m_iY; }
	void	SetString(char* pData);
	char*	GetString() { return m_pszData; }
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
