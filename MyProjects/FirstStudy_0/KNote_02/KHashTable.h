#pragma once
#include "KLinkedlist.h"
template <class K>
class KHashTable
{
public:
	KLinkedlist<K>*		m_pArray;
	int					m_iLength;
	int					Hash(TCHAR* pName);
	void				Insert(K* newItem);
public:
	KHashTable(int iLength);
	~KHashTable();
};
template <class K>
int		KHashTable<K>::Hash(TCHAR* pName)
{
	int iValue = 0;
	int iLen = _tcslen(pName);
	for (int i = 0;i < iLen;i++)
	{
		iValue += pName[i];
	}
	int iKey = (iValue * iLen) % m_iLength;
	return iKey;
}
template <class K>
void	KHashTable<K>::Insert(K* newItem)
{
	int iIndex = Hash(newItem->m_szName);
	m_pArray[iIndex]->AddLink(newItem);
}
template <class K>
KHashTable<K>::KHashTable(int iLength)
{
	m_pArray = new KLinkedlist<K>[iLength];
	m_iLength = iLength;
}
template <class K>
KHashTable<K>::~KHashTable()
{
	delete[] m_pArray;
}
