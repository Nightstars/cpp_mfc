
// cpp_mfcView.cpp: CcppmfcView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "cpp_mfc.h"
#endif

#include "cpp_mfcDoc.h"
#include "cpp_mfcView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CcppmfcView

IMPLEMENT_DYNCREATE(CcppmfcView, CView)

BEGIN_MESSAGE_MAP(CcppmfcView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CcppmfcView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CcppmfcView 构造/析构

CcppmfcView::CcppmfcView() noexcept
{
	// TODO: 在此处添加构造代码

}

CcppmfcView::~CcppmfcView()
{
}

BOOL CcppmfcView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CcppmfcView 绘图

void CcppmfcView::OnDraw(CDC* /*pDC*/)
{
	CcppmfcDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CcppmfcView 打印


void CcppmfcView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CcppmfcView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CcppmfcView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CcppmfcView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CcppmfcView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CcppmfcView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CcppmfcView 诊断

#ifdef _DEBUG
void CcppmfcView::AssertValid() const
{
	CView::AssertValid();
}

void CcppmfcView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CcppmfcDoc* CcppmfcView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CcppmfcDoc)));
	return (CcppmfcDoc*)m_pDocument;
}
#endif //_DEBUG


// CcppmfcView 消息处理程序
