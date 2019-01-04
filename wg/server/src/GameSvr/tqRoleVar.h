/** ���ļ������ɹ���tools_h�Զ����ɣ������ֶ��޸ġ� 01/12/15 20:29:51*/
#ifndef _tq_role_338saf3w3_var_h_
#define _tq_role_338saf3w3_var_h_
#include <pkgBits.h>
#include <pkgBase.h>


/**----------------const---------------*/
//tolua_begin
#define PKG_CUR_VER									 127
#define MAX_SQL_LEN									 2097152
#define MAX_ROLE_TABLE_CNT							 1
#define MAX_CITY_STATES_CNT							 32
#define MAX_INBUILD_CNT								 30
#define MAX_BUILDING_CNT							 6
#define MAX_CITY_CNT								 5
#define MAX_SELFFIELD_CNT							 11
#define MAX_ITEMS_CNT								 750
#define MAX_HOLES_CNT								 3
#define MAX_WEARS_CNT								 12
#define MAX_USERNAME_ARR_LEN						 33
#define MAX_USERNAME_LEN							 (MAX_USERNAME_ARR_LEN - 1)
#define MIN_USERNAME_LEN							 3
#define MAX_ROLENAME_ARR_LEN						 22
#define MAX_ROLENAME_LEN							 (MAX_ROLENAME_ARR_LEN - 1)
#define MIN_ROLENAME_LEN							 3
#define MAX_HERONAME_ARR_LEN						 19
#define MAX_HERONAME_LEN							 (MAX_HERONAME_ARR_LEN - 1)
#define MIN_HERONAME_LEN							 2
#define MAX_CITYNAME_ARR_LEN						 22
#define MAX_CITYNAME_LEN							 (MAX_CITYNAME_ARR_LEN - 1)
#define MAX_TASKS_CNT								 500
#define MAX_ONLINE_TASKS_CNT						 4
#define MAX_EVERYDAY_TASKS_CNT						 10
#define MAX_ACT_TASKS_CNT							 100
#define MAX_HERO_CNT								 32
#define MAX_NEWHERO_CNT								 6
#define MAX_SLDS_CNT								 50
#define MAX_GEMBESET_CNT							 3
#define MAX_MAILTITLE_ARR_LEN						 46
#define MAX_MAISYSLCON_ARR_LEN						 4097
#define MAX_MAILCON_ARR_LEN							 751
#define MAX_MAILTITLE_LEN							 (MAX_MAILTITLE_ARR_LEN - 1)
#define MAX_MAISYSLCON_LEN							 (MAX_MAISYSLCON_ARR_LEN - 1)
#define MAX_MAILCON_LEN								 (MAX_MAILCON_ARR_LEN - 1)
#define MAX_BULLETINS_CNT							 16
#define MAX_BUDDYS_CNT								 300
#define MAX_BUDDYS_APPLY_CNT						 10
#define MAX_ROLEATTRS_CNT							 22
#define MAX_HEROATTRS_CNT							 37
#define MAX_SIMPLEHEROATTRS_CNT						 3
#define MAX_NEWHEROATTRS_CNT						 9
#define MAX_FARM_CNT								 120
#define MAX_CULTURE_CNT								 33
#define MAX_FARM_LOG_CNT							 50
#define MAX_SUBJECT_CNT								 5
#define MAX_HEROWEAR_CNT							 7
#define MAX_HERO_SKILL_CNT							 13
#define MAX_HERO_SCUT_CNT							 12
#define MAX_ITEM_ATTRS_CNT							 18
#define MAX_FAVORITE_CNT							 10
#define MAX_ENEMY_CNT								 300
#define MAX_SUCC_COPYFIELD_CNT						 30
#define MAX_LINEUP_CNT								 16
#define MAX_DEFAULTTEAM_HERO_CNT					 5
#define MAX_DEFAULTTEAM_CNT							 3
#define MAX_TEAM_HERO_CNT							 5
#define MAX_SELFARMY_CNT							 20
#define MAX_ENEMYARMY_CNT							 50
#define MAX_ALLIARMY_CNT							 10
#define MAX_PAIQIAN_ALLIARMY_CNT					 5
#define MAX_CITYDEF_CNT								 5
#define MAX_ROLEINTRO_ARR_LEN						 151
#define MAX_ROLEINTRO_LEN							 150
#define MAX_COLLECTOR_CNT							 10
#define MAX_INVITE_JOIN_ALLI_CNT					 10
#define MAX_ALLINAME_ARR_LEN						 22
#define MAX_TRADING_ROLES_CNT						 20
#define MAX_ACT_TERRACE_COUNT						 100
#define MAX_ACTREWARDS_CNT							 4
#define MAX_SIGNINREWARDS_CNT						 3
#define MAX_SIGNINREWARDS_CNT_EX					 4
#define MAX_ACTVALTASKS_CNT							 20
#define MAX_FORCELINEUPCFG_CNT						 2
#define MAX_YD_LVL_IDS_CNT							 15
#define MAX_BD_LVL_IDS_CNT							 15
#define MAX_BUY_ITEMS_CNT							 20
#define MAX_CTLCFG_BTIMAP_CNT						 4
#define MAX_PAYACT_GIFT_CNT							 10
#define MAX_WAIT_BUILDS_CNT							 20
#define MAX_CDKEY_CNT								 20
#define MAX_HELPTIP_CNT								 20
//tolua_end


/**----------------struct---------------*/

#pragma pack(push, 1)
/*
 *  �Ѿ���ɵĽ����ṹ
 */
struct SInBuild //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint32 ulId;												// ����λ��id
	uint32 ulResId;												// ������Դid
	uint8 ucLevel;												// ������ǰ�ȼ�
	uint8 ucState;												// ����״̬
	uint32 ulStoptime;											// ������������ʱ��
	uint32 ulDuration;											// �ȴ�״̬�еĽ�����Ҫ��ʱ��
	//tolua_end

	SInBuild():ulId(0),
		ulResId(0),
		ucLevel(0),
		ucState(0),
		ulStoptime(0),
		ulDuration(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT32(ulId, 1);
		D_UINT32(ulResId, 1);
		D_UINT8(ucLevel, 1);
		D_UINT8(ucState, 1);
		D_UINT32(ulStoptime, 1);
		D_UINT32(ulDuration, 1);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT32(ulId, 1);
		E_UINT32(ulResId, 1);
		E_UINT8(ucLevel, 1);
		E_UINT8(ucState, 1);
		E_UINT32(ulStoptime, 1);
		E_UINT32(ulDuration, 1);
		return iPos;
	}
};//tolua_export


/*
 *  �ڳǽ����б�ṹ
 */
struct SInBuildList //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint8 ucTotal;												// �ڳǽ�������
	SInBuild astInBuilds[MAX_INBUILD_CNT];						// �����б�ľ�������
	//tolua_end

	SInBuildList():ucTotal(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT8(ucTotal, 1);
		D_ARRAY_STRUCT(astInBuilds, ucTotal, MAX_INBUILD_CNT, 1);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT8(ucTotal, 1);
		E_ARRAY_STRUCT(astInBuilds, ucTotal, MAX_INBUILD_CNT, 1);
		return iPos;
	}
};//tolua_export


/*
 *  �ǳ���Դ
 */
struct SCityRes //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint8 ucLevel;												// �Ǳ��ȼ�
	uint32 ulBuildVal;											// �Ǳ������
	uint32 ulHurtBuildVal;										// ����Ľ����
	uint32 todayLostedBuildTime;								// ��������Ľ����ʱ��
	uint32 todayLostedBuildVal;									// ��������Ľ����ֵ
	int32 lIdlePopu;											// �����˿�
	uint64 ullWood;												// ľ��
	uint64 ullStone;											// ʯ��
	uint64 ullIron;												// ����
	uint64 ullFood;												// ��ʳ
	uint64 ullMoney;											// Ǯ��
	uint32 ulMLastTime;											// Ǯ�����һ�εĸ���ʱ��
	uint32 ulILastTime;											// �����˿����һ�εĸ���ʱ��
	uint8 lastMaxLevel;											// �Ǳ��ϴε����ȼ�
	//tolua_end

	SCityRes():ucLevel(0),
		ulBuildVal(0),
		ulHurtBuildVal(0),
		todayLostedBuildTime(0),
		todayLostedBuildVal(0),
		lIdlePopu(0),
		ullWood(0),
		ullStone(0),
		ullIron(0),
		ullFood(0),
		ullMoney(0),
		ulMLastTime(0),
		ulILastTime(0),
		lastMaxLevel(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT8(ucLevel, 1);
		D_UINT32(ulBuildVal, 1);
		D_UINT32(ulHurtBuildVal, 1);
		D_UINT32(todayLostedBuildTime, 1);
		D_UINT32(todayLostedBuildVal, 1);
		D_INT32(lIdlePopu, 1);
		D_UINT64(ullWood, 1);
		D_UINT64(ullStone, 1);
		D_UINT64(ullIron, 1);
		D_UINT64(ullFood, 1);
		D_UINT64(ullMoney, 1);
		D_UINT32(ulMLastTime, 1);
		D_UINT32(ulILastTime, 1);
		D_UINT8(lastMaxLevel, 17);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT8(ucLevel, 1);
		E_UINT32(ulBuildVal, 1);
		E_UINT32(ulHurtBuildVal, 1);
		E_UINT32(todayLostedBuildTime, 1);
		E_UINT32(todayLostedBuildVal, 1);
		E_INT32(lIdlePopu, 1);
		E_UINT64(ullWood, 1);
		E_UINT64(ullStone, 1);
		E_UINT64(ullIron, 1);
		E_UINT64(ullFood, 1);
		E_UINT64(ullMoney, 1);
		E_UINT32(ulMLastTime, 1);
		E_UINT32(ulILastTime, 1);
		E_UINT8(lastMaxLevel, 17);
		return iPos;
	}
};//tolua_export


/*
 *  �ǳط���
 */
struct SCityDef //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint32 defs[MAX_CITYDEF_CNT];								// �Ƿ������б�
	uint32 stopTime;											// ��ǰ���ڽ���Ƿ��Ľ���ʱ��
	uint32 buildResId;											// ��ǰ���ڽ���Ƿ�����Դid
	uint32 buildNumber;											// ��ǰ���ڽ���Ƿ�������
	//tolua_end

	SCityDef():stopTime(0),
		buildResId(0),
		buildNumber(0){
		memset(defs, 0, sizeof(defs[0])*MAX_CITYDEF_CNT);
	}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_ARRAY_UINT32(defs, MAX_CITYDEF_CNT, MAX_CITYDEF_CNT, 1);
		D_UINT32(stopTime, 1);
		D_UINT32(buildResId, 1);
		D_UINT32(buildNumber, 1);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_ARRAY_UINT32(defs, MAX_CITYDEF_CNT, MAX_CITYDEF_CNT, 1);
		E_UINT32(stopTime, 1);
		E_UINT32(buildResId, 1);
		E_UINT32(buildNumber, 1);
		return iPos;
	}
};//tolua_export


/*
 *  effect�ṹ����
 */
struct SEffect //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint16 id;													// Ч��id
	uint32 val;													// Ч��ֵ
	uint8 unit;													// Ч����λ
	//tolua_end

	SEffect():id(0),
		val(0),
		unit(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT16(id, 1);
		D_UINT32(val, 1);
		D_UINT8(unit, 1);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT16(id, 1);
		E_UINT32(val, 1);
		E_UINT8(unit, 1);
		return iPos;
	}
};//tolua_export


/*
 *  �����߽ṹ����
 */
struct SCreator //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint8 type;													// ����������
	uint64 id;													// �����ߵ�id
	uint32 skillId;												// ������ʹ�õļ���id
	//tolua_end

	SCreator():type(0),
		id(0),
		skillId(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT8(type, 1);
		D_UINT64(id, 1);
		D_UINT32(skillId, 1);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT8(type, 1);
		E_UINT64(id, 1);
		E_UINT32(skillId, 1);
		return iPos;
	}
};//tolua_export


/*
 *  state�ṹ����
 */
struct SState //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint32 id;													// state��Ψһid
	uint16 type;												// Ч������
	uint32 startTime;											// ��ǰЧ����ʼ��ʱ��
	uint32 lastTime;											// ���һ�θ���Ч����ʱ��
	uint32 duration;											// ��ʾʱ�����룩
	uint8 isOnline;												// �Ƿ�ֻ�����߲ż�ʱ��
	SCreator creator;											// ������
	SEffect effect;												// Ч��
	//tolua_end

	SState():id(0),
		type(0),
		startTime(0),
		lastTime(0),
		duration(0),
		isOnline(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT32(id, 1);
		D_UINT16(type, 1);
		D_UINT32(startTime, 1);
		D_UINT32(lastTime, 1);
		D_UINT32(duration, 1);
		D_UINT8(isOnline, 1);
		D_STRUCT(creator, 1);
		D_STRUCT(effect, 1);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT32(id, 1);
		E_UINT16(type, 1);
		E_UINT32(startTime, 1);
		E_UINT32(lastTime, 1);
		E_UINT32(duration, 1);
		E_UINT8(isOnline, 1);
		E_STRUCT(creator, 1);
		E_STRUCT(effect, 1);
		return iPos;
	}
};//tolua_export


/*
 *  State�б�ṹ����
 */
