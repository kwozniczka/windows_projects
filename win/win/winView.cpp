
// WinView.cpp : implementation of the CWinView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Win.h"
#endif

#include "WinDoc.h"
#include "WinView.h"
#include "ColorRect.h"
#include "Coordinates.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



#define RIGHT_SHIFT 30
#define RECT_WIDTH 50 
#define START 100
#define START_COORD 50
#define ENDY 500

#define SIZE_LINES 20

// CWinView

IMPLEMENT_DYNCREATE(CWinView, CView)

BEGIN_MESSAGE_MAP(CWinView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CWinView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CWinView construction/destruction

CWinView::CWinView()
{
	// TODO: add construction code here

	this->m_pClientRect = new CRect;
}

CWinView::~CWinView()
{
	delete m_pClientRect;
}

BOOL CWinView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CWinView drawing

void CWinView::OnDraw(CDC* pDC)
{
	CWinDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;


	GetClientRect( m_pClientRect );

	std::pair<int, int> leftTopPoint( START_COORD, 0.1 * m_pClientRect->Height());
	std::pair<int, int> rightBottomPoint( ENDX, 0.9 * m_pClientRect->Height() );


	std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> lines;

	for( int i = 0; i < SIZE_LINES + 1; i++ )
	{

		std::pair<std::pair<int, int>, std::pair<int, int>> s;
		//xy poczatek
		s.first.first = START_COORD;
		s.first.second = (0.8*m_pClientRect->bottom * i / SIZE_LINES) + 0.1*m_pClientRect->bottom;
		
		//xy koniec
		s.second.first = ENDX;
		s.second.second = (0.8*m_pClientRect->bottom * i / SIZE_LINES) + 0.1*m_pClientRect->bottom;

		lines.push_back( s );
	}

	CCoordinates* coord = new CCoordinates( leftTopPoint, rightBottomPoint, lines );
	coord->drawCoordinates( pDC );


	for( int i = 0; i < 6; ++i )
	{
		CRect rect( START + i*( RECT_WIDTH + RIGHT_SHIFT ), 0.35* m_pClientRect->Height(),  START + i*( RECT_WIDTH + RIGHT_SHIFT ) + RECT_WIDTH, 0.9 * m_pClientRect->Height() );
		CColorRect* rectan = new CColorRect( &rect, 10, RED, colors[i]);

		rectan->PaintRect( pDC, rect );
	}

}


// CWinView printing


void CWinView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CWinView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CWinView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CWinView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CWinView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CWinView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CWinView diagnostics

#ifdef _DEBUG
void CWinView::AssertValid() const
{
	CView::AssertValid();
}

void CWinView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWinDoc* CWinView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWinDoc)));
	return (CWinDoc*)m_pDocument;
}
#endif //_DEBUG


// CWinView message handlers
