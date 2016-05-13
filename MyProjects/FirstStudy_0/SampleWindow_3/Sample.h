#pragma once
#include "KCore.h"
#include "KEnemy.h"
#include "KHero.h"
#include "KSound.h"
#define MAX_OBJECT 100

class Sample : public KCore
{
public:
	KSound					m_pSound;
	KEnemy					m_Object[MAX_OBJECT];
	KEnemy					m_BackGround;
	KHero					m_Hero;
	float					m_iX;
	float					m_iY;
public:
	bool					Init();
	bool					Frame();
	bool					Render();
	bool					Release();
public:
	Sample();
	virtual ~Sample();
};

