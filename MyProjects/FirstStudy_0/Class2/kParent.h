#pragma once
#include <iostream>
class kParent
{
protected:
	kParent*	data[3];
	int		m_iMoney;
public:
	int		GetMoney() {
		return m_iMoney;
	}
	//가상 함수
	virtual void		SetMoney(int iMoney) {
		m_iMoney = iMoney;
	}
public:
	kParent();
	kParent(int iMoney);
	virtual ~kParent();
};

class Ka : public kParent
{
public:
	void		SetMoney(int iMoney) {
		m_iMoney = iMoney * 2;
	}
	int			GetMoney() {
		return m_iMoney;
	}
	~Ka()
	{
		std::cout << "~Ka" << std::endl;
	}
};
class Kb : public kParent
{
public:
	void		SetMoney(int iMoney) {
		m_iMoney = iMoney;
	}
	int			GetMoney() {
		return m_iMoney;
	}
	~Kb()
	{
		std::cout << "~Kb" << std::endl;
	}
};
class Kc : public kParent
{
public:
	void		SetMoney(int iMoney) {
		m_iMoney = iMoney;
	}
	int			GetMoney() {
		return m_iMoney;
	}
	~Kc()
	{
		std::cout << "~Kc" << std::endl;
	}
};

class kManager
{
public:
	kParent* m_pData[3];
	void Add(kParent* pData, int iIndex)
	{
		m_pData[iIndex] = pData;
	}
	void show()
	{
		for (int i = 0;i < 3;i++)
		{
			std::cout << m_pData[i]->GetMoney();
		}
	}
};
