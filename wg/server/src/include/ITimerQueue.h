#ifndef _I_TIMERQUEUE_H
#define _I_TIMERQUEUE_H
#include "IInterface.h"
#include "ITimerListener.h"

typedef void* TQHANDLE;

// {7292645E-9B07-4c76-926B-332D18F40577}
static const TQGUID IUID_ITIMERQUEUE = { 0x7292645e, 0x9b07, 0x4c76, { 0x92,
		0x6b, 0x33, 0x2d, 0x18, 0xf4, 0x5, 0x77 } };
// {2292646E-1B07-4175-826C-222D18F40577}
static const TQGUID IUID_ITIMERQUEUE_EX = { 0x2292646E, 0x1b07, 0x4175, { 0x82,
		0x6c, 0x22, 0x2d, 0x18, 0xf4, 0x5, 0x77 } };

/** ʱ����нӿ� */
class ITimerQueue: public IInterface {
public:
	/** ��ʼ��ʱ�Ӷ��е���С���ȣ���λ�Ǻ���
	 @param ulPrecisionMs
	 ʱ�Ӷ��е���С���ȣ���λ����
	 @return
	 ����true��ʼ�����ɹ���
	 */
	virtual bool Init(uint32 ulPrecisionMs) = 0;

	/** ��ʱ�Ӷ����У�����һ��ʱ��
	 @param ulIdEvent
	 ��ʱ�ӵ��¼�id����ֵ����ITimerListener::OnTimer()����ʱ������
	 @param lpUserData
	 ��ʱ�ӵ��û�����
	 @param ulElapseMs
	 ��ʱ�ӽ���������ʱ����
	 @param lpTimer
	 ��ʱ�ӱ�����ʱ�������õļ�������
	 @return
	 �����ظ�ʱ�ӵľ����ΪNULLʱ��ʾ���ʧ�ܡ��þ���������ͷŸ�ʱ�ӽڵ㣬
	 �μ�@see ITimerQueue::KillTimer��
	 */
	virtual TQHANDLE SetTimer(uint32 ulIdEvent, void* lpUserData,
			uint32 ulElapseMs, ITimerListener* lpTimer) = 0;

	/** ͨ��ʱ�Ӿ����ð󶨵�userdata
	 @param hTimer
	 ʱ�Ӿ��
	 @return
	 �����û�����
	 */
	virtual void* GetUserData(TQHANDLE hTimer) = 0;

	/** Kill��ĳ��ʱ�ӽڵ�
	 @param hTimer
	 ��Ҫ��Kill��ʱ�ӽڵ������þ������@see ITimerQueue::SetTimer ����
	 */
	virtual bool KillTimer(TQHANDLE hTimer) = 0;

	virtual void Print() = 0; // for debug
};

const int TIMER_IDS_COUNT = 8;
class TIMER_IDS {
public:
	char keyCount;
	uint32 ids[TIMER_IDS_COUNT];
	bool operator<(const TIMER_IDS& ids) const {
		for (int i = 0; i < keyCount; ++i) {
			if (this->ids[i] < ids.ids[i])
				return true;
		}
		return false;
	}

	TIMER_IDS() {
		keyCount = 0;
		memset(this->ids, 0, sizeof(this->ids));
	}

	TIMER_IDS(const TIMER_IDS& ids, int keyCount) {
		this->keyCount = keyCount;
		for (int i = 0; i < TIMER_IDS_COUNT; ++i) {
			this->ids[i] = ids.ids[i];
		}
	}
};

const int TIMER_PARAMS_COUNT = 2;
class TIMER_PARAMS {
public:
	uint32 ps[TIMER_PARAMS_COUNT];
};

class ITimerQueueEx: public IInterface {
public:
	virtual bool Init(uint32 queueSize, uint32 precisionMs) = 0;
	virtual TIMER_IDS* GetConstIds() = 0;
	virtual TIMER_PARAMS* GetConstParams() = 0;
	virtual void Start(int keyIdCnt, const TIMER_IDS* ids, uint32 elapseMs,
			const TIMER_PARAMS* params, ITimerListenerEx* timerListener) = 0;
	virtual void Stop() = 0;
};

#endif // _I_TIMERQUEUE_H
