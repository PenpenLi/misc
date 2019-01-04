#ifndef _DELEGATION_H_
#define _DELEGATION_H_
#include <assert.h>

/** �ṩClosure�洢�ռ��������
 */
struct ObjectPlaceHolder {
	/** ����ģ��ʵ�������������࣬��Ա����ָ�����м̳����޼̳��´�С��һ����
	 ObjectPlaceHolder��Ҫ�ṩ�㹻�Ŀռ乩MemFuncInvoker...ʵ���洢��������
	 Ҫ����̳�����ģ���Ա����ָ�롣
	 */
	class DummyBaseA {
	};
	class DummyBaseB {
	};
	class DummyClass: public DummyBaseA, public DummyBaseB {
	};

public:
	ObjectPlaceHolder() {
		Clear();
	}
	ObjectPlaceHolder(const ObjectPlaceHolder& other) {
		obj = other.obj;
		fptr = other.fptr;
	}
	inline bool IsNull(void) const {
		return obj == NULL;
	}
	inline void Clear(void) {
		obj = NULL;
		fptr = NULL;
	}
	inline bool operator ==(const ObjectPlaceHolder& other) const {
		return (obj == other.obj && fptr == other.fptr);
	}
private:
	DummyClass* obj;
	void (DummyClass::*fptr)(void);
};

/** Closure����ʵ�֣�ͬʱʵ���˾�̬��Ա�����ӿ�invoke������ʵ���麯�����ƹ��ܵĹؼ�
 ���ص�new����ʹ��ָ���Ŀռ���Ϊ����ʵ�����Ŀռ䣬��Ϊ����ʵ�������õ�ί�з��Ŀ�
 �䣬������Ҫ�ͷţ�����delete����ʲôҲ����
 */
template<typename Delegation, typename T, typename R, typename V>
struct MemFuncInvoker0 {
private:
	struct Wrapper { typedef Delegation type; };
	friend class Wrapper :: type;
	typedef MemFuncInvoker0<Delegation, T, R, V> ThisType;
	typedef R (T::*Fptr)(V);
	MemFuncInvoker0(T* obj, Fptr func) {
		mObj = obj;
		mFunc = func;
	}
	static inline R Invoke(const ObjectPlaceHolder* address, V var) {
		const ThisType* pThis = reinterpret_cast<const ThisType*>(address);
		T* pObj = pThis->mObj;
		Fptr pFunc = pThis->mFunc;
		(pObj->*pFunc)(var);
	}
	static inline void* operator new(size_t size,
			const ObjectPlaceHolder* address, size_t space) {
		assert(size<=space);
		return (void*) address;
	}
	static inline void operator delete(void*, const ObjectPlaceHolder* address,
			size_t space) {
	}
private:
	T* mObj;
	Fptr mFunc;
};

/** ί�е�ʵ�� �޷���ֵ
 */
template<typename R, typename V>
struct Delegation0 {
public:
	typedef Delegation0<R, V> ThisType;
	typedef R (*InvokerType)(const ObjectPlaceHolder*, V);
public:
	Delegation0() {
		Detach();
	}
	Delegation0(const Delegation0& other) {
		mObj = other.mObj;
		invoker = other.invoker;
	}
	template<typename T>
	Delegation0(T* obj, R (T::*fptr)(V)) {
		Attach(obj, fptr);
	}
	template<typename T>
	inline void Attach(T* obj, R (T::*fptr)(V)) {
		invoker = MemFuncInvoker0<ThisType, T, R, V>::Invoke;
		new (&mObj, sizeof(ObjectPlaceHolder)) MemFuncInvoker0<ThisType, T, R, V>(
				obj, fptr);
	}
	inline void Detach(void) {
		mObj.Clear();
		invoker = NULL;
	}
	inline bool IsNull(void) const {
		return mObj.IsNull() || invoker == NULL;
	}
	inline R operator ()(V var) {
		invoker(&mObj, var);
	}
	inline bool operator ==(const Delegation0& other) const {
		return (mObj == other.mObj);
	}
private:
	//��������MemFuncInvokerʵ���Ŀռ�
	ObjectPlaceHolder mObj;
	InvokerType invoker;
};

#endif //_DELEGATION_H_
