#pragma once
#define TAB_SIZE 30000
#include <time.h>
#include "Resource.h"

class SortType
{
public:
	SortType();
	SortType(int* t);
	virtual ~SortType();

public:
	virtual void Sort() = 0;
	unsigned int GetSortTime();
	CString GetSortName();
	int GetSortType();
	
	
	
protected:
	int tab[TAB_SIZE];
	CString name;
	int size = TAB_SIZE;
	int type = 0; //  w klasach dziedziczacych : 1 - proste, 2 - szybkie
	unsigned int sortingTime = -1; 
	
};

