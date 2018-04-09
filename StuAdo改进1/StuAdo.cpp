// StuAdo.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "StuAdo.h"
#include "StuAdoDlg.h"
#include "PasswordDialog.h"
#include "Math.h"

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
	
	AfxOleInit();//��ʼ��com
	try
    {
		m_pConnection.CreateInstance(_uuidof(Connection));//����ado����
	}
    catch(_com_error e1)    //�������Ӵ���
    {
		AfxMessageBox( "����ado���Ӵ���!");
		return FALSE;    
    }
    try
    {
		//�򿪱���Access���ݿ�student.accdb
		m_pConnection->Open( "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=student.accdb","","",adModeUnknown);
	//	m_pConnection->Open( "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=student.mdb","","",adModeUnknown);
    }
    catch(_com_error e2)    //�������Ӵ���
    {
		AfxMessageBox( "���ݿ�����ʧ�ܣ�ȷ�����ݿ�student.accdb�Ƿ��ڵ�ǰ·����!");
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


//==========================================================================
	int flag=3;
	while(flag--){
	CPasswordDialog m_dlg;
	int r2=rand()%256;
	SetDialogBkColor(RGB(r2,255,255),RGB(255,0,0));
	m_dlg.DoModal();
	if(m_dlg.DoModal() != IDOK)return false;

	//����SQL�������
	CString str="";
	str.Format("�û��������벻��Ϊ��!������%d��������ᣡ",flag);
	if(m_dlg.m_user == "" || m_dlg.m_pwd == "")
    {
		AfxMessageBox(str);
		continue;
    }
	CString strSql;
	strSql.Format("select userName,pwd from t_login where userName = '%s'",m_dlg.m_user);
	//����
	BSTR bsSql = strSql.AllocSysString();
	m_pRecordset.CreateInstance(_uuidof(Recordset));
	try
	{
		m_pRecordset->Open(bsSql,theApp.m_pConnection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}
//====================================================================
	_variant_t var;
	CString strName,strPwd; 
    strPwd=strName="";
    try
    {
		if(!m_pRecordset->BOF)    
			m_pRecordset->MoveFirst();
		else
		{
			AfxMessageBox("�����ڸ��û�����");
			continue;
		}
		while(!m_pRecordset->adoEOF)
		{
			var=m_pRecordset->GetCollect("userName");
			if(var.vt!=VT_NULL)
				strName = (LPCSTR)_bstr_t(var);
			var=m_pRecordset->GetCollect("pwd");
			if(var.vt!=VT_NULL)
				strPwd = (LPCSTR)_bstr_t(var);
			m_pRecordset->MoveNext();
		}
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}
	
	if(m_dlg.m_pwd==strPwd)
	{
		CStuAdoDlg dlg;
		m_pMainWnd = &dlg;
		dlg.DoModal();
		return true;
	}
	else
	{
		CString str1="";
		str1.Format("�û�����������������������룬������%d���������",flag);
		AfxMessageBox(str);
		continue;
	}
	}
	/*
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}*/
	
	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
//	return true;
}
