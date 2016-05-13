#include "KBitmapMgr.h"

template <typename K>
void SwapPoint(K* a, K* b)
{
	a->m_pNext = b;
	b->m_pPrev = a;
}
KNode<KBitmap> *	 KBitmapMgr::Swap(KNode<KBitmap>* a, KNode<KBitmap>* b)
{
	KNode<KBitmap>* aPrev = a->m_pPrev;
	KNode<KBitmap>* aNext = a->m_pNext;
	KNode<KBitmap>* bPrev = b->m_pPrev;
	KNode<KBitmap>* bNext = b->m_pNext;

	if (aPrev != NULL) 
	{
		SwapPoint(aPrev, b);
	}
	else
	{
		m_List.m_pHead = b;
		b->m_pPrev = NULL;
	}
	if (aNext != b)
	{
		SwapPoint(b, aNext);
		if (aNext->m_pNext == b)	SwapPoint(aNext, a);
		else						SwapPoint(bPrev, a);
	}
	else
	{
		SwapPoint(b, a);
		a->m_pNext = bNext;
		if (bNext != NULL)	SwapPoint(a, bNext);
	}
	if (bNext != NULL) SwapPoint(a, bNext);
	else				a->m_pNext = NULL;

	if (aNext == b)return a;
	return aNext;
}
KBitmap*		KBitmapMgr::Load(TCHAR* pszLoadFile)
{
	TCHAR Drive[MAX_PATH] = { 0, };
	TCHAR Dir[MAX_PATH] = { 0, };
	TCHAR Name[MAX_PATH] = { 0, };
	TCHAR Ext[MAX_PATH] = { 0, };
	TCHAR SaveName[MAX_PATH] = { 0, };
	_tsplitpath_s(pszLoadFile, Drive, Dir, Name, Ext);
	_stprintf_s(SaveName, _T("%s%s"), Name, Ext);
	KBitmap* pBitmap = NULL;
	pBitmap = m_List.GetData(SaveName);
	if (pBitmap)
	{
		return pBitmap;
	}

	KBitmap* pData = new KBitmap;
	if (pData->Load(pszLoadFile))
	{
		m_Hash.Insert(pData);
		m_List.AddLink(pData);
		return m_Hash.Find(SaveName);
	}
	return NULL;
}

KBitmap*		KBitmapMgr::Find(int iIndex)
{
	for (KNode<KBitmap>* pLink = m_List.m_pHead; pLink != NULL; pLink = pLink->m_pNext)
	{
		KBitmap* pData = pLink->m_pData;
		if (pData->m_iIndex == iIndex)
		{
			return pData;
		}
	}
	return NULL;
}
KBitmap*		KBitmapMgr::Find(TCHAR* pszName)
{
	int iIndex = this->m_Hash.Hash(pszName);
	if (iIndex >= m_Hash.m_iLength) return NULL;
	return m_Hash.m_pArray[iIndex].GetData(pszName);
}
void			KBitmapMgr::Release()
{
	m_List.Release();
}
KBitmapMgr::KBitmapMgr()
{
}


KBitmapMgr::~KBitmapMgr()
{
}
