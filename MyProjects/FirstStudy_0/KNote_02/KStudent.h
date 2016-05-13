#pragma once
#include "KSubject.h"
class KStudent
{
public:
	int			m_iIndex;
	TCHAR		m_szName[5];
	int			m_iTotal;
	float		m_fAverage;
	KSubject	m_Ssubject;
public:
	KStudent();
	virtual ~KStudent();
};

