#if !defined(AFX_PASSWORDDIALOG_H__24B99A63_80F3_4247_84C8_2983C0E3D302__INCLUDED_)
#define AFX_PASSWORDDIALOG_H__24B99A63_80F3_4247_84C8_2983C0E3D302__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PasswordDialog.h : header file
//
//#include "resource.h"
/////////////////////////////////////////////////////////////////////////////
// CPasswordDialog dialog

class CPasswordDialog : public CDialog
{
// Construction
public:
	CPasswordDialog(CWnd* pParent = NULL);   // standard constructor
	_ConnectionPtr m_pConnection;  
    _CommandPtr m_pCommand;  
    _RecordsetPtr m_pRecordset;
// Dialog Data
	//{{AFX_DATA(CPasswordDialog)
	enum { IDD = IDD_PASSWORD_DIALOG };
	CString	m_pwd;
	CString	m_user;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPasswordDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPasswordDialog)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PASSWORDDIALOG_H__24B99A63_80F3_4247_84C8_2983C0E3D302__INCLUDED_)
