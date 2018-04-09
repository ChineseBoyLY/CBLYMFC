// MyWc.h : main header file for the MYWC application
//

#if !defined(AFX_MYWC_H__26530695_63DF_40AE_BB2D_1553E95DC1FD__INCLUDED_)
#define AFX_MYWC_H__26530695_63DF_40AE_BB2D_1553E95DC1FD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyWcApp:
// See MyWc.cpp for the implementation of this class
//

class CMyWcApp : public CWinApp
{
public:
	CMyWcApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyWcApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMyWcApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYWC_H__26530695_63DF_40AE_BB2D_1553E95DC1FD__INCLUDED_)
