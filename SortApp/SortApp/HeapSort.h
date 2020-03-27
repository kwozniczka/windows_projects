#pragma once
#include "SortType.h"

class HeapSort : public SortType
{
public:
	HeapSort(int* t);
	~HeapSort();
	void Sort();

private:
	void updateHeap(int* tab, int l, int p);

};

