
// calculator_projectDlg.h: 헤더 파일
//

#pragma once

//클래스내부에멤버변수선언
// CcalculatorprojectDlg 대화 상자
class CcalculatorprojectDlg : public CDialogEx
{
// 생성입니다.
public:
	CcalculatorprojectDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	enum Math m_select;//사칙연산선택
	int m_First;
	int m_Second;
	int m_Result;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR_PROJECT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	CString m_Finish;
	afx_msg void OnBnClickedButtonPlus();
	afx_msg void OnBnClickedButtonMin();
	afx_msg void OnBnClickedButtonMul();
	afx_msg void OnBnClickedButtonDiv();
	afx_msg void OnBnClickedButtonEnd();
	afx_msg void OnBnClickedButtonReset();
	afx_msg void OnEnChangeEdit1();
};
