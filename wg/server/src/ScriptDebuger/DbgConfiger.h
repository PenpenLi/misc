#ifndef _DBGCONFIGER_H__
#define _DBGCONFIGER_H__
#include <singleton.h>
#include <set>

class DbgConfiger : public Singleton<DbgConfiger>
{
	DECLARE_SINGLETON(DbgConfiger);
public:
	/** ���ļ�װ��Debug������
	@param lpszFileName
		�����ļ�����
	@return
		����true��false
	*/
	bool Load(const char* lpszFileName);

	/** �Ƿ��ǺϷ���ip
	@return
		����true��ʾ�Ϸ���ip
	*/
	bool IsValidIp(uint32 lIp);

	/** �Ƿ�������ʱ�����õ���״̬
	@return
		����true��Ҫ����
	*/
	bool IsSetTrackInStart();

private:
	DbgConfiger();

private:
	std::set<uint32> m_setVaildIps;
	bool m_bSetTrackInStart;
};

#endif // _DBGCONFIGER_H__
