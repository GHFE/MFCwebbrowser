
// MFCWEBDlg.h : 头文件
//

#pragma once
#include "explorer1.h"
#include "afxwin.h"


// CMFCWEBDlg 对话框
class CMFCWEBDlg : public CDialogEx
{
// 构造
public:
	CMFCWEBDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFCWEB_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnInputAddress();
	DECLARE_MESSAGE_MAP()
public:
	CExplorer1 iee;
	afx_msg void OnBnClickedButton1();
	CString m_url;
	CEdit m_edit;
	DECLARE_EVENTSINK_MAP()
	void OnNewwindow3Explorer1(LPDISPATCH* ppDisp, BOOL* Cancel, unsigned long dwFlags, LPCTSTR bstrUrlContext, LPCTSTR bstrUrl);
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton5();
//	void OnDownloadcompleteExplorer1();
//	void OnDocumentcompleteExplorer1(LPDISPATCH pDisp, VARIANT* URL);
	//void SetURL(LPCTSTR lpszURL);
	//LPCTSTR lpszURL;
	//afx_msg void OnSize(UINT nType, int cx, int cy);
	void ReSize(void);
	POINT old;
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
