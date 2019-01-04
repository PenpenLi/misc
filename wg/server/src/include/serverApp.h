#ifndef _SERVERAPP_H_
#define _SERVERAPP_H_
#include <platform.h>
#include <NetIO.h>
#include <Socket.h>
#include <Messager.h>
#include <DllLoader.h>
#include <IGameSys.h>
#include <configer.h>
#include <string>
#include <IUpdateSys.h>
#include <IEventSys.h>
#include <IScriptSys.h>
#include <ITime.h>
#include <ITimerQueue.h>
#include <log.h>
#include <sharemem.h>
#include <DataProcessor.h>
#include <ShareMemKeyMgr.h>

#define GLOBAL_CONFIGURE_PATH  "./globalconfig.xml"

/** ����messager�Ļ�������С */
#define MESSAGER_RECV_LEN 0x200000

/*
inline unsigned int ServerApp::timeGetTime()
{
        unsigned int uptime = 0;
        struct timespec on;
        if(clock_gettime(CLOCK_MONOTONIC, &on) == 0)
                 uptime = on.tv_sec*1000 + on.tv_nsec/1000000;
        return uptime;
}
*/

class HostUser {
public:
	const char* GetName() {
		return "host user";
	}
};

/** ������Ӧ�ó���Ļ��� 
 */
class ServerApp {
public:
	/** ��ʾ��ǰ�������İ汾��Ϣ
	 */
	virtual void ShowVersion(void);

	/** ��ʼִ��,�ڲ���ѭ����
	 */
	virtual void Run(void);

public:
	/** ���캯��
	 */
	ServerApp();

	/** ��������
	 */
	virtual ~ServerApp();

protected:
	/** ��ʼ������
	 */
	virtual bool Init(void);

	/** װ��ȫ�������ļ�
	 */
	virtual bool LoadGlobalConfigure();

	/** ״̬�����ļ�
	 */
	virtual bool Configure(void);

	/** װ����Դ�ļ�
	 */
	virtual bool LoadResources(void);

public:
	/** �������¼���֮ǰ����ø���� 
	 */
	virtual void OnBeforeWaitEvent();

	/** �������¼���֮�����ø���� 
	 */
	virtual void OnBeforeRecvEvent();

	/** ��һ���ͻ��������ٻ���ø����
	 @param iSocketFd
	 socket���
	 @param stClientAddr
	 �ͻ��ĵ�ַ��Ϣ
	 */
	virtual void OnAccept(int iSocketFd, const sockaddr_in& stClientAddr);

	/** ���յ�һ���ͻ����͵��������ݻ���ø����
	 @param lpstEvent
	 �����¼��ڵ�ָ��,���¼��ڵ�����OnAccept�б�������client��socket����Ͱ�
	 */
	virtual void OnRecvEvent(const Net::SEvent* lpstEvent);
	
	virtual void OnSendEvent(const Net::SEvent* lpstEvent);

	/** ���յ�Messager��Ϣǰ�ص��øýӿ�
	 */
	virtual void OnBeforeRecvMessager();

	/** ���յ�Messager��Ϣʱ�ص��øýӿ�
	 */
	virtual void OnRecvMessager();

	/** ���յ�һ����������
	 */
	virtual int OnCommandCfg(const char* lpszCmd);

	/** ���յ�Messager��Ϣ��ص��øýӿ�
	 */
	virtual void OnAfterRecv();

	/** ����Ӧ������ʱ����ø����
	 */
	virtual void OnDestroy();

public:
	/** ����Ψһ�Լ�飬���ص�ǰ�Ľ��������Ƿ�ΪΨһ
	 */
	bool CheckUnique();

	/** ����ǰ��������Ϊ�ػ�����
	 */
	bool Daemonize();

	bool IsDaemonized();

	void CloseStdOut();

	/** Pendһ������������
	 @param lpszCmd ��Ҫpend������
	 @param lpszServerId ��Ҫpend��Ŀ��
	 */
	void PendCommand(const char* cmd, const char* serverName);

	/** ����ȫ������·��
	 */
	void SetGlobalCfgPath(const char* path);

	void StopServer(const char* svrname);

	bool IsExist(const char* svrname);

	void Release();

protected:
	/** װ�ع��ø�ʽ�������ļ�
	 @param lpszCfgPath
	 �����ļ�·��
	 @return
	 ����true��false
	 */
	bool LoadCommConfig(const char* lpszCfgPath);

	/** װ�ض�̬��ע������
	 @param lpszCfgPath
	 �����ļ�·��
	 @return
	 ����true��false
	 */
	bool LoadDynRegConfig(const char* lpszCfgPath);

	/** ��ʼ����ϷϵͳIGameSys����
	 @return
	 ����true��false
	 */
	bool InitGameSys();

	/** ��ʼ����������Ķ��� 
	 */
	bool InitGameObjects(void);

	/** ��ʼ�������� 
	 */
	bool InitListeners(void);

