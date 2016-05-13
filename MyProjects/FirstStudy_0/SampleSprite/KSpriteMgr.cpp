#include "KSpriteMgr.h"

INT		KSpriteMgr::Load(TCHAR* pszName, TCHAR* pszColorFile, TCHAR* pszMaskFile)
{
	KSprite* pSprite = new KSprite;
	if (!pSprite->Load(pszColorFile, pszMaskFile))
	{
		delete pSprite;
		return 0;
	}
	pSprite->m_szName = pszName;
	m_mapList.insert( make_pair(++m_iKey, pSprite));
	pSprite->m_iSpriteID = m_iKey;
	return m_iKey;
}

KSprite* KSpriteMgr::Find(INT iKey)
{
	std::map<INT, KSprite*>::iterator itor = m_mapList.find(iKey);
	if (itor == m_mapList.end()) return NULL;
	KSprite* pSprite = (*itor).second;
	return pSprite;
}

KSpriteMgr::KSpriteMgr()
{
	m_iKey = 0;
}


KSpriteMgr::~KSpriteMgr()
{
}
