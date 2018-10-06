// PidSidDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "U.S.A.h"
#include "PidSidDlg.h"
#include "afxdialogex.h"


// PidSidDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(PidSidDlg, CDialog)
CString Source(_T(""));


PidSidDlg::~PidSidDlg()
{
}

void PidSidDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_COMBO1, c_SelectDrive);
	DDX_Text(pDX, IDC_EDIT_VID, ViewVID);
	DDX_Text(pDX, IDC_EDIT_PID, ViewPID);
	DDX_Text(pDX, IDC_EDIT_USBTool, ViewTool);
	CString USBTool(_T("Unknown"));
	CString VID(_T("0x"));
	CString PID(_T("0x"));
	
	DWORD dwType = REG_SZ;
	DWORD dwSize = 128;
	HKEY hKey;
	TCHAR szBuffer[128] = {'\0' ,};

	LONG lResult = RegOpenKeyEx(HKEY_LOCAL_MACHINE , _T("SYSTEM\\CurrentControlSet\\services\\USBSTOR\\Enum") , 0 , KEY_READ , &hKey);
	if(ERROR_SUCCESS == lResult){
		RegQueryValueEx(hKey , _T("0") , NULL , &dwType , (LPBYTE)szBuffer , &dwSize);
	}

	for(int i=0; i<4 ; i++){
		VID += szBuffer[8+i];
		PID += szBuffer[17+i];
	}
	if(VID==_T("0x") || PID==_T("0x")){
		VID = _T("Unknown");
		PID = _T("Unknown");
	}

	if(PID == _T("0x1000") || PID == _T("0x0163") || PID == _T("0x0165")){
		USBTool=_T("USBEST CONTROLLER");
		Source=(_T("http://hdhwang.tistory.com/attachment/cfile5.uf@233B894856D52AED1B8CB4.zip"));	
	}

	else if(PID == _T("0x1000") || PID == _T("0xBC06") || PID == _T("0x70D4")){
		USBTool=_T("SMI CONTROLLER");
		Source=(_T("http://hdhwang.tistory.com/attachment/cfile6.uf@26243B4856D52AE52B68AA.zip"));	
	}

	else if(PID == _T("0x2168")){
		USBTool=_T("OTI CONTROLLER");
		Source=(_T("http://hdhwang.tistory.com/attachment/cfile4.uf@212C1B4856D52AD924509E.rar"));
	}

	else if(PID == _T("0x1603")){
		USBTool=_T("Skymedi CONTROLLER");
		Source=(_T("http://hdhwang.tistory.com/attachment/cfile26.uf@2736054856D52ADA1F3B66.rar"));
	}

	if (Source == _T("")) {
		GetDlgItem(1)->EnableWindow(FALSE);
	}

	SetDlgItemText(IDC_EDIT_VID,VID);
	SetDlgItemText(IDC_EDIT_PID,PID);
	SetDlgItemText(IDC_EDIT_USBTool,USBTool);
	DDX_Control(pDX, 1, download);
}


BEGIN_MESSAGE_MAP(PidSidDlg, CDialog)
	ON_BN_CLICKED(IDOK, &PidSidDlg::OnBnClickedOk)
	ON_CBN_SELCHANGE(IDC_COMBO1, &PidSidDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(1, &PidSidDlg::OnBnClicked1)
END_MESSAGE_MAP()


// PidSidDlg 메시지 처리기입니다.

void PidSidDlg::OnCbnSelchangeCombo1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.


}


void PidSidDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	//CDialog::OnOK();
	ShellExecute(m_hWnd, _T("open"), Source, NULL, NULL, SW_SHOW);


}

PidSidDlg::PidSidDlg(CWnd* pParent /*=NULL*/)
	: CDialog(PidSidDlg::IDD, pParent)
	, ViewVID(_T(""))
	, ViewPID(_T(""))
	, ViewTool(_T(""))
{
}

void PidSidDlg::OnBnClicked1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
