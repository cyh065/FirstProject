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
	printf("================ ���� ���� ���α׷�===============\n");
	printf("==================================================\n");
}
void ListInput() {
	TData* pEnd = 0;
	int iNum = 0;
	printf("�ο��� ����Դϱ�?\t");//�ο�����
	scanf("%d", &iNum);
	char name[10];
	int k, e, m;
	for (int i = 0; i < iNum; i++)
	{
		TData* A = (TData*)malloc(sizeof(TData));//������
		printf("\n�̸�:\t");
		while (getchar() != '\n');
		scanf("%s", &name);
		while (getchar() != '\n');
		printf("����:\t");
		scanf("%d", &k);
		printf("����:\t");
		scanf("%d", &e);
		printf("����:\t");
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

	if (pFileName == NULL)return false;//pFileName�� ������� ���
	FILE* fp = fopen(pFileName, "w");//���� ���Ѻο�
	if (fp == NULL)return false;
	fprintf(fp, "##########��������##########");
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
	fclose(fp);//���� �ݱ�
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

	while (!feof(fpRead)) //������ ����������
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
	printf("##########�� ��##########");
	printf("\n�̸�\t����\t����\t����\t����\t���\n");
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
	printf("�̸�:"); scanf("%s", pStudent->szName);
	printf("����:"); scanf("%d", &pStudent->kor);
	printf("����:"); scanf("%d", &pStudent->eng);
	printf("����:"); scanf("%d", &pStudent->mat);
	pStudent->tot = (pStudent->kor + pStudent->eng + pStudent->mat);
	pStudent->avr = pStudent->tot / 3;
	AddLink(pStudent);
}
void ListDel() {
	while (1) {
		char Search[10] = { 0, };
		printf("������ �̸�: "); scanf("%s", Search);
		TData* pSearch = SearchLink(Search);
		if (pSearch != NULL)
		{
			DelLink(pSearch);
			break;
		}
		else
		{
			printf("�˻��Ҽ� �����ϴ�.");
		}
	}
}
void LinkUp() {
	while (1) {
		char Search[10] = { 0, };
		printf("�˻� �̸�: "); scanf("%s", Search);
		TData* pSearch = SearchLink(Search);
		if (pSearch != NULL)
		{
			printf("�̸�:"); scanf("%s", pSearch->szName);
			printf("����:"); scanf("%d", &pSearch->kor);
			printf("����:"); scanf("%d", &pSearch->eng);
			printf("����:"); scanf("%d", &pSearch->mat);
			pSearch->tot = (pSearch->kor + pSearch->eng + pSearch->mat);
			pSearch->avr = pSearch->tot / 3;
			break;
		}
		else
		{
			printf("�˻��Ҽ� �����ϴ�.");
		}
	}
}
void main(int argc,char* argv[])
{
	while (1)
	{
		int iCnt = 0;
		printf("select-(����: 0, ���: 1, �߰�: 2, ����: 3, ����: 4, ����: 999)\n");
		scanf("%d", &iCnt);
		if (iCnt == 999)break;//����
		switch (iCnt)
		{
		case 0:
		{
			Clear();//ȭ�� �ʱ�ȭ
			ListInput();//��忡 ���� �޾Ƴ���
			WriteFile(argv[1]);// ���ϻ����Ͽ� ListInput���� ���� ���� ���Ͽ� ����ִ´�
			DeleteNode();//��� �ʱ�ȭ
		}break;
		case 1:
		{
			Clear();//ȭ�� �ʱ�ȭ
			ReadFile(argv[1]);//���Ͽ� �ִ� ���� �о� ��忡 �޾ƿ´�.
			ListPrint();//ȭ�鿡 ��尪�� ���
			DeleteNode();//��� �ʱ�ȭ
		}break;
		case 2:
		{
			Clear();//ȭ�� �ʱ�ȭ
			ReadFile(argv[1]);//���Ͽ� �ִ� ���� �о� ��忡 �޾ƿ´�.
			ListPlus();//���ο� ���� �޾� ��忡 �߰�
			ListPrint();//ȭ�鿡 ��尪�� ���
			WriteFile(argv[1]);//���ο� ��尪�� ���Ͽ� �ִ´�.
			DeleteNode();//��� �ʱ�ȭ
		}break;
		case 3:
		{
			Clear();//ȭ�� �ʱ�ȭ
			ReadFile(argv[1]);//���Ͽ� �ִ� ���� �о� ��忡 �޾ƿ´�.
			ListDel();//��带 �˻��Ͽ� �˻��� ����� ���� �����Ѵ�.
			Clear();//ȭ�� �ʱ�ȭ
			ListPrint();//ȭ�鿡 ���� ��带 �� ������ ������ ���
			WriteFile(argv[1]);//������ ������ ���Ͽ� �ִ´�.
			DeleteNode();//��� �ʱ�ȭ
		}break;
		case 4:
		{
			Clear();//ȭ�� �ʱ�ȭ
			ReadFile(argv[1]);//���Ͽ� �ִ� ���� �о� ��忡 �޾ƿ´�.
			LinkUp();//��尪�� �˻��Ͽ� �˻��ѳ�带 �����Ѵ�.
			ListPrint();//ȭ�鿡 ������ ���
			WriteFile(argv[1]);//������ ������ ���Ͽ� �ִ´�.
			DeleteNode();//��� �ʱ�ȭ
		}break;
		}
	}

	getchar();
}