#include "LinkedList_0.h"

Node*	g_pHead = 0;

ostream& operator << (ostream &os, const Node& p)
{
	os << p.m_cName << "\t" << p.m_iKor << "\t" << p.m_iEng << "\t"
		<< p.m_iMat << "\t" << p.m_iTot << "\t" << p.m_fAvr << endl;
	return os;
}
istream& operator >>(istream& is, Node& p)
{
	cout << "이름 :";
	is >> p.m_cName;
	cout << "국어 :";
	is >> p.m_iKor;
	cout << "영어 :";
	is >> p.m_iEng;
	cout << "수학 :";
	is >> p.m_iMat;
	return is;
}
void Node::InputData(Node *p)
{
	cin >> *p;
	int iTot = p->m_iKor + p->m_iEng + p->m_iMat;
	float fAvr = iTot / 3.0f;
	p->m_iTot = iTot;
	p->m_fAvr = fAvr;
}
void Node::Clear()
{

	system("cls");
	cout << "==================================================\n" 
		<< "================ 성적 관리 프로그램===============\n"
		<< "==================================================\n" << endl;
}

void Node::AddLink(Node* pNode)
{
	for (Node* pTemp = g_pHead;
		pTemp != NULL;
		pTemp = pTemp->m_pNext)
	{
		if (pTemp->m_pNext == NULL)
		{
			pTemp->m_pNext = pNode;
			return;
		}
	}
	g_pHead = pNode;
}
void Node::WriteLink()
{
	Clear();
	cout << "이름\t국어\t영어\t수학\t총점\t평균\n" << endl;
	for (Node* pTemp = g_pHead;
   	pTemp != NULL;
		pTemp = pTemp->m_pNext)
	{
		cout << *pTemp << endl;
	}
}
Node* Node::SearchLink(const char* strName)
{
	Node* pList = g_pHead;
	for (Node* pTemp = g_pHead;
	pTemp != NULL;
		pTemp = pTemp->m_pNext)
	{


		if (strcmp(pTemp->m_cName, strName) == 0)
		{
			return pTemp;
		}
	}
	return NULL;
}
void Node::DeleteLink(Node* pStudent)
{
	if (g_pHead == pStudent)
	{
		g_pHead = pStudent->m_pNext;
		delete pStudent;
		pStudent = NULL;
		m_iNum--;
		return;
	}
	for (Node* pTemp = g_pHead;
	pTemp != NULL;
		pTemp = pTemp->m_pNext)
	{
		if (pTemp->m_pNext == pStudent)
		{
			pTemp->m_pNext = pStudent->m_pNext;
			delete pStudent;
			pStudent = NULL;
			m_iNum--;
			break;
		}
	}
}
void  Node::FreeLink()
{
	Node* pList = g_pHead;
	while (pList->m_pNext)
	{
		Node *pDelNode = pList->m_pNext;
		pList->m_pNext = pDelNode->m_pNext;
		delete pDelNode;
		pDelNode = NULL;
	}
	delete g_pHead;
}
void Node::WriteFile()
{
	FILE* fp = fopen("Student.txt", "w");
	if (fp)
	{
		std::cout << "인원이 몇명입니까?" << std::endl;
		scanf("%d", &m_iNum);
		while (getchar() != '\n');
		for (int iCnt = 0;iCnt < m_iNum;iCnt++)
		{
			int	iNameA = 65 + rand() % 26;
			int	iNameB = 65 + rand() % 26;
			int	iNameC = 65 + rand() % 26;
			int iKor = rand() % 100;
			int iEng = rand() % 100;
			int iMat = rand() % 100;
			int iTot = iKor + iEng + iMat;
			float fAvr = iTot / 3.0f;
			fprintf(fp, "%c%c%c %d %d %d %d %0.3f\n", iNameA,iNameB,iNameC,
				iKor, iEng, iMat, iTot, fAvr);
		}
		fclose(fp);
	}
}

void Node::ReadFile()
{
	FILE* fpRead = fopen("Student.txt", "r");
	if (fpRead)
	{
		for (int iCnt = 0;iCnt < m_iNum;iCnt++)
		{
			char szBuffer[256] = { 0, };
			Node* pNode = (Node*)malloc(sizeof(Node));
			memset(pNode, 0,sizeof(Node));
//			fscanf(fpRead, "%s",strBuffer);
			fgets(szBuffer, 256, fpRead);
			sscanf(szBuffer, "%s%d%d%d%d%f\n",
				pNode->m_cName,
				&pNode->m_iKor,
				&pNode->m_iEng,
				&pNode->m_iMat,
				&pNode->m_iTot,
				&pNode->m_fAvr);
			AddLink(pNode);
		}
		fclose(fpRead);
	}
}
void Node::PlusData()
{
	Node* pStudent = (Node*)malloc(sizeof(Node));
	SAFE_NEW(pStudent, Node);
	InputData(pStudent);
	pStudent->m_pNext = 0;
	AddLink(pStudent);
}
void Node::UpData(int iCount)
{
	while (1)
	{
		char strSearchName[9] = { 0, };
		//scanf("%s", strSearchName);
		GetString(strSearchName);
		Node* pSearchNode = SearchLink(strSearchName);
		if (pSearchNode != NULL)
		{
			if (iCount == 2)
			{
				DeleteLink(pSearchNode);
				break;
			}
			else
			{
				InputData(pSearchNode);
				break;
			}
		}
		else
		{
			cout << "검색할 수 없습니다. \n" << endl;
		}
	}
}

Node::Node()
{
}

Node::~Node()
{
}