struct SStateList //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint8 count;												// State�б�ĸ���
	SState states[MAX_CITY_STATES_CNT];							// State�б�ľ�������
	uint32 lastStateId;											// state���һ�ε�id
	//tolua_end

	SStateList():count(0),
		lastStateId(1000){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT8(count, 1);
		D_ARRAY_STRUCT(states, count, MAX_CITY_STATES_CNT, 1);
		D_UINT32(lastStateId, 101);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT8(count, 1);
		E_ARRAY_STRUCT(states, count, MAX_CITY_STATES_CNT, 1);
		E_UINT32(lastStateId, 101);
		return iPos;
	}
};//tolua_export


/*
 *  �������нṹ
 */
struct SCity //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint8 ucType;												// ���е�����
	SInBuildList stInBuilds;									// �ڳǽ����б�
	//tolua_end

	SCity():ucType(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT8(ucType, 1);
		D_STRUCT(stInBuilds, 1);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT8(ucType, 1);
		E_STRUCT(stInBuilds, 1);
		return iPos;
	}
};//tolua_export


/*
 *  ��ά����
 */
struct SPos //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	int32 x;													// ����x
	int32 y;													// ����y
	//tolua_end

	SPos():x(0),
		y(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_INT32(x, 1);
		D_INT32(y, 1);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_INT32(x, 1);
		E_INT32(y, 1);
		return iPos;
	}
};//tolua_export


/*
 *  ����Ұ�ؽṹ
 */
struct SSelfField //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint32 gridId;												// Ұ�صĸ���id
	uint32 startTime;											// �ɼ���ʼ��ʱ��
	uint32 soldierNumber;										// ����ɼ���ʿ������
	//tolua_end

	SSelfField():gridId(0),
		startTime(0),
		soldierNumber(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT32(gridId, 1);
		D_UINT32(startTime, 1);
		D_UINT32(soldierNumber, 1);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT32(gridId, 1);
		E_UINT32(startTime, 1);
		E_UINT32(soldierNumber, 1);
		return iPos;
	}
};//tolua_export


/*
 *  ��̳�һ�����
 */
struct SExchangeTodayTimes //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint32 curTimes;											// �Ѿ��һ�����
	uint32 maxTimes;											// ����������
	uint32 lastTime;											// �����һ��ʱ��
	//tolua_end

	SExchangeTodayTimes():curTimes(0),
		maxTimes(0),
		lastTime(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT32(curTimes, 13);
		D_UINT32(maxTimes, 13);
		D_UINT32(lastTime, 13);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT32(curTimes, 13);
		E_UINT32(maxTimes, 13);
		E_UINT32(lastTime, 13);
		return iPos;
	}
};//tolua_export


/*
 *  �����б�
 */
struct SCitys //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	SCityRes stCRes;											// �Ǳ���ͨ����Դ
	SCityDef cityDef;											// �ǳط���
	uint8 ucTotal;												// �����б����
	SCity astCitys[MAX_CITY_CNT];								// �����б��������
	uint8 fieldTotal;											// �Լ���Ұ���б����
	SSelfField selfFields[MAX_SELFFIELD_CNT];					// �Լ���Ұ���б����
	SExchangeTodayTimes exchangeTodayTimes;						// ��̳�һ�����
	uint8 startAutoBuild;										// �Ƿ������Զ�����
	int8 waitBuildCount;										// �ȴ��������
	uint32 waitBuilds[MAX_WAIT_BUILDS_CNT];						// �ȴ���������
	//tolua_end

	SCitys():ucTotal(0),
		fieldTotal(0),
		startAutoBuild(0),
		waitBuildCount(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_STRUCT(stCRes, 1);
		D_STRUCT(cityDef, 1);
		D_UINT8(ucTotal, 1);
		D_ARRAY_STRUCT(astCitys, ucTotal, MAX_CITY_CNT, 1);
		D_UINT8(fieldTotal, 1);
		D_ARRAY_STRUCT(selfFields, fieldTotal, MAX_SELFFIELD_CNT, 1);
		D_STRUCT(exchangeTodayTimes, 13);
		D_UINT8(startAutoBuild, 111);
		D_INT8(waitBuildCount, 111);
		D_ARRAY_UINT32(waitBuilds, waitBuildCount, MAX_WAIT_BUILDS_CNT, 111);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_STRUCT(stCRes, 1);
		E_STRUCT(cityDef, 1);
		E_UINT8(ucTotal, 1);
		E_ARRAY_STRUCT(astCitys, ucTotal, MAX_CITY_CNT, 1);
		E_UINT8(fieldTotal, 1);
		E_ARRAY_STRUCT(selfFields, fieldTotal, MAX_SELFFIELD_CNT, 1);
		E_STRUCT(exchangeTodayTimes, 13);
		E_UINT8(startAutoBuild, 111);
		E_INT8(waitBuildCount, 111);
		E_ARRAY_UINT32(waitBuilds, waitBuildCount, MAX_WAIT_BUILDS_CNT, 111);
		return iPos;
	}
};//tolua_export


/*
 *  �׽ṹ
 */
struct SOneHole //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint16 usAttr;												// ���Ե�����
	uint32 ulIdxOrVal;											// ������ֵ
	//tolua_end

	SOneHole():usAttr(0),
		ulIdxOrVal(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT16(usAttr, 1);
		D_UINT32(ulIdxOrVal, 1);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT16(usAttr, 1);
		E_UINT32(ulIdxOrVal, 1);
		return iPos;
	}
};//tolua_export


/*
 *  ��ɫ���й̶������Ի�仯���ٵ�����
 */
struct SFixVar //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint8 ucIcon;												// ͷ��
	uint32 ulCityId;											// ��������id
	uint32 ulCPosX;												// ��������id
	uint32 ulCPosY;												// ��������id
	uint32 ulCreateTime;										// ����ʱ��
	//tolua_end

	SFixVar():ucIcon(0),
		ulCityId(0),
		ulCPosX(0),
		ulCPosY(0),
		ulCreateTime(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT8(ucIcon, 1);
		D_UINT32(ulCityId, 1);
		D_UINT32(ulCPosX, 1);
		D_UINT32(ulCPosY, 1);
		D_UINT32(ulCreateTime, 1);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT8(ucIcon, 1);
		E_UINT32(ulCityId, 1);
		E_UINT32(ulCPosX, 1);
		E_UINT32(ulCPosY, 1);
		E_UINT32(ulCreateTime, 1);
		return iPos;
	}
};//tolua_export


/*
 *  ����ֵ
 */
struct SAttr //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint16 usAttr;												// ��������
	int32 ulVal;												// ����ֵ,��©
	uint8 ucUnit;												// ��������
	//tolua_end

	SAttr():usAttr(0),
		ulVal(0),
		ucUnit(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT16(usAttr, 1);
		D_INT32(ulVal, 1);
		D_UINT8(ucUnit, 1);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT16(usAttr, 1);
		E_INT32(ulVal, 1);
		E_UINT8(ucUnit, 1);
		return iPos;
	}
};//tolua_export


/*
 *  ����ֵ
 */
struct SAttrEx //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint16 attr;												// ��������
	uint32 val;													// ����ֵ
	uint8 unit;													// ��������
	//tolua_end

	SAttrEx():attr(0),
		val(0),
		unit(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT16(attr, 1);
		D_UINT32(val, 1);
		D_UINT8(unit, 1);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT16(attr, 1);
		E_UINT32(val, 1);
		E_UINT8(unit, 1);
		return iPos;
	}
};//tolua_export


/*
 *  ��������ֵ�б�
 */
struct SRoleAttrList //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint32 ulNSLastTime;										// ��ʿ���������ʱ��
	uint8 ucCount;												// ���Ը���
	SAttr astAttrs[MAX_ROLEATTRS_CNT];							// ����ֵ
	uint32 lastPSRefreshDay;									// �ϴ�ps����ˢ����һ���еĵڼ���
	//tolua_end

	SRoleAttrList():ulNSLastTime(0),
		ucCount(0),
		lastPSRefreshDay(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT32(ulNSLastTime, 1);
		D_UINT8(ucCount, 1);
		D_ARRAY_STRUCT(astAttrs, ucCount, MAX_ROLEATTRS_CNT, 1);
		D_UINT32(lastPSRefreshDay, 10);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT32(ulNSLastTime, 1);
		E_UINT8(ucCount, 1);
		E_ARRAY_STRUCT(astAttrs, ucCount, MAX_ROLEATTRS_CNT, 1);
		E_UINT32(lastPSRefreshDay, 10);
		return iPos;
	}
};//tolua_export


/*
 *  qq��Ա
 */
struct SQQMembership //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint8 is_yellow_vip;
	uint8 is_yellow_year_vip;
	uint8 yellow_vip_level;
	uint8 is_yellow_high_vip;
	uint8 is_blue_vip;
	uint8 is_blue_year_vip;
	uint8 blue_vip_level;
	uint8 is_super_blue_vip;
	uint8 _3366_grow_level;
	//tolua_end

	SQQMembership():is_yellow_vip(0),
		is_yellow_year_vip(0),
		yellow_vip_level(0),
		is_yellow_high_vip(0),
		is_blue_vip(0),
		is_blue_year_vip(0),
		blue_vip_level(0),
		is_super_blue_vip(0),
		_3366_grow_level(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT8(is_yellow_vip, 105);
		D_UINT8(is_yellow_year_vip, 105);
		D_UINT8(yellow_vip_level, 105);
		D_UINT8(is_yellow_high_vip, 105);
		D_UINT8(is_blue_vip, 105);
		D_UINT8(is_blue_year_vip, 105);
		D_UINT8(blue_vip_level, 105);
		D_UINT8(is_super_blue_vip, 105);
		D_UINT8(_3366_grow_level, 110);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT8(is_yellow_vip, 105);
		E_UINT8(is_yellow_year_vip, 105);
		E_UINT8(yellow_vip_level, 105);
		E_UINT8(is_yellow_high_vip, 105);
		E_UINT8(is_blue_vip, 105);
		E_UINT8(is_blue_year_vip, 105);
		E_UINT8(blue_vip_level, 105);
		E_UINT8(is_super_blue_vip, 105);
		E_UINT8(_3366_grow_level, 110);
		return iPos;
	}
};//tolua_export


/*
 *  ��ɫ�����л�������
 */
struct SBaseInfo //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint8 ucGM;													// GMȨ��
	uint8 ucLevel;												// ��ɫ�ȼ�
	uint32 ulPrestige;											// ����ֵ
	uint32 ulCityHonor;											// ������
	uint32 ulCityCD;											// ת�ݵ���ȴʱ��
	uint64 ullAlliance;											// ����id
	uint8 ucState;												// ����״̬
	SRoleAttrList stAttrs;										// ���������б�
	uint32 cityModel;											// ���ǳǳ����
	char introduction[MAX_ROLEINTRO_ARR_LEN];					// ����
	SQQMembership qqMembership;									// qq��Ա
	//tolua_end

	SBaseInfo():ucGM(0),
		ucLevel(0),
		ulPrestige(0),
		ulCityHonor(0),
		ulCityCD(0),
		ullAlliance(0),
		ucState(0),
		cityModel(0){
		introduction[0]=0;
	}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT8(ucGM, 1);
		D_UINT8(ucLevel, 1);
		D_UINT32(ulPrestige, 1);
		D_UINT32(ulCityHonor, 1);
		D_UINT32(ulCityCD, 1);
		D_UINT64(ullAlliance, 1);
		D_UINT8(ucState, 1);
		D_STRUCT(stAttrs, 1);
		D_UINT32(cityModel, 7);
		D_STRING(introduction, MAX_ROLEINTRO_ARR_LEN, 8);
		D_STRUCT(qqMembership, 105);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT8(ucGM, 1);
		E_UINT8(ucLevel, 1);
		E_UINT32(ulPrestige, 1);
		E_UINT32(ulCityHonor, 1);
		E_UINT32(ulCityCD, 1);
		E_UINT64(ullAlliance, 1);
		E_UINT8(ucState, 1);
		E_STRUCT(stAttrs, 1);
		E_UINT32(cityModel, 7);
		E_STRING(introduction, MAX_ROLEINTRO_ARR_LEN, 8);
		E_STRUCT(qqMembership, 105);
		return iPos;
	}
};//tolua_export


/*
 *  ��������ṹ
 */
struct STask //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint32 taskId;												// ����id
	uint8 state;												// ����״̬
	//tolua_end

	STask():taskId(0),
		state(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT32(taskId, 1);
		D_UINT8(state, 1);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT32(taskId, 1);
		E_UINT8(state, 1);
		return iPos;
	}
};//tolua_export


/*
 *  ���ڽ����еľ�������
 */
struct SDoingRoleTask //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint32 taskId;												// ���ڽ����еľ�������id
	uint32 stopTime;											// ����Ľ���ʱ��
	uint32 cdStopTime;											// ��ȴ�Ľ���ʱ��
	//tolua_end

	SDoingRoleTask():taskId(0),
		stopTime(0),
		cdStopTime(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT32(taskId, 20);
		D_UINT32(stopTime, 20);
		D_UINT32(cdStopTime, 20);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT32(taskId, 20);
		E_UINT32(stopTime, 20);
		E_UINT32(cdStopTime, 20);
		return iPos;
	}
};//tolua_export


