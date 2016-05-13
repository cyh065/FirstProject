#pragma once
#include "KStd.h"
#include "KBitmap.h"

class KShape
{
public:
	KBitmap*			m_pColor;
	KBitmap*			m_pMask;
	RECT				m_rtDraw;
	POINT				m_Position;
public:
	virtual	bool		Load(TCHAR* pColor, TCHAR* pMask);
	virtual bool		Init();
	virtual bool		Frame();
	virtual bool		Render();
	virtual bool		Release();
public:
	KShape();
	virtual ~KShape();
};