	/** ��ʼ���ű�ϵͳģ�� 
	 */
	bool InitScriptModule(void);

	/** �ͷ�GameSys���� 
	 */
	void ReleaseGameSys();

	/** װ�ؽű�
	 */
	bool LoadFromScript(void);

private:
	int GetNetIOEventCount();
	void HandleNetIOEvents(int iEventCount);
	void HandleNetIOEvents(Net::SEvent* lpstEvent);
	void HandleLinuxNetIOEvents(Net::SEvent* lpstEvent);
	void HandleRecvMessager();
	void HandleCommandCfg();

protected:
	struct SScriptMoudleObj {
		Script::IScriptModule* lpModule;
		std::string strFlag;
	};
	typedef std::vector<SScriptMoudleObj> StdVctScriptModule;
	typedef StdVctScriptModule::iterator StdVctScriptModuleIter;

	/// ��Ϸϵͳ����
	IGameSys* m_lpGameSys;
	/// ����ϵͳ����
	IUpdateSys* m_lpUpdateSys;
	/// �¼�ϵͳ����
	IEventSys* m_lpEventSys;
	/// ʱ�����
	ITime* m_lpTime;
	/// ʱ�����
	ITimerQueue* m_lpTimerQueue;

	/// �ű�ϵͳ����
	Script::IScriptSys* m_lpScriptSys;

	/// ����װ����Ϸϵͳ��̬��
	DllLoader m_objGameSysDynLib;
	/// ��������
	SConfig m_stConfig;
	/// �ű�ģ���б�
	StdVctScriptModule m_vctModules;

	/// ����Ŀ¼
	std::string m_strWorkDir;
	/// ������socket����
	Net::Socket m_objHostSocket;
	/// NetIO����
	Net::NetIO* m_objNetIO;
	/// Messager����
	Net::Messager m_objMessager;
	/// ��ǰ��������Ψһ��ʶ����
	std::string m_strNameId;
	/// ���Խ��ܵ������·�¼���
	int32 m_iMaxEvents;
	/// ÿ��ѭ�����ߵ�ʱ����,��λ΢��
	uint32 m_uiSleepUs;
	/// �ڵȴ�һ������ʱ�䵽��ʱ�ĳ�ʱ����
	uint32 m_uiWaitEventTimeOutMs;
	/// ÿ��ѭ���д���messager��������,һ�㽨��Ϊ����1
	int32 m_iMessagerMaxCount;
	/// �����󶨵Ķ˿ں�
	ushort m_usHostBindPort;
	/// ���������ļ������д�С
	int32 m_iListenNumber;
	/// ����������socket���͵Ļ����С
	int32 m_iHostSocketSendMaxLen;
	/// ����client��socket���յĻ����С
	int32 m_iClientSocketRecvMaxLen;
	/// ����client��socket���͵Ļ����С
	int32 m_iClientSocketSendMaxLen;
	/// ���ý���messager�������Ĵ�С
	int32 m_iMessageBufferMaxSize;
	/// ������������client������
	int32 m_iClientMaxSocketCount;
	/// ����client�ı��ּ����ʱ����
	uint32 m_uiClientActiveSec;

	/// ����������
	std::string m_strServerName;
	/// ���汾��
	uint32 m_uiVersionMajor;
	/// �ΰ汾��
	uint32 m_uiVersionMinor;
	/// �����汾��
	uint32 m_uiVersionBuild;
	/// ��������
	std::string m_szBuildDate;
	/// ����ʱ��
	std::string m_szBuildTime;

	/// ����յ���messager��Ϣ����
	uchar* m_lpszMsgPkg;
	/// ����յ���messager��Ϣ�������ݳ���
	int m_iMsgLen;
	/// ���͸�messager���ݵķ���id
	uint32 m_ulMessagerFromSvrId;

	/// ���������ùܵ�
	IO::Pipe* m_lpCmdCfgPipe;

	std::string m_szGlobleCfgPath;

	/// ���̻���Ĺ����ڴ�
	SHAREMEM_HANDLE m_mutex;

	HostUser m_hostUser;

	bool m_isRunning;
	bool m_isDaemonized;

	ShareMemKeyMgr m_shareMemKeyMgr;
};

inline ServerApp::ServerApp() {
	m_lpGameSys = NULL;
	m_lpUpdateSys = NULL;
	m_lpEventSys = NULL;
	m_lpTime = NULL;
	m_lpTimerQueue = NULL;
	m_lpScriptSys = NULL;
	m_objNetIO = NULL;
	m_iMaxEvents = 0;
	m_uiSleepUs = 5000;
	m_uiWaitEventTimeOutMs = 0;
	m_iMessagerMaxCount = 0;
	m_usHostBindPort = 0;
	m_iListenNumber = 5;
	m_iHostSocketSendMaxLen = 1024;
	m_iClientSocketRecvMaxLen = 1024;
	m_iClientSocketSendMaxLen = 1024;
	m_iMessageBufferMaxSize = MESSAGER_RECV_LEN;
	m_iClientMaxSocketCount = 1024;
	m_uiClientActiveSec = 0;
	m_uiVersionMajor = 0;
	m_uiVersionMinor = 0;
	m_uiVersionBuild = 0;
	m_lpszMsgPkg = NULL;
	m_iMsgLen = 0;
	m_ulMessagerFromSvrId = 0xffff;
	m_lpCmdCfgPipe = NULL;
	m_szGlobleCfgPath = GLOBAL_CONFIGURE_PATH;
	m_mutex = INVAILED_SHAREMEM_HANDLE;

	m_lpszMsgPkg = new uchar[m_iMessageBufferMaxSize];

	m_isRunning = true;
	m_isDaemonized = false;
	Net::Startup();
}

