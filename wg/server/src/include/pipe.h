#ifndef _PIPE_H_
#define _PIPE_H_
#include "commhead.h"
#include "semaphore.h"
#include "sharemem.h"
#include "ioresult.h"
#include "ringutil.h"


namespace IO {

/** �ܵ���ʼ����־ */
enum EPipeLockFlag {
	/// ����ͬ����־
	PIPE_NOT_LOCK = 0,

	/// ����ͬ����־
	PIPE_MUTEX_LOCK = 1,
};

/// �ܵ�ͷ�û��Զ������ݳ���
#define PIPE_HEAD_USERDATA_LEN 256
#define PIPE_REAR_SPACE_BYTE 1

/// ���к���������
typedef uint32 seq_type;

/** �����һ�����к�
 @param ulSeq
 ��ǰ���к�
 @return
 �����¸����к�
 */
inline seq_type TQGETNEXTSEQ(seq_type ulSeq) {
	++ulSeq;
	if (ulSeq == 0) {
		ulSeq = 1;
	}
	return ulSeq;
}

/** �����ڴ洫��ܵ�
 */
class Pipe {
public:
	/** ���캯��
	 @param strNameKey
	 �����ڴ�key
	 @param iSize
	 �����ڴ�Ĵ�С
	 @param uiType
	 �ùܵ���һЩ��ǣ�Ĭ��ֵ������ͬ������
	 */
	Pipe();
	Pipe(const char* strNameKey, int iSize, uint uiType = PIPE_MUTEX_LOCK);

	/** ��������
	 */
	virtual ~Pipe();

	/** Init the pipe by share mem key, iSize, uiType
	 @param strNameKey
	 �����ڴ�key
	 @param iSize
	 �����ڴ�Ĵ�С
	 @param uiType
	 �ùܵ���һЩ��ǣ�Ĭ��ֵ������ͬ������
	 @return
	 ����ֵΪtrue��ʾ�ɹ�
	 */
	bool Init(const char* strNameKey, int iSize, uint uiType = PIPE_MUTEX_LOCK);

public:
	/** ��ܵ���ѹ��һ���ݶΣ���PushHead��PushData�����
	 @param iLen
	 ���ݶεĳ���
	 @param lpBuf
	 ���ݶε�����ָ��
	 @return
	 ���سɹ���ܵ�����־
	 */
	int Push(int iLen, const void* lpBuf);

	int PushHead(int iLen);

	void PushData(int iLen, const void* lpBuf);

	/** �ӹܵ���Top�˻��ͷ���ݣ�ֻ�ǻ�����ݣ����������ݴӹܵ���pop��
	 @param iLen [in/out]
	 �������lpBuf����󳤶�, �������ʵ�ʻ�ó���
	 @param lpBuf
	 ��Ҫ������ݶε�����ָ��
	 @return
	 ���سɹ���ܵ��ջ����������־
	 */
	int Top(int &iLen, void* lpBuf);

	/** ��ùܵ�ͷ�������к�
	 */
	uint32 GetTopSeq();

	/** ��ùܵ����ڶ�ȡ�������к�
	 */
	uint32 GetGetSeq();

	/** ͨ�����кŵ�������
	 @param uiSeq
	 ��Ҫ���������İ����
	 */
	void PopBySeq(uint32 ulSeq);

	/** �ӹܵ�������˻��ͷ���ݣ�ͬʱ�����ݴӹܵ���pop��
	 @param iLen [in/out]
	 �������lpBuf����󳤶�, �������ʵ�ʻ�ó���
	 @param lpBuf
	 ��Ҫ������ݶε�����ָ��
	 @return
	 ���سɹ���ܵ��ջ����������־
	 */
	int Pop(int &iLen, void* lpBuf);

	/** �ӹܵ�������˽����ݴӹܵ���pop��
	 */
	int Pop();

	/** �ӹܵ���ָ����λ��ȡ����
	 @param iLen [in/out]
	 �������lpBuf����󳤶�, �������ʵ�ʻ�ó���
	 @param lpBuf
	 ��Ҫ������ݶε�����ָ��
	 @return
	 ���سɹ���ܵ��ջ����������־
	 */
	int Get(int &iLen, void* lpBuf);

	/** ��Get�Ķ�ָ������һ����λ��
	 */
	int NextGetPos();

