#pragma once
#include <windows.h>
#define K_START int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow) {
#define K_END }
class KEngine
{
public:
	KEngine();
	virtual ~KEngine();
};

KEngine::KEngine()
{
}


KEngine::~KEngine()
{
}

