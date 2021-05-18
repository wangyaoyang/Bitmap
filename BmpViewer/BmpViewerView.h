// BmpViewerView.h : CBmpViewerView 类的接口
//


#pragma once


class CBmpViewerView : public CScrollView
{
protected: // 仅从序列化创建
	CBmpViewerView();
	DECLARE_DYNCREATE(CBmpViewerView)

// 属性
public:
	CBmpViewerDoc* GetDocument() const;

// 操作
public:

// 重写
	public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 构造后第一次调用
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CBmpViewerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
private:
	CSize		m_Origin;
	CRect		m_rectColor;
	COLORREF	m_curColor;
	bool		m_bCaptured;
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // BmpViewerView.cpp 的调试版本
inline CBmpViewerDoc* CBmpViewerView::GetDocument() const
   { return reinterpret_cast<CBmpViewerDoc*>(m_pDocument); }
#endif

