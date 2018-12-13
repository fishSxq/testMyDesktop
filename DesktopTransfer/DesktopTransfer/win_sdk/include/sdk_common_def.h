#ifndef __SDK_COMMON_DEF__
#define __SDK_COMMON_DEF__

#include <string>
#include <vector>
#include <list>

enum RegistDevType
{
	DevType_Android = 1,
	DevType_iOS = 2,
	DevType_PC = 3,
	DevType_Web = 4,
};

enum StopSessionResult
{
	StopSessionSuccess,
	StopSessionFailed,
	StopSessionNotFind,
};

enum SDK_AUDIO_TYPE
{
	ENCODE_PCMA,
	ENCODE_PCMU,
	ENCODE_OPUS,
	ENCODE_AAC,
};

enum CaptureSourceType
{
	CaptureSourceTypeUnknown = -1,	//未知类型
	CaptureSourceTypeCamera,	//电脑摄像头、USB摄像头
	CaptureSourceTypeDesktop,	//桌面采集
	CaptureSourceTypeIPC		//IPC固定摄像头
};

enum CaptureMediaSourceStatus
{
	CAPTURE_ENABLE_AUDIO = 0x01,
	CAPTURE_ENABLE_VIDEO = 0x02
};


enum SDK_VIDEO_TYPE
{
	ENCODE_H264,
	ENCODE_HEVC,
};

enum CAPTURE_LEVEL
{
	CaptureLevel_FHD,
	CaptureLevel_HD,
	CaptureLevel_SD_1,
	CaptureLevel_SD_2
};

enum BITRATE_LEVEL
{
	BITRATE_DEFINE = -1,
	BITRATE_LOW = 0,
	BITRATE_LOW_HD = 1,
	BITRATE_MID = 2,
	BITRATE_MID_HD	= 3,
	BITRATE_HIGH = 4,
	BITRATE_HIGH_HD = 5,
};

enum SDK_PLAYTYPE
{
	REALPLAY_SERVICEURL = 0,
	REALPLAY_URL,
	PLAYBACK_SERVICEURL,
	PLAYBACK_URL,
	FILE_PLAY,
	LAN_PLAY_UDP_STRREAM,
	DOWNLOAD_SERVICEURL,
	DOWNLOAD_URL,
	REALPLAY_USER_TOKENID,
	REALPLAY_MEETING_TOKENID,
};

enum SDK_CAPTURETYPE
{
	SDK_CAPTURE_NONE = 0x00,
	SDK_CAPTURE_PUBLISH = 0x01,
	SDK_CAPTURE_RECORD = 0x02,
	SDK_CAPTURE_PROJECTION = 0x04,
	SDK_CAPTURE_EXTCAM = 0x08,
	SDK_CAPTURE_NATIVECAM = 0x10,
	SDK_CAPTURE_PCAPTURE_NATIVECAMROJECTION = 0x20,
	SDK_CAPTURE_UDP_PUBLISH = 0x40,
	SDK_CAPTURE_UDP_LAN_PUBLISH = 0x80,
	SDK_CAPTURE_BBR_PUBLISH = 0x100,
	SDK_CAPTURE_FACE_RECOGNITION = 0x1000,
	SDK_CAPTURE_COUNT
};
enum SDK_CAPTURECTRL
{
    SDK_CAPTURE_PROPERTY_CAMERA_INDEX = 0x0,
    SDK_CAPTURE_PROPERTY_ENABLE_QOS,
    SDK_CAPTURE_PROPERTY_CAMERA_MAX_ZOOM,
    SDK_CAPTURE_PROPERTY_CAMERA_CUR_ZOOM,
    SDK_CAPTURE_PROPERTY_ENABLE_AUDIO,
    SDK_CAPTURE_PROPERTY_ENABLE_VIDEO,
    SDK_CAPTURE_PROPERTY_CAMERA_ROTATION,
    SDK_CAPTURE_PROPERTY_SCREEN_ORIENTATION,
    SDK_CAPTURE_PROPERTY_ENABLE_AECM,
    SDK_CAPTURE_PROPERTY_ENABLE_TORCH,
    SDK_CAPTURE_PROPERTY_ENABLE_LOCALRECORD,
    SDK_CAPTURE_PROPERTY_PUBLISH_ADDR,
    SDK_CAPTURE_PROPERTY_NICK_NAME,
    SDK_CAPTURE_PROPERTY_VIDEO_SCALE_TYPE,
};
enum SDK_PLAYCTRL
{
	SDK_SET_PLAYTIME,
	SDK_SET_SCALE,
	SDK_SET_VOLUME,
	SDK_SET_MUTE,
	SDK_SET_STRETCHTYPE,
	SDK_SET_BRIGHTNESS,
	SDK_SET_PAUSE,
	SDK_SET_BGPLAY,
	SDK_ENABLE_LOUDSPEAKER,
	SDK_SET_PLAY_BOXBLUR,
};

