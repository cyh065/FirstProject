#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
int iCount = 1;
void Hanoi(int iCnt,char a,char b,char c) {
	if (iCnt > 0) {
		Hanoi(iCnt - 1, a, c, b);
		printf("%d. [%d����] %c - > %c\n",iCount,iCnt, a, c);
		iCount++;
		Hanoi(iCnt - 1, b, a, c);
	}
}
void main() {
	int i;
	printf("�����ǰ������˷��ּ���.");
	scanf("\n%d", &i);
	Hanoi(i,'A','B','C');
}