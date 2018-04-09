// lab5Doc.cpp : implementation of the CLab5Doc class
//

#include "stdafx.h"
#include "lab5.h"

#include "lab5Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLab5Doc

IMPLEMENT_DYNCREATE(CLab5Doc, CDocument)

BEGIN_MESSAGE_MAP(CLab5Doc, CDocument)
	//{{AFX_MSG_MAP(CLab5Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLab5Doc construction/destruction

CLab5Doc::CLab5Doc()
{
	// TODO: add one-time construction code here
	for(int i=0;i<40;i++)
	{
		m_student[i].name[0]=NULL;
		m_student[i].sex[0]=NULL;
		m_student[i].age=NULL;
		m_student[i].tel[0]=NULL;
		m_student[i].school[0]=NULL;
	}

}

CLab5Doc::~CLab5Doc()
{
}

BOOL CLab5Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CLab5Doc serialization

void CLab5Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		for(int i=0;i<40;i++)
		{
			ar.Write(m_student[i].name,10);
			ar.Write(m_student[i].sex,3);
			ar<<m_student[i].age;
			ar.Write(m_student[i].tel,14);
			ar.Write(m_student[i].school,30);
		}
	}
	else
	{
		// TODO: add loading code here
		for(int i=0;i<40;i++)
		{
			ar.Read(m_student[i].name,10);
			ar.Read(m_student[i].sex,3);
			ar>>m_student[i].age;
			ar.Read(m_student[i].tel,14);
			ar.Read(m_student[i].school,30);
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
// CLab5Doc diagnostics

#ifdef _DEBUG
void CLab5Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CLab5Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLab5Doc commands
