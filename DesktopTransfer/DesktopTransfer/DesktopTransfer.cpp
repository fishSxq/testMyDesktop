#include "DesktopTransfer.h"
#include <QStringList>
#include "HYDispatchCenter.h"
#include <QMessageBox>
#include "win_sdk/include/hyplayer_sdk.h"
#include "HYCommon.h"

#pragma execution_character_set("utf-8")

DesktopTransfer::DesktopTransfer(QWidget *parent)
	: QMainWindow(parent)
	, m_nResulotionIndex(0)
	, m_nAudioTypeIndex(0)
	, m_bMouseCapturing(false)
	, m_hCaptureWnd(NULL)
	, m_pAreaCapture(NULL)
	, m_nRegistDelayID(-1)
	, m_nDmgType(2337)
	, m_pPartDesktopCapture(NULL)
{
	ui.setupUi(this);

	m_IniFile = new QSettings("config.ini", QSettings::IniFormat);

	m_btnGroup = new QButtonGroup(this);
	m_btnGroup->addButton(ui.radioBtnDesktop, 0);
	m_btnGroup->addButton(ui.radioBtnWindow, 1);
	m_btnGroup->addButton(ui.radioBtnPartDesktop, 2);

	initConfig();

	QStringList listCom;
	listCom << "原始宽高" << "VGA(640*480)" << "720P(1280 * 720)" << "1080P(1920*1080)";
    ui.comBoxResolution->addItems(listCom);
	ui.comBoxResolution->setCurrentIndex(m_nResulotionIndex);
	
	listCom.clear();
	listCom << "PCMA" << "OPUS";
	ui.comBoxAudioType->addItems(listCom);
	ui.comBoxAudioType->setCurrentIndex(m_nAudioTypeIndex);

	connect(ui.toolBtnPreview, SIGNAL(clicked()), this, SLOT(OnClickedPreview()));
	connect(ui.toolBtnStart, SIGNAL(clicked()), this, SLOT(OnClickedSaveAndStart()));

	connect(ui.toolButtonSelWnd, SIGNAL(pressed()), this, SLOT(OnPressedSelWnd()));
	connect(&(HYDispatchCenter::shareInstance()), SIGNAL(receiveDatagram(int, int, QByteArray)), this, SLOT(receiveSdkDatagrams(int, int, QByteArray)));

	connect(m_btnGroup, SIGNAL((buttonClicked(int))), this, SLOT(radioCheckedChange(int)));

	QString tt = m_strIp + ":" + QString::number(m_nPort);
	ui.lineServerAddr->setText(tt);

	ui.labelSelWndTitle->setText(m_strCaptureTitle);

	m_btnGroup->button(m_nCaptureType)->setChecked(true);

	//QStringList sl = m_strCaptureArea.split(":");
	//QString strShowArea = "";
	//if (4 == sl.count())
	//{
	//	strShowArea += "x:";
	//	strShowArea += sl.at(0);
	//	strShowArea += "<br/>y:";
	//	strShowArea += sl.at(1);
	//	strShowArea += "<br/>w:";
	//	strShowArea += sl.at(2);
	//	strShowArea += "<br/>h:";
	//	strShowArea += sl.at(3);
	//}
	ui.labelWinArea->setText(m_strCaptureArea);

	QIcon icon;
	icon.addFile(QStringLiteral(":/DesktopTransfer/Resources/image/From.ico"));
	ui.toolButtonSelWnd->setIcon(icon);	

	QPixmap pixmap(":/DesktopTransfer/Resources/image/Scan.ico"); //定义大小
	QSize picSize(28, 28); //缩放图片，按比例
	QPixmap scaledPixmap = pixmap.scaled(picSize, Qt::KeepAspectRatio); //设置样式
	m_myCursor = QCursor(scaledPixmap, -1, -1);

	m_pAreaCapture = new QtCaptureWnd();
	m_pAreaCapture->hide();
	m_pAreaCapture->setAttribute(Qt::WA_TransparentForMouseEvents, true);

	m_pPartDesktopCapture = new QtPartDesktop();
	m_pPartDesktopCapture->hide();
	//ui.toolButtonSelWnd->setAttribute(Qt::WA_TransparentForMouseEvents, true);

	//注册服务器定时器
	m_nRegistDelayID = startTimer(500);
}


