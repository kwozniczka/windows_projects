
// SortAppDoc.cpp : implementation of the CSortAppDoc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "SortApp.h"
#endif

#include "SortAppDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CSortAppDoc

IMPLEMENT_DYNCREATE(CSortAppDoc, CDocument)

BEGIN_MESSAGE_MAP(CSortAppDoc, CDocument)
	ON_COMMAND(ID_PROSTE, &CSortAppDoc::OnSimpleSorts)
	ON_COMMAND(ID_SZYBKIE, &CSortAppDoc::OnQuickSorts)
	ON_COMMAND(ID_WSZYSTKIE, &CSortAppDoc::OnAllSorts)
END_MESSAGE_MAP()


// CSortAppDoc construction/destruction

CSortAppDoc::CSortAppDoc()
{
	// TODO: add one-time construction code here

	tab = new int[TAB_SIZE];
	srand(time(NULL));
	for (int i = 0; i < TAB_SIZE; ++i)
		tab[i] = rand() % 1000;

	sorts.push_back(new InsertSort(tab));
	sorts.push_back(new HeapSort(tab));
	sorts.push_back(new BubbleSort(tab));
	sorts.push_back(new HalfSort(tab));
	sorts.push_back(new SelectSort(tab));
	sorts.push_back(new QuickSort(tab));

	sortStatus = 3;

}

CSortAppDoc::~CSortAppDoc()
{
}

BOOL CSortAppDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	countMaxSortTime();

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CSortAppDoc serialization

void CSortAppDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

#ifdef SHARED_HANDLERS


// Support for thumbnails
void CSortAppDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CSortAppDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}




void CSortAppDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CSortAppDoc diagnostics

#ifdef _DEBUG
void CSortAppDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSortAppDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CSortAppDoc commands

int CSortAppDoc::getSortStatus()
{
	return sortStatus;
}

unsigned int CSortAppDoc::getMaxSortTime()
{
	if (sortStatus == 1 || sortStatus == 3)
		return maxSimpleSortsTime;
	return maxQuickSortsTime;
}

void CSortAppDoc::countMaxSortTime()
{
	unsigned int time = 0;
	for (SortType* sort : sorts) {
		time = sort->GetSortTime();
		if (sort->GetSortType() == 1) { // to tutaj mamy proste sortowania
			if (maxSimpleSortsTime < time)
				maxSimpleSortsTime = time;
		}
		else {
			if (maxQuickSortsTime < time)
				maxQuickSortsTime = time;
		}
	}
}


void CSortAppDoc::OnSimpleSorts()
{
	sortStatus = 1;
	UpdateAllViews(NULL);
}


void CSortAppDoc::OnQuickSorts()
{
	sortStatus = 2;
	UpdateAllViews(NULL);
}


void CSortAppDoc::OnAllSorts()
{
	sortStatus = 3;
	UpdateAllViews(NULL);
}
