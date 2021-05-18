// BmpViewerDoc.cpp :  CBmpViewerDoc 类的实现
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


// CBmpViewerDoc 构造/析构

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

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CBmpViewerDoc 序列化

void CBmpViewerDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		m_bitmap.m_Load( *ar.GetFile() );
	}
}


// CBmpViewerDoc 诊断

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


// CBmpViewerDoc 命令

BOOL CBmpViewerDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;
/*
	static char BASED_CODE szFilter[] = "位图文件 (*.bmp)|*.bmp||";
	CFileDialog	fdlg(	TRUE,"*.bmp","*.bmp",
						OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,szFilter	);
	if( fdlg.DoModal() != IDOK ) return FALSE;
	if( m_bitmap.m_Load( fdlg.GetPathName() ) != 0 ) return FALSE;
*/
	return TRUE;
}