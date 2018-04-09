// lab3.h : main header file for the LAB3 application
//

#if !defined(AFX_LAB3_H__EABD04F6_9F28_461E_9362_45973FA4DEB2__INCLUDED_)
#define AFX_LAB3_H__EABD04F6_9F28_461E_9362_45973FA4DEB2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CLab3App:
// See lab3.cpp for the implementation of this class
//

class CLab3App : public CWinApp
{
public:
	CLab3App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLab3App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CLab3App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LAB3_H__EABD04F6_9F28_461E_9362_45973FA4DEB2__INCLUDED_)
