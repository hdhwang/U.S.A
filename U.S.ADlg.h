
// U.S.ADlg.h : ��� ����
//

#pragma once
#include "afxwin.h"


// CUSADlg ��ȭ ����
class CUSADlg : public CDialogEx
{
// �����Դϴ�.
public:
	CUSADlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_USA_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CBitmapButton image1;
	CBitmapButton image2;
	CBitmapButton image3;
	CBitmapButton image4;
	CBitmapButton UsbWritable;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
};
