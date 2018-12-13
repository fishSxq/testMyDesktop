#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_DesktopTransfer.h"
#include <QSettings>
#include <QSystemTrayIcon>
#include <QMouseEvent>
#include <windows.h>
#include "QtCaptureWnd.h"
#include "QtPartDesktop.h"

class DesktopTransfer : public QMainWindow
{
	Q_OBJECT

public:
	DesktopTransfer(QWidget *parent = Q_NULLPTR);

private:
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void timerEvent(QTimerEvent *event);
	void closeEvent(QCloseEvent *event);

	char* ConvertLPWSTRToLPSTR(LPWSTR lpwszStrIn);

private Q_SLOTS :
	void on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason);
	void OnClickedPreview();
	void OnClickedSaveAndStart();
	void OnPressedSelWnd();
	void OnCheckedChangeSelWnd();
	void receiveSdkDatagrams(int nMsgType, int nSession, QByteArray datagram);
	void radioCheckedChange(int index);

private:
	void initConfig();
	void saveConfig();
	void startCapture(bool bPreview);
	void showPartDesktopWnd();

private:
	Ui::DesktopTransferClass ui;

	QSettings* m_IniFile;
	QSystemTrayIcon* mSysTrayIcon;
	QButtonGroup* m_btnGroup;
	QCursor     m_myCursor;
	QtCaptureWnd* m_pAreaCapture;
	QtPartDesktop* m_pPartDesktopCapture;

	QString m_strIp;
	int m_nPort;
	int m_nResulotionIndex;
	int m_nAudioTypeIndex;
	int m_nHasConfiged;
	int m_nCaptureType;    //0：全桌面采集  1：窗口采集   2：部分桌面采集
	HWND m_hCaptureWnd;
	QString m_strCaptureTitle;
	QString  m_strCaptureArea;   //x:y:w:h

	bool m_bMouseCapturing;
	int m_nRegistDelayID;
	QString  m_strUserID;  //以物理地址做userid
	QString  m_strUserTokenID;
	int m_nDmgType;
};