/*
 *  ���ջ�Ծ������ṹ
 */
struct SActValTask //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint32 taskId;												// ����id
	uint32 times;												// ��ɵ��������
	//tolua_end

	SActValTask():taskId(0),
		times(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT32(taskId, 25);
		D_UINT32(times, 25);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT32(taskId, 25);
		E_UINT32(times, 25);
		return iPos;
	}
};//tolua_export


/*
 *  �����ṹ
 */
struct SActTask //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint32 taskId;												// ����id
	uint8 state;												// ����״̬
	uint32 times;												// ��ɵ��������
	uint32 maxTimes;											// ����������������
	uint32 startTime;											// ����Ŀ�ʼʱ��
	uint32 stopTime;											// ����Ľ���ʱ��
	//tolua_end

	SActTask():taskId(0),
		state(0),
		times(0),
		maxTimes(0),
		startTime(0),
		stopTime(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT32(taskId, 30);
		D_UINT8(state, 30);
		D_UINT32(times, 30);
		D_UINT32(maxTimes, 30);
		D_UINT32(startTime, 30);
		D_UINT32(stopTime, 30);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT32(taskId, 30);
		E_UINT8(state, 30);
		E_UINT32(times, 30);
		E_UINT32(maxTimes, 30);
		E_UINT32(startTime, 30);
		E_UINT32(stopTime, 30);
		return iPos;
	}
};//tolua_export


/*
 *  ��Ծ�Ƚṹ
 */
struct SActivityVal //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint32 refreshActValTime;									// �����Ծֵ��ˢ��ʱ��
	uint32 val;													// �������еĻ�Ծֵ
	uint32 gotActRewardTime;									// ����ȡ�Ļ�Ծ�Ƚ�����ˢ��ʱ��
	uint32 gotActRewards[MAX_ACTREWARDS_CNT];					// ����ȡ�Ļ�Ծ�Ƚ���
	uint32 refreshSigninTime;									// �����Ծֵ��ˢ��ʱ��
	uint8 todaySign;											// �����Ƿ���ǩ��
	uint32 signinDaysTime;										// ����ǩ��������ˢ��ʱ��
	uint8 signinDays;											// ����ǩ������
	uint32 gotSigninRewardTime;									// ����ȡ��ǩ��������ˢ��ʱ��
	uint32 gotSigninRewards[MAX_SIGNINREWARDS_CNT];				// ����ȡ��ǩ������
	uint32 refreshTaskTime;										// ˢ�������б��ʱ��
	int32 count;												// �����б���
	SActValTask tasks[MAX_ACTVALTASKS_CNT];						// �����б�����
	uint32 gotOnlineGoodsTime;									// ���һ�λ�ȡ���߽��������ʱ��
	uint32 gotGoodsTimes;										// ���һ�λ�ȡ���߽�������Ĵ���
	uint32 gotSigninRewardsEx[MAX_SIGNINREWARDS_CNT_EX];		// ����ȡ��ǩ������
	//tolua_end

	SActivityVal():refreshActValTime(0),
		val(0),
		gotActRewardTime(0),
		refreshSigninTime(0),
		todaySign(0),
		signinDaysTime(0),
		signinDays(0),
		gotSigninRewardTime(0),
		refreshTaskTime(0),
		count(0),
		gotOnlineGoodsTime(0),
		gotGoodsTimes(0){
		memset(gotActRewards, 0, sizeof(gotActRewards[0])*MAX_ACTREWARDS_CNT);
		memset(gotSigninRewards, 0, sizeof(gotSigninRewards[0])*MAX_SIGNINREWARDS_CNT);
		memset(gotSigninRewardsEx, 0, sizeof(gotSigninRewardsEx[0])*MAX_SIGNINREWARDS_CNT_EX);
	}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT32(refreshActValTime, 25);
		D_UINT32(val, 25);
		D_UINT32(gotActRewardTime, 25);
		D_ARRAY_UINT32(gotActRewards, MAX_ACTREWARDS_CNT, MAX_ACTREWARDS_CNT, 25);
		D_UINT32(refreshSigninTime, 25);
		D_UINT8(todaySign, 25);
		D_UINT32(signinDaysTime, 25);
		D_UINT8(signinDays, 25);
		D_UINT32(gotSigninRewardTime, 25);
		D_ARRAY_UINT32(gotSigninRewards, MAX_SIGNINREWARDS_CNT, MAX_SIGNINREWARDS_CNT, 25);
		D_UINT32(refreshTaskTime, 25);
		D_INT32(count, 25);
		D_ARRAY_STRUCT(tasks, count, MAX_ACTVALTASKS_CNT, 25);
		D_UINT32(gotOnlineGoodsTime, 102);
		D_UINT32(gotGoodsTimes, 102);
		D_ARRAY_UINT32(gotSigninRewardsEx, MAX_SIGNINREWARDS_CNT_EX, MAX_SIGNINREWARDS_CNT_EX, 125);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT32(refreshActValTime, 25);
		E_UINT32(val, 25);
		E_UINT32(gotActRewardTime, 25);
		E_ARRAY_UINT32(gotActRewards, MAX_ACTREWARDS_CNT, MAX_ACTREWARDS_CNT, 25);
		E_UINT32(refreshSigninTime, 25);
		E_UINT8(todaySign, 25);
		E_UINT32(signinDaysTime, 25);
		E_UINT8(signinDays, 25);
		E_UINT32(gotSigninRewardTime, 25);
		E_ARRAY_UINT32(gotSigninRewards, MAX_SIGNINREWARDS_CNT, MAX_SIGNINREWARDS_CNT, 25);
		E_UINT32(refreshTaskTime, 25);
		E_INT32(count, 25);
		E_ARRAY_STRUCT(tasks, count, MAX_ACTVALTASKS_CNT, 25);
		E_UINT32(gotOnlineGoodsTime, 102);
		E_UINT32(gotGoodsTimes, 102);
		E_ARRAY_UINT32(gotSigninRewardsEx, MAX_SIGNINREWARDS_CNT_EX, MAX_SIGNINREWARDS_CNT_EX, 125);
		return iPos;
	}
};//tolua_export


/*
 *  �����콱����
 */
struct SOnlineTask //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint32 taskId;												// ����id
	uint32 startTime;											// ������ʼ��ʱ��
	uint32 lastTime;											// �ϴ��Ѿ���¼��ʱ��
	uint32 lastLapsed;											// �ϴ��Ѿ���¼�����ŵ�ʱ��
	uint8 isCircled;											// �Ƿ��ѿ�ʼѭ������
	//tolua_end

	SOnlineTask():taskId(0),
		startTime(0),
		lastTime(0),
		lastLapsed(0),
		isCircled(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT32(taskId, 27);
		D_UINT32(startTime, 27);
		D_UINT32(lastTime, 27);
		D_UINT32(lastLapsed, 27);
		D_UINT8(isCircled, 27);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT32(taskId, 27);
		E_UINT32(startTime, 27);
		E_UINT32(lastTime, 27);
		E_UINT32(lastLapsed, 27);
		E_UINT8(isCircled, 27);
		return iPos;
	}
};//tolua_export


/*
 *  ����ָ������
 */
struct SNewcomerTask //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint32 curTaskId;											// ��ǰ����id
	uint8 isEnd;												// ����ָ�������Ƿ����
	uint8 isGlobalTipEnd;										// ����ָ�������������ʾȫ�ֹ������
	//tolua_end

	SNewcomerTask():curTaskId(0),
		isEnd(0),
		isGlobalTipEnd(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT32(curTaskId, 28);
		D_UINT8(isEnd, 123);
		D_UINT8(isGlobalTipEnd, 124);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT32(curTaskId, 28);
		E_UINT8(isEnd, 123);
		E_UINT8(isGlobalTipEnd, 124);
		return iPos;
	}
};//tolua_export


/*
 *  ��������
 */
struct SYellowDiamondTask //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	int8 gotNewgift;											// �����������ȡ
	uint32 gotCommGift;											// ����ÿ���������ȡʱ��
	uint32 gotYearGift;											// ��ѻ���ÿ���������ȡʱ��
	int32 lvlCount;												// ����ȼ��������ȡid�б�ĸ���
	int8 gotLvlGifts[MAX_YD_LVL_IDS_CNT];						// ����ȼ��������ȡid�б�
	//tolua_end

	SYellowDiamondTask():gotNewgift(0),
		gotCommGift(0),
		gotYearGift(0),
		lvlCount(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_INT8(gotNewgift, 104);
		D_UINT32(gotCommGift, 104);
		D_UINT32(gotYearGift, 104);
		D_INT32(lvlCount, 104);
		D_ARRAY_INT8(gotLvlGifts, lvlCount, MAX_YD_LVL_IDS_CNT, 104);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_INT8(gotNewgift, 104);
		E_UINT32(gotCommGift, 104);
		E_UINT32(gotYearGift, 104);
		E_INT32(lvlCount, 104);
		E_ARRAY_INT8(gotLvlGifts, lvlCount, MAX_YD_LVL_IDS_CNT, 104);
		return iPos;
	}
};//tolua_export


/*
 *  ��������
 */
struct SBlueDiamondTask //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	int8 gotNewgift;											// �����������ȡ
	uint32 gotCommGift;											// ����ÿ���������ȡʱ��
	uint32 gotYearGift;											// �������ÿ���������ȡʱ��
	uint32 gotHighGift;											// ��������ÿ���������ȡʱ��
	int32 lvlCount;												// ����ȼ��������ȡid�б�ĸ���
	int8 gotLvlGifts[MAX_BD_LVL_IDS_CNT];						// ����ȼ��������ȡid�б�
	uint32 got3366Gift;											// 3366ÿ���������ȡʱ��
	//tolua_end

	SBlueDiamondTask():gotNewgift(0),
		gotCommGift(0),
		gotYearGift(0),
		gotHighGift(0),
		lvlCount(0),
		got3366Gift(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_INT8(gotNewgift, 113);
		D_UINT32(gotCommGift, 113);
		D_UINT32(gotYearGift, 113);
		D_UINT32(gotHighGift, 113);
		D_INT32(lvlCount, 113);
		D_ARRAY_INT8(gotLvlGifts, lvlCount, MAX_BD_LVL_IDS_CNT, 113);
		D_UINT32(got3366Gift, 113);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_INT8(gotNewgift, 113);
		E_UINT32(gotCommGift, 113);
		E_UINT32(gotYearGift, 113);
		E_UINT32(gotHighGift, 113);
		E_INT32(lvlCount, 113);
		E_ARRAY_INT8(gotLvlGifts, lvlCount, MAX_BD_LVL_IDS_CNT, 113);
		E_UINT32(got3366Gift, 113);
		return iPos;
	}
};//tolua_export


/*
 *  ��ֵ�
 */
struct SPayAct //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint32 lastPayTime;											// ���һ�γ�ֵʱ��
	uint32 allGold;												// ���еĳ�ֵ��
	uint32 actAllGold;											// ���λ�ĳ�ֵ��
	uint8 giftGots[MAX_PAYACT_GIFT_CNT];						// �����ȡ���
	//tolua_end

	SPayAct():lastPayTime(0),
		allGold(0),
		actAllGold(0){
		memset(giftGots, 0, sizeof(giftGots[0])*MAX_PAYACT_GIFT_CNT);
	}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT32(lastPayTime, 108);
		D_UINT32(allGold, 108);
		D_UINT32(actAllGold, 108);
		D_ARRAY_UINT8(giftGots, MAX_PAYACT_GIFT_CNT, MAX_PAYACT_GIFT_CNT, 108);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT32(lastPayTime, 108);
		E_UINT32(allGold, 108);
		E_UINT32(actAllGold, 108);
		E_ARRAY_UINT8(giftGots, MAX_PAYACT_GIFT_CNT, MAX_PAYACT_GIFT_CNT, 108);
		return iPos;
	}
};//tolua_export


/*
 *  ����boss
 */
struct SWorldboss //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint8 times;												// ������ս����
	uint16 guwuLevel;											// ����ȼ�
	uint8 gotGift;												// ����Ľ����Ƿ���ȡ
	uint32 refreshTime;											// ˢ��ʱ��
	uint32 getPersonRankGiftTime;								// ��ȡ����������Ʒ��ʱ��
	uint32 getCountryRankGiftTime;								// ��ȡ����������Ʒ��ʱ��
	//tolua_end

	SWorldboss():times(0),
		guwuLevel(0),
		gotGift(0),
		refreshTime(0),
		getPersonRankGiftTime(0),
		getCountryRankGiftTime(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT8(times, 116);
		D_UINT16(guwuLevel, 116);
		D_UINT8(gotGift, 116);
		D_UINT32(refreshTime, 116);
		D_UINT32(getPersonRankGiftTime, 117);
		D_UINT32(getCountryRankGiftTime, 117);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT8(times, 116);
		E_UINT16(guwuLevel, 116);
		E_UINT8(gotGift, 116);
		E_UINT32(refreshTime, 116);
		E_UINT32(getPersonRankGiftTime, 117);
		E_UINT32(getCountryRankGiftTime, 117);
		return iPos;
	}
};//tolua_export


/*
 *  ���ͽ����Ļ
 */
