// ConsoleApplication1.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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

