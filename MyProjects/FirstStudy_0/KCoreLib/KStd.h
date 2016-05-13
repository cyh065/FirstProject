#pragma once
#include <windows.h>
#include <tchar.h>
#include <vector>
#include <list>
#include <map>
#include <string>
using namespace std;

struct KRect
{
	int			x, y;
	int			w, h;
};

template <class K> class KSingleton
{
public:
	static K& GetInstance()
	{
		static K theSingleton;
		return theSingleton;
	}
};