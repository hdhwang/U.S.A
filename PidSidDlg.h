#pragma once
#include "afxwin.h"


// PidSidDlg ��ȭ �����Դϴ�.

class PidSidDlg : public CDialog
{
	DECLARE_DYNAMIC(PidSidDlg)

public:
	PidSidDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~PidSidDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CComboBox c_SelectDrive;
	afx_msg void OnCbnSelchangeCombo1();
	CString ViewVID;
	CString ViewPID;
	CString ViewTool;
	afx_msg void OnBnClicked1();
	CButton download;
};
