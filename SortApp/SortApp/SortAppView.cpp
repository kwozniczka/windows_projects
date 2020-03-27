
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
#define START 120
#define START_COORD 80
#define ENDY 500

#define SIZE_LINES 20

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSortAppView

IMPLEMENT_DYNCREATE(CSortAppView, CView)

BEGIN_MESSAGE_MAP(CSortAppView, CView)
END_MESSAGE_MAP()

// CSortAppView construction/destruction

CSortAppView::CSortAppView()
{
	// TODO: add construction code here
	this->m_pClientRect = new CRect;

	m_pFontNums = new CFont;
	LOGFONT logFontNums;
	memset(&logFontNums, 0, sizeof(logFontNums));

	CString sFontNums("Arial");

	lstrcpy(logFontNums.lfFaceName, sFontNums);

	logFontNums.lfCharSet = DEFAULT_CHARSET;
	logFontNums.lfWeight = FW_NORMAL;
	logFontNums.lfHeight = -12;
	logFontNums.lfWidth = -8;

	if (!m_pFontNums->CreateFontIndirect(&logFontNums))
	{
		TRACE0("Could not create font for the trends.");
	}

	//---------------------------------

	m_pFontNames = new CFont;
	LOGFONT logFontNames;
	memset(&logFontNames, 0, sizeof(logFontNames));

	CString sFontNames("Georgia");

	lstrcpy(logFontNames.lfFaceName, sFontNames);

	logFontNames.lfCharSet = DEFAULT_CHARSET;
	logFontNames.lfWeight = FW_NORMAL;
	logFontNames.lfHeight = -24;
	logFontNames.lfWidth = -10;
	


	if (!m_pFontNames->CreateFontIndirect(&logFontNames))
	{
		TRACE0("Could not create font for the trends.");
	}

}

CSortAppView::~CSortAppView()
{
	delete m_pClientRect;
	

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

	
	drawPlot(pDC);
	drawSorts(pDC, pDoc);
	drawScale(pDC, pDoc);


	/*
	for (int i = 0; i < pDoc->sorts.size(); i++) {
		CString str1;
		str1.Format(L"%d", (int)pDoc->sorts[i]->GetSortTime());
		pDC->TextOutW(10, 30*(i+1), str1);
	}*/
	
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




void CSortAppView::drawPlot(CDC * pDC)
{

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


}

void CSortAppView::drawRectangle(CDC * pDC, int amount)
{

	POINT leftTop;
	POINT rightBottom;

	for (int i = 0; i < amount; ++i)
	{
		leftTop.x = START + i*(RECT_WIDTH + RIGHT_SHIFT);
		leftTop.y = 0.35* m_pClientRect->Height();
		rightBottom.x = START + i*(RECT_WIDTH + RIGHT_SHIFT) + RECT_WIDTH;
		rightBottom.y = 0.9 * m_pClientRect->Height();

		//CColorRect* rectan = new CColorRect(leftTop, rightBottom, 10, RED, colors[i]);
		CRect r(leftTop, rightBottom);
		CColorRect rectan(&r, 10, RED, colors[i]);
		//rectan->PaintRect(pDC);
		rectan.PaintRect(pDC);
	}
}


void CSortAppView::drawSorts(CDC * pDC, CSortAppDoc * pDoc)
{
	int status = pDoc->getSortStatus();
	if (status == 1) {  // sortowania proste
		drawRectangle(pDC, 3);
	}
	else if (status == 2) { // sortowania szybkie
		drawRectangle(pDC, 2);
	}
	else if (status == 3) { // sortowania wszystkie
		drawRectangle(pDC, 6);
	}
}

void CSortAppView::drawScale(CDC * pDC, CSortAppDoc * pDoc)
{
	int status = pDoc->getSortStatus();
	
	std::pair<int, int> p; 
	std::vector<std::pair<int, int>> points;
	
	for (int i = 0; i < SIZE_LINES; i++) {
		p.first = START_COORD - 50;
		p.second = (0.8*m_pClientRect->bottom * i / SIZE_LINES) + 0.1*m_pClientRect->bottom;
		points.push_back(p);
	}
	
	CFont* pOldFont = pDC->SelectObject(m_pFontNums);
	COLORREF oldColor = pDC->SetTextColor(RGB(0,0,0));
	CString str = L"1024";
	pDC->TextOutW(points[0].first, points[0].second, str);
	pDC->SelectObject(pOldFont);
	


}
