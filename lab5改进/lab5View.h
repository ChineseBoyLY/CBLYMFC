// lab5View.h : interface of the CLab5View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LAB5VIEW_H__F0C9D4B9_BEED_46D6_97F0_EDA1070EE61E__INCLUDED_)
#define AFX_LAB5VIEW_H__F0C9D4B9_BEED_46D6_97F0_EDA1070EE61E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CLab5View : public CFormView
{
	int m_nCurrentNo;

protected: // create from serialization only
	CLab5View();
	DECLARE_DYNCREATE(CLab5View)

public:
	//{{AFX_DATA(CLab5View)
	enum { IDD = IDD_LAB5_FORM };
	CComboBox	m_noList;
	int		m_age;
	CString	m_name;
	CString	m_school;
	CString	m_sex;
	CString	m_tel;
	//}}AFX_DATA

// Attributes
public:
	CLab5Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLab5View)
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
	virtual ~CLab5View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLab5View)
	afx_msg void OnSelchangeComboSno();
	afx_msg void OnChangeEditAge();
	afx_msg void OnChangeEditName();
	afx_msg void OnChangeEditSchool();
	afx_msg void OnChangeEditSex();
	afx_msg void OnChangeEditTel();
	afx_msg void OnFileMyopen();
	afx_msg void OnFileMysave();
	afx_msg void OnPlay();
	afx_msg void OnStop();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in lab5View.cpp
inline CLab5Doc* CLab5View::GetDocument()
   { return (CLab5Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LAB5VIEW_H__F0C9D4B9_BEED_46D6_97F0_EDA1070EE61E__INCLUDED_)
