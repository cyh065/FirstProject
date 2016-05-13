#include "Student.h"


void Student::WriteData(int iNum, int const ResultSet())
{
	FILE* fpCreate = fopen("Data.txt", "w");
	srand((unsigned)time(NULL));
	if (fpCreate)
	{
		for (int iCnt = 0; iCnt < iNum; iCnt++)
		{
			int iNameA = 65 + rand() % 26;
			int iNameB = 65 + rand() % 26;
			int iNameC = 97 + rand() % 26;
			int iKor   = ResultSet();
			int iEng   = ResultSet();
			int iMat   = ResultSet();
			fprintf(fpCreate, "%c%c%c %d %d %d\n", iNameA, iNameB, iNameC,
				iKor, iEng, iMat);
		}
		fclose(fpCreate);
	}
}
void Student::ReadData()
{
	FILE* fpRead = fopen("Data.txt", "r");
	if (fpRead)
	{
		for (int iCnt = 0;iCnt < g_iNum;iCnt++)
		{
			char strBuffer[256] = { 0, };
			Student* pStudent = (Student*)malloc(sizeof(Student));
			memset(pStudent, 0, sizeof(Student));

		}
	}
}



Student::Student()
{
}


Student::~Student()
{
}
