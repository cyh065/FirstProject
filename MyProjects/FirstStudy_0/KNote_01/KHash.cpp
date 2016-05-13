#include "KHash.h"


int KHashTable::hash(string itemKey)
{
	int value = 0;
	int itemLength = itemKey.length();
	for (int i = 0;i < itemLength; i++)
	{
		value += itemKey[i];
	}
		return(itemLength * value) % Length;
}


void KHashTable::insertItem(Item* newItem)
{
	int index = hash(newItem->key);
	array[index].insertItem(newItem);
}

bool KHashTable::removeItem(string itemKey)
{
	int index = hash(itemKey);
	return array[index].removeItem(itemKey);
}

Item * KHashTable::getItemByKey(string itemKey)
{
	int index = hash(itemKey);
	return array[index].getItem(itemKey);
}

void KHashTable::printTable()
{
	cout << "\nHash Table: \n";
	for (int i = 0;i < Length; i++)
	{
		cout << "Bukket " << i + 1 << ": ";
		array[i].printList();
	}
}

void KHashTable::printHistogram()
{
	cout << "\n\nHash Table Contains";
	cout << getNumberOfItems() << " Items total\n";
	for (int i = 0; i < Length; i++)
	{
		cout << i + 1 << ":\t";
		for (int j = 0; j < array[i].getLength(); j++) cout << "X";
		cout << "\n";
	}
}

int KHashTable::getLength()
{
	return Length;
}

int KHashTable::getNumberOfItems()
{
	int itemCount = 0;
	for (int i = 0; i < Length; i++)
	{
		itemCount += array[i].getLength();
	}
	return itemCount;
}


KHashTable::KHashTable(int MAX_TABLE_LENGTH)
{
	if (MAX_TABLE_LENGTH <= 0) MAX_TABLE_LENGTH = 15;
	array = new KLinkedlist2[MAX_TABLE_LENGTH];
	Length = MAX_TABLE_LENGTH;

}


KHashTable::~KHashTable()
{
	delete[] array;
}