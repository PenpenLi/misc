#ifndef _GAMESCRIPT_H_
#define _GAMESCRIPT_H_

#include <IScriptSys.h>
#include <IEventSys.h>
#include <IEventHandlerMgr.h>

struct lua_State;
extern int tolua_tqAllTolua_open(lua_State* tolua_S);

namespace Script {

class DynSMWebSvr: public IScriptModule {
DECLARE_TQINTERFACE()DECLARE_DEFAULT_RENDERLISTENER()
DECLARE_IEVENTHANDLERMGR()
	;

public:
	bool InitScriptEnvironment(IScriptSys* lpScriptSys, void* lpScriptEnv);
	bool OnOneTimeInit();
	void OnOneTimeRelease() {
	}
	;
	void OnEvent(SEvent& stEvent);
	void OnOneEvent(SEvent& stEvent);
	virtual void OnUpdate(uint32 timeMs);

public:
	/** ���캯�� */
	DynSMWebSvr();
	/** �������� */
	virtual ~DynSMWebSvr();

private:
	/** ע��lua����
	 @param lpLuaState
	 lua״̬����
	 */
	void RegisterLuaFun(lua_State* lpLuaState);
	void SendEventToScript(SEvent& stEvent);
	void UpdateScript(uint32 timeMs);

private:
	lua_State* m_lpLuaState;
	uint32 m_lastTimeMs;
};

} // end namespace Script

#endif // _GAMESCRIPT_H_
