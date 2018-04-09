// StuAdoDlg.h : header file
//

#if !defined(AFX_STUADODLG_H__E67D3B54_8B42_43C0_B1AB_F9A8EF1E13D5__INCLUDED_)
#define AFX_STUADODLG_H__E67D3B54_8B42_43C0_B1AB_F9A8EF1E13D5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CStuAdoDlg dialog

class CStuAdoDlg : public CDialog
{
// Construction
public:
	void showInfo();
	CStuAdoDlg(CWnd* pParent = NULL);	// standard constructor
	_ConnectionPtr m_pConnection;  
    _CommandPtr m_pCommand;  
    _RecordsetPtr m_pRecordset;  

// Dialog Data
	//{{AFX_DATA(CStuAdoDlg)
	enum { IDD = IDD_STUADO_DIALOG };
	CButton	m_follow_address;
	CButton	m_follow_name;
	CButton	m_follow_id;
	CButton	m_listall;
	CListBox	m_listdatabase;
	CButton	m_modify;
	CButton	m_exit;
	CButton	m_delete;
	CButton	m_add;
	CString	m_address;
	CString	m_name;
	CString	m_id;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStuAdoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CStuAdoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnListall();
	afx_msg void OnAdd();
	afx_msg void OnDelete();
	afx_msg void OnExitsys();
	afx_msg void OnModify();
	afx_msg void OnSelchangeListdatabase();
	afx_msg void OnFollowId();
	afx_msg void OnFollowName();
	afx_msg void OnFollowAddress();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STUADODLG_H__E67D3B54_8B42_43C0_B1AB_F9A8EF1E13D5__INCLUDED_)
