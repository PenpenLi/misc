#ifndef _FIXALLOC_H_
#define _FIXALLOC_H_
#include <memory>
#include <limits>
#include <vector>
#include <list>
#include <assert.h>


/** һ���̶���С�ṹ���������
 @remarks
 �÷�������֧�ֶ��̣߳�ͬʱ�ڵ��������ü�����ȫ���ƣ�
 �������÷�����ʱ��ȷ�������нڵ��Զ�ʧЧ��ȫ����Free
 */
template<typename T>
class FixAlloc {
private:
	/** ����ڵ�ṹ */
	struct SInnerListNode {
		/** ָ����¸��ڵ� */
		SInnerListNode* lpNext;
	};

	/** ÿ�������ͷ���ṹ */
	struct SBufferHead {
		/** �ÿ鱻���õĸ��� */
		int iRefCount;
		/** �ÿ����ʼ��ַ,�ڽڵ��ͷ�ʱ����Χ�ж� */
		char* lpFirstPtr;
		/** �ÿ�Ľ�β��ַ,�ڽڵ��ͷ�ʱ����Χ�ж� */
		char* lpLastPtr;
		/** ��ǰ�ɷ���Ŀ��нڵ�ͷָ�� */
		SInnerListNode* lpFreeHead;
	};

public:
	/** ��ʼ��fixedlist������
	 @remark
	 ���°汾��������iNodeSize��bConstruct��Ŀ����Ϊ�˷���һ��ָ����С���ڴ棬
	 ������Ϊ�̶���С�Ľṹʹ�ã�����һ��������ʹ�ã�
	 FixAlloc<char> objAlloc;
	 objAlloc.Init(1024, 32, false, false);
	 ������һ���ṹ��ʹ�ã�
	 FixAlloc<MyStruct> objAlloc;
	 objAlloc.Init(1024, 0, false, true);
	 @param iCount
	 ��Ҫ����Ľڵ����
	 @param iNodeSize
	 �����ڵ�Ĵ�С�����Ϊ0�����ȡsizeof(T)��Ϊ�ڵ�Ĵ�С
	 @param bFixed
	 �Ƿ�Ϊ�̶���С���ڴ棬�����пպ󲢲����·��䣬���Ϊfalse���ڶ���Ϊ��ʱ
	 ����������iCount���ڵ�������ڴ�ʹ��
	 @param bConstruct
	 �Ƿ�Ϊ����Ķ�����й��������
	 @return
	 ����true��ʾ��ʼ���ɹ�
	 */
	bool Init(int iCount, int iNodeSize, bool bFixed, bool bConstruct);

	/** ����һ�����õĽڵ�
	 @param lpulPos [O] ��ý�������Ľڵ��������е�λ��
	 �������ΪNULL�������㺬�壬һ�ǿɷ������Ϊ��(bFixedΪtrue)��
	 һ���ڴ��ù�(bFixedΪfalse)
	 �ڸó�Ա�����л��Զ�����T�Ĺ��캯��
	 */
	T* Alloc(uint32* lpulPos = NULL);

	/** �ͷ�һ���ڵ�
	 @param lpObject
	 �����ͷŵĶ���ָ��
	 �ڸó�Ա�����л��Զ�����T����������
	 */
	void Free(T* lpObject);

	/** �������еĽڵ���� */
	int GetAllCount();

	/** ���ص�ǰ���õĽڵ���� */
	int GetFreeCount();

	/** ���ص�ǰ�Ѿ���ʹ�õĽڵ���� */
	int GetUsedCount();

	/** ͨ�������±��ýڵ����
	 @param iIdx �����±�
	 @return ���ض�Ӧ�Ľڵ����
	 */
	T* GetNodeByIdx(int iIdx);

public:
	/** ���캯�� */
	FixAlloc();
	/** �������� */
	~FixAlloc();

private:
	/** ��һ���������ڴ��ʼ����һ����ӵĵ�������
	 @param lpBuffer
	 �������ڴ�
	 @param iCount
	 ����Ľڵ����
	 @return
	 ����true��false
	 */
	bool InitBufferToList(char* lpBuffer, int iCount);

