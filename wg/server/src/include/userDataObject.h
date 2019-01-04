#ifndef _USERDATAOBJECT_H_
#define _USERDATAOBJECT_H_
#include <assert.h>
#include "object.h"

class UserDataObject;
typedef void (*UserDataUnref_Fun)(const UserDataObject*);

/** �û����ݶ���
 */
class UserDataObject: public BaseObject {
public:
	void* GetUserData(int iIndex) const {
		assert(iIndex >= 0 && iIndex < GetUserDataCount());
		if (iIndex >= 0 && iIndex < GetUserDataCount()) {
			return m_aUserData[iIndex];
		}
		return NULL;
	}

	void SetUserData(int iIndex, void* lpUserData) {
		assert(iIndex >= 0 && iIndex < GetUserDataCount());
		if (iIndex >= 0 && iIndex < GetUserDataCount()) {
			m_aUserData[iIndex] = lpUserData;
		}
	}

	int GetUserDataCount() const {
		return sizeof(m_aUserData) / sizeof(m_aUserData[0]);
	}

	/** ����==������ */
	bool operator ==(const UserDataObject& stOther) const {
		return (m_aUserData[0] == stOther.m_aUserData[0]
				&& m_aUserData[1] == stOther.m_aUserData[1]);
	}

	/** ���ø����ͷ��û���������ú��� */
	void SetUnRefFun(UserDataUnref_Fun pfn) {
		m_pfnUnRef = pfn;
	}

	/** ɾ�������ڲ������� */
	void UnRef() {
		if (m_pfnUnRef != NULL) {
			m_pfnUnRef(this);
		}
	}

public:
	/** ���캯�� */
	UserDataObject() :
			m_pfnUnRef(NULL) {
		memset(m_aUserData, 0, sizeof(m_aUserData));
	}

	/** �������� */
	virtual ~UserDataObject() {
	}

private:
	void* m_aUserData[2];
	UserDataUnref_Fun m_pfnUnRef;
};

#endif // _USERDATAOBJECT_H_
