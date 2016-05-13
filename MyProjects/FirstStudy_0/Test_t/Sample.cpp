#define _CRT_SECURE_NO_WARNINGS
#include <Stdio.h>
#include <cstdio>
#include <iostream>
#include <string>
#include <cstdlib>

struct Node {
	char Name;
	int value;

	Node* pNext;
	Node* pPrev;
};
Node* g_Head = 0;
Node* g_Tail = 0;
Node* DelNode(Node * pNode) {
	Node* pDelNode = pNode->pNext;
	pDelNode->pNext->pPrev = pDelNode->pPrev;
	pDelNode->pPrev->pNext = pDelNode->pNext;
	pNode->pNext = pDelNode->pNext;

	printf("%c가 죽었다\n", pDelNode->Name);
	free(pDelNode);
	return pNode->pPrev;
}
void Josep(int Cnt, Node* pEnd) {
	Node* cNode = 0;
	while (pEnd != pEnd->pNext) {

		for (int i = 0;i < Cnt;i++) {
			cNode = pEnd;
			pEnd = pEnd->pPrev;
		}

		DelNode(pEnd);
	}
	printf("%c 가 살아남았다.", pEnd->Name);
}
void CircleList(int iCnt,char* Na) {
	Node* pEnd = 0;
	Node* pFir = 0;
	for (int i = 0; i < iCnt; i++) {
		Node* pNode = (Node*)malloc(sizeof(Node));
		if (g_Head == NULL) {
			pNode->value = 1;
			pNode->Name = Na[i];
			g_Head = pNode;
			g_Tail = g_Head;
			pEnd = pNode;
		}
		else {
			pNode->value = i + 1;
			pNode->Name = Na[i];
			pFir = g_Head;
			g_Head = pNode;
			g_Head->pNext = pFir;
			pFir->pPrev = g_Head;
		}
	}
	g_Head->pPrev = g_Tail;
	g_Tail->pNext = g_Head;
	int Cnt=0;
	printf("\n몇명 간격으로?\t");
	scanf("%d", &Cnt);
	Josep(Cnt,pEnd);
}
void main()
{

	int iCnt = 0;
	char Na[100];
	printf("병사의 순서를 정하시오\t");
	scanf("%s", &Na);
	iCnt = strlen(Na);
	CircleList(iCnt,Na);
	
}