#pragma once
#include "KObject.h"

class KHero : public KObject
{
public:
	bool			m_bGet = false;
	int				m_iget;
public:
	bool			Init();
	bool			Frame();
	bool			Render();
	bool			Release();
public:
	void			Left();
	void			Right();
	void			Up();
	void			Down();
public:
	KHero();
	virtual ~KHero();
};

