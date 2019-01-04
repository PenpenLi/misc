#ifndef _PTRLIST_H_
#define _PTRLIST_H_
#include "fixAlloc.h"
#include "singleton.h"

const int C_PTRLISTALLOC_NODE_COUNT = 4096;
const bool C_ISFIXED_ALLOC_PTRLISTALLOC_NODE = false;

//==============================================================================
struct SListNode {
	/** ��һ�ڵ���뵱ǰ�ڵ��ǰ��
	 @param lpInsertNode
	 Ҫ����Ľڵ� */
	void InsertBefore(SListNode* lpInsertNode);

	/** ��һ�ڵ���뵱ǰ�ڵ�ĺ���
	 @param lpInsertNode
	 Ҫ����Ľڵ� */
	void InsertAfter(SListNode* lpInsertNode);

	/** ����ǰ�ڵ���������Ƴ� */
	void RemoveSelfFromList();

	/** ���캯�� */
	SListNode();

	SListNode* lpPrev;
	SListNode* lpNext;
};

inline SListNode::SListNode() :
		lpPrev(NULL), lpNext(NULL) {
}

inline
void SListNode::InsertBefore(SListNode* lpInsertNode) {
	if (lpInsertNode) {
		lpInsertNode->lpPrev = this->lpPrev;
		lpInsertNode->lpNext = this;
		if (this->lpPrev) {
			this->lpPrev->lpNext = lpInsertNode;
		}
		this->lpPrev = lpInsertNode;
	}
}

inline
void SListNode::InsertAfter(SListNode* lpInsertNode) {
	if (lpInsertNode) {
		lpInsertNode->lpPrev = this;
		lpInsertNode->lpNext = this->lpNext;
		if (this->lpNext) {
			this->lpNext->lpPrev = lpInsertNode;
		}
		this->lpNext = lpInsertNode;
	}
}

inline
void SListNode::RemoveSelfFromList() {
	if (this->lpPrev) {
		this->lpPrev->lpNext = this->lpNext;
	}

	if (this->lpNext) {
		this->lpNext->lpPrev = this->lpPrev;
	}

	lpPrev = NULL;
	lpNext = NULL;
}

//==============================================================================
/** ĳ����ָ������ڵ� */
template<typename T>
struct SPtrListNode: public SListNode {
	/** ���캯�� */
	SPtrListNode();

	/** ǰһ���ڵ�ָ�� */
	SPtrListNode<T>* Prev() const;

	/** ��һ���ڵ�ָ�� */
	SPtrListNode<T>* Next() const;

	/** ��ǰ�ڵ�ֵ */
	T* Value();

	T* lpPtr;
};

template<typename T> inline SPtrListNode<T>::SPtrListNode() :
		lpPtr(NULL) {
}

template<typename T> inline SPtrListNode<T>* SPtrListNode<T>::Prev() const {
	return static_cast<SPtrListNode<T>*>(lpPrev);
}

template<typename T> inline SPtrListNode<T>* SPtrListNode<T>::Next() const {
	return static_cast<SPtrListNode<T>*>(lpNext);
}

template<typename T> inline T* SPtrListNode<T>::Value() {
	return lpPtr;
}

//==============================================================================
/** �����б�ڵ�ĵ��� */
class PtrListAlloc: public Singleton<PtrListAlloc> {
	DECLARE_SINGLETON(PtrListAlloc);
public:
	/** ����һ�����õĽڵ�
	 �������ΪNULL�������㺬�壬һ�ǿɷ������Ϊ��(bFixedΪtrue)��
	 һ���ڴ��ù�(bFixedΪfalse)	*/
	SPtrListNode<void>* Alloc();

	/** �ͷ�һ���ڵ�
	 @param lpObject
	 �����ͷŵĶ���ָ�� */
	void Free(SPtrListNode<void>* lpObject);

private:
	/** ���캯����˽�л���Ŀ���Ƿ�ֹ�����ط��������ȷ����һ��*/
	PtrListAlloc();

private:
	/** ����ڵ���������� */
	FixAlloc<SPtrListNode<void> > m_objNodeAlloc;
};

inline PtrListAlloc::PtrListAlloc() {
	m_objNodeAlloc.Init(C_PTRLISTALLOC_NODE_COUNT, 0,
			C_ISFIXED_ALLOC_PTRLISTALLOC_NODE, true);
}

inline SPtrListNode<void>* PtrListAlloc::Alloc() {
	return m_objNodeAlloc.Alloc();
}

inline
void PtrListAlloc::Free(SPtrListNode<void>* lpObject) {
	m_objNodeAlloc.Free(lpObject);
}

//==============================================================================
/** ָ������ @see SPtrListNode �� @see PtrListAlloc*/

