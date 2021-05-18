// BmpViewerDoc.h :  CBmpViewerDoc ��Ľӿ�
//


#pragma once

#include "..\BitmapDecoder.h"
class CBmpViewerDoc : public CDocument
{
protected: // �������л�����
	CBmpViewerDoc();
	DECLARE_DYNCREATE(CBmpViewerDoc)

// ����
public:

// ����
public:

// ��д
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~CBmpViewerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
private:
	CBitmapDecoder	m_bitmap;
public:
	CBitmapDecoder&	m_GetBitmap() { return m_bitmap; }
};