inline ServerApp::~ServerApp() {
	ReleaseGameSys();
	SafeDeleteArray(m_lpszMsgPkg);
	SafeDelete(m_lpCmdCfgPipe);
	m_objHostSocket.Close();
	DestoryNetIO(&m_objNetIO);
	Net::Cleanup();
}

inline void ServerApp::ShowVersion(void) {
	std::cout << "==================================================="
			<< std::endl;
	std::cout << " Server name: " << m_strServerName << std::endl;
	std::cout << " Version: " << m_uiVersionMajor << "." << m_uiVersionMinor
			<< "." << m_uiVersionBuild << std::endl;
	std::cout << " Last Compiling Date: " << m_szBuildDate << " "
			<< m_szBuildTime << std::endl;
	std::cout << " Copyright: 2013-2014" << std::endl;
	std::cout << "==================================================="
			<< std::endl;
}

inline bool ServerApp::Init(void) {
	// init the rand 
	time_t lTime;
	srand(time(&lTime));

	m_objNetIO = Net::CreateNetIO();

	// load global configure
	if (!LoadGlobalConfigure()) {
		std::cerr << "*Load global configure failed " << std::endl;
		return false;
	}

	// Load the configure file 
	if (!Configure()) {
		std::cerr << "*Load configure failed " << std::endl;
		return false;
	}

	// Load resources file 
	if (!LoadResources()) {
		std::cerr << "*Load resources failed " << std::endl;
		return false;
	}

	// ��ʼ�����ùܵ�
	m_lpCmdCfgPipe = new IO::Pipe;
	const char* cmdCfgKey = m_shareMemKeyMgr.MakeKey(SMEMTYPE_CMD_CFG_HEAD,
			m_strNameId.c_str());
	if (!m_lpCmdCfgPipe->Init(cmdCfgKey, 4096, IO::PIPE_MUTEX_LOCK)) {
		std::cerr << "*Init command config failed!" << std::endl;
		return false;
	}

	// create host socket for client connect
	if (m_usHostBindPort > 0
			&& !m_objHostSocket.CreateSocket(AF_INET, SOCK_STREAM, 0, 0)) {
		std::cerr << "*Create socket SOCK_STREAM for tcp failed!" << std::endl;
		return false;
	}

	// create io net object (epoll for linux, completeio for windows) 
	if (m_iMaxEvents > 0 && !m_objNetIO->Create(m_iMaxEvents)) {
		std::cerr << "*Create netio event failed! max events count: "
				<< m_iMaxEvents << std::endl;
		return false;
	}

	// bind the host socket with one port
	if (m_usHostBindPort > 0 && !m_objHostSocket.Bind(m_usHostBindPort)) {
		std::cerr << "*Bind the socket with " << m_usHostBindPort
				<< " port failed!" << std::endl;
		return false;
	}

	// set the host socket send buffer max size
	if (m_usHostBindPort > 0
			&& !m_objHostSocket.SetSendBufferMaxSize(m_iHostSocketSendMaxLen)) {
		std::cerr << "*Set socket max send buffer size to "
				<< m_iHostSocketSendMaxLen << " failed!" << std::endl;
		return false;
	}

	// set the host socket listen number
	if (m_usHostBindPort > 0) {
		m_objHostSocket.SetListenNumber(m_iListenNumber);
	}

	// add the host socket into net io event queue
	if (m_usHostBindPort > 0) {
		if (!m_objNetIO->AddRecvEvent(m_objHostSocket.GetHandle(), &m_hostUser)) {
			std::cerr << "*Add io event  failed!" << std::endl;
			return false;
		}
	}

	return true;
}

inline void ServerApp::Run(void) {
	if (!Init()) {
		return;
	}

	if (IsDaemonized()) {
		CloseStdOut();
	}

	while (m_isRunning) {
		OnBeforeWaitEvent();
		m_lpUpdateSys->OnUpdate(m_lpTime->GetCurrentTimeMs());
		m_lpEventSys->ProcessPendEvents();
		int iEventCount = GetNetIOEventCount();
		if (iEventCount < 0) {
			m_lpTime->SleepMs(m_uiSleepUs / 1000);
			continue;
		}
		OnBeforeRecvEvent();
		HandleNetIOEvents(iEventCount);
		OnBeforeRecvMessager();
		HandleRecvMessager();
		HandleCommandCfg();
		OnAfterRecv();
		m_lpTime->SleepMs(m_uiSleepUs / 1000);
	}

	OnDestroy();
}

