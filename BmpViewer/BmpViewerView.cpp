// BmpViewerView.cpp : CBmpViewerView ���ʵ��
//

#include "stdafx.h"
#include "BmpViewer.h"

#include "BmpViewerDoc.h"
#include "BmpViewerView.h"
#include ".\bmpviewerview.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBmpViewerView

IMPLEMENT_DYNCREATE(CBmpViewerView, CScrollView)

BEGIN_MESSAGE_MAP(CBmpViewerView, CScrollView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
//	ON_WM_LBUTTONUP()
//	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CBmpViewerView ����/����

CBmpViewerView::CBmpViewerView()
:m_Origin(0,0)
{
	m_bCaptured = false;
	m_curColor = RGB(255,255,255);
	m_rectColor.SetRect( 0,0,0,0 );
}

CBmpViewerView::~CBmpViewerView()
{
}

BOOL CBmpViewerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸� CREATESTRUCT cs ���޸Ĵ������
	// ��ʽ

	return CScrollView::PreCreateWindow(cs);
}

// CBmpViewerView ����

void CBmpViewerView::OnDraw(CDC* pDC)
{
	CBmpViewerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CBitmapDecoder&	bitmap = pDoc->m_GetBitmap();
	CRect			clientRect;
	GetClientRect(	clientRect );
	LONG			width	= bitmap.m_GetWidth();
	LONG			height	= bitmap.m_GetHeight();
	CBrush			brush(m_curColor);
	bitmap.m_Show( pDC,clientRect,m_Origin );
	m_rectColor.SetRect( width,0,width+10,10 );
	pDC->FillRect(m_rectColor,&brush);
}

void CBmpViewerView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();
	CSize sizeTotal;
	// TODO: �������ͼ�ĺϼƴ�С
	sizeTotal.cx = sizeTotal.cy = 5000;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

// CBmpViewerView ��ӡ

BOOL CBmpViewerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CBmpViewerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��ӡǰ��Ӷ���ĳ�ʼ��
}

void CBmpViewerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��ӡ������������
}


// CBmpViewerView ���

#ifdef _DEBUG
void CBmpViewerView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CBmpViewerView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CBmpViewerDoc* CBmpViewerView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBmpViewerDoc)));
	return (CBmpViewerDoc*)m_pDocument;
}
#endif //_DEBUG


// CBmpViewerView ��Ϣ�������

void CBmpViewerView::OnLButtonDown(UINT nFlags, CPoint point)
{
	m_bCaptured = true;
	CBmpViewerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if( pDoc && m_bCaptured )
	{
		m_curColor = pDoc->m_GetBitmap().m_PickColor(point.x,point.y);
		InvalidateRect( CRect(point.x-1,point.y-1,point.x+1,point.y+1) );
		InvalidateRect( m_rectColor );
	}

	CScrollView::OnLButtonDown(nFlags, point);
}
