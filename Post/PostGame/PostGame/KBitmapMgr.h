#pragma once
#include "KBitmap.h"
#include "KHashTable.h"

class KBitmapMgr : public KSingleton<KBitmapMgr>
{
public:
	friend class KSingleton<KBitmapMgr>;
public:
	KLinkedList<KBitmap>		m_List;
	KHashTable<KBitmap>			m_Hash;
private:
	KLinkedList<KBitmap>		m_InitList;
public:
	KBitmap*					Load(TCHAR* pszLoadFile);
	KBitmap*					Find(int iIndex);
	void						Release();
	void						Delete(int iIndex) {};
	void						Delete(KBitmap* iData) {};
	KNode<KBitmap>*				Swap(
		KNode<KBitmap>* a,
		KNode<KBitmap>* b);
	KBitmap* Find(TCHAR* pszName);
public:
	KBitmapMgr();
	virtual ~KBitmapMgr();
};
#define l_BitmapMgr KBitmapMgr::GetInstance()