enum SDK_OPERATION_TYPE
{
	SDK_OPERATION_NONE,
	SDK_OPERATION_START_TALKBACK,
	SDK_OPERATION_JOIN_TALKBACK,
	SDK_OPERATION_START_MEETING,
	SDK_OPERATION_JOIN_MEETING,
	SDK_OPERATION_CHANNELSPEAK,
};

enum LOG_TYPE
{
	LOG_INTERFACE,
	LOG_RUN,
	LOG_STATISTIC,
};

enum LOG_LEVEL
{
	LOG_FINE,
	LOG_INFO,
	LOG_WARNING,
	LOG_ERROR
};

enum STREAM_TRANSFER_TYPE
{
	STREAM_UDP,
	STREAM_TCP,
	STREAM_RTC
};

//视频拉伸类型，
enum VIDEO_STRETCHTYPE
{
	VIDEO_NOT_STRETCH,        //不拉伸，保持原始宽高比，会出现黑边
	VIDEO_FULL_STRETCH,       //全部拉伸，可能会失真，视频被拉高或压扁
	VIDEO_FLEXIBLE_STRETCH    //智能拉伸，保持原始宽高比拉伸，部分视频不显示
};

class  CPlayBackPara
{
public:
	CPlayBackPara()
	{
		this->clear();
	}

	void clear()
	{
		m_nServiceSessionID = -1;
		m_nPlayType = PLAYBACK_URL;
		m_nTSType = STREAM_TCP;
		m_windowObject = NULL;
		m_bEnableVideo = true;
		m_bEnableAudio = true;
		m_nFlags = 0;
		m_nStretchType = VIDEO_NOT_STRETCH;
		m_nStartTime = 0;
		m_nEndTime = 0;
		m_dScale = 1.0;
		m_nTotalTime = -1;
		m_nPlayTimeOffset = 0;
	}

public:
	int   m_nServiceSessionID;
	SDK_PLAYTYPE  m_nPlayType;
	STREAM_TRANSFER_TYPE  m_nTSType;  //enum TSType
	std::string  m_strUrl;
	std::string  m_strStreamTip;
	void*       m_windowObject;
	int  m_bEnableVideo;
	int  m_bEnableAudio;
	int  m_nRecordId;
	int  m_nPlayTimeOffset;
	int  m_nStartTime;
	int  m_nEndTime;
	float  m_dScale;
	int  m_nFlags;
	VIDEO_STRETCHTYPE m_nStretchType;
	int m_nTotalTime;

	int m_nSeqNo;
	std::string m_strDomainCode;
};

typedef std::list<CPlayBackPara>  lsPlaybackPara;

class  CPlayParams
{
public:
	CPlayParams()
	{
		this->clear();
	}

	void clear()
	{
		m_nServiceSessionID = -1;
		m_nPlayType = REALPLAY_URL;
		m_nTSType = STREAM_TCP;
		m_windowObject = NULL;
		m_bEnableVideo = true;
		m_bEnableAudio = true;
		m_nFlags = 0;
		m_nStretchType = VIDEO_NOT_STRETCH;
		m_nStartTime = 0;
		m_nEndTime = 0;
		m_dScale = 1.0;
		m_nTranscodingScale = 0;
		m_nTranscodingOption = 0;
		m_nMeetingVideoQuality = 0;
		m_nCallID = 0;
		m_nBoxblur = 0;
	}