void DesktopTransfer::mousePressEvent(QMouseEvent *event)
{
	QPoint pRwidget = ui.widgetRight->mapFromParent(event->pos());
	if (Qt::LeftButton == event->button()
		&& ui.toolButtonSelWnd->geometry().contains(pRwidget))
	{
		m_bMouseCapturing = true;
		QIcon icon;
		icon.addFile(QStringLiteral(":/DesktopTransfer/Resources/image/From_h.ico"));
		ui.toolButtonSelWnd->setIcon(icon);
		setCursor(m_myCursor);
		ui.toolButtonSelWnd->setFocusPolicy(Qt::ClickFocus);
	}
}

void DesktopTransfer::mouseMoveEvent(QMouseEvent *event)
{
	if (m_bMouseCapturing)
	{
		POINT pp;
		QPoint pG = mapToGlobal(event->pos());
		pp.x = pG.x();
		pp.y = pG.y();
		HWND hw = WindowFromPoint(pp);

		if (m_hCaptureWnd != hw 
			&& hw != GetDesktopWindow()
			&& hw != HWND(ui.toolButtonSelWnd->winId()))
		{
			TCHAR tszText[MAX_PATH] = { 0 };
			::GetWindowText(hw, tszText, MAX_PATH);
			//LPCTSTR strFF = TEXT(tszText);
			//ui.labelSelWndTitle->setText(ConvertLPWSTRToLPSTR(tszText));
			char tmp[256] = { 0 };
			sprintf(tmp, "%2X", (unsigned char*)hw);
			ui.labelSelWndTitle->setText(tmp);
			m_hCaptureWnd = hw;
			RECT rc;
			::GetWindowRect(hw, &rc);
			QRect qrc;
			qrc.setX(rc.left - 4);
			qrc.setY(rc.top - 4);
			qrc.setWidth(rc.right - rc.left + 8);
			qrc.setHeight(rc.bottom - rc.top + 8);
			m_pAreaCapture->setGeometry(qrc);
			m_pAreaCapture->move(qrc.left(),qrc.top() );
			m_pAreaCapture->show();
		}
	}
}

void DesktopTransfer::mouseReleaseEvent(QMouseEvent *event)
{
	if (m_bMouseCapturing)
	{
		m_bMouseCapturing = false;
		QIcon icon;
		icon.addFile(QStringLiteral(":/DesktopTransfer/Resources/image/From.ico"));
		ui.toolButtonSelWnd->setIcon(icon);
		setCursor(Qt::ArrowCursor);
		ui.toolButtonSelWnd->setCheckable(false);
	}
}

void DesktopTransfer::timerEvent(QTimerEvent *event)
{
	int nTimerId = event->timerId();
	if (nTimerId == m_nRegistDelayID)
	{
		char addr[128] = { 0 };
		CHyPlayerSdk::instance()->GetMac(addr);
		m_strUserID = addr;
		CHyPlayerSdk::instance()->Regist(CHyPlayerSdk::instance()->GetSeqNo(), m_strUserID.toStdString().c_str()
			, m_strUserID.toStdString().c_str(), m_strIp.toStdString().c_str(), m_nPort, DevType_PC);
		killTimer(m_nRegistDelayID);
		m_nRegistDelayID = -1;
	}
}

void DesktopTransfer::closeEvent(QCloseEvent *event)
{
	CHyPlayerSdk::instance()->StopCapture();
	CHyPlayerSdk::instance()->UnRegist(CHyPlayerSdk::instance()->GetSeqNo());
}

void DesktopTransfer::initConfig()
{
	if (m_IniFile)
	{
		m_IniFile->beginGroup("Config");
		m_nHasConfiged = m_IniFile->value("HasConfiged").toInt();
		m_strIp = m_IniFile->value("Ip").toString();
		m_nPort = m_IniFile->value("Port").toInt();
		m_nResulotionIndex = m_IniFile->value("ResulotionIndex").toInt();
		m_nAudioTypeIndex = m_IniFile->value("AudioTypeIndex").toInt();
		m_nCaptureType = m_IniFile->value("CaptureType").toInt();
		m_hCaptureWnd = HWND(m_IniFile->value("CaptureWnd").toLongLong());
		m_strCaptureTitle = m_IniFile->value("CaptureTitle").toString();
		m_strCaptureArea = m_IniFile->value("CaptureArea").toString();
		m_nDmgType = m_IniFile->value("DmgType").toInt();
		m_IniFile->endGroup();
	}
}

