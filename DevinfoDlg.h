#pragma once


// CDevinfoDlg ��ȭ �����Դϴ�.

class CDevinfoDlg : public CDialog
{
	DECLARE_DYNAMIC(CDevinfoDlg)

public:
	CDevinfoDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDevinfoDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