	CPlayParams& operator=(const CPlayBackPara& playbackPara)
	{
		m_nServiceSessionID = playbackPara.m_nServiceSessionID;
		m_nPlayType = playbackPara.m_nPlayType;
		m_nTSType = playbackPara.m_nTSType;
		m_strUrl = playbackPara.m_strUrl;
		m_nRecordId = playbackPara.m_nRecordId;
		m_strStreamTip = playbackPara.m_strStreamTip;
		m_windowObject = playbackPara.m_windowObject;
		m_bEnableVideo = playbackPara.m_bEnableVideo;
		m_bEnableAudio = playbackPara.m_bEnableAudio;
		m_nFlags = playbackPara.m_nFlags;
		m_nStretchType = playbackPara.m_nStretchType;
		m_nStartTime = playbackPara.m_nStartTime;
		m_nEndTime = playbackPara.m_nEndTime;
		m_dScale = playbackPara.m_dScale;
		m_nSeqNo = playbackPara.m_nSeqNo;
		m_strDomainCode = playbackPara.m_strDomainCode;
		return *this;
	}

public:
	int   m_nServiceSessionID;
	SDK_PLAYTYPE  m_nPlayType;
	STREAM_TRANSFER_TYPE  m_nTSType;  //enum TSType
	std::string  m_strUrl;
	std::string  m_strStreamTip;
	void*       m_windowObject;
	int  m_bEnableVideo;
	int  m_bEnableAudio;
	int  m_nRecordId;
	int  m_nStartTime;
	int  m_nEndTime;
	float  m_dScale;
	std::string m_strFileName;
	std::string  m_strServerIP;
	int  m_nServicePort;
	int  m_nFlags;
	VIDEO_STRETCHTYPE m_nStretchType;
	bool m_bEnableAecm;
	int m_nTotalSize;
	std::string  m_strNatServerIP;
	int  m_nNatServerPort;
	int m_nTranscodingScale;
	int m_nTranscodingOption;

	int m_nSeqNo;
	std::string m_strDomainCode;
	std::string m_strUserTokenID;
	int m_nMeetingID;
	int m_nMeetingVideoQuality; //0:高清 1：标清

	int m_nCallID;
	int m_nBoxblur;
};

class CCapParams
{
public:
	CCapParams()
		: m_nCameraId(0)
		, m_nMicId(0)
		, m_nVideoSrcFps(25)
		, m_nScreenX(0)
		, m_nScreenY(0)
		, m_nVideoSrcWidth(640)
		, m_nVideoSrcHeight(480)
		, m_nRawPictureType(9)
		, m_nVideoSrcOrientation(0)
		, m_nAudioCodecType(12)
		, m_nAudioBitsPerSample(16)
		, m_nAudioChannel(1)
		, m_nAudioSample(16000)
		, m_nAudioBitrate(32000)
		, m_nAudioEncComplex(4)
		, m_nEnableAEC(0)
		, m_nEnableAGC(0)
		, m_nEnableNS(0)
		, m_nEnableFEC(0)
	{}
	//Device
	int  m_nCameraId;
	int  m_nMicId;
	//Video
	int	m_nVideoSrcFps;                   //帧率
	int  m_nScreenX;              //桌面采集时起始点X
	int  m_nScreenY;             //桌面采集时起始点Y
	int  m_nVideoSrcWidth;              //原始宽
	int  m_nVideoSrcHeight;             //原始高
	int  m_nRawPictureType;        //源数据类型默认是YUV420P
	int  m_nVideoSrcOrientation;      //视频方向

	int	m_nUsbVid;
	int	m_nUsbPid;
	int	m_nUsbFd;
	int	m_nBusNum;
	int	m_nDevAddr;
	std::string  m_strUsbFsName;

	//Audio
	int  m_nAudioCodecType;             //音频类型
	int  m_nAudioBitsPerSample;          //音频采样位数
	int  m_nAudioChannel;               //音频声道
	int  m_nAudioSample;           //音频采样率
	int  m_nAudioBitrate;            //音频码率
	int  m_nAudioEncComplex;         //音频编码复杂度(0~10)
	int  m_nEnableAEC;
	int  m_nEnableAGC;
	int  m_nEnableNS;
	int  m_nEnableFEC;

	//Overlay
	std::string	m_strOverlayCmdParam;
};

class CCodecParams
{
public:
	CCodecParams()
		: m_nDstWidth(640)
		, m_nDstHeight(480)
		, m_nEncodePattern(0)
		, m_nVideoType(ENCODE_H264)
		, m_nQuality(1)
		, m_nPresetOption(1)
		, m_nBitRate(1024)
		, m_nDstFPS(25)
	{}

	int  m_nBitRate;
	int  m_nDstFPS;
	int  m_nDstWidth;              //目的宽
	int  m_nDstHeight;             //目的高
	int  m_nEncodePattern;         //编码方式(硬编/软编/其他方式)
	int  m_nVideoType;             //需要编码的视频类型化
	int  m_nQuality;
	int  m_nRawPictureType;        //原始数据类型
	int  m_nPresetOption;          //预设质量类型(0-5  六档,档位越高,质量越好)
};

class CEncryptInfo
{
public:
	CEncryptInfo()
		: m_nAllocCallID(1)
		, m_nCallId(-1)
		, m_nGroupId(0)
		, m_nNetworkMode(1)
		, m_nCallType(1)
	{}

	int m_nAllocCallID;
	int m_nCallId;
	int m_nGroupId;
	int m_bIsCaller;
	int m_nNetworkMode;
	int m_nCallType;
	std::string m_strPeerId;
	std::string m_strPeerAddr;
};


class CCapParameters
{
public:
	CCapParameters()
		: m_hPreviewWindow(NULL)
		, m_pfAudioAMCB(NULL)
		, m_pAMCBUser(NULL)
		, m_capturePara()
		, m_publishCodecPara()
		, m_recordCodecPara()
		, m_nSeqNo(0)
		, m_nCaptureType(SDK_CAPTURE_NONE)
		, m_nAutoGetAddr(1)
		, m_nNeedDispatch(0)
		, m_nEncrypt(0)
	{}


	CCapParams m_capturePara;
	CCodecParams m_publishCodecPara;
	CCodecParams m_recordCodecPara;
	void*	m_hPreviewWindow;			//视频窗口
	void*   m_pfAudioAMCB;     //音频振幅回调
	void*   m_pAMCBUser;     //音频振幅回调附带
	int  m_nCaptureType;
	int  m_nMediaFlags;
	std::string  m_strRecordPath;
	std::string  m_strPublishIP;
	int  m_nPublishPort;
	std::string  m_strNatServerIP;
	int  m_nNatServerPort;
	int m_nSeqNo;
	int m_nAutoGetAddr;
	int m_nNeedDispatch;
	int m_nEncrypt;
	CEncryptInfo m_encInfo;
};


class CToUserInfo
{
public:
	std::string strToUserDomainCode; // 对方用户域编码
	std::string strToUserID; // 对方用户ID
	std::string strToUserName; //对方用户名称
};


class CTalkBackInfo
{
public:
	std::string strTalkbackDomainCode; // 对讲会话域编码
	int nTalkbackID;   //对讲ID
};

class CJoinTalkBackInfo : public CTalkBackInfo
{
public:
	CJoinTalkBackInfo()
		: nNeedCapture(1)
	{}

	int nNeedCapture;
};


class CMeetingBaseInfo
{
public:
	std::string strMeetingDomainCode; // 会议域编码
	int nMeetingID;   //会议ID
};





class CUserBaseInfo
{
public:
	std::string strUserDomainCode;
	std::string strUserDomainName;
	std::string strUserTokenID;
	std::string strUserName;
	std::string strUserID;
	std::string strMac;
	int nDevType;
};

class CSimpleUserInfo
{
public:
	std::string strUserDomainCode;
	std::string strUserID;
};

class CUserSpeaker
{
public:
	std::string strUserDomainCode;
	std::string strUserID;
	int nSetSpeak; //0:禁言 1：解禁言
};

class CMeetingUserInfo : public CToUserInfo
{
public:
	CMeetingUserInfo()
		: nDevType(1)
	{}

	int nDevType;
};

class CRecordInfo
{
public:
	CRecordInfo()
		: nRecordID(0)
	{}

	std::string strDomainCode;
	int nRecordID;
};


typedef std::list<CSimpleUserInfo> lsSimpleUserInfo;
typedef std::list<CToUserInfo> lsToUser;
typedef std::list<CUserSpeaker> lsUserSpeak;
typedef std::list<CMeetingUserInfo> lsMeetingUserInfo;
typedef std::list<CRecordInfo>  lsRecordInfo;

class CMeetingInfo
{
public:
	CMeetingInfo()
		: nMeetingMode(1)
		, nRecord(0)
		, nInviteStyle(1)
		, nForceInvite(1)
		, nVoiceIntercom(0)
		, nNeedCapture(1)
		, nEncrypt(0)
	{}

	std::string strMeetingDomainCode;
	std::string strMeetingName;
	std::string strMeetingDesc;
	std::string strTrunkPara;
	std::string strMainUserDomainCode;
	std::string strMainUserID;
	int nMeetingMode;
	int nRecord;
	int nInviteStyle;
	int nForceInvite;
	int nVoiceIntercom;
	int nNeedCapture;   //0:不需要 1:需要
	int nEncrypt;		//是否加密

	lsMeetingUserInfo lsMeetingUser;
};

class CJoinMeetingInfo
{
public:
	CJoinMeetingInfo()
		: nIsAgree(1)
		, nPicMode(0)
		, nNeedCapture(1)
	{}

	CMeetingBaseInfo meetingBaseInfo;
	CSimpleUserInfo inviteUserInfo;
	int nIsAgree;
	int nPicMode;
	int nNeedCapture;
};

class CTalkParams
{
public:
	CTalkParams()
		: nTalkbackMode(0)
		, nRecord(0)
		, nInviteStyle(1)
		, nNoneDevice(0)
		, nVoiceIntercom(0)
		, nNeedCapture(1)
	{}

	std::string strTalkbackDomainCode; // 对讲会话域编码，同发起方域或对方域
	std::string strTalkbackName; // 对讲标题
	std::string strTalkbackDesc; //	对讲描述
	std::string strTrunkPara; // 透明参数
	int nTalkbackMode; // 业务模式 1：正常模式 2：空闲选一模式 3: 会议模式 4：推送模式
	int	nRecord; // 是否录像 0不录像 1：录像
	int	nInviteStyle;//参加方式（1正常2 强制）
	lsToUser	lsToUsers; //对方用户列表json格式：(vecToUser:[{strToUserDomainCode:"14dda9d2e171",strToUserID:"strToUserID",strToUserName : "strToUserName"}])
	int nNoneDevice; //  发起方设备状态 0:有设备 1 : 无设备对讲
	int nVoiceIntercom; // 对讲模式 0 音视频 1 语音
	int nNeedCapture;   //0:不需要 1:需要
};


//////////////////////集群对讲
class CTrunkChannelUserBaseInfo 
{
public:
	std::string strTcUserDomainCode;
	std::string 	strTcUserID;
};

class CTrunkChannelUserInfo : public CTrunkChannelUserBaseInfo
{
public:
	CTrunkChannelUserInfo() :nPriority(-1), nEnForce(1){}

	std::string 	strTcUserName;     //为空 代表可选
	int	nPriority;					   //-1 代表可选
	int nEnForce;
};

class CGetChannelUserInfo : public CTrunkChannelUserInfo
{
public:
	CGetChannelUserInfo() :nUserStatus(-1) {}
	int	nUserStatus;					   //-1 代表可选
};


typedef std::list<CTrunkChannelUserBaseInfo> lsBaseTruncChannelUser;
typedef std::list<CTrunkChannelUserInfo> lsTruncChannelUser;

class CTrunkChannelBaseInfo
{
public:
	CTrunkChannelBaseInfo()
		:nTrunkChannelID(-1)
	{}

	std::string strTrunkChannelDomainCode;
	int	nTrunkChannelID;
};

class CStartTrunkChannelSpeakInfo : public CTrunkChannelBaseInfo
{
public:
	CStartTrunkChannelSpeakInfo()
		:nNeedCapture(1)
	{}

	int	nNeedCapture;
};


class CTrunkChannelInfo : public CTrunkChannelBaseInfo
{
public:
	CTrunkChannelInfo()
		:nTrunkChannelType(-1)
		, nRecordStatus(-1)
		, nSpeakTimeout(-1)
	{}

	std::string	strTrunkChannelName;
	int	nTrunkChannelType;
	int	nRecordStatus;
	int	nSpeakTimeout;
};

class CQueryTrunkChannelInfo
{
public:
	CQueryTrunkChannelInfo()
		:nTrunkChannelType(-1)
		, nPage(1)
		, nSize(99999)
		, nReverse(0)
	{}

	std::string strTrunkChannelDomainCode;
	std::string strTrunkChannelKey;
	std::string strTcUserDomainCode;
	std::string strTcUserID;
	std::string strBeginCreateTime;
	std::string strEndCreateTime;
	int nTrunkChannelType;
	int nPage;
	int nSize;
	int nReverse;
};

class CGpsInfo
{
public:
	CGpsInfo()
		: fLongitude(-1.0f)
		, fLatitude(-1.0f)
		, fAltitude(-1.0f)
		, fSpeed(-1.0f)
		, nSignalGrades(-1)
		, nDataSourceType(-1)
	{}

	double fLongitude;
	double fLatitude;
	std::string strCollectTime;
	double fAltitude;
	double fSpeed;
	int nSignalGrades;
	int nDataSourceType;
};

class CInitCmInfo
{
public:
	CInitCmInfo()
		: nDevType(0x02)
		, nFlags(0)
		, nDevFd(-1)
	{}

	int nDevType; //设备类型，终端填0x02
	std::string	strDevPasswd;      //加密卡密码，缺省12345678
	std::string	strDevPath;      // 加密卡路径， / sdcard / android / data / 包名 / rt_sech.bin
	int	nDevFd;       //保留字段
	int  nFlags;
	std::string	 strKdcServerIP;        // 中心服务器地址
	int	nKdcServerPort;     //中心服务器端口
	std::string	strDcmServerIP;      // 保留字段
	int	nDcmServerPort;     // 保留字段
};

#endif
