// StuAdo.h : main header file for the STUADO application
//

#if !defined(AFX_STUADO_H__071DD619_D2B3_496E_AA45_CC7620CE3677__INCLUDED_)
#define AFX_STUADO_H__071DD619_D2B3_496E_AA45_CC7620CE3677__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#import  "msado15.dll" no_namespace rename( "EOF","adoEOF")

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CStuAdoApp:
// See StuAdo.cpp for the implementation of this class
//

class CStuAdoApp : public CWinApp
{
public:
	CStuAdoApp();
	_ConnectionPtr m_pConnection;
	_RecordsetPtr m_pRecordset; 
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStuAdoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CStuAdoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STUADO_H__071DD619_D2B3_496E_AA45_CC7620CE3677__INCLUDED_)
