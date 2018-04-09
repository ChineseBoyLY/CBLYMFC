// MyWcDlg.h : header file
//

#if !defined(AFX_MYWCDLG_H__39E20DF7_AB1A_41DF_839A_06F17FC9A25E__INCLUDED_)
#define AFX_MYWCDLG_H__39E20DF7_AB1A_41DF_839A_06F17FC9A25E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMyWcDlg dialog

#include "WCSocket.h"
class CMyWcDlg : public CDialog
{
// Construction
public:
	CMyWcDlg(CWnd* pParent = NULL);	// standard constructor
	CWCSocket sockClient;
	_DATA m_Dat;
// Dialog Data
	//{{AFX_DATA(CMyWcDlg)
	enum { IDD = IDD_MYWC_DIALOG };
	CListBox	m_ctlName;
	CListBox	m_ctlRecvd;
	CString	m_client_name;
	BOOL	m_talk;
	CString	m_systemTime;
	CString	m_server_name;
	int		m_nPort;
	CString	m_send_info;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyWcDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMyWcDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnConnect();
	afx_msg void OnClose();
	afx_msg void OnSend();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYWCDLG_H__39E20DF7_AB1A_41DF_839A_06F17FC9A25E__INCLUDED_)
