// lab6View.h : interface of the CLab6View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LAB6VIEW_H__8123618A_B8E6_4D60_8CAE_8473352CA08E__INCLUDED_)
#define AFX_LAB6VIEW_H__8123618A_B8E6_4D60_8CAE_8473352CA08E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CLab6View : public CView
{
protected: // create from serialization only
	CLab6View();
	DECLARE_DYNCREATE(CLab6View)

// Attributes
public:
	CLab6Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLab6View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLab6View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLab6View)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnColor();
	afx_msg void OnEllipse();
	afx_msg void OnEllirect();
	afx_msg void OnLine();
	afx_msg void OnRect();
	afx_msg void OnWidth1();
	afx_msg void OnWidth2();
	afx_msg void OnWidth3();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnUpdateLine(CCmdUI* pCmdUI);
	afx_msg void OnUpdateRect(CCmdUI* pCmdUI);
	afx_msg void OnUpdateEllirect(CCmdUI* pCmdUI);
	afx_msg void OnUpdateEllipse(CCmdUI* pCmdUI);
	afx_msg void OnUpdateWidth1(CCmdUI* pCmdUI);
	afx_msg void OnUpdateWidth2(CCmdUI* pCmdUI);
	afx_msg void OnUpdateWidth3(CCmdUI* pCmdUI);
	afx_msg void OnClear();
	afx_msg void OnFill();
	afx_msg void OnUpdateFill(CCmdUI* pCmdUI);
	afx_msg void OnFont();
	afx_msg void FontOut(CDC* pDC,int& nHeight,int nPoints,int dline);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	int m_type;
	COLORREF m_color;
	COLORREF m_fillcolor;
	int m_nmx;
	int m_nmy;
	int m_width;
	CBitmap *m_pbmp;
	CDC * m_pmdc;
	CPoint m_pold;
	CPoint m_pnew;
	BOOL m_bdoing;
};

#ifndef _DEBUG  // debug version in lab6View.cpp
inline CLab6Doc* CLab6View::GetDocument()
   { return (CLab6Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LAB6VIEW_H__8123618A_B8E6_4D60_8CAE_8473352CA08E__INCLUDED_)