template<typename T>
class PtrList {
public:
	typedef SPtrListNode<T> Iterator;

public:
	/** �������ͷ����һ������ָ��
	 @param lpPtr
	 ��Ҫ����Ķ���ָ��
	 @return
	 ���ؽڵ�ָ�� */
	Iterator* PushFront(T* lpPtr);

	/** �������β����һ������ָ��
	 @param lpPtr
	 ��Ҫ����Ķ���ָ��
	 @return
	 ���ؽڵ�ָ�� */
	Iterator* PushBack(T* lpPtr);

	/** ��һ������ڵ�Attach�������ͷ,������ڵ���Ҫ�Ǳ�Pick������
	 @param lpNode
	 ��ҪAttack������ڵ�*/
	void AttachFront(Iterator* lpNode);

	/** ��һ������ڵ�Attach�������β,������ڵ���Ҫ�Ǳ�Pick������
	 @param lpNode
	 ��ҪAttach������ڵ�*/
	void AttachBack(Iterator* lpNode);

	/** ����ͷ�Ƴ� */
	void PopFront();

	/** ����β�Ƴ� */
	void PopBack();

	/** �������н��ýڵ�ժȡ
	 @remark
	 ��@see Erase ��ͬ���ǣ�Pickֻ�ǽ��ýڵ�ժȡ��������������ɾ���ýڵ�
	 ���ýڵ㻹��Ҫ���뵽�����С�
	 @param lpNode
	 ��Ҫժȡ�Ľڵ�ָ��
	 @return
	 �����¸��ڵ��ָ��*/
	Iterator* Pick(Iterator* lpNode);

	/** �Ƴ�һ������Ľڵ�ָ��
	 @param lpNode
	 ��Ҫ�Ƴ��Ľڵ�ָ��
	 @return
	 �����¸��ڵ��ָ��*/
	Iterator* Erase(Iterator* lpNode);

	/** ���ر�ͷ��ֵ */
	T* Front();

	/** ���ر�β��ֵ */
	T* Back();

	/** ����һ������
	 @param lpObj
	 Ҫ���ҵĶ���
	 @return
	 ���ص�ǰ�����������α� */
	Iterator* Find(const T* lpObj);

	/** ��ָ���ķ�Χ�ڲ���һ������
	 @param lpBegin
	 ��Χ�α�ͷ
	 @param lpEnd
	 ��Χ�α�β
	 @param lpObj
	 Ҫ���ҵĶ���
	 @return
	 ���ص�ǰ�����������α� */
	Iterator* FindInRange(Iterator* lpBegin, Iterator* lpEnd, const T* lpObj);

	/** ���������Ƴ�ָ����ֵ
	 @param lpObj
	 �����Ƴ���ֵ
	 @remark
	 ���ڸò�����Ҫ������������ڵ�,���Ժ�ʱ�ϳ�,�����ڱȽ�ʱʹ�� */
	void Remove(T* lpObj);

	/** ���ص�ǰ�����Ƿ�Ϊ�� */
	bool IsEmpty(void);

	/** ��ȡ����Ŀ�ʼ�ڵ�ָ�� */
	Iterator* Begin() const;

	/** ��ȡ����Ľ���Eof�ڵ�ָ�� */
	Iterator* End() const;

	/** ������� */
	void Clear();

	/** �ͷ������б���Դ */
	void Release();

public:
	/** ���캯�� */
	PtrList();

	/** �������� */
	virtual ~PtrList();

private:
	/** ����ͷ�ڵ�ָ�� */
	SPtrListNode<T>* m_lpHead;
	/** ����β�ڵ�ָ�� */
	SPtrListNode<T>* m_lpTail;
};

template<typename T> inline PtrList<T>::PtrList() {
	m_lpHead =
			reinterpret_cast<SPtrListNode<T>*>(PtrListAlloc::Instance()->Alloc());
	m_lpTail =
			reinterpret_cast<SPtrListNode<T>*>(PtrListAlloc::Instance()->Alloc());
	m_lpHead->lpPrev = NULL;
	m_lpHead->lpNext = m_lpTail;
	m_lpTail->lpPrev = m_lpHead;
	m_lpTail->lpNext = NULL;
}

template<typename T> inline PtrList<T>::~PtrList() {
	Release();
}

template<typename T> inline typename PtrList<T>::Iterator* PtrList<T>::PushFront(
		T* lpPtr) {
	SPtrListNode<T>* lpNode = NULL;
	if (lpPtr != NULL) {
		lpNode =
				reinterpret_cast<SPtrListNode<T>*>(PtrListAlloc::Instance()->Alloc());
		lpNode->lpPtr = lpPtr;
		m_lpHead->InsertAfter(lpNode);
	}
	return lpNode;
}

