#include "T_Region.h"

void main()
{
	int* a = new int;
	*a = 0;
	/*const int* b = a;
	*b = 10;
	int* c = new int;
	b = c;*/

	int x = 10;  
	int y = 10;
	int& const d = x;
	int& j = x;
	j = 100;
	j = y;
	cout << j;


	Point x1(0, 0);
	Point x2(100, 100);
	Point x3;

	const Point& x4 = x1;
	const Point* x5 = &x1;

	const Point& x6 = x1.GetRef();
	const Point* x7 = x1.Get();

	Point x3 = x1.GetRef();
	const Point& x4 = x1.GetRef();
	const Point* x3 = x1.Get();

	int iX = x6.GetX();
	//int iY = x6.GetY();//오류! 비 상수 함수 호출

	iX = x7->GetX();
	//iY = x7->GetY(); //오류! 비 상수 함수 호출
	iX = x3.GetX();
	int iY = x3.GetY();


	std::cout << x1.m_iX << std::endl;
	++x1;
	std::cout << x1.m_iX << std::endl;
	x1++;
	std::cout << x1.m_iX << std::endl;
	x3 = x1 + x2;
	std::cout << x3.m_iX << std::endl;
	x3 = x1 + 10;
	std::cout << x3.m_iX << std::endl;
	x3 = 10 + x1;
	std::cout << x3.m_iX << std::endl;
	x3 = x2;
	if (x3 == x2)
	{
		std::cout << "같다" << std::endl;
	}
	else {
		std::cout << "다르다" << std::endl;
	}
	Point x5(10, 10);
	std::cout << x5[0] << x5[1] << std::endl;
	std::cin  >> x5;
	std::cout << x5;

	const Point& p4 = x1;
	x3 = p4 + 10;
	/*x3 = x1 * 10;
	x3 = x1 + x2;
	x3 = x1 * x2;
	x3 = x1 / x2;
	x3 = x1 - x2;*/

	T_Region rectA, rectB, rectC, rectD;
	rectA.SetRect(10, 10, 100, 100);
	rectA.Show();

	Point a;
	a.Set(&rectA);
	a.m_pRegion->GetLeft();
	//rectA.ReSize(40, 40);
	//rectA.Show();

	rectB.SetRect(50, 50, 120, 120);
	rectB.Show();

	bool bFlag = rectA^rectB;

	rectC.IntersectRegion(rectA, rectB);
	rectC.Show();

	rectD.UnionRegion(rectA, rectB);
	rectD.Show();

	T_Region rectE, rectF;

	Point p1, p2;
	p1.SetPosition(10, 10);
	p2.SetPosition(100, 100);
	rectE.SetRect(p1, p2);
	rectE.Show();

	const Point& p6 = p1;
	rectF.SetRect(p6, p2);

	rectF.SetRect(&p1, &p2);
	rectF.Show();
}