#pragma once
#include <iostream>
#include <cstdlib>
#include <time.h>
class Student;
class Result
{
public:
	int		m_iKor;
	int		m_iEng;
	int		m_iMat;
	int		m_iTotal;
	float	m_fAverage;

public:
	int		ResultSet() const;
public:
	Result();
	~Result();
};