template<typename T> inline typename PtrList<T>::Iterator* PtrList<T>::PushBack(
		T* lpPtr) {
	Iterator* lpNode = NULL;
	if (lpPtr != NULL) {
		lpNode = reinterpret_cast<Iterator*>(PtrListAlloc::Instance()->Alloc());
		lpNode->lpPtr = lpPtr;
		m_lpTail->InsertBefore(lpNode);
	}
	return lpNode;
}

template<typename T> inline
void PtrList<T>::AttachFront(Iterator* lpNode) {
	if (lpNode != NULL) {
		m_lpHead->InsertAfter(lpNode);
	}
}

template<typename T> inline
void PtrList<T>::AttachBack(Iterator* lpNode) {
	if (lpNode != NULL) {
		m_lpTail->InsertBefore(lpNode);
	}
}

template<typename T> inline
void PtrList<T>::PopFront() {
	if (!IsEmpty()) {
		Erase(m_lpHead->Next());
	}
}

template<typename T> inline
void PtrList<T>::PopBack() {
	if (!IsEmpty()) {
		Erase(m_lpTail->Prev());
	}
}

template<typename T> inline typename PtrList<T>::Iterator* PtrList<T>::Erase(
		Iterator* lpPtr) {
	Iterator* lpNext = Pick(lpPtr);
	if (lpPtr) {
		PtrListAlloc::Instance()->Free(
				reinterpret_cast<SPtrListNode<void>*>(lpPtr));
	}
	return lpNext;
}

template<typename T> inline typename PtrList<T>::Iterator* PtrList<T>::Pick(
		Iterator* lpPtr) {
	Iterator* lpNext = NULL;
	if (lpPtr != NULL && lpPtr != m_lpHead && lpPtr != m_lpTail) {
		lpNext = lpPtr->Next();
		lpPtr->RemoveSelfFromList();
	} else if (lpPtr == m_lpHead || lpPtr == m_lpTail) {
		lpPtr = lpNext->Prev();  // crash it
	}
	return lpNext;
}

template<typename T> inline T* PtrList<T>::Front() {
	if (!IsEmpty()) {
		return m_lpTail->Prev()->Value();
	}
	return NULL;
}

template<typename T> inline T* PtrList<T>::Back() {
	if (!IsEmpty()) {
		return m_lpHead->Next()->Value();
	}
	return NULL;
}

template<typename T> inline typename PtrList<T>::Iterator* PtrList<T>::Find(
		const T* lpObj) {
	return FindInRange(Begin(), End(), lpObj);
}

template<typename T> inline typename PtrList<T>::Iterator* PtrList<T>::FindInRange(
		Iterator* lpBegin, Iterator* lpEnd, const T* lpObj) {
	Iterator* lpIter = lpBegin;
	for (; lpIter != lpEnd; lpIter = lpIter->Next()) {
		if (lpIter->Value() == lpObj) {
			return lpIter;
		}
	}
	return lpEnd;
}

template<typename T> inline
void PtrList<T>::Remove(T* lpObj) {
	Iterator* lpIter = FindInRange(Begin(), End(), lpObj);
	while (lpIter != End()) {
		lpIter = Erase(lpIter);
		lpIter = FindInRange(lpIter, End(), lpObj);
	}
}

template<typename T> inline
bool PtrList<T>::IsEmpty() {
	return (m_lpHead->Next() == m_lpTail);
}

template<typename T> inline typename PtrList<T>::Iterator* PtrList<T>::Begin() const {
	return m_lpHead->Next();
}

template<typename T> inline typename PtrList<T>::Iterator* PtrList<T>::End() const {
	return m_lpTail;
}

template<typename T> inline
void PtrList<T>::Clear() {
	Iterator* lpNode = Begin();
	Iterator* lpNextNode = lpNode;
	while (lpNode != End()) {
		lpNextNode = lpNode->Next();
		lpNode->RemoveSelfFromList();
		PtrListAlloc::Instance()->Free(
				reinterpret_cast<SPtrListNode<void>*>(lpNode));
		lpNode = lpNextNode;
	}
}

template<typename T> inline
void PtrList<T>::Release() {
	SPtrListNode<T>* lpNode = m_lpHead;
	SPtrListNode<T>* lpNextNode = lpNode;
	while (lpNode) {
		lpNextNode = static_cast<SPtrListNode<T>*>(lpNode->lpNext);
		PtrListAlloc::Instance()->Free(
				reinterpret_cast<SPtrListNode<void>*>(lpNode));
		lpNode = lpNextNode;
	}

	m_lpHead = NULL;
	m_lpTail = NULL;
}

#endif // _PTRLIST_H_
