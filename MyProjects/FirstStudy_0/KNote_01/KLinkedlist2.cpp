#include "KLinkedlist2.h"


void KLinkedlist2::insertItem(Item * newItem)
{
	if (!head->next)
	{
		head->next = newItem;
		length++;
		return;
	}
	Item * p = head;
	Item * q = head;
	while (q)
	{
		p = q;
		q = p->next;
	}
	p->next = newItem;
	newItem->next = NULL;
	length++;
}

bool KLinkedlist2::removeItem(string itemKey)
{
	if (!head->next)return false;
	Item * p = head;
	Item * q = head;
	while (q)
	{
		if (q->key == itemKey)
		{
			p->next = q->next;
			delete q;
			length--;
			return true;
		}
		p = q;
		q = p->next;
	}
	return false;
}

Item* KLinkedlist2::getItem(string itemKey)
{
	Item * p = head;
	Item * q = head;
	while (q)
	{
		p = q;
		if ((p != head) && (p->key == itemKey)) return p;
		q = p->next;
	}
	return NULL;
}

void KLinkedlist2::printList()
{
	if (length == 0)
	{
		cout << "\n{ }\n";
		return;
	}
	Item * p = head;
	Item * q = head;
	cout << "\n{ ";
	while (q)
	{
		p = q;
		if (p != head)
		{
			cout << p->key;
			if (p->next) cout << ", ";
			else cout << " ";
		}
		q = p->next;
	}
	cout << "}\n";
}

int KLinkedlist2::getLength()
{
	return length;
}

KLinkedlist2::KLinkedlist2()
{
	head = new Item;
	head->next = NULL;
	length = 0;
}


KLinkedlist2::~KLinkedlist2()
{
	Item * p = head;
	Item * q = head;
	while (q)
	{
		p = q;
		q = p->next;
		if (q) delete p;
	}
}