	/** ��Get�Ķ�ָ����������
	 */
	void ResetGetPos();

	/** ��������ѹ��ܵ���, ���ʹ��ź�, ��@see Pipe::WaitForPushSignal ����ʹ��
	 */
	void SendPushSignal();

	/** �������ݴӹܵ���pop��, ���ʹ��ź�, ��@see Pipe::WaitForPopSignal ����ʹ��
	 */
	void SendPopSignal();

	/** ��������ѹ��ܵ���, ����˵ȴ� @see Pipe::SendPopSignal
	 */
	void WaitForPopSignal();

	/** ��������ѹ��ܵ���, ����˵ȴ� @see Pipe::SendPushSignal
	 */
	void WaitForPushSignal();

	/** ��õ�ǰ�ܵ�����
	 */
	const char* GetName();

	/** ����û����ݳ���
	 */
	int GetUserDataLen() const;

	/** ����û����ݻ���ָ��
	 */
	char* GetUserData() const;

private:
	/** ��������ܵ������ݳ��� */
	int GetLeftLen();

	/** ��õ�ǰptr�����ݵĳ���
	 @param iGetPos
	 �ò���������m_lpHead->iGet��m_lpHead->iFront
	 @return
	 ����_ptr��ָ���pipe�����ݰ��ĳ��� */
	int GetDataLen(int iGetPos);

	/** ��õ�ǰptr�����ݵĳ���
	 @param iGetPos
	 �ò���������m_lpHead->iGet��m_lpHead->iFront
	 @param iLen [in/out]
	 �������lpBuf����󳤶�, �������ʵ�ʻ�ó���
	 @param lpBuf
	 ��Ҫ������ݶε�����ָ��
	 @return
	 ���سɹ���ܵ��ջ����������־
	 */
	int InnerGet(int iGetPos, int &iLen, void* lpBuf);

	/** ��ָ��λ���Ƶ���һ��������ʼλ��λ��
	 @param iPos
	 ��ǰ����ָ��λ��
	 @return
	 ���� TQ_IO_OK ���������󷵻�ֵ
	 */
	int NextPos(int& iPos);

	/** ��ܵ���ĩβд��ָ�����ȵ����� 
	 @param lpBuf
	 Ҫд������ݻ���
	 @param iLen
	 ���ݻ���ĳ���
	 @remarks
	 �ú������ƶ�rearָ���ֵ
	 */
	void WriteDataToPipeRear(const void* lpBuf, int iLen);

	/** ��ָ����λ�ö�ȡ����
	 @param iGetPos
	 �ò���������m_lpHead->iGet��m_lpHead->iFront
	 @param lpBuf
	 ��Ҫ������ݶε�����ָ��
	 @param iLen
	 �������lpBuf��Ҫ��ȡ���ݳ���
	 */
	void ReadDataFromPipeGetPos(int iGetPos, void* lpBuf, int iLen);

	/** ��ùܵ�ָ��λ�ð������к�
	 @param iGetPos
	 �ò���������m_lpHead->iGet��m_lpHead->iFront
	 @return
	 ����ָ���������
	 */
	uint32 GetSeq(int iGetPos);

	/** ���չ����rearλ��
	 */
	int GetExpandRear();

private:
	typedef int len_type;
	#define SEQ_TYPE_SIZE sizeof(seq_type)
	#define LEN_TYPE_SIZE sizeof(len_type)
	#define PIPE_PKG_HEAD_SIZE (SEQ_TYPE_SIZE+LEN_TYPE_SIZE)

	/** �ܵ���ͷ�ṹ */
#pragma pack(push, 1)
	struct SPipeHead {
		/// �ܵ�βָ��
		int iRear;
		/// �ܵ�ͷָ��
		int iFront;
		/// �ܵ���ǰ��ȡ���ݵ�ָ��
		int iGet;
		/// �����ڴ�Ĵ�С
		int iSize;
		/// ���ü���
		int iRefCount;
		/// ��ǰ�Ѿ�ʹ�õ����к�
		seq_type ulSeq;
		/// �û��Զ�������
		char acUserData[PIPE_HEAD_USERDATA_LEN];
	};
#pragma pack(pop)

private:
	/// ���ͱ�־
	uint m_uiType;
	/// �ܵ�ͷָ��
	SPipeHead* m_lpHead;
	/// �����ڴ���
	SHAREMEM_HANDLE m_hShareMem;
	/// ��ſ�ʹ�õ�Buf����
	int m_iBufSize;
	/// �����ڴ�ӳ�䵽�����е��ڴ�ָ��,ʵ�ʴ�����ݵ�ָ��
	uchar* m_lpBuffer;

