#include "KInput.h"
#include "KSys.h"

void		KInput::MsgEvent(MSG msg)
{
	switch (msg.message)
	{
	case WM_LBUTTONDOWN:
	{
		GetCursorPos(&m_MovePt);
		//ClientToScreen(g_hWnd, &m_MovePt);
		ScreenToClient(g_hWnd, &m_MovePt);
		m_dwMouseState[0] = TRUE;
	}break;
	case WM_LBUTTONUP:
	{
		m_dwMouseState[0] = FALSE;
	}break;
	case WM_RBUTTONDOWN:
	{
		m_dwMouseState[1] = TRUE;
	}break;
	case WM_RBUTTONUP:
	{
		m_dwMouseState[1] = FALSE;
	}break;
	case WM_MBUTTONDOWN:
	{
		m_dwMouseState[2] = TRUE;
	}break;
	case WM_MBUTTONUP:
	{
		m_dwMouseState[2] = FALSE;
	}break;
	}
};
bool		KInput::Init() // �ʱ�ȭ
{
	ZeroMemory(m_dwKeyState, sizeof(DWORD) * 256);
	ZeroMemory(m_dwMouseState, sizeof(DWORD) * 3);
	return true;
}
DWORD		KInput::KeyCheck(DWORD dwKey)
{
	SHORT sKey = GetAsyncKeyState(dwKey);
	// 0x8000 = 1000 0000 0000 0000
	if (sKey & 0x8000)
	{
		if (m_dwKeyState[dwKey] == KEY_FREE)
			m_dwKeyState[dwKey] = KEY_PUSH;
		else
			m_dwKeyState[dwKey] = KEY_HOLD;
	}
	else
	{
		if (m_dwKeyState[dwKey] == KEY_PUSH ||
			m_dwKeyState[dwKey] == KEY_HOLD)
			m_dwKeyState[dwKey] = KEY_UP;
		else
			m_dwKeyState[dwKey] = KEY_FREE;
	}
	return m_dwKeyState[dwKey];
}
bool		KInput::Frame()
{
	GetCursorPos(&m_MovePt);
	ScreenToClient(g_hWnd, &m_MovePt);
	return true;
}
bool		KInput::Render()
{
#ifdef _DEBUG
	_stprintf_s(m_csBuffer,
		L"x =[%d], y =[%d]\n",
		m_MovePt.x, m_MovePt.y);
	//OutputDebugString(m_csBuffer);
#endif
	return true;
}
bool		KInput::Release()
{
	return true;
}

KInput::KInput()
{
}


KInput::~KInput()
{
}
