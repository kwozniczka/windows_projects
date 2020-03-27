#pragma once
#include "SortType.h"

class HalfSort : public SortType
{
public:
	HalfSort(int* t);
	~HalfSort();

	void Sort();
};

