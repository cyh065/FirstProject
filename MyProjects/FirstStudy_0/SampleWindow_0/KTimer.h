#pragma once
#include "KBase.h"
class KTimer : public KBase
{
public:
	bool		Init();		//	초기화
	bool		Frame();	//	계산
	bool		Render();	//	드로우
	bool		Release();	//	삭제,소멸
public:
	KTimer();
	virtual ~KTimer();
};

