// PasswordDialog.cpp : implementation file
//

#include "stdafx.h"
#include "lab4.h"
#include "PasswordDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPasswordDialog dialog


CPasswordDialog::CPasswordDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CPasswordDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPasswordDialog)
	m_password = _T("");
	//}}AFX_DATA_INIT
}


void CPasswordDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPasswordDialog)
	DDX_Text(pDX, IDC_PASSWORD_EDIT, m_password);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPasswordDialog, CDialog)
	//{{AFX_MSG_MAP(CPasswordDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPasswordDialog message handlers