inline bool ServerApp::LoadFromScript() {
	bool bRt = false;
	if (m_lpScriptSys != NULL) {
		for (uint i = 0; i < m_stConfig.stScript.vctPaths.size(); ++i) {
			std::string szPath = m_strWorkDir + m_stConfig.stScript.vctPaths[i];
			m_lpScriptSys->AddSysPath(szPath.c_str());
		}
		bRt = m_lpScriptSys->RunScriptFromFile(m_stConfig.stScript.strRoot.c_str());
	}
	if (!bRt) {
		std::cerr << "load script failed!" << std::endl;
	}
	return bRt;
}

inline bool ServerApp::LoadGlobalConfigure() {
	TiXmlDocument objDoc(m_szGlobleCfgPath.c_str());
	objDoc.LoadFile();

	if (objDoc.Error()
			&& objDoc.ErrorId() == TiXmlBase::TIXML_ERROR_OPENING_FILE) {
		std::cerr << "Load global configure xml file failed: "
				<< m_szGlobleCfgPath << std::endl;
		return false;
	}

	std::string pathKey;
	if (IsWin32()) {
		pathKey = "Win32WorkDirection";
	} else if (IsLinux()) {
		pathKey = "LinuxWorkDirection";
	}

	TiXmlNode* lpNode = objDoc.FirstChild(pathKey.c_str());
	if (lpNode != NULL) {
		TiXmlElement* lpElement = lpNode->ToElement();
		const char* lpszVal = lpElement->Attribute("value");
		if (lpszVal != NULL) {
			m_strWorkDir = lpszVal;
		}
	}

	return true;
}

inline bool ServerApp::LoadCommConfig(const char* lpszCfgPath) {
	assert(lpszCfgPath != NULL);
	if (lpszCfgPath == NULL) {
		return false;
	}

	TiXmlNode* lpNode = NULL;
	TiXmlElement* lpElement = NULL;
	int iVal = 0;

	std::string szPath = m_strWorkDir + lpszCfgPath;
	TiXmlDocument objDoc(szPath.c_str());
	objDoc.LoadFile();
	if (objDoc.Error()
			&& objDoc.ErrorId() == TiXmlBase::TIXML_ERROR_OPENING_FILE) {
		std::cerr << "Load configure xml file " << szPath << " failed!"
				<< std::endl;
		return false;
	}

	// ��ȡ��־���Ŀ¼
	lpNode = objDoc.FirstChild("Log");
	if (lpNode != NULL) {
		lpElement = lpNode->ToElement();
		const char* lpszVal = lpElement->Attribute("value");
		if (lpszVal != NULL) {
			m_stConfig.strLogFile = m_strWorkDir + lpszVal;
		}
	}

	// ��ȡ��ǰ��������Ψһ��ʶ����
	lpNode = objDoc.FirstChild("ServerName");
	if (lpNode != NULL) {
		lpElement = lpNode->ToElement();
		const char* lpszVal = lpElement->Attribute("value");
		if (lpszVal != NULL) {
			m_strNameId = lpszVal;
		}
	}

	// ��ȡ�ȴ�IOEvent��������
	lpNode = objDoc.FirstChild("IOEventMaxCount");
	if (lpNode != NULL) {
		lpElement = lpNode->ToElement();
		lpElement->Attribute("value", &iVal);
		m_iMaxEvents = iVal;
	}

	// ��ȡÿ��ѭ���ȴ���ʱ��������λ΢��
	lpNode = objDoc.FirstChild("SleepUs");
	if (lpNode != NULL) {
		lpElement = lpNode->ToElement();
		lpElement->Attribute("value", &iVal);
		m_uiSleepUs = iVal;
	}

	// ��ȡ�ȴ�IOEvent�ĳ�ʱ����λ�Ǻ���
	lpNode = objDoc.FirstChild("WaitIOEventTimeOutMs");
	if (lpNode != NULL) {
		lpElement = lpNode->ToElement();
		lpElement->Attribute("value", &iVal);
		m_uiWaitEventTimeOutMs = iVal;
	}

	// ��ȡ�ڵ���ѭ���пɴ���messager�а��������ֵ
	lpNode = objDoc.FirstChild("MessagerMaxCount");
	if (lpNode != NULL) {
		lpElement = lpNode->ToElement();
		lpElement->Attribute("value", &iVal);
		m_iMessagerMaxCount = iVal;
	}

	// ��ȡ��socket�İ󶨶˿�
	lpNode = objDoc.FirstChild("HostBindPort");
	if (lpNode != NULL) {
		lpElement = lpNode->ToElement();
		lpElement->Attribute("value", &iVal);
		m_usHostBindPort = iVal;
	}

	// ��ȡ��socket�ļ����������
	lpNode = objDoc.FirstChild("ListenNumber");
	if (lpNode != NULL) {
		lpElement = lpNode->ToElement();
		lpElement->Attribute("value", &iVal);
		m_iListenNumber = iVal;
	}

	// ��ȡ��socket�ķ��ͻ�������󳤶�
	lpNode = objDoc.FirstChild("HostSocketSendMaxLen");
	if (lpNode != NULL) {
		lpElement = lpNode->ToElement();
		lpElement->Attribute("value", &iVal);
		m_iHostSocketSendMaxLen = iVal;
	}

	// ��ȡ�ͻ���socket�Ľ��ջ�������󳤶�
	lpNode = objDoc.FirstChild("ClientSocketRecvMaxLen");
	if (lpNode != NULL) {
		lpElement = lpNode->ToElement();
		lpElement->Attribute("value", &iVal);
		m_iClientSocketRecvMaxLen = iVal;
	}

	// ��ȡ����socket�ķ��ͻ�������󳤶�
	lpNode = objDoc.FirstChild("ClientSocketSendMaxLen");
	if (lpNode != NULL) {
		lpElement = lpNode->ToElement();
		lpElement->Attribute("value", &iVal);
		m_iClientSocketSendMaxLen = iVal;
	}

	// ��ȡ����messager�Ļ�������󳤶�
	lpNode = objDoc.FirstChild("MessageBufferMaxSize");
	if (lpNode != NULL) {
		lpElement = lpNode->ToElement();
		lpElement->Attribute("value", &iVal);
		if (iVal > MESSAGER_RECV_LEN) {
			SafeDeleteArray(m_lpszMsgPkg);
			m_iMessageBufferMaxSize = iVal;
			m_lpszMsgPkg = new uchar[m_iMessageBufferMaxSize];
		}
	}

	// ��ȡ�������ӵ����ͻ�����
	lpNode = objDoc.FirstChild("ClientMaxSocketCount");
	if (lpNode != NULL) {
		lpElement = lpNode->ToElement();
		lpElement->Attribute("value", &iVal);
		m_iClientMaxSocketCount = iVal;
	}

	// ��ȡclient�ı��ּ����ʱ����,��λ��
	lpNode = objDoc.FirstChild("ClientActiveSec");
	if (lpNode != NULL) {
		lpElement = lpNode->ToElement();
		lpElement->Attribute("value", &iVal);
		m_uiClientActiveSec = iVal;
	}

	return true;
}

