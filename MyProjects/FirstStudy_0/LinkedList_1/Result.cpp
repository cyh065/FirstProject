#include "Result.h"


int Result::ResultSet()  const
{
	srand((unsigned)time(NULL));
	int iNum = rand() %100;
	return iNum;
}
Result::Result()
{
}


Result::~Result()
{
}
