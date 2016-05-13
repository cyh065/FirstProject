#pragma once
#include "KCore.h"
#include "KHero.h"
#include "KEnemy.h"
#include "KVector.h"
#include "KSound.h"

#define MAX_OBJECT 300
class Sample : public KCore
{
public:
	KSound				m_pSound;

	KHero				m_Hero;
	KHero				m_Hero_Up;
	KEnemy				m_Background;
	KEnemy				m_GameOver;
	KEnemy				m_GameMenu;
	KEnemy				m_Box;
	KEnemy				m_Truck;

	KEnemy				m_Object_One[MAX_OBJECT];
	KEnemy				m_Object_Two[MAX_OBJECT];
	KEnemy				m_Object_Thr[MAX_OBJECT];
	KEnemy				m_Trail[3];
	

	vector<KVector*>	m_Data_One;
	vector<KVector*>	m_Data_Two;
	vector<KVector*>	m_Data_Thr;
	vector<KVector*>	m_Data_Fou;
	float				m_iX;
	float				m_iY;
	float				m_fTimer_One;
	float				m_fTimer_Two;
	float				m_fTimer_Thr;


	KBitmap		m_ColorBitmap;
	KBitmap		m_MaskBitmap;
	HDC        m_hMaskMemDC;
	HDC        m_hColorMemDC;

	int					m_iCnt;
	TCHAR				m_csBuffer[MAX_PATH];
public:
	bool				Init();
	bool				Frame();
	bool				Render();
	bool				Release();
public:
	Sample();
	virtual ~Sample();
};

