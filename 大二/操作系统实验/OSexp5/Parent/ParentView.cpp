// ParentView.cpp : implementation of the CParentView class
//
#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<process.h>
#include "stdafx.h"
#include "Parent.h"

#include "ParentDoc.h"
#include "ParentView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
HANDLE hPipe;
/////////////////////////////////////////////////////////////////////////////
// CParentView

IMPLEMENT_DYNCREATE(CParentView, CView)

BEGIN_MESSAGE_MAP(CParentView, CView)
	//{{AFX_MSG_MAP(CParentView)
	ON_COMMAND(ID_Pipe_CREATE, OnPipeCREATE)
	ON_COMMAND(ID_Pipe_READ, OnPipeREAD)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CParentView construction/destruction

CParentView::CParentView()
{
	// TODO: add construction code here

}

CParentView::~CParentView()
{
}

BOOL CParentView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CParentView drawing

void CParentView::OnDraw(CDC* pDC)
{
	CParentDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CParentView printing

BOOL CParentView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CParentView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CParentView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CParentView diagnostics

#ifdef _DEBUG
void CParentView::AssertValid() const
{
	CView::AssertValid();
}

void CParentView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CParentDoc* CParentView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CParentDoc)));
	return (CParentDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CParentView message handlers

void CParentView::OnPipeCREATE() 
{
	// TODO: Add your command handler code here
	hPipe=CreateNamedPipe("\\\\.\\pipe\\NamedPipe",                            //���������ܵ�
	PIPE_ACCESS_DUPLEX | FILE_FLAG_OVERLAPPED,0,1,1024,1024,0,NULL);
	if(hPipe == INVALID_HANDLE_VALUE) {                   //���������ܵ�ʧ�ܱ���
		MessageBox("���������ܵ�ʧ��!");
		return;
	}
	STARTUPINFO sui;
	PROCESS_INFORMATION pi;
	ZeroMemory(&sui, sizeof(STARTUPINFO));
	sui.cb = sizeof(STARTUPINFO);
	sui.dwFlags = STARTF_USESTDHANDLES;
	sui.hStdInput = hPipe;
	sui.hStdOutput = hPipe;
	sui.hStdError = GetStdHandle(STD_ERROR_HANDLE);
	if (!CreateProcess("C:/Users/Administrator/Desktop/OSexp5/Child/Debug/Child.exe", NULL, NULL, NULL, TRUE, 0, NULL, NULL, &sui, &pi)) {          //�����ӽ���
		CloseHandle(hPipe);
		hPipe = NULL;
		MessageBox("�����ӽ���ʧ��!");
		return ;
	} 
}

void CParentView::OnPipeREAD() 
{
	// TODO: Add your command handler code here
	char buf[100];
	DWORD dwRead;
	if (!ReadFile(hPipe, buf, 100, &dwRead, NULL)) {            //�������ܵ���ȡ����
		MessageBox("��ȡ����ʧ�ܣ�");
		return ;
	}
	MessageBox(buf);
}

//DEL void CParentView::OnPipeWRITE() 
//DEL {
//DEL 	// TODO: Add your command handler code here
//DEL 	char buf[] = "��ã����Ǹ�����";
//DEL 	DWORD dwWrite;
//DEL 	if (!WriteFile(hPipe, buf, strlen(buf) + 1, &dwWrite, NULL)) {
//DEL 		MessageBox("д������ʧ��!");
//DEL 		return ;
//DEL 	}
//DEL }
