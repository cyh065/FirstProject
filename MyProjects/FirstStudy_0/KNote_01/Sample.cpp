#include "KManager.h"

void main()
{
	bool bUp = true;
	int iCnt = 10;
	KManager mgr;
	
	mgr.InputData(iCnt);
	mgr.ReadFile(iCnt);
	mgr.ShowData(mgr.Find(3));
	mgr.Sort(bUp);
	int iSort = 0;
	while (1) {
		int iCount = 0;
		cout << "\nSelect( ���:0, �߰�:1, ����:2,  ����:3, ����:999 ) " << endl;
		scanf("%d", &iCount);
		cout << "\nSelect( ���Ĺ�� : �������� -> 0, �ø����� -> 1 " << endl;
		cin >> iSort;
		if (iSort == 0)bUp = true;
		else {
			bUp = false;
		}
		if (iCount == 999)break;
		switch (iCount)
		{
		case 0:
		{
			mgr.Sort(bUp);
			mgr.ShowData();
		}break;
		case 1:
		{
			mgr.PlusData();
			mgr.Sort(bUp);
			mgr.ShowData();
		}break;
		case 2:
		{
			mgr.UpData(iCount);
			mgr.ShowData();
		}break;
		case 3:
		{
			mgr.UpData(iCount);
			mgr.ShowData();
		}break;
		}
	}
	mgr.Release();
}