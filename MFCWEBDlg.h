
// MFCWEBDlg.h : ͷ�ļ�
//

#pragma once
#include "explorer1.h"
#include "afxwin.h"


// CMFCWEBDlg �Ի���
class CMFCWEBDlg : public CDialogEx
{
// ����
public:
	CMFCWEBDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFCWEB_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
