================================================================================
    MICROSOFT 基础类库： BmpViewer 项目概述
===============================================================================

应用程序向导已为您创建了此 BmpViewer 应用程序。此应用程序
不仅介绍了使用 Microsoft 基础类的基本知识，
而且是编写应用程序的起点。

此文件包含组成 BmpViewer 应用程序的每个文件的内容摘要。

BmpViewer.vcproj
    这是使用“应用程序向导”生成的 VC++ 项目的主项目文件。 
    它包含有关生成文件的 Visual C++ 版本的信息，以及
    有关用“应用程序向导”所选择的平台、配置和
    项目功能的信息。

BmpViewer.h
    这是应用程序的主头文件。  它包含其他
    项目特定的头文件（包括 Resource.h），并声明
    CBmpViewerApp 应用程序类。

BmpViewer.cpp
    这是包含应用程序
    类 CBmpViewerApp 的主应用程序源文件。

BmpViewer.rc
    这是程序使用的所有 Microsoft Windows 资源
    的列表。  它包含存储在 RES 子目录中
    的图标、位图和光标。  可直接在 Microsoft 
    Visual C++ 中编辑此文件。 项目资源包含在 2052 中。

res\BmpViewer.ico
    这是一个图标文件，用作应用程序的图标。  此
    图标包含在主资源文件 BmpViewer.rc 中。

res\BmpViewer.rc2
    此文件包含不由 Microsoft 
    Visual C++ 编辑的资源。 应将所有不能由
    资源编辑器编辑的资源放在此文件中。
BmpViewer.reg
    这是一个 .REG 文件示例，向您显示
    框架将为您设置的注册设置类型。  可以将它用作 .REG
    文件，以与应用程序一起使用，或干脆删除它而依赖
    默认的 RegisterShellFileTypes 注册。
/////////////////////////////////////////////////////////////////////////////

对于主框架窗口：
    项目将包含标准的 MFC 界面。
MainFrm.h, MainFrm.cpp
    这些文件包含框架类 CMainFrame，该类派生自
    CMDIFrameWnd 并控制所有的 MDI 框架功能。
res\Toolbar.bmp
    此位图文件用于创建工具栏的平铺图像。
    初始工具栏和状态栏在 CMainFrame 
    类中构造。 使用资源编辑器编辑此工具栏位图，并
    更新 BmpViewer.rc 中的 IDR_MAINFRAME TOOLBAR 数组以添加
    工具栏按钮。
/////////////////////////////////////////////////////////////////////////////

对于子框架窗口：

ChildFrm.h、ChildFrm.cpp
    这些文件定义和实现 CChildFrame 类，此类
    支持 MDI 应用程序中的子窗口。

/////////////////////////////////////////////////////////////////////////////

应用程序向导将创建一种文档类型和一个视图：

BmpViewerDoc.h、BmpViewerDoc.cpp - 文档
    这些文件包含 CBmpViewerDoc 类。  编辑这些文件
    以添加特殊的文档数据并实现文件的保存和加载
    （通过 CBmpViewerDoc::Serialize）。
    此文档将具有下列字符串：
        文件扩展名：      BMP
        文件类型 ID：        BmpViewer.Document
        主框架标题：  Bitmap Viewer
        文档类型名称：       Bitmap
        筛选器名称：         Bitmap Files (*.BMP)
        文件的新简称： BmpViewer
        文件类型全称： BmpViewer.Document
BmpViewerView.h、BmpViewerView.cpp - 文档视图
    这些文件包含 CBmpViewerView 类。
    CBmpViewerView 对象用于查看 CBmpViewerDoc 对象。
res\BmpViewerDoc.ico
    这是一个图标文件，用作 
    CBmpViewerDoc 类 MDI 子窗口的图标。  此图标包含在主
    资源文件 BmpViewer.rc 中。
/////////////////////////////////////////////////////////////////////////////

其他功能：

ActiveX 控件
    应用程序支持使用 ActiveX 控件。

打印支持和打印预览支持
    应用程序向导已生成了一些代码，通过从 MFC 库调用 CView 类中的成员函数来
    处理打印、打印设置和打印预览命令。
/////////////////////////////////////////////////////////////////////////////

其他标准文件：

StdAfx.h、StdAfx.cpp
    这些文件用于生成名为 BmpViewer.pch 的预编译头文件 (PCH)
    和名为 StdAfx.obj 的预编译类型文件。

Resource.h
    这是标准头文件，它定义新资源 ID。
    Microsoft Visual C++ 将读取并更新此文件。

/////////////////////////////////////////////////////////////////////////////

其他说明：

应用程序向导使用“TODO:” 来指示
应添加或自定义的源代码部分。

如果应用程序在共享 DLL 中使用 MFC，且应用程序使用的语言不是
操作系统的当前语言，则需要从 Microsoft Visual C++ 光盘上 
Win\System 目录下将相应的本地化资源 MFC70XXX.DLL 
复制到计算机的 system 或 system32 目录下，
并将其重命名为 MFCLOC.DLL。  （“XXX”代表
语言缩写。  例如，MFC70DEU.DLL 包含翻译成
德语的资源。）  如果不这样做，应用程序的某些 UI 元素
将保留为操作系统的语言。

/////////////////////////////////////////////////////////////////////////////
