#pragma once
#include "KSprite.h"
#include <map>
class KSpriteMgr : public KSingleton<KSpriteMgr>
{
public:
	INT							m_iKey;
	friend class KSingleton<KSpriteMgr>;
	std::map<INT, KSprite*>		m_mapList;
	INT							Load(TCHAR* pszName,
									TCHAR* pszColorFile,
									TCHAR* pszMaskFile);
	KSprite*					Find(INT iKey);
public:
	KSpriteMgr();
	virtual ~KSpriteMgr();
};
#define I_Sprite KSpriteMgr::GetInstance()

