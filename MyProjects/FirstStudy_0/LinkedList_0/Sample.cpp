#include "LinkedList_0.h"

void main()
{
	Node Node;
	Node.WriteFile();
	Node.ReadFile();

	while (1)
	{
		int iCount = 0;
		cout << "\nSelect( ���:0, �߰�:1, ����:2,  ����:3, ����:999 ) : " << endl;
		scanf("%d", &iCount);

		if (iCount == 999)break;
		switch (iCount)
		{
		case 0:
		{
			Node.WriteLink();
		}break;
		case 1:
		{
			Node.PlusData();
			Node.WriteLink();
		}break;
		case 2:
		{
			Node.UpData(iCount);
			Node.WriteLink();
		}break;
		case 3:
		{
			Node.UpData(iCount);
			Node.WriteLink();
		}break;
		}
	}
	Node.FreeLink();
}