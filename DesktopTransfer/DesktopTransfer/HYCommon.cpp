#include "HYCommon.h"
#include "HYDispatchCenter.h"

/*
* HYCommonResponse
*/
HYCommonResponse::HYCommonResponse(QObject *parent)
	: QObject(parent)
	, nMsgType(0)
	, nSession(-1)
	, nResultCode(-1)
	, strResultDescribe("")
{
}

HYCommonResponse::HYCommonResponse(HYCommonResponse& ref, QObject *parent)
	: HYCommonResponse(parent)
{
	*this = ref;
}

HYCommonResponse::HYCommonResponse(const QByteArray &json, QObject *parent)
	: HYCommonResponse(parent)
{
	this->readFromJson(json);
}

HYCommonResponse::~HYCommonResponse()
{
}

HYCommonResponse& HYCommonResponse::operator=(const HYCommonResponse& ref)
{
	this->nMsgType = ref.nMsgType;
	this->nSession = ref.nSession;
	this->nResultCode = ref.nResultCode;
	this->strResultDescribe = ref.strResultDescribe;

	return *this;
}

void HYCommonResponse::readFromJson(const QByteArray &json)
{
	QJsonParseError parseResult;
	QJsonDocument jsonDocument = QJsonDocument::fromJson(json, &parseResult);
	if (QJsonParseError::NoError != parseResult.error)
	{
		CMF_LOG(LOG_RUN, LOG_ERROR, "Parse talk channle list get response(%s) error:%s", QString(json).toStdString().c_str(), parseResult.errorString().toStdString().c_str());

		return;
	}

	QJsonObject jsonObj = jsonDocument.object();
	this->read(jsonObj);
}

void HYCommonResponse::read(const QJsonObject &json)
{
	if (json.contains("nResultCode") && json["nResultCode"].isDouble())
	{
		this->nResultCode = json["nResultCode"].toInt();
	}
	else
	{
		this->nResultCode = -1;
	}

	if (json.contains("strResultDescribe") && json["strResultDescribe"].isString())
	{
		this->strResultDescribe = json["strResultDescribe"].toString();
	}
	else
	{
		this->strResultDescribe.clear();
	}

	if (json.contains("nMsgType") && json["nMsgType"].isDouble())
	{
		this->nMsgType = json["nMsgType"].toInt();
	}
	else
	{
		this->nMsgType = -1;
	}
}

HYUserRegisterResponse::HYUserRegisterResponse(QObject *parent)
	: HYCommonResponse(parent)
	, strUserDomainCode("")
	, strUserDomainName("")
	, strUserTokenID("")
{
}

HYUserRegisterResponse::HYUserRegisterResponse(const QByteArray &json, QObject *parent)
	: HYCommonResponse(parent)
	, strUserDomainCode("")
	, strUserDomainName("")
	, strUserTokenID("")
{
	this->readFromJson(json);
}

HYUserRegisterResponse::~HYUserRegisterResponse()
{
}

void HYUserRegisterResponse::readFromJson(const QByteArray &json)
{
	QJsonParseError parseResult;
	QJsonDocument jsonDocument = QJsonDocument::fromJson(json, &parseResult);
	if (QJsonParseError::NoError != parseResult.error)
	{
		CMF_LOG(LOG_RUN, LOG_ERROR, "Parse user register response(%s) error:%s", QString(json).toStdString().c_str(), parseResult.errorString().toStdString().c_str());

		return;
	}

	QJsonObject jsonObj = jsonDocument.object();
	HYCommonResponse::read(jsonObj);
	if (jsonObj.contains("strUserDomainCode") && jsonObj["strUserDomainCode"].isString())
	{
		this->strUserDomainCode = jsonObj["strUserDomainCode"].toString();
	}
	else
	{
		this->strUserDomainCode.clear();
	}

	if (jsonObj.contains("strUserDomainName") && jsonObj["strUserDomainName"].isString())
	{
		this->strUserDomainName = jsonObj["strUserDomainName"].toString();
	}
	else
	{
		this->strUserDomainName.clear();
	}

	if (jsonObj.contains("strUserTokenID"))
	{
		if (jsonObj["strUserTokenID"].isString())
		{
			this->strUserTokenID = jsonObj["strUserTokenID"].toString();
		}
		else if (jsonObj["strUserTokenID"].isDouble())
		{
			this->strUserTokenID = QString("%1").arg(jsonObj["strUserTokenID"].toInt());
		}
	}
	else
	{
		this->strUserTokenID.clear();
	}
}

HYStartCaptureRsp::HYStartCaptureRsp(QObject *parent /*= Q_NULLPTR*/)
	: HYCommonResponse(parent)
{
}

HYStartCaptureRsp::HYStartCaptureRsp(const QByteArray &json, QObject *parent /*= Q_NULLPTR*/)
	: HYCommonResponse(parent)
{
	this->readFromJson(json);
}

HYStartCaptureRsp::~HYStartCaptureRsp()
{
}

void HYStartCaptureRsp::readFromJson(const QByteArray &json)
{
	QJsonParseError parseResult;
	QJsonDocument jsonDocument = QJsonDocument::fromJson(json, &parseResult);
	if (QJsonParseError::NoError != parseResult.error)
	{
		CMF_LOG(LOG_RUN, LOG_ERROR, "Parse start capture  response(%s) error:%s", QString(json).toStdString().c_str(), parseResult.errorString().toStdString().c_str());

		return;
	}

	QJsonObject jsonObj = jsonDocument.object();
	if (jsonObj.contains("m_nResultCode") && jsonObj["m_nResultCode"].isDouble())
	{
		this->nResultCode = jsonObj["m_nResultCode"].toInt();
	}
	if (jsonObj.contains("m_strResultDsc") && jsonObj["m_strResultDsc"].isString())
	{
		this->strResultDescribe = jsonObj["m_strResultDsc"].toString();
	}
	if (jsonObj.contains("m_nSeqNo") && jsonObj["m_nSeqNo"].isDouble())
	{
		this->m_nSeqNo = jsonObj["m_nSeqNo"].toInt();
	}
	if (jsonObj.contains("m_nNeedDispatch") && jsonObj["m_nNeedDispatch"].isDouble())
	{
		this->m_nNeedDispatch = jsonObj["m_nNeedDispatch"].toInt();
	}
}



HYFaceRecAlarmNotify::HYFaceRecAlarmNotify(QObject *parent /*= Q_NULLPTR*/)
{
}

HYFaceRecAlarmNotify::HYFaceRecAlarmNotify(const QByteArray &json, QObject *parent /*= Q_NULLPTR*/)
{
	this->readFromJson(json);
}

HYFaceRecAlarmNotify::~HYFaceRecAlarmNotify()
{
}

void HYFaceRecAlarmNotify::readFromJson(const QByteArray &json)
{
	QJsonParseError parseResult;
	QJsonDocument jsonDocument = QJsonDocument::fromJson(json, &parseResult);
	if (QJsonParseError::NoError != parseResult.error)
	{
		CMF_LOG(LOG_RUN, LOG_ERROR, "Parse start capture  response(%s) error:%s", QString(json).toStdString().c_str(), parseResult.errorString().toStdString().c_str());

		return;
	}

	QJsonObject jsonObj = jsonDocument.object();
	if (jsonObj.contains("m_nSimilarity") && jsonObj["m_nSimilarity"].isDouble())
	{
		this->m_nSimilarity = jsonObj["m_nSimilarity"].toInt();
	}
}