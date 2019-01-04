#ifndef _FIX_QUEUE_H_
#define _FIX_QUEUE_H_
#include <commhead.h>

/** �̶��ڵ�����Ķ��� */
template<class _Ty>
class FixQueue {
public:
	/** ��ʼ�����к��� 
	 @param iNodeCount
	 �ڵ����
	 @param uiType
	 ���б�־,Ĭ���Ƕ��̱߳�����
	 @return
	 ����true��false */
	bool init(int iNodeCount);

	/** �����ѹ��ĳֵ 
	 @param val
	 Ҫѹ���ֵ */
	void push(const _Ty& val);

	/** ���ض��ж�����ֵ */
	_Ty top();

	/** �����ж����������@see topʹ�� */
	void pop();

	/** �ж϶����Ƿ�Ϊ�� */
	bool empty();

	/** �ж϶����Ƿ�Ϊ�� */
	bool full();

	/** ��ն��У����е�������С�����ı� */
	void clear();

public:
	/** ���캯�� */
	FixQueue();
	/** ���캯�� 
	 @param iNodeCount
	 �ڵ����
	 @param uiType
	 ���б�־,Ĭ���Ƕ��̱߳����� */
	FixQueue(int iNodeCount);
	/** �������� */
	~FixQueue();

private:
	int _iTop;					/// ����ͷλ��
	int _iTail;					/// ����βλ��
	int _iCount;				/// ����ʵ�ʽڵ�ĸ�����=iNodeCount+1
	std::vector<_Ty> _vctQueue;	/// �������ݴ�ŵ�ʵ������
};

template<class _Ty> inline FixQueue<_Ty>::FixQueue() :
		_iTop(0), _iTail(0), _iCount(0) {
}

template<class _Ty> inline FixQueue<_Ty>::FixQueue(int iNodeCount) {
	bool bRt = init(iNodeCount);
	assert(bRt);
}

template<class _Ty> inline FixQueue<_Ty>::~FixQueue() {
	_vctQueue.clear();
}

template<class _Ty> inline
bool FixQueue<_Ty>::init(int iNodeCount) {
	_iCount = iNodeCount + 1;
	_vctQueue.resize(_iCount);
	_iTop = 0;
	_iTail = 0;
	return true;
}

template<class _Ty> inline
void FixQueue<_Ty>::push(const _Ty& val) {
	int iTimes = 0;
	while (true) {
		if (_iTop == _iTail
				|| ((_iTail + _iCount - _iTop) % _iCount) < (_iCount - 1)) {
			_vctQueue[_iTail++] = val;
			_iTail = _iTail % _iCount;
			break;
		}

		if ((++iTimes) > 1000) {
			iTimes = 0;
			std::cerr << "the fix queue fill, can't push val in the queue!"
					<< std::endl;
		}

		// block here
		tq_sleep(1);
	}
}

template<class _Ty> inline _Ty FixQueue<_Ty>::top() {
	_Ty val;
	val = _vctQueue[_iTop];
	return val;
}

template<class _Ty> inline
void FixQueue<_Ty>::pop() {
	if (_iTop != _iTail) {
		_iTop = (_iTop + 1) % _iCount;
	}
}

template<class _Ty> inline
bool FixQueue<_Ty>::empty() {
	return (_iTop == _iTail);
}

template<class _Ty> inline
bool FixQueue<_Ty>::full() {
	return ((_iTail + _iCount - _iTop) % _iCount) == (_iCount - 1);
}

template<class _Ty> inline
void FixQueue<_Ty>::clear() {
	_iTop = _iTail = 0;
}

#endif // _FIX_QUEUE_H_
