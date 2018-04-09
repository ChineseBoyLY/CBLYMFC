// lab6.h : main header file for the LAB6 application
//

#if !defined(AFX_LAB6_H__57C6A189_3560_4CB6_B57A_84C4EF1C2C7F__INCLUDED_)
#define AFX_LAB6_H__57C6A189_3560_4CB6_B57A_84C4EF1C2C7F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CLab6App:
// See lab6.cpp for the implementation of this class
//

class CLab6App : public CWinApp
{
public:
	CLab6App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLab6App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CLab6App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LAB6_H__57C6A189_3560_4CB6_B57A_84C4EF1C2C7F__INCLUDED_)
