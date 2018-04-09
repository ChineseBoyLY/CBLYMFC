// lab5.h : main header file for the LAB5 application
//

#if !defined(AFX_LAB5_H__444FE8F4_2173_4785_BD99_AACE342A1638__INCLUDED_)
#define AFX_LAB5_H__444FE8F4_2173_4785_BD99_AACE342A1638__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CLab5App:
// See lab5.cpp for the implementation of this class
//

class CLab5App : public CWinApp
{
public:
	CLab5App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLab5App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CLab5App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LAB5_H__444FE8F4_2173_4785_BD99_AACE342A1638__INCLUDED_)
