// DriveDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "U.S.A.h"
#include "DriveDlg.h"
#include "afxdialogex.h"
CString seldrive=_T("empty");

// CDriveDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDriveDlg, CDialog)

CDriveDlg::CDriveDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDriveDlg::IDD, pParent)
{

}

CDriveDlg::~CDriveDlg()
{
}

void CDriveDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, c_SelectDrive);
 
	CString strDrive;    // 논리적 드라이브명 임시 저장
	TCHAR pTmp[256];
	memset(pTmp, '\0', 256);
	GetLogicalDriveStrings(256, pTmp);
	
	for(int i=0 ; i<256 ; i++) {
		if(pTmp[i] == '\0' && pTmp[i+1] == '\0')
		break;
		
		strDrive.Empty();
		
		while(pTmp[i] != '\0')
			strDrive += pTmp[i++];
		
		if(GetDriveType(strDrive) == DRIVE_REMOVABLE || GetDriveType(strDrive) == DRIVE_FIXED) {
			c_SelectDrive.AddString(strDrive);
			if(strcmp((LPSTR)(LPCTSTR)seldrive,"empty")==0){
				seldrive = strDrive;
			}
		}
	}
	c_SelectDrive.SetCurSel(0);


}


BEGIN_MESSAGE_MAP(CDriveDlg, CDialog)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CDriveDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(1, &CDriveDlg::OnBnClicked1)
END_MESSAGE_MAP()


// CDriveDlg 메시지 처리기입니다.


void CDriveDlg::OnCbnSelchangeCombo1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int curSel=c_SelectDrive.GetCurSel();
	//콤보 박스의 해당 인덱스 위치의 항목 값을 얻어온다.
	c_SelectDrive.GetLBText(curSel, seldrive);
	


}


void CDriveDlg::OnBnClicked1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	char* pszBuffer = "Anti Autorun Virus Success!!         - Created by U.S.A";
	CFile File(seldrive+_T("autorun.inf"),
	CFile::modeCreate |  CFile::modeReadWrite);
	File.Write(pszBuffer, strlen(pszBuffer));
	File.Close();

	CFileStatus status;
	CFile::GetStatus(seldrive+_T("autorun.inf"), status);    // 먼저 파일의 상태값을 가져옵니다.
	status.m_attribute =CFile::readOnly | CFile::hidden | CFile::system;// 속성을 지정합니다.
	CFile::SetStatus(seldrive+_T("autorun.inf"), status);    // 파일에 상태값을 저장합니다.

	//icacls를 이용하여 모든 사용자에게 autorun.inf 파일 접근 권한을 읽기로 변경 (NTFS 파일시스템에서만 가능)
	CString icaclsParm = seldrive + _T("autorun.inf /deny Everyone:RX");
	SHELLEXECUTEINFO sei;
	ZeroMemory(&sei, sizeof(SHELLEXECUTEINFO));
	sei.cbSize = sizeof(SHELLEXECUTEINFO);
	sei.lpFile = __TEXT("icacls");
	sei.lpParameters = icaclsParm;
	sei.nShow = SW_HIDE;
	sei.fMask = SEE_MASK_NOCLOSEPROCESS;
	sei.lpVerb = _T("Open");
	ShellExecuteEx(&sei);
	WaitForSingleObject(sei.hProcess, INFINITE);



	MessageBox(seldrive+(_T("를 Autorun Virus로부터 방지합니다.")),
			  _T("성공"),
			  MB_OK|MB_ICONINFORMATION
	);
	CDialog::OnOK();
	
}
