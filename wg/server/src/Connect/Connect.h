#ifndef _TQ_CONNECT_H_
#define _TQ_CONNECT_H_
#include <commhead.h>
#include <serverApp.h>
#include <Socket.h>
#include <messagerCmd.h>
#include <ObjContainer.h>
#include "User.h"
#include "GameSvrMessager.h"
#include "./zlib/zlib.h"

#define USE_GZIP_FLAG true
#define USE_GZIP_LEN 256


class Connect: public IReconnectCallback, public ServerApp {
public:
	virtual bool Init();
	virtual bool Configure();
	virtual void OnBeforeWaitEvent();
	virtual void OnAccept(int iSocketFd, const sockaddr_in& stClientAddr);
	virtual void OnRecvEvent(const Net::SEvent* lpstEvent);
	virtual void OnRecvMessager();
	virtual int OnCommandCfg(const char* cmd);
	virtual void OnDestroy();
	virtual bool Reconnected(User* curUser, object_id existUserid, const char* cltKey);

public:
	/** ���캯�� */
	Connect();

	/** �������� */
	virtual ~Connect();

public:
	/** ���õ�ǰ�ķ���������Ŀ¼
	 @param lpszSvrCfgDir ��ǰ�������������ļ�Ŀ¼
	 */
	virtual void SetSvrCfgDir(const char* lpszSvrCfgDir);
	virtual void ShowHelpInfo();
	virtual void StartGame(const char* svrname);

protected:
	virtual void HandleAccept(int iSocketFd, const sockaddr_in& stClientAddr);
	virtual void HandleRecvData(const Net::SEvent* lpstEvent);
	virtual bool HandleRecvData(User* user, char* recvBuf, int recvLen);
	virtual bool AddNetIoInEvent(int socket, User* user);
	virtual void DelNetIoEvent(User* user);

private:
	void SetServerVersion();
	void SetWin32CompletionRecvLen();
	void SetSocketObject(Net::Socket &objSocket, int iSocketFd);
	bool InitSimObjContainer();
	User* NewUser(const sockaddr_in& addr, int socket);
	User* NewTmpUser(const sockaddr_in& stClientAddr, int iSocket);
	bool InitMessager();

	void FreeUser(User* lpUser);
	void ExitUser(User* user);

	void UpdateUsers();

	bool IsExitSysCmd(const char* cmd);
	char* AssignHandler(User* user, char* recvBuf, int& recvLen);
	void FreeListUsers(ObjContainer<User>* list);

	void CheckOnlineUserActive();
	void CheckTmpUserActive();
	void CheckUserActive(uint32& curIdx, ObjContainer<User>* container, bool isSendMsg);

protected:
	/// ���������õ����Ŀ¼
	std::string m_svrCfgDir;
	/// ���user�ڵ�ĵ�ǰ�����������
	ObjContainer<User> m_userContainer;
	ObjContainer<User> m_tmpUsers;
	/// ��ǰ�����user�Ƿ��ڼ�����±�������,ÿһ��ѭ�������һ��
	uint32 m_curCheckUserActiveIndex;
	uint32 m_curCheckTmpUserActiveIndex;
	/// �͵�ǰhttpsvr���������Ϸ������id
	int m_gameSvrId;
	/// ������Ϸ������messager
	GameSvrMessager m_gameSvrMessager;
};

#endif // _TQ_CONNECT_H_