struct SSendReward //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint8 sendFirstHero;										// �Ƿ��Ѿ��������׸��佫
	//tolua_end

	SSendReward():sendFirstHero(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT8(sendFirstHero, 122);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT8(sendFirstHero, 122);
		return iPos;
	}
};//tolua_export


/*
 *  �������������б�
 */
struct STaskList //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	int32 count;												// �����б���
	STask tasks[MAX_TASKS_CNT];									// �����б�����
	SDoingRoleTask doingRoleTask;								// ���ڽ����еľ�������
	uint32 refreshTime;											// �ճ������б�ˢ��
	int32 everydayCount;										// �ճ������б���
	STask everydayTasks[MAX_EVERYDAY_TASKS_CNT];				// �ճ������б�����
	uint32 prestigeLastTime;									// ������������һ��ʱ��
	SActivityVal activityVal;									// ��Ծ��
	SOnlineTask onlineTask;										// �����콱����
	SNewcomerTask newComerTask;									// ����ָ������
	int32 actTaskCount;											// ������б���
	SActTask actTasks[MAX_ACT_TASKS_CNT];						// ������б�����
	SYellowDiamondTask ydtasks;									// ��������
	SPayAct payAct;												// ��ֵ�
	SBlueDiamondTask bdtasks;									// ��������
	SWorldboss worldboss;										// ����boss
	SSendReward sendReward;										// ���ͽ����Ļ
	//tolua_end

	STaskList():count(0),
		refreshTime(0),
		everydayCount(0),
		prestigeLastTime(0),
		actTaskCount(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_INT32(count, 1);
		D_ARRAY_STRUCT(tasks, count, MAX_TASKS_CNT, 1);
		D_STRUCT(doingRoleTask, 20);
		D_UINT32(refreshTime, 21);
		D_INT32(everydayCount, 21);
		D_ARRAY_STRUCT(everydayTasks, everydayCount, MAX_EVERYDAY_TASKS_CNT, 21);
		D_UINT32(prestigeLastTime, 22);
		D_STRUCT(activityVal, 25);
		D_STRUCT(onlineTask, 27);
		D_STRUCT(newComerTask, 28);
		D_INT32(actTaskCount, 30);
		D_ARRAY_STRUCT(actTasks, actTaskCount, MAX_ACT_TASKS_CNT, 30);
		D_STRUCT(ydtasks, 104);
		D_STRUCT(payAct, 108);
		D_STRUCT(bdtasks, 113);
		D_STRUCT(worldboss, 116);
		D_STRUCT(sendReward, 122);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_INT32(count, 1);
		E_ARRAY_STRUCT(tasks, count, MAX_TASKS_CNT, 1);
		E_STRUCT(doingRoleTask, 20);
		E_UINT32(refreshTime, 21);
		E_INT32(everydayCount, 21);
		E_ARRAY_STRUCT(everydayTasks, everydayCount, MAX_EVERYDAY_TASKS_CNT, 21);
		E_UINT32(prestigeLastTime, 22);
		E_STRUCT(activityVal, 25);
		E_STRUCT(onlineTask, 27);
		E_STRUCT(newComerTask, 28);
		E_INT32(actTaskCount, 30);
		E_ARRAY_STRUCT(actTasks, actTaskCount, MAX_ACT_TASKS_CNT, 30);
		E_STRUCT(ydtasks, 104);
		E_STRUCT(payAct, 108);
		E_STRUCT(bdtasks, 113);
		E_STRUCT(worldboss, 116);
		E_STRUCT(sendReward, 122);
		return iPos;
	}
};//tolua_export


/*
 *  ����ʿ���ṹ
 */
struct SSoldier //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint32 resid;												// ʿ����ԴID*1000+level
	uint32 number;												// ʿ������
	//tolua_end

	SSoldier():resid(0),
		number(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT32(resid, 1);
		D_UINT32(number, 1);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT32(resid, 1);
		E_UINT32(number, 1);
		return iPos;
	}
};//tolua_export


/*
 *  ��ս�ṹ
 */
struct SDeclare //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint8 state;												// ״̬
	uint32 stoptime;											// ״̬������ʱ��
	uint64 id;													// Ŀ��id
	//tolua_end

	SDeclare():state(0),
		stoptime(0),
		id(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT8(state, 1);
		D_UINT32(stoptime, 1);
		D_UINT64(id, 1);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT8(state, 1);
		E_UINT32(stoptime, 1);
		E_UINT64(id, 1);
		return iPos;
	}
};//tolua_export


/*
 *  Ĭ��ս��
 */
struct SDefaultTeam //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint32 lineupId;											// ����id
	uint64 heroIds[MAX_DEFAULTTEAM_HERO_CNT];					// �б���Ӣ��id
	//tolua_end

	SDefaultTeam():lineupId(0){
		memset(heroIds, 0, sizeof(heroIds[0])*MAX_DEFAULTTEAM_HERO_CNT);
	}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT32(lineupId, 1);
		D_ARRAY_UINT64(heroIds, MAX_DEFAULTTEAM_HERO_CNT, MAX_DEFAULTTEAM_HERO_CNT, 1);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT32(lineupId, 1);
		E_ARRAY_UINT64(heroIds, MAX_DEFAULTTEAM_HERO_CNT, MAX_DEFAULTTEAM_HERO_CNT, 1);
		return iPos;
	}
};//tolua_export


/*
 *  ÿ��ս��
 */
struct STodayFightTimes //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint32 taofa;												// �ַ�����
	uint32 cuihui;												// �ݻٴ���
	uint32 tiaoxin;												// ���ƴ���
	uint32 fightowner;											// ����Ұ����������
	uint32 lastTime;											// �����һ��ʱ��
	//tolua_end

	STodayFightTimes():taofa(0),
		cuihui(0),
		tiaoxin(0),
		fightowner(0),
		lastTime(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT32(taofa, 1);
		D_UINT32(cuihui, 1);
		D_UINT32(tiaoxin, 1);
		D_UINT32(fightowner, 1);
		D_UINT32(lastTime, 1);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT32(taofa, 1);
		E_UINT32(cuihui, 1);
		E_UINT32(tiaoxin, 1);
		E_UINT32(fightowner, 1);
		E_UINT32(lastTime, 1);
		return iPos;
	}
};//tolua_export


/*
 *  �����м�Ӣ�۽ṹ
 */
struct SSimpleHero //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint64 id;													// Ӣ��id
	char name[MAX_HERONAME_ARR_LEN];							// Ӣ����
	uint8 level;												// Ӣ�۵ȼ�
	uint8 attrCount;											// ���Ը���
	SAttrEx attrs[MAX_SIMPLEHEROATTRS_CNT];						// ����ֵ
	SSoldier soldier;											// Я����ʿ��
	uint8 lineupPos;											// �����е�վλ
	//tolua_end

	SSimpleHero():id(0),
		level(0),
		attrCount(0),
		lineupPos(0){
		name[0]=0;
	}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT64(id, 1);
		D_STRING(name, MAX_HERONAME_ARR_LEN, 1);
		D_UINT8(level, 1);
		D_UINT8(attrCount, 1);
		D_ARRAY_STRUCT(attrs, attrCount, MAX_SIMPLEHEROATTRS_CNT, 1);
		D_STRUCT(soldier, 1);
		D_UINT8(lineupPos, 1);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT64(id, 1);
		E_STRING(name, MAX_HERONAME_ARR_LEN, 1);
		E_UINT8(level, 1);
		E_UINT8(attrCount, 1);
		E_ARRAY_STRUCT(attrs, attrCount, MAX_SIMPLEHEROATTRS_CNT, 1);
		E_STRUCT(soldier, 1);
		E_UINT8(lineupPos, 1);
		return iPos;
	}
};//tolua_export


/*
 *  ���ؾ���
 */
struct SDefArmy //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint32 lineupId;											// ����id
	uint8 heroCount;											// Ӣ�۸���
	uint64 heros[MAX_TEAM_HERO_CNT];							// Ӣ���б�
	//tolua_end

	SDefArmy():lineupId(0),
		heroCount(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT32(lineupId, 1);
		D_UINT8(heroCount, 1);
		D_ARRAY_UINT64(heros, heroCount, MAX_TEAM_HERO_CNT, 1);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT32(lineupId, 1);
		E_UINT8(heroCount, 1);
		E_ARRAY_UINT64(heros, heroCount, MAX_TEAM_HERO_CNT, 1);
		return iPos;
	}
};//tolua_export


/*
 *  ��������
 */
struct STowerArmy //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	SSoldier soldiers[MAX_TEAM_HERO_CNT];						// ÿ�������е�ʿ��
	//tolua_end

	STowerArmy(){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_ARRAY_STRUCT(soldiers, MAX_TEAM_HERO_CNT, MAX_TEAM_HERO_CNT, 1);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_ARRAY_STRUCT(soldiers, MAX_TEAM_HERO_CNT, MAX_TEAM_HERO_CNT, 1);
		return iPos;
	}
};//tolua_export


/*
 *  ����Ĺ�ս����
 */
struct SFightTodayHonor //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint32 hasRefreshTime;										// �ɹ��׵ı��˴����ˢ��ʱ��
	uint32 hasHonor;											// ���컹ʣ�������
	uint32 getRefreshTime;										// ��õ�ˢ��ʱ��
	uint32 getHonor;											// �����ѻ������
	//tolua_end

	SFightTodayHonor():hasRefreshTime(0),
		hasHonor(0),
		getRefreshTime(0),
		getHonor(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT32(hasRefreshTime, 118);
		D_UINT32(hasHonor, 118);
		D_UINT32(getRefreshTime, 118);
		D_UINT32(getHonor, 118);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT32(hasRefreshTime, 118);
		E_UINT32(hasHonor, 118);
		E_UINT32(getRefreshTime, 118);
		E_UINT32(getHonor, 118);
		return iPos;
	}
};//tolua_export


/*
 *  ���½ṹ
 */
struct SMilitary //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint8 favoriteCount;										// �ղ�Ŀ�����
	uint64 favorites[MAX_FAVORITE_CNT];							// �ղ�Ŀ���б�
	uint8 enemyCount;											// ���˸���
	uint64 enemys[MAX_ENEMY_CNT];								// �����б�
	uint8 lineupCount;											// ���͸���
	uint32 lineups[MAX_LINEUP_CNT];								// ����Ŀ���б�
	SDefaultTeam defaultTeams[MAX_DEFAULTTEAM_CNT];				// Ĭ��ս���б�
	STodayFightTimes todayFightTimes;							// ÿ��ս��
	uint8 selfArmyCount;										// �ҵĳ������Ӹ���
	uint64 selfArmyIds[MAX_SELFARMY_CNT];						// �ҵĳ��������б�
	uint8 enemyArmyCount;										// �����ҷ����˾��Ӹ���
	uint64 enemyArmyIds[MAX_ENEMYARMY_CNT];						// �����ҷ����˾����б�
	uint8 alliArmyCount;										// ͬ����ǲ���Ӹ���
	uint64 alliArmyIds[MAX_ALLIARMY_CNT];						// ͬ����ǲ�����б�
	SDefArmy defArmy;											// ���ؾ���
	STowerArmy towerArmy;										// ��������
	uint8 succCopyFieldCount;									// ��ս�ɹ��ĸ�������
	uint32 succCopyFields[MAX_SUCC_COPYFIELD_CNT];				// ��ս�ɹ��ĸ���id�б�
	SFightTodayHonor todayHonor;								// ����Ĺ�ս����
	//tolua_end

	SMilitary():favoriteCount(0),
		enemyCount(0),
		lineupCount(0),
		selfArmyCount(0),
		enemyArmyCount(0),
		alliArmyCount(0),
		succCopyFieldCount(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT8(favoriteCount, 1);
		D_ARRAY_UINT64(favorites, favoriteCount, MAX_FAVORITE_CNT, 1);
		D_UINT8(enemyCount, 1);
		D_ARRAY_UINT64(enemys, enemyCount, MAX_ENEMY_CNT, 1);
		D_UINT8(lineupCount, 1);
		D_ARRAY_UINT32(lineups, lineupCount, MAX_LINEUP_CNT, 1);
		D_ARRAY_STRUCT(defaultTeams, MAX_DEFAULTTEAM_CNT, MAX_DEFAULTTEAM_CNT, 1);
		D_STRUCT(todayFightTimes, 1);
		D_UINT8(selfArmyCount, 1);
		D_ARRAY_UINT64(selfArmyIds, selfArmyCount, MAX_SELFARMY_CNT, 1);
		D_UINT8(enemyArmyCount, 1);
		D_ARRAY_UINT64(enemyArmyIds, enemyArmyCount, MAX_ENEMYARMY_CNT, 1);
		D_UINT8(alliArmyCount, 1);
		D_ARRAY_UINT64(alliArmyIds, alliArmyCount, MAX_ALLIARMY_CNT, 1);
		D_STRUCT(defArmy, 1);
		D_STRUCT(towerArmy, 1);
		D_UINT8(succCopyFieldCount, 2);
		D_ARRAY_UINT32(succCopyFields, succCopyFieldCount, MAX_SUCC_COPYFIELD_CNT, 2);
		D_STRUCT(todayHonor, 118);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT8(favoriteCount, 1);
		E_ARRAY_UINT64(favorites, favoriteCount, MAX_FAVORITE_CNT, 1);
		E_UINT8(enemyCount, 1);
		E_ARRAY_UINT64(enemys, enemyCount, MAX_ENEMY_CNT, 1);
		E_UINT8(lineupCount, 1);
		E_ARRAY_UINT32(lineups, lineupCount, MAX_LINEUP_CNT, 1);
		E_ARRAY_STRUCT(defaultTeams, MAX_DEFAULTTEAM_CNT, MAX_DEFAULTTEAM_CNT, 1);
		E_STRUCT(todayFightTimes, 1);
		E_UINT8(selfArmyCount, 1);
		E_ARRAY_UINT64(selfArmyIds, selfArmyCount, MAX_SELFARMY_CNT, 1);
		E_UINT8(enemyArmyCount, 1);
		E_ARRAY_UINT64(enemyArmyIds, enemyArmyCount, MAX_ENEMYARMY_CNT, 1);
		E_UINT8(alliArmyCount, 1);
		E_ARRAY_UINT64(alliArmyIds, alliArmyCount, MAX_ALLIARMY_CNT, 1);
		E_STRUCT(defArmy, 1);
		E_STRUCT(towerArmy, 1);
		E_UINT8(succCopyFieldCount, 2);
		E_ARRAY_UINT32(succCopyFields, succCopyFieldCount, MAX_SUCC_COPYFIELD_CNT, 2);
		E_STRUCT(todayHonor, 118);
		return iPos;
	}
};//tolua_export


