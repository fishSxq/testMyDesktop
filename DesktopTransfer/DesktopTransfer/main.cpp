#include "DesktopTransfer.h"
#include <QtWidgets/QApplication>

#include "HYDispatchCenter.h"
#include "win_sdk/include/hyplayer_sdk.h"

void SDKEventCallBack(long nMsgType, long nSeqNo, const char* strMsg, void* pUser)
{
	QByteArray datagram(strMsg);
	CMF_LOG(LOG_RUN, LOG_INFO, "Receive MsgType(%d) seqNo(%d) SDK datagram: %s", nMsgType, nSeqNo, QString(datagram).toStdString().c_str());
	qApp->postEvent(&(HYDispatchCenter::shareInstance()), new HYMessageEvent(nMsgType, nSeqNo, datagram));
}


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	DesktopTransfer w;
	w.show();

	CHyPlayerSdk::instance()->SetCBFunc(SDKEventCallBack, NULL);
	return a.exec();
}
