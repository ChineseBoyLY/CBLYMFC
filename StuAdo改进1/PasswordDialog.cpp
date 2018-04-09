// PasswordDialog.cpp : implementation file
//

#include "stdafx.h"
#include "StuAdo.h"
#include "StuAdoDlg.h"
#include "PasswordDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPasswordDialog dialog

extern CStuAdoApp theApp;

CPasswordDialog::CPasswordDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CPasswordDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPasswordDialog)
	m_pwd = _T("");
	m_user = _T("");
	//}}AFX_DATA_INIT
	/*
	m_pRecordset.CreateInstance(_uuidof(Recordset));
	try
	{
		m_pRecordset->Open( "SELECT * FROM t_login",theApp.m_pConnection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}
	*/
}


void CPasswordDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPasswordDialog)
	DDX_Text(pDX, IDC_PWD_EDIT, m_pwd);
	DDX_Text(pDX, IDC_USER_EDIT, m_user);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPasswordDialog, CDialog)
	//{{AFX_MSG_MAP(CPasswordDialog)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPasswordDialog message handlers


//DEL void CPasswordDialog::OnOK() 
//DEL {/*
//DEL 	UpdateData(true);
//DEL 	// TODO: Add extra validation here
//DEL 	int flag=3;
//DEL 	while(flag--){
//DEL 	CPasswordDialog m_dlg;
//DEL 	
//DEL 	m_dlg.DoModal();
//DEL 	if(m_dlg.DoModal() != IDOK)return ;
//DEL 	//����SQL�������
//DEL 	CString str="";
//DEL 	str.Format("�û��������벻��Ϊ��!������%d��������ᣡ",flag);
//DEL 	if(m_user == "" || m_pwd == "")
//DEL     {
//DEL 		AfxMessageBox(str);
//DEL 		continue;
//DEL     }
//DEL 	CString strSql;
//DEL 	strSql.Format("select userName,pwd from t_login where userName = '%s'",m_user);
//DEL 	//����
//DEL 	BSTR bsSql = strSql.AllocSysString();
//DEL 	m_pRecordset.CreateInstance(_uuidof(Recordset));
//DEL 	try
//DEL 	{
//DEL 		m_pRecordset->Open(bsSql,theApp.m_pConnection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
//DEL 	}
//DEL 	catch(_com_error *e)
//DEL 	{
//DEL 		AfxMessageBox(e->ErrorMessage());
//DEL 	}
//DEL //====================================================================
//DEL 	_variant_t var;
//DEL 	CString strName,strPwd; 
//DEL     strPwd=strName="";
//DEL     try
//DEL     {
//DEL 		if(!m_pRecordset->BOF)    
//DEL 			m_pRecordset->MoveFirst();
//DEL 		else
//DEL 		{
//DEL 			AfxMessageBox("�����ڸ��û�����");
//DEL 			continue;
//DEL 		}
//DEL 		while(!m_pRecordset->adoEOF)
//DEL 		{
//DEL 			var=m_pRecordset->GetCollect("userName");
//DEL 			if(var.vt!=VT_NULL)
//DEL 				strName = (LPCSTR)_bstr_t(var);
//DEL 			var=m_pRecordset->GetCollect("pwd");
//DEL 			if(var.vt!=VT_NULL)
//DEL 				strPwd = (LPCSTR)_bstr_t(var);
//DEL 			m_pRecordset->MoveNext();
//DEL 		}
//DEL 	}
//DEL 	catch(_com_error *e)
//DEL 	{
//DEL 		AfxMessageBox(e->ErrorMessage());
//DEL 	}
//DEL 	
//DEL 	if(m_pwd==strPwd)
//DEL 	{
//DEL 		CStuAdoDlg dlg;
//DEL 		dlg.DoModal();
//DEL 	}
//DEL 	else
//DEL 	{
//DEL 		CString str1="";
//DEL 		str1.Format("�û�����������������������룬������%d���������",flag);
//DEL 		AfxMessageBox(str);
//DEL 		continue;
//DEL 	}
//DEL 	}*/
//DEL 	CDialog::OnOK();
//DEL }

//DEL void CPasswordDialog::OnCancel() 
//DEL {
//DEL 	// TODO: Add extra cleanup here
//DEL 	
//DEL 	CDialog::OnCancel();
//DEL }
