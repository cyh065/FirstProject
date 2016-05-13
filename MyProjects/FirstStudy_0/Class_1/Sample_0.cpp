#include "T_Region.h"

void main()
{
	T_Region rectA, rectB ,rectC,rectD;
	rectA.SetRect(10, 10, 100, 100);
	rectA.Show();
	//rectA.ReSize(40, 40);
	//rectA.Show();

	rectB.SetRect(50, 50, 120, 120);
	rectB.Show();

	rectC.IntersectRegion(rectA, rectB);
	rectC.Show();

	rectD.UnionRegion(rectA, rectB);
	rectD.Show();
}