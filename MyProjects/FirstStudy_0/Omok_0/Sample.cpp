#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <windows.h>
#include <cstdio>
#include <cstdlib>
#include <conio.h>
//키보드의 ASCII코드값 
#define	RIGHT	77
#define LEFT	75
#define UP		72
#define DOWN	80
#define ENTER	13

void	KeyCheck(bool bPlayer);
void	GotoXY(int x, int y);
void	Drawboard();
int		Judgment();

int OmokBoard[19][19];//오목판의 배열
//정중앙의 좌표
int iCursorX = 19;
int iCursorY = 9;



void KeyCheck(bool bPayer)//키보드의 값을읽어옴
{
	int iPlayTurn = 1;
	while (iPlayTurn)
	{
		switch (getch())
		{
		case RIGHT:
		{
			iCursorX += 2;
			if (iCursorX > 38)//우측 끝까지 갔을경우 우측으로 더이상 못가게 함
			{
				iCursorX -= 2;
			}
			GotoXY(iCursorX, iCursorY);
			break;
		}
		case LEFT:
		{
			iCursorX -= 2;
			if (iCursorX < 0)//좌측 끝까지 갔을경우 좌측으로 더이상 못가게 함
			{
				iCursorX += 2;
			}
			GotoXY(iCursorX, iCursorY);
			break;
		}
		case UP:
		{
			iCursorY--;
			if (iCursorY <= 0)//상단 끝까지 갔을경우 상단으로 더이상 못가게 함
			{
				iCursorY++;
			}
			GotoXY(iCursorX, iCursorY);
			break;
		}
		case DOWN:
		{
			iCursorY++;
			if (iCursorY > 19)//하단 끝까지 갔을경우 하단으로 더이상 못가게 함
			{
				iCursorY--;
			}
			GotoXY(iCursorX, iCursorY);
			break;
		}
		case ENTER:
		{
			if (OmokBoard[iCursorX / 2][iCursorY - 1] != 0)//배열의 값에 값이 들어있는경우 취소
				break;
			if (!bPayer)
			{
				OmokBoard[iCursorX / 2][iCursorY - 1] = 2;
			}
			else
			{
				OmokBoard[iCursorX / 2][iCursorY - 1] = 1;
			}
			iPlayTurn = 0;
		}
		}
		GotoXY(2, 21);
		printf("1p=○      2p=● \n현재좌표OmokBoard(%d %d)", iCursorX / 2, iCursorY - 1);
		GotoXY(iCursorX, iCursorY);
	}
}

