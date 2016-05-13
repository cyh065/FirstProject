#pragma once
#include "KNode.h"
#include <string>
using namespace std;

struct Item
{
	string	key;
	Item*	next;
};

class KLinkedlist2
{
private:
	Item *			head;
	int				length;
public:
	void			insertItem(Item* newItem);
	bool			removeItem(string itemKey);
	Item *			getItem(string itemKey);
	void			printList();
	int				getLength();

public:
	KLinkedlist2();
	virtual ~KLinkedlist2();
};

