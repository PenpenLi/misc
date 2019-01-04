/*
 * Messager.h
 *
 *  Created on: 2013-2-27
 *      Author: Administrator
 */

#ifndef MESSAGER_H_
#define MESSAGER_H_

#include <commhead.h>
#include <pipe.h>
#include <map>
#include <set>

namespace Net {

/** �Ƿ��ķ�����ID���� */
#define INVALID_SVRID 0xffffffff
/** ͨ��һ����������ID���յ������ID���һ���ܵ�ID */
#define MAKEPIPEID(ulFromId, ulToId) (uint64)(((uint64)(ulFromId) << 32) | (uint64)(ulToId))
/** �ӹܵ�ID�л����������ID */
#define GETFROMSVRID(PIPEID) (uint32)(((PIPEID)>>32)&0xffffffff)
/** �ӹܵ�ID�л���յ������ID */
#define GETTOSVRID(PIPEID) (uint32)((PIPEID)&0xffffffff)
/** ��ȡ���������� */
#define GETSVRTYPE(SVRID) (uchar)(((SVRID)>>24)&0xff)

extern const char* c_szComMessagerShareMem;
extern const int c_iComMessagerShareMem;

#pragma pack(push, 1)
struct SMessagerReg {
	/// ��������ID
	uint32 ulFromId;
	/// �յ������ID
	uint32 ulToId;
	/// ��������IP
	int32 lFromIp;
	/// ����������messager�����������Ķ˿�
	ushort usFromPort;
	/// �յ������IP
	int32 lToIp;
	/// �յ��������messager�����������Ķ˿�
	ushort usToPort;
	/// ���͹ܵ��Ĵ�С
	int iSendBufSize;
	/// ���չܵ��Ĵ�С
	int iRecvBufSize;
	/// ���͹ܵ�keyֵ
	char szSendKey[32];
	/// ���չܵ�keyֵ
	char szRecvKey[32];
};
#pragma pack(pop)

/** ����������Ϣ����Ĺ������
 */
class Messager {
public:
	/** װ�������ļ�
	 @param lpszConfig
	 �����ļ�·����
	 @return
	 ����true��false
	 */
	bool LoadConfig(const char* lpszConfig);

	/** �������������佨������
	 @remark
	 ��Ҫ�������ӵ����������������ǿ����ӵ�,����Config�������������õ�
	 @param lpszFromSvr
	 ��Ҫ���ӵ�������������
	 @param lpszToSvr
	 ��Ҫ���ӵ��յ����������,
	 ��������������"*",������������Config�����õ�,�����ι�ϵ��
	 @return
	 ����true��false
	 */
	bool Connect(const char* lpszFromSvr, const char* lpszToSvr);

	/** ��ָ��lpszFromSvr�Ľ��չܵ��б��н���һ��messager���ݰ�
	 @remark
	 ��Recv���и��ڲ�����״̬��־,ÿ�ε���Recv����Ӹ�����״̬��־Ϊ����ҵ�
	 ��Ӧ�Ľ��չܵ����н�������,Ȼ���ڲ�����״̬��־��Ϊ���ѽ��յ��¸�λ��
	 @param ulFromSvrId [O]
	 �ѽ��յ������ݰ���Դserver��ID
	 @param lpBuf
	 ��Ž��յ������ݵĻ�����
	 @param lplBufLen [I/O]
	 ���뻺��������󳤶�,����ʵ�ʽ��յ����ݵ��ֽ���
	 @return
	 ����ʵ�ʽ��յ����ݵ��ֽ���
	 */
	int Recv(uint32& ulFromSvrId, void* lpBuf, int32 lBufLen);

	/** ��ָ���ķ�����id�������ݰ�
	 @param ulToSvrId
	 Ŀ�ķ�����id
	 @param lpBuf
	 ��Ž�Ҫ���͵����ݻ�����
	 @param lBufLen
	 ��Ҫ���͵����ݻ��������ֽ���
	 @return
	 ����ʵ�ʷ��͵������ֽ���
	 */
	int Send(uint32 ulToSvrId, const void* lpBuf, int32 lBufLen);

	int SendHead(uint32 ulToSvrId, int32 lBufLen);
	void SendData(uint32 ulToSvrId, const void* lpBuf, int32 lBufLen);

	/** ͨ������������÷�������Ӧ��ID
	 @param lpszSvrName
	 ������Ψһ��ʾ����
	 @return
	 ���ظ÷�������Ӧ��ID��INVALID_SVRID
	 */
	uint32 GetSvrIdByName(const char* lpszSvrName);