	/** ����һ���µ��ڴ�� */
	bool AllocOneBlock();

private:
	typedef typename std::vector<SBufferHead*> StdVctNodeBuffer;
	typedef typename StdVctNodeBuffer::iterator StdVctNodeBufferIter;
	int m_iNodeCount;					/// ÿ���ڴ���������ɵĽڵ����
	StdVctNodeBuffer m_vctNodeBuffer;	/// ����������ΪFreeNode������ڴ�飬�Ա��ͷš�
	bool m_bFixed;						/// �Ƿ�Ϊ�̶���С���ڴ棬�����пպ󲢲����·���
	bool m_bConstruct;					/// �Ƿ�Ϊ����Ķ�����й��������
	int m_iAllNodeCount;				/// ���нڵ����
	int m_iUsedNodeCount;				/// �Ѿ���ʹ�õĽڵ����
	int m_iNodeSize;					/// �ڵ��С
};


template<typename T> inline FixAlloc<T>::FixAlloc() :
		m_iNodeCount(0), m_bFixed(false), m_iAllNodeCount(0), m_iUsedNodeCount(
				0), m_iNodeSize(0) {
}


template<typename T> inline FixAlloc<T>::~FixAlloc() {
	for (uint i = 0; i < m_vctNodeBuffer.size(); ++i) {
		SBufferHead* lpBufHead = m_vctNodeBuffer[i];
		SafeDeleteArray(lpBufHead);
	}
	m_vctNodeBuffer.clear();
	m_iNodeCount = 0;
	m_iAllNodeCount = 0;
	m_iUsedNodeCount = 0;
}


template<typename T> inline
bool FixAlloc<T>::Init(int iCount, int iNodeSize, bool bFixed,
		bool bConstruct) {
	m_bFixed = bFixed;
	m_bConstruct = bConstruct;
	m_iNodeSize = iNodeSize;
	if (m_iNodeSize <= 0) {
		m_iNodeSize = sizeof(T);
	}

	if (iCount > 0) {
		m_iNodeCount = iCount;
		return AllocOneBlock();
	}

	return false;
}


template<typename T> inline
bool FixAlloc<T>::InitBufferToList(char* lpBuffer, int iCount) {
	int iNodeSize = sizeof(SInnerListNode) + m_iNodeSize;
	SBufferHead* lpBufHead = reinterpret_cast<SBufferHead*>(lpBuffer);
	lpBufHead->iRefCount = 0;
	lpBufHead->lpFirstPtr = lpBuffer;
	lpBufHead->lpLastPtr =
			(lpBuffer + iCount * iNodeSize + sizeof(SBufferHead));
	lpBufHead->lpFreeHead = NULL;

	char* lpNodeBuf = lpBuffer + sizeof(SBufferHead);
	SInnerListNode* lpNode = reinterpret_cast<SInnerListNode*>(lpNodeBuf);
	lpNode->lpNext = NULL;
	for (int i = 0; i < iCount - 1; ++i) {
		SInnerListNode* lpNode1 = reinterpret_cast<SInnerListNode*>(lpNodeBuf
				+ i * iNodeSize);
		SInnerListNode* lpNode2 = reinterpret_cast<SInnerListNode*>(lpNodeBuf
				+ (i + 1) * iNodeSize);
		lpNode1->lpNext = lpNode2;
		lpNode2->lpNext = NULL;
	}

	lpBufHead->lpFreeHead = lpNode;
	m_vctNodeBuffer.push_back(lpBufHead);
	return true;
}


template<typename T> inline
bool FixAlloc<T>::AllocOneBlock() {
	int iNodeSize = sizeof(SInnerListNode) + m_iNodeSize;
	char* lpBuffer = new char[sizeof(SBufferHead) + m_iNodeCount * iNodeSize];
	if (lpBuffer != NULL) {
		m_iAllNodeCount += m_iNodeCount;
		if (!InitBufferToList(lpBuffer, m_iNodeCount)) {
			SafeDeleteArray(lpBuffer);
			return false;
		}
		return true;
	}
	return false;
}


template<typename T> inline T* FixAlloc<T>::GetNodeByIdx(int iIdx) {
	if (iIdx >= 0 && iIdx < m_iAllNodeCount) {
		int iBlockIdx = iIdx / m_iNodeCount;
		int iInnerIdx = iIdx % m_iNodeCount;
		SBufferHead* lpBufferHead = m_vctNodeBuffer[iBlockIdx];
		char* lpNodeBuf = lpBufferHead->lpFirstPtr + sizeof(SBufferHead);
		int iNodeSize = sizeof(SInnerListNode) + m_iNodeSize;
		T* lpObject = reinterpret_cast<T*>(lpNodeBuf + iInnerIdx * iNodeSize
				+ sizeof(SInnerListNode));
		return lpObject;
	}
	return NULL;
}


