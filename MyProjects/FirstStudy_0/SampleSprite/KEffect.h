#pragma once
#include "KSprite.h"
class KEffect
{
public:
	KSprite*		m_pSprite;
	bool			Frame()
	{
		m_pSprite->Frame();
	}
	bool			Render()
	{
		m_pSprite->Render();
	}
public:
	KEffect();
	virtual ~KEffect();
};