	/** ͨ��������ID��÷�������
	 @param ulSvrId
	 ������ID
	 @return
	 ���ظ÷���������NULL
	 */
	const char* GetSvrNameById(uint32 ulSvrId);

	/** ͨ�������������ͣ�������һ���ӵ�ǰ���ָ����յ������id
	 @param ucSvrType
	 ������������
	 @return
	 ����Ҫ��õķ�����ID
	 */
	uint32 GetRandomToSvrIdByType(uchar ucSvrType);

	/** ͨ�������Ż��һ���ӵ�ǰ���ָ����յ������id
	 @param iIndex
	 ������
	 @return
	 ����Ҫ��õķ�����ID
	 */
	uint32 GetToSvrIdByIndex(int iIndex);

public:
	/** ���캯�� */
	Messager();
	/** �������� */
	~Messager();

private:
	/** ��������������ӵ��ڲ�����,��@see Connect����
	 @param lpszFromSvr
	 ��Ҫ���ӵ�������������
	 @param lpszToSvr
	 ��Ҫ���ӵ��յ����������,
	 @return
	 ����true��false
	 */
	bool InnerConnectOne(const char* lpszFromUrl, const char* lpszToUrl);

private:
	/** default config value */
	struct SDefaultVal {
		/// Messager���������ļ���ַ
		std::string strServerPath;
		/// Messager������Ĭ�ϵĶ˿ں�
		ushort usHostPort;
		/// Ĭ�Ϸ��͹ܵ��Ĵ�С
		int iSendBufSize;
		/// Ĭ�Ͻ��չܵ��Ĵ�С
		int iRecvBufSize;
	};

	/** messager node config struct*/
	struct SMessagerNode {
		/// �������ڵ�ID
		uint32 ulId;
		/// �������ڵ�����
		std::string szName;
		/// �������ڵ�IP
		int32 lIp;
		/// �������ڵ�˿�
		ushort usPort;
	};
	typedef std::map<uint32, SMessagerNode> StdMapMsgNode;
	typedef StdMapMsgNode::iterator StdMapMsgNodeIter;

	/** messager name map struct*/
	typedef std::map<std::string, uint32> StdMapMsgNameNode;
	typedef StdMapMsgNameNode::iterator StdMapMsgNameNodeIter;

	struct SMessagerLink {
		/// �ͷ��ܵ��Ĵ�С
		int iSendBufSize;
		/// ���͹ܵ���Ӧ�Ĺ����ڴ�key
		std::string strSendKey;
		/// ���չܵ��Ĵ�С
		int iRecvBufSize;
		/// ���չܵ���Ӧ�Ĺ����ڴ�key
		std::string strRecvKey;
	};
	/// this map key be combined of MAKEPIPEID(ulFromId,usToId)
	typedef std::map<uint64, SMessagerLink> StdMapLink;
	typedef StdMapLink::iterator StdMapLinkIter;

	/// this map key be combined of MAKEPIPEID(ulFromId,ulToId)
	typedef std::map<uint64, IO::Pipe*> StdMapPipe;
	typedef StdMapPipe::iterator StdMapPipeIter;

	typedef std::set<uint32> StdSetToSvrs;
	typedef StdSetToSvrs::iterator StdSetToSvrsIter;
	/// ��map��key��fromsvrid, ���������������ӹ�ϵ��tosvrid���б�
	typedef std::map<uint32, StdSetToSvrs> StdMapToSvrs;
	typedef StdMapToSvrs::iterator StdMapToSvrsIter;

private:
	/// �Դ���ܵ�һ��Ĭ�ϵ�����
	SDefaultVal m_stDefaultVal;
	/// �������ڵ�map
	StdMapMsgNode m_mapMsgNodes;
	/// �������ڵ����ƺ�id��map
	StdMapMsgNameNode m_mapMsgNameNodes;
	/// �������ڵ����ӹ�ϵmap<key(fromid,toid), node>
	StdMapLink m_mapMsgLinks;
	/// �������ڵ����ӹ�ϵmap<key(fromid), toid>
	StdMapToSvrs m_mapLinkToSvrs;
	/// ���͹ܵ���map<key(fromid,toid), pipe>
	StdMapPipe m_mapSendPipes;
	/// ���չܵ���map<key(fromid,toid), pipe>
	StdMapPipe m_mapRecvPipes;

	/// from pipe id
	uint32 m_ulFromId;

	/// �Ƿ���Խ���
	bool m_bRecvBegin;
	/// current recv iter
	StdMapPipeIter m_iterCurRecv;
};

} //end namespace Net

#endif /* MESSAGER_H_ */
