#pragma once

#include <QObject>
#include <QUrl>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QByteArray>

#include "win_sdk/include/hyplayer_sdk.h"
#include "win_sdk/include/sdk_common_def.h"

enum SDK_MESSAGE_ID
{
	USER_REGISTER_REQ = 54001,
	USER_REGISTER_RSP = 54003,
	START_CAPTURE_RSP = 45013,
	FACEREC_DETECT_NOTIFY = 45056,
};


class HYCommonResponse : public QObject
{
	Q_OBJECT

public:
	enum ResultError {
		NoError = 0
	};
	Q_ENUM(ResultError)

public:
	explicit HYCommonResponse(QObject *parent = Q_NULLPTR);
	HYCommonResponse(HYCommonResponse&, QObject *parent = Q_NULLPTR);
	HYCommonResponse(const QByteArray &json, QObject *parent = Q_NULLPTR);
	virtual ~HYCommonResponse();

	HYCommonResponse& operator=(const HYCommonResponse&);

	int getSession() const { return nSession; }
	void setSession(int session) { nSession = session; }

	int resultCode() const { return this->nResultCode; }
	void setResultCode(int error) { this->nResultCode = error; }

	QString resultDescribe() const { return this->strResultDescribe; }
	void setResultDescribe(QString strError) { this->strResultDescribe = strError; }

	virtual void readFromJson(const QByteArray &json);
protected:
	void read(const QJsonObject &json);

protected:
	int nMsgType;
	int nSession;
	int nResultCode;
	QString strResultDescribe;
};

class HYUserRegisterResponse : public HYCommonResponse
{
	Q_OBJECT

public:
	explicit HYUserRegisterResponse(QObject *parent = Q_NULLPTR);
	explicit HYUserRegisterResponse(const QByteArray &json, QObject *parent = Q_NULLPTR);
	~HYUserRegisterResponse();

public:
	void readFromJson(const QByteArray &json) override;

public:
	QString strUserDomainCode;
	QString strUserDomainName;
	QString strUserTokenID;
};

class HYStartCaptureRsp : public HYCommonResponse
{
	Q_OBJECT

public:
	HYStartCaptureRsp(QObject *parent = Q_NULLPTR);
	HYStartCaptureRsp(const QByteArray &json, QObject *parent = Q_NULLPTR);
	~HYStartCaptureRsp();

public:
	void readFromJson(const QByteArray &json) override;

	int m_nSeqNo;
	int m_nNeedDispatch;
};

class HYFaceRecAlarmNotify : public QObject
{
	Q_OBJECT

public:
	HYFaceRecAlarmNotify(QObject *parent = Q_NULLPTR);
	HYFaceRecAlarmNotify(const QByteArray &json, QObject *parent = Q_NULLPTR);
	~HYFaceRecAlarmNotify();

public:
	void readFromJson(const QByteArray &json);

	int m_nSimilarity; // 0 - 100
};