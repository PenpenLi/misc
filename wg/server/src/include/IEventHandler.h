#ifndef _I_EVENT_HANDLER_H_
#define _I_EVENT_HANDLER_H_
#include "IInterface.h"
#include "IEventListener.h"
#include "delegation.h"
#include <list>

// {C962C784-4C24-45db-BE06-493EDF8FAA27}
static const TQGUID IUID_IEVENTHANDLER = { 0xc962c784, 0x4c24, 0x45db, { 0xbe,
		0x6, 0x49, 0x3e, 0xdf, 0x8f, 0xaa, 0x27 } };

enum EEventType;
typedef Delegation0<void, SEvent&> DelegationEvent;

/** �¼�ϵͳ��ʼ����־ */
enum EEventHandlerFlag {
	/// ����ͬ����־
	EEHF_NOT_LOCK = 0,
	/// ����ͬ����־
	EEHF_MUTEX_LOCK = 1,
};

/** �¼��ص�ע���ṹ
 */
struct SEventTable {
	/// �������¼�������ʼid
	object_id lObjFromId;
	/// �������¼�������ֹid
	object_id lObjToId;
	/// Ҫ������¼�����ID
	EEventType eEventType;
	/// ������¼��Ļص�����
	DelegationEvent objCallback;
	/// ������û����ݶ���
	UserDataObject objUserData;
};

typedef std::list<SEventTable> StdLstEventTable;
typedef StdLstEventTable::iterator StdLstEventTableIter;

/** �¼��������ӿ�
 */
class IEventHandler: public IInterface {
public:
	/** ��ʼ�����¼��������ӿ�
	 @param iInitNodeCount
	 ��������ע��ĳ�ʼ�ڵ����
	 @param eFlag
	 �Ƿ���Ҫ�߳�ͬ���ı�����־
	 @return
	 ����true��false
	 */
	virtual bool Init(int iInitNodeCount, EEventHandlerFlag eFlag) = 0;

	/** ע��һ����ĳ���¼��Ķ���ص��ӿ�
	 @param lObjFromId
	 �������¼�������ʼid
	 @param lObjToId
	 �������¼�������ֹid
	 @param eEventType
	 Ҫ������¼�����ID
	 @param objCallback
	 ������¼��Ļص�����
	 @param objUserData
	 ������û����ݶ���
	 @return
	 ���ظ�ע������ΪNULLʱ��ʾʧ�ܡ��þ����Ҫ��UnRegisterʹ�á�
	 */
	virtual TQHANDLE Register(object_id lObjFromId, object_id lObjToId,
			EEventType eEventType, const DelegationEvent& objCallback,
			const UserDataObject* lpUserData) = 0;

	/** ע��һ���¼�������
	 @param hHandle
	 �¼�ע���������ɺ���Register���ص�ֵ��
	 */
	virtual void UnRegister(TQHANDLE hHandle) = 0;

	/** ���ص�ǰ���¼��������Ƿ����
	 */
	virtual bool GetEvtHandlerEnabled() = 0;

	/** ���¼�����������,��õ�ǰ���������¸��ֵܴ���������ָ��
	 */
	virtual const IEventHandler* GetNextHandler() const = 0;

	/** ���¼�����������,��õ�ǰ��������ǰһ���ֵܴ���������ָ��
	 */
	virtual const IEventHandler* GetPreviousHandler() const = 0;

	/** ����һ���¼���Ϣ
	 @param stEvent
	 �¼���Ϣ
	 */
	virtual void ProcessEvent(SEvent& stEvent) = 0;

	/** ���û�رյ�ǰ����������Ч��
	 @remarks
	 ����ʹ�øú���ʵ�ֱ��������ɾ��,ͬʱ����ʵ�ֲ���Ӧ�¼�
	 @param bEnabled
	 true��false
	 */
	virtual void SetEvtHandlerEnabled(bool bEnabled) = 0;

	/** ���õ�ǰ����������һ���ֵܴ�����ָ��
	 @param lpHandler
	 ��һ���ֵܴ�����ָ��
	 */
	virtual void SetNextHandler(const IEventHandler* lpHandler) = 0;

	/** ���õ�ǰ����������һ���ֵܴ�����ָ��
	 @param lpHandler
	 ��һ���ֵܴ�����ָ��
	 */
	virtual void SetPreviousHandler(const IEventHandler* lpHandler) = 0;
};

#endif // _I_EVENT_HANDLER_H_
