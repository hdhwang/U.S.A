#pragma once
#include "afxwin.h"


// CDriveDlg 대화 상자입니다.

class CDriveDlg : public CDialog
{
	DECLARE_DYNAMIC(CDriveDlg)

public:
	CDriveDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDriveDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CComboBox c_SelectDrive;
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClicked1();
};
