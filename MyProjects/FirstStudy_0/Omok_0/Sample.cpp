#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <windows.h>
#include <cstdio>
#include <cstdlib>
#include <conio.h>
//Ű������ ASCII�ڵ尪 
#define	RIGHT	77
#define LEFT	75
#define UP		72
#define DOWN	80
#define ENTER	13

void	KeyCheck(bool bPlayer);
void	GotoXY(int x, int y);
void	Drawboard();
int		Judgment();

int OmokBoard[19][19];//�������� �迭
//���߾��� ��ǥ
int iCursorX = 19;
int iCursorY = 9;



void KeyCheck(bool bPayer)//Ű������ �����о��
{
	int iPlayTurn = 1;
	while (iPlayTurn)
	{
		switch (getch())
		{
		case RIGHT:
		{
			iCursorX += 2;
			if (iCursorX > 38)//���� ������ ������� �������� ���̻� ������ ��
			{
				iCursorX -= 2;
			}
			GotoXY(iCursorX, iCursorY);
			break;
		}
		case LEFT:
		{
			iCursorX -= 2;
			if (iCursorX < 0)//���� ������ ������� �������� ���̻� ������ ��
			{
				iCursorX += 2;
			}
			GotoXY(iCursorX, iCursorY);
			break;
		}
		case UP:
		{
			iCursorY--;
			if (iCursorY <= 0)//��� ������ ������� ������� ���̻� ������ ��
			{
				iCursorY++;
			}
			GotoXY(iCursorX, iCursorY);
			break;
		}
		case DOWN:
		{
			iCursorY++;
			if (iCursorY > 19)//�ϴ� ������ ������� �ϴ����� ���̻� ������ ��
			{
				iCursorY--;
			}
			GotoXY(iCursorX, iCursorY);
			break;
		}
		case ENTER:
		{
			if (OmokBoard[iCursorX / 2][iCursorY - 1] != 0)//�迭�� ���� ���� ����ִ°�� ���
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

	
			//Player�� ����޼�Ȯ��
			for (int Player = 1;Player < 3;Player++)
			{
				
				int k = 1;
				for (k = 1;k < 5;k++) {
					if (OmokBoard[j][i] == OmokBoard[j - k][i] && OmokBoard[j][i] == Player) {// ���� Ȯ��
						LCnt_p++;
					}
				}
				for (k = 1;k < 5;k++) {
					if (OmokBoard[j][i] == OmokBoard[j + k][i] && OmokBoard[j][i] == Player) {// ���� Ȯ��
						RCnt_p++;
					}
				}
				for (k = 1;k < 5;k++) {
					if (OmokBoard[j][i] == OmokBoard[j][i + k] && OmokBoard[j][i] == Player) {// �ϴ� Ȯ��
						DCnt_p++;
					}
				}
				for (k = 1;k < 5;k++) {
					if (OmokBoard[j][i] == OmokBoard[j][i - k] && OmokBoard[j][i] == Player) {// ��� Ȯ��
						UCnt_p++;
					}
				}
				for (k = 1;k < 5;k++) {
					if (OmokBoard[j][i] == OmokBoard[j + k][i + k] && OmokBoard[j][i] == Player) {// �����ϴܹ��� Ȯ��
						DRCnt_p++;
					}
				}
				for (k = 1;k < 5;k++) {
					if (OmokBoard[j][i] == OmokBoard[j + k][i - k] && OmokBoard[j][i] == Player) {// ������ܹ��� Ȯ��
						URCnt_p++;
					}
				}
				for (k = 1;k < 5;k++) {
					if (OmokBoard[j][i] == OmokBoard[j - k][i - k] && OmokBoard[j][i] == Player) {// ������ܹ��� Ȯ��
						ULCnt_p++;
					}
				}
				for (k = 1;k < 5;k++) {if (OmokBoard[j][i] == OmokBoard[j - k][i + k] && OmokBoard[j][i] == Player) {// �����ϴܹ��� Ȯ��
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
			if (i == 0)//���� ���
			{
				if (j == 0)//������ �𼭸� ����
				{
					if (OmokBoard[j][i] == 1) 			printf("��");
					else if (OmokBoard[j][i] == 2)		printf("��");
					else if (OmokBoard[j][i] == 0)		printf("��");
				}
				else if (j == 18)//������ �𼭸� ����
				{
					if (OmokBoard[j][i] == 1)			printf("��");
					else if (OmokBoard[j][i] == 2)		printf("��");
					else if (OmokBoard[j][i] == 0)		printf("��");
				}
				else//������ �ڸ��� ����
				{
					if (OmokBoard[j][i] == 1)			printf("��");
					else if (OmokBoard[j][i] == 2)		printf("��");
					else if (OmokBoard[j][i] == 0)		printf("��");
				}
			}
			else if (i == 18)//���� �ϴ�
			{
				if (j == 0)//������ �𼭸� ����
				{
					if (OmokBoard[j][i] == 1)			printf("��");
					else if (OmokBoard[j][i] == 2)		printf("��");
					else if (OmokBoard[j][i] == 0)		printf("��");
				}
				else if (j == 18)//������ �𼭸� ����
				{
					if (OmokBoard[j][i] == 1)			printf("��");
					else if (OmokBoard[j][i] == 2)		printf("��");
					else if (OmokBoard[j][i] == 0)		printf("��");
				}
				else//������ �ڸ��� ����
				{
					if (OmokBoard[j][i] == 1)			printf("��");
					else if (OmokBoard[j][i] == 2)		printf("��");
					else if (OmokBoard[j][i] == 0)		printf("��");
				}
			}
			else//�׿� �ڸ�
			{
				if (j == 0)//���� �𼭸��� ����
				{
					if (OmokBoard[j][i] == 1)			printf("��");
					else if (OmokBoard[j][i] == 2)		printf("��");
					else if (OmokBoard[j][i] == 0)		printf("��");
				}
				else if (j == 18)//���� �𼭸��� ����
				{
					if (OmokBoard[j][i] == 1)			printf("��");
					else if (OmokBoard[j][i] == 2)		printf("��");
					else if (OmokBoard[j][i] == 0)		printf("��");
				}
				else//������ �ڸ��� ����
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
	GotoXY(2, 21);
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
	printf("%dP �� �̰���ϴ�.", Player);


	getchar();
}