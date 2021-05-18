// BmpViewerDoc.cpp :  CBmpViewerDoc ���ʵ��
//

#include "stdafx.h"
#include "BmpViewer.h"

#include "BmpViewerDoc.h"
#include ".\bmpviewerdoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBmpViewerDoc

IMPLEMENT_DYNCREATE(CBmpViewerDoc, CDocument)

BEGIN_MESSAGE_MAP(CBmpViewerDoc, CDocument)
END_MESSAGE_MAP()


// CBmpViewerDoc ����/����

CBmpViewerDoc::CBmpViewerDoc()
{
}

CBmpViewerDoc::~CBmpViewerDoc()
{
}

BOOL CBmpViewerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CBmpViewerDoc ���л�

void CBmpViewerDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		m_bitmap.m_Load( *ar.GetFile() );
	}
}


// CBmpViewerDoc ���

#ifdef _DEBUG
void CBmpViewerDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CBmpViewerDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CBmpViewerDoc ����

BOOL CBmpViewerDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;
/*
	static char BASED_CODE szFilter[] = "λͼ�ļ� (*.bmp)|*.bmp||";
	CFileDialog	fdlg(	TRUE,"*.bmp","*.bmp",
						OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,szFilter	);
	if( fdlg.DoModal() != IDOK ) return FALSE;
	if( m_bitmap.m_Load( fdlg.GetPathName() ) != 0 ) return FALSE;
*/
	return TRUE;
}