template<typename T> inline T* FixAlloc<T>::Alloc(uint32* lpulPos) {
	SBufferHead* lpBufHead = NULL;
	StdVctNodeBufferIter iter = m_vctNodeBuffer.begin();
	for (int i = 0; iter != m_vctNodeBuffer.end(); ++iter, ++i) {
		lpBufHead = (*iter);
		if (lpBufHead->lpFreeHead != NULL) {
			if (lpulPos != NULL) {
				int iNodeSize = sizeof(SInnerListNode) + m_iNodeSize;
				int iOffsetSize = int32(
						reinterpret_cast<char*>(lpBufHead->lpFreeHead)
								- lpBufHead->lpFirstPtr) - sizeof(SBufferHead);
				int32 lOffsetPos = iOffsetSize / iNodeSize;
				assert((iOffsetSize%iNodeSize) == 0);
				*lpulPos = m_iNodeCount * i + lOffsetPos;
			}
			break;
		}
	}

	if (NULL == lpBufHead || NULL == lpBufHead->lpFreeHead) {
		if (!m_bFixed) {
			// alloc new block
			if (!AllocOneBlock()) {
				return NULL;
			}
			lpBufHead = m_vctNodeBuffer[m_vctNodeBuffer.size() - 1];

			if (lpulPos != NULL) {
				*lpulPos = m_iAllNodeCount - m_iNodeCount;
			}
		} else {
			return NULL;
		}
	}

	assert(lpBufHead->lpFreeHead != NULL);
	SInnerListNode* lpNode = lpBufHead->lpFreeHead;
	++lpBufHead->iRefCount;
	lpBufHead->lpFreeHead = lpBufHead->lpFreeHead->lpNext;
	lpNode->lpNext = NULL;

	T* lpObject = reinterpret_cast<T*>(reinterpret_cast<char*>(lpNode)
			+ sizeof(SInnerListNode));
	++m_iUsedNodeCount;

	if (m_bConstruct) {
		new (reinterpret_cast<void*>(lpObject)) T();
	}

	return lpObject;
}


template<typename T> inline
void FixAlloc<T>::Free(T* lpObject) {
	if (lpObject != NULL) {
		if (m_bConstruct) {
			(lpObject)->~T();
		}

		SInnerListNode* lpNode =
				reinterpret_cast<SInnerListNode*>(reinterpret_cast<char*>(lpObject)
						- sizeof(SInnerListNode));
		char* lpNodePtr = reinterpret_cast<char*>(lpNode);

		SBufferHead* lpBufHead = NULL;
		StdVctNodeBufferIter iter = m_vctNodeBuffer.begin();
		for (; iter != m_vctNodeBuffer.end(); ++iter) {
			lpBufHead = (*iter);
			/// ��Ҫ�������ڴ�Ϸ��Եļ��
			if (lpNodePtr >= lpBufHead->lpFirstPtr
					&& lpNodePtr < lpBufHead->lpLastPtr) {
				lpNode->lpNext = lpBufHead->lpFreeHead;
				lpBufHead->lpFreeHead = lpNode;
				--lpBufHead->iRefCount;
				assert(lpBufHead->iRefCount >= 0);
				/// ȷ�����ٻ�ʣһ���ڴ�ɹ�ʹ��
				if (lpBufHead->iRefCount == 0 && m_vctNodeBuffer.size() > 1) {
					char* lpFirstPtr = lpBufHead->lpFirstPtr;
					SafeDeleteArray(lpFirstPtr);
					m_vctNodeBuffer.erase(iter);
				}
				--m_iUsedNodeCount;
				break;
			}
		}
	}
}


template<typename T> inline
int FixAlloc<T>::GetAllCount() {
	return m_iAllNodeCount;
}


template<typename T> inline
int FixAlloc<T>::GetFreeCount() {
	return m_iAllNodeCount - m_iUsedNodeCount;
}


template<typename T> inline
int FixAlloc<T>::GetUsedCount() {
	return m_iUsedNodeCount;
}

#endif // _FIXALLOC_H_
