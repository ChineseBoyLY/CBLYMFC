// lab4Dlg.h : header file
//

#if !defined(AFX_LAB4DLG_H__821D30DC_F154_4B1D_A9ED_63B864052722__INCLUDED_)
#define AFX_LAB4DLG_H__821D30DC_F154_4B1D_A9ED_63B864052722__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CLab4Dlg dialog

class CLab4Dlg : public CDialog
{
// Construction
public:
	bool flag;
	void Calculate(void);
	void UpdateDisplay(double lVal);
	CLab4Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CLab4Dlg)
	enum { IDD = IDD_LAB4_DIALOG };
	CString	m_display;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLab4Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	double m_first;
	double m_second;
	double m_coff;
	CString m_operator;
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CLab4Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnOperandInput(UINT nID);
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonMinus();
	afx_msg void OnButtonMultiply();
	afx_msg void OnButtonDiv();
	afx_msg void OnButtonEqual();
	afx_msg void OnButtonSqrt();
	afx_msg void OnButtonClear();
	afx_msg void OnButtonReciprocal();
	afx_msg void OnButtonSign();
	afx_msg void OnButtonPoint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LAB4DLG_H__821D30DC_F154_4B1D_A9ED_63B864052722__INCLUDED_)
