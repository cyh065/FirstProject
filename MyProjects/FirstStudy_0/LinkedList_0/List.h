#pragma once
#include "Cstd.h"


class List
{	
public:
	int		m_iNum;
	virtual void GetString(char* name) {
		cout << "�˻��̸� : ";
		cin >> name;
	}
public:
	List();
	~List();
};

