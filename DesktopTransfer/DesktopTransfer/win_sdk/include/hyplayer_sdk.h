#ifndef __HYPLAYER_SDK_H__
#define __HYPLAYER_SDK_H__

#include "hyplayer_sdk_export.h"
#include "sdk_common_def.h"
#include <map>
#include <set>

class CTTask;
class CSdpMsgParse;
class CSdkDbOperator;

typedef void(*fEventCallBack)(long nMsgType,long nSeqNo,const char* strMsg, void* pUser);

typedef void* WindowObject;

class CHyPlayerSdk;

#define CMF_LOG(LOGTYPE, LOGGRADE, FORMAT_STRING, ...) \
	{ \
		CHyPlayerSdk::instance()->CmfLog(LOGTYPE, LOGGRADE, ", %s,%d: " FORMAT_STRING , CHyPlayerSdk::instance()->GetNoPathFileName( __FILE__,sizeof(__FILE__) ), __LINE__, ##__VA_ARGS__);\
	}


class HYPLAYER_SDK_DLL CHyPlayerSdk
{
public:
    CHyPlayerSdk();
	~CHyPlayerSdk();

public:
	static CHyPlayerSdk* instance(void);
	static void SetWorkPath(const char* pszPath);

	enum CAPEVEL
	{
		CapLevel_FHD,
		CapLevel_HD,
		CapLevel_SD_1,
		CapLevel_SD_2,
		ScreenCapLevel_FHD,
		ScreenCapLevel_HD,
		ScreenCapLevel_SD_1,
		ScreenCapLevel_SD_2,
		CapLevelCount,
	};

	class CCallidInfo
	{
	public:
		CCallidInfo()
			: bAuthentication(false)
			, bCapture(false)
		{}

		bool bAuthentication;
		bool bCapture;
		std::set<int> setPlaySession;
	};

public:
	/*********************************************************************/
	/*     System                                                        */
	/*********************************************************************/
	void Reset();

	void SetCBFunc(fEventCallBack fCB, void* pUser);

	/*********************************************************************/
	/*     Common                                                        */
	/*********************************************************************/
	long DelUserData(long nID);
	long AddUserData(const char* pszKey, const char* pszCondition, const char* pszValue);
	long SetUserData(const char* pszKey, const char* pszCondition, const char* pszValue);
	std::string GetUserData(const char* pszKey);
	std::string GetUserValue(const char* pszKey);
	long ModifyUserData(long nID, const char* strUserCondition, const char* strUserValue);
	long DelUserDataByUserkey(const char* strUserKey);
	
	int GetSeqNo();
	SDK_OPERATION_TYPE GetCurrentServiceType();

	/*********************************************************************/
	/*   加解密                                                          */
	/*********************************************************************/
	int InitCm(const CInitCmInfo& info);
	int UninitCm();
	int GetEncryptCallID(int nSeqNo, int nAlloc, const std::string& strPeerId);


	/*********************************************************************/
	/*     Play                                                          */
	/*********************************************************************/
    int GetPlaySession();
    bool StartPlayMedia(CPlayParams* pParam);
    StopSessionResult StopPlayBySessionID(int nPlaySession);
    StopSessionResult StopAllPlay();
    bool SetPlayDebugFlag(int nPlaySession, int nTsDebugLevel, int nDsDebugLevel, int nRsDebugLevel);
	bool SnapShot(int nPlaySession, const char* strPath);
    bool GetMediaInfo(int nPlaySession);
	bool SetVideoRotate(int nSession);

	bool SetPlayProperty(int nType, int nSessionID,  int nValue, int nValueEx);
	void SetGlobalAudioStat(int nAudioOn);
	void GetRecordInfo(int nSeqNo, lsRecordInfo lsRecord);

	int StartMultiPlayback(lsPlaybackPara lsPara);
	int SetMultiPlaybackTime(int nTime);
	int PauseMultiPlayback(int nPause);
	int SetMultiPlaybackMute(int nMute);
	int SetMultiPlaybackSpeed(int nSpeed);
	int StopMultiPlayback();

	//bool StartDownload(const char* strFileName, const char* strDomainCode,int nRecordID,int nBeginTime = 0, int nEndTime = 0);

	/*********************************************************************/
	/*     Capture                                                       */
	/*********************************************************************/
	bool IsCaptureStarted();
	int StartCapture(CCapParameters& rParams);
	int StartCaptureIFDispatch(CCapParameters& rParams, int nNeedDispatch = 0);
	bool StopCapture();
	
	bool ChangeCameraDeviceID(int nCameraID);
	bool SwitchMicID(int nMicID);

    bool ChangeCapturePara( int nPublishWidth, int nPublishHeight, int nPublishFPS, int nPublishBitrate);
	void SendCaptureNotify(WindowObject hNotifyWnd);
    bool SetCaptureProperty(int nProperty, int nValue, int nParam);
	bool SetCapPublishAddr(const char* strIP, int nPort);
    bool CaptureSnapShot( const char* strPath);
    bool SetMyCaptureName( const char* strName);

    bool StartSearchLanCaptureDevice();
    bool StopSearchLanCaptureDevice();
    bool RegistUIToBroadcastServer();
	
	int FixRecordFile(const char* strFile);
	std::string GetOsdString(const std::string& strOsd);
	std::string GetCameraList();
	std::string GetMicList();

	CCapParameters GetDefaultCaptureParams(CaptureSourceType nSrcType, CAPTURE_LEVEL nLevel);
	int GetCurrentCaptureMediaFlag();
	int GetCapturePublish();

	int GetFRBlackList(int nSessionID, const char* strGroupCode, const char* strSavePath);
	int EnableCaptureFaceDectect(int nEnable, int nFaceExtractInterval,const char* strGroupCode,const char* strBlackListPath);
	/*********************************************************************/
	/*     Service                                                       */
	/*********************************************************************/
    //////////Common/////////////////
	bool SendCommonUDPMsg( const char* strIP, unsigned int nMsgType, unsigned int nMsgSeqNo, const char* strContent);
	long SendNetworkMessage(long nMsgType, long nMsgSeqNo, const char* strContent);
	long SendNetworkMessageWithNoReply(long nMsgType, long nMsgSeqNo, const char* strContent);

	long SendDataToMutilUser(long nMsgSeqNo, const char* strContent, long nImportant, lsSimpleUserInfo lsUser);

	void CmfLog(LOG_TYPE logType,LOG_LEVEL logLevel, const char* fmt, ... );
	int ReportGps(const CGpsInfo& gpsInfo);
   
	//////////Interface: User Manager/////////////////
	int Regist(int nSeqNo, const char* strUserID, const char* strUserName, const char* strServerIP,
		int nServerPort, RegistDevType nDevType, int nPriority = 0);
	int UnRegist(int nSeqNo);
	int KickoutUser(int nSeqNo, const char* strKickUserTokenID, const char* strKickReason);
	int SetUserFriend(int nSeqNo, lsSimpleUserInfo lsUser);
	int SetUserUseIPC(int nSeqNo, const char* strServiceUrl, int nIsUse);
	int GetIPCInfo(char* ipcInfo);

	//////////Interface: TalkBack/////////////////
	int SetTalkBackCapturePara(const CCapParameters& talkCaptureParams);
	int StartTalking(int nSeqNo, CTalkParams stParams);
	int QuitTalking(int nSeqNo, const CTalkBackInfo& talkbackInfo);
	int JudgeJoinTalking(int nSeqNo, const CJoinTalkBackInfo& talkbackInfo, int nIsAgree, int nVoiceIntercom);
	int InviteUserTalkBack(int nSeqNo, const CTalkBackInfo& talkInfo, lsToUser lsUser);
	int KickTalkbackUser(int nSeqNo, const CTalkBackInfo& talkInfo, const char* strKickUserDomainCode, const char* strKickUserID);
    int GetTalkbackInfo(int nSeqNo, const CTalkBackInfo& talkInfo);
	int DelTalkbackInfo(int nSeqNo, const CTalkBackInfo& talkInfo);
	int SetTalkBackListen(int nSeqNo, const CTalkBackInfo& talkInfo, bool nEnable);
	int SetTalkBackSpeak(int nSeqNo, const CTalkBackInfo& talkInfo, lsUserSpeak lsUser);
	int GetTalkBackRecord(int nSeqNo, const CTalkBackInfo& talkInfo);
	int SetTalkBackSpeakPTT(int nSeqNo, const CTalkBackInfo& talkInfo, int nSetSpeak);

	//////////Interface:Meeting/////////////////
	int SetMeetingCapturePara(const CCapParameters& talkCaptureParams);
	int StartMeeting(int nSeqNo, CMeetingInfo& meetingInfo);
	int JoinMeeting(int nSeqNo, CJoinMeetingInfo& joinMeetingInfo);
	int InviteUserMeeting(int nSeqNo, CMeetingBaseInfo& meetingBaseInfo, lsMeetingUserInfo& lsUser);
	int KickMeetingUser(int nSeqNo, CMeetingBaseInfo& meetingBaseInfo, CSimpleUserInfo& kickUserInfo);
	int QuitMeeting(int nSeqNo, CMeetingBaseInfo& meetingBaseInfo);
	int StopMeeting(int nSeqNo, CMeetingBaseInfo& meetingBaseInfo);
	int ZoomMeetingPic(int nSeqNo, CMeetingBaseInfo& meetingBaseInfo, const char* strMeetingUrl, int nX, int nY);
	int SwapMeetingPic(int nSeqNo, CMeetingBaseInfo& meetingBaseInfo, const char* strMeetingUrl, int nStartX, int nStartY, int nEndX, int nEndY);
	int MeetingPushOne(int nSeqNo, CMeetingBaseInfo& meetingBaseInfo, const char* strMeetingUrl, int nX, int nY);
	int SetMeetingSpeak(int nSeqNo, CMeetingBaseInfo& meetingBaseInfo,int nSetSpeakForAll, lsUserSpeak lsUser);
	//int GetMeetingList(int nSeqNo );
	int GetMeetingInfo(int nSeqNo, CMeetingBaseInfo& meetingBaseInfo,  int nListMode);
	int DelMeetingInfo(int nSeqNo, CMeetingBaseInfo& meetingBaseInfo);
	int ObserverMeetingState(int nSeqNo, CMeetingBaseInfo& meetingBaseInfo, int nEnable);
	//strStartTime  2017-01-01 01:01:00
	int SetPredetermineMeeting(int nSeqNo, CMeetingInfo& meetingInfo, int nMeetingID, const char* strStartTime, int nDuration);
	int SwapMeetingUser(int nSeqNo, CMeetingBaseInfo& meetingBaseInfo, CSimpleUserInfo& userAInfo, CSimpleUserInfo& userBInfo);
	int UserRaiseInMeeting(int nSeqNo, CMeetingBaseInfo& meetingBaseInfo);
	int GetMeetingLayoutInfo(int nSeqNo, CMeetingBaseInfo& meetingBaseInfo);
	int BeginMeetingRecord(int nSeqNo, CMeetingBaseInfo& meetingBaseInfo);
	int MeetingChangeLayoutType(int nSeqNo, CMeetingBaseInfo& meetingBaseInfo);
	int CancelInviteUserMeetingReq(int nSeqNo, CMeetingBaseInfo& meetingBaseInfo, lsSimpleUserInfo& lsUserInfo);


	//////////Interface:集群对讲/////////////////
	int AddTrunkChannelUser(int nSeqNo, const CTrunkChannelUserInfo& trChannelUser);	
	//stTrunkChannelUserInfo：
	//strTcUserName 为空 代表可选;
	//nPriority为-1 代表可选
	int ModifyTrunkChannelUser(int nSeqNo, const CTrunkChannelUserInfo& trChannelUser);	
	//lsTruncChannelUser->stTrunkChannelUserInfo,只需传值:
	//strTcUserDomainCode;
	//strTcUserID;
	int DelTrunkChannelUser(int nSeqNo, lsBaseTruncChannelUser lsChannelUser);
	//stTrunkChannelInfo：
	//strTrunkChannelID不需要传值
	int CreateTrunkChannel(int nSeqNo, const CTrunkChannelInfo& trChInfo,lsTruncChannelUser lsUser);
	//stTrunkChannelInfo：
	int ModifyTrunkChannel(int nSeqNo,  const CTrunkChannelInfo& trChInfo);
	int DelTrunkChannel(int nSeqNo,  const CTrunkChannelBaseInfo& trChInfo);
	int QueryTrunkChannelList(int nSeqNo, const CQueryTrunkChannelInfo& trCri);
	int GetTrunkChannelInfo(int nSeqNo, const CTrunkChannelBaseInfo& trChInfo);
	int JoinTrunkChannel(int nSeqNo, const CTrunkChannelBaseInfo& trChInfo, int nPriority);
	int LeaveTrunkChannel(int nSeqNo,  const CTrunkChannelBaseInfo& trChInfo);
	int StartTrunkChannelSpeak(int nSeqNo,  const CStartTrunkChannelSpeakInfo& trChInfo, CCapParameters capturePara);
	int StopTrunkChannelSpeak(int nSeqNo,  const CTrunkChannelBaseInfo& trChInfo);
	int ControlTrunkChannelRecord(int nSeqNo,  const CTrunkChannelBaseInfo& trChInfo, int nRecord);
	int KickoutTrunkChannel(int nSeqNo, const CTrunkChannelBaseInfo& trChInfo,lsBaseTruncChannelUser lsUser);
	int InviteUserTrunkChannel(int nSeqNo, const CTrunkChannelBaseInfo& trChInfo, lsTruncChannelUser lsUser);
	int ObserverTrunkChannel(int nSeqNo, const CTrunkChannelBaseInfo& trChInfo, int nEnable);

	/*********************************************************************/
	/*     cm service manager                                            */
	/*********************************************************************/
	int ChangeCmPasswd(const char* strOldPasswd, const char* strNewPasswd);
	int UpdateCmExpiredSecretKey();
	int CmSelfDestruct();



	/*********************************************************************/
	/*     Inner method                                                  */
	/*********************************************************************/
	const char* GetNoPathFileName(const char* pszName, const size_t nNameLen);
	void OnMsgCallBack(long nMsgType, long nSeqNo, const char* strMsg);
	CUserBaseInfo* GetUserBaseInfo();

	bool GetMac(char* mac);

private:
	void InitParams();
	void ProcessServiceErrorRsp(int nSeqNo, int nOperationType, int nCode, const char* strDesc);
	int ProcessSendServiceMsg(int nSeqNo);
	int StartCaptureIfGetAddr();
	int InnerStartCapture();
	void DelEncryptSession(int nCallId, bool bCapture, int nSessionID = -1);
	bool StartPlayUrl(CPlayParams params);
	bool StartPlay(CPlayParams* pParam);
	void Init();
	void Uninit();

public:
	static std::string m_strWorkPath;

private:
    static int m_nPlaySessionID;
    static int m_nTaskID;
	static bool m_bInit;
	fEventCallBack m_fCallBackFunc;
	void* m_pUser;
	CTTask* m_pTask;
	CUserBaseInfo* m_pUserInfo;
	std::string m_pTmpUserName;
	std::map<int, CPlayParams> m_mapMedia;
    bool m_bCaptureUsed;
	CCapParameters m_captureParamsArray[CapLevelCount];
	CCapParameters m_talkbackCapturePara;
	CCapParameters m_meetingCapturePara;
	CCapParameters m_normalCapturePara;

	CCapParameters m_channelSpeakCapPara;
	CStartTrunkChannelSpeakInfo m_channelSpeakInfo;
	CTalkParams  m_talkbackInfo;
	CJoinTalkBackInfo m_joinTalkbackInfo;
	CMeetingInfo m_meetingInfo;
	CJoinMeetingInfo m_joinMeetingInfo;
	int m_nVoiceIntercom;

	SDK_OPERATION_TYPE m_eOperationType;

	static CHyPlayerSdk* m_spPlayer;
	
	int m_nSeqNo;
	//穿透IP、Port用于播放
	std::string m_strNatIP;
	int m_nNatPort;
	std::string m_strIP;
	int m_nPort;

	std::string m_strKdcIP;
	int m_nKdcPort;

	CSdkDbOperator* m_pDBOperator;
	int m_nAuidoOn;
	int m_nCaptureAVStatus;

	std::map<int, CCallidInfo> m_mapEncryptSession;
	int m_nEncryptDevType;
};


#endif
