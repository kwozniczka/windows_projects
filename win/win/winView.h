
// WinView.h : interface of the CWinView class
//

#pragma once

#define RED RGB(255,0,0)
#define GREEN RGB(153, 255, 153)
#define PINK RGB(255, 204, 255)
#define BLUE RGB(179, 240, 255)
#define PEACH RGB(255, 187, 153)
#define PURPLE RGB(230, 153, 255)
#define YELLOW RGB(255, 255, 179)

#include <vector>


static COLORREF colors[] = { BLUE, PINK, GREEN, PEACH, PURPLE, YELLOW };


class CWinView : public CView
{
protected: // create from serialization only
	CWinView();
	DECLARE_DYNCREATE(CWinView)

// Attributes
public:
	CWinDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CWinView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()

private:
	CRect* m_pClientRect;
};

#ifndef _DEBUG  // debug version in WinView.cpp
inline CWinDoc* CWinView::GetDocument() const
   { return reinterpret_cast<CWinDoc*>(m_pDocument); }
#endif