inline bool ServerApp::LoadDynRegConfig(const char* lpszCfgPath) {
	assert(lpszCfgPath != NULL);
	if (lpszCfgPath == NULL) {
		return false;
	}

	std::string szPath = m_strWorkDir + lpszCfgPath;
	if (!m_stConfig.LoadSysConfig(szPath.c_str())) {
		return false;
	}

	return true;
}

inline bool ServerApp::Configure(void) {
	return true;
}

inline bool ServerApp::LoadResources(void) {
	return true;
}

inline void ServerApp::OnBeforeWaitEvent() {
}

inline void ServerApp::OnBeforeRecvEvent() {
}

inline void ServerApp::OnAccept(int iSocketFd,
		const sockaddr_in& stClientAddr) {
}

inline void ServerApp::OnRecvEvent(const Net::SEvent* lpstEvent) {
}

inline void ServerApp::OnSendEvent(const Net::SEvent* lpstEvent) {
}

inline void ServerApp::OnBeforeRecvMessager() {
}

inline void ServerApp::OnRecvMessager() {
}

inline int ServerApp::OnCommandCfg(const char* cmd) {
	if (strcmp(cmd, "exit") == 0) {
		m_isRunning = false;
		return 1;
	}
	return 0;
}

inline void ServerApp::OnAfterRecv() {
}

inline void ServerApp::OnDestroy() {
}

inline bool ServerApp::CheckUnique() {
	return false;
}

inline bool ServerApp::Daemonize() {
#if defined(LINUX)
	pid_t pid = fork();
	if (pid > 0) {
		exit(0);
	} else if (pid < 0) {
		std::cerr << "Daemonize failed 1" << std::endl;
		exit(1);
		return false;
	}

	setsid();
	pid = fork();
	if (pid > 0) {
		exit(0);
	} else if (pid < 0) {
		std::cerr << "Daemonize failed 2" << std::endl;
		exit(1);
		return false;
	}

	umask(0);
	m_isDaemonized = true;
#endif// LINUX
	return true;
}

inline bool ServerApp::IsDaemonized() {
	return m_isDaemonized;
}

inline void ServerApp::CloseStdOut() {
#if defined(LINUX)
	close(0);
	close(1);
	close(2);
#endif// LINUX
}

