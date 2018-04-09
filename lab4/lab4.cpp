// lab4.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "lab4.h"
#include "lab4Dlg.h"
#include "PasswordDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLab4App

BEGIN_MESSAGE_MAP(CLab4App, CWinApp)
	//{{AFX_MSG_MAP(CLab4App)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLab4App construction

CLab4App::CLab4App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CLab4App object

CLab4App theApp;

/////////////////////////////////////////////////////////////////////////////
// CLab4App initialization

BOOL CLab4App::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	while(true){
	CPasswordDialog m_dlg;
	if (m_dlg.DoModal()!= IDOK)
	{
		return false;
	}
	
	if(m_dlg.m_password!="123456")
	{
		AfxMessageBox(_T("口令错误，确认后将退出程序"));
		//return false;
		continue;
	}
//	else if (nResponse == IDCANCEL)
//	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
//	}
	else{
	CLab4Dlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	return true;
	}
	}
	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	
//	return true;
}
