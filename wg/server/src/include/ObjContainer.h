#ifndef _OBJ_CONTAINER_H
#define _OBJ_CONTAINER_H
#include <commhead.h>
#include <vector>
#include <fixAlloc.h>
#include <fixQueue.h>

/** ����������� */
template<class T>
class ObjContainer {
public:
	/** ��ʼ���÷���������� 
	 @param type
	 ���������
	 @param maxcount
	 �����ɷ�������������
	 @return
	 ����true��false*/
	bool init(uchar type, int maxcount);

	/** ͨ�������id��øö���ָ�� 
	 @param lId
	 ����id
	 @return
	 ���ض���ָ���NULL*/
	T* getById(object_id id);

	/** ��ȡ�ܵĶ������������NULL���� */
	int getCount();

	/** ͨ�������������øö���ָ�� 
	 @param idx
	 ���������
	 @return
	 ���ض���ָ���NULL*/
	T* getByIdx(uint32 idx);

	/** �ͷ�һ������
	 @param lId
	 Ҫ�ͷŵĶ���id*/
	void freeObject(object_id id);

	/** ����һ������ 
	 @return
	 ���ض����ָ���NULL */
	T* allocObject();

public:
	/** ���캯�� */
	ObjContainer();
	/** �������� */
	virtual ~ObjContainer();

private:
	object_id getNewObjectId();

private:
	FixAlloc<T> m_allocs;	// ���������
	FixQueue<object_id> m_freeIds; // ��ſ��еĽڵ�
	std::vector<T*> m_objects;	// ��Ŷ���ָ��
	uchar m_type; // ���������
};

template<class T> inline ObjContainer<T>::ObjContainer() :
		m_type(0) {
}

template<class T> inline ObjContainer<T>::~ObjContainer() {
}

template<class T> inline
bool ObjContainer<T>::init(uchar type, int maxcount) {
	if (maxcount <= 0)
		return false;
	m_type = type;
	m_allocs.Init(maxcount, 0, true, true);
	m_objects.resize(maxcount);
	m_freeIds.init(maxcount);
	for (int i = 0; i < maxcount; ++i) {
		m_objects[i] = NULL;
		m_freeIds.push((object_id)(i));
	}
	return true;
}

template<class T> inline T* ObjContainer<T>::getById(object_id id) {
	int32 idx = GETSIMOBJINDEX(id);
	if (idx < 0 || idx >= (int32)m_objects.size())
		return NULL;
	T* obj = m_objects[idx];
	if (obj != NULL && obj->getId() == id) {
		return obj;
	}
	return NULL;
}

template<class T> inline int ObjContainer<T>::getCount() {
	return (int)m_objects.size();
}

template<class T> inline T* ObjContainer<T>::getByIdx(uint32 idx) {
	if (idx >= (uint32)m_objects.size())
		return NULL;
	return m_objects[idx];
}

template<class T> inline
void ObjContainer<T>::freeObject(object_id id) {
	int32 idx = GETSIMOBJINDEX(id);
	if (idx < 0 || idx >= (int32)m_objects.size())
		return;
	T* obj = m_objects[idx];
	if (obj != NULL && obj->getId() == id) {
		m_allocs.Free(obj);
		m_freeIds.push(id);
		m_objects[idx] = NULL;
		std::clog << "free object id: " << (uint32) id << std::endl;
	}
}

template<class T> inline T* ObjContainer<T>::allocObject() {
	object_id id = getNewObjectId();
	if (id == SIMOBJ_INVALID_ID)
		return NULL;

	std::clog << "alloc object id: " << (uint32) id << std::endl;
	T* obj = m_allocs.Alloc();
	if (obj == NULL) {
		assert(false);
		std::cerr << "alloc object id failed" << std::endl;
		return NULL;
	}

	uint32 idx = GETSIMOBJINDEX(id);
	m_objects[idx] = obj;
	obj->setId(id);
	return obj;
}

template<class T> inline object_id ObjContainer<T>::getNewObjectId() {
	if (m_freeIds.empty())
		return SIMOBJ_INVALID_ID;

	object_id id = m_freeIds.top();
	m_freeIds.pop();
	uint32 idx = GETSIMOBJINDEX(id);
	ushort seq = GETSIMOBJSEQ(id);
	seq = NEXT_OBJ_SEQ(seq);
	return MAKESIMOBJID(idx, m_type, seq);
}

#endif // _OBJ_CONTAINER_H
