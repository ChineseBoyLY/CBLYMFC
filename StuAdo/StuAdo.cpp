// StuAdo.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "StuAdo.h"
#include "StuAdoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStuAdoApp

BEGIN_MESSAGE_MAP(CStuAdoApp, CWinApp)
	//{{AFX_MSG_MAP(CStuAdoApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStuAdoApp construction

CStuAdoApp::CStuAdoApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CStuAdoApp object

CStuAdoApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CStuAdoApp initialization

BOOL CStuAdoApp::InitInstance()
{
	AfxEnableControlContainer();
	
	AfxOleInit();//初始化com
	try
    {
		m_pConnection.CreateInstance(_uuidof(Connection));//创建ado连接
	}
    catch(_com_error e1)    //处理连接错误
    {
		AfxMessageBox( "创建ado连接错误!");
		return FALSE;    
    }
    try
    {
		//打开本地Access数据库student.accdb
		m_pConnection->Open( "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=student.accdb","","",adModeUnknown);
	//	m_pConnection->Open( "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=student.accdb","","",adModeUnknown);
    }
    catch(_com_error e2)    //处理连接错误
    {
		AfxMessageBox( "数据库连接失败，确认数据库student.accdb是否在当前路径下!");
		return FALSE;    
    }
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CStuAdoDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
