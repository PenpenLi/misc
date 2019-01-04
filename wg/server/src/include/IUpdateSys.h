#ifndef _I_UPDATESYS_H_
#define _I_UPDATESYS_H_
#include "IInterface.h"
#include "IUpdateListener.h"

// {0E1694FD-2AA4-4d07-BCB7-1BECC71CB058}
static const TQGUID IUID_IUPDATESYS = { 0xe1694fd, 0x2aa4, 0x4d07, { 0xbc, 0xb7,
		0x1b, 0xec, 0xc7, 0x1c, 0xb0, 0x58 } };

//tolua_begin

/** ����ϵͳ,����������¼�������
 */
class IUpdateSys: public IInterface {
public:
	/** ��ϵͳ�����һ�����¼�������
	 @param listener
	 ��Ҫ����ӵĸ��¼�������
	 */
	virtual void AddUpdateListener(IUpdateListener* listener) = 0;

	/** ɾ��ָ�������ŵĸ��¼�������
	 @param idx
	 ����������
	 */
	virtual void DelUpdateListener(int idx) = 0;

	/** ��ȡ���¼�������ĸ���
	 @return
	 ���ظ��¼�������ĸ���
	 */
	virtual int GetUpdateListenerCount() = 0;
};

//tolua_end

#endif // _I_UPDATESYS_H_
