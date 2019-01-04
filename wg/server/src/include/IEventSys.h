#ifndef _I_EVENTSYS_H_
#define _I_EVENTSYS_H_
#include "IInterface.h"
//#include "delegation.h"
#include "IEventListener.h"

// {04E37DAE-9D02-40db-91CA-306D01AB624E}
static const TQGUID IUID_IEVENTSYS = { 0x4e37dae, 0x9d02, 0x40db, { 0x91, 0xca,
		0x30, 0x6d, 0x1, 0xab, 0x62, 0x4e } };

//tolua_begin

/** �¼�ϵͳ��ʼ����־ */
enum EEventSysFlag {
	/// ����ͬ����־
	EESF_NOT_LOCK = 0,
	/// ����ͬ����־
	EESF_MUTEX_LOCK = 1,
};

/** ��Ҫ�����¼����е�ά�����¼��ķַ�����
 */
class IEventSys: public IInterface {
public:
	/** ��ʼ���¼�����ϵͳ
	 @param count
	 ��ʼ���¼��ڵ����
	 @param handlePendMaxTimes
	 ��һ֡�д���pend�������¼��ĸ���
	 @return
	 ����true��ʼ�����ɹ���
	 */
	virtual bool Init(uint32 count, uint32 handlePendMaxTimes) = 0;

	/** �����¼�����
	 @return
	 ����0��ʾ����Ϣ����������ʾ��������ͣ�����Ϊ������Ϣ�ĸ���
	 */
	virtual int ProcessPendEvents()= 0;

	/** ���¼�����ϵͳ����һ���¼���Ϣ����Ҫ������������
	 @param event
	 �¼���Ϣ����
	 @return
	 ����0��ʾ�ɹ�, ������ʾ��������͡�
	 */
	virtual int SendEvent(SEvent& event) = 0;

	/** ���¼�����ϵͳ���¼������з���һ���¼���Ϣ������Ҫ���������޷���ֵ
	 @param event
	 �¼���Ϣ����
	 */
	virtual void PendEvent(SEvent& event) = 0;

	/** ����¼���������
	 @param listener
	 ��Ҫ����ӵ��¼���������
	 */
	virtual void AddEventListener(IEventListener* listener) = 0;

	/** ɾ��ָ�������ŵ��¼���������
	 @param idx
	 ����������
	 */
	virtual void DelEventListener(int idx) = 0;

	/** ��ȡ�¼���������ĸ���
	 @return
	 �����¼���������ĸ���
	 */
	virtual int GetEventListenerCount() = 0;

};

//tolua_end

#endif // _I_EVENTSYS_H_