inline void ServerApp::PendCommand(const char* cmd, const char* serverName) {
	if (cmd != NULL && serverName != NULL) {
		IO::Pipe* cmdCfgPipe = new IO::Pipe;
		const char* cmdCfgKey = m_shareMemKeyMgr.MakeKey(SMEMTYPE_CMD_CFG_HEAD, serverName);
		if (cmdCfgPipe->Init(cmdCfgKey, 4096, IO::PIPE_MUTEX_LOCK)) {
			cmdCfgPipe->Push(strlen(cmd) + 1, cmd);
		}
		SafeDelete(cmdCfgPipe);
	}
}

inline bool ServerApp::InitGameSys() {
	std::string szGameSysDllName = "./libGameSys";
	szGameSysDllName += DYNLIB_EXT;
	if (!m_objGameSysDynLib.Load(szGameSysDllName.c_str())) {
		assert(false);
		return false;
	}

	CREATEINTERFACE pfnCreate = (CREATEINTERFACE) m_objGameSysDynLib.GetSymbol(
			"CreateInterface");
	assert(pfnCreate != NULL);
	if (pfnCreate == NULL) {
		return false;
	}
	m_lpGameSys = reinterpret_cast<IGameSys*>(pfnCreate(IUID_IGAMESYS));

	// register from config
	if (m_lpGameSys != NULL) {
		// ע��ʹ��������е����нӿڶ���
		std::vector<IInterface*> vctObjs;
		StdMapRegIter iter = m_stConfig.mapRegs.begin();
		for (; iter != m_stConfig.mapRegs.end(); ++iter) {
			SRegInterface& stReg = (*iter).second;
			if (!m_lpGameSys->RegisterInterface(stReg.IGUID,
					stReg.strPath.c_str())) {
				std::cerr << "*RegisterInterface " << stReg.strPath
						<< " failed! " << std::endl;
				assert(false);
				return false;
			}

			if (stReg.strRegName != "") {
				IInterface* lpObj = m_lpGameSys->CreateInterface(stReg.IGUID);
				vctObjs.push_back(lpObj);
				if (lpObj == NULL) {
					std::cerr << stReg.strRegName << ": *CreateInterface "
							<< " failed! " << std::endl;
					assert(false);
					return false;
				} else {
					std::cout << "CreateInterface [" << stReg.strRegName
							<< "] ok! " << std::endl;
				}

				if (!m_lpGameSys->RegisterUserData(stReg.strRegName.c_str(),
						lpObj)) {
					std::cerr << "*RegisterUserData " << stReg.strRegName
							<< " failed! " << std::endl;
					assert(false);
					return false;
				}
			}
		}

		// �������нӿڶ���ĳ�ʼ�����
		std::vector<IInterface*>::iterator vctIter = vctObjs.begin();
		for (; vctIter != vctObjs.end(); ++vctIter) {
			(*vctIter)->OnOneTimeInit();
		}
	}
	return (m_lpGameSys != NULL);
}

inline bool ServerApp::InitGameObjects(void) {
	if (m_lpGameSys == NULL) {
		return false;
	}

	// ��ʼ����־ϵͳ
	ILogSys* lpLogSys = static_cast<ILogSys*>(m_lpGameSys->GetUserData(
			"ILogSys"));
	if (lpLogSys == NULL) {
		return false;
	}
	
	std::string comLog = m_stConfig.strLogFile + "_COM";
	lpLogSys->AddLog("COM", comLog.c_str(), 1, 50, 0x200000);
	
	std::string deal32WanLog = m_stConfig.strLogFile +"_DEAL_32WAN";
	lpLogSys->AddLog("DEAL_32WAN", deal32WanLog.c_str(), 1, 50, 0x200000);

	std::string onlinesLog = m_stConfig.strLogFile +"_ONLINES";
	lpLogSys->AddLog("ONLINES", onlinesLog.c_str(), 1, 50, 0x200000);

	std::string osLog = m_stConfig.strLogFile +"_OS";
	lpLogSys->AddLog("OS", osLog.c_str(), 1, 50, 0x200000);

	std::string acuLog = m_stConfig.strLogFile +"_ACU";
	lpLogSys->AddLog("ACU", acuLog.c_str(), 1, 50, 0x200000);

	std::string sugLog = m_stConfig.strLogFile +"_SUG";
	lpLogSys->AddLog("SUG", sugLog.c_str(), 1, 50, 0x200000);

	LOG_INIT(lpLogSys);
	LOG("COM",
	"----------------------- server log start -------------------------");

	m_lpUpdateSys = static_cast<IUpdateSys*>(m_lpGameSys->GetUserData(
			"IUpdateSys"));
	if (m_lpUpdateSys == NULL) {
		return false;
	}

	m_lpEventSys =
			static_cast<IEventSys*>(m_lpGameSys->GetUserData("IEventSys"));
	if (m_lpEventSys == NULL) {
		return false;
	}

	m_lpTime = static_cast<ITime*>(m_lpGameSys->GetUserData("ITime"));
	if (m_lpTime == NULL) {
		return false;
	}

	m_lpTimerQueue = static_cast<ITimerQueue*>(m_lpGameSys->GetUserData(
			"ITimerQueue"));
	if (m_lpTimerQueue == NULL) {
		return false;
	}

	if (!m_lpEventSys->Init(1024, 128)) {
		return false;
	}

	m_lpScriptSys = static_cast<Script::IScriptSys*>(m_lpGameSys->GetUserData(
			"IScriptSys"));
	if (m_lpScriptSys == NULL) {
		return false;
	}

	// ��ʼ��������
	if (!InitListeners()) {
		return false;
	}

	// ��ʼ���ű�ϵͳģ��
	if (!InitScriptModule()) {
		return false;
	}

	return true;
}

