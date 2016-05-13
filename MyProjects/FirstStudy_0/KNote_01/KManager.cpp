#include "KManager.h"
// iCnt 명에 대한 학생을 랜덤하게 구성.
KHashTable g_table;
void KManager::Clear()
{

	system("cls");
	cout << "==================================================\n"
		<< "================ 성적 관리 프로그램===============\n"
		<< "==================================================\n" << endl;
}
void	KManager::ReadFile(int iCnt)
{
	FILE* fpRead = fopen("Student.txt", "r");
	if (fpRead)
	{
		for (int iNum = 0;iNum < iCnt;iNum++)
		{
			char szBuffer[256] = { 0, };
			KStudent* pNode = new KStudent;
			fgets(szBuffer, 256, fpRead);
			sscanf(szBuffer, "%d%s%d%d%d%d\n",
				&pNode->m_iIndex,
				pNode->m_szName,
				&pNode->m_Ssubject.m_iKor,
				&pNode->m_Ssubject.m_iEng,
				&pNode->m_Ssubject.m_iMat,
				&pNode->m_iTotal
				);
			this->m_List.AddLink(pNode);
			
			Item * Name = new Item{ pNode->m_szName,NULL };
			g_table.insertItem(Name);
		}
		fclose(fpRead);
	}
}
bool	KManager::InputData(int iCnt)
{
	FILE* fp = fopen("Student.txt", "w");
	if (fp)
	{
		for (int iStd = 0; iStd < iCnt; iStd++)
		{
			KStudent*	pStudent = new KStudent;
			for (int iName = 0;iName < 5;iName++)
			{
				char cWord = 65 + rand() % 26;
				pStudent->m_szName[iName] = (char)cWord;
			}
			pStudent->m_szName[4] = 0;
			pStudent->m_iIndex = iStd;
			pStudent->m_Ssubject.m_iKor = rand() % 101;
			pStudent->m_Ssubject.m_iEng = rand() % 101;
			pStudent->m_Ssubject.m_iMat = rand() % 101;
			pStudent->m_iTotal = pStudent->m_Ssubject.m_iKor +
								 pStudent->m_Ssubject.m_iEng +
								 pStudent->m_Ssubject.m_iMat;
			fprintf(fp, "%d %s %d %d %d %d \n",pStudent->m_iIndex
				, pStudent->m_szName
				, pStudent->m_Ssubject.m_iKor
				, pStudent->m_Ssubject.m_iEng
				, pStudent->m_Ssubject.m_iMat
				, pStudent->m_iTotal);
		}
		fclose(fp);
	}
	return true;
}
KStudent*	KManager::Find(int iIndex)
{
	for (KNode<KStudent>* pLink = m_List.m_pHead;pLink != NULL;pLink = pLink->m_pNext)
	{
		if (pLink->m_pData->m_iIndex == iIndex)
		{
			return pLink->m_pData;
		}
	}
	return NULL;
}
void	KManager::Swap(KNode<KStudent> *a, KNode<KStudent> *b, bool bUp)
{
	if(bUp == true)//내림차순
	{
		if (a->m_pData->m_iIndex > b->m_pData->m_iIndex) {
			KStudent iTemp = *a->m_pData;
			*a->m_pData = *b->m_pData;
			*b->m_pData = iTemp;
			return;
		}
	}
	else//올림차순
	{
		if (a->m_pData->m_iIndex < b->m_pData->m_iIndex) {
			KStudent iTemp = *a->m_pData;
			*a->m_pData = *b->m_pData;
			*b->m_pData = iTemp;
			return;
		}
	}
}
void	KManager::Sort(bool bUp)
{
	for (KNode<KStudent>* pLink = m_List.m_pHead;pLink != NULL;pLink = pLink->m_pNext)
	{
		for (KNode<KStudent>* pLink2 = pLink->m_pNext;pLink2 != NULL;pLink2 = pLink2->m_pNext)
		{
				Swap(pLink, pLink2,bUp);	
		}
	}
}
void	KManager::Release()
{
	m_List.Release();
}
void	KManager::ShowData()
{
	Clear();
	for (KNode<KStudent>* pLink = m_List.m_pHead;pLink != NULL;pLink = pLink->m_pNext)
	{
		KStudent* pData = pLink->m_pData;
		cout << "학번\t이름\t국어\t영어\t수학\t총점" << endl;
		wcout << " " 
			<< pData->m_iIndex << "\t"
			<< pData->m_szName << "\t "
			<< pData->m_Ssubject.m_iKor << "\t "
			<< pData->m_Ssubject.m_iEng << "\t "
			<< pData->m_Ssubject.m_iMat << "\t "
			<< pData->m_iTotal << "\t "
			<< endl;
	}
	//g_table.printTable();//해쉬 테이블 출력
}
void	KManager::ShowData(KStudent* pStd)
{
	cout << "학번\t이름\t국어\t영어\t수학\t총점" << endl;
	wcout <<" " 
		<< pStd->m_iIndex << "\t"
		<< pStd->m_szName << "\t "
		<< pStd->m_Ssubject.m_iKor << "\t "
		<< pStd->m_Ssubject.m_iEng << "\t "
		<< pStd->m_Ssubject.m_iMat << "\t "
		<< pStd->m_iTotal << "\t "
		<< endl;
}
void	KManager::PlusData()
{
	
	KStudent* pStudent = new KStudent;
	cout << "학번 :";
	cin >> pStudent->m_iIndex;
	cout << "이름 :";
	scanf("%s", pStudent->m_szName);
	pStudent->m_szName[4] = 0;
	cout << "국어 :";
	cin >> pStudent->m_Ssubject.m_iKor;
	cout << "영어 :";
	cin >> pStudent->m_Ssubject.m_iEng;
	cout << "수학 :";
	cin >> pStudent->m_Ssubject.m_iMat;
	this->m_List.AddLink(pStudent);
}
void	KManager::ReformData(KStudent* iData)
{
	cout << "이름 :";
	g_table.removeItem(iData->m_szName);
	scanf("%s", iData->m_szName);
	iData->m_szName[4] = 0;
	Item * Name = new Item{ iData->m_szName,NULL };
	g_table.insertItem(Name);
	cout << "국어 :";
	cin >> iData->m_Ssubject.m_iKor;
	cout << "영어 :";
	cin >> iData->m_Ssubject.m_iEng;
	cout << "수학 :";
	cin >> iData->m_Ssubject.m_iMat;
	iData->m_iTotal = iData->m_Ssubject.m_iKor +
		iData->m_Ssubject.m_iEng +
		iData->m_Ssubject.m_iMat;
}
void	KManager::UpData(int iCnt)
{
	while (1)
	{
		int iNum;
		cout << "학번 : ";
		cin >> iNum;
		KStudent* pSearchNode = Find(iNum);
		pSearchNode->m_szName;
		if (pSearchNode != NULL)
		{
			if (iCnt == 2)
			{
				this->m_List.DeleteLink(pSearchNode);
				g_table.removeItem(pSearchNode->m_szName);
				break;
			}
			else
			{
				ReformData(pSearchNode);
				break;
			}
		}
		else
		{
			cout << "검색할 수 없습니다. \n" << endl;
		}
	}
}

KManager::KManager()
{
}


KManager::~KManager()
{
}
