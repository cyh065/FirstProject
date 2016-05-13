#pragma once
#include <iostream>
#include <tchar.h>
template < class K >
class KNode
{
public:
	K*		m_pData;
	KNode*	m_pNext;
	KNode*	m_pPrev;
public:
	KNode();
	~KNode();
};
template <class K>
KNode<K>::KNode()
{
	m_pData = NULL;
	m_pNext = NULL;
	m_pPrev = NULL;
}
template < class K>
KNode<K>::~KNode()
{
	delete m_pData
}