/*
 *  ����ṹ
 */
struct SInviteJoinAlliance //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint64 allianceId;											// ����id
	uint64 roleId;												// ������id
	//tolua_end

	SInviteJoinAlliance():allianceId(0),
		roleId(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT64(allianceId, 15);
		D_UINT64(roleId, 15);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT64(allianceId, 15);
		E_UINT64(roleId, 15);
		return iPos;
	}
};//tolua_export


/*
 *  ���̽ṹ
 */
struct STradingArea //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint32 stopTime;											// ����ֹͣʱ��
	int32 count;												// Ŀ�����
	uint64 roleIds[MAX_TRADING_ROLES_CNT];						// Ŀ���ɫid�б�
	int32 todayTimes;											// �������ܵĴ���
	uint32 refreshTime;											// ˢ��ʱ��
	uint16 curTimes;											// ��ǰ���̵Ĵ���
	//tolua_end

	STradingArea():stopTime(0),
		count(0),
		todayTimes(0),
		refreshTime(0),
		curTimes(1){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT32(stopTime, 16);
		D_INT32(count, 16);
		D_ARRAY_UINT64(roleIds, count, MAX_TRADING_ROLES_CNT, 16);
		D_INT32(todayTimes, 24);
		D_UINT32(refreshTime, 24);
		D_UINT16(curTimes, 112);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT32(stopTime, 16);
		E_INT32(count, 16);
		E_ARRAY_UINT64(roleIds, count, MAX_TRADING_ROLES_CNT, 16);
		E_INT32(todayTimes, 24);
		E_UINT32(refreshTime, 24);
		E_UINT16(curTimes, 112);
		return iPos;
	}
};//tolua_export


/*
 *  ǧ����
 */
struct SActTower //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint32 todayEnterTimes;										// �������Ĵ���
	uint32 todayRefreshTime;									// ���������ˢ��ʱ��
	uint32 maxLayer;											// ��ǰ��Ҵ�������߲�
	uint32 leftLifes;											// ��ǰ�ؿ�ʣ�������
	uint32 stopTime;											// ս����ȴ�Ľ���ʱ��
	uint32 curLayer;											// ��ǰ���ڹ����¥��
	uint32 maxTime;												// ͨ��������ʱ��ʱ��
	uint32 autoStartTime;										// �Զ���ս�Ŀ�ʼʱ��
	uint16 autoToLayer;											// �Զ���ս�����޲���
	//tolua_end

	SActTower():todayEnterTimes(0),
		todayRefreshTime(0),
		maxLayer(0),
		leftLifes(0),
		stopTime(0),
		curLayer(0),
		maxTime(0),
		autoStartTime(0),
		autoToLayer(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT32(todayEnterTimes, 18);
		D_UINT32(todayRefreshTime, 18);
		D_UINT32(maxLayer, 18);
		D_UINT32(leftLifes, 18);
		D_UINT32(stopTime, 18);
		D_UINT32(curLayer, 18);
		D_UINT32(maxTime, 19);
		D_UINT32(autoStartTime, 120);
		D_UINT16(autoToLayer, 121);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT32(todayEnterTimes, 18);
		E_UINT32(todayRefreshTime, 18);
		E_UINT32(maxLayer, 18);
		E_UINT32(leftLifes, 18);
		E_UINT32(stopTime, 18);
		E_UINT32(curLayer, 18);
		E_UINT32(maxTime, 19);
		E_UINT32(autoStartTime, 120);
		E_UINT16(autoToLayer, 121);
		return iPos;
	}
};//tolua_export


/*
 *  �㽫̨�ؿ�
 */
struct SActTerraceGate //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint32 gateId;												// �ؿ�id
	uint32 subGateId;											// �ӹؿ�id
	//tolua_end

	SActTerraceGate():gateId(0),
		subGateId(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT32(gateId, 18);
		D_UINT32(subGateId, 18);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT32(gateId, 18);
		E_UINT32(subGateId, 18);
		return iPos;
	}
};//tolua_export


/*
 *  �㽫̨
 */
struct SActTerrace //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint32 todayEnterTimes;										// �������Ĵ���
	uint32 todayRefreshTime;									// ���������ˢ��ʱ��
	SActTerraceGate maxGate;									// ��ǰ��Ҵ�������߹ؿ�
	uint32 leftLifes;											// ��ǰ�ؿ�ʣ�������
	uint32 stopTime;											// ս����ȴ�Ľ���ʱ��
	SActTerraceGate curGate;									// ��ǰ���ڹ���Ĺؿ�
	int32 countResults;											// ͨ���˵Ĺؿ��������б��С
	uint8 results[MAX_ACT_TERRACE_COUNT];						// �����б�
	uint32 autoStartTime;										// �Զ���ս�Ŀ�ʼʱ��
	uint16 autoToSubGateId;										// �Զ���ս�������ӹ�
	//tolua_end

	SActTerrace():todayEnterTimes(0),
		todayRefreshTime(0),
		leftLifes(0),
		stopTime(0),
		countResults(0),
		autoStartTime(0),
		autoToSubGateId(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT32(todayEnterTimes, 18);
		D_UINT32(todayRefreshTime, 18);
		D_STRUCT(maxGate, 18);
		D_UINT32(leftLifes, 18);
		D_UINT32(stopTime, 18);
		D_STRUCT(curGate, 18);
		D_INT32(countResults, 18);
		D_ARRAY_UINT8(results, countResults, MAX_ACT_TERRACE_COUNT, 18);
		D_UINT32(autoStartTime, 120);
		D_UINT16(autoToSubGateId, 121);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT32(todayEnterTimes, 18);
		E_UINT32(todayRefreshTime, 18);
		E_STRUCT(maxGate, 18);
		E_UINT32(leftLifes, 18);
		E_UINT32(stopTime, 18);
		E_STRUCT(curGate, 18);
		E_INT32(countResults, 18);
		E_ARRAY_UINT8(results, countResults, MAX_ACT_TERRACE_COUNT, 18);
		E_UINT32(autoStartTime, 120);
		E_UINT16(autoToSubGateId, 121);
		return iPos;
	}
};//tolua_export


/*
 *  �佫�������ͱ���ṹ
 */
struct SForceLineupCfg //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint32 type;												// ����
	uint32 lineup;												// ����
	int8 heroCount;												// �佫����
	uint64 heroIds[MAX_TEAM_HERO_CNT];							// �佫id�б�
	//tolua_end

	SForceLineupCfg():type(0),
		lineup(0),
		heroCount(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT32(type, 29);
		D_UINT32(lineup, 29);
		D_INT8(heroCount, 29);
		D_ARRAY_UINT64(heroIds, heroCount, MAX_TEAM_HERO_CNT, 29);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT32(type, 29);
		E_UINT32(lineup, 29);
		E_INT8(heroCount, 29);
		E_ARRAY_UINT64(heroIds, heroCount, MAX_TEAM_HERO_CNT, 29);
		return iPos;
	}
};//tolua_export


/*
 *  ���ְ�����ʾ
 */
struct SHelpTip //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint32 id;													// id
	uint8 times;												// �Ѿ���ʾ�Ĵ���
	//tolua_end

	SHelpTip():id(0),
		times(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT32(id, 127);
		D_UINT8(times, 127);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT32(id, 127);
		E_UINT8(times, 127);
		return iPos;
	}
};//tolua_export


/*
 *  ��ҿͻ��˵�����
 */
struct SPlayerClientCfg //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	int8 forceCount;											// �佫���ָ���
	SForceLineupCfg forces[MAX_FORCELINEUPCFG_CNT];				// �佫����
	uint8 toggleMap[MAX_CTLCFG_BTIMAP_CNT];						// �ͻ��˵�һЩ����bitλ
	int32 gonggaoVer;											// ���һ����ҿ����Ĺ���汾��
	int16 helpTipCount;											// ���ְ���tip�ĸ���
	SHelpTip helpTips[MAX_HELPTIP_CNT];							// ���ְ���tipid���б�
	//tolua_end

	SPlayerClientCfg():forceCount(0),
		gonggaoVer(0),
		helpTipCount(0){
		memset(toggleMap, 0, sizeof(toggleMap[0])*MAX_CTLCFG_BTIMAP_CNT);
	}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_INT8(forceCount, 29);
		D_ARRAY_STRUCT(forces, forceCount, MAX_FORCELINEUPCFG_CNT, 29);
		D_ARRAY_UINT8(toggleMap, MAX_CTLCFG_BTIMAP_CNT, MAX_CTLCFG_BTIMAP_CNT, 107);
		D_INT32(gonggaoVer, 119);
		D_INT16(helpTipCount, 127);
		D_ARRAY_STRUCT(helpTips, helpTipCount, MAX_HELPTIP_CNT, 127);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_INT8(forceCount, 29);
		E_ARRAY_STRUCT(forces, forceCount, MAX_FORCELINEUPCFG_CNT, 29);
		E_ARRAY_UINT8(toggleMap, MAX_CTLCFG_BTIMAP_CNT, MAX_CTLCFG_BTIMAP_CNT, 107);
		E_INT32(gonggaoVer, 119);
		E_INT16(helpTipCount, 127);
		E_ARRAY_STRUCT(helpTips, helpTipCount, MAX_HELPTIP_CNT, 127);
		return iPos;
	}
};//tolua_export


/*
 *  �������޵ĵ���
 */
struct SBuyLimitItem //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint32 resId;												// ����id
	uint32 number;												// ����
	//tolua_end

	SBuyLimitItem():resId(0),
		number(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT32(resId, 106);
		D_UINT32(number, 106);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT32(resId, 106);
		E_UINT32(number, 106);
		return iPos;
	}
};//tolua_export


/*
 *  vip����
 */
struct SVip //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint8 level;												// �ȼ�
	//tolua_end

	SVip():level(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT8(level, 110);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT8(level, 110);
		return iPos;
	}
};//tolua_export


/*
 *  cd key
 */
struct SCDKey //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	int32 count;												// �������cdkey
	int16 types[MAX_CDKEY_CNT];									// �Ѿ������type
	//tolua_end

	SCDKey():count(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_INT32(count, 115);
		D_ARRAY_INT16(types, count, MAX_CDKEY_CNT, 115);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_INT32(count, 115);
		E_ARRAY_INT16(types, count, MAX_CDKEY_CNT, 115);
		return iPos;
	}
};//tolua_export


/*
 *  ����ṹ
 */
struct SMiscs //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	SPlayerClientCfg clientCfg;									// ��ҿͻ��˵�����
	char applyAlliance[MAX_ALLINAME_ARR_LEN];					// ���������������
	uint8 inviteJoinAllianceCount;								// �����Ҽ������˵ĸ���
	SInviteJoinAlliance inviteJoinAlliances[MAX_INVITE_JOIN_ALLI_CNT];	// �����Ҽ������˵��б�
	STradingArea trading;										// ���̽ṹ
	SActTower actTower;											// ǧ����
	SActTerrace actTerrace;										// �㽫̨
	uint32 buyLimitTime;										// �������޵��ߵ�ʱ��
	int32 buyLimitCount;										// �������޵��ߵĸ���
	SBuyLimitItem buyLimitItems[MAX_BUY_ITEMS_CNT];				// �������޵ĵ���
	SVip vip;													// vip����
	SCDKey cdkey;												// cd key
	//tolua_end

	SMiscs():inviteJoinAllianceCount(0),
		buyLimitTime(0),
		buyLimitCount(0){
		applyAlliance[0]=0;
	}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_STRUCT(clientCfg, 29);
		D_STRING(applyAlliance, MAX_ALLINAME_ARR_LEN, 15);
		D_UINT8(inviteJoinAllianceCount, 15);
		D_ARRAY_STRUCT(inviteJoinAlliances, inviteJoinAllianceCount, MAX_INVITE_JOIN_ALLI_CNT, 15);
		D_STRUCT(trading, 16);
		D_STRUCT(actTower, 18);
		D_STRUCT(actTerrace, 18);
		D_UINT32(buyLimitTime, 106);
		D_INT32(buyLimitCount, 106);
		D_ARRAY_STRUCT(buyLimitItems, buyLimitCount, MAX_BUY_ITEMS_CNT, 106);
		D_STRUCT(vip, 110);
		D_STRUCT(cdkey, 115);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_STRUCT(clientCfg, 29);
		E_STRING(applyAlliance, MAX_ALLINAME_ARR_LEN, 15);
		E_UINT8(inviteJoinAllianceCount, 15);
		E_ARRAY_STRUCT(inviteJoinAlliances, inviteJoinAllianceCount, MAX_INVITE_JOIN_ALLI_CNT, 15);
		E_STRUCT(trading, 16);
		E_STRUCT(actTower, 18);
		E_STRUCT(actTerrace, 18);
		E_UINT32(buyLimitTime, 106);
		E_INT32(buyLimitCount, 106);
		E_ARRAY_STRUCT(buyLimitItems, buyLimitCount, MAX_BUY_ITEMS_CNT, 106);
		E_STRUCT(vip, 110);
		E_STRUCT(cdkey, 115);
		return iPos;
	}
};//tolua_export


/*
 *  ����ʿ���б�ṹ
 */
struct SSoldierList //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint8 count;												// ʿ�����͸���
	SSoldier soldiers[MAX_SLDS_CNT];							// ʿ�����;�������
	//tolua_end

	SSoldierList():count(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT8(count, 1);
		D_ARRAY_STRUCT(soldiers, count, MAX_SLDS_CNT, 1);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT8(count, 1);
		E_ARRAY_STRUCT(soldiers, count, MAX_SLDS_CNT, 1);
		return iPos;
	}
};//tolua_export


/*
 *  ����Ӣ��Я��ʿ���ṹ
 */
struct SCarrySoldier //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint32 ulResId;												// ʿ����ԴID
	uint32 ulNumber;											// ʿ������
	//tolua_end

	SCarrySoldier():ulResId(0),
		ulNumber(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT32(ulResId, 1);
		D_UINT32(ulNumber, 1);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT32(ulResId, 1);
		E_UINT32(ulNumber, 1);
		return iPos;
	}
};//tolua_export


/*
 *  ����Ӣ��Я��ʿ���б�ṹ
 */
struct SCarrySoldierList //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint8 ucCount;												// ʿ�����͸���
	SCarrySoldier astSoldiers[MAX_SLDS_CNT];					// ʿ�����;�������
	//tolua_end

	SCarrySoldierList():ucCount(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT8(ucCount, 1);
		D_ARRAY_STRUCT(astSoldiers, ucCount, MAX_SLDS_CNT, 1);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT8(ucCount, 1);
		E_ARRAY_STRUCT(astSoldiers, ucCount, MAX_SLDS_CNT, 1);
		return iPos;
	}
};//tolua_export


/*
 *  Ӣ������ֵ�б�
 */
struct SHeroAttrList //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint8 ucCount;												// ���Ը���
	SAttr astAttrs[MAX_HEROATTRS_CNT];							// ����ֵ
	//tolua_end

	SHeroAttrList():ucCount(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT8(ucCount, 1);
		D_ARRAY_STRUCT(astAttrs, ucCount, MAX_HEROATTRS_CNT, 1);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT8(ucCount, 1);
		E_ARRAY_STRUCT(astAttrs, ucCount, MAX_HEROATTRS_CNT, 1);
		return iPos;
	}
};//tolua_export


/*
 *  ��������ֵ�б�
 */
struct SItemAttrList //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint8 ucCount;												// ���Ը���
	SAttr astAttrs[MAX_ITEM_ATTRS_CNT];							// ����ֵ
	//tolua_end

	SItemAttrList():ucCount(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT8(ucCount, 1);
		D_ARRAY_STRUCT(astAttrs, ucCount, MAX_ITEM_ATTRS_CNT, 1);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT8(ucCount, 1);
		E_ARRAY_STRUCT(astAttrs, ucCount, MAX_ITEM_ATTRS_CNT, 1);
		return iPos;
	}
};//tolua_export


/*
 *  ��Ƕ��ʯ�б�
 */
struct SGemBesetList //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint8 ucCount;												// ��ʯ����
	uint32 aulGems[MAX_GEMBESET_CNT];							// ��ʯresid�б�
	//tolua_end

	SGemBesetList():ucCount(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT8(ucCount, 3);
		D_ARRAY_UINT32(aulGems, ucCount, MAX_GEMBESET_CNT, 3);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT8(ucCount, 3);
		E_ARRAY_UINT32(aulGems, ucCount, MAX_GEMBESET_CNT, 3);
		return iPos;
	}
};//tolua_export


/*
 *  ���ߣ�������ͨ��Ʒ��װ������ʯ�ȣ�
 */
struct SItem //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint64 ullId;												// ����ID
	uint8 ucType;												// ��������
	uint32 ulResId;												// ������ԴID
	uint16 usNumber;											// ���߶ѵ�����
	uint8 ucForceLevel;											// ǿ���ȼ�
	SItemAttrList stAttrs;										// �����б�
	SGemBesetList stGems;										// ��ʯ�б�
	//tolua_end

	SItem():ullId(0),
		ucType(0),
		ulResId(0),
		usNumber(0),
		ucForceLevel(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT64(ullId, 1);
		D_UINT8(ucType, 1);
		D_UINT32(ulResId, 1);
		D_UINT16(usNumber, 1);
		D_UINT8(ucForceLevel, 3);
		D_STRUCT(stAttrs, 1);
		D_STRUCT(stGems, 3);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT64(ullId, 1);
		E_UINT8(ucType, 1);
		E_UINT32(ulResId, 1);
		E_UINT16(usNumber, 1);
		E_UINT8(ucForceLevel, 3);
		E_STRUCT(stAttrs, 1);
		E_STRUCT(stGems, 3);
		return iPos;
	}
};//tolua_export


/*
 *  ��������ֵ�б�
 */
struct SItemAttrListEx //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint8 count;												// ���Ը���
	SAttrEx attrs[MAX_ITEM_ATTRS_CNT];							// ����ֵ
	//tolua_end

	SItemAttrListEx():count(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT8(count, 1);
		D_ARRAY_STRUCT(attrs, count, MAX_ITEM_ATTRS_CNT, 1);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT8(count, 1);
		E_ARRAY_STRUCT(attrs, count, MAX_ITEM_ATTRS_CNT, 1);
		return iPos;
	}
};//tolua_export


/*
 *  ��Ƕ��ʯ�б�
 */
struct SGemBesetListEx //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint8 count;												// ��ʯ����
	uint32 gems[MAX_GEMBESET_CNT];								// ��ʯresid�б�
	//tolua_end

	SGemBesetListEx():count(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT8(count, 3);
		D_ARRAY_UINT32(gems, count, MAX_GEMBESET_CNT, 3);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT8(count, 3);
		E_ARRAY_UINT32(gems, count, MAX_GEMBESET_CNT, 3);
		return iPos;
	}
};//tolua_export


/*
 *  ���ߣ�������ͨ��Ʒ��װ������ʯ�ȣ�
 */
struct SItemEx //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint64 id;													// ����ID
	uint8 type;													// ��������
	uint8 isRaw;												// �����Ƿ��ѱ�����
	uint8 isBind;												// �����Ƿ��Ѱ�
	uint32 resId;												// ������ԴID
	uint16 number;												// ���߶ѵ�����
	uint8 forceLevel;											// ǿ���ȼ�
	SItemAttrListEx attrs;										// �����б�
	SGemBesetListEx gems;										// ��ʯ�б�
	//tolua_end

	SItemEx():id(0),
		type(0),
		isRaw(0),
		isBind(0),
		resId(0),
		number(0),
		forceLevel(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT64(id, 1);
		D_UINT8(type, 1);
		D_UINT8(isRaw, 5);
		D_UINT8(isBind, 6);
		D_UINT32(resId, 1);
		D_UINT16(number, 1);
		D_UINT8(forceLevel, 3);
		D_STRUCT(attrs, 1);
		D_STRUCT(gems, 3);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT64(id, 1);
		E_UINT8(type, 1);
		E_UINT8(isRaw, 5);
		E_UINT8(isBind, 6);
		E_UINT32(resId, 1);
		E_UINT16(number, 1);
		E_UINT8(forceLevel, 3);
		E_STRUCT(attrs, 1);
		E_STRUCT(gems, 3);
		return iPos;
	}
};//tolua_export


/*
 *  ����װ��
 */
struct SWear //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint8 armPos;												// װ��λ��
	SItemEx arm;												// װ��
	//tolua_end

	SWear():armPos(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT8(armPos, 1);
		D_STRUCT(arm, 1);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT8(armPos, 1);
		E_STRUCT(arm, 1);
		return iPos;
	}
};//tolua_export


/*
 *  ����װ���б�
 */
struct SWearList //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint8 count;												// װ������
	SWear wears[MAX_HEROWEAR_CNT];								// װ��
	//tolua_end

	SWearList():count(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT8(count, 1);
		D_ARRAY_STRUCT(wears, count, MAX_HEROWEAR_CNT, 1);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT8(count, 1);
		E_ARRAY_STRUCT(wears, count, MAX_HEROWEAR_CNT, 1);
		return iPos;
	}
};//tolua_export


/*
 *  �����б�ṹ
 */
struct SItemListEx //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint16 count;												// ���߸�����
	SItemEx items[MAX_ITEMS_CNT];								// �����б�ľ�������
	//tolua_end

	SItemListEx():count(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT16(count, 4);
		D_ARRAY_STRUCT(items, count, MAX_ITEMS_CNT, 4);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT16(count, 4);
		E_ARRAY_STRUCT(items, count, MAX_ITEMS_CNT, 4);
		return iPos;
	}
};//tolua_export


/*
 *  ��ɫ�������еĵ���
 */
struct SAllItems //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint32 ulGiftGold;											// ����
	uint32 ulGold;												// ���
	uint16 usGridMaxCnt;										// ���������
	SItemListEx stItems;										// �����е���Ʒ
	uint32 lastSalveTime;										// ���һ��ˢ��ҩ���ʱ��
	//tolua_end

	SAllItems():ulGiftGold(0),
		ulGold(0),
		usGridMaxCnt(0),
		lastSalveTime(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT32(ulGiftGold, 1);
		D_UINT32(ulGold, 1);
		D_UINT16(usGridMaxCnt, 1);
		D_STRUCT(stItems, 4);
		D_UINT32(lastSalveTime, 14);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT32(ulGiftGold, 1);
		E_UINT32(ulGold, 1);
		E_UINT16(usGridMaxCnt, 1);
		E_STRUCT(stItems, 4);
		E_UINT32(lastSalveTime, 14);
		return iPos;
	}
};//tolua_export


/*
 *  ����
 */
struct SSkill //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint32 ulResId;												// ������ԴID
	uint8 ucLevel;												// ���ܵȼ�
	uint32 ulDex;												// ��ǰ��������
	//tolua_end

	SSkill():ulResId(0),
		ucLevel(0),
		ulDex(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT32(ulResId, 1);
		D_UINT8(ucLevel, 1);
		D_UINT32(ulDex, 1);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT32(ulResId, 1);
		E_UINT8(ucLevel, 1);
		E_UINT32(ulDex, 1);
		return iPos;
	}
};//tolua_export


/*
 *  �����б�
 */
struct SSkillList //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint8 ucCount;												// ���ܸ���
	SSkill astSkills[MAX_HERO_SKILL_CNT];						// ����
	//tolua_end

	SSkillList():ucCount(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT8(ucCount, 1);
		D_ARRAY_STRUCT(astSkills, ucCount, MAX_HERO_SKILL_CNT, 1);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT8(ucCount, 1);
		E_ARRAY_STRUCT(astSkills, ucCount, MAX_HERO_SKILL_CNT, 1);
		return iPos;
	}
};//tolua_export


/*
 *  ���߿��
 */
struct SSCut //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint8 ucCutPos;												// ���߿��λ��
	uint32 ulResId;												// �����ĵ�����Դid
	//tolua_end

	SSCut():ucCutPos(0),
		ulResId(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT8(ucCutPos, 1);
		D_UINT32(ulResId, 1);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT8(ucCutPos, 1);
		E_UINT32(ulResId, 1);
		return iPos;
	}
};//tolua_export


/*
 *  ���߿���б�
 */
struct SSCutList //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint8 ucCount;												// ��ݸ���
	SSCut astSCuts[MAX_HERO_SCUT_CNT];							// ���
	//tolua_end

	SSCutList():ucCount(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT8(ucCount, 1);
		D_ARRAY_STRUCT(astSCuts, ucCount, MAX_HERO_SCUT_CNT, 1);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT8(ucCount, 1);
		E_ARRAY_STRUCT(astSCuts, ucCount, MAX_HERO_SCUT_CNT, 1);
		return iPos;
	}
};//tolua_export


/*
 *  Ӣ�������ṹ
 */
struct OSHeroSteel //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint8 ucSteelType;											// ��������
	uint32 ulStartTime;											// ��ʼ����ʱ�䣨��λ�룩
	uint32 ulLastTime;											// ���һ�μ�����µ�����ʱ�䣨��λ�룩
	uint8 ucHours;												// ������Сʱ��
	uint64 ullExp;												// �Ѿ���õľ���
	uint32 ulTakeGold;											// �Ѿ���õľ���
	//tolua_end

	OSHeroSteel():ucSteelType(0),
		ulStartTime(0),
		ulLastTime(0),
		ucHours(0),
		ullExp(0),
		ulTakeGold(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT8(ucSteelType, 1);
		D_UINT32(ulStartTime, 1);
		D_UINT32(ulLastTime, 1);
		D_UINT8(ucHours, 1);
		D_UINT64(ullExp, 1);
		D_UINT32(ulTakeGold, 1);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT8(ucSteelType, 1);
		E_UINT32(ulStartTime, 1);
		E_UINT32(ulLastTime, 1);
		E_UINT8(ucHours, 1);
		E_UINT64(ullExp, 1);
		E_UINT32(ulTakeGold, 1);
		return iPos;
	}
};//tolua_export


/*
 *  Ӣ�������ṹ
 */
struct SHeroSteel //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint8 steelType;											// ��������
	uint32 startTime;											// ��ʼ����ʱ�䣨��λ�룩
	uint8 quarters;												// ������15������
	uint32 quarterRes;											// һ���ӿɻ�õľ���
	uint32 quarterMoney;										// һ�������ĵ�Ǯ��
	uint32 hourGold;											// һСʱ���ĵĽ��
	uint8 actMult;												// ��ӳɵı���
	//tolua_end

	SHeroSteel():steelType(0),
		startTime(0),
		quarters(0),
		quarterRes(0),
		quarterMoney(0),
		hourGold(0),
		actMult(1){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT8(steelType, 12);
		D_UINT32(startTime, 12);
		D_UINT8(quarters, 12);
		D_UINT32(quarterRes, 12);
		D_UINT32(quarterMoney, 12);
		D_UINT32(hourGold, 12);
		D_UINT8(actMult, 103);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT8(steelType, 12);
		E_UINT32(startTime, 12);
		E_UINT8(quarters, 12);
		E_UINT32(quarterRes, 12);
		E_UINT32(quarterMoney, 12);
		E_UINT32(hourGold, 12);
		E_UINT8(actMult, 103);
		return iPos;
	}
};//tolua_export


/*
 *  Ӣ�۽ṹ
 */
struct SOHero //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint64 ullId;												// Ӣ��Id
	uint32 ulResId;												// Ӣ��ResId
	char szName[MAX_HERONAME_ARR_LEN];							// Ӣ����
	uint8 ucLevel;												// Ӣ�۵ȼ�
	uint32 ulExp;												// Ӣ�۾���
	uint8 ucState;												// Ӣ��״̬
	uint32 ulCityId;											// Ӣ�۵�ǰ���ڳ���id
	uint32 ulCityPosX;											// Ӣ�۵�ǰ���ڳ���ˮƽ����
	uint32 ulCityPosY;											// Ӣ�۵�ǰ���ڳ��д�ֱ����
	uint8 aucSubjects[MAX_SUBJECT_CNT];							// Ӣ�۱����б�
	SCarrySoldierList stSoldiers;								// Я����ʿ���б�
	SHeroAttrList stAttrs;										// �����б�
	SWearList stWears;											// ����װ���б�
	SSkillList stSkills;										// �����б�
	SSCutList stSCuts;											// ���߿���б�
	SHeroSteel stSteel;											// Ӣ������
	//tolua_end

	SOHero():ullId(0),
		ulResId(0),
		ucLevel(0),
		ulExp(0),
		ucState(0),
		ulCityId(0),
		ulCityPosX(0),
		ulCityPosY(0){
		szName[0]=0;
		memset(aucSubjects, 0, sizeof(aucSubjects[0])*MAX_SUBJECT_CNT);
	}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT64(ullId, 1);
		D_UINT32(ulResId, 1);
		D_STRING(szName, MAX_HERONAME_ARR_LEN, 1);
		D_UINT8(ucLevel, 1);
		D_UINT32(ulExp, 1);
		D_UINT8(ucState, 1);
		D_UINT32(ulCityId, 1);
		D_UINT32(ulCityPosX, 1);
		D_UINT32(ulCityPosY, 1);
		D_ARRAY_UINT8(aucSubjects, MAX_SUBJECT_CNT, MAX_SUBJECT_CNT, 1);
		D_STRUCT(stSoldiers, 1);
		D_STRUCT(stAttrs, 1);
		D_STRUCT(stWears, 1);
		D_STRUCT(stSkills, 1);
		D_STRUCT(stSCuts, 1);
		D_STRUCT(stSteel, 1);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT64(ullId, 1);
		E_UINT32(ulResId, 1);
		E_STRING(szName, MAX_HERONAME_ARR_LEN, 1);
		E_UINT8(ucLevel, 1);
		E_UINT32(ulExp, 1);
		E_UINT8(ucState, 1);
		E_UINT32(ulCityId, 1);
		E_UINT32(ulCityPosX, 1);
		E_UINT32(ulCityPosY, 1);
		E_ARRAY_UINT8(aucSubjects, MAX_SUBJECT_CNT, MAX_SUBJECT_CNT, 1);
		E_STRUCT(stSoldiers, 1);
		E_STRUCT(stAttrs, 1);
		E_STRUCT(stWears, 1);
		E_STRUCT(stSkills, 1);
		E_STRUCT(stSCuts, 1);
		E_STRUCT(stSteel, 1);
		return iPos;
	}
};//tolua_export


/*
 *  Ӣ�ۼ��������ṹ
 */
struct SSkillSteel //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint32 ulResId;												// ����ResId
	uint32 ulStoptime;											// ������������ʱ��
	uint32 ulDurtime;											// ����������ʱ������λСʱ
	//tolua_end

	SSkillSteel():ulResId(0),
		ulStoptime(0),
		ulDurtime(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT32(ulResId, 1);
		D_UINT32(ulStoptime, 1);
		D_UINT32(ulDurtime, 1);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT32(ulResId, 1);
		E_UINT32(ulStoptime, 1);
		E_UINT32(ulDurtime, 1);
		return iPos;
	}
};//tolua_export


/*
 *  Ӣ�۽ṹ
 */
struct SHero //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint64 ullId;												// Ӣ��Id
	uint8 ucProf;												// Ӣ��ְҵ
	char szName[MAX_HERONAME_ARR_LEN];							// Ӣ����
	uint8 ucLevel;												// Ӣ�۵ȼ�
	uint8 ucSkeletonLevel;										// Ӣ������ȼ�
	uint32 ulSSteelStopTime;									// Ӣ����������ʱ��
	uint32 ulIcon;												// Ӣ��ͷ��
	uint8 ucSex;												// Ӣ���Ա�
	uint8 ucState;												// Ӣ��״̬
	uint8 ucOfficial;											// Ӣ�۹�ְ
	uint8 ucLockState;											// ����״̬
	uint32 ulUnlockTime;										// ��������ʱ��
	uint8 aucSubjects[MAX_SUBJECT_CNT];							// Ӣ�۱����б�
	SHeroAttrList stAttrs;										// �����б�
	SSoldier stSoldier;											// Я����ʿ��
	SWearList stWears;											// ����װ���б�
	SSkillList stSkills;										// �����б�
	uint32 ulCurTacticSkill;									// ��ǰװ����ս�Լ���
	SHeroSteel stSteel;											// Ӣ������
	SSkillSteel stSkillSteel;									// Ӣ�ۼ�������
	//tolua_end

	SHero():ullId(0),
		ucProf(0),
		ucLevel(0),
		ucSkeletonLevel(0),
		ulSSteelStopTime(0),
		ulIcon(0),
		ucSex(0),
		ucState(0),
		ucOfficial(0),
		ucLockState(0),
		ulUnlockTime(0),
		ulCurTacticSkill(0){
		szName[0]=0;
	}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT64(ullId, 1);
		D_UINT8(ucProf, 1);
		D_STRING(szName, MAX_HERONAME_ARR_LEN, 1);
		D_UINT8(ucLevel, 1);
		D_UINT8(ucSkeletonLevel, 1);
		D_UINT32(ulSSteelStopTime, 1);
		D_UINT32(ulIcon, 1);
		D_UINT8(ucSex, 1);
		D_UINT8(ucState, 1);
		D_UINT8(ucOfficial, 1);
		D_UINT8(ucLockState, 1);
		D_UINT32(ulUnlockTime, 1);
		D_ARRAY_UINT8(aucSubjects, MAX_SUBJECT_CNT, MAX_SUBJECT_CNT, 1);
		D_STRUCT(stAttrs, 1);
		D_STRUCT(stSoldier, 1);
		D_STRUCT(stWears, 1);
		D_STRUCT(stSkills, 1);
		D_UINT32(ulCurTacticSkill, 1);
		D_STRUCT(stSteel, 1);
		D_STRUCT(stSkillSteel, 1);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT64(ullId, 1);
		E_UINT8(ucProf, 1);
		E_STRING(szName, MAX_HERONAME_ARR_LEN, 1);
		E_UINT8(ucLevel, 1);
		E_UINT8(ucSkeletonLevel, 1);
		E_UINT32(ulSSteelStopTime, 1);
		E_UINT32(ulIcon, 1);
		E_UINT8(ucSex, 1);
		E_UINT8(ucState, 1);
		E_UINT8(ucOfficial, 1);
		E_UINT8(ucLockState, 1);
		E_UINT32(ulUnlockTime, 1);
		E_ARRAY_UINT8(aucSubjects, MAX_SUBJECT_CNT, MAX_SUBJECT_CNT, 1);
		E_STRUCT(stAttrs, 1);
		E_STRUCT(stSoldier, 1);
		E_STRUCT(stWears, 1);
		E_STRUCT(stSkills, 1);
		E_UINT32(ulCurTacticSkill, 1);
		E_STRUCT(stSteel, 1);
		E_STRUCT(stSkillSteel, 1);
		return iPos;
	}
};//tolua_export


/*
 *  �ƹ��е�Ӣ��
 */
struct SNewHero //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint32 ulId;												// Id
	uint8 ucProf;												// Ӣ��ְҵ
	char szName[MAX_HERONAME_ARR_LEN];							// Ӣ����
	uint8 ucLevel;												// Ӣ�۵ȼ�
	uint32 ulIcon;												// Ӣ��ͷ��
	uint8 ucSex;												// Ӣ���Ա�
	uint8 ucAttrCount;											// ���Ը���
	SAttr astAttrs[MAX_NEWHEROATTRS_CNT];						// ����ֵ
	//tolua_end

	SNewHero():ulId(0),
		ucProf(0),
		ucLevel(0),
		ulIcon(0),
		ucSex(0),
		ucAttrCount(0){
		szName[0]=0;
	}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT32(ulId, 1);
		D_UINT8(ucProf, 1);
		D_STRING(szName, MAX_HERONAME_ARR_LEN, 1);
		D_UINT8(ucLevel, 1);
		D_UINT32(ulIcon, 1);
		D_UINT8(ucSex, 1);
		D_UINT8(ucAttrCount, 1);
		D_ARRAY_STRUCT(astAttrs, ucAttrCount, MAX_NEWHEROATTRS_CNT, 1);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT32(ulId, 1);
		E_UINT8(ucProf, 1);
		E_STRING(szName, MAX_HERONAME_ARR_LEN, 1);
		E_UINT8(ucLevel, 1);
		E_UINT32(ulIcon, 1);
		E_UINT8(ucSex, 1);
		E_UINT8(ucAttrCount, 1);
		E_ARRAY_STRUCT(astAttrs, ucAttrCount, MAX_NEWHEROATTRS_CNT, 1);
		return iPos;
	}
};//tolua_export


/*
 *  Ӣ���б�ṹ
 */
struct SHeroList //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint32 ulHeroAttrLastTime;									// Ӣ������ˢ�µ��ϴ�ʱ��
	uint8 ucCount;												// Ӣ�۸���
	SHero astHeros[MAX_HERO_CNT];								// Ӣ�۾�������
	uint32 ulCanUseSSTime;										// ��ʹ�õļ�������ʱ��
	uint32 ulNewHeroLastTime;									// �ƹ���Ӣ��ˢ�µ��ϴ�ʱ��
	uint8 ucNewCount;											// �ƹ���Ӣ�۸���
	SNewHero astNewHeros[MAX_NEWHERO_CNT];						// �ƹ���Ӣ�۾�������
	//tolua_end

	SHeroList():ulHeroAttrLastTime(0),
		ucCount(0),
		ulCanUseSSTime(0),
		ulNewHeroLastTime(0),
		ucNewCount(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT32(ulHeroAttrLastTime, 1);
		D_UINT8(ucCount, 1);
		D_ARRAY_STRUCT(astHeros, ucCount, MAX_HERO_CNT, 1);
		D_UINT32(ulCanUseSSTime, 1);
		D_UINT32(ulNewHeroLastTime, 1);
		D_UINT8(ucNewCount, 1);
		D_ARRAY_STRUCT(astNewHeros, ucNewCount, MAX_NEWHERO_CNT, 1);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT32(ulHeroAttrLastTime, 1);
		E_UINT8(ucCount, 1);
		E_ARRAY_STRUCT(astHeros, ucCount, MAX_HERO_CNT, 1);
		E_UINT32(ulCanUseSSTime, 1);
		E_UINT32(ulNewHeroLastTime, 1);
		E_UINT8(ucNewCount, 1);
		E_ARRAY_STRUCT(astNewHeros, ucNewCount, MAX_NEWHERO_CNT, 1);
		return iPos;
	}
};//tolua_export


