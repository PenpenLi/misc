#ifndef _OBJECT_H_
#define _OBJECT_H_
#include "objectDef.h"

//tolua_begin
class BaseObject {
public:
	void setId(object_id id) {
		m_id = id;
	}

	object_id getId() {
		return m_id;
	}

public:
	virtual ~BaseObject() {
	}

protected:
	BaseObject() :
			m_id(0) {
	}

protected:
	object_id m_id;
};

/** �������� */
class TypeObject: public BaseObject {
public:
	/** ��ö������� */
	int32 GetType() {
		return m_lType;
	}

	//tolua_end
public:
	/** �������� */
	virtual ~TypeObject() {
	}

protected:
	/** ���캯�� */
	TypeObject() :
			m_lType(-1) {
	}

protected:
	int32 m_lType;
	//tolua_begin
};

//tolua_end

//tolua_begin

/** ���ü������� */
class RefObject: public BaseObject {
public:
	/** �������ü��� */
	int32 AddRef() {
		return ++m_lRefCount;
	}

	/** ��õ�ǰ�����ü��� */
	int32 GetRefCount() const {
		return m_lRefCount;
	}

	/** �ͷ����ü��� */
	virtual int32 Release() {
		if (m_lRefCount <= 0) {
			delete this;
		} else {
			--m_lRefCount;
		}
		return m_lRefCount;
	}

	//tolua_end
protected:
	/** ���캯��*/
	RefObject() :
			m_lRefCount(0) {
	}
	/** ��������*/
	virtual ~RefObject() {
	}
protected:
	/** ���ü��� */
	int32 m_lRefCount;
	//tolua_begin

};

//tolua_end

#endif // _OBJECT_H_
