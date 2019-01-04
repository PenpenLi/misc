#ifndef I_RANKMANAGER_H_
#define I_RANKMANAGER_H_
#include <commhead.h>
#include "IGridsManager.h"
#include "IRank.h"

//tolua_begin
class IRankManager {
public:
	/**
	 * @param rankName
	 * 	"actTower", "role"
	 */
	virtual IRank* GetRank(const char* rankName) = 0;

	/**
	 * �ڿ�ʼǰ����
	 */
	virtual void StartChangeRolePos(int64 roleId) = 0;

	/**
	 * �����grid�����
	 */
	virtual void AddNewRole(int64 roleId) = 0;

	/**
	 * ��ɾ��ǰ����
	 */
	virtual void RemoveRole(int64 roleId) = 0;

	/**
	 * ȫ����������
	 */
	virtual void EndChangeRolePos(int64 roleId)=0;

	//tolua_end
	virtual ~IRankManager(){};
	//tolua_begin
};
//tolua_end

#endif /* I_RANKMANAGER_H_ */
