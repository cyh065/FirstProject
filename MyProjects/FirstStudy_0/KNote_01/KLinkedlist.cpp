#include "KLinkedlist.h"

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
		pTemp->m_pPrev = m_pHead;
		m_pHead->m_pNext = pTemp;
		
	}
	m_iCount++;
	return true;
}
template <class K>
void	KLinkedlist<K>::DeleteLink(K* pLink)
{
	KNode<K>* pNode = new KNode<K>;
	pNode->m_pData = pLink;
	if (m_pHead->m_pData == pNode->m_pData)
	{
		m_pHead = m_pHead->m_pNext;
		delete pNode;
		pNode = NULL;
		m_iCount--;
		return;
	}
	for (KNode<K>* pTemp = m_pHead;pTemp != NULL;pTemp = pTemp->m_pNext)
	{
		if (pTemp->m_pData == pNode->m_pData)
		{
			KNode<K>* pDelNode = 0;
			pDelNode = pTemp;
			if (pTemp->m_pNext == NULL) {
				pTemp->m_pPrev->m_pNext = NULL;
				m_pTail = pTemp->m_pPrev;
			}
			else
			{
				pTemp->m_pNext->m_pPrev = pTemp->m_pPrev;
				pTemp->m_pPrev->m_pNext = pTemp->m_pNext;
				pTemp = pTemp->m_pNext;
				
			}
			delete pDelNode;
			pDelNode = NULL;
			m_iCount--;
			break;
		}
	}
}
template <class K>
void KLinkedlist<K>::Delete(KNode<K>* pNode)
{

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

