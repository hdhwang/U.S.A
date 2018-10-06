#pragma once
#include "afxwin.h"


// PidSidDlg 대화 상자입니다.

class PidSidDlg : public CDialog
{
	DECLARE_DYNAMIC(PidSidDlg)

public:
	PidSidDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~PidSidDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