void DesktopTransfer::saveConfig()
{
	if (!m_nHasConfiged)
	{
		m_nHasConfiged = 1;
	}

	QString addrServer = ui.lineServerAddr->text();
	int nPos = addrServer.indexOf(":");
	m_strIp = addrServer.left(nPos);
	m_nPort = addrServer.right(addrServer.size() - nPos - 1).toInt();

	m_nResulotionIndex = ui.comBoxResolution->currentIndex();
	m_nAudioTypeIndex = ui.comBoxAudioType->currentIndex();

	m_nCaptureType = m_btnGroup->checkedId();

	if (m_pPartDesktopCapture)
	{
		QRect rc = m_pPartDesktopCapture->GetCaptureArea();
		m_strCaptureArea = QString("x:%1<br/>y:%2<br/>w:%3<br/>h:%4").arg(QString::number(rc.x())).arg(QString::number(rc.y()))
			.arg(QString::number(rc.width())).arg(QString::number(rc.height()));
		ui.labelWinArea->setText(m_strCaptureArea);
	}

	m_strCaptureArea = ui.labelWinArea->text();

	if (m_IniFile)
	{
		m_IniFile->beginGroup("Config");
		m_IniFile->setValue("HasConfiged", m_nHasConfiged);
		m_IniFile->setValue("Ip", m_strIp);
		m_IniFile->setValue("Port", m_nPort);
		m_IniFile->setValue("ResulotionIndex", m_nResulotionIndex);
		m_IniFile->setValue("AudioTypeIndex", m_nAudioTypeIndex);
		m_IniFile->setValue("CaptureType", m_nCaptureType);
		m_IniFile->setValue("CaptureWnd", long(m_hCaptureWnd));
		m_IniFile->setValue("CaptureTitle", m_strCaptureTitle);
		m_IniFile->setValue("CaptureArea", m_strCaptureArea);
		m_IniFile->endGroup();
	}
}

void DesktopTransfer::startCapture(bool bPreview)
{
	CAPTURE_LEVEL level = CaptureLevel_FHD;
	switch (m_nResulotionIndex)
	{
	case 1:
		level = CaptureLevel_SD_1;
		break;
	case 2:
		level = CaptureLevel_HD;
		break;
	case 3:
		level = CaptureLevel_FHD;
		break;
	default:
		//原始宽高
		break;
	}

	CCapParameters para = CHyPlayerSdk::instance()->GetDefaultCaptureParams(CaptureSourceTypeDesktop, level);
	
	if (4 == m_nResulotionIndex)
	{
		//原始宽高
	}

	if (0 == m_nAudioTypeIndex)
	{
		para.m_capturePara.m_nAudioCodecType = ENCODE_PCMA;
	}
	else
	{
		para.m_capturePara.m_nAudioCodecType = ENCODE_OPUS;
	}


	para.m_nAutoGetAddr = 1;
	if (bPreview)
	{
		para.m_hPreviewWindow = (void*)(ui.widgetPreview->winId());
	}
	else
	{
		para.m_hPreviewWindow = NULL;
		ui.widgetPreview->drawPostText(true, Qt::green, "采集中...");
	}
	para.m_nMediaFlags = 3;
	para.m_nSeqNo = CHyPlayerSdk::instance()->GetSeqNo();
	CHyPlayerSdk::instance()->StartCapture(para);
}

