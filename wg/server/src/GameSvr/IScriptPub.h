#ifndef _TQ_I_SCRIPT_PUB_H_
#define _TQ_I_SCRIPT_PUB_H_
#include <IInterface.h>
#include "tqRoleVar.h"
#include <IDatabase.h>

class SPlayer;
using namespace IO;

//tolua_begin
enum EGameUserState {
	/// ��ʼ��״̬
	EGUS_INIT,
	/// FlashУ��״̬
	EGUS_CHECK_CROSS,
	/// ���ڵ�¼
	EGUS_LOGINNING,
	/// ������ɫ״̬
	EGUS_CREATEROLE,
	/// ����Ϸ��
	EGUS_INGAME,
	/// ��������Ϸ�У���������������룬���ɳ����Զ�����
	EGUS_OFFLINE_INGAME,
	/// ���ڹر�״̬
	EGUS_WILLCLOSE,
};
//tolua_end

//tolua_begin
struct ScriptEvent : public SBaseEvent {
	/// connect server id
	int connid;
	/// �������¼�����Ҷ���id
	object_id playerid;
	/// �������ݻ��峤��
	int datalen;
	/// �������ݻ���
	char* data;
	//tolua_end
	
	/** ���캯�� */
	ScriptEvent():connid(0),playerid(0),datalen(0),data(NULL){}
	virtual ~ScriptEvent(){}
	/** ��õ�ǰ�ṹ��С */
	virtual int GetSize(){ return sizeof(ScriptEvent); }
	
	//tolua_begin
};
//tolua_end

//tolua_begin
struct TimerEvent : public SBaseEvent {
	/// ʱ�Ӿ��
	int hdr;
	/// connect server id
	int connid;
	/// �������¼�����Ҷ���id
	object_id playerid;
	/// �¼�ID
	uint32 eventid;
	/// ��ǰʱ��
	uint32 curtimeMs;
	/// ����
	int64 param1;
	/// ����
	int64 param2;
	//tolua_end
	
	/** ���캯�� */
	TimerEvent():hdr(0),connid(0),playerid(0),eventid(0),curtimeMs(0),param1(0),param2(0){}
	virtual ~TimerEvent(){}
	/** ��õ�ǰ�ṹ��С */
	virtual int GetSize(){ return sizeof(TimerEvent); }
	
	//tolua_begin
};
//tolua_end

struct TimerUserData {
	/// connect server id
	int connid;
	/// �������¼�����Ҷ���id
	object_id playerid;
	/// ����
	int64 param1;
	/// ����
	int64 param2;
};


//tolua_begin
class IScriptPub : public IInterface {
public:

	virtual object_id MakeNewRoleId(const SDBVar* dbvar) = 0;

	/** ������ɫ 
	*/
	virtual int CreateRole(const SDBVar* dbvar) = 0;

	/** �û���¼��Ϸ
	*/
	virtual int RoleLogin(SDBVar* dbvar, const char* username, int zoneid) = 0;

	/** ��ɫ���ݱ���
	*/
	virtual int RoleSave(const SDBVar* dbvar) = 0;

	/** �û��ǳ���Ϸ
	*/
	virtual void RoleLogout(const SPlayer* lpPlayer, int iReason) = 0;

	/** ��ָ��id�Ŀͻ��˷�����Ϣ
	*/
	virtual void SendMsg(object_id id, int connid, const char* msg) = 0;

	/** 
	*/
	virtual void SendMsgNotifyCmd(object_id id, int connid, int cmd) = 0;

	/** 
	*/
	virtual void SendUseKeyCmd(object_id id, int connid, const char* key) = 0;

	virtual SDBVar* AllocDBVar() = 0;

	virtual void FreeDBVar(SDBVar* dbvar) = 0;

	virtual bool IsExistRoleName(const char* rolename) = 0;
	
	virtual bool IsExistUserName(const char* username) = 0;

	virtual int InitAlliByUID(object_id id, SDBAlliVar* dballivar) = 0;

	virtual SDBAlliVar* AllocDBAlliVar() = 0;
 
	virtual void FreeDBAlliVar(SDBAlliVar* dbvar) = 0;

	virtual TimerUserData* AllocTimerUserData() = 0;

	virtual void FreeTimerUserData(TimerUserData* userdata) = 0;

	virtual ushort GetZoneId() = 0;

	virtual IDatabase* GetDBConn() = 0;
	
	virtual void ClearInnerHero(const SHero* hero) = 0;

	virtual int32 diffTimeMs(uint32 time1, uint32 time2) = 0;

	virtual uint32 getTimeMs() = 0;
	
	virtual uint64 getTimeMsEx() = 0;

	virtual const char* GetCfgBasePath() = 0;
	
	virtual const char* GetLogBasePath() = 0;
	
	virtual const char* GetSvrNameId() = 0;

	virtual ~IScriptPub(){}
};
//tolua_end

#endif // _TQ_I_SCRIPT_PUB_H_





