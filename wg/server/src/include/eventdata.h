#ifndef _EVENT_DATA_H_
#define _EVENT_DATA_H_
#include "baseevent.h"

//tolua_begin

struct SLogEvent: public SBaseEvent {
	/// pointer to text which has been logged
	const char* text;

	SLogEvent() :
		text(NULL) {
	}
	/** get struct size */
	virtual int GetSize() {
		return sizeof(SLogEvent);
	}
};

struct SNetEvent: public SBaseEvent {
	/// ������Ϣ����
	int32 msgType;
	/// ��ǰ����״̬
	int32 netState;
	/// ��ǰ��������
	int32 netError;
	/// ������ϢЭ���
	int32 cmd;
	/// ������Ϣ���ֵ
	int32 cmdResult;
	/// �������ݻ��峤��
	int32 dataLen;
	/// �������ݻ���
	char* data;

	SNetEvent() :
			msgType(0), netState(0), netError(0), cmd(0), cmdResult(0), dataLen(
					0), data(NULL) {
	}
	/** get struct size */
	virtual int GetSize() {
		return sizeof(SNetEvent);
	}
};

struct SUserEvent: public SBaseEvent {
	/// Some user specified data as int
	int64 userData1;
	/// Another user specified data as int
	int64 userData2;
	/// Some user specified data as float
	float userData3;

	SUserEvent() :
		userData1(0), userData2(0), userData3(0.0f) {
	}
	/** get struct size */
	virtual int GetSize() {
		return sizeof(SUserEvent);
	}
};

/** �����õ����ݽṹ�������ֽ��� */
inline int GetEventDataMaxSize() {
	int iSize1 = sizeof(SLogEvent);
	int iSize2 = sizeof(SNetEvent);
	int iSize3 = sizeof(SUserEvent);

	int iMaxSize = iSize1;
	if (iSize2 > iMaxSize)
		iMaxSize = iSize2;
	if (iSize3 > iMaxSize)
		iMaxSize = iSize3;
	return iMaxSize;
}

//tolua_end

#endif // _EVENT_DATA_H_
