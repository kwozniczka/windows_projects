#pragma once
#include "SortType.h"

class SelectSort : public SortType
{
public:
	SelectSort(int* t);
	~SelectSort();
	void Sort();
};

