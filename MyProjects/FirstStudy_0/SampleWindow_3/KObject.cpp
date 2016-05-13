#include "KObject.h"
#include "KSys.h"
#include "KBitmapMgr.h"
bool					KObject::Draw()
{
	StretchBlt(m_pBitmap->m_hOffScreenDC,
		m_fPosX, m_fPosY, m_rt.w, m_rt.h,
		m_pBitmap->m_hMemDC, m_rt.x, m_rt.y,
		m_pBitmap->m_hBitInfo.bmWidth, // 64
		m_pBitmap->m_hBitInfo.bmHeight, // 64
		SRCCOPY);
	return true;
}
void					KObject::SetRect(int x, int y, int w, int h)
{
	m_rt.x = x;
	m_rt.y = y;
	m_rt.w = w;
	m_rt.h = h;
}
bool					KObject::Load(HDC hScreenDC, HDC hOffScreenDC, TCHAR* pFileName)
{
	m_pBitmap = l_BitmapMgr.Load(pFileName);
	if (m_pBitmap == NULL)
	{
		return false;
	}
	return true;
}

//void					KObject::Left()
//{
//	m_fX -= g_fSecondPerFrame * m_fSpeed;
//}
//void					KObject::Right()
//{
//	m_fX += g_fSecondPerFrame * m_fSpeed;
//}
//void					KObject::Up()
//{
//	m_fY -= g_fSecondPerFrame * m_fSpeed;
//}
//void					KObject::Down()
//{
//	m_fY += g_fSecondPerFrame * m_fSpeed;
//}

void					KObject::SetPos(int iX, int iY, float fSpeed)
{
	m_rtCollide.x = iX - (m_rt.w / 2);
	m_rtCollide.y = iY - (m_rt.h / 2);
	m_rtCollide.w = m_rtCollide.x + m_rt.w;
	m_rtCollide.h = m_rtCollide.y + m_rt.h;

	m_fPosX = iX;
	m_fPosY = iY;
	m_fSpeed = fSpeed;
}
void					KObject::SetSpeed(float fSpeed)
{
	m_fSpeed += fSpeed  * g_fSecondPerFrame;
	if (m_fSpeed < 10.0f) m_fSpeed = 10.0f;
}

bool					KObject::Init()
{
	return true;
}
bool					KObject::Frame()
{
	/*if (m_fX < 10 || m_fX > 800 - 145 - 10)
	{
		m_fDirection[0] *= -1.0f;
	}
	if (m_fY < 10 || m_fY > 600 - 145 - 10)
	{
		m_fDirection[1] *= -1.0f;
	}
	m_fX += m_fDirection[0] * m_fSpeed * g_fSecondPerFrame;
	m_fY += m_fDirection[1] * m_fSpeed * g_fSecondPerFrame;*/
	return true;
}
bool					KObject::Render()
{
	if (m_bUsed == true)
	{
		BitBlt(m_pBitmap->m_hOffScreenDC,
			m_rtCollide.x, m_rtCollide.y,
			m_rt.w, m_rt.h,
			m_pBitmap->m_hMemDC,
			m_rt.x, m_rt.y,
			SRCCOPY);

	}

	//StretchBlt(	m_Bitmap.m_hOffScreenDC,
	//			m_fX, m_fY,
	//			800, 600, 
	//			m_Bitmap.m_hMemDC, 
	//			m_Bitmap.m_hBitInfo.bmWidth/2,
	//			m_Bitmap.m_hBitInfo.bmHeight/2,
	//			m_Bitmap.m_hBitInfo.bmWidth - m_Bitmap.m_hBitInfo.bmWidth / 2,
	//			m_Bitmap.m_hBitInfo.bmHeight - m_Bitmap.m_hBitInfo.bmHeight / 2,
	//			SRCCOPY);
	return true;
}
bool					KObject::Release()
{
	m_pBitmap->Release();
	return true;
}

KObject::KObject()
{
	m_fDirection[0] = 1.0f;
	m_fDirection[1] = 1.0f;
	m_fSpeed = 0.0f;
	m_fPosX = 0.0f;
	m_fPosY = 0.0f;
	m_pBitmap = NULL;
	m_bUsed = true;
}


KObject::~KObject()
{
}
