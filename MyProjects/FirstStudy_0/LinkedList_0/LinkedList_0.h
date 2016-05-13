#pragma once
#include "List.h"


class Node : public List 
{
public:
	char	m_cName[9];
	int		m_iKor;
	int		m_iEng;
	int		m_iMat;
	int		m_iTot;
	float   m_fAvr;
	Node*	m_pNext;
public :
	void	Clear();
	void	WriteFile();
	void	ReadFile();
	void	PlusData();
	void	UpData(int iCount);
	
	void	AddLink(Node* pNode);
	void	WriteLink();
	Node*	SearchLink(const char* cName);
	void	DeleteLink(Node* pNode);
	void	FreeLink();

	friend	ostream& operator <<(ostream& os,const Node& p);
	friend	istream& operator >>(istream& is, const Node& p);
	
	void 	InputData(Node* p);
public:
	Node();

	~Node();
};




