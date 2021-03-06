
// BuildMFCDlg.h : header file
//

#pragma once

// GuiLite interface
#define COLOR_BYTES		2
#define UI_BLOCK_NUM	9
typedef int(*SYNC_DATA)(int hr, int spo2, int rr, int nibp_sys, int nibp_dia, int nibp_mean);
extern SYNC_DATA gSyncData;
extern int startHostMonitor(int main_cnt, int main_width, int main_height, int sub_cnt, int sub_width, int sub_height, int color_bytes);
static int sync_data(int hr, int spo2, int rr, int nibp_sys, int nibp_dia, int nibp_mean);

class CUiBlock;
// CBuildMFCDlg dialog
class CBuildMFCDlg : public CDialogEx
{
// Construction
public:
	CBuildMFCDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BUILDMFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	DECLARE_MESSAGE_MAP()

	void updateUI(CDC* pDC);

private:
	static CBuildMFCDlg* m_the_dialog;
	static UINT ThreadHostMonitor(LPVOID pParam);
	static UINT ThreadRefreshUI(LPVOID pParam);

	CUiBlock*	m_uiBlock[UI_BLOCK_NUM];
	bool		m_is_main_ui_mode;
};
