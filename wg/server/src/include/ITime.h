#ifndef _I_TIME_H_
#define _I_TIME_H_
#include <IInterface.h>

// {0206A677-529E-4264-9F07-F91C10AEBB87}
static const TQGUID IUID_ITIME = { 0x206a677, 0x529e, 0x4264, { 0x9f, 0x7, 0xf9,
		0x1c, 0x10, 0xae, 0xbb, 0x87 } };

//tolua_begin

/** ʱ��ӿڣ������ǻ�ȡ��server��ͬ����ʱ�����������client�����ⲥ��ʱ��
 */
class ITime: public IInterface {
public:
	/** ���õ�ǰclientʱ���server��ʱ��Ĳ���
	 @param dispersionMs
	 ��λ���룬= servertime-clienttime
	 */
	virtual void SetDispersionMs(uint32 dispersionMs) = 0;

	/** ���õ�ǰʱ�����������
	 @param scale
	 ʱ�����������
	 */
	virtual void SetScale(double scale) = 0;

	/** ����һ����ʱ��
	 @param timeMs
	 ���ߵ�ʱ�䳤��,��λ����
	 */
	virtual void SleepMs(uint32 timeMs) = 0;

	/** ��õ�ǰʱ��
	 @remark
	 �ú������ص�ʱ����ͨ��ʱ���������������������õ���,������������ʱ��
	 @return
	 ���ص�ǰ���������ʱ��,��λ����
	 */
	virtual uint32 GetCurrentTimeMs() = 0;
	virtual uint64 GetCurrentTimeMsEx() = 0;

	/** ��õ�ǰʱ��
	 @remark
	 �ú������ص�ʱ����ͨ��ʱ���������������������õ���,������������ʱ��
	 @return
	 ���ص�ǰ���������ʱ��,��λ��
	 */
	virtual uint32 GetCurrentTimeSec() = 0;
};

//tolua_end

#endif // _I_TIME_H_
