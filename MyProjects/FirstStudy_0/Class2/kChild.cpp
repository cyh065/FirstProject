#include "kChild.h"



kChild::kChild() : kParent(10000000)
{
	std::cout << "kChild()" << std::endl;
}


kChild::~kChild()
{
	std::cout << "~kChild()" << std::endl;
}
