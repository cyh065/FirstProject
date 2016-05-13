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
	cout << "정수 입력";
	cin >> iValue;
	cin >> fValue;
	cout << iValue << " " << fValue;
	//char ch
	//while(ch = cin.get() != '\n' && ch != EOF);
	//error C2086 : 'float fValue' : 재정의
	//float fValue = 3.141592f;
	//char cValue;
	//unsigned char i; // 부호 없는 0 ~ 255
	//signed char j; // 부호 있는 -128 ~ 127

	printf("디버그 버전");
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
//	printf("탑의 높이는?");
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
	
	printf("\n문자 입력1");
	scanf("%c", &ch0);
	while (getchar() != '\n');
	printf("\n문자 입력2");
	scanf("%c", &ch1);
	printf("\n정수 입력");
	scanf("%d", &iValue);
	printf("\n실수 입력");
	scanf("%f", &fValue);
	printf("\n문자열 입력");
	scanf("%s", array);
	printf("%d %-10.2f",ch0, iValue, fValue);
	printf("\n%s", array);
	printf("릴리즈 버전");
}
#endif