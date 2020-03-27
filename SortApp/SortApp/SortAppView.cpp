
// SortAppView.cpp : implementation of the CSortAppView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "SortApp.h"
#endif

#include "SortAppDoc.h"
#include "SortAppView.h"
#include "ColorRect.h"
#include "Coordinates.h"
#include "Sortowania.h"



#define RIGHT_SHIFT 30
#define RECT_WIDTH 50 
#define START 100
#define START_COORD 50
#define ENDY 500

#define SIZE_LINES 20

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSortAppView

IMPLEMENT_DYNCREATE(CSortAppView, CView)

BEGIN_MESSAGE_MAP(CSortAppView, CView)
	ON_COMMAND(ID_PROSTE, &CSortAppView::OnSimpleSort)
	ON_COMMAND(ID_SZYBKIE, &CSortAppView::OnQuickSort)
	ON_COMMAND(ID_WSZYSTKIE, &CSortAppView::OnAllSort)
END_MESSAGE_MAP()

// CSortAppView construction/destruction

CSortAppView::CSortAppView()
{
	// TODO: add construction code here
	this->m_pClientRect = new CRect;
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
	

}

CSortAppView::~CSortAppView()
{
	delete m_pClientRect;
	delete tab;

}

BOOL CSortAppView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CSortAppView drawing

void CSortAppView::OnDraw(CDC* pDC)
{
	CSortAppDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;


	GetClientRect(m_pClientRect);

	std::pair<int, int> leftTopPoint(START_COORD, 0.1 * m_pClientRect->Height());
	std::pair<int, int> rightBottomPoint(ENDX, 0.9 * m_pClientRect->Height());


	std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> lines;

	for (int i = 0; i < SIZE_LINES + 1; i++)
	{

		std::pair<std::pair<int, int>, std::pair<int, int>> s;
		//xy poczatek
		s.first.first = START_COORD;
		s.first.second = (0.8*m_pClientRect->bottom * i / SIZE_LINES) + 0.1*m_pClientRect->bottom;

		//xy koniec
		s.second.first = ENDX;
		s.second.second = (0.8*m_pClientRect->bottom * i / SIZE_LINES) + 0.1*m_pClientRect->bottom;

		lines.push_back(s);
	}

	CCoordinates* coord = new CCoordinates(leftTopPoint, rightBottomPoint, lines);
	coord->drawCoordinates(pDC);

	/*
	for (int i = 0; i < 6; ++i)
	{
		CRect rect(START + i*(RECT_WIDTH + RIGHT_SHIFT), 0.35* m_pClientRect->Height(), START + i*(RECT_WIDTH + RIGHT_SHIFT) + RECT_WIDTH, 0.9 * m_pClientRect->Height());
		CColorRect* rectan = new CColorRect(&rect, 10, RED, colors[i]);

		rectan->PaintRect(pDC, rect);
	}*/

	POINT leftTop;
	POINT rightBottom;

	for (int i = 0; i < 6; ++i)
	{
		leftTop.x = START + i*(RECT_WIDTH + RIGHT_SHIFT);
		leftTop.y = 0.35* m_pClientRect->Height();
		rightBottom.x = START + i*(RECT_WIDTH + RIGHT_SHIFT) + RECT_WIDTH;
		rightBottom.y = 0.9 * m_pClientRect->Height();

		//CRect rect( START + i*( RECT_WIDTH + RIGHT_SHIFT ), 0.35* m_pClientRect->Height(),  START + i*( RECT_WIDTH + RIGHT_SHIFT ) + RECT_WIDTH, 0.9 * m_pClientRect->Height() );
		//CColorRect* rectan = new CColorRect( &rect, 10, RED, colors[i]);
		//rectan->PaintRect( pDC, rect );

		//CColorRect* rectan = new CColorRect(leftTop, rightBottom, 10, RED, colors[i]);
		CRect r(leftTop, rightBottom);
		CColorRect rectan(&r, 10, RED, colors[i]);
		//rectan->PaintRect(pDC);
		rectan.PaintRect(pDC);
	}

	for (int i = 0; i < sorts.size(); i++) {
		CString str1;
		str1.Format(L"%d", (int)sorts[i]->GetSortTime());
		pDC->TextOutW(10, 30*(i+1), str1);
	}
	
}


// CSortAppView diagnostics

#ifdef _DEBUG
void CSortAppView::AssertValid() const
{
	CView::AssertValid();
}

void CSortAppView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSortAppDoc* CSortAppView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSortAppDoc)));
	return (CSortAppDoc*)m_pDocument;
}
#endif //_DEBUG




// przycisk "proste"
void CSortAppView::OnSimpleSort()
{
	// TODO: Add your command handler code here


}


void CSortAppView::OnQuickSort()
{
	// TODO: Add your command handler code here
}


void CSortAppView::OnAllSort()
{
	// TODO: Add your command handler code here
}
