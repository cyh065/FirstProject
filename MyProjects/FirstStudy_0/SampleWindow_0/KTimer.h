#pragma once
#include "KBase.h"
class KTimer : public KBase
{
public:
	bool		Init();		//	�ʱ�ȭ
	bool		Frame();	//	���
	bool		Render();	//	��ο�
	bool		Release();	//	����,�Ҹ�
public:
	KTimer();
	virtual ~KTimer();
};

