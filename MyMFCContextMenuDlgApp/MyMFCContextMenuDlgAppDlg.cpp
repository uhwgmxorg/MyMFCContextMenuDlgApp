
// MyMFCContextMenuDlgAppDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MyMFCContextMenuDlgApp.h"
#include "MyMFCContextMenuDlgAppDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMyMFCContextMenuDlgAppDlg dialog



CMyMFCContextMenuDlgAppDlg::CMyMFCContextMenuDlgAppDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MYMFCCONTEXTMENUDLGAPP_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyMFCContextMenuDlgAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMyMFCContextMenuDlgAppDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_POPUP_MENUEITEM01, &CMyMFCContextMenuDlgAppDlg::OnPopupMenueitem01)
	ON_COMMAND(ID_POPUP_MENUEITEM02, &CMyMFCContextMenuDlgAppDlg::OnPopupMenueitem02)
END_MESSAGE_MAP()


// CMyMFCContextMenuDlgAppDlg message handlers

BOOL CMyMFCContextMenuDlgAppDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMyMFCContextMenuDlgAppDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMyMFCContextMenuDlgAppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//------------------------------/
//-       Menue Events         -/
//------------------------------/
#pragma region Menue Events 

/// <summary>
/// OnPopupMenueitem01
/// </summary>
void CMyMFCContextMenuDlgAppDlg::OnPopupMenueitem01()
{
	TRACE(_T("OnPopupMenueitem01\n"));

}

/// <summary>
/// OnPopupMenueitem02
/// </summary>
void CMyMFCContextMenuDlgAppDlg::OnPopupMenueitem02()
{
	TRACE(_T("OnPopupMenueitem02\n"));
}

#pragma endregion

//------------------------------/
//-       Other Events         -/
//------------------------------/
#pragma region My Other Events

/// <summary>
/// OnContextMenu
/// </summary>
/// <param name=""></param>
/// <param name=""></param>
void CMyMFCContextMenuDlgAppDlg::OnContextMenu(CWnd* pWnd, CPoint point)
{

	// Load the desired menu
	CMenu mnuPopupSubmit;
	mnuPopupSubmit.LoadMenu(IDR_SUBMIT);

	// Get a pointer to the first item of the menu
	CMenu* mnuPopupMenu = mnuPopupSubmit.GetSubMenu(0);
	ASSERT(mnuPopupMenu);

	mnuPopupMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);

	// Check the LastError
	DWORD dwerr = GetLastError();
	// Get the last Error in text
	wchar_t buf[256];
	FormatMessageW(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL, dwerr, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		buf, (sizeof(buf) / sizeof(wchar_t)), NULL);
	TRACE(_T("LastError %u %s"), dwerr, buf);

	TRACE(_T("OnContextMenu\n"));
}

#pragma endregion