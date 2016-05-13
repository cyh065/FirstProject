#include "stdafx.h"
#include <cstdlib>
#include <time.h>

struct Node
{
	int iData;
	int iIndex;
	Node* pChild[2];
};
Node* g_pRootNode = 0;//루트 노드
int g_iIndex = 0;//노드의 인덱스

Node* NewNode(int iValue)//노드 생성 함수
{
	Node* pNode = new Node;//노드에 데이터값 생성
	pNode->iData = iValue;
	pNode->iIndex = g_iIndex++;//노드의 인덱스값을 부여
	pNode->pChild[0] = 0;//2진트리의 왼쪽노드
	pNode->pChild[1] = 0;//2진트리의 오른쪽노드
	return pNode;//노드 반환
}
Node* Find(Node* pNode, int iValue)//노드 검색 함수;
{
	if (pNode == NULL)return NULL;//노드값이 없을경우 NULL을 반환
	if (pNode->iIndex == iValue)//검색한노드의 인덱스가 값과 맞을경우 실행
	{
		return pNode;//값을 찾았을경우 그 노드를 반환
	}
	for (int Child = 0;Child < 2;Child++)
	{
		Node* pFind = Find(pNode->pChild[Child], iValue);//못찾았을경우 노드를 다시 검색해 들어감
		if (pFind != NULL)return pFind;//값을 찾았을경우 바로 나갈수있게 노드를 반환
	}
	return NULL;//값을 못찾았을경우 NULL을 반환
}
void AddNode(int iValue)//노드를 생성하는 함수
{
	Node* pNode = NewNode(iValue);//노드를 초기화하고 값을 넣는다
	Node* pParent = Find(g_pRootNode, (pNode->iIndex - 1) / 2);//노드의 부모를 찾기
	if (pParent->pChild[0] == NULL)//부모노드의 좌측 자식노드가 없을경우
	{
		pParent->pChild[0] = pNode;//부모노드의 좌측자식에 노드를 입력
	}
	else//그게 아닐경우
	{
		pParent->pChild[1] = pNode;//부모노드의 우측자식에 노드를 입력
 	}
}
void DataSet(int iData[],int iValue)//데이터를 생성하는 함수
{
	time_t tmp = clock();// 변수에 시간값을 넣는다 (1000=1초)
	unsigned int iTick = rand();//변수에 랜덤한값을 집어넣음
	srand((unsigned int)time(&tmp));//시간마다 랜덤한값을 생성
	for (int i = 0;i < iValue;i++)
	{
		iData[i] = (iTick + rand())%iValue;//배열안에 랜덤한 값을 집어넣는다.
	}
}
void PrintNode(Node* pNode)//노드 출력 함수
{
	if (pNode == NULL)return;//만약 노드값이 없다면 내보내라
	//printf("%d ", pNode->iIndex);//전위
	PrintNode(pNode->pChild[0]);//노드의 좌측자식으로 이동
	//printf("%d ", pNode->iIndex);//중위
	PrintNode(pNode->pChild[1]);//노드의 우측자식으로이동
	printf("%d ", pNode->iIndex);//후위 마지막에 읽은노드의 인덱스값을 출력
}

int main()
{
	const int MAX_CNT = 16;//배열의 갯수
	int iData[MAX_CNT];//배열 생성
	DataSet(iData,MAX_CNT);//배열에 값을 집어넣는다
	g_pRootNode = NewNode(iData[0]);//루트노드에 값을 집어넣기
	for (int i = 1;i < MAX_CNT;i++)
	{
		AddNode(iData[i]);//자식노드들에게 값을 집어넣는다.
	}
	PrintNode(g_pRootNode);//노드의 값을 출력
	return 0;
}