#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string>
struct TData
{
	char szName[10];
	int kor;
	int eng;
	int mat;
	int tot;
	float avr;
	TData* pNext;
	TData* pPrev;
};
TData* g_Head = 0;
TData* g_Tail = 0;
void Clear() {
	system("cls");
	printf("==================================================\n");
	printf("================ 성적 관리 프로그램===============\n");
	printf("==================================================\n");
}
void ListInput() {
	TData* pEnd = 0;
	int iNum = 0;
	printf("인원이 몇명입니까?\t");//인원설정
	scanf("%d", &iNum);
	char name[10];
	int k, e, m;
	for (int i = 0; i < iNum; i++)
	{
		TData* A = (TData*)malloc(sizeof(TData));//노드생성
		printf("\n이름:\t");
		while (getchar() != '\n');
		scanf("%s", &name);
		while (getchar() != '\n');
		printf("국어:\t");
		scanf("%d", &k);
		printf("영어:\t");
		scanf("%d", &e);
		printf("수학:\t");
		scanf("%d", &m);
		strcpy(A->szName, name);
		A->kor = k;
		A->eng = e;
		A->mat = m;
		A->pNext = 0;
		A->tot = (k + e + m);
		A->avr = (k + e + m) / 3;
		if (g_Head == NULL) {
			g_Head = A;
			pEnd = A;
		}
		else
		{
			pEnd -> pNext = A;
			pEnd = A;
		}
	}
}
bool WriteFile(char* pFileName){

	if (pFileName == NULL)return false;//pFileName이 없을경우 취소
	FILE* fp = fopen(pFileName, "w");//쓰기 권한부여
	if (fp == NULL)return false;
	fprintf(fp, "##########성적관리##########");
	for (TData* pNode = g_Head;
	pNode != NULL;
		pNode = pNode->pNext)
	{
		fprintf(fp, "\n%s\t%d\t%d\t%d\t%d\t%0.3f",
			pNode->szName,
			pNode->kor,
			pNode->eng,
			pNode->mat,
			pNode->tot,
			pNode->avr);
	}
	fclose(fp);//파일 닫기
}
void DeleteNode(){
	TData* pDelNode = 0;
	TData* pNode = g_Head;
	while (pNode != NULL) {
		pDelNode = pNode;
		pNode = pNode->pNext;
		free(pDelNode);
	}
	g_Head = 0;
}
void ReadFile(char* pFileName) {
	if (pFileName == NULL)return;
	FILE* fpRead = fopen(pFileName, "r");
	if(fpRead == NULL)return;
	char Buffer[256] = { 0, };
	fscanf(fpRead, "%s", Buffer);
	
	TData* pEnd = 0;
	TData* pFirst = 0;

	while (!feof(fpRead)) //파일이 끝날때까지
	{
		TData* B = (TData*)malloc(sizeof(TData));
		fscanf(fpRead,"%s%d%d%d%d%f",
			B->szName,
			&B->kor,
			&B->eng,
			&B->mat,
			&B->tot,
			&B->avr);

		B->pNext = 0;
		if (g_Head == NULL) {
			g_Head = B;
			g_Tail = g_Head;
			pEnd = B;
			g_Tail->pPrev = 0;
		}
		else
		{
			pFirst = g_Head;         
			g_Head = B;
			g_Head->pNext = pFirst;
			if (g_Tail->pPrev == 0) {
				g_Tail->pPrev = g_Head;
			}
			else {
				pFirst->pPrev = g_Head;
				g_Head->pPrev = NULL;
			}
		}
	}
	fclose(fpRead);
}
void ListPrint() {
	printf("##########성 적##########");
	printf("\n이름\t국어\t영어\t수학\t총점\t평균\n");
	for (TData* pNode = g_Head;
	pNode != NULL;
		pNode = pNode->pNext){
		printf("%s\t%d\t%d\t%d\t%d\t%0.3f\n",
			pNode->szName,
			pNode->kor,
			pNode->eng,
			pNode->mat,
			pNode->tot,
			pNode->avr);
	}
}
void AddLink(TData* pStudent) {
	for (TData* pTemp = g_Head;
	pTemp != NULL;
		pTemp = pTemp->pNext) {
		if (pTemp->pNext == NULL) {
			pTemp->pNext = pStudent;
			return;
		}
	}
	g_Head = pStudent;
}
void DelLink(TData* pStudent) {
	if (g_Head == pStudent) {
		g_Head = pStudent->pNext;
		free(pStudent);
		return;
	}
	for (TData* pTemp = g_Head;
	pTemp != NULL;
		pTemp = pTemp->pNext) {
		if (pTemp->pNext == pStudent) {
			pTemp->pNext = pStudent->pNext;
			free(pStudent);
			break;
		}
	}
}
TData* SearchLink(char* strName) {
	TData* pList = g_Head;
	for (TData* pTemp = pList;
	pTemp != NULL;
		pTemp = pTemp->pNext) {
		if (strcmp(pTemp->szName,strName) == 0) {
			return pTemp;
		}
	}
	return NULL;
}
void ListPlus() {
	TData* pStudent = (TData*)malloc(sizeof(TData));
	memset(pStudent, 0, sizeof(TData));
	printf("이름:"); scanf("%s", pStudent->szName);
	printf("국어:"); scanf("%d", &pStudent->kor);
	printf("영어:"); scanf("%d", &pStudent->eng);
	printf("수학:"); scanf("%d", &pStudent->mat);
	pStudent->tot = (pStudent->kor + pStudent->eng + pStudent->mat);
	pStudent->avr = pStudent->tot / 3;
	AddLink(pStudent);
}
void ListDel() {
	while (1) {
		char Search[10] = { 0, };
		printf("삭제할 이름: "); scanf("%s", Search);
		TData* pSearch = SearchLink(Search);
		if (pSearch != NULL)
		{
			DelLink(pSearch);
			break;
		}
		else
		{
			printf("검색할수 없습니다.");
		}
	}
}
void LinkUp() {
	while (1) {
		char Search[10] = { 0, };
		printf("검색 이름: "); scanf("%s", Search);
		TData* pSearch = SearchLink(Search);
		if (pSearch != NULL)
		{
			printf("이름:"); scanf("%s", pSearch->szName);
			printf("국어:"); scanf("%d", &pSearch->kor);
			printf("영어:"); scanf("%d", &pSearch->eng);
			printf("수학:"); scanf("%d", &pSearch->mat);
			pSearch->tot = (pSearch->kor + pSearch->eng + pSearch->mat);
			pSearch->avr = pSearch->tot / 3;
			break;
		}
		else
		{
			printf("검색할수 없습니다.");
		}
	}
}
void main(int argc,char* argv[])
{
	while (1)
	{
		int iCnt = 0;
		printf("select-(생성: 0, 출력: 1, 추가: 2, 삭제: 3, 수정: 4, 종료: 999)\n");
		scanf("%d", &iCnt);
		if (iCnt == 999)break;//종료
		switch (iCnt)
		{
		case 0:
		{
			Clear();//화면 초기화
			ListInput();//노드에 값을 받아넣음
			WriteFile(argv[1]);// 파일생성하여 ListInput에서 받은 값을 파일에 집어넣는다
			DeleteNode();//노드 초기화
		}break;
		case 1:
		{
			Clear();//화면 초기화
			ReadFile(argv[1]);//파일에 있는 값을 읽어 노드에 받아온다.
			ListPrint();//화면에 노드값을 출력
			DeleteNode();//노드 초기화
		}break;
		case 2:
		{
			Clear();//화면 초기화
			ReadFile(argv[1]);//파일에 있는 값을 읽어 노드에 받아온다.
			ListPlus();//새로운 값을 받아 노드에 추가
			ListPrint();//화면에 노드값을 출력
			WriteFile(argv[1]);//새로운 노드값을 파일에 넣는다.
			DeleteNode();//노드 초기화
		}break;
		case 3:
		{
			Clear();//화면 초기화
			ReadFile(argv[1]);//파일에 있는 값을 읽어 노드에 받아온다.
			ListDel();//노드를 검색하여 검색한 노드의 값을 삭제한다.
			Clear();//화면 초기화
			ListPrint();//화면에 지운 노드를 뺀 나머지 노드들을 출력
			WriteFile(argv[1]);//나머지 노드들을 파일에 넣는다.
			DeleteNode();//노드 초기화
		}break;
		case 4:
		{
			Clear();//화면 초기화
			ReadFile(argv[1]);//파일에 있는 값을 읽어 노드에 받아온다.
			LinkUp();//노드값을 검색하여 검색한노드를 수정한다.
			ListPrint();//화면에 노드들을 출력
			WriteFile(argv[1]);//수정된 노드들을 파일에 넣는다.
			DeleteNode();//노드 초기화
		}break;
		}
	}

	getchar();
}