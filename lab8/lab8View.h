// lab8View.h : interface of the CLab8View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LAB8VIEW_H__68B39CE6_DF46_47F8_BAB6_BC8EDB6685FC__INCLUDED_)
#define AFX_LAB8VIEW_H__68B39CE6_DF46_47F8_BAB6_BC8EDB6685FC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CLab8Set;

class CLab8View : public CRecordView
{
protected: // create from serialization only
	CLab8View();
	DECLARE_DYNCREATE(CLab8View)

public:
	//{{AFX_DATA(CLab8View)
	enum { IDD = IDD_LAB8_FORM };
	CLab8Set* m_pSet;
	CString	m_ID;
	CString	m_name;
	CString	m_position;
	CString	m_singer;
	CString	m_writer;
	//}}AFX_DATA

// Attributes
public:
	CLab8Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLab8View)
	public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	void MyUpdateData(void);
	virtual ~CLab8View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLab8View)
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordLast();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordAdd();
	afx_msg void OnRecordDel();
	afx_msg void OnRecordEdit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in lab8View.cpp
inline CLab8Doc* CLab8View::GetDocument()
   { return (CLab8Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LAB8VIEW_H__68B39CE6_DF46_47F8_BAB6_BC8EDB6685FC__INCLUDED_)
