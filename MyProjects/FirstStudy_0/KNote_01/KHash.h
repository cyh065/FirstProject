#pragma once
#include "KLinkedlist2.h"


class KHashTable
{
private:
	KLinkedlist2*	array;
	int				Length;
	int				hash(string itemKey);
public:
	void insertItem(Item* newItem);
	bool removeItem(string itemKey);
	Item * getItemByKey(string itemKey);
	void printTable();
	void printHistogram();
	int getLength();
	int getNumberOfItems();
public:
	KHashTable(int MAX_TABLE_LENGTH = 15);
	virtual ~KHashTable();
};




