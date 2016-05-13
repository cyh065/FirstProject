#pragma once
#include "KCore.h"
#include "KBitmap.h"
#include "KHero.h"
#include "KEffect.h"

class Sample : public KCore
{
public:
	KBitmap						m_Bitmap;
	typedef		vector<RECT>	SPRITE_ARRAY;
	vector<SPRITE_ARRAY>		m_SpriteList;
	KHero						m_Hero;
	list<KEffect*>				m_EffectList;
public:
	bool						Init();
	bool						Frame();
	bool						Render();
	bool						LoadSprite(TCHAR* pFileName);
	void						SetSprite(int iIndex, float fLifeTime = 1.0f);
public:
	Sample();
	virtual ~Sample();
};

