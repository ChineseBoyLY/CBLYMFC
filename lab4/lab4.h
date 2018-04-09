// lab4.h : main header file for the LAB4 application
//

#if !defined(AFX_LAB4_H__98C9AF0E_998E_4D1F_9D23_46A9CCCCFDC9__INCLUDED_)
#define AFX_LAB4_H__98C9AF0E_998E_4D1F_9D23_46A9CCCCFDC9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CLab4App:
// See lab4.cpp for the implementation of this class
//

class CLab4App : public CWinApp
{
public:
	CLab4App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLab4App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CLab4App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LAB4_H__98C9AF0E_998E_4D1F_9D23_46A9CCCCFDC9__INCLUDED_)
