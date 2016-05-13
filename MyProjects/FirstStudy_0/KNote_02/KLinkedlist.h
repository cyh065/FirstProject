#pragma once
#include "KNode.h"

template < class K >
class KLinkedlist
{
public:
	int				m_iCount;
	KNode<K>*		m_pHead;
	KNode<K>*		m_pTail;
	KNode<K>*		GetHead();
	K*				GetData(int iIndex)
	{
		return NULL;
	};
	bool			AddLink(K* pLink);
	void			Release();
	void			Delete(int iIndex) {};
	void			Delete(K* iData) {};
	void			Delete(KNode<K>* pNode) {};
public:
	KLinkedlist();
	~KLinkedlist();
};
template <class K>
void	KLinkedlist<K>::Release()
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
KNode<K>*	KLinkedlist<K>::GetHead()
{
	return m_pHead;
}
template <class K>
bool	KLinkedlist<K>::AddLink(K* pData)
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
	}
	m_iCount++;
	return true;
}
template <class K>
K*				GetData(int iIndex)
{
	KNode<K>* pNode = m_pHead;
}
template <class K>
KLinkedlist<K>::KLinkedlist()
{
	m_iCount = 0;
	m_pHead = NULL;
	m_pTail = NULL;
}
template <class K>
KLinkedlist<K>::~KLinkedlist()
{
}
