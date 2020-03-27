#pragma once
#include "SortType.h"

class InsertSort : public SortType
{
public:
	InsertSort(int* t);
	~InsertSort();

	void Sort();
	
};

