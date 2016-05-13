#include "kSon.h"

void main()
{
	kManager mgr;
	kParent*a = new Ka;
	a->SetMoney(100);
	kParent*b = new Kb;
	a->SetMoney(200);
	kParent*c = new Kc;
	a->SetMoney(300);
	mgr.Add(a,0);
	mgr.Add(b,1);
	mgr.Add(c,2);
	mgr.show();
	delete a;
	delete b;
	delete c;
	/*kParent* a = new Ka;
	kParent* b = new Kb;
	kParent* c = new Kc;

	a->SetMoney(10000);
	b->SetMoney(10000);
	c->SetMoney(10000);*/

	//kSon* son = new kSon;
	////son->m_iMoney = 1000;
	//son->SetMoney(1000);
	//std::cout << son->GetMoney() << std::endl;

	//kParent* parent = new kParent;
	kParent* parent = new kChild;
	//parent->m_iMoney = 1000;
	//std::cout << parent->m_iMoney << std::endl;
	
	parent->SetMoney(1000);
	std::cout << parent->GetMoney() << std::endl;;
	//std::cout << ((kParent*)child)->m_iMoney;


	//delete parent;
	//delete parent;

	std::cout << "ÀüÃ¼ ¼Ò¸ê";
}