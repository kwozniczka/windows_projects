#include "stdafx.h"
#include "BubbleSort.h"


BubbleSort::BubbleSort(int * t) : SortType(t)
{
	type = 1;
	name = "Bubble";
}


BubbleSort::~BubbleSort()
{
}

void BubbleSort::Sort()
{
	//od duzych do malych
	for (int j = 0; j < size - 1; j++)
	{
		for (int i = size - 1; i > j; i--)
		{
			if (tab[i] < tab[i - 1])
			{
				int temp = tab[i];
				tab[i] = tab[i - 1];
				tab[i - 1] = temp;
			}
		}
	}
}
