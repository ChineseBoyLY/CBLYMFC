// lab2View.h : interface of the CLab2View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LAB2VIEW_H__09D5ED69_0807_4606_82C1_F56B552B1080__INCLUDED_)
#define AFX_LAB2VIEW_H__09D5ED69_0807_4606_82C1_F56B552B1080__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CLab2View : public CFormView
{
protected: // create from serialization only
	CLab2View();
	DECLARE_DYNCREATE(CLab2View)

public:
	//{{AFX_DATA(CLab2View)
	enum { IDD = IDD_LAB2_FORM };
	CString	m_strTime;
	//}}AFX_DATA

// Attributes
public:
	CLab2Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLab2View)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	bool m_btimer;
	unsigned int m_timer;
	virtual ~CLab2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLab2View)
	afx_msg void OnTimeStart();
	afx_msg void OnTimeStop();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnUpdateTimeStart(CCmdUI* pCmdUI);
	afx_msg void OnTimeCurrent();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	int ms;
	int s;
	int m;
	int h;
};

#ifndef _DEBUG  // debug version in lab2View.cpp
inline CLab2Doc* CLab2View::GetDocument()
   { return (CLab2Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LAB2VIEW_H__09D5ED69_0807_4606_82C1_F56B552B1080__INCLUDED_)
