
// MFCWEBDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCWEB.h"
#include "MFCWEBDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCWEBDlg �Ի���



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


// CMFCWEBDlg ��Ϣ�������

BOOL CMFCWEBDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��
	CRect rect;
	GetClientRect(&rect);     //ȡ�ͻ�����С    
	old.x = rect.right - rect.left;
	old.y = rect.bottom - rect.top;
	int cx = GetSystemMetrics(SM_CXFULLSCREEN);
	int cy = GetSystemMetrics(SM_CYFULLSCREEN);
	CRect rt;
	SystemParametersInfo(SPI_GETWORKAREA, 0, &rt, 0);
	cx = rt.right;
	cy = rt.bottom;
	MoveWindow(0, 0, cx, cy);

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	iee.Navigate(L"www.baidu.com", NULL, NULL, NULL, NULL);
	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCWEBDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFCWEBDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCWEBDlg::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
	// TODO:  �ڴ˴������Ϣ����������
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	iee.GoForward();
}


void CMFCWEBDlg::OnBnClickedButton4()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	iee.GoHome();
	
}


void CMFCWEBDlg::OnBnClickedButton2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	iee.GoBack();
}


void CMFCWEBDlg::OnBnClickedButton5()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	iee.Refresh();
}


//void CMFCWEBDlg::OnDownloadcompleteExplorer1()
//{
//	// TODO:  �ڴ˴������Ϣ����������
//	((CMainFrame *)GetParentFrame())->SetURL(lpszURL);
//	GetDocument()->SetTitle(lpszURL);
//}

//
//void CMFCWEBDlg::OnDocumentcompleteExplorer1(LPDISPATCH pDisp, VARIANT* URL)
//{
//	// TODO:  �ڴ˴������Ϣ����������
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
	POINT Newp; //��ȡ���ڶԻ���Ĵ�С
	CRect recta;
	GetClientRect(&recta);     //ȡ�ͻ�����С  
	Newp.x = recta.right - recta.left;
	Newp.y = recta.bottom - recta.top;
	fsp[0] = (float)Newp.x / old.x;
	fsp[1] = (float)Newp.y / old.y;
	CRect Rect;
	int woc;
	CPoint OldTLPoint, TLPoint; //���Ͻ�
	CPoint OldBRPoint, BRPoint; //���½�
	
	HWND  hwndChild = ::GetWindow(m_hWnd, GW_CHILD);  //�г����пؼ�  
	while (hwndChild)
	{
		woc = ::GetDlgCtrlID(hwndChild);//ȡ��ID
		GetDlgItem(woc)->GetWindowRect(Rect);
		ScreenToClient(Rect);
		//OldTLPoint = Rect.TopLeft();
		//TLPoint.x = long(OldTLPoint.x*fsp[0]);
		//TLPoint.y = long(OldTLPoint.y*fsp[1]);
		//OldBRPoint = Rect.BottomRight();
		//BRPoint.x = long(OldBRPoint.x *fsp[0]);
		//BRPoint.y = long(OldBRPoint.y *fsp[1]);
		//Rect.SetRect(TLPoint, BRPoint);
		Rect.left = Rect.left*fsp[0];  //���ձ��������ռ����λ��
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
	// TODO:  �ڴ˴������Ϣ����������
}
