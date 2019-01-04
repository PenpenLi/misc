#ifndef _DLLLOADER_H_
#define _DLLLOADER_H_
#include "commhead.h"

class DllLoader {
public:
	DllLoader() {
		m_inst = NULL;
	}

	virtual ~DllLoader() {
		UnLoad();
	}

	/** װ�ض�̬��
	 @param name
	 ��Ҫװ�صĶ�̬��·��
	 @return
	 ����true��false
	 */
	bool Load(const char* name) {
		m_dllName = name;
		m_inst = (DYNLIB_HANDLE) DYNLIB_LOAD( m_dllName.c_str() );
		return (m_inst != NULL);
	}

	/** ж�ض�̬��
	 */
	void UnLoad() {
		if (m_inst != NULL) {
			DYNLIB_UNLOAD(m_inst);
		}
	}

	/** ��ö�̬�������
	 */
	const char* GetName(void) const {
		return m_dllName.c_str();
	}

	/** ����ָ����symbol������ַ���
	 @param funName
	 ������
	 @returns
	 ����ɹ����ظú����ĵ�ַ
	 @par
	 ���ʧ���򷵻�<b>NULL</b>.
	 */
	void* GetSymbol(const char* funName) const throw () {
		return (void*) DYNLIB_GETSYM( m_inst, funName );
	}

protected:
	std::string m_dllName;
	DYNLIB_HANDLE m_inst;
};

#endif // _DLLLOADER_H_
