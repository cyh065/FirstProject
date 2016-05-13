#pragma once
#include "KLinkedlist.cpp"
#include "KHash.h"
#include "KStudent.h"


class KManager
{
public:
	KLinkedlist<KStudent>	m_List;
	KHashTable*				m_Hash;
public:
	void					Clear();
	bool					InputData(int iCnt);
	void					ReadFile(int iCnt);
	KStudent*				Find(int iIndex);
	void					Sort(bool bUp);
	void					Release();
	void					ShowData();
	void					Swap(KNode<KStudent> *a, KNode<KStudent> *b ,bool bUp);
	void					ShowData(KStudent* pStd);
	void					PlusData();
	void					UpData(int iCnt);
	void					ReformData(KStudent* iData);
	void					Delete(int iIndex) {};
	void					Delete(KStudent* iData) {};
public:
	KManager();
	virtual ~KManager();
};

