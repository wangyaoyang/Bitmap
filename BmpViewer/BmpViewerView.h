// BmpViewerView.h : CBmpViewerView ��Ľӿ�
//


#pragma once


class CBmpViewerView : public CScrollView
{
protected: // �������л�����
	CBmpViewerView();
	DECLARE_DYNCREATE(CBmpViewerView)

// ����
public:
	CBmpViewerDoc* GetDocument() const;

// ����
public:

// ��д
	public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ������һ�ε���
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CBmpViewerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
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

#ifndef _DEBUG  // BmpViewerView.cpp �ĵ��԰汾
inline CBmpViewerDoc* CBmpViewerView::GetDocument() const
   { return reinterpret_cast<CBmpViewerDoc*>(m_pDocument); }
#endif

