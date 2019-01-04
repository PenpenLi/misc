#ifndef _I_GAMESYS_H
#define _I_GAMESYS_H
#include "IInterface.h"

// {6B57354B-57D9-4eec-AD41-F657304DC77D}
static const TQGUID IUID_IGAMESYS = { 0x6b57354b, 0x57d9, 0x4eec, { 0xad, 0x41,
		0xf6, 0x57, 0x30, 0x4d, 0xc7, 0x7d } };

//tolua_begin

/** �ṩ�������ӿڶ���ע��ͷ��ʵĶ����������ṩ�ӿ��ڲ����໥����һ��
 ;������˴������ǽӿڼ���ʵ���������໥֮�����Ϲ�ϵ��
 */
class IGameSys: public IInterface {
public:
	/** ��ʼ����Ϸϵͳ
	 */
	virtual bool Init() = 0;

	/** ����Ϸϵͳע��һ������ĳ��IUID�Ľӿ�����Ķ�̬�⣬��@see IGameSys::CreateInterfaceʹ��
	 @param guid
	 �ӿڵ�Ψһ��ʾID
	 @param dllName
	 ��̬���·���ļ���
	 @return
	 ����true��false
	 */
	virtual bool RegisterInterface(const TQGUID& guid,
			const char* dllName) = 0;

	/** ͨ��IUID����һ���ӿڶ���
	 @param guid
	 �ӿڵ�Ψһ��ʾID
	 @param guidName
	 �ӿڵ�Ψһ��ʾ�ַ���, ͬguid
	 @return
	 ���ؽӿڶ���, ΪNULLʱ����ʧ��.
	 */
	virtual IInterface* CreateInterface(const TQGUID& guid) = 0;
	virtual IInterface* CreateInterface(const char* guidName)= 0;

	/** ͨ��IUID����ͬʱ��ʼ��һ���ӿڶ���
	 @remark
	 ��CreateInterface�������ǣ������ĵ��øýӿڵ�OnOneTimeInit��Ա����
	 @param guid
	 �ӿڵ�Ψһ��ʾID
	 @param guidName
	 �ӿڵ�Ψһ��ʾ�ַ���, ͬguid
	 @return
	 ���ؽӿڶ���, ΪNULLʱ����ʧ��.
	 */
	virtual IInterface* CreateAndInitInterface(const TQGUID& guid) = 0;
	virtual IInterface* CreateAndInitInterface(const char* guidName)= 0;

	/** ����һ���ӿڶ���
	 @param interFace
	 Ҫ�����ٵĽӿڶ����ָ��
	 */
	virtual void DestroyInterface(IInterface** interFace) = 0;

	/** ������ʵ��, �û������������ע��һ���û�����ָ��, ���û�����ָ���һ��keyֵ��
	 һ������ø÷���ע��һ���ӿڶ���, ����m_lpGameSys->RegisterUserData("EventSys", m_lpEventSys)
	 @param key
	 �û����ݵ�keyֵ
	 @param userData
	 �û�����ָ��
	 @return
	 ����true��false, ����false��ʾ��keyֵ�Ѿ���ʹ�û����Ϊ��
	 */
	virtual bool RegisterUserData(const char* key, void* userData) = 0;

	/** ע��һ���û�����ָ��
	 @param key
	 �û����ݵ�keyֵ
	 */
	virtual void UnRegisterUserData(const char* key) = 0;

	/** ͨ��keyֵ���һ���û�����ָ��
	 @param key
	 �û����ݵ�keyֵ
	 @return
	 �����û�����ָ��
	 */
	virtual void* GetUserData(const char* key) = 0;
};

#endif // _I_GAMESYS_H
