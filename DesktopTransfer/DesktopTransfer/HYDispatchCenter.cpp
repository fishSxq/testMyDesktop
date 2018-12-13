#include "HYDispatchCenter.h"
#include <QDebug>

/*
* HYMessageEvent
*/
HYMessageEvent::HYMessageEvent(const int &messageType, const int &messageSession, const QByteArray &data)
	: QEvent(QEvent::Type(HYMsgType))
	, m_nMsgType(messageType)
	, m_nSession(messageSession)
	, datagram(data)
{
}

HYMessageEvent::~HYMessageEvent()
{

}

/*
* HYDispatchCenter
*/
HYDispatchCenter::HYDispatchCenter(QObject *parent)
	: QObject(parent)
    , m_ifStoreToBuff(false)
{
}

HYDispatchCenter::~HYDispatchCenter()
{
}

HYDispatchCenter& HYDispatchCenter::shareInstance()
{
	static HYDispatchCenter dispatchCenter;
	return dispatchCenter;
}

bool HYDispatchCenter::event(QEvent *event)
{
	if (HYMsgType == event->type())
	{
		HYMessageEvent *sdkEvent = static_cast<HYMessageEvent *>(event);
        if (m_ifStoreToBuff)
        {
            m_lstMsg.push_back(new HYMessageEvent(sdkEvent->m_nMsgType, sdkEvent->m_nSession, sdkEvent->datagram));
            //m_lstMsg.push_back(sdkEvent);
        }
        else
        {
            emit receiveDatagram(sdkEvent->m_nMsgType, sdkEvent->m_nSession, sdkEvent->datagram);
        }
		return true;
	}

	return QObject::event(event);
}

void HYDispatchCenter::setMsgToBuffFlag(bool bBuffer)
{
    if (bBuffer)
    {
        m_ifStoreToBuff = true;
    }
    else
    {
        for each (HYMessageEvent* sdkEvent in m_lstMsg )
        {
            emit receiveDatagram(sdkEvent->m_nMsgType, sdkEvent->m_nSession, sdkEvent->datagram);
        }
        qDebug() << "get msg from buff, count:" << m_lstMsg.size();
        m_lstMsg.clear();
        m_ifStoreToBuff = false;
    }
}

