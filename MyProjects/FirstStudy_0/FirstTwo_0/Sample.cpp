#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
#include<iostream>
#include<cstdio>
using namespace std;
//#undef _DEBUG
#ifndef _DEBUG
void main()
{
	
	int iValue;
	float fValue;
	cout << "���� �Է�";
	cin >> iValue;
	cin >> fValue;
	cout << iValue << " " << fValue;
	//char ch
	//while(ch = cin.get() != '\n' && ch != EOF);
	//error C2086 : 'float fValue' : ������
	//float fValue = 3.141592f;
	//char cValue;
	//unsigned char i; // ��ȣ ���� 0 ~ 255
	//signed char j; // ��ȣ �ִ� -128 ~ 127

	printf("����� ����");
}
//void HanoiTower(int i, char a, char b, char c)
//{
//	if (i > 0) {
//		HanoiTower(i - 1, a, c, b);
//		printf("\n%c => %c", a, c);
//		HanoiTower(i - 1, b, a, c);
//	}
//}
//void main()
//{
//	int iValue;
//	printf("ž�� ���̴�?");
//	scanf("\n%d", &iValue);
//	HanoiTower(iValue, 'A', 'B', 'C');
//}
#else
void main()
{
	int iValue;
	float fValue = 3.14f;
	char array[7];// = "abcdef";
	char ch0,ch1;
	
	printf("\n���� �Է�1");
	scanf("%c", &ch0);
	while (getchar() != '\n');
	printf("\n���� �Է�2");
	scanf("%c", &ch1);
	printf("\n���� �Է�");
	scanf("%d", &iValue);
	printf("\n�Ǽ� �Է�");
	scanf("%f", &fValue);
	printf("\n���ڿ� �Է�");
	scanf("%s", array);
	printf("%d %-10.2f",ch0, iValue, fValue);
	printf("\n%s", array);
	printf("������ ����");
}
#endif