// BmpViewerView.cpp : CBmpViewerView 类的实现
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
//	ON_WM_LBUTTONUP()
//	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CBmpViewerView 构造/析构

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
	// TODO: 在此处通过修改 CREATESTRUCT cs 来修改窗口类或
	// 样式

	return CScrollView::PreCreateWindow(cs);
}

// CBmpViewerView 绘制

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
	// TODO: 计算此视图的合计大小
	sizeTotal.cx = sizeTotal.cy = 5000;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

// CBmpViewerView 打印

BOOL CBmpViewerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CBmpViewerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 打印前添加额外的初始化
}

void CBmpViewerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 打印后添加清除过程
}


// CBmpViewerView 诊断

#ifdef _DEBUG
void CBmpViewerView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CBmpViewerView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CBmpViewerDoc* CBmpViewerView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBmpViewerDoc)));
	return (CBmpViewerDoc*)m_pDocument;
}
#endif //_DEBUG


// CBmpViewerView 消息处理程序

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
