#pragma once
#include "KNode.h"

template <class K>
class KLinkedList
{
public:
	int				m_iCount;
	KNode<K>*		m_pTail;
	KNode<K>*		m_pHead;
	KNode<K>*		GetHead();
	K*				GetData(int iIndex)
	{
		KNode<K>* pNode = m_pHead;
		while (pNode != NULL)
		{
			if (pNode->m_pData->m_iIndex = iIndex)
			{
				return pNode->m_pData;
			}
			pNode = pNode->m_pNext;
		}
		return NULL;
	}
	K*				GetData(TCHAR* pszData)
	{
		KNode<K>* pNode = m_pHead;
		while (pNode != NULL)
		{
			if (_tcsicmp(pNode->m_pData->m_szName, pszData) == 0)
			{
				return pNode->m_pData;
			}
			pNode = pNode->m_pNext;
		}
		return NULL;
	}

	bool			AddLink(K* pLink);
	void			Release();
	void			Delete(int iIndex) {};
	void			Delete(K* iData) {};
	void			Delete(KNode<K>* pNode) {};
public:
	KLinkedList();
	~KLinkedList();
};
#pragma region func
template <class K>
void		KLinkedList<K>::Release()
{
	KNode<K>* pDelNode = 0;
	KNode<K>* pNode = m_pHead;
	while (pNode != NULL)
	{
		pDelNode = pNode;
		pNode = pNode->m_pNext;
		delete pDelNode;
	}
	m_pHead = 0;
	m_pTail = 0;
}
template <class K>
KNode<K>*	KLinkedList<K>::GetHead()
{
	return m_pHead;
}
template<class K>
bool		KLinkedList<K>::AddLink(K* pData)
{
	KNode<K>* pNode = new KNode<K>();
	pNode->m_pData = pData;
	if (m_pHead == NULL)
	{
		m_pHead = pNode;
		m_pTail = pNode;
	}
	else
	{
		KNode<K>* pTemp = m_pHead;
		m_pHead = pNode;
		m_pHead->m_pNext = pTemp;
		pTemp->m_pPrev = pNode;
	}
	m_iCount++;
	return true;
}
template <class K>
KLinkedList<K>::KLinkedList()
{
	m_iCount = 0;
	m_pHead = NULL;
	m_pTail = NULL;
}
template <class K>
KLinkedList<K>::~KLinkedList()
{

}
#pragma endregion