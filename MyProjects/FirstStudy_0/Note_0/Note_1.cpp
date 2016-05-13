#include "stdafx.h"
#include <cstdlib>
#include <time.h>

struct Node
{
	int iData;
	int iIndex;
	Node* pChild[2];
};
Node* g_pRootNode = 0;//��Ʈ ���
int g_iIndex = 0;//����� �ε���

Node* NewNode(int iValue)//��� ���� �Լ�
{
	Node* pNode = new Node;//��忡 �����Ͱ� ����
	pNode->iData = iValue;
	pNode->iIndex = g_iIndex++;//����� �ε������� �ο�
	pNode->pChild[0] = 0;//2��Ʈ���� ���ʳ��
	pNode->pChild[1] = 0;//2��Ʈ���� �����ʳ��
	return pNode;//��� ��ȯ
}
Node* Find(Node* pNode, int iValue)//��� �˻� �Լ�;
{
	if (pNode == NULL)return NULL;//��尪�� ������� NULL�� ��ȯ
	if (pNode->iIndex == iValue)//�˻��ѳ���� �ε����� ���� ������� ����
	{
		return pNode;//���� ã������� �� ��带 ��ȯ
	}
	for (int Child = 0;Child < 2;Child++)
	{
		Node* pFind = Find(pNode->pChild[Child], iValue);//��ã������� ��带 �ٽ� �˻��� ��
		if (pFind != NULL)return pFind;//���� ã������� �ٷ� �������ְ� ��带 ��ȯ
	}
	return NULL;//���� ��ã������� NULL�� ��ȯ
}
void AddNode(int iValue)//��带 �����ϴ� �Լ�
{
	Node* pNode = NewNode(iValue);//��带 �ʱ�ȭ�ϰ� ���� �ִ´�
	Node* pParent = Find(g_pRootNode, (pNode->iIndex - 1) / 2);//����� �θ� ã��
	if (pParent->pChild[0] == NULL)//�θ����� ���� �ڽĳ�尡 �������
	{
		pParent->pChild[0] = pNode;//�θ����� �����ڽĿ� ��带 �Է�
	}
	else//�װ� �ƴҰ��
	{
		pParent->pChild[1] = pNode;//�θ����� �����ڽĿ� ��带 �Է�
 	}
}
void DataSet(int iData[],int iValue)//�����͸� �����ϴ� �Լ�
{
	time_t tmp = clock();// ������ �ð����� �ִ´� (1000=1��)
	unsigned int iTick = rand();//������ �����Ѱ��� �������
	srand((unsigned int)time(&tmp));//�ð����� �����Ѱ��� ����
	for (int i = 0;i < iValue;i++)
	{
		iData[i] = (iTick + rand())%iValue;//�迭�ȿ� ������ ���� ����ִ´�.
	}
}
void PrintNode(Node* pNode)//��� ��� �Լ�
{
	if (pNode == NULL)return;//���� ��尪�� ���ٸ� ��������
	//printf("%d ", pNode->iIndex);//����
	PrintNode(pNode->pChild[0]);//����� �����ڽ����� �̵�
	//printf("%d ", pNode->iIndex);//����
	PrintNode(pNode->pChild[1]);//����� �����ڽ������̵�
	printf("%d ", pNode->iIndex);//���� �������� ��������� �ε������� ���
}

int main()
{
	const int MAX_CNT = 16;//�迭�� ����
	int iData[MAX_CNT];//�迭 ����
	DataSet(iData,MAX_CNT);//�迭�� ���� ����ִ´�
	g_pRootNode = NewNode(iData[0]);//��Ʈ��忡 ���� ����ֱ�
	for (int i = 1;i < MAX_CNT;i++)
	{
		AddNode(iData[i]);//�ڽĳ��鿡�� ���� ����ִ´�.
	}
	PrintNode(g_pRootNode);//����� ���� ���
	return 0;
}