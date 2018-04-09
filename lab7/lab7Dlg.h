// lab7Dlg.h : header file
//

#if !defined(AFX_LAB7DLG_H__B0945A86_C978_4DFE_93B5_7DA19E03F433__INCLUDED_)
#define AFX_LAB7DLG_H__B0945A86_C978_4DFE_93B5_7DA19E03F433__INCLUDED_

#if _MSC_VER > 1000
#pragma once

#endif // _MSC_VER > 1000

#include "MCIClass.h"
/////////////////////////////////////////////////////////////////////////////
// CLab7Dlg dialog

class CLab7Dlg : public CDialog,protected CMCIClass
{
// Construction
public:
	CLab7Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CLab7Dlg)
	enum { IDD = IDD_LAB7_DIALOG };
	CSliderCtrl	m_Slider;
	CProgressCtrl	m_Progress;
	int		m_radio;
	CString	m_dight;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLab7Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CLab7Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonOpen();
	afx_msg void OnButtonPlay();
	afx_msg void OnButtonStop();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnRadioWave();
	afx_msg void OnRadioMidi();
	afx_msg void OnRadioAvi();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LAB7DLG_H__B0945A86_C978_4DFE_93B5_7DA19E03F433__INCLUDED_)