	/// ���ݴ�ȡ�Ļ�����
	Semaphore* m_lpCsBuffer;
	/// popʱ���ź���, ��ʼ״̬ʱlock
	Semaphore* m_lpPopSignal;
	/// pushʱ���ź���, ��ʼ״̬ʱlock
	Semaphore* m_lpPushSignal;
	/// �ܵ�����
	std::string m_strName;
};

//------------------------------------------------------------------------------------------
inline Pipe::Pipe() :
		m_uiType(0), m_lpHead(NULL), m_hShareMem(INVAILED_SHAREMEM_HANDLE), m_iBufSize(
				0), m_lpBuffer(NULL), m_lpCsBuffer(0), m_lpPopSignal(0), m_lpPushSignal(
				0) {
}

//------------------------------------------------------------------------------------------
inline Pipe::Pipe(const char* strNameKey, int iSize, uint uiType) :
		m_lpHead(NULL), m_hShareMem(INVAILED_SHAREMEM_HANDLE), m_iBufSize(0), m_lpBuffer(
				NULL), m_lpCsBuffer(0), m_lpPopSignal(0), m_lpPushSignal(0) {
	bool bt = Init(strNameKey, iSize, uiType);
	assert(bt);
}

//------------------------------------------------------------------------------------------
inline Pipe::~Pipe() {
	if (m_lpHead != NULL) {
		SEMAPHORE_PTR_LOCK(m_lpCsBuffer);
		int refCount = --m_lpHead->iRefCount;
		
		SEMAPHORE_PTR_UNLOCK(m_lpCsBuffer);
		UnMapShareMem((void*) m_lpHead);
		m_lpHead = NULL;

		if (refCount <= 0) {
			ReleaseShareMem(m_hShareMem);
		}
	}

	SafeDelete(m_lpCsBuffer);
	SafeDelete(m_lpPopSignal);
	SafeDelete(m_lpPushSignal);
	m_lpBuffer = NULL;
}

//------------------------------------------------------------------------------------------
inline
bool Pipe::Init(const char* strNameKey, int iSize, uint uiType) {
	m_uiType = uiType;
	assert( strNameKey != NULL);
	if (strNameKey == NULL) {
		return false;
	}

	if (iSize < 4096) {
		iSize = 4096;
	}

	m_strName = strNameKey;

	// create all semphare
	char szTName[256];
	if (m_uiType == PIPE_MUTEX_LOCK) {
		SafeSprintf(szTName, sizeof(szTName), "%s.cs", strNameKey);
		m_lpCsBuffer = new Semaphore(szTName);
		assert(0!=m_lpCsBuffer);

		SafeSprintf(szTName, sizeof(szTName), "%s.pop", strNameKey);
		m_lpPopSignal = new Semaphore(szTName);
		assert(0!=m_lpPopSignal);

		SafeSprintf(szTName, sizeof(szTName), "%s.push", strNameKey);
		m_lpPushSignal = new Semaphore(szTName);
		assert(0!=m_lpPushSignal);

		if (m_lpCsBuffer == NULL || m_lpPopSignal == NULL
				|| m_lpPushSignal == NULL) {
			return false;
		}
	}

	// alloc share memory
	bool bExist = false;
	m_hShareMem = CreateShareMem(strNameKey, iSize, bExist);
	if (INVAILED_SHAREMEM_HANDLE == m_hShareMem) {
		cerr << "create share mem failed!" << endl;
		return false;
	}

	// mapping the share mem to local proc mem
	m_lpBuffer = (uchar *) MapShareMem(m_hShareMem);
	if (0 == m_lpBuffer) {
		cerr << "map share mem handle failed!" << endl;
		return false;
	}

	// init the local var
	m_lpHead = reinterpret_cast<SPipeHead*>(m_lpBuffer);
	m_lpBuffer = m_lpBuffer + sizeof(SPipeHead);

	if (!bExist) {
		m_lpHead->iSize = iSize;
		SEMAPHORE_PTR_LOCK(m_lpCsBuffer);
		m_lpHead->iRear = 0;
		m_lpHead->iFront = 0;
		m_lpHead->iGet = 0;
		m_lpHead->iRefCount = 0;
		m_lpHead->ulSeq = 0;
		memset(m_lpHead->acUserData, 0, sizeof(m_lpHead->acUserData));
		SEMAPHORE_PTR_UNLOCK(m_lpCsBuffer);
	} else {
		// already exist, get the old mem size
		iSize = m_lpHead->iSize;
		SEMAPHORE_PTR_LOCK(m_lpCsBuffer);
		++m_lpHead->iRefCount; // ref count add 1
		SEMAPHORE_PTR_UNLOCK(m_lpCsBuffer);
	}

	m_iBufSize = iSize - sizeof(SPipeHead);
	return true;
}

//------------------------------------------------------------------------------------------
inline
void Pipe::WriteDataToPipeRear(const void* lpBuf, int iLen) {
	if (m_lpHead != NULL && iLen <= GetLeftLen()) {
		int iWritePos = m_lpHead->iRear;
		int iLeftLen = (m_iBufSize - iWritePos);
		if (iLeftLen > iLen) {
			memcpy((m_lpBuffer + iWritePos), lpBuf, iLen);
		} else {
			// split two segment data
			memcpy((m_lpBuffer + iWritePos), lpBuf, iLeftLen);
			memcpy(m_lpBuffer, (uchar*) lpBuf + iLeftLen, iLen - iLeftLen);
		}

		m_lpHead->iRear = (m_lpHead->iRear + iLen) % m_iBufSize;
	}
}

//------------------------------------------------------------------------------------------
inline
void Pipe::ReadDataFromPipeGetPos(int iGetPos, void* lpBuf, int iLen) {
	iGetPos = iGetPos % m_iBufSize;
	int iLeftLen = m_iBufSize - iGetPos;
	if (iLeftLen >= iLen) {
		memcpy(lpBuf, (m_lpBuffer + iGetPos), iLen);
	} else if (iLeftLen <= 0) {
		int iReadPos = (iGetPos) % m_iBufSize;
		memcpy(lpBuf, (m_lpBuffer + iReadPos), iLen);
	} else // iLeftLen > 0 and iLeftLen < iCurDateLen
	{
		// split two segment data
		memcpy(lpBuf, (m_lpBuffer + iGetPos), iLeftLen);
		memcpy((char*) lpBuf + iLeftLen, m_lpBuffer, iLen - iLeftLen);
	}
}

//------------------------------------------------------------------------------------------
inline
int Pipe::Push(int iLen, const void* lpBuf) {
	int iRt = PushHead(iLen);
	if (iRt != TQ_IO_OK) {
		return iRt;
	}
	PushData(iLen, lpBuf);
	return iRt;
}

//------------------------------------------------------------------------------------------
inline
int Pipe::PushHead(int iLen) {
	int iRt = TQ_IO_OK;
	if (iLen <= 0) {
		return iRt;
	}

	if (m_lpHead == NULL) {
		return TQ_IO_ERR_PIPE_EMPTY;
	}

	SEMAPHORE_PTR_LOCK(m_lpCsBuffer);
	m_lpHead->ulSeq = TQGETNEXTSEQ(m_lpHead->ulSeq);
	if (GetLeftLen() >= (int)(iLen + PIPE_PKG_HEAD_SIZE)) {
		len_type lLen = (len_type) (iLen);
		// first write the data len
		WriteDataToPipeRear(&lLen, sizeof(lLen));
		// write the seq
		WriteDataToPipeRear(&m_lpHead->ulSeq, sizeof(m_lpHead->ulSeq));
	} else {
		iRt = TQ_IO_ERR_PIPE_FULL;
	}
	SEMAPHORE_PTR_UNLOCK(m_lpCsBuffer);

	return iRt;
}

//------------------------------------------------------------------------------------------
inline
void Pipe::PushData(int iLen, const void* lpBuf) {
	SEMAPHORE_PTR_LOCK(m_lpCsBuffer);
	// copy data buf to pipe
	WriteDataToPipeRear(lpBuf, iLen);
	SEMAPHORE_PTR_UNLOCK(m_lpCsBuffer);
}

//------------------------------------------------------------------------------------------
inline
int Pipe::Top(int& iLen, void* lpBuf) {
	if (m_lpHead == NULL) {
		return TQ_IO_ERR_PIPE_EMPTY;
	}

	return InnerGet(m_lpHead->iFront, iLen, lpBuf);
}

//------------------------------------------------------------------------------------------
inline
int Pipe::Pop(int & iLen, void* lpBuf) {
	if (m_lpHead == NULL) {
		return TQ_IO_ERR_PIPE_EMPTY;
	}

	int iRt = InnerGet(m_lpHead->iFront, iLen, lpBuf);
	if (iRt == TQ_IO_OK) {
		iRt = Pop();
	}
	return iRt;
}

//------------------------------------------------------------------------------------------
inline
int Pipe::Pop() {
	int iRt = TQ_IO_OK;
	if (m_lpHead == NULL) {
		return iRt;
	}

	NextPos(m_lpHead->iFront);
	SEMAPHORE_PTR_LOCK(m_lpCsBuffer);
	m_lpHead->iGet = AdjustPosInRangeRingQueue(m_iBufSize,
			m_lpHead->iFront, m_lpHead->iRear, m_lpHead->iGet);
	SEMAPHORE_PTR_UNLOCK(m_lpCsBuffer);

	return iRt;
}

//------------------------------------------------------------------------------------------
inline
int Pipe::Get(int &iLen, void* lpBuf) {
	if (m_lpHead == NULL) {
		return TQ_IO_ERR_PIPE_EMPTY;
	}

	return InnerGet(m_lpHead->iGet, iLen, lpBuf);
}

//------------------------------------------------------------------------------------------
inline
int Pipe::NextGetPos() {
	int iRt = TQ_IO_OK;
	if (m_lpHead == NULL) {
		return iRt;
	}
	SEMAPHORE_PTR_LOCK(m_lpCsBuffer);
	iRt = NextPos(m_lpHead->iGet);
	SEMAPHORE_PTR_UNLOCK(m_lpCsBuffer);
	return iRt;
}

//------------------------------------------------------------------------------------------
inline
void Pipe::ResetGetPos() {
	if (m_lpHead != NULL) {
		m_lpHead->iGet = m_lpHead->iFront;
	}
}

//------------------------------------------------------------------------------------------
inline
int Pipe::NextPos(int& iPos) {
	int iRt = TQ_IO_OK;
	int iCurDateLen = GetDataLen(iPos);
	if (0 != iCurDateLen) {
		iPos = (iPos + PIPE_PKG_HEAD_SIZE + iCurDateLen) % m_iBufSize;
	}
	return iRt;
}

//------------------------------------------------------------------------------------------
inline
void Pipe::SendPushSignal() {
	SEMAPHORE_PTR_UNLOCK(m_lpPushSignal);
}

//------------------------------------------------------------------------------------------
inline
void Pipe::SendPopSignal() {
	SEMAPHORE_PTR_UNLOCK(m_lpPopSignal);
}

//------------------------------------------------------------------------------------------
inline
void Pipe::WaitForPopSignal() {
	SEMAPHORE_PTR_LOCK(m_lpPopSignal);
}

//------------------------------------------------------------------------------------------
inline
void Pipe::WaitForPushSignal() {
	SEMAPHORE_PTR_LOCK(m_lpPushSignal);
}

//------------------------------------------------------------------------------------------
inline
int Pipe::GetLeftLen() {
	int iLeftLen = 0;
	if (m_lpHead != NULL) {
		iLeftLen = (m_lpHead->iFront - m_lpHead->iRear + 2 * m_iBufSize
				- PIPE_REAR_SPACE_BYTE) % m_iBufSize;
	}
	return iLeftLen;
}

//------------------------------------------------------------------------------------------
inline
int Pipe::GetDataLen(int iGetPos) {
	int erear = GetExpandRear();
	if (m_lpHead == NULL || iGetPos + (int)sizeof(len_type) > erear) {
		return 0;
	}

	len_type lCurDataLen;
	ReadDataFromPipeGetPos(iGetPos, &lCurDataLen, sizeof(lCurDataLen));
	if ((erear - iGetPos) < (int)(lCurDataLen + PIPE_PKG_HEAD_SIZE)) {
		return 0;
	}
	return lCurDataLen;
}

//------------------------------------------------------------------------------------------
inline uint32 Pipe::GetSeq(int iGetPos) {
	int erear = GetExpandRear();
	if (m_lpHead == NULL || (int)(iGetPos + PIPE_PKG_HEAD_SIZE)< erear ) {
		return 0;
	}

	seq_type ulSeq;
	iGetPos = (iGetPos + sizeof(len_type)) % m_iBufSize;
	ReadDataFromPipeGetPos(iGetPos, &ulSeq, sizeof(ulSeq));
	return ulSeq;
}

//------------------------------------------------------------------------------------------
inline
int Pipe::InnerGet(int iGetPos, int &iLen, void* lpBuf) {
	int iRt = TQ_IO_OK;
	assert(lpBuf != NULL);
	if (lpBuf == NULL) {
		return TQ_IO_ERR_PIPE_INVALIEDPARAM;
	}

	SEMAPHORE_PTR_LOCK(m_lpCsBuffer);
	int iCurDateLen = GetDataLen(iGetPos);
	if (iCurDateLen > iLen) {
		// iLen is not enough
		iRt = TQ_IO_ERR_PIPE_RECVBUF_LEN_LESS;
	} else if (0 == iCurDateLen) {
		// pipe empty
		iRt = TQ_IO_ERR_PIPE_EMPTY;
	} else {
		iGetPos = (iGetPos + PIPE_PKG_HEAD_SIZE) % m_iBufSize;
		ReadDataFromPipeGetPos(iGetPos, lpBuf, iCurDateLen);
	}
	iLen = iCurDateLen;
	SEMAPHORE_PTR_UNLOCK(m_lpCsBuffer);

	return iRt;
}

//------------------------------------------------------------------------------------------
inline
const char* Pipe::GetName() {
	return m_strName.c_str();
}

//------------------------------------------------------------------------------------------
inline uint32 Pipe::GetTopSeq() {
	if (m_lpHead == NULL) {
		return 0;
	}
	return (uint32) GetSeq(m_lpHead->iFront);
}

//------------------------------------------------------------------------------------------
inline uint32 Pipe::GetGetSeq() {
	if (m_lpHead == NULL) {
		return 0;
	}
	return (uint32) GetSeq(m_lpHead->iGet);
}

//------------------------------------------------------------------------------------------
inline
void Pipe::PopBySeq(uint32 ulSeq) {
	if (m_lpHead != NULL) {
		SEMAPHORE_PTR_LOCK(m_lpCsBuffer);
		int iGetPos = m_lpHead->iFront;
		while (true) {
			uint32 ulCurSeq = GetSeq(iGetPos);
			if (ulCurSeq == 0) {
				break;
			}

			if (ulCurSeq == ulSeq) {
				int iRet = NextPos(iGetPos);
				if (iRet != IO::TQ_IO_OK) {
					break;
				}

				m_lpHead->iFront = iGetPos;
				break;
			}

			int iRet = NextPos(iGetPos);
			if (iRet != IO::TQ_IO_OK) {
				break;
			}
		}

		m_lpHead->iGet = AdjustPosInRangeRingQueue(m_iBufSize,
				m_lpHead->iFront, m_lpHead->iRear, m_lpHead->iGet);

		SEMAPHORE_PTR_UNLOCK(m_lpCsBuffer);
	}
}

//------------------------------------------------------------------------------------------
inline
int Pipe::GetUserDataLen() const {
	if (m_lpHead != NULL) {
		return sizeof(m_lpHead->acUserData);
	}
	return 0;
}

//------------------------------------------------------------------------------------------
inline
char* Pipe::GetUserData() const {
	if (m_lpHead != NULL) {
		return m_lpHead->acUserData;
	}
	return NULL;
}

//------------------------------------------------------------------------------------------
inline
int Pipe::GetExpandRear() {
	int rear = m_lpHead->iRear;
	if (m_lpHead->iFront > m_lpHead->iRear) {
		rear = m_lpHead->iRear + m_iBufSize;
	}
	return rear;
}

} // end namespace IO

#endif // _PIPE_H_
