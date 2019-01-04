#ifndef _I_LOGSYS_H_
#define _I_LOGSYS_H_
#include "IInterface.h"

// {4312CD49-3210-4cd6-B83B-A7BA0530347C}
static const TQGUID IUID_ILOGSYS = { 0x4312cd49, 0x3210, 0x4cd6, { 0xb8, 0x3b,
		0xa7, 0xba, 0x5, 0x30, 0x34, 0x7c } };

//tolua_begin

/** �����һ����־ʱʹ�õı�־ */
enum EOutLogFlag {
	/// ��ͨ����
	EOLF_NORMAL = 0x0000,
	/// ����־��ͷ���Զ����ʱ���ǩ
	EOLF_OUTTIME = 0x0001,
};

/** ��־ϵͳ */
class ILogSys: public IInterface {
public:
	/** ���һ����־������
	@param key
		��־�ļ���Ӧ��keyֵ
	@param outPath
		��־�ļ���·�����ƻ�udp������·����
		������"./log/xxx.log"��"udp://172.0.0.1:4444"
	@param cacheItemCount
		���ɻ������Ŀ��
	@param maxLogSubFileCount
		��ǰkey��Ӧ����־���������ɵ������־�������ļ�����
	@param fileMaxSize
		��ֵ��ʾ�����������ļ������ɵ�����ֽ���
	@return
		����true��false
	*/
	virtual bool AddLog(const char* key,
		const char* outPath,
		uint32 cacheItemCount,
		uint32 maxLogSubFileCount,
		uint32 fileMaxSize) = 0;

	/** ���ĳ��key��Ӧ����־�ļ�·����
	@param key
		��־�ļ���Ӧ��keyֵ
	@return
		������־�ļ�·����(UTF8)
	*/
	virtual const char* GetLogPath(const char* key) = 0;

	/** ��־���, �÷�ʾ��:
	@param key
		��־�ļ���Ӧ��keyֵ
	@param iFlag
		������־��ѡ�ı�־λ,��LOG_FLAG_SHOWDATE
	@param fmt
		��ʽ�ַ���
	@param ...
		�ɱ䳤�����б�
	*/
	virtual void Log(const char* key, EOutLogFlag flag, const char* fmt, ... ) = 0;
	virtual void Log(const char* key, EOutLogFlag flag, const char* fmt, va_list args) = 0;

	/** ��־���, ���Warning��־
	@param key
		��־�ļ���Ӧ��keyֵ
	@param iFlag
		������־��ѡ�ı�־λ,��LOG_FLAG_SHOWDATE
	@param fmt
		��ʽ�ַ���
	@param ...
		�ɱ䳤�����б�
	*/
	virtual void LogWarning(const char* key, EOutLogFlag flag, const char* fmt, ... ) = 0;
	virtual void LogWarning(const char* key, EOutLogFlag flag, const char* fmt, va_list args) = 0;

	/** ��־���, ���Error��־
	@param key
		��־�ļ���Ӧ��keyֵ
	@param iFlag
		������־��ѡ�ı�־λ,��LOG_FLAG_SHOWDATE
	@param fmt
		��ʽ�ַ���
	@param ...
		�ɱ䳤�����б�
	*/
	virtual void LogError(const char* key, EOutLogFlag flag, const char* fmt, ... ) = 0;
	virtual void LogError(const char* key, EOutLogFlag flag, const char* fmt, va_list args) = 0;

	/** ��־���, ���һ������������ݿ�
	@param key
		��־�ļ���Ӧ��keyֵ
	@param data
		��Ҫ���͵���־���ݻ���
	@param dataLen
		��־����ĳ���
	*/
	virtual void LogData(const char* key, const char* data, int dataLen) = 0;

	/** �������е�����д�뵽�豸��
		����־����������У������Ǳ������ˣ���û����д�뵽�豸��
	@param key
		��־�ļ���Ӧ��keyֵ
	*/
	virtual void Flush(const char* key) = 0;
};

//tolua_end

#endif // _I_LOGSYS_H_