/*
 *  ս���ṹ
 */
struct SBulletin //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	//tolua_end

	SBulletin(){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		return iPos;
	}
};//tolua_export


/*
 *  ս���ṹ�б�
 */
struct SBulletinList //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint8 ucCount;												// ս������
	SBulletin astBulletins[MAX_BULLETINS_CNT];					// ս����������
	//tolua_end

	SBulletinList():ucCount(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT8(ucCount, 1);
		D_ARRAY_STRUCT(astBulletins, ucCount, MAX_BULLETINS_CNT, 1);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT8(ucCount, 1);
		E_ARRAY_STRUCT(astBulletins, ucCount, MAX_BULLETINS_CNT, 1);
		return iPos;
	}
};//tolua_export


/*
 *  ���ѽṹ
 */
struct SBuddy //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint8 flag;													// �������ͱ�־
	uint64 roleId;												// ��ɫid
	//tolua_end

	SBuddy():flag(0),
		roleId(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT8(flag, 1);
		D_UINT64(roleId, 1);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT8(flag, 1);
		E_UINT64(roleId, 1);
		return iPos;
	}
};//tolua_export


/*
 *  ���ѽṹ�б�
 */
struct SBuddyList //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint16 count;												// ���Ѹ���
	SBuddy buddys[MAX_BUDDYS_CNT];								// ���Ѿ�������
	uint16 applyCount;											// �������
	uint64 applyRoleIds[MAX_BUDDYS_APPLY_CNT];					// �����б�
	//tolua_end

	SBuddyList():count(0),
		applyCount(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT16(count, 1);
		D_ARRAY_STRUCT(buddys, count, MAX_BUDDYS_CNT, 1);
		D_UINT16(applyCount, 1);
		D_ARRAY_UINT64(applyRoleIds, applyCount, MAX_BUDDYS_APPLY_CNT, 1);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT16(count, 1);
		E_ARRAY_STRUCT(buddys, count, MAX_BUDDYS_CNT, 1);
		E_UINT16(applyCount, 1);
		E_ARRAY_UINT64(applyRoleIds, applyCount, MAX_BUDDYS_APPLY_CNT, 1);
		return iPos;
	}
};//tolua_export


/*
 *  ũ���ṹ
 */
struct SFarm //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint32 ulId;												// ũ��λ��Id
	uint32 ulResId;												// ũ����ԴId
	uint8 ucLevel;												// ��Դ�ȼ�
	uint8 ucState;												// ��Դ�ɳ�״̬
	uint32 ulStartTime;											// ��Դ�ɳ�����ʼʱ��
	uint32 ulStopTime;											// ��Դ��ʱ�ɳ����
	uint32 ulTotalRes;											// ��Դ�ɳ���ɺ�ɲɼ����ܵ�����
	uint32 ulLeftRes;											// ��Դ�ɳ���ɺ�ɲɼ���ʣ�������
	uint8 collectorCount;										// �ɼ�������
	uint64 collectors[MAX_COLLECTOR_CNT];						// �ɼ���id�б�
	uint32 seqId;												// ũ����ԴseqId
	uint32 protectStopTime;										// ũ����ԴseqId
	//tolua_end

	SFarm():ulId(0),
		ulResId(0),
		ucLevel(1),
		ucState(0),
		ulStartTime(0),
		ulStopTime(0),
		ulTotalRes(0),
		ulLeftRes(0),
		collectorCount(0),
		seqId(0),
		protectStopTime(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT32(ulId, 1);
		D_UINT32(ulResId, 1);
		D_UINT8(ucLevel, 1);
		D_UINT8(ucState, 1);
		D_UINT32(ulStartTime, 1);
		D_UINT32(ulStopTime, 1);
		D_UINT32(ulTotalRes, 1);
		D_UINT32(ulLeftRes, 1);
		D_UINT8(collectorCount, 9);
		D_ARRAY_UINT64(collectors, collectorCount, MAX_COLLECTOR_CNT, 9);
		D_UINT32(seqId, 100);
		D_UINT32(protectStopTime, 110);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT32(ulId, 1);
		E_UINT32(ulResId, 1);
		E_UINT8(ucLevel, 1);
		E_UINT8(ucState, 1);
		E_UINT32(ulStartTime, 1);
		E_UINT32(ulStopTime, 1);
		E_UINT32(ulTotalRes, 1);
		E_UINT32(ulLeftRes, 1);
		E_UINT8(collectorCount, 9);
		E_ARRAY_UINT64(collectors, collectorCount, MAX_COLLECTOR_CNT, 9);
		E_UINT32(seqId, 100);
		E_UINT32(protectStopTime, 110);
		return iPos;
	}
};//tolua_export


/*
 *  ũ����¼�ṹ
 */
struct SFarmLog //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint8 ucType;												// ��¼����
	char szRName[MAX_ROLENAME_ARR_LEN];							// ��ɫ��
	uint32 ulLogTime;											// ��¼��־��ʱ��
	uint32 ulParam1;											// ��¼����1
	uint32 ulParam2;											// ��¼����2
	uint32 ulParam3;											// ��¼����3
	uint32 ulParam4;											// ��¼����4
	//tolua_end

	SFarmLog():ucType(0),
		ulLogTime(0),
		ulParam1(0),
		ulParam2(0),
		ulParam3(0),
		ulParam4(0){
		szRName[0]=0;
	}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT8(ucType, 1);
		D_STRING(szRName, MAX_ROLENAME_ARR_LEN, 1);
		D_UINT32(ulLogTime, 1);
		D_UINT32(ulParam1, 1);
		D_UINT32(ulParam2, 1);
		D_UINT32(ulParam3, 1);
		D_UINT32(ulParam4, 1);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT8(ucType, 1);
		E_STRING(szRName, MAX_ROLENAME_ARR_LEN, 1);
		E_UINT32(ulLogTime, 1);
		E_UINT32(ulParam1, 1);
		E_UINT32(ulParam2, 1);
		E_UINT32(ulParam3, 1);
		E_UINT32(ulParam4, 1);
		return iPos;
	}
};//tolua_export


/*
 *  ũ���ṹ�б�
 */
struct SFarmList //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint8 ucCount;												// ũ������
	SFarm astFarms[MAX_FARM_CNT];								// ũ����������
	uint32 ulLogVer;											// ��¼��İ汾��
	uint8 ucLogCount;											// ũ��������¼����
	SFarmLog astFarmLogs[MAX_FARM_LOG_CNT];						// ũ�������¼
	uint32 farmVer;												// ũ���İ汾��
	uint32 lastSeqId;											// �ؿ����һ�ε�seqId
	//tolua_end

	SFarmList():ucCount(0),
		ulLogVer(0),
		ucLogCount(0),
		farmVer(0),
		lastSeqId(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT8(ucCount, 1);
		D_ARRAY_STRUCT(astFarms, ucCount, MAX_FARM_CNT, 1);
		D_UINT32(ulLogVer, 1);
		D_UINT8(ucLogCount, 1);
		D_ARRAY_STRUCT(astFarmLogs, ucLogCount, MAX_FARM_LOG_CNT, 1);
		D_UINT32(farmVer, 9);
		D_UINT32(lastSeqId, 100);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT8(ucCount, 1);
		E_ARRAY_STRUCT(astFarms, ucCount, MAX_FARM_CNT, 1);
		E_UINT32(ulLogVer, 1);
		E_UINT8(ucLogCount, 1);
		E_ARRAY_STRUCT(astFarmLogs, ucLogCount, MAX_FARM_LOG_CNT, 1);
		E_UINT32(farmVer, 9);
		E_UINT32(lastSeqId, 100);
		return iPos;
	}
};//tolua_export


/*
 *  �Ƽ�
 */
struct SCulture //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint8 level;												// �Ƽ��ȼ�
	uint32 id;													// �Ƽ���Դid
	//tolua_end

	SCulture():level(0),
		id(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT8(level, 1);
		D_UINT32(id, 1);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT8(level, 1);
		E_UINT32(id, 1);
		return iPos;
	}
};//tolua_export


/*
 *  �����о��ĿƼ�
 */
struct SLearningCulture //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint32 id;													// �Ƽ�id
	uint32 stoptime;											// ֹͣʱ��
	//tolua_end

	SLearningCulture():id(0),
		stoptime(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT32(id, 1);
		D_UINT32(stoptime, 1);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT32(id, 1);
		E_UINT32(stoptime, 1);
		return iPos;
	}
};//tolua_export


/*
 *  �Ƽ��б�
 */
struct SCultures //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint8 count;												// �Ƽ�����
	SCulture cultures[MAX_CULTURE_CNT];							// �Ƽ���������
	SLearningCulture learning;									// �����о��ĿƼ�
	//tolua_end

	SCultures():count(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT8(count, 1);
		D_ARRAY_STRUCT(cultures, count, MAX_CULTURE_CNT, 1);
		D_STRUCT(learning, 1);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT8(count, 1);
		E_ARRAY_STRUCT(cultures, count, MAX_CULTURE_CNT, 1);
		E_STRUCT(learning, 1);
		return iPos;
	}
};//tolua_export


/*
 *  ��־û�����Ľ�ɫ����
 */
struct SDBVar //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint64 ullRoleId;											// ��ɫΨһid
	char szUName[MAX_USERNAME_ARR_LEN];							// �û���
	char szRName[MAX_ROLENAME_ARR_LEN];							// ��ɫ��
	uint8 ucSex;												// �Ա�
	SFixVar stFixVar;											// �־ò��������
	SBaseInfo stBInfos;											// ��ɫ��һЩ��������
	SHeroList stHeros;											// Ӣ���б�
	SSoldierList soldiers;										// ʿ���б�
	SCitys stCitys;												// �����б�
	SFarmList stFarms;											// ũ���б�
	SCultures cultures;											// �Ƽ��б�
	SAllItems stItems;											// �����б�
	SStateList states;											// buff�б�
	SMilitary military;											// ������Ϣ
	STaskList tasks;											// �����б�
	SBulletinList stBulletins;									// ս���б�
	SBuddyList buddys;											// �����б�
	SMiscs stMiscs;												// ����ṹ
	uint32 regTime;												// ��ɫ����ʱ��
	uint32 lockToTime;											// ��Ž�ֹʱ��
	//tolua_end

	SDBVar():ullRoleId(0),
		ucSex(0),
		regTime(0),
		lockToTime(0){
		szUName[0]=0;
		szRName[0]=0;
	}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT64(ullRoleId, 1);
		D_STRING(szUName, MAX_USERNAME_ARR_LEN, 1);
		D_STRING(szRName, MAX_ROLENAME_ARR_LEN, 1);
		D_UINT8(ucSex, 1);
		D_STRUCT(stFixVar, 1);
		D_STRUCT(stBInfos, 1);
		D_STRUCT(stHeros, 1);
		D_STRUCT(soldiers, 1);
		D_STRUCT(stCitys, 1);
		D_STRUCT(stFarms, 1);
		D_STRUCT(cultures, 1);
		D_STRUCT(stItems, 1);
		D_STRUCT(states, 1);
		D_STRUCT(military, 1);
		D_STRUCT(tasks, 1);
		D_STRUCT(stBulletins, 1);
		D_STRUCT(buddys, 1);
		D_STRUCT(stMiscs, 1);
		D_UINT32(regTime, 23);
		D_UINT32(lockToTime, 114);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT64(ullRoleId, 1);
		E_STRING(szUName, MAX_USERNAME_ARR_LEN, 1);
		E_STRING(szRName, MAX_ROLENAME_ARR_LEN, 1);
		E_UINT8(ucSex, 1);
		E_STRUCT(stFixVar, 1);
		E_STRUCT(stBInfos, 1);
		E_STRUCT(stHeros, 1);
		E_STRUCT(soldiers, 1);
		E_STRUCT(stCitys, 1);
		E_STRUCT(stFarms, 1);
		E_STRUCT(cultures, 1);
		E_STRUCT(stItems, 1);
		E_STRUCT(states, 1);
		E_STRUCT(military, 1);
		E_STRUCT(tasks, 1);
		E_STRUCT(stBulletins, 1);
		E_STRUCT(buddys, 1);
		E_STRUCT(stMiscs, 1);
		E_UINT32(regTime, 23);
		E_UINT32(lockToTime, 114);
		return iPos;
	}
};//tolua_export


/*
 *  ��־û��������������
 */
struct SDBAlliVar //tolua_export 
	: public SPkgBase 
{//tolua_export
	//tolua_begin
	uint64 ullallianceId;										// ����Ψһid
	//tolua_end

	SDBAlliVar():ullallianceId(0){}

	int Decode(const char* lpInBuf, int iInBufLen, int iPos, int iVer){
		D_UINT64(ullallianceId, 1);
		return iPos;
	}

	int Encode(char* lpOutBuf, int iOutBufLen, int iPos, int iVer){
		E_UINT64(ullallianceId, 1);
		return iPos;
	}
};//tolua_export


#pragma pack(pop)


#endif //_tq_role_338saf3w3_var_h_
