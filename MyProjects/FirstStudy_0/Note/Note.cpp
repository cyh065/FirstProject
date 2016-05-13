// Note.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <cstdlib>
#include <time.h>
#include <cstdio>
struct Node
{
	int iData;
	int iIndex;
	Node* pChild[2];
};
Node* g_Array[50000];
Node* g_RootNode = 0;
int g_iIndex=0;
bool Swap(int* a, int* b)
{
	if ((*a) > (*b))
	{
		int t = *a;
		*a = *b;
		*b = t;
		return true;
	}
	return false;
}
void SelectionSort(int item[], int iCount)
{
	for (int a = 0;a < iCount;a++)
	{
		for (int b = a + 1;b < iCount;b++)
		{
			Swap(&item[a], &item[b]);
		}
	}
}
void InsertionSort(int item[], int iCount, int iStart = 1, int iStep = 1)
{
	for (int a = iStart;a < iCount;a += iStep)
	{
		int tmp = item[a];
		int b = a - iStep;
		while (b >= 0 && item[b] > tmp)
		{
			item[b + iStep] = item[b];
			b -= iStep;
		}
		item[b + iStep] = tmp;
	}
}
void ShellSort(int item[], int iCount)
{
	int k = iCount;
	while (k>1)
	{
		k = k / 2;
		// 부분정렬
		for (int s = 0;s < k;s++)
		{
			InsertionSort(item, iCount, s, k);
		}
	}
}
Node* Find(Node* pNode, int iValue) 
{
	if (pNode == NULL)return NULL;
	if (pNode->iIndex == iValue)
	{
		return pNode;
	}
	for (int iChild = 0;iChild < 2;iChild++)
	{
		Node* pFind = Find(pNode->pChild[iChild], iValue);
		if (pFind != NULL) return pFind;
	}
	return NULL;
}
Node* NewNode(int iValue)
{
	Node* pNode = new Node;
	g_Array[g_iIndex];
	pNode->iData = iValue;
	pNode->iIndex = g_iIndex++;
	pNode->pChild[0] = 0;
	pNode->pChild[1] = 0;
	return pNode;
}
void AddNode(int iValue) 
{
	Node* pNode = NewNode(iValue);
	int Temp = 0;
	Node* pParent = Find(g_RootNode,(pNode->iIndex-1)/2);
	
	if (pParent->pChild[0] == NULL)
	{
		pParent->pChild[0]= pNode;

	}
	else
	{
		pParent->pChild[1] = pNode;
	}
	if (g_RootNode->iData < pNode->iData) {
		Temp = pNode->iData;
		pNode->iData = g_RootNode->iData;
		g_RootNode->iData = Temp;
	}
}
void PrintNode(Node* pNode)
{
	if (pNode == NULL) return;
	//printf("%d  ", pNode->iIndex);
	PrintNode(pNode->pChild[0]);
	//printf("%d  ", pNode->iIndex);
	PrintNode(pNode->pChild[1]);
	//printf("%d  ", pNode->iIndex);
}
void SetData(int Array[], int iCnt)
{
	time_t tmp = clock();
	unsigned int iTick = rand();
	srand((unsigned int)time(&tmp));
	for (int i = 0;i < iCnt;i++)
	{
		Array[i] = (iTick + rand()) % iCnt;
	}
}
void HeapSort(int item[],int iValue) {
	
	for (int i = 0;i < iValue-1;i++)
	{
		Node* pNode = Find(g_RootNode, i);
		item[i] = pNode->iData;
	}
	ShellSort(item, iValue);
}
void DataPrint(int item[],int iValue) {
	printf("\n");
	for (int i = 0;i < iValue;i++) {
		printf("%d ", item[i]);
	}
}
int main()
{
	const int MAX_CNT = 50000;
	int iData[MAX_CNT];
	SetData(iData, MAX_CNT);
	g_RootNode = NewNode(iData[0]);
	for (int iCnt = 1;iCnt < MAX_CNT;iCnt++)
	{
		AddNode(iData[iCnt]);
	}
	PrintNode(g_RootNode);
	time_t stmp = clock();
	HeapSort(iData, MAX_CNT);
	time_t etmp = clock();
	printf("\n%s: %8.3f[%ld] ", "힙정렬", (etmp - stmp) / (double)CLK_TCK, etmp - stmp);
	DataPrint(iData, 10);
	stmp = clock();

	SetData(iData, MAX_CNT);
	SelectionSort(iData, MAX_CNT);
	etmp = clock();
	printf("\n%s: %8.3f[%ld] ", "선택정렬", (etmp - stmp) / (double)CLK_TCK, etmp - stmp);  
	DataPrint(iData, 10);

	return 0;
}