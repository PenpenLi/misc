#ifndef _GAME_H_
#define _GAME_H_ 
#include <commhead.h>
#include <tinyxml/tinyxml.h>
#include <safefun.h>
#include <pkgBase.h>
#include "idb.h"
#include "tean.h"
#include "log.h"
#include "zoneline.h"
#include "config.h"
#include <map>
#include <python/Python.h>

#define MAX_ZONE_COUNT 2

class CGame {
public:
	/** Ĭ�Ϲ��캯�� */
	CGame();
	/** �������� */
	virtual ~CGame();

public:
	void SetConfig(const char* cfg, const char* log);

	/** ��ʼ����Ϸ����
	 @return ����true��ʾ��ʼ���ɹ�
	 */
	bool Init();

public:
	/** ����װ�������ߵ�����
	 @return ����true��ʾװ�ڳɹ�
	 */
	bool ReLoadZones();

	/** ��鵱ǰ���û����Ƿ����
	 @param ��Ҫ�������û���
	 @return ����1��ʾ����
	 */
	int HasUserName(const char* lpszUserName);

	/** ע��һ���û��ʺ�
	 @param lpszUser �û���
	 @param lpszPwd �û�����
	 @param lpszEmail �û�����
	 @param lpszIp �û�ע��ip
	 @param lpszCommentId �Ƽ����û���
	 @param iCommentFlag �Ƽ�����
	 @return ����1��ʾע��ɹ�
	 */
	int RegAccount(const char* lpszUser, const char* lpszPwd,
			const char* lpszEmail, const char* lpszIp,
			const char* lpszCommentId, const int iCommentFlag);

	/** ����û��������Ƿ���ȷ
	 @param lpszUser �û���
	 @param lpszPwd ����
	 @return ����1��ʾ����
	 */
	int HasUserPwd(const char* lpszUser, const char* lpszPwd);

	/** ���ָ�����û����Ƿ��и��ʼ�
	 @param lpszUser �û���
	 @param lpszEmail ����
	 @return ����1��ʾ����
	 */
	int HasUserEmail(const char* lpszUser, const char* lpszEmail);

	/** ��������б�
	 @param lpszUser �û���
	 @param iFlag 1-��ʾ���ţ�2-��ʾ��ͨ��3-��ʾ�û��Ѽ���
	 @return �������б��python����
	 */
	PyObject* GetZonelist(const char* lpszUser, int iFlag);

	PyObject* GetZoneGrouplist();

	/** �ı��û�����
	 @param lpszUser �û���
	 @param lpszNewPwd �µ�����
	 @return 1��ʾ�޸ĳɹ�
	 */
	int ChangeUserpassword(const char* lpszUser, const char* lpszNewPwd);

	/** ����һ���ַ����������Ҳ���ַ�����ʽ
	 @param lpInBuf ��Ҫ�����ܵ��ַ���
	 @param lpOutBuf ��ż��ܺ�Ľ��
	 @param iOutBufLen ��ż��ܺ�Ľ��buf����󳤶�
	 */
	void EncodeSigStr(const char* lpInBuf, char* lpOutBuf, int iOutBufLen);

	/** ����һ���ַ����������Ҳ���ַ�����ʽ
	 @param lpInBuf ��Ҫ�����ܵ��ַ���
	 @param lpOutBuf ��Ž��ܺ�Ľ��
	 @param iOutBufLen ��Ž��ܺ�Ľ��buf����󳤶�
	 */
	void DecodeSigStr(const char* lpInBuf, char* lpOutBuf, int iOutBufLen);

	/** ɾ����ǰ���µ����н�ɫ����
	 */
	void DeleteRoles();

public:
	typedef std::map<ushort, SDir> StdMapZone;
	typedef StdMapZone::iterator StdMapDirIter;
	typedef std::vector<SDir> StdVctDir;
	typedef StdVctDir::iterator StdVctZoneIter;

private:
	/** ��ʼ����Կ */
	void InitKey();

	/** װ�ڷ����������� */
	bool LoadConfig();

	/** ��ʼ����Ϸϵͳ */
	bool InitGame();

	/** �������ݿ� 
	 @return ����true��ʾ���ӳɹ�
	 */
	bool ConnectDB();

	/** �ر����ݿ� */
	void CloseDB();

	/** װ�������ߵ�����
	 @return ����true��ʾװ�ڳɹ�
	 */
	bool LoadZones();

	int LoadXMLInteger(TiXmlDocument& doc, const char* key);
	const char* LoadXMLString(TiXmlDocument& doc, const char* key);
	void GetMyActiveZoneList(const char* user, StdVctDir& zone);
	void GetZoneListByFlag(const char* user, StdVctDir& zonelist, uchar flag);
	PyObject* NewPyZoneList(StdVctDir* zonelist);
	int ReadBlobFromDB(const char* buf, int buflen, SPkgBase* basepkg);
	int WriteBlobForDB(char* buf, int buflen, const SPkgBase* basepkg);

private:
	/// �����ļ�
	std::string m_configName;

	/// ��־�ļ�
	std::string m_logName;

	/// ��ʼ���ɹ���־
	bool m_bInitOk;
	/// �߳��Ƿ�ֹͣ��־
	bool m_bStop;
	/// ���ݿ����
	IDB* m_db;
	/// ������ѯ��Sql����buf
	char* m_lpszSql;
	/// ǩ����Կ
	uchar m_aucKey[MAX_KEY_LEN];
	/// ����С��map��
	StdMapZone m_dirs;
	/// ��Ϸ�����ļ�
	SConfig m_stConfig;
};

#endif // _GAME_H_
