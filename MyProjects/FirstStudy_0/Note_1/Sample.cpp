#include "T_Note.h"

void PRINT_REF(Point& pData)
{
	cout << pData.GetX() << " " << pData.GetY() << " " << pData.GetString() << endl;
}
void PRINT_POINT(Point* pData)
{
	cout << pData->GetX() << " " << pData->GetY() << " " << pData->GetString() << endl;
}
void PRINT(Point pData)
{
//	pData.SetPosition(100, 100);
	cout << pData.GetX() << " " << pData.GetY() << " " << pData.GetString() << endl;
}



void main()
{
	{
		Point* p1 = 0;
		SAFE_NEW(p1, Point);
		cout << p1->GetX() << p1->GetY();
		p1->SetString("KGCA");
		p1->Show();
		SAFE_DEL(p1);
	}

	Point p2(20, 20);
	cout << p2.GetX() << p2.GetY();
	p2.SetString("KGCA");
	p2.Show();

	Point p3(30, 30, "GAME");
	cout << p3.GetX() << p3.GetY() << p3.GetString();
	p3.Show();

	Point p4 = p3;
	cout << p4.GetX() << p4.GetY() << p4.GetString();

	PRINT_REF(p4);
	PRINT_POINT(&p4);
	PRINT(p4);
	cout << "\n" << Point::g_iCount << "프로그램 종료";
	cout << "\n" << p4.GetCount() << "프로그램 종료";
}