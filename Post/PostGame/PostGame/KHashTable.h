#pragma once
#include "KLinkedList.h"
template <class K>
class KHashTable
{
public:
	KLinkedList<K>*			m_pArray;
	int						m_iLength;
	int						Hash(TCHAR* pName);
	void					Insert(K* newItem);
	K*						Find(TCHAR* pszName);
public:
	KHashTable(int iLength = 20);
	~KHashTable();
};
template <class K>
int KHashTable<K>::Hash(TCHAR* pName)
{
	int iKey = 5381;
	int c;
	size_t hash = 0x811c9dc5;
	while (c = *pName++)
	{
		hash ^= c;
		hash *= 0x01000193;
	}
	return hash % m_iLength;
}
template <class K>
void KHashTable<K>::Insert(K* newItem)
{
	int iIndex = Hash(newItem->m_szName);
	m_pArray[iIndex].AddLink(newItem);
}
template <class K>
K* KHashTable<K>::Find(TCHAR* pszName)
{
	int iIndex = Hash(pszName);
	return m_pArray[iIndex].GetData(pszName);
}
template <class K>
KHashTable<K>::KHashTable(int iLength)
{
	m_pArray = new KLinkedList<K>[iLength];
	m_iLength = iLength;
}
template <class K>
KHashTable<K>::~KHashTable()
{
	delete[] m_pArray;
}