#ifndef _GAME_SVR_H__
#define _GAME_SVR_H__
#include <IDatabase.h>
#include <serverApp.h>
#include <ITimerQueue.h>
#include <IScriptSys.h>
#include <IEventSys.h>
#include <messagerCmd.h>
#include <sharemem.h>

class DatabaseCfg {
public:
	bool LoadConfig(const char* filename);

public:
	const char* GetHostIp() {
		return m_strHostIp.c_str();
	}
	ushort GetHostPort() {
		return m_usHostPort;
	}
	const char* GetUserName() {
		return m_strUsername.c_str();
	}
	const char* GetPassword() {
		return m_strPassword.c_str();
	}
	const char* GetDatabase() {
		return m_strDatabase.c_str();
	}
	const char* GetCharSet() {
		return m_strCharacterSet.c_str();
	}
	ushort GetZoneId() {
		return m_usZoneId;
	}

	DatabaseCfg() :
			m_usHostPort(0), m_usZoneId(1) {
	}

private:
	const char* LoadString(TiXmlDocument& objDoc, const char* fieldkey);
	int LoadInteger(TiXmlDocument& objDoc, const char* fieldkey);

private:
	/// ���ݿ������IP
	std::string m_strHostIp;
	/// ���ݿ�������˿�
	ushort m_usHostPort;
	/// ���ݿ��û�����
	std::string m_strUsername;
	/// ���ݿ�����
	std::string m_strPassword;
	/// ���ݿ�����
	std::string m_strDatabase;
	/// ���ݿ���ַ���
	std::string m_strCharacterSet;
	/// ��Ϸ��������id
	ushort m_usZoneId;
};

///ʱ�Ӿ���
#define TIMERQUEUE_PRECISION_MS 500

class ScriptPub;
class GridsManager;
class RankManager;
class ProxyServer;
class GameSvr: public ServerApp {
public:
	virtual bool Init();
	virtual bool Configure();
	virtual void OnRecvMessager();
	virtual void OnDestroy();
	virtual int OnCommandCfg(const char* cmd);

public:
	IO::IDatabase* GetDB();
	ushort GetZoneId();
	int GetMaxRegCount();
	void SendMsg(object_id id, int32 connid, const char* lpMsg);
	void SendMsgNotifyCmd(object_id id, int32 connid, int cmd);
	void SendUseKeyCmd(object_id id, int32 connid, const char* key);
	void SendProxyCmd(const char* msg);
	const char* GetCfgBasePath();
	const char* GetLogBasePath();
	const char* GetSvrNameId();

public:
	/** ���캯�� */
	GameSvr();
	/** �������� */
	~GameSvr();

public:
	/** ���õ�ǰ�ķ���������Ŀ¼
	 @param lpszSvrCfgDir ��ǰ�������������ļ�Ŀ¼
	 */
	virtual void SetSvrCfgDir(const char* lpszSvrCfgDir);
	void ShowHelpInfo();
	void ReloadScript(const char* svrname, int reloadFlag);
	void StartGame(const char* svrname);
	void StopServer(const char* svrname);

protected:
	bool InitFileMgr();
	bool InitMessager();
	void SetServerVersion();
	bool InitScriptPub();
	bool InitDBObject();
	bool InitTimerQueue();
	bool InitGridsMgr();
	bool InitRankMgr();
	bool InitProxyServer();
	int32 GetMessagerType();
	void OnBeforeWaitEvent();
	void OnMsgTransfer(char* msg);
	void OnMsgNotify(char* msg);
	void OnMsgCmdUserExit(MsgNotify* notify);
	void OnMsgCmdUserLoginOk(MsgNotify* notify);
	bool IsExitSysCmd(const char* cmd);
	void SendTransferMsg(object_id id, int connid, char* msg);

protected:
	/// ���������õ����Ŀ¼
	std::string m_strSvrCfgDir;
	/// ���������õĻ���·��
	std::string m_strCfgBasePath;
	/// ��������־�Ļ���·��
	std::string m_strLogBasePath;
	/// ���ݿ����
	IO::IDatabase* m_lpIDB;
	/// ���ݿ�����
	DatabaseCfg m_dbCfg;
	/// �͵�ǰgamesvr�������HTTP������id
	int m_iHttpSvrId;
	/// �͵�ǰgamesvr�������FLASH������id
	int m_iFlashSvrId;
	/// ���ű����õĽӿ�
	ScriptPub* m_lpScriptPub;
	/// �ǳ��������
	GridsManager* m_lpGridsMgr;
	/// ��������
	RankManager* m_lpRankMgr;
	/// ���������
	ProxyServer* m_lpProxyServer;
};

#endif// _GAME_SVR_H__
