#pragma once
#include "KShape.h"
#include <string>


class KSprite : public KShape
{
public:
	wstring			m_szName;
	int				m_iSpriteID;
	int				m_iNumFrame;
	float			m_fSecPerRender;
	int				m_iCurFrame;
	float			m_fTimer;
	float			m_fLifeTime;
	vector<RECT>	m_rtList;
public:
	void			SetRectArray(vector<RECT> rtList, float fLifeTime = 1.0f);
	void			SetSpeed(float fSpeed);
	bool			Frame();
	bool			Render();
	bool			Release();
public:
	KSprite();
	virtual ~KSprite();
};

