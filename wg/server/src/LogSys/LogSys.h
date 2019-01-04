/*
 * LogSys.h
 *
 *  Created on: 2013-2-20
 *      Author: Administrator
 */

#ifndef LOGSYS_H_
#define LOGSYS_H_
#include <ILogSys.h>
#include <commhead.h>
#include <Socket.h>
#include <IpHelper.h>
#include <string>
#include <map>

#define MAX_LOG_BUFFER_LEN 4096

class LogSys: public ILogSys {
DECLARE_TQINTERFACE()
	;DECLARE_DEFAULT_EVENTLISTENER()
	;DECLARE_DEFAULT_RENDERLISTENER()
	;DECLARE_DEFAULT_UPDATELISTENER()
	;
public:
	bool AddLog(const char* key, const char* outPath, uint32 cacheItemCount,
			uint32 maxLogSubFileCount, uint32 fileMaxSize);

	const char* GetLogPath(const char* key);
	void Log(const char* key, EOutLogFlag flag,
			const char* fmt, ...);
	void Log(const char* key, EOutLogFlag flag,
			const char* fmt, va_list args);
	void LogWarning(const char* key, EOutLogFlag flag,
			const char* fmt, ...);
	void LogWarning(const char* key, EOutLogFlag flag,
			const char* fmt, va_list args);
	void LogError(const char* key, EOutLogFlag flag,
			const char* fmt, ...);
	void LogError(const char* key, EOutLogFlag flag,
			const char* fmt, va_list args);
	void LogData(const char* key, const char* data, int len);
	void Flush(const char* key);

	bool OnOneTimeInit();
	void OnOneTimeRelease();
public:
	/** ���캯�� */
	LogSys();
	/** �������� */
	virtual ~LogSys();

public:
	/** ��־���� */
	enum ELogNodeType {
		/// û�г�ʼ��������
		ELNT_NONE,
		/// udp����
		ELNT_UDP,
		/// �����ļ�����
		ELNT_FILE,
	};

	/** ��־�����ݱ�־ */
	enum ELogTextFlag {
		/// �ı���ʽ
		ELTF_TEXT,
		/// �����Ƹ�ʽ
		ELTF_BIN,
	};

private:
	/** Upd������־ */
	struct SLogUdp {
		/// ��־��������IP
		uint32 ip;
		/// ��־�������Ķ˿�
		ushort port;
		/// UPD��SOCKET
		Net::Socket objSocket;

		/** ���캯�� */
		SLogUdp() :
				ip(0), port(0) {
		}
	};

	/** �ļ���־ */
	struct SLogFile {
		/// �������ɵ�������ļ�����
		uint32 maxSubLogFilesCount;
		/// �����ļ��������ɵ��ֽ���
		uint32 fileMaxSize;
		/// ��־����Ļ����ļ�(��������չ��)
		std::string basePath;
		/// ��־����ļ�
		std::string fileName;
		/// ��ǰ�ļ��Ĵ�С
		uint32 fileSize;
		/// �ɻ���ĵ����log��Ŀ,���۵�����Ŀ���Ž���һ���ļ���д��
		uint32 maxCacheItems;
		/// ��ǰ�ѻ������Ŀ����
		uint32 curCacheItems;
		/// �ϴ�flush��ʱ��
		uint32 lastLogTime;
		/// ���ڻ����buf
		char* cacheBuf;

		/** ���캯�� */
		SLogFile() :
				maxSubLogFilesCount(10), fileMaxSize(1000000), fileSize(0), maxCacheItems(
						1), curCacheItems(0), lastLogTime(0), cacheBuf(
						NULL) {
		}
	};

	/** һ����־�ڵ�,��keyһһ��Ӧ */
	struct SLogNode {
		/// ��־����
		ELogNodeType flag;
		/// Upd������־
		SLogUdp udp;
		/// �ļ���־
		SLogFile file;
		/// ��Ҫ������ļ���upd·��
		std::string outPath;

		SLogNode() :
				flag(ELNT_NONE) {
		}
	};
	typedef std::map<std::string, SLogNode> StdMapLogs;
	typedef StdMapLogs::iterator StdMapLogsIter;

private:
	bool AddLogNode(const char* key, const char* outPath);

	SLogNode* GetNodeByKey(const char* key);

	void FormatLogString(const char* tag, EOutLogFlag flag,
			const char* fmt, va_list args, char* outBuf,
			int outBufLen);

	void WriteLog(SLogNode* node, ELogTextFlag flag, const void* buf,
			int bufLen);

	void WriteToFile(SLogNode* node, ELogTextFlag flag, const void* buf,
			int bufLen);

	void WriteToUdpServer(SLogNode* node, ELogTextFlag flag,
			const void* buf, int bufLen);

	/** ����ǰ�ڵ��Ӧ��ϵ����־�ļ���������Ŀ���ǿ���һ���ļ������ɵ�����ֽ�������
	 �����Ƴ���: ... xxx.3.log xxx.2.log xxx.1.log */
	void RenameSubLogFile(SLogNode* node);

	void InnerFlush(SLogNode* node);

private:
	/// ��־�ڵ�map
	StdMapLogs m_mapLogs;
};

#endif /* LOGSYS_H_ */
