#pragma once
#include "kParent.h"
class kChild : public kParent
{
public:
	int		GetMoney()
	{
		return m_iMoney;
	}
	//������ �ߴ�.
	void	SetMoney(int iValue)
	{
		m_iMoney += iValue;
	}
public:
	kChild();
	~kChild();
};

