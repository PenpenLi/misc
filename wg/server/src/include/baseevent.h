#ifndef _BASE_EVENT_H_
#define _BASE_EVENT_H_
#include "eventtype.h"
#include "userDataObject.h"

//tolua_begin
struct SBaseEvent {
	/// event type
	EEventType eventType;

	SBaseEvent() :
			eventType(EET_UNKNOWN) {
	}
	virtual ~SBaseEvent(){}
	/** get struct size */
	virtual int GetSize() = 0;
};

/** Struct for holding event data.
 */
struct SEvent {
public:
	/// �������¼��Ķ���id��type
	object_id id;
	/// �¼����ݶ���
	SBaseEvent* eventData;
	/// �û�����
	UserDataObject userData;

public:
	/** ���캯�� */
	SEvent() :
			id(-1), eventData(NULL), bSkiped(false), bUpParent(true) {
	}
	/** ���캯�� */
	SEvent(SBaseEvent* baseEvent) :
			id(-1), eventData(baseEvent), bSkiped(false), bUpParent(true) {
	}

	/** �����Ƿ����ƽ�������¼��������Ĵ��� */
	bool IsSkiped() {
		return bSkiped;
	}

	/** �����Ƿ���Ը����¼��������Ĵ��� */
	bool IsUpParent() {
		return bUpParent;
	}

	/** �����Ƿ����ƽ�������¼��������Ĵ���
	 @param bSkiped �Ƿ���Ա�־ */
	void Skip(bool bSkiped) {
		this->bSkiped = bSkiped;
		if (this->bSkiped) {
			UpParent(false);
		}
	}

	/** �����Ƿ���Ը����¼��������Ĵ���
	 @param bSkiped
	 �Ƿ���Ա�־ */
	void UpParent(bool bFlag) {
		this->bUpParent = bFlag;
	}

	//tolua_end
private:
	/// �Ƿ����ƽ�������¼��������Ĵ���
	bool bSkiped;
	/// �Ƿ���Ը����¼��������Ĵ���
	bool bUpParent;
	//tolua_begin
};

//tolua_end

#endif // _BASE_EVENT_H_
