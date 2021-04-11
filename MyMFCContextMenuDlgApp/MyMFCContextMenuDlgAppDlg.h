
// MyMFCContextMenuDlgAppDlg.h : header file
//

#pragma once


// CMyMFCContextMenuDlgAppDlg dialog
class CMyMFCContextMenuDlgAppDlg : public CDialogEx
{
// Construction
public:
	CMyMFCContextMenuDlgAppDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MYMFCCONTEXTMENUDLGAPP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnPopupMenueitem01();
	afx_msg void OnPopupMenueitem02();
};
