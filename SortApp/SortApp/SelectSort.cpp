#include "stdafx.h"
#include "SelectSort.h"


SelectSort::SelectSort(int * t) : SortType(t)
{
	type = 1;
	name = "Select";
}


SelectSort::~SelectSort()
{
}

void SelectSort::Sort()
{
	for (int i = 0; i < size - 1; i++)
	{
		int min = tab[i];
		int pozMin = i;

		for (int j = i + 1; j < size; j++)
			if (tab[j] < min)
			{
				min = tab[j];
				pozMin = j;
			}

		tab[pozMin] = tab[i];
		tab[i] = min;
	}
}
