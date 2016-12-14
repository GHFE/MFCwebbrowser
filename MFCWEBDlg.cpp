
// MFCWEBDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCWEB.h"
#include "MFCWEBDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCWEBDlg 对话框



CMFCWEBDlg::CMFCWEBDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCWEBDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCWEBDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EXPLORER1, iee);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
}

BEGIN_MESSAGE_MAP(CMFCWEBDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCWEBDlg::OnBnClickedButton1)
	ON_COMMAND(IDOK, OnInputAddress)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCWEBDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCWEBDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCWEBDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCWEBDlg::OnBnClickedButton5)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CMFCWEBDlg 消息处理程序

BOOL CMFCWEBDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
	CRect rect;
	GetClientRect(&rect);     //取客户区大小    
	old.x = rect.right - rect.left;
	old.y = rect.bottom - rect.top;
	int cx = GetSystemMetrics(SM_CXFULLSCREEN);
	int cy = GetSystemMetrics(SM_CYFULLSCREEN);
	CRect rt;
	SystemParametersInfo(SPI_GETWORKAREA, 0, &rt, 0);
	cx = rt.right;
	cy = rt.bottom;
	MoveWindow(0, 0, cx, cy);

	// TODO:  在此添加额外的初始化代码
	iee.Navigate(L"www.baidu.com", NULL, NULL, NULL, NULL);
	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCWEBDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCWEBDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCWEBDlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	m_edit.GetWindowText(m_url);
	iee.Navigate(m_url, NULL, NULL, NULL, NULL);
	//m_edit.SetWindowText(m_url);
}
BEGIN_EVENTSINK_MAP(CMFCWEBDlg, CDialogEx)
	ON_EVENT(CMFCWEBDlg, IDC_EXPLORER1, 273, CMFCWEBDlg::OnNewwindow3Explorer1, VTS_PDISPATCH VTS_PBOOL VTS_UI4 VTS_BSTR VTS_BSTR)
//	ON_EVENT(CMFCWEBDlg, IDC_EXPLORER1, 104, CMFCWEBDlg::OnDownloadcompleteExplorer1, VTS_NONE)
//ON_EVENT(CMFCWEBDlg, IDC_EXPLORER1, 259, CMFCWEBDlg::OnDocumentcompleteExplorer1, VTS_DISPATCH VTS_PVARIANT)
END_EVENTSINK_MAP()


void CMFCWEBDlg::OnNewwindow3Explorer1(LPDISPATCH* ppDisp, BOOL* Cancel, unsigned long dwFlags, LPCTSTR bstrUrlContext, LPCTSTR bstrUrl)
{
	// TODO:  在此处添加消息处理程序代码
	*Cancel = TRUE;
	CString strUrl;
	strUrl = bstrUrl;
	VARIANT vInfo;
	VariantInit(&vInfo);
	this->iee.Navigate(strUrl, &vInfo, &vInfo, &vInfo, &vInfo);
	this->ShowWindow(SW_SHOW);
}
void CMFCWEBDlg::OnInputAddress()
{
	m_edit.GetWindowText(m_url);
	iee.Navigate(m_url, NULL, NULL, NULL, NULL);
	//m_edit.SetWindowText(m_url);

}


void CMFCWEBDlg::OnBnClickedButton3()
{
	// TODO:  在此添加控件通知处理程序代码
	iee.GoForward();
}


void CMFCWEBDlg::OnBnClickedButton4()
{
	// TODO:  在此添加控件通知处理程序代码
	iee.GoHome();
	
}


void CMFCWEBDlg::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码
	iee.GoBack();
}


void CMFCWEBDlg::OnBnClickedButton5()
{
	// TODO:  在此添加控件通知处理程序代码
	iee.Refresh();
}


//void CMFCWEBDlg::OnDownloadcompleteExplorer1()
//{
//	// TODO:  在此处添加消息处理程序代码
//	((CMainFrame *)GetParentFrame())->SetURL(lpszURL);
//	GetDocument()->SetTitle(lpszURL);
//}

//
//void CMFCWEBDlg::OnDocumentcompleteExplorer1(LPDISPATCH pDisp, VARIANT* URL)
//{
//	// TODO:  在此处添加消息处理程序代码
//	((CMFCWEBDlg *)GetParentFrame())->SetURL(lpszURL);
//		//::GetDocument()->SetTitle(lpszURL);
//}
//
//void CMFCWEBDlg::SetURL(LPCTSTR lpszURL)
//{
//	m_edit.GetDlgItem(IDC_EDIT1)->SetWindowText(lpszURL);
//
//}
//
void CMFCWEBDlg::ReSize(void)
{
	float fsp[2];
	POINT Newp; //获取现在对话框的大小
	CRect recta;
	GetClientRect(&recta);     //取客户区大小  
	Newp.x = recta.right - recta.left;
	Newp.y = recta.bottom - recta.top;
	fsp[0] = (float)Newp.x / old.x;
	fsp[1] = (float)Newp.y / old.y;
	CRect Rect;
	int woc;
	CPoint OldTLPoint, TLPoint; //左上角
	CPoint OldBRPoint, BRPoint; //右下角
	
	HWND  hwndChild = ::GetWindow(m_hWnd, GW_CHILD);  //列出所有控件  
	while (hwndChild)
	{
		woc = ::GetDlgCtrlID(hwndChild);//取得ID
		GetDlgItem(woc)->GetWindowRect(Rect);
		ScreenToClient(Rect);
		//OldTLPoint = Rect.TopLeft();
		//TLPoint.x = long(OldTLPoint.x*fsp[0]);
		//TLPoint.y = long(OldTLPoint.y*fsp[1]);
		//OldBRPoint = Rect.BottomRight();
		//BRPoint.x = long(OldBRPoint.x *fsp[0]);
		//BRPoint.y = long(OldBRPoint.y *fsp[1]);
		//Rect.SetRect(TLPoint, BRPoint);
		Rect.left = Rect.left*fsp[0];  //按照比例调整空间的新位置
		Rect.top = Rect.top*fsp[1];
		Rect.bottom = Rect.bottom*fsp[1];
		Rect.right = Rect.right*fsp[0];

		GetDlgItem(woc)->MoveWindow(Rect, TRUE);
		hwndChild = ::GetWindow(hwndChild, GW_HWNDNEXT);
	}
	old = Newp;
}



void CMFCWEBDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);
	ReSize();
	// TODO:  在此处添加消息处理程序代码
}