inline bool ServerApp::InitListeners(void) {
	if (m_lpGameSys == NULL) {
		return false;
	}

	// ����¼���������
	std::vector<std::string>::iterator iter =
			m_stConfig.stLoadDyn.vctEventListeners.begin();
	for (; iter != m_stConfig.stLoadDyn.vctEventListeners.end(); ++iter) {
		IInterface* lpInterface =
				reinterpret_cast<IInterface*>(m_lpGameSys->GetUserData(
						(*iter).c_str()));
		IEventListener* lpListener = static_cast<IEventListener*>(lpInterface);
		if (m_lpEventSys != NULL && lpListener != NULL) {
			m_lpEventSys->AddEventListener(lpListener);
			;
		}
	}

	// ��Ӹ��¼�������
	iter = m_stConfig.stLoadDyn.vctUpdateListeners.begin();
	for (; iter != m_stConfig.stLoadDyn.vctUpdateListeners.end(); ++iter) {
		IInterface* lpInterface =
				reinterpret_cast<IInterface*>(m_lpGameSys->GetUserData(
						(*iter).c_str()));
		IUpdateListener* lpListener = static_cast<IUpdateListener*>(lpInterface);
		if (m_lpUpdateSys != NULL && lpListener != NULL) {
			m_lpUpdateSys->AddUpdateListener(lpListener);
		}
	}

	return true;
}

inline int ServerApp::GetNetIOEventCount() {
	int iEventTotal = 0;
	if (m_iMaxEvents > 0) {
		iEventTotal = m_objNetIO->WaitEvent(m_uiWaitEventTimeOutMs);
	}
	if (iEventTotal < 0) {
		std::clog << "net io wait event failed!" << std::endl;
	}
	return iEventTotal;
}

inline void ServerApp::HandleNetIOEvents(int iEventCount) {
	for (int i = 0; i < iEventCount; ++i) {
		Net::SEvent* lpstEvent = m_objNetIO->GetEvent(i);
		HandleNetIOEvents(lpstEvent);
	}
}

inline void ServerApp::HandleRecvMessager() {
	for (int i = 0; i < m_iMessagerMaxCount; ++i) {
		m_iMsgLen = m_iMessageBufferMaxSize;
		int iRt = m_objMessager.Recv(m_ulMessagerFromSvrId, m_lpszMsgPkg,
				m_iMsgLen);
		if (iRt > 0) {
			m_iMsgLen = iRt;
			OnRecvMessager();
		} else {
			break;
		}
	}
}

inline void ServerApp::HandleCommandCfg() {
	if (m_lpCmdCfgPipe == NULL)
		return;
	char szCmdMsg[4096];
	int iCmdMsgLen = sizeof(szCmdMsg);
	if (m_lpCmdCfgPipe->Pop(iCmdMsgLen, szCmdMsg) == IO::TQ_IO_OK) {
		OnCommandCfg(szCmdMsg);
	}
}

inline void ServerApp::HandleNetIOEvents(Net::SEvent* lpstEvent) {
	if (lpstEvent->userPtr == &m_hostUser) {
		// accept the client connect
		sockaddr_in stClientAddr;
		int iAddrLen = sizeof(stClientAddr);
		int iSocketFd = m_objHostSocket.Accept((sockaddr *) &stClientAddr,
				&iAddrLen);
		if (iSocketFd < 0) {
			std::clog << "Accept one client connect failed!" << std::endl;
			return;
		}
		OnAccept(iSocketFd, stClientAddr);
	} else if ( lpstEvent->isRecvEvent()  ) {
		OnRecvEvent(lpstEvent);
	} else if ( lpstEvent->isWriteEvent() ) {
		OnSendEvent(lpstEvent);
	} else {
		std::clog << "unkown event !" << std::endl;
	}
}