void GotoXY(int x, int y)
{
	COORD Pos={x-1,y-1};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

bool Endboard(int OmokBoard[19][19]) 
{
	
	for (int i = 0;i < 19;i++)
	{
		for (int j = 0;j < 19;j++)
		{

			int LCnt_p = 0;
			int RCnt_p = 0;
			int UCnt_p = 0;
			int DCnt_p = 0;
			int URCnt_p = 0;
			int DRCnt_p = 0;
			int DLCnt_p = 0;
			int ULCnt_p = 0;

	
			//Player의 오목달성확인
			for (int Player = 1;Player < 3;Player++)
			{
				
				int k = 1;
				for (k = 1;k < 5;k++) {
					if (OmokBoard[j][i] == OmokBoard[j - k][i] && OmokBoard[j][i] == Player) {// 좌측 확인
						LCnt_p++;
					}
				}
				for (k = 1;k < 5;k++) {
					if (OmokBoard[j][i] == OmokBoard[j + k][i] && OmokBoard[j][i] == Player) {// 우측 확인
						RCnt_p++;
					}
				}
				for (k = 1;k < 5;k++) {
					if (OmokBoard[j][i] == OmokBoard[j][i + k] && OmokBoard[j][i] == Player) {// 하단 확인
						DCnt_p++;
					}
				}
				for (k = 1;k < 5;k++) {
					if (OmokBoard[j][i] == OmokBoard[j][i - k] && OmokBoard[j][i] == Player) {// 상단 확인
						UCnt_p++;
					}
				}
				for (k = 1;k < 5;k++) {
					if (OmokBoard[j][i] == OmokBoard[j + k][i + k] && OmokBoard[j][i] == Player) {// 우측하단방향 확인
						DRCnt_p++;
					}
				}
				for (k = 1;k < 5;k++) {
					if (OmokBoard[j][i] == OmokBoard[j + k][i - k] && OmokBoard[j][i] == Player) {// 우측상단방향 확인
						URCnt_p++;
					}
				}
				for (k = 1;k < 5;k++) {
					if (OmokBoard[j][i] == OmokBoard[j - k][i - k] && OmokBoard[j][i] == Player) {// 좌측상단방향 확인
						ULCnt_p++;
					}
				}
				for (k = 1;k < 5;k++) {if (OmokBoard[j][i] == OmokBoard[j - k][i + k] && OmokBoard[j][i] == Player) {// 좌측하단방향 확인
						DLCnt_p++;
					}
				}
				
			}
			if (LCnt_p == 4 || RCnt_p == 4
				|| UCnt_p == 4 || DCnt_p == 4
				|| URCnt_p == 4 || DRCnt_p == 4
				|| DLCnt_p == 4 || ULCnt_p == 4)
			{
				return true;
			}
			LCnt_p = 0;
			RCnt_p = 0;
			UCnt_p = 0;
			DCnt_p = 0;
			URCnt_p = 0;
			DRCnt_p = 0;
			DLCnt_p = 0;
			ULCnt_p = 0;
		}
	}
	return false;
}

void Drawboard()
{
	system("cls");
	int i, j;

	for (i = 0;i<19;i++)
	{
		for (j = 0;j<19;j++)
		{
			if (i == 0)//제일 상단
			{
				if (j == 0)//좌측끝 모서리 생성
				{
					if (OmokBoard[j][i] == 1) 			printf("○");
					else if (OmokBoard[j][i] == 2)		printf("●");
					else if (OmokBoard[j][i] == 0)		printf("┌");
				}
				else if (j == 18)//우측끝 모서리 생성
				{
					if (OmokBoard[j][i] == 1)			printf("○");
					else if (OmokBoard[j][i] == 2)		printf("●");
					else if (OmokBoard[j][i] == 0)		printf("┐");
				}
				else//나머지 자리에 생성
				{
					if (OmokBoard[j][i] == 1)			printf("○");
					else if (OmokBoard[j][i] == 2)		printf("●");
					else if (OmokBoard[j][i] == 0)		printf("┬");
				}
			}
			else if (i == 18)//제일 하단
			{
				if (j == 0)//좌측끝 모서리 생성
				{
					if (OmokBoard[j][i] == 1)			printf("○");
					else if (OmokBoard[j][i] == 2)		printf("●");
					else if (OmokBoard[j][i] == 0)		printf("└");
				}
				else if (j == 18)//우측끝 모서리 생성
				{
					if (OmokBoard[j][i] == 1)			printf("○");
					else if (OmokBoard[j][i] == 2)		printf("●");
					else if (OmokBoard[j][i] == 0)		printf("┘");
				}
				else//나머지 자리에 생성
				{
					if (OmokBoard[j][i] == 1)			printf("○");
					else if (OmokBoard[j][i] == 2)		printf("●");
					else if (OmokBoard[j][i] == 0)		printf("┴");
				}
			}
			else//그외 자리
			{
				if (j == 0)//좌측 모서리에 생성
				{
					if (OmokBoard[j][i] == 1)			printf("○");
					else if (OmokBoard[j][i] == 2)		printf("●");
					else if (OmokBoard[j][i] == 0)		printf("├");
				}
				else if (j == 18)//우측 모서리에 생성
				{
					if (OmokBoard[j][i] == 1)			printf("○");
					else if (OmokBoard[j][i] == 2)		printf("●");
					else if (OmokBoard[j][i] == 0)		printf("┤");
				}
				else//나머지 자리에 생성
				{
					if (OmokBoard[j][i] == 1)			printf("○");
					else if (OmokBoard[j][i] == 2)		printf("●");
					else if (OmokBoard[j][i] == 0)		printf("┼");
				}
			}
		}
		printf("\n");
	}
	GotoXY(2, 20);
	printf("방향키와 엔터키를 이용하여 돌을 놓습니다.");
	GotoXY(2, 21);
	printf("1p=○      2p=● \n현재좌표OmokBoard(%d %d)", iCursorX / 2, iCursorY - 1);
	GotoXY(iCursorX, iCursorY);
}

int Judgment()
{
	return 1;
}

void main()
{
	bool bPlayer = true;
	int iGameLoop = 1;
	int Player = 0;
	for (int iRowBoard = 0;iRowBoard < 19;iRowBoard++)
	{
		for (int iColBoard = 0;iColBoard < 19;iColBoard++)
		{
			OmokBoard[iRowBoard][iColBoard] = 0;
		}
	}

	Drawboard();

	while (iGameLoop)
	{
		KeyCheck(bPlayer);
		Drawboard();
		if (Endboard(OmokBoard) == true) {
			break;
		}
		iGameLoop = Judgment();
	
		bPlayer = !bPlayer;
	}

	if (bPlayer == false) 
	{
		Player = 2;
	}
	else
	{
		Player = 1;
	}
	printf("%dP 가 이겼습니다.", Player);


	getchar();
}