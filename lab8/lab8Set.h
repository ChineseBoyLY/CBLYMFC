// lab8Set.h : interface of the CLab8Set class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LAB8SET_H__2A9E5949_4D2E_4C1F_A451_49538DB608C2__INCLUDED_)
#define AFX_LAB8SET_H__2A9E5949_4D2E_4C1F_A451_49538DB608C2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CLab8Set : public CRecordset
{
public:
	CLab8Set(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CLab8Set)

// Field/Param Data
	//{{AFX_FIELD(CLab8Set, CRecordset)
	CString	m_column1;
	CString	m_column2;
	CString	m_column3;
	CString	m_column4;
	CString	m_column5;
	//}}AFX_FIELD

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLab8Set)
	public:
	virtual CString GetDefaultConnect();	// Default connection string
	virtual CString GetDefaultSQL(); 	// default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LAB8SET_H__2A9E5949_4D2E_4C1F_A451_49538DB608C2__INCLUDED_)

