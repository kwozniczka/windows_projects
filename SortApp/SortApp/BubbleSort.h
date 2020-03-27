#pragma once
#include "SortType.h"

class BubbleSort : public SortType
{
public:
	BubbleSort(int* t);
	~BubbleSort();
	void Sort();
};

