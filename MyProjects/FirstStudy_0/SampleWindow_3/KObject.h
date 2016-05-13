#pragma once
#include "KBitmap.h"
class KObject
{
public:
	KBitmap*				m_pBitmap;
	int						m_iBitmapID;
	bool					m_bUsed;

	float					m_fSpeed;
	float					m_fPosX;
	float					m_fPosY;
	float					m_fDirection[2];
	KRect					m_rt;
	KRect					m_rtCollide;
public:
	bool					Load(HDC hScreenDC, HDC hOffScreenDC, TCHAR* pFileName);
	bool					Init();
	bool					Frame();
	bool					Render();
	bool					Release();
public:
	bool					Draw();
	void					SetPos(int iX, int iY, float fSpeed);
	void					SetSpeed(float fSpeed = 1.0f);
	void					SetRect(int x, int y, int w, int h);
	//void					Left();
	//void					Right();
	//void					Up();
	//void					Down();
public:
	KObject();
	virtual ~KObject();
};

