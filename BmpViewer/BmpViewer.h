// BmpViewer.h : BmpViewer Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error �ڰ������� PCH �Ĵ��ļ�֮ǰ������stdafx.h�� 
#endif

#include "resource.h"       // ������


// CBmpViewerApp:
// �йش����ʵ�֣������ BmpViewer.cpp
//

class CBmpViewerApp : public CWinApp
{
public:
	CBmpViewerApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CBmpViewerApp theApp;
