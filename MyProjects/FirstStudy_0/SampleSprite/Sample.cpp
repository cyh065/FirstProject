#include "Sample.h"
#include "KSys.h"
#include "KSpriteMgr.h"
#include <iostream>

bool		Sample::Init()
{
	LoadSprite(L"Sprite.txt");

	int iIndex = I_Sprite.Load(L"TypeA", 
		L"../../data/bitmap1.bmp", 
		L"../../data/bitmap2.bmp");
	KSprite* pSprite = I_Sprite.Find(iIndex);
	pSprite->SetRectArray(m_SpriteList[0], 2.0f);

	iIndex = I_Sprite.Load(L"TypeB",
		L"../../data/bitmap1.bmp",
		L"../../data/bitmap2.bmp");
	pSprite = I_Sprite.Find(iIndex);
	pSprite->SetRectArray(m_SpriteList[1], 1.0f);

	iIndex = I_Sprite.Load(L"TypeC",
		L"../../data/bitmap1.bmp",
		L"../../data/bitmap2.bmp");
	pSprite = I_Sprite.Find(iIndex);
	pSprite->SetRectArray(m_SpriteList[2], 1.0f);

	m_Hero.Load(L"../../data/bitmap.bmp",
				L"../../data/bitmap.bmp");
	m_Effect.SetSprite(0);
	return true;
}

void		Sample::SetSprite(int iIndex, float fLifeTime)
{
	m_iSpriteID = iIndex;

}

bool		Sample::Frame()
{
	return true;
}

bool		Sample::Render()
{
	for (int iEffect = 0; iEffect < m_EffectList.size(); iEffect++)
	{
		m_EffectList[iEffect]->Frame();
		m_EffectList[iEffect]->Render();
	}
	return true;
}

bool		Sample::LoadSprite(TCHAR* pFileName)
{
	TCHAR pBuffer[256] = { 0, };
	TCHAR pTemp[256] = { 0, };

	FILE* fp;
	_wfopen_s(&fp, pFileName, _T("rt"));
	if (fp = NULL)return false;

	int iNumSprite = 0;
	_fgetts(pBuffer, _countof(pBuffer), fp);
	_stscanf_s(pBuffer, _T("%s%d"),
		pTemp, _countof(pTemp), &iNumSprite);

	m_SpriteList.resize(iNumSprite);

	int iNumFrame = 0;
	for (int iSprite = 0; iSprite < iNumSprite; iSprite++)
	{
		_fgetts(pBuffer, _countof(pBuffer), fp);
		_stscanf_s(pBuffer, _T("%s%d"),
			pTemp, _countof(pTemp), &iNumFrame);

		int iNumber;
		m_SpriteList[iSprite].resize(iNumFrame);
		
		for (int iFrame = 0;iFrame < iNumFrame; iFrame++)
		{
			RECT rt;
			_fgetts(pBuffer, _countof(pBuffer), fp);
			_stscanf_s(pBuffer, _T("%d%d%d%d%d"),
				&iNumber, &rt.left, &rt.top, &rt.right, &rt.bottom);
			m_SpriteList[iSprite][iFrame] = rt;

		}
	}
	fclose(fp);
	return true;
}
Sample::Sample()
{
}


Sample::~Sample()
{
}

int WINAPI wWinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPWSTR		lpCmpLine,
	int			nCmdShow)
{
	Sample Kwin;
	if (Kwin.SetWindow(hInstance) == true)
	{
		Kwin.Run();
	}
	return 0;
}