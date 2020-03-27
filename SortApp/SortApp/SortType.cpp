#include "stdafx.h"
#include "SortType.h"


SortType::SortType()
{

}

SortType::SortType(int * t)
{
	for (int i = 0; i < size; i++)
		tab[i] = t[i];
}


SortType::~SortType()
{

}

unsigned int SortType::GetSortTime()
{
	if (sortingTime == -1) {
		unsigned int beforeSorting = ::GetTickCount();
		Sort();
		unsigned int afterSorting = ::GetTickCount();
		sortingTime = afterSorting - beforeSorting;
		return sortingTime;
	}
	return sortingTime;
}

CString SortType::GetSortName()
{
	return name;
}

int SortType::GetSortType()
{
	return type;
}
