#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <stdio.h>
#include <time.h>
#include <cstdlib>
#include <string>
#include <iostream>
#include <conio.h>
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
void Swap(int* a, int* b)
{
	if ((*a) > (*b)) {
		int t = 0;
		t = *a;
		*a = *b;
		*b = t;
	}
}
void SelSort(int Array[], int iCnt) {
	for (int i = 0; i < iCnt; i++)
	{
		for (int j = i+1;j < iCnt; j++)
		{
				Swap(&Array[i], &Array[j]);
		}
	}
}
void BubSort(int Array[], int iCnt) {
	for (int i = 1;i < iCnt;i++)
	{
		for (int j = 0;j < iCnt-i;j++) 
		{
			Swap(&Array[j], &Array[j + 1]);
		}
	}
}
void IstSort(int Array[], int iCnt, int iStart=1, int iStep=1) {
	for (int i = iStart; i < iCnt;i+=iStep) {
		int Temp = Array[i];
		int a = i - iStep;
		while (a >= 0 && Temp < Array[a])
		{
			Array[a + iStep] = Array[a];
			a-=iStep;
		}
		Array[a + iStep] = Temp;
	}
}
void SheSort(int Array[], int iCnt) {
	int k = iCnt;
	while (k>1)
	{
		k = k / 2;
		for (int i = 0;i < k;i++)
		{
			IstSort(Array, iCnt, i, k);
		}
		
	}
}
int Partition(int Array[], int iBegin,int iEnd) {
	int left,right,iPivot;
	left = iBegin+1;
	right = iEnd;
	iPivot = iBegin;
	while (left <= right)
	{
		while (Array[left]<=Array[iPivot] && left<=iEnd)left++;
		while (Array[right]>=Array[iPivot] && right>=iBegin+1)right--;
		if (left <= right) 
		{
			Swap(&Array[left], &Array[right]);
		}
	}
	Swap(&Array[iPivot], &Array[right]);
	return right;
}
void QuiSort(int Array[], int iBegin,int iEnd) {
	if (iBegin < iEnd)
	{
		int X = Partition(Array, iBegin, iEnd);
		QuiSort(Array, iBegin, X - 1);
		QuiSort(Array, X + 1, iEnd);
	}
}
void DataPrint(int item[], int iCount)
{
	for (int i = 0; i < 10;i++)
	{
		printf("%d ", item[i]);
	}
}
#define MAX_CNT 6
void main() {

		int Array[MAX_CNT];

		SetData(Array,MAX_CNT);	
		time_t stmp = clock();
		SelSort(Array, MAX_CNT);
		time_t etmp = clock();
		printf("\n%s:%8.3f[%ld] ", "선택정렬", (etmp - stmp) / (double)CLK_TCK, etmp - stmp);
		DataPrint(Array, MAX_CNT);

		SetData(Array, MAX_CNT);
		stmp = clock();
		BubSort(Array, MAX_CNT);
		etmp = clock();
		printf("\n%s:%8.3f[%ld] ", "거품정렬", (etmp - stmp) / (double)CLK_TCK, etmp - stmp);
		DataPrint(Array, MAX_CNT);

		SetData(Array, MAX_CNT);
		stmp = clock();
		IstSort(Array, MAX_CNT);
		etmp = clock();
		printf("\n%s:%8.3f[%ld] ", "삽입정렬", (etmp - stmp) / (double)CLK_TCK, etmp - stmp);
		DataPrint(Array, MAX_CNT);
	
		SetData(Array, MAX_CNT);
		stmp = clock();
		SheSort(Array, MAX_CNT);
		etmp = clock();
		printf("\n%s:%8.3f[%ld] ", "셀정렬", (etmp - stmp) / (double)CLK_TCK, etmp - stmp);
		DataPrint(Array, MAX_CNT);
	
		SetData(Array, MAX_CNT);
		stmp = clock();
		QuiSort(Array,0, MAX_CNT-1);
		etmp = clock();
		printf("\n%s:%8.3f[%ld] ", "퀵정렬", (etmp - stmp) / (double)CLK_TCK, etmp - stmp);
		DataPrint(Array, MAX_CNT);

		getchar();
}