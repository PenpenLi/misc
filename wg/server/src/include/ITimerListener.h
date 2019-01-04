#ifndef _I_TIMERLISTENER_H
#define _I_TIMERLISTENER_H

/** �ýӿ�����������ʱ�Ӵ����¼��ģ�������Ҫʱ�������Ķ������̳��ڸýӿ�
 */
class ITimerListener {
public:
	/** ����ʱ�ӻص�����
	 @param hHdr
	 ��ʱ�Ӷ�Ӧ�ľ��
	 @param lIdEvent
	 ��ʱ�Ӷ�Ӧ���¼�id
	 @param lpUserData
	 ��ʱ�Ӷ�Ӧ���û�����
	 @param lCurTimeMs
	 ��ǰϵͳ�ľ���ʱ�䣬��λ����
	 */
	virtual void OnTimer(TQHANDLE hHdr, int32 lIdEvent, void* lpUserData,
			int32 lCurTimeMs) = 0;
};

class TIMER_IDS;
class TIMER_PARAMS;

class ITimerListenerEx {
public:
	virtual void OnTimer(const TIMER_IDS* ids, const TIMER_PARAMS* params,
			uint32 curTimeMs) = 0;
};

#endif // _I_TIMERLISTENER_H
