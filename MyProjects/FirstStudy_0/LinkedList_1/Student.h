#pragma once
#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Result.h"

int g_iNum;
class Student
{
public:
	char		m_cName[9];
	Student*	m_pNext;

public:
	void		WriteData(int iNum, int const ResultSet());
	void		ReadData();
public:
	Student();
	~Student();
};

