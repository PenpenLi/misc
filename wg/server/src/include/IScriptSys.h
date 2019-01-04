#ifndef _I_SCRIPTSYS_H_
#define _I_SCRIPTSYS_H_
#include "IGameSys.h"
#include "IUpdateListener.h"

extern "C" _TQ_EXPORT void *l_alloc(void *ud, void *ptr, size_t osize,
		size_t nsize);

// {ECC0929B-11DC-4175-BCE9-E9AED369DBE1}
static const TQGUID IUID_ISCRIPTSYS = { 0xecc0929b, 0x11dc, 0x4175, { 0xbc,
		0xe9, 0xe9, 0xae, 0xd3, 0x69, 0xdb, 0xe1 } };

// {DCC0925B-32DC-31AB-AAC9-E9AED36990E1}
static const TQGUID IUID_ISMCOM = { 0xdcc0925b, 0x32dc, 0x31ab, { 0xaa, 0xc9,
		0xe9, 0xae, 0xd3, 0x69, 0x90, 0xe1 } };

// {49C092A0-74BE-56DD-BBC9-E9CCD36990CB}
static const TQGUID IUID_ISMCLT = { 0x49c092a0, 0x74BE, 0x56dd, { 0xbb, 0xc9,
		0xe9, 0xcc, 0xd3, 0x69, 0x90, 0xcb } };

// {AA8A7BA0-0265-457d-AA3E-8F33AA002873}
static const TQGUID IUID_ISM_WEB_SVR = { 0xaa8a7ba0, 0x265, 0x457d, { 0xaa,
		0x3e, 0x8f, 0x33, 0xaa, 0x0, 0x28, 0x73 } };

// {87DFBE31-1D48-4171-B43C-EEF292173DE4}
static const TQGUID IUID_ISMDBG = { 0x87dfbe31, 0x1d48, 0x4171, { 0xb4, 0x3c,
		0xee, 0xf2, 0x92, 0x17, 0x3d, 0xe4 } };

namespace Script {
/** �ű�ģ��ӿ�
 �ڸ�ģ����ʵ���µĽű��ӿڵ������Զ�̬�����ʽ�ṩ��
 IScriptSys::AddScriptModule��״̬��ʼ��
 */
class IScriptSys;
class IScriptModule: public IInterface {
public:
	/** ��ʼ���ű����л���
	 @param lpScriptSys
	 �ű�ϵͳ
	 @param lpScriptEnv
	 ��ǰ�ű���ȫ�����л���
	 @return
	 ����true��ʾ��ʼ���ɹ�
	 */
	virtual bool InitScriptEnvironment(IScriptSys* lpScriptSys,
			void* lpScriptEnv) = 0;
};

/** �ű�ϵͳ�ӿ�
 */
class IScriptSys //tolua_export
		: public IInterface
{ //tolua_export
public:
	//tolua_begin
	/** ����Ѽ��ص��ļ�����
	 */
	virtual void ClearLoaded() = 0;
	//tolua_end

	/** ��ű�ϵͳ���һ���ű�ģ��
	 @param lpScriptModule
	 �ű�ģ��Ķ���ָ��
	 @return
	 ����true��false
	 */
	virtual bool AddScriptModule(const IScriptModule* lpScriptModule) = 0;

	/** ���һ���ű����е�ϵͳĿ¼,�ڽű�����ʱ,�᳢�ԴӸ�·������
	 һ��������Ľű��ļ��Ƿ����,����python��import,lua��require
	 @param lpszPath
	 ��Ҫ���õ�ϵͳ·��
	 */
	virtual void AddSysPath(const char* lpszPath) = 0;

	/** װ�ز�����һ���ű��ļ�
	 @param lpszName
	 �ű��ļ�·����
	 @return
	 ����true��false
	 */
	virtual bool RunScriptFromFile(const char* lpszName) = 0;

	/** װ��һ���ű��ļ�
	 @param lpszName
	 �ű��ļ�·����
	 @return
	 ����0��ʾ�ɹ�
	 */
	virtual int LoadScriptFromFile(const char* lpszName) = 0;

	/** ֻ����һ�νű�
	 @param lpScriptString
	 �ű��������ָ��
	 */
	virtual int RunScriptString(const char* lpScriptString) = 0;

	/** ������һ�νű����еĴ���
	 */
	virtual const char* GetLastError() const = 0;
}; //tolua_export

}// end Script namespace

#endif // _I_SCRIPTSYS_H_

