// lab8.h : main header file for the LAB8 application
//

#if !defined(AFX_LAB8_H__E2BFD9C8_3AC8_4A0B_A019_96CB8B01228A__INCLUDED_)
#define AFX_LAB8_H__E2BFD9C8_3AC8_4A0B_A019_96CB8B01228A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CLab8App:
// See lab8.cpp for the implementation of this class
//

class CLab8App : public CWinApp
{
public:
	CLab8App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLab8App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CLab8App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LAB8_H__E2BFD9C8_3AC8_4A0B_A019_96CB8B01228A__INCLUDED_)
