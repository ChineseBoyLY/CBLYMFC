// lab8Set.cpp : implementation of the CLab8Set class
//

#include "stdafx.h"
#include "lab8.h"
#include "lab8Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLab8Set implementation

IMPLEMENT_DYNAMIC(CLab8Set, CRecordset)

CLab8Set::CLab8Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CLab8Set)
	m_column1 = _T("");
	m_column2 = _T("");
	m_column3 = _T("");
	m_column4 = _T("");
	m_column5 = _T("");
	m_nFields = 5;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}

CString CLab8Set::GetDefaultConnect()
{
	return _T("ODBC;DSN=MS Access Database");
}

CString CLab8Set::GetDefaultSQL()
{
	return _T("[Table1]");
}

void CLab8Set::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CLab8Set)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[编号]"), m_column1);
	RFX_Text(pFX, _T("[名称]"), m_column2);
	RFX_Text(pFX, _T("[演唱]"), m_column3);
	RFX_Text(pFX, _T("[作者]"), m_column4);
	RFX_Text(pFX, _T("[位置]"), m_column5);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CLab8Set diagnostics

#ifdef _DEBUG
void CLab8Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CLab8Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
