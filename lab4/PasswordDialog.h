#if !defined(AFX_PASSWORDDIALOG_H__4F2A627A_2014_48BE_B64C_A100A86DA1C6__INCLUDED_)
#define AFX_PASSWORDDIALOG_H__4F2A627A_2014_48BE_B64C_A100A86DA1C6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PasswordDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPasswordDialog dialog

class CPasswordDialog : public CDialog
{
// Construction
public:
	CPasswordDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPasswordDialog)
	enum { IDD = IDD_PASSWORD_DIALOG };
	CString	m_password;
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
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PASSWORDDIALOG_H__4F2A627A_2014_48BE_B64C_A100A86DA1C6__INCLUDED_)
