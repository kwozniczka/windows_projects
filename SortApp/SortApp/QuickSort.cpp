#include "stdafx.h"
#include "QuickSort.h"


QuickSort::QuickSort(int * t) : SortType(t)
{
	type = 2;
	l = 0;
	p = size - 1; 
	name.LoadStringW(IDS_QUICK_SORT);
}


QuickSort::~QuickSort()
{
}

void QuickSort::Sort()
{
	quick(tab, l, p);
}

void QuickSort::quick(int * tab, int l, int p)
{

	int i = l;
	int j = p;
	int x = tab[(i + j) / 2];

	while (i < j)
	{
		while (tab[i] < x) i++;
		while (tab[j] > x) j--;

		if (i <= j)
		{
			int pom = tab[i];
			tab[i] = tab[j];
			tab[j] = pom;
			i++;
			j--;
		}
	}
	if (l < j)
		quick(tab, l, j);
	if (i < p)
		quick(tab, i, p);
}
