// Note_0.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <cstdlib>
#include <time.h>

void SetData(int iData[],int iValue)
{
	time_t tmp = clock();
	unsigned int iTick = rand();
	srand((unsigned int)time(&tmp));
	for (int i = 0;i < iValue;i++)
	{
		iData[i] = (iTick + rand())%iValue;
	}

}
bool Swap(int* a, int* b)
{
	if ((*a ) > (*b)) {
		int t = 0;
		t = *a;
		*a = *b;
		*b = t;
		return true;
	}
	return false;
}
void SelectSort(int iData[],int iValue)
{
	for (int i = 0;i < iValue;i++)
	{
		for (int j = i+1; j < iValue;j++)
		{
			Swap(&iData[i], &iData[j]);
		}
	}
}
void InsertSort(int iData[], int iValue, int iStart = 1,int iStep = 1)
{
	for (int i = iStart;i < iValue;i+=iStep)
	{
		int Temp = iData[i];
		int j = i - iStep;
		while (j >= 0 && iData[j] > Temp)
		{
			iData[j + iStep] = iData[j];
			j -= iStep;
		}
		iData[j + iStep] = Temp;
	}
}
void ShellSort(int iData[], int iValue)
{
	int k = iValue;
	while(k>1)
	{
		k = k / 2;
		for (int j = 0;j < k;j++)
		{
			InsertSort(iData, iValue, j, k);
		}
	}
}
void BubbleSort(int iData[], int iValue)
{
	for (int i = 0;i < iValue-1;i++)
	{
		for (int j = 0;j < iValue-i-1;j++)
		{
			Swap(&iData[j], &iData[j+1]);
		}
	}
}
int Partition(int iData[], int iBegin, int iEnd)
{
	int left, right, iPivot;
	left = iBegin+1;
	right = iEnd;
	iPivot = iBegin;
	while (left <= right) 
	{
		while (iData[left] <= iData[iPivot] && left <= iEnd)left++;
		while (iData[right] >= iData[iPivot] && right >= iBegin+1)right--;
		if (left <= right)
		{
			Swap(&iData[left], &iData[right]);
		}
	}
	Swap(&iData[iBegin], &iData[right]);
	return right;
}
void QuickSort(int iData[], int iBegin, int iEnd)
{
	if (iBegin < iEnd) {
		int X = Partition(iData, iBegin, iEnd);
		QuickSort(iData, iBegin, X - 1);
		QuickSort(iData, X + 1, iEnd);
	}
}
void PrintData(int iData[],int iValue) 
{
	for (int i = 0;i < iValue;i++)
	{
		printf("%d ",iData[i]);
	}
}

#define MAX_CNT 50000

int main()
{
	int iData[MAX_CNT];
	SetData(iData,MAX_CNT);
	time_t sTmp = clock();
	//선택 정렬
	SelectSort(iData,MAX_CNT);
	time_t eTmp = clock();
	printf("\n%s : %8.3f[%ld]\n","선택 정렬",(eTmp-sTmp)/(double)CLK_TCK,eTmp-sTmp);
	PrintData(iData, 10);

	SetData(iData, MAX_CNT);
	sTmp = clock();
	//거품 정렬
	BubbleSort(iData, MAX_CNT);
	eTmp = clock();
	printf("\n%s : %8.3f[%ld]\n", "거품 정렬", (eTmp - sTmp) / (double)CLK_TCK, eTmp - sTmp);
	PrintData(iData, 10);

	SetData(iData, MAX_CNT);
	sTmp = clock();
	//삽입 정렬
	InsertSort(iData, MAX_CNT);
	eTmp = clock();
	printf("\n%s : %8.3f[%ld]\n", "삽입 정렬", (eTmp - sTmp) / (double)CLK_TCK, eTmp - sTmp);
	PrintData(iData, 10);

	SetData(iData, MAX_CNT);
	sTmp = clock();
	//쉘 정렬
	ShellSort(iData, MAX_CNT);
	eTmp = clock();
	printf("\n%s : %8.3f[%ld]\n", "쉘 정렬", (eTmp - sTmp) / (double)CLK_TCK, eTmp - sTmp);
	PrintData(iData, 10);

	SetData(iData, MAX_CNT);
	sTmp = clock();
	//퀵 정렬
	QuickSort(iData,0, MAX_CNT-1);
	eTmp = clock();
	printf("\n%s : %8.3f[%ld]\n", "퀵 정렬", (eTmp - sTmp) / (double)CLK_TCK, eTmp - sTmp);
	PrintData(iData, 10);
     return 0;
}

