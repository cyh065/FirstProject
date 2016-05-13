#include "kParent.h"



kParent::kParent()
{
	this->m_iMoney = 0;
	std::cout << "kParent()" << std::endl;
}

kParent::kParent(int iMoney) : m_iMoney ( iMoney )
{
	//this->m_iMoney = iMoney;
	std::cout << "kParent()" << std::endl;
}

kParent::~kParent()
{
	std::cout << "~kParent()" << std::endl;
}
