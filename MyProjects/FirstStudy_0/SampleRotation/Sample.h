#pragma once
#include "KCore.h"
#include "KBitmap.h"
class Sample : public KCore
{
public:
	KBitmap				m_BackGround;
	KBitmap				m_ColorBitmap;
	KBitmap				m_MaskBitmap;
	float				m_fAngle;
	HBRUSH				m_back;
	RECT				m_rt;
	HDC					m_RotationBitmapDC;
	HDC					m_hMaskMemDC;
	HDC					m_hColorMemDC;
public:
	bool				Init();
	bool				Frame();
	bool				Render();
	bool				Release();
	void				DrawObject();
	void				DrawBackGround();
	void				DrawRotate(float fAngle);
	HBITMAP				GetRotationBitmap(HDC hdc, float fAngle, int iWidth, int iHeight);
public:
	Sample();
	virtual ~Sample();
};

