// ConsoleApplication1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

class CParent {

};
class CChild : public CParent
{

};

int main()
{
	int* a = 0;
	int** b = &a;

	CChild* child = new CChild;
	CParent* par1 = child;
	CParent** par = &par1;
    return 0;
}

