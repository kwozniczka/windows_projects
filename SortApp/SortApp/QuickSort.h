#pragma once
#include "SortType.h"

class QuickSort : public SortType
{
public:

	QuickSort(int* t);
	~QuickSort();
	void Sort();
	void quick(int * tab, int l, int p);

public:
	int l;
	int p;

};

