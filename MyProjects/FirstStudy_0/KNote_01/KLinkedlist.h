#pragma once
#include "KNode.h"



template < class K >
class KLinkedlist
{

public:
	int				m_iCount;
	KNode<K> *		m_pHead;
	KNode<K> *		m_pTail;
	KNode<K> *		GetHead();	
	K *				GetData(int iIndex)
	{
		return NULL;
	};

	bool			AddLink(K* pLink);
	void			DeleteLink(K* pLink);
	void			Release();
	void			Delete(int iIndex) {};
	void			Delete(K* iData) {};
	void			Delete(KNode<K>* pNode);
public:
	KLinkedlist();
	~KLinkedlist();
};

