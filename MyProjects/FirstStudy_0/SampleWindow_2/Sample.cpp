#include "Sample.h"
//Intermediate Directory does not end with a trailing slash. 
//This build instance will add the slash as it is required to
//allow proper evaluation of the Intermediate Directory.
// 출력 디렉터리 마지막부분에 \ 를 안 붙혔을경우 경로를 찾을 수 없다.
void		Sample::MsgEvent(MSG msg)
{
	m_Input.MsgEvent(msg);
}
bool		Sample::Init()
{
	m_Timer.Init();
	m_Input.Init();
	return true;
}
bool		Sample::Frame()
{
	m_Timer.Frame();
	m_Input.Frame();

	if (m_Input.KeyCheck('W') == KEY_PUSH)
	{
		MessageBox(m_hWnd, L"W KEY_UP", L"KeyState", MB_OK);
	}
	if (m_Input.KeyCheck('S') == KEY_PUSH)
	{
		MessageBox(m_hWnd, L"S click", L"KeyState", MB_OK);
	}
	if (m_Input.KeyCheck('A') == KEY_PUSH)
	{
		MessageBox(m_hWnd, L"A click", L"KeyState", MB_OK);
	}
	if (m_Input.KeyCheck('D') == KEY_PUSH)
	{
		MessageBox(m_hWnd, L"D click", L"KeyState", MB_OK);
	}
	return true;
}
bool		Sample::Render()
{
	m_Timer.Render();
	m_Input.Render();
	HDC hdc = GetDC(this->m_hWnd);
	//SetBkMode(hdc, TRANSPARENT);
	TextOut(hdc, 0, 0, m_Timer.m_csBuffer, _tcslen(m_Timer.m_csBuffer));
	TextOut(hdc, 0, 25, m_Input.m_csBuffer, _tcslen(m_Input.m_csBuffer));
	ReleaseDC(m_hWnd, hdc);
	return true;
}
bool		Sample::Release()
{
	m_Timer.Release();
	m_Input.Render();
	return true;
}

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