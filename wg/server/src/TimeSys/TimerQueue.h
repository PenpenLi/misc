/*
 * TimerQueue.h
 *
 *  Created on: 2013-3-6
 *      Author: qujianbiao
 */

#ifndef TIMERQUEUE_H_
#define TIMERQUEUE_H_
#include <ITimerQueue.h>
#include <ptrList.h>
#include <fixAlloc.h>
#include <ITime.h>

enum ETimerConstant {
	//��ߵ�ʱ�Ӿ���ֵ(����)
	ETCX_MAX_PRECISION = 500,
	//��ʼ��ʱ�ڵ�������ĳ�ʼ����
	ETCX_ALLOC_NODE_COUNT = 8192,
	//ʱ�Ӷ����нڵ����
	ETCX_TIMER_NODE_COUNT = 7200,
};

class TimerQueue: public ITimerQueue {
DECLARE_TQINTERFACE()DECLARE_DEFAULT_EVENTLISTENER()
	DECLARE_DEFAULT_RENDERLISTENER()

public:
	bool Init(uint32 ulPrecisionMs) {
		return true;
	}
	;
	bool OnOneTimeInit();
	void OnOneTimeRelease() {
	}
	void OnUpdate(uint32 ulCurTimeMs);
	TQHANDLE SetTimer(uint32 ulIdEvent, void* lpUserData, uint32 ulElapseMs,
			ITimerListener* lpTimer);
	bool KillTimer(TQHANDLE hTimer);
	void* GetUserData(TQHANDLE hTimer);
	void Print();

public:
	TimerQueue();
	virtual ~TimerQueue();

private:
	struct STimerNode;
	typedef PtrList<STimerNode> TqLstTimer;
	typedef TqLstTimer::Iterator TqLstTimerIter;

	struct STimerNode {
		/// ��ʱ�ӵ��¼�id
		uint32 eventId;
		/// ��ʱ�ӵ��û�����
		void* userData;
		/// ��ʱ�ӱ����õ�ʱ��(����)
		uint32 setTimeMs;
		/// ��ʱ�ӵĴ���ʱ����(����)
		uint32 elapseMs;
		/// ����ʱ�ص��ļ�������ӿ�
		ITimerListener* timerListener;
		/// ����ýڵ�����ŵ�����ָ��
		TqLstTimer* timerList;
		/// �ýڵ��Ψһ��ʾ
		uint64 uid;

		void clear() {
			eventId = 0;
			userData = NULL;
			setTimeMs = 0;
			elapseMs = 0;
			timerListener = NULL;
			timerList = NULL;
			uid = 0;
		}
	};

	class TimerQueueA {
	public:
		TimerQueueA() :
				m_vector(NULL), m_size(0), m_lastTraversePos(0) {
		}

		virtual ~TimerQueueA() {
			SafeDeleteArray(m_vector);
			m_size = 0;
		}

		void resize(uint32 size) {
			SafeDeleteArray(m_vector);
			m_vector = new TqLstTimer[size];
			m_size = size;
		}

		uint32 size() {
			return m_size;
		}

		TqLstTimer& operator [](int idx) {
			return *(m_vector + idx);
		}

		void initTraversePos(uint32 traversePos) {
			m_lastTraversePos = ((int32) traversePos - 1 + m_size) % m_size;
		}

		int32 getFromLastTraversePosDistance(uint32 curPos) {
			int32 distance = (int32) (curPos - m_lastTraversePos);
			if (distance < 0) {
				distance += m_size;
			}
			return distance;
		}

		int32 getNextTraversePos() {
			return (m_lastTraversePos + 1) % m_size;
		}

		void moveTraversePos() {
			m_lastTraversePos = (m_lastTraversePos + 1) % m_size;
		}

	private:
		TqLstTimer* m_vector;
		uint32 m_size;
		uint32 m_lastTraversePos;
	};

private:
	TqLstTimer* GetLstTimer(uint32 curTimeMs, uint32 elapseMs);
	uint32 FormatTimeByPrecision(uint32 timeMs);uint64 GetTimerUID();
	uint32 GetQueueIdxByTime(uint32 timeMs);
	void TraverseTimerNodesList(TqLstTimer& timerList, uint32 fmtCurTimeMs,
			uint32 curTimeMs);
	void ReattachTimerNodeToPos(uint64 lastUid, STimerNode* node,
			TqLstTimer& timerList, TqLstTimerIter* iter, uint32 fmtCurTimeMs);

private:
	uint32 m_precisionMs;
	FixAlloc<STimerNode> m_timerNodeAlloc;
	TimerQueueA m_timerQueue;
	ITime* m_time;
};

#endif /* TIMERQUEUE_H_ */
