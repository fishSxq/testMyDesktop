#pragma once

#include <QObject>
#include <QEvent>
#include <QList>

/*
* 通用消息类型
*/
const int HYMsgType = QEvent::registerEventType();
class HYMessageEvent : public QEvent
{
	friend class HYDispatchCenter;
public:
	HYMessageEvent(const int &messageType, const int &messageSession, const QByteArray &datagram);
	~HYMessageEvent();

	void * operator new(std::size_t n)
	{
		return malloc(n);
	}

	void operator delete(void * d)
	{
		free(d);
	}

private:
	int m_nMsgType;
	int m_nSession;
	QByteArray datagram;
};

class HYDispatchCenter : public QObject
{
	Q_OBJECT

private:
	HYDispatchCenter(QObject *parent = Q_NULLPTR);
	~HYDispatchCenter();

public:
	static HYDispatchCenter& shareInstance();
    void setMsgToBuffFlag(bool);

Q_SIGNALS:
	void receiveDatagram(int nMsgType, int nSession, const QByteArray &data);

protected:
	bool event(QEvent *event) override;
    bool m_ifStoreToBuff;
    QList<HYMessageEvent*> m_lstMsg;
};