void DesktopTransfer::showPartDesktopWnd()
{
	int x = 0;
	int y = 0;
	int w = 0;
	int h = 0;
	QStringList sl = m_strCaptureArea.split("<br/>");
	QString si = "";
	if (4 == sl.count())
	{
		si = sl.at(0);
		x = si.right(si.size() - si.indexOf(":") - 1).toInt();
		si = sl.at(1);
		y = si.right(si.size() - si.indexOf(":") - 1).toInt();
		si = sl.at(2);
		w = si.right(si.size() - si.indexOf(":") - 1).toInt();
		si = sl.at(3);
		h = si.right(si.size() - si.indexOf(":") - 1).toInt();
	}
	if (m_pPartDesktopCapture)
	{
		m_pPartDesktopCapture->setGeometry(x, y, w, h);
		m_pPartDesktopCapture->move(x, y);
		m_pPartDesktopCapture->show();
	}
}

void DesktopTransfer::on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason)
{
	switch (reason)
	{
	case QSystemTrayIcon::Trigger:
	case QSystemTrayIcon::DoubleClick:
	{
		this->setWindowState((this->windowState() & ~Qt::WindowMinimized) | Qt::WindowActive);
		this->show();
	}
	break;
	default:
		break;
	}
}

void DesktopTransfer::OnClickedPreview()
{
	this->startCapture(true);
}

void DesktopTransfer::OnClickedSaveAndStart()
{
	saveConfig();
	
	this->startCapture(false);
}

void DesktopTransfer::OnPressedSelWnd()
{
	if (!ui.radioBtnWindow->isChecked())
	{
		return;
	}
	ui.toolButtonSelWnd->setCheckable(true);
	m_bMouseCapturing = true;
	QIcon icon;
	icon.addFile(QStringLiteral(":/DesktopTransfer/Resources/image/From_h.ico"));
	ui.toolButtonSelWnd->setIcon(icon);
	setCursor(m_myCursor);
}

void DesktopTransfer::OnCheckedChangeSelWnd()
{

}

void DesktopTransfer::receiveSdkDatagrams(int nMsgType, int nSession, QByteArray datagram)
{
	switch (nMsgType)
	{
	case USER_REGISTER_RSP:
	{
		HYUserRegisterResponse registerRsp(datagram);
		if (HYCommonResponse::NoError != registerRsp.resultCode())
		{
			QMessageBox::about(NULL, "提示", "注册服务器失败.");

		}
		else
		{
			m_strUserTokenID = registerRsp.strUserTokenID;
			//this->startCapture(false);
			//showPartDesktopWnd();
		}
	}
	break;
	case START_CAPTURE_RSP:
	{
		HYStartCaptureRsp capRsp(datagram);
		if (0 != capRsp.resultCode())
		{
			//QMessageBox::about(NULL, "Tip", "Camera started fail.");
			this->setWindowState((this->windowState() & ~Qt::WindowMinimized) | Qt::WindowActive);
			this->show();
			ui.widgetPreview->drawPostText(true, Qt::red, "采集失败");
			ui.linePublishUrl->setText("");
		}
		else
		{
			QString url = QString("rtsp://%1:554/%2/rtsp://%3:554?BitRate=512;FrameRate=25;IFrame=100;DmgType=%4").arg(m_strIp)
				.arg(QString::number(m_nDmgType)).arg(m_strUserTokenID).arg(QString::number(m_nDmgType));
			ui.linePublishUrl->setText(url);
		}
	}
	break;
	default:
		break;
	}
}

void DesktopTransfer::radioCheckedChange(int index)
{
	if (!ui.radioBtnWindow->isChecked() && m_pAreaCapture)
	{
		m_pAreaCapture->hide();
	}
}

char* DesktopTransfer::ConvertLPWSTRToLPSTR(LPWSTR lpwszStrIn)
{
	LPSTR pszOut = NULL;
	if (lpwszStrIn != NULL)
	{
		int nInputStrLen = wcslen(lpwszStrIn);

		// Double NULL Termination
		int nOutputStrLen = WideCharToMultiByte(CP_ACP, 0, lpwszStrIn, nInputStrLen, NULL, 0, 0, 0) + 2;
		pszOut = new char[nOutputStrLen];

		if (pszOut)
		{
			memset(pszOut, 0x00, nOutputStrLen);
			WideCharToMultiByte(CP_ACP, 0, lpwszStrIn, nInputStrLen, pszOut, nOutputStrLen, 0, 0);
		}
	}
	return pszOut;
}