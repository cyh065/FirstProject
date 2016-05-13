// Omok.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"



void KeyCheck(bool bPayer)
{
	int iPlayTurn = 1;
	while (iPlayTurn)
	{
		switch (getch())
		{
			case RIGHT:
			{
				iCursorX += 2;
				if (iCursorX > 38)
				{
					iCursorX -= 2;
				}
				GotoXY(iCursorX, iCursorY);
				break;
			}
			case LEFT:
			{
				iCursorX -= 2;
				if (iCursorX < 0)
				{
					iCursorX += 2;
				}
				GotoXY(iCursorX, iCursorY);
				break;
			}
			case UP:
			{
				iCursorY--;
				if (iCursorY <= 0)
				{
					iCursorY++;
				}
				GotoXY(iCursorX, iCursorY);
				break;
			}
			case DOWN:
			{
				iCursorY++;
				if (iCursorY > 19)
				{
					iCursorY--;
				}
				GotoXY(iCursorX, iCursorY);
				break;
			}
			case ENTER:
			{
				if (OmokBoard[iCursorX / 2][iCursorY - 1] != 0)
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
		printf("1p=��      2p=�� \n������ǥOmokBoard(%d %d)", iCursorX / 2, iCursorY - 1);
		GotoXY(iCursorX, iCursorY);
	}
}

void GotoXY(int x, int y)
{
	COORD Pos ={ x-1, y-1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void Drawboard()
{
	system("cls");
	int i, j;

	for (i = 0;i<19;i++)
	{
		for (j = 0;j<19;j++)
		{
			if (i == 0)
			{
				if (j == 0)
				{
					if (OmokBoard[j][i] == 1) 			printf("��");
					else if (OmokBoard[j][i] == 2)		printf("��");
					else if (OmokBoard[j][i] == 0)		printf("��");
				}
				else if (j == 18)
				{
					if (OmokBoard[j][i] == 1)			printf("��");
					else if (OmokBoard[j][i] == 2)		printf("��");
					else if (OmokBoard[j][i] == 0)		printf("��");
				}
				else
				{
					if (OmokBoard[j][i] == 1)			printf("��");
					else if (OmokBoard[j][i] == 2)		printf("��");
					else if (OmokBoard[j][i] == 0)		printf("��");
				}
			}
			else if (i == 18)
			{
				if (j == 0)
				{
					if (OmokBoard[j][i] == 1)			printf("��");
					else if (OmokBoard[j][i] == 2)		printf("��");
					else if (OmokBoard[j][i] == 0)		printf("��");
				}
				else if (j == 18)
				{
					if (OmokBoard[j][i] == 1)			printf("��");
					else if (OmokBoard[j][i] == 2)		printf("��");
					else if (OmokBoard[j][i] == 0)		printf("��");
				}
				else
				{
					if (OmokBoard[j][i] == 1)			printf("��");
					else if (OmokBoard[j][i] == 2)		printf("��");
					else if (OmokBoard[j][i] == 0)		printf("��");
				}
			}
			else
			{
				if (j == 0)
				{
					if (OmokBoard[j][i] == 1)			printf("��");
					else if (OmokBoard[j][i] == 2)		printf("��");
					else if (OmokBoard[j][i] == 0)		printf("��");
				}
				else if (j == 18)
				{
					if (OmokBoard[j][i] == 1)			printf("��");
					else if (OmokBoard[j][i] == 2)		printf("��");
					else if (OmokBoard[j][i] == 0)		printf("��");
				}
				else
				{
					if (OmokBoard[j][i] == 1)			printf("��");
					else if (OmokBoard[j][i] == 2)		printf("��");
					else if (OmokBoard[j][i] == 0)		printf("��");
				}
			}
		}
		printf("\n");
	}
	GotoXY(2, 20);
	printf("����Ű�� ����Ű�� �̿��Ͽ� ���� �����ϴ�.");
	GotoXY(2, 21);  //������� ���� ����
	printf("1p=��      2p=�� \n������ǥOmokBoard(%d %d)", iCursorX / 2, iCursorY - 1);
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
		iGameLoop = Judgment();
		bPlayer = !bPlayer;
	}
}

