#pragma once
#include<iostream>
using namespace std;

class Grand
{
public:
	int		m_iMoney = 100000000;
public:
	virtual void GetMoney()=0;
public:
	Grand();
	~Grand();
};

