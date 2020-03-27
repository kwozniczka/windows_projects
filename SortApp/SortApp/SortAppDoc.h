
// SortAppDoc.h : interface of the CSortAppDoc class
//


#pragma once

#include <vector>
#include "SortType.h"
#include "InsertSort.h"
#include "BubbleSort.h"
#include "HalfSort.h"
#include "HeapSort.h"
#include "SelectSort.h"
#include "QuickSort.h"


class CSortAppDoc : public CDocument
{
protected: // create from serialization only
	CSortAppDoc();
	DECLARE_DYNCREATE(CSortAppDoc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CSortAppDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()


#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
	afx_msg void OnSimpleSorts();
	afx_msg void OnQuickSorts();
	afx_msg void OnAllSorts();\

public:
	int* tab;
	std::vector<SortType*> sorts;
	int getSortStatus();
	unsigned int getMaxSortTime();

private:
	int sortStatus;  // 1 - proste, 2 - szybkie
	unsigned int maxSimpleSortsTime;
	unsigned int maxQuickSortsTime;
	void countMaxSortTime();
};
