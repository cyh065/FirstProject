#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
char* strncp(char* str2, char* str, int c) {
	int i;
	char* st = str;
	for (i = 0;i < c;i++) {
		str2[i] = str[i];
	}
	str2[i] = 0;
	i = 0;
	return str2;
}
int strcmpy(char* str1, char* str2) {
	if(str1 == str2){
		return 0;
	}
	else{
		int j = 0;
		int ctr1[10],ctr2[10];
		
		for (j = 0; j < *str1; j++) {
			ctr1[j] = *(str1 + j);
			ctr2[j] = *(str2 + j);
			if (ctr1[j] > ctr2[j]) {
				return 1;
			}
			if (ctr1[j] < ctr2[j]) {
				return -1;
			}
		}
	}
}
char* strst(char* str1, char* str2) {
	int iCnt = 0;
	char* st = str2;
	while (1)
	{
		if (*str1 == *str2) {
			str1++;
			str2++;
			iCnt++;
		}
		else if (*str2 == '\0')
		{
			return str1 - iCnt;
			break;
		}
		else if (*str1 == '\0')
		{
			return 0;
			break;
		}
		else if (*str1 != *str2)
		{
			str2 = st;
			str1++;
			iCnt = 0;
		}
	}

}
void main()
{
	char *str1 = "KGCA game academy - 31 - ";
	char str2[10];
	char *str3 = "game";
	printf("str1: %s\n", str1);
	printf("str2: %s\n", strncp(str2, str1, 4));
	
	printf("str2: %s\n", str2);
	printf("str1 Length: %d\n", strcmpy(str1, str2));
	printf("str2 Length: %d\n", strcmpy(str2, str1));
	printf("str2 Length: %d\n", strcmpy(str2, str2));
	printf("str1: %s\n", str1);
	printf("str2: %s\n", str2);
	printf("str2: %s\n", strst(str1, str3));
	printf("str1: %s\n", str1);
	printf("str2: %s\n", str2);
}