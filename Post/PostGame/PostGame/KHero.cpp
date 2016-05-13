#include "KHero.h"
#include "KSys.h"

bool			KHero::Init()
{
	return true;
}
bool			KHero::Frame()
{
	m_rtCollide.x = m_fPosX;// - (m_rt.w / 2);
	m_rtCollide.y = m_fPosY;// -(m_rt.h / 2);
	m_rtCollide.w = m_rtCollide.x + m_rt.w;
	m_rtCollide.h = m_rtCollide.y + m_rt.h;
	return true;
}
// 대상 포지션 X,Y
// 대상 크기 W,H
// 원본 시작위치  X,Y
// 원본 크기 W,H

bool			KHero::Render()
{
	BitBlt(m_pBitmap->m_hOffScreenDC,
		m_fPosX, m_fPosY,
		m_rt.w, m_rt.h,
		m_pBitmap->m_hMemDC,
		m_rt.x, m_rt.y,
		SRCCOPY);
	return true;
}
bool			KHero::Release()
{
	m_pBitmap->Release();
	return true;
}
void			KHero::Left()
{
	m_fPosX = 380;
	m_fPosY = 300;
}
void			KHero::Right()
{
	m_fPosX = 680;
	m_fPosY = 300;
}
void			KHero::Up()
{
	m_fPosX = 530;
	m_fPosY = 300;
}
void			KHero::Down()
{
	m_fPosX = 550;
	m_fPosY = 450;
	m_bGet = false;
}

KHero::KHero()
{
	m_fDirection[0] = 1.0f;
	m_fDirection[1] = 1.0f;
	m_fSpeed = 0.0f;
	m_fPosX = 0.0f;
	m_fPosY = 0.0f;
}


KHero::~KHero()
{
}
