// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �Ǵ� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <cstdio>
#include <cstdlib>
#include <conio.h>

#define	RIGHT	77
#define LEFT	75
#define UP		72
#define DOWN	80
#define ENTER	13

void	KeyCheck(bool bPlayer);
void	GotoXY(int x, int y);
void	Drawboard();
int		Judgment();

int OmokBoard[19][19];
int iCursorX = 19;
int iCursorY = 9;


// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.
