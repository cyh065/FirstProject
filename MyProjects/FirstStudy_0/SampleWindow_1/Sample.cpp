#include "Sample.h"


int WINAPI wWinMain(
	HINSTANCE	hInstance,
	HINSTANCE	hPrevInstance,
	LPWSTR		lpCmdLine,
	int			nCmdShow)
{
	Sample Kwin;
	if (Kwin.SetWindow(hInstance) == true)
	{
		Kwin.Run();
	}
	return 0;
}


Sample::Sample()
{
}


Sample::~Sample()
{
}
