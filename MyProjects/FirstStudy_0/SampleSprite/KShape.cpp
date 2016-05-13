#include "KShape.h"
#include "KSpriteMgr.h"
#include "KSys.h"

bool		KShape::Load(TCHAR* pColor, TCHAR* pMask)
{
	m_pColor = I_BitmapMgr.Load(pColor);
	m_pMask = I_BitmapMgr.Load(pMask);
}
bool		KShape::Init()
{
	return true;
}
bool		KShape::Frame()
{
	return true;
}
bool		KShape::Render()
{
	BitBlt(g_hOffScreenDC,
		m_Position.x,
		m_Position.y,
		m_rtDraw.right,
		m_rtDraw.bottom,
		m_pMask->m_hMemDC,
		m_rtDraw.left,
		m_rtDraw.top, SRCAND);

	BitBlt(g_hOffScreenDC,
		m_Position.x,
		m_Position.y,
		m_rtDraw.right,
		m_rtDraw.bottom,
		m_pColor->m_hMemDC,
		m_rtDraw.left,
		m_rtDraw.top, SRCINVERT);

	BitBlt(g_hOffScreenDC,
		m_Position.x,
		m_Position.y,
		m_rtDraw.right,
		m_rtDraw.bottom,
		m_pMask->m_hMemDC,
		m_rtDraw.left,
		m_rtDraw.top, SRCINVERT);

	return true;
}
bool		KShape::Release()
{
	return true;
}
KShape::KShape()
{
}


KShape::~KShape()
{
}