inline bool ServerApp::InitScriptModule() {
	if (m_lpGameSys == NULL || m_lpScriptSys == NULL) {
		assert(false);
		return false;
	}

	StdMapRegScriptModuleIter iter =
			m_stConfig.stLoadDyn.mapScriptModules.begin();
	for (; iter != m_stConfig.stLoadDyn.mapScriptModules.end(); ++iter) {
		TQGUID& stId = (TQGUID&) ((*iter).first);
		SScriptModuleNode& stNode = (*iter).second;
		std::clog << "start load script module !" << std::endl;
		Script::IScriptModule* lpModule = NULL;
		if (stNode.strFlag == "GET") {
			lpModule =
					static_cast<Script::IScriptModule*>(m_lpGameSys->GetUserData(
							stNode.strName.c_str()));
		} else {
			lpModule =
					static_cast<Script::IScriptModule*>(m_lpGameSys->CreateInterface(
							stId));
		}

		std::clog << "start reg script module !" << std::endl;
		assert(lpModule!=NULL);
		if (lpModule != NULL) {
			std::clog << "init module !" << std::endl;
			if (stNode.strFlag != "GET") {
				lpModule->SetGameSys(m_lpGameSys);
				if (!lpModule->OnOneTimeInit()) {
					assert(false);
					return false;
				}
			}

			std::clog << "add module !" << std::endl;
			bool bRt = m_lpScriptSys->AddScriptModule(lpModule);
			std::clog << "add module ok!" << std::endl;
			assert(bRt);
			if (!bRt) {
				return false;
			}

			std::clog << "save module !" << std::endl;
			SScriptMoudleObj stMoudle;
			stMoudle.strFlag = stNode.strFlag;
			stMoudle.lpModule = lpModule;
			m_vctModules.push_back(stMoudle);
		}
	}
	return true;
}

inline void ServerApp::SetGlobalCfgPath(const char* path) {
	m_szGlobleCfgPath = path;
}

inline void ServerApp::StopServer(const char* svrname) {
	if (svrname != NULL && strcmp(svrname, "") != 0) {
		PendCommand("exit", svrname);
		std::cout << "send stop server command!" << std::endl;
	}
}

inline void ServerApp::ReleaseGameSys(void) {
	if (m_lpGameSys != NULL) {
		// �������нӿڵ�OnOneTimeRelease���
		StdMapRegIter iter = m_stConfig.mapRegs.begin();
		for (; iter != m_stConfig.mapRegs.end(); ++iter) {
			SRegInterface& stReg = (*iter).second;
			if (stReg.strRegName != "") {
				IInterface* lpInterface =
						reinterpret_cast<IInterface*>(m_lpGameSys->GetUserData(
								stReg.strRegName.c_str()));
				if (lpInterface != NULL) {
					lpInterface->OnOneTimeRelease();
				}
			}
		}

		// �������еĽű�ģ������OnOneTimeRelease���
		StdVctScriptModuleIter iterSM = m_vctModules.begin();
		for (; iterSM != m_vctModules.end(); ++iterSM) {
			Script::IScriptModule* lpModule = (*iterSM).lpModule;
			if ((*iterSM).strFlag != "GET") {
				lpModule->OnOneTimeRelease();
			}
		}

		// �ͷ����нӿ�
		for (iter = m_stConfig.mapRegs.begin();
				iter != m_stConfig.mapRegs.end(); ++iter) {
			SRegInterface& stReg = (*iter).second;
			if (stReg.strRegName != "") {
				IInterface* lpInterface =
						reinterpret_cast<IInterface*>(m_lpGameSys->GetUserData(
								stReg.strRegName.c_str()));
				if (lpInterface != NULL) {
					m_lpGameSys->DestroyInterface(&lpInterface);
				}
			}
		}

		// �ͷ����еĽű�ģ�����
		iterSM = m_vctModules.begin();
		for (; iterSM != m_vctModules.end(); ++iterSM) {
			Script::IScriptModule* lpModule = (*iterSM).lpModule;
			if ((*iterSM).strFlag != "GET") {
				m_lpGameSys->DestroyInterface((IInterface**) &lpModule);
			}

		}

		// �ͷ���Ϸϵͳ����
		DESTROYINTERFACE pfnDestory =
				(DESTROYINTERFACE) m_objGameSysDynLib.GetSymbol(
						"DestroyInterface");
		assert(pfnDestory != NULL);
		if (pfnDestory != NULL) {
			pfnDestory(reinterpret_cast<IInterface**>(&m_lpGameSys));
		}
	}
}

inline bool ServerApp::IsExist(const char* svrname) {
	const char* mutexKey = m_shareMemKeyMgr.MakeKey(SMEMTYPE_MUTEX_GAME, svrname);
	bool existFlag = false;
	m_mutex = CreateShareMem(mutexKey, 1, existFlag);
	if (m_mutex == INVAILED_SHAREMEM_HANDLE) {
		std::cerr << "IsExist: create mutex share mem failed" << std::endl;
		return true;
	}

	if (existFlag) {
		std::cerr << "IsExist: server :" << svrname << " exist!" << std::endl;
		m_mutex = INVAILED_SHAREMEM_HANDLE;
		return true;
	}
	
	return false;
}

inline void ServerApp::Release() {
	if (m_mutex != INVAILED_SHAREMEM_HANDLE) {
		ReleaseShareMem(m_mutex);
		m_mutex = INVAILED_SHAREMEM_HANDLE;
	}
}

#endif // _SERVERAPP_H_
