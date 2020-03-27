#include "Sortowania.h"
#include "stdafx.h"
#include <stdlib.h>
#include <algorithm> 
#include <memory.h>

void updateHeap(int* tab, int l, int p);

//====================================
void insertSort(int *tab, int size)
{
	for (int i = 1; i < size; i++)
	{
		int x = tab[i];
		int j = i - 1;
		while ((j >= 0) && (tab[j] > x))
			tab[j + 1] = tab[j--];
		tab[j + 1] = x;
	}
}



//====================================
void halfSort(int *tab, int size)
{
	for (int i = 1; i < size; i++) {

		int x = tab[i];
		int l = 0;
		int p = i - 1;
		int sr;

		while (l <= p)
		{
			sr = (l + p) / 2;
			if (x < tab[sr])
				p = sr - 1;
			else
				l = sr + 1;
		}
		if (l < i)
		{
			memcpy(tab + l + 1, tab + l, (i - l) * sizeof(int)); // MEGAFAST!
																 //for ( int j = i - 1; j >= sr; j-- )
																 //tab[ j + 1 ] = tab[ j ];
			tab[l] = x;
		}
	}
}





//====================================
void bubbleSort(int *tab, int size)
{
	//od du¿ych do ma³ych
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





//====================================
void selectSort(int *tab, int size)
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




//====================================
void heapSort(int *tab, int size)
{
	//stogowe/kopcowe
	//kopiec: h[i] >= h[2i] oraz h[i] >= h[2i+1]
	//
	//
	for (int j = size / 2 + 1; j > 0; )
		updateHeap(tab, --j, size - 1);

	for (int j = size - 1; j; )
	{
		int x = tab[j];
		tab[j] = tab[0];
		tab[0] = x;
		updateHeap(tab, 0, --j);
	}
}





//====================================
void updateHeap(int* tab, int l, int p)
{
	int i = l;
	int j = 2 * i;
	int x = tab[i];

	while (j <= p)
	{
		if (j < p)
			if (tab[j] < tab[j + 1])
				j++;

		if (tab[j] <= x) break;

		tab[i] = tab[j];
		i = j;
		j = 2 * i;
	}
	tab[i] = x;
}





//====================================
void quickSort(int *tab, int l, int p)
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
		quickSort(tab, l, j);
	if (i < p)
		quickSort(tab, i, p);
}






