#include "KManager.h"
template<typename K>
void SwapPoint(K* a,K* b)
{
	a->m_pNext = b;
	b->m_pPrev = a;
}


KNode<KStudent>* KManager::Swap(KNode<KStudent>* a, KNode<KStudent>* b)
{
	KNode<KStudent> * aPrev = a->m_pPrev;
	KNode<KStudent> * aNext = a->m_pNext;
	KNode<KStudent> * bPrev = b->m_pPrev;
	KNode<KStudent> * bNext = b->m_pNext;

	
	if (aPrev != NULL) // 1번 head	<-> b;
	{
		SwapPoint(aPrev, a);
		//aPrev->m_pNext = b;
		//b->m_pPrev = aPrev;
	}
	else
	{
		m_List.m_pHead = b;
		b->m_pPrev = NULL;
	}
	// 1번 tail == b;
	
	if (aNext != b) //b<->a
	{
		SwapPoint(b, aNext);
		//b->m_pNext = aNext;
		//aNext->m_pPrev = b;
		//a -> c -> b
		if (aNext->m_pNext == b)
		{
			SwapPoint(aNext, a);
			//aNext->m_pNext = a;
			//a->m_pPrev = aNext;
		}
		else
		{
			SwapPoint(bPrev, a);
			//bPrev->m_pNext = a;
			//a->m_pPrev = bPrev;
		}
	}
	else //b <-> a
	{
		SwapPoint(b, a);
		//b->m_pNext = a;
		//a->m_pPrev = b;
		a->m_pNext = bNext;
		if (bNext != NULL)
		{
			bNext->m_pPrev = a;
		}
	}
	//a->c ->b ->d
	if (bNext != NULL)
	{
		SwapPoint(a, bNext);
		//a->m_pNext = bNext;
		//bNext->m_pPrev = a;
	}
	else
	{
		a->m_pNext = NULL;
	}
	if (aNext == b)return a;
	return aNext;
}
// iCnt 명에 대한 학생을 랜덤하게 구성.
bool	KManager::InputData(int iCnt)
{
	for (int iStd = 0; iStd < iCnt; iStd++)
	{
		KStudent*	pStudent = new KStudent;
		for (int iName = 0;iName < 5;iName++)
		{
			char cWord = 65 + rand() % 26;
			pStudent->m_szName[iName] = cWord;
		}
		pStudent->m_szName[4] = 0;
		pStudent->m_iIndex = iStd;
		pStudent->m_Ssubject.m_iKor = rand() % 101;
		pStudent->m_Ssubject.m_iEng = rand() % 101;
		pStudent->m_Ssubject.m_iMat = rand() % 101;
		pStudent->m_iTotal = pStudent->m_Ssubject.m_iKor
			+ pStudent->m_Ssubject.m_iEng
			+ pStudent->m_Ssubject.m_iMat;
		m_Hash.Insert(pStudent);
		m_List.AddLink(pStudent);
	}
	return true;
}
KStudent*	KManager::Find(TCHAR* pszName)
{
	int iIndex = this->m_Hash.Hash(pszName);
	m_Hash.m_pArray[iIndex].GetData(pszName);
}
void	KManager::Sort(bool bUp = true)
{
	KNode<KStudent>* pNodeSrc = m_List.GetHead();
	while (pNodeSrc && pNodeSrc->m_pNext)
	{
		KNode<KStudent>* pNodeSwap = pNodeSrc;
		KStudent* pSrcStudent = pNodeSwap->m_pData;
		for (KNode<KStudent>* pNodeDesk = pNodeSrc->m_pNext;
		pNodeDesk != NULL;
			pNodeDesk = pNodeDesk->m_pNext)
		{
			KStudent* pDeskStudent = pNodeDesk->m_pData;
			if (pNodeSwap->m_pData->m_iTotal > pDeskStudent->m_iTotal)
			{
				pNodeSwap = pNodeDesk;
			}
		}
		if (pNodeSrc != pNodeSwap) 
		{
			Swap(pNodeSrc,pNodeSwap);
		}
		else
		{
			pNodeSrc = pNodeSrc->m_pNext;
		}
	}
}
void	KManager::Release()
{
	m_List.Release();
}
void	KManager::ShowData()
{
	for (KNode<KStudent>* pLink = m_List.m_pHead;pLink != NULL;pLink = pLink->m_pNext)
	{
		KStudent* pData = pLink->m_pData;
		wcout << pData->m_iIndex << " "
			<< pData->m_szName << " "
			<< pData->m_Ssubject.m_iKor << " "
			<< pData->m_Ssubject.m_iEng << " "
			<< pData->m_Ssubject.m_iMat << " "
			<< pData->m_iTotal << " "
			<< endl;
	}
}
void	KManager::ShowData(KStudent* pStd)
{

}

KManager::KManager()
{
}


KManager::~KManager()
{
}
