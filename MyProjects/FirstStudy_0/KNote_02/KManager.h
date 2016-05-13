#pragma once
#include "KHashTable.h"
#include "KStudent.h"

class KManager
{
public:
	KLinkedlist<KStudent>	m_List;
	KHashTable<KStudent>	m_Hash;
private:
	//HashTable<KStudent>		m_InitList;
public:
	bool	InputData(int iCnt);
	KStudent*	Find(int iIndex);
	void	Sort(bool bUp = true);
	void	Release();
	void	ShowData();
	void	ShowData(KStudent* pStd);
	void	Delete(int iIndex) {};
	void	Delete(KStudent* iData) {};
	KNode<KStudent>* Swap(KNode<KStudent>* a, KNode<KStudent>* b);
	KStudent*	Find(TCHAR* pszName);
public:
	KManager();
	virtual ~KManager();
};

