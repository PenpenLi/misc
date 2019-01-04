#ifndef _TQ_DYNSMCOM_H_
#define _TQ_DYNSMCOM_H_
#include <IScriptSys.h>
#include "GameSys.h"
struct lua_State;
extern int luaopen_tqAllTolua(lua_State* tolua_S);

namespace Script {
class DynSMCom: public IScriptModule {
DECLARE_TQINTERFACE()DECLARE_DEFAULT_EVENTLISTENER()
	DECLARE_DEFAULT_RENDERLISTENER()
	DECLARE_DEFAULT_UPDATELISTENER()

public:
	bool InitScriptEnvironment(IScriptSys* lpScriptSys, void* lpScriptEnv);
	bool OnOneTimeInit();
	void OnOneTimeRelease() {
	}
	;

public:
	/** ���캯�� */
	DynSMCom();
	/** �������� */
	virtual ~DynSMCom();

private:
	/** ע��lua����
	 @param lpLuaState
	 lua״̬����
	 */
	void RegisterLuaFun(lua_State* lpLuaState);

private:
	lua_State* m_lpLuaState;
};

} // end namespace Script

#endif // _TQ_DYNSMCOM_H_
