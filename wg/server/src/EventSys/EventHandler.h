/*
 * EventHandler.h
 *
 *  Created on: 2013-3-7
 *      Author: qujianbiao
 */

#ifndef EVENTHANDLER_H_
#define EVENTHANDLER_H_
#include <IEventHandler.h>
#include <fixAlloc.h>
#include <ptrList.h>
#include <userDataObject.h>
#include <map>

class EventHandler: public IEventHandler {
DECLARE_TQINTERFACE()DECLARE_DEFAULT_EVENTLISTENER()
	DECLARE_DEFAULT_RENDERLISTENER()
	DECLARE_DEFAULT_UPDATELISTENER()

public:
	bool Init(int iInitNodeCount, EEventHandlerFlag eFlag);
	TQHANDLE Register(object_id lObjFromId, object_id lObjToId,
			EEventType eEventType, const DelegationEvent& objCallback,
			const UserDataObject* lpUserData);
	void UnRegister(TQHANDLE hHandle);
	bool GetEvtHandlerEnabled();
	const IEventHandler* GetNextHandler() const;
	const IEventHandler* GetPreviousHandler() const;
	void ProcessEvent(SEvent& stEvent);
	void SetEvtHandlerEnabled(bool bEnabled);
	void SetNextHandler(const IEventHandler* lpHandler);
	void SetPreviousHandler(const IEventHandler* lpHandler);

	bool OnOneTimeInit();
	void OnOneTimeRelease();

public:
	EventHandler();
	virtual ~EventHandler();

public:
	struct SRegCallBackNode;
	typedef PtrList<SRegCallBackNode> TqLstCallBack;
	typedef TqLstCallBack::Iterator TqLstCallBackIter;

	/** �ص�ע��ڵ�ṹ */
	struct SRegCallBackNode {
		/// ����Ȥ�Ķ�����ʼID
		object_id lObjFromId;
		/// ����Ȥ�Ķ������ID
		object_id lObjToId;
		/// ������¼��Ļص�����
		DelegationEvent objCallback;
		/// �û�����
		UserDataObject userData;
		/// �ýڵ�����������ָ��
		TqLstCallBack* lpList;
		/// �ýڵ���¼�����
		int iEventType;
		/** ���캯�� */
		SRegCallBackNode() :
				lObjFromId(0), lObjToId(0), lpList(NULL), iEventType(0) {
		}
		/** �������캯�� */
		SRegCallBackNode(const SRegCallBackNode& other) {
			lObjFromId = other.lObjFromId;
			lObjToId = other.lObjToId;
			objCallback = other.objCallback;
			userData = other.userData;
			lpList = other.lpList;
			iEventType = other.iEventType;
		}
		/** ����==������ */
		bool operator ==(const SRegCallBackNode& stOther) const {
			return (lObjFromId == stOther.lObjFromId
					&& lObjToId == stOther.lObjToId
					&& objCallback == stOther.objCallback
					&& userData == stOther.userData);
		}
	};

	/// ����map<key, >�е�key��lEventId
	typedef std::map<int32, TqLstCallBack*> StdMapCallBack;
	typedef StdMapCallBack::iterator StdMapCallBackIter;

private:
	/** �ж�һ��id�Ƿ��������id�ķ�Χ��
	 @param lFromId
	 �������ʼid
	 @param lToId
	 �����ĩβid
	 @param lCurId
	 Ҫ�����id
	 @return
	 ����true��ʾlCurId��[lFromId,lToId]������
	 */
	bool InObjectIdRange(object_id lFromId, object_id lToId, object_id lCurId);

	/** ����Id
	 @param lFromId
	 �������ʼid
	 @param lToId
	 �����ĩβid
	 */
	bool AdjustFromToId(object_id& lFromId, object_id& lToId);

	/**  �ͷ��¼����нڵ�
	 */
	void ReleaseListNodes(TqLstCallBack* lpList);

private:
	/// �¼��ص�map
	StdMapCallBack m_mapCallBacks;
	/// ��ʶ��ǰ�Ĵ������Ƿ����
	bool m_bEnable;
	/// ��ǰ����������һ�������ֵ�ָ��
	IEventHandler* m_lpPreviousHandler;
	/// ��ǰ����������һ�������ֵ�ָ��
	IEventHandler* m_lpNextHandler;

private:
	/// �¼��ڵ������
	static FixAlloc<SRegCallBackNode> sm_objRegCallbackNodeAlloc;
	/// �¼��ڵ�������Ƿ񱻳�ʼ����־
	static bool sm_bInitAlloc;
	/// �¼����з�����
	static FixAlloc<TqLstCallBack> sm_objCallbackListAlloc;
};

#endif /* EVENTHANDLER_H_ */
