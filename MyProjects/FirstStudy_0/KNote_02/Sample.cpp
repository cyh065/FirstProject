#include "KManager.h"

void main()
{
	KManager mgr;
	mgr.InputData(10);
	mgr.ShowData(mgr.Find(3));
	mgr.Sort();
	mgr.ShowData();
	mgr.Release();
}