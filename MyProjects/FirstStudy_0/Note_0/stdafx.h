// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
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


// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.
