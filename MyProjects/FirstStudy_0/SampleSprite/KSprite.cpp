#include "KSprite.h"
#include "KSys.h"

void		KSprite::SetRectArray(vector<RECT> rtList, float fLifeTime = 1.0f)
{
	for (int iList = 0; iList < rtList.size();iList++)
	{
		m_rtList.push_back(rtList[iList]);
	}
	m_fLifeTime = fLifeTime;
	m_iNumFrame = m_rtList.size();
	m_iCurFrame = 0;
}

void		KSprite::SetSpeed(float fSpeed)
{
	m_fLifeTime = fSpeed;
	m_fSecPerRender = m_fLifeTime / m_iNumFrame;
}

bool		KSprite::Frame()
{
	m_fTimer += g_fSecondPerFrame;
	if (m_fTimer > m_fSecPerRender)
	{
		if (++m_iCurFrame >= m_iNumFrame)
		{
			m_iCurFrame = 0;
		}
		m_fTimer = 0.0f;
	}
}

bool		KSprite::Render()
{
	return true;
}

bool		KSprite::Release()
{
	return true;
}


KSprite::KSprite()
{
	m_fSecPerRender = 0.0f;
	m_iSpriteID = 0;
	m_iCurFrame = 0;
	m_fTimer = 0.0f;
}


KSprite::~KSprite()
{
}
