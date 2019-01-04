----------------------------------------------------------------------------------
-- ͨ�����ļ������ɲ�ͬ��Ϸ�Ľ�ɫ����
-- ���ɽ�ɫ���ݿ�
-- ������ȡ�͸��½�ɫ���ݵĽӿں���
-- ���ɹ�toluaʹ�õ�ע��
-- ���ļ����ɵĽ�������: xxx.h �ļ�  xxx.sql �ļ� 

-- ����˳���ȱ��� GameSvr���ڱ��� GameScript�� ��
-- libgamescript.so copy �� bin ��
-- luaut.dll copy �� script ��
----------------------------------------------------------------------------------
require('db_define')

g_role = 
{
	-- ��Ҫ������ļ�
	output_file = '../tqRoleVar.h',
	output_db_file = '../tqDbAssist.h',
	-- �Ƿ������toluaʹ��
	is_out_tolua = true,
	
	-- �����Ķ���
	const = 
	{
		{name = 'PKG_CUR_VER';                    	val = 127,},
		
		{name = 'MAX_SQL_LEN';                    	val = 2097152,},
		{name = 'MAX_ROLE_TABLE_CNT';               val = 1,},
		{name = 'MAX_CITY_STATES_CNT';                    val = 32,},
		{name = 'MAX_INBUILD_CNT';                  val = 30,},
		{name = 'MAX_BUILDING_CNT';                 val = 6,},
		{name = 'MAX_CITY_CNT';                 	val = 5,},
		{name = 'MAX_SELFFIELD_CNT';                 	val = 11,},
		{name = 'MAX_ITEMS_CNT';                 	val = 750,},
		{name = 'MAX_HOLES_CNT';                 	val = 3,},
		{name = 'MAX_WEARS_CNT';                 	val = 12,},
		{name = 'MAX_USERNAME_ARR_LEN';           val = 33,},
		{name = 'MAX_USERNAME_LEN';          		val = '(MAX_USERNAME_ARR_LEN - 1)',},
		{name = 'MIN_USERNAME_LEN';          		val = 3,},
		{name = 'MAX_ROLENAME_ARR_LEN';           val = 22,},
		{name = 'MAX_ROLENAME_LEN';           		val = '(MAX_ROLENAME_ARR_LEN - 1)',},
		{name = 'MIN_ROLENAME_LEN';           		val = 3,},
		{name = 'MAX_HERONAME_ARR_LEN';           val = 19,},
		{name = 'MAX_HERONAME_LEN';           		val = '(MAX_HERONAME_ARR_LEN - 1)',},
		{name = 'MIN_HERONAME_LEN';           		val = 2,},
		{name = 'MAX_CITYNAME_ARR_LEN';            val = 22,},
		{name = 'MAX_CITYNAME_LEN';           		val = '(MAX_CITYNAME_ARR_LEN - 1)',},
		{name = 'MAX_TASKS_CNT';                 	val = 500,},
		{name = 'MAX_ONLINE_TASKS_CNT';                 	val = 4,},
		{name = 'MAX_EVERYDAY_TASKS_CNT';                 	val = 10,},
		{name = 'MAX_ACT_TASKS_CNT';                 	val = 100,},
		{name = 'MAX_HERO_CNT';               		val = 32,},
		{name = 'MAX_NEWHERO_CNT';             	val = 6,},
		{name = 'MAX_SLDS_CNT';               		val = 50,},
		{name = 'MAX_GEMBESET_CNT';               		val = 3,},
		
		{name = 'MAX_MAILTITLE_ARR_LEN';       val = 45+1,},
		{name = 'MAX_MAISYSLCON_ARR_LEN';   val = 4096+1,},
		{name = 'MAX_MAILCON_ARR_LEN';        val = 750+1,},
		
		{name = 'MAX_MAILTITLE_LEN',             val = '(MAX_MAILTITLE_ARR_LEN - 1)',},
		{name = 'MAX_MAISYSLCON_LEN',          val = '(MAX_MAISYSLCON_ARR_LEN - 1)',},
		{name = 'MAX_MAILCON_LEN',               val = '(MAX_MAILCON_ARR_LEN - 1)',},
		
		{name = 'MAX_BULLETINS_CNT';            	val = 16,},
		{name = 'MAX_BUDDYS_CNT';               	val = 300,},
		{name = 'MAX_BUDDYS_APPLY_CNT';      val = 10,},
		{name = 'MAX_ROLEATTRS_CNT';           val = 22,},
		{name = 'MAX_HEROATTRS_CNT';          	val = 37,},
		{name = 'MAX_SIMPLEHEROATTRS_CNT'; val = 3,},
		{name = 'MAX_NEWHEROATTRS_CNT';     val = 9,},
		{name = 'MAX_FARM_CNT';               		val = 120,},
		{name = 'MAX_CULTURE_CNT';               		val = 33,},
		{name = 'MAX_FARM_LOG_CNT';               		val = 50,},
		{name = 'MAX_SUBJECT_CNT';               val = 5,},
		{name = 'MAX_HEROWEAR_CNT';               val = 7,},
		{name = 'MAX_HERO_SKILL_CNT';               val = 13,},
		{name = 'MAX_HERO_SCUT_CNT';               val = 12,},
		{name = 'MAX_ITEM_ATTRS_CNT';               val = 18,},
		{name = 'MAX_FAVORITE_CNT';               val = 10,},
		{name = 'MAX_ENEMY_CNT';               val = 300,},
		{name = 'MAX_SUCC_COPYFIELD_CNT';               val = 30,},
		{name = 'MAX_LINEUP_CNT';               val = 16,},
		{name = 'MAX_DEFAULTTEAM_HERO_CNT';               val = 5,},
		{name = 'MAX_DEFAULTTEAM_CNT';               val = 3,},
		{name = 'MAX_TEAM_HERO_CNT';               val = 5,},
		{name = 'MAX_SELFARMY_CNT';               val = 20,},
		{name = 'MAX_ENEMYARMY_CNT';          val = 50,},
		{name = 'MAX_ALLIARMY_CNT';          val = 10,},
		{name = 'MAX_PAIQIAN_ALLIARMY_CNT';          val = 5,},
		{name = 'MAX_CITYDEF_CNT';          val = 5,},
		{name = 'MAX_ROLEINTRO_ARR_LEN';          val = 151,},
		{name = 'MAX_ROLEINTRO_LEN';          val = 150,},
		{name = 'MAX_COLLECTOR_CNT';          val = 10,},
		{name = 'MAX_INVITE_JOIN_ALLI_CNT';          val = 10,},
		{name = 'MAX_ALLINAME_ARR_LEN';           val = 22,},
		{name = 'MAX_TRADING_ROLES_CNT';           val = 20,},
		{name = 'MAX_ACT_TERRACE_COUNT';           val = 100,},
		{name = 'MAX_ACTREWARDS_CNT';           val = 4,},
		{name = 'MAX_SIGNINREWARDS_CNT';           val = 3,},
		{name = 'MAX_SIGNINREWARDS_CNT_EX';           val = 4,},
		{name = 'MAX_ACTVALTASKS_CNT';           val = 20,},
		{name = 'MAX_FORCELINEUPCFG_CNT';           val = 2,},
		{name = 'MAX_YD_LVL_IDS_CNT';           val = 15,},
		{name = 'MAX_BD_LVL_IDS_CNT';           val = 15,},
		{name = 'MAX_BUY_ITEMS_CNT';           val = 20,},
		{name = 'MAX_CTLCFG_BTIMAP_CNT';           val = 4,},
		{name = 'MAX_PAYACT_GIFT_CNT';           val = 10,},
		{name = 'MAX_WAIT_BUILDS_CNT';           val = 20,},
		{name = 'MAX_CDKEY_CNT';           val = 20,},
		{name = 'MAX_HELPTIP_CNT';           val = 20,},
	};
	
	
	-- �ṹ�Ķ���
	struct = 
	{
		-- �ڳǽ����ṹ
		{
			type = 'struct',
			name = 'SInBuild',
			desc = '�Ѿ���ɵĽ����ṹ',
			item = 
			{
				{ type='uint32',	name='Id', 				default='0', 	ver=1, 	desc='����λ��id', },
				{ type='uint32',	name='ResId', 			default='0', 	ver=1, 	desc='������Դid', },
				{ type='uchar', 	name='Level', 			default='0', 	ver=1, 	desc='������ǰ�ȼ�', },
				{ type='uchar',	name='State',			default='0', 	ver=1, 	desc='����״̬', },
				{ type='uint32',	name='Stoptime',		default='0', 	ver=1, 	desc='������������ʱ��', },
				{ type='uint32',	name='Duration',		default='0', 	ver=1, 	desc='�ȴ�״̬�еĽ�����Ҫ��ʱ��', },
			},
		},
		
		-- �ڳǽ����б�ṹ 
		{
			type = 'struct',
			name = 'SInBuildList',
			desc = '�ڳǽ����б�ṹ',
			item = 
			{
				{ type='uchar',		name='Total', 			default='0', 	ver=1, 	desc='�ڳǽ�������', },
				{ type='SInBuild', 	name='InBuilds', 		count='MAX_INBUILD_CNT', refer='Total',	ver=1, 	desc='�����б�ľ�������', },
			},
		},
		
		--�ǳ���Դ
		{
			type = 'struct',
			name = 'SCityRes',
			desc = '�ǳ���Դ',
			item = 
			{
				{ type='uchar',		name='Level', 								default='0', 	ver=1, 			desc='�Ǳ��ȼ�', },
				{ type='uint32',		name='BuildVal', 							default='0', 	ver=1, 			desc='�Ǳ������', },
				{ type='uint32',		name='HurtBuildVal', 					default='0', 	ver=1, 			desc='����Ľ����', },
				{ type='uint32',		purename='todayLostedBuildTime', 	default='0', 	ver=1, 			desc='��������Ľ����ʱ��', },
				{ type='uint32',		purename='todayLostedBuildVal', 	default='0', 	ver=1, 			desc='��������Ľ����ֵ', },
				{ type='int32',		name='IdlePopu',							default='0', 	ver=1, 			desc='�����˿�', },
				{ type='uint64',		name='Wood',								default='0', 	ver=1, 			desc='ľ��', },
				{ type='uint64',		name='Stone',								default='0', 	ver=1, 			desc='ʯ��', },
				{ type='uint64',		name='Iron',								default='0', 	ver=1, 			desc='����', },
				{ type='uint64',		name='Food',								default='0', 	ver=1, 			desc='��ʳ', },
				{ type='uint64',		name='Money',							default='0', 	ver=1, 			desc='Ǯ��', },
				{ type='uint32',		name='MLastTime',						default='0', 	ver=1, 			desc='Ǯ�����һ�εĸ���ʱ��', },
				{ type='uint32',		name='ILastTime',						default='0', 	ver=1, 			desc='�����˿����һ�εĸ���ʱ��', },
				{ type='uchar',		purename='lastMaxLevel', 								default='0', 	ver=17, 			desc='�Ǳ��ϴε����ȼ�', },
			},
		},
		
		--�ǳط���
		{
			type = 'struct',
			name = 'SCityDef',
			desc = '�ǳط���',
			item = 
			{
				{ type='uint32',	purename='defs',					count='MAX_CITYDEF_CNT',		ver=1, 	desc='�Ƿ������б�', },
				{ type='uint32',	purename='stopTime',			default='0',								ver=1,	desc='��ǰ���ڽ���Ƿ��Ľ���ʱ��',},
				{ type='uint32',	purename='buildResId',			default='0',								ver=1,	desc='��ǰ���ڽ���Ƿ�����Դid',},
				{ type='uint32',	purename='buildNumber',		default='0',								ver=1,	desc='��ǰ���ڽ���Ƿ�������',},
			},
		},
		
		--effect�ṹ����
		{
			type = 'struct',
			name = 'SEffect',
			desc = 'effect�ṹ����',
			item = 
			{
				{ type='ushort', 	purename='id', 		default='0', 	ver=1, 	desc='Ч��id', },
				{ type='uint32', 	purename='val', 		default='0', 	ver=1, 	desc='Ч��ֵ', },
				{ type='uchar', 	purename='unit', 		default='0', 	ver=1, 	desc='Ч����λ', },				
			},		
		},
		
		--�����߽ṹ����
		{
			type = 'struct',
			name = 'SCreator',
			desc = '�����߽ṹ����',
			item = 
			{
				{ type='uchar', 	purename='type', 		default='0', 	ver=1, 	desc='����������', },
				{ type='uint64', 	purename='id', 			default='0', 	ver=1, 	desc='�����ߵ�id', },
				{ type='uint32', 	purename='skillId', 		default='0', 	ver=1, 	desc='������ʹ�õļ���id', },
			},			
		},
		
		-- state�ṹ����
		{
			type = 'struct',
			name = 'SState',
			desc = 'state�ṹ����',
			item = 
			{
				{ type='uint32',		purename='id', 				default='0', 	ver=1, 	desc='state��Ψһid', },
				{ type='ushort',		purename='type', 			default='0', 	ver=1, 	desc='Ч������', },
				{ type='uint32', 		purename='startTime', 		default='0', 	ver=1, 	desc='��ǰЧ����ʼ��ʱ��', },
				{ type='uint32', 		purename='lastTime', 		default='0', 	ver=1, 	desc='���һ�θ���Ч����ʱ��', },
				{ type='uint32', 		purename='duration', 		default='0', 	ver=1, 	desc='��ʾʱ�����룩', },
				{ type='uchar', 		purename='isOnline', 		default='0', 	ver=1, 	desc='�Ƿ�ֻ�����߲ż�ʱ��', },
				{ type='SCreator', 	purename='creator', 								ver=1, 	desc='������', },
				{ type='SEffect', 	purename='effect', 								ver=1, 	desc='Ч��', },
			},
		},
		
		-- state�б�ṹ����
		{
			type = 'struct',
			name = 'SStateList',
			desc = 'State�б�ṹ����',
			item = 
			{
				{ type='uchar',		purename='count',	default='0', 	ver=1, 	desc='State�б�ĸ���', },
				{ type='SState',		purename='states',	count='MAX_CITY_STATES_CNT', refer='count',	ver=1, 	desc='State�б�ľ�������', },
				{ type='uint32',		purename='lastStateId',	default='1000', 	ver=101, 	desc='state���һ�ε�id', },
			},
		},
		
		-- �������нṹ
		{
			type = 'struct',
			name = 'SCity',
			desc = '�������нṹ',
			item = 
			{
				{ type='uchar',				name='Type', 					default='0', 	ver=1, 	desc='���е�����', },
				{ type='SInBuildList', 	name='InBuilds', 									ver=1, 	desc='�ڳǽ����б�', },
			},
		},
		
		--��ά����
		{
			type = 'struct',
			name = 'SPos',
			desc = '��ά����',
			item = 
			{
				{ type='int32',		purename='x',	default='0', 	ver=1, 	desc='����x', },
				{ type='int32',		purename='y',	default='0', 	ver=1, 	desc='����y', },
			},
		},		
		
		-- ����Ұ�ؽṹ
		{
			type = 'struct',
			name = 'SSelfField',
			desc = '����Ұ�ؽṹ',
			item = 
			{
				{ type='uint32',			purename='gridId', 				default='0', 	ver=1, 	desc='Ұ�صĸ���id', },
				{ type='uint32',			purename='startTime', 			default='0', 	ver=1, 	desc='�ɼ���ʼ��ʱ��', },
				{ type='uint32',			purename='soldierNumber', 	default='0', 	ver=1, 	desc='����ɼ���ʿ������', },
			},
		},
		
		-- ��̳�һ�����
		{
			type = 'struct',
			name = 'SExchangeTodayTimes',
			desc = '��̳�һ�����',
			item = 
			{
				{ type='uint32',		purename='curTimes', 			default='0', 	ver=13, 	desc='�Ѿ��һ�����', },
				{ type='uint32',		purename='maxTimes', 			default='0', 	ver=13, 	desc='����������', },
				{ type='uint32',		purename='lastTime',	default='0', 	ver=13, 	desc='�����һ��ʱ��', },
			},
		},
		
		-- �����б�
		{
			type = 'struct',
			name = 'SCitys',
			desc = '�����б�',
			item = 
			{
				{ type='SCityRes',		name='CRes', 			default='0', 	ver=1, 	desc='�Ǳ���ͨ����Դ', },
				{ type='SCityDef',		purename='cityDef', 	default='0', 	ver=1, 	desc='�ǳط���', },
				{ type='uchar',			name='Total', 			default='0', 	ver=1, 	desc='�����б����', },
				{ type='SCity', 			name='Citys', 			count='MAX_CITY_CNT', refer='Total',	ver=1, 	desc='�����б��������', },
				
				{ type='uchar',			purename='fieldTotal', 	default='0', 	ver=1, 	desc='�Լ���Ұ���б����', },
				{ type='SSelfField',		purename='selfFields', 	count='MAX_SELFFIELD_CNT', refer='fieldTotal',	ver=1, 	desc='�Լ���Ұ���б����', },
				{ type='SExchangeTodayTimes',	purename='exchangeTodayTimes', default='0', 	ver=13, 	desc='��̳�һ�����', },
				
				{ type='uint8',			purename='startAutoBuild', 	default='0', 	ver=111, 	desc='�Ƿ������Զ�����', },
				{ type='int8',				purename='waitBuildCount', 	default='0', 	ver=111, 	desc='�ȴ��������', },
				{ type='uint32',			purename='waitBuilds', 	count='MAX_WAIT_BUILDS_CNT', refer='waitBuildCount',	ver=111, 	desc='�ȴ���������', },
			},
		},
		
		--�׽ṹ
		{
			type = 'struct',
			name = 'SOneHole',
			desc = '�׽ṹ',
			item = 
			{
				{ type='ushort',	name='Attr',		default='0', 	ver=1, 	desc='���Ե�����', },
				{ type='uint32',		name='IdxOrVal',	default='0', 	ver=1, 	desc='������ֵ', },
			},
		},
		
		--��ɫ���й̶������Ի�仯���ٵ�����
		{
			type = 'struct',
			name = 'SFixVar',
			desc = '��ɫ���й̶������Ի�仯���ٵ�����',
			item = 
			{
				{ type='uchar',		name='Icon',			default='0', 					ver=1, 			desc='ͷ��', },
				{ type='uint32',		name='CityId',			default='0', 					ver=1, 			desc='��������id', },
				{ type='uint32',		name='CPosX',			default='0', 					ver=1, 			desc='��������id', },
				{ type='uint32',		name='CPosY',			default='0', 					ver=1, 			desc='��������id', },
				{ type='uint32',		name='CreateTime',	default='0', 					ver=1, 			desc='����ʱ��', },
			},
		},
		
		--����ֵ
		{
			type = 'struct',
			name = 'SAttr',
			desc = '����ֵ',
			item = 
			{
				{ type='ushort',		name='Attr',		default='0', 	ver=1, 			desc='��������', },
				{ type='int32',		purename='ulVal', default='0', 	ver=1, 			desc='����ֵ,��©', },
				{ type='uchar',		name='Unit',		default='0', 	ver=1, 			desc='��������', },
			},
		},
		
		--����ֵ
		{
			type = 'struct',
			name = 'SAttrEx',
			desc = '����ֵ',
			item = 
			{
				{ type='ushort',		purename='attr',		default='0', 	ver=1, 			desc='��������', },
				{ type='uint32',		purename='val',		default='0', 	ver=1, 			desc='����ֵ', },
				{ type='uchar',		purename='unit',		default='0', 	ver=1, 			desc='��������', },
			},
		},
		
		--��������ֵ�б�
		{
			type = 'struct',
			name = 'SRoleAttrList',
			desc = '��������ֵ�б�',
			item = 
			{
				{ type='uint32',		name='NSLastTime',	default='0', 	ver=1, 			desc='��ʿ���������ʱ��', },
				{ type='uchar',		name='Count',			default='0', 	ver=1, 			desc='���Ը���', },
				{ type='SAttr',		name='Attrs',			count='MAX_ROLEATTRS_CNT', 	refer='Count',	ver=1,	desc='����ֵ', },
				{ type='uint32',		purename='lastPSRefreshDay',		default='0', 	ver=10, 			desc='�ϴ�ps����ˢ����һ���еĵڼ���', },
			},
		},
		
		--qq��Ա
		{
			type = 'struct',
			name = 'SQQMembership',
			desc = 'qq��Ա',
			item = 
			{
				{ type='uint8',	purename='is_yellow_vip',	default='0', 	ver=105, 			desc='', },
				{ type='uint8',	purename='is_yellow_year_vip',	default='0', 	ver=105, 			desc='', },
				{ type='uint8',	purename='yellow_vip_level',	default='0', 	ver=105, 			desc='', },
				{ type='uint8',	purename='is_yellow_high_vip',	default='0', 	ver=105, 			desc='', },
				{ type='uint8',	purename='is_blue_vip',	default='0', 	ver=105, 			desc='', },
				{ type='uint8',	purename='is_blue_year_vip',	default='0', 	ver=105, 			desc='', },
				{ type='uint8',	purename='blue_vip_level',	default='0', 	ver=105, 			desc='', },
				{ type='uint8',	purename='is_super_blue_vip',	default='0', 	ver=105, 			desc='', },
				{ type='uint8',	purename='_3366_grow_level',	default='0', 	ver=110, 			desc='', },
			},
		},
	
		--��ɫ�����л�������
		{
			type = 'struct',
			name = 'SBaseInfo',
			desc = '��ɫ�����л�������',
			item = 
			{
				{ type='uchar',				name='GM',			default='0', 			ver=1, 			desc='GMȨ��', },
				{ type='uchar',				name='Level',		default='0', 			ver=1, 			desc='��ɫ�ȼ�', },
				{ type='uint32',				name='Prestige',	default='0', 			ver=1, 			desc='����ֵ', },
				{ type='uint32',				name='CityHonor',default='0', 			ver=1, 			desc='������', },
				{ type='uint32',				name='CityCD',	default='0', 			ver=1, 			desc='ת�ݵ���ȴʱ��', },
				{ type='uint64',				name='Alliance',	default='0', 			ver=1, 			desc='����id', },
				{ type='uchar',				name='State',		default='0', 			ver=1, 			desc='����״̬', },
				{ type='SRoleAttrList',		name='Attrs',									ver=1, 			desc='���������б�', },
				{ type='uint32',				purename='cityModel',	default='0', 	ver=7, 			desc='���ǳǳ����', },
				{ type='string',				purename='introduction',	count='MAX_ROLEINTRO_ARR_LEN', 	ver=8, 			desc='����', },
				{ type='SQQMembership',	purename='qqMembership',		ver=105,	desc='qq��Ա', },
			},
		},
		
		--��������ṹ
		{
			type = 'struct',
			name = 'STask',
			desc = '��������ṹ',
			item = 
			{
				{ type='uint32',	purename='taskId',	default='0', 	ver=1, 		desc='����id', },
				{ type='uchar',		purename='state',		default='0', 	ver=1, 			desc='����״̬', },
			},	
		},
		
		--��������ṹ
		{
			type = 'struct',
			name = 'SDoingRoleTask',
			desc = '���ڽ����еľ�������',
			item = 
			{
				{ type='uint32',	purename='taskId',	default='0', 	ver=20, 		desc='���ڽ����еľ�������id', },
				{ type='uint32',	purename='stopTime',	default='0', 	ver=20, 			desc='����Ľ���ʱ��', },
				{ type='uint32',	purename='cdStopTime',	default='0', 	ver=20, 			desc='��ȴ�Ľ���ʱ��', },
			},	
		},
		
		--�ջ�Ծ������ṹ
		{
			type = 'struct',
			name = 'SActValTask',
			desc = '���ջ�Ծ������ṹ',
			item = 
			{
				{ type='uint32',	purename='taskId',	default='0', 	ver=25, 		desc='����id', },
				{ type='uint32',	purename='times',		default='0', 	ver=25, 			desc='��ɵ��������', },
			},	
		},
		
		--�����ṹ
		{
			type = 'struct',
			name = 'SActTask',
			desc = '�����ṹ',
			item = 
			{
				{ type='uint32',	purename='taskId',	default='0', 	ver=30, 		desc='����id', },
				{ type='uchar',	purename='state',	default='0', 	ver=30, 		desc='����״̬', },
				{ type='uint32',	purename='times',		default='0', 	ver=30, 			desc='��ɵ��������', },
				{ type='uint32',	purename='maxTimes',		default='0', 	ver=30, 			desc='����������������', },
				{ type='uint32',	purename='startTime',		default='0', 	ver=30, 			desc='����Ŀ�ʼʱ��', },
				{ type='uint32',	purename='stopTime',		default='0', 	ver=30, 			desc='����Ľ���ʱ��', },
			},	
		},
		
		--��Ծ�Ƚṹ
		{
			type = 'struct',
			name = 'SActivityVal',
			desc = '��Ծ�Ƚṹ',
			item = 
			{
				{ type='uint32',	purename='refreshActValTime',	default='0', 	ver=25, 		desc='�����Ծֵ��ˢ��ʱ��', },
				{ type='uint32',	purename='val',	default='0', 	ver=25, 		desc='�������еĻ�Ծֵ', },
				{ type='uint32',	purename='gotActRewardTime',	default='0', 	ver=25, 		desc='����ȡ�Ļ�Ծ�Ƚ�����ˢ��ʱ��', },
				{ type='uint32',	purename='gotActRewards', count='MAX_ACTREWARDS_CNT',  ver=25, desc='����ȡ�Ļ�Ծ�Ƚ���', },
				
				{ type='uint32',	purename='refreshSigninTime',	default='0', 	ver=25, 		desc='�����Ծֵ��ˢ��ʱ��', },
				{ type='uint8',	purename='todaySign', default='0', ver=25, desc='�����Ƿ���ǩ��', },				
				{ type='uint32',	purename='signinDaysTime', default='0', ver=25, desc='����ǩ��������ˢ��ʱ��', },
				{ type='uint8',	purename='signinDays', default='0', ver=25, desc='����ǩ������', },
				{ type='uint32',	purename='gotSigninRewardTime', default='0',  ver=25, desc='����ȡ��ǩ��������ˢ��ʱ��', },
				{ type='uint32',	purename='gotSigninRewards', count='MAX_SIGNINREWARDS_CNT',  ver=25, desc='����ȡ��ǩ������', },
				
				{ type='uint32',	purename='refreshTaskTime',	default='0', 	ver=25, 	desc='ˢ�������б��ʱ��', },
				{ type='int32',	purename='count',	default='0', 	ver=25, 	desc='�����б���', },
				{ type='SActValTask',	purename='tasks',	count='MAX_ACTVALTASKS_CNT', refer='count',	ver=25, 	desc='�����б�����', },
				
				{ type='uint32',	purename='gotOnlineGoodsTime',	default='0', 	ver=102, 	desc='���һ�λ�ȡ���߽��������ʱ��', },
				{ type='uint32',	purename='gotGoodsTimes',	default='0', 	ver=102, 	desc='���һ�λ�ȡ���߽�������Ĵ���', },
				{ type='uint32',	purename='gotSigninRewardsEx', count='MAX_SIGNINREWARDS_CNT_EX',  ver=125, desc='����ȡ��ǩ������', },
			},	
		},
		
		--�����콱����
		{
			type = 'struct',
			name = 'SOnlineTask',
			desc = '�����콱����',
			item = 
			{
				{ type='uint32',	purename='taskId',		default='0', 	ver=27, 		desc='����id', },
				{ type='uint32',	purename='startTime',	default='0', 	ver=27, 		desc='������ʼ��ʱ��', },
				{ type='uint32',	purename='lastTime',	default='0', 	ver=27, 		desc='�ϴ��Ѿ���¼��ʱ��', },
				{ type='uint32',	purename='lastLapsed',	default='0', 	ver=27, 		desc='�ϴ��Ѿ���¼�����ŵ�ʱ��', },
				{ type='uint8',	purename='isCircled',	default='0', 	ver=27, 		desc='�Ƿ��ѿ�ʼѭ������', },
			},	
		},
		
		--����ָ������
		{
			type = 'struct',
			name = 'SNewcomerTask',
			desc = '����ָ������',
			item = 
			{
				{ type='uint32',	purename='curTaskId',		default='0', 	ver=28, 		desc='��ǰ����id', },
				{ type='uint8',	purename='isEnd',		default='0', 	ver=123, 		desc='����ָ�������Ƿ����', },
				{ type='uint8',	purename='isGlobalTipEnd',		default='0', 	ver=124, 		desc='����ָ�������������ʾȫ�ֹ������', },
			},	
		},
		
		--����ָ������
		{
			type = 'struct',
			name = 'SYellowDiamondTask',
			desc = '��������',
			item = 
			{
				{ type='int8',	purename='gotNewgift',	default='0', 	ver=104, 	desc='�����������ȡ', },
				{ type='uint32',	purename='gotCommGift',	default='0', 	ver=104, 	desc='����ÿ���������ȡʱ��', },
				{ type='uint32',	purename='gotYearGift',	default='0', 	ver=104, 	desc='��ѻ���ÿ���������ȡʱ��', },
				{ type='int32',	purename='lvlCount',	default='0', 	ver=104, 	desc='����ȼ��������ȡid�б�ĸ���', },
				{ type='int8',	purename='gotLvlGifts',	count='MAX_YD_LVL_IDS_CNT', refer='lvlCount', 	ver=104, 	desc='����ȼ��������ȡid�б�', },
			},	
		},
		
		{
			type = 'struct',
			name = 'SBlueDiamondTask',
			desc = '��������',
			item = 
			{
				{ type='int8',	purename='gotNewgift',	default='0', 	ver=113, 	desc='�����������ȡ', },
				{ type='uint32',	purename='gotCommGift',	default='0', 	ver=113, 	desc='����ÿ���������ȡʱ��', },
				{ type='uint32',	purename='gotYearGift',	default='0', 	ver=113, 	desc='�������ÿ���������ȡʱ��', },
				{ type='uint32',	purename='gotHighGift',	default='0', 	ver=113, 	desc='��������ÿ���������ȡʱ��', },
				{ type='int32',	purename='lvlCount',	default='0', 	ver=113, 	desc='����ȼ��������ȡid�б�ĸ���', },
				{ type='int8',	purename='gotLvlGifts',	count='MAX_BD_LVL_IDS_CNT', refer='lvlCount', 	ver=113, 	desc='����ȼ��������ȡid�б�', },
				{ type='uint32',	purename='got3366Gift',	default='0', 	ver=113, 	desc='3366ÿ���������ȡʱ��', },
			},	
		},
		
		--��ֵ�
		{
			type = 'struct',
			name = 'SPayAct',
			desc = '��ֵ�',
			item = 
			{
				{ type='uint32',	purename='lastPayTime',	default='0', 	ver=108, 	desc='���һ�γ�ֵʱ��', },
				{ type='uint32',	purename='allGold',	default='0', 	ver=108, 	desc='���еĳ�ֵ��', },
				{ type='uint32',	purename='actAllGold',	default='0', 	ver=108, 	desc='���λ�ĳ�ֵ��', },
				{ type='uint8',	purename='giftGots', count='MAX_PAYACT_GIFT_CNT', ver=108, desc='�����ȡ���', },
			},	
		},		
		
		--����boss
		{
			type = 'struct',
			name = 'SWorldboss',
			desc = '����boss',
			item = 
			{
				{ type='uint8',	purename='times',		default='0', 	ver=116, 	desc='������ս����', },
				{ type='uint16',	purename='guwuLevel',	default='0', 	ver=116, 	desc='����ȼ�', },
				{ type='uint8',	purename='gotGift',	default='0', 	ver=116, 	desc='����Ľ����Ƿ���ȡ', },
				{ type='uint32',	purename='refreshTime',	default='0', 	ver=116, 	desc='ˢ��ʱ��', },
				{ type='uint32',	purename='getPersonRankGiftTime',	default='0', 	ver=117, 	desc='��ȡ����������Ʒ��ʱ��', },
				{ type='uint32',	purename='getCountryRankGiftTime',	default='0', 	ver=117, 	desc='��ȡ����������Ʒ��ʱ��', },
			},	
		},
		
		--���ͽ����Ļ
		{
			type = 'struct',
			name = 'SSendReward',
			desc = '���ͽ����Ļ',
			item = 
			{
				{ type='uint8',	purename='sendFirstHero',		default='0', 	ver=122, 	desc='�Ƿ��Ѿ��������׸��佫', },
			},	
		},
		
		--�������������б�
		{
			type = 'struct',
			name = 'STaskList',
			desc = '�������������б�',
			item = 
			{
				{ type='int32',	purename='count',	default='0', 	ver=1, 	desc='�����б���', },
				{ type='STask',	purename='tasks',	count='MAX_TASKS_CNT', refer='count',	ver=1, 	desc='�����б�����', },
				{ type='SDoingRoleTask',	purename='doingRoleTask',	 ver=20, 	desc='���ڽ����еľ�������', },
				{ type='uint32',	purename='refreshTime',	default='0', 	ver=21, 	desc='�ճ������б�ˢ��', },
				{ type='int32',	purename='everydayCount',	default='0', 	ver=21, 	desc='�ճ������б���', },
				{ type='STask',	purename='everydayTasks',	count='MAX_EVERYDAY_TASKS_CNT', refer='everydayCount',	ver=21, 	desc='�ճ������б�����', },
				{ type='uint32',	purename='prestigeLastTime',	default='0', 	ver=22, 	desc='������������һ��ʱ��', },				
				{ type='SActivityVal',	purename='activityVal',	ver=25, 	desc='��Ծ��', },
				{ type='SOnlineTask',	purename='onlineTask', ver=27, 	desc='�����콱����', },
				{ type='SNewcomerTask',	purename='newComerTask', ver=28, 	desc='����ָ������', },
				{ type='int32',	purename='actTaskCount',	default='0', 	ver=30, 	desc='������б���', },
				{ type='SActTask',	purename='actTasks',	count='MAX_ACT_TASKS_CNT', refer='actTaskCount',	ver=30,	desc='������б�����', },
				{ type='SYellowDiamondTask', purename='ydtasks',	ver=104, desc='��������', },
				{ type='SPayAct', purename='payAct',	ver=108, desc='��ֵ�', },
				{ type='SBlueDiamondTask', purename='bdtasks',	ver=113, desc='��������', },
				{ type='SWorldboss', purename='worldboss',	ver=116, desc='����boss', },
				{ type='SSendReward', purename='sendReward',	ver=122, desc='���ͽ����Ļ', },
			},	
		},
		
		--����ʿ���ṹ
		{
			type = 'struct',
			name = 'SSoldier',
			desc = '����ʿ���ṹ',
			item = 
			{
				{ type='uint32',		purename='resid',			default='0', 							ver=1, 	desc='ʿ����ԴID*1000+level', },
				{ type='uint32',		purename='number',		default='0', 							ver=1, 	desc='ʿ������', },
			},
		},		
		
		--��ս�ṹ
		{
			type = 'struct',
			name = 'SDeclare',
			desc = '��ս�ṹ',
			item = 
			{
				{ type='uchar',		purename='state',	default='0', 	ver=1, 	desc='״̬', },
				{ type='uint32',		purename='stoptime',	default='0', 	ver=1, 	desc='״̬������ʱ��', },
				{ type='uint64',		purename='id',		default='0', 	ver=1, 	desc='Ŀ��id', },
			},
		},
		
		--Ĭ��ս��
		{
			type = 'struct',
			name = 'SDefaultTeam',
			desc = 'Ĭ��ս��',
			item = 
			{
				{ type='uint32',		purename='lineupId',	default='0', 	ver=1, 	desc='����id', },
				{ type='uint64',		purename='heroIds',	count='MAX_DEFAULTTEAM_HERO_CNT',	ver=1, 	desc='�б���Ӣ��id', },
			},
		},
		
		--ÿ��ս��
		{
			type = 'struct',
			name = 'STodayFightTimes',
			desc = 'ÿ��ս��',
			item = 
			{
				{ type='uint32',		purename='taofa',		default='0', 	ver=1, 	desc='�ַ�����', },
				{ type='uint32',		purename='cuihui',		default='0', 	ver=1, 	desc='�ݻٴ���', },
				{ type='uint32',		purename='tiaoxin',		default='0', 	ver=1, 	desc='���ƴ���', },
				{ type='uint32',		purename='fightowner',	default='0', 	ver=1, 	desc='����Ұ����������', },
				{ type='uint32',		purename='lastTime',	default='0', 	ver=1, 	desc='�����һ��ʱ��', },
			},
		},
		
		--�����м�Ӣ�۽ṹ
		{
			type = 'struct',
			name = 'SSimpleHero',
			desc = '�����м�Ӣ�۽ṹ',
			item = 
			{
				{ type='uint64',		purename='id',	default='0', 	ver=1, 	desc='Ӣ��id', },
				{ type='string',		purename='name',				count='MAX_HERONAME_ARR_LEN',	ver=1, 	desc='Ӣ����', },
				{ type='uchar', 		purename='level', 				default='0', 								ver=1, 	desc='Ӣ�۵ȼ�', },		
				{ type='uchar',		purename='attrCount',		default='0', 	ver=1, 			desc='���Ը���', },
				{ type='SAttrEx',	purename='attrs',		count='MAX_SIMPLEHEROATTRS_CNT', 	refer='attrCount',	ver=1,	desc='����ֵ', },	--�����ȡ���������ս��			
				{ type='SSoldier',	purename='soldier', 															ver=1, 	desc='Я����ʿ��', },
				{ type='uchar', 		purename='lineupPos', 				default='0', 								ver=1, 	desc='�����е�վλ', },		
			},
		},
		
		--���ؾ���
		{
			type = 'struct',
			name = 'SDefArmy',
			desc = '���ؾ���',
			item = 
			{
				{ type='uint32',					purename='lineupId',					default='0', 								ver=1, 	desc='����id', },
				{ type='uchar',					purename='heroCount',				default='0', 								ver=1, 	desc='Ӣ�۸���', },				
				{ type='uint64',					purename='heros',	count='MAX_TEAM_HERO_CNT', refer='heroCount',	ver=1, 	desc='Ӣ���б�', },
			}
		},
		
		--��������
		{
			type = 'struct',
			name = 'STowerArmy',
			desc = '��������',
			item = 
			{
				{ type='SSoldier',				purename='soldiers',	count='MAX_TEAM_HERO_CNT', ver=1, 	desc='ÿ�������е�ʿ��', },
			}
		},
		
		--����Ĺ�ս����
		{
			type = 'struct',
			name = 'SFightTodayHonor',
			desc = '����Ĺ�ս����',
			item = 
			{
				{ type='uint32', 	purename='hasRefreshTime', 		default='0', 				ver=118, 	desc='�ɹ��׵ı��˴����ˢ��ʱ��', },
				{ type='uint32', 	purename='hasHonor', 		default='0', 				ver=118, 	desc='���컹ʣ�������', },
				{ type='uint32', 	purename='getRefreshTime', 		default='0', 				ver=118, 	desc='��õ�ˢ��ʱ��', },
				{ type='uint32', 	purename='getHonor', 		default='0', 				ver=118, 	desc='�����ѻ������', },
			}
		},
		
		--���½ṹ
		{
			type = 'struct',
			name = 'SMilitary',
			desc = '���½ṹ',
			item = 
			{
				{ type='uchar',					purename='favoriteCount',	default='0', 	ver=1, 	desc='�ղ�Ŀ�����', },
				{ type='uint64',					purename='favorites',	count='MAX_FAVORITE_CNT', refer='favoriteCount',	ver=1, 	desc='�ղ�Ŀ���б�', },
				
				{ type='uchar',					purename='enemyCount',	default='0', 	ver=1, 	desc='���˸���', },
				{ type='uint64',					purename='enemys',	count='MAX_ENEMY_CNT', refer='enemyCount',	ver=1, 	desc='�����б�', },
				
				{ type='uchar',					purename='lineupCount',	default='0', 	ver=1, 	desc='���͸���', },
				{ type='uint32',					purename='lineups',	count='MAX_LINEUP_CNT', refer='lineupCount',	ver=1, 	desc='����Ŀ���б�', },
				
				{ type='SDefaultTeam',		purename='defaultTeams',	count='MAX_DEFAULTTEAM_CNT',	ver=1, 	desc='Ĭ��ս���б�', },
				{ type='STodayFightTimes',	purename='todayFightTimes', ver=1, 	desc='ÿ��ս��', },
				
				{ type='uchar',					purename='selfArmyCount',	default='0', 	ver=1, 	desc='�ҵĳ������Ӹ���', },
				{ type='uint64',					purename='selfArmyIds', 		count='MAX_SELFARMY_CNT', refer='selfArmyCount', ver=1, 	desc='�ҵĳ��������б�', },
				
				{ type='uchar',					purename='enemyArmyCount',	default='0', 	ver=1, 	desc='�����ҷ����˾��Ӹ���', },
				{ type='uint64',					purename='enemyArmyIds', count='MAX_ENEMYARMY_CNT', refer='enemyArmyCount', ver=1, 	desc='�����ҷ����˾����б�', },
				
				{ type='uchar',					purename='alliArmyCount',	default='0', 	ver=1, 	desc='ͬ����ǲ���Ӹ���', },
				{ type='uint64',					purename='alliArmyIds', count='MAX_ALLIARMY_CNT', refer='alliArmyCount', ver=1, 	desc='ͬ����ǲ�����б�', },
				
				{ type='SDefArmy',				purename='defArmy',	ver=1, 	desc='���ؾ���', },
				{ type='STowerArmy',			purename='towerArmy',	ver=1, 	desc='��������', },
				
				{ type='uchar',					purename='succCopyFieldCount',	default='0', 	ver=2, 	desc='��ս�ɹ��ĸ�������', },
				{ type='uint32',					purename='succCopyFields',	count='MAX_SUCC_COPYFIELD_CNT', refer='succCopyFieldCount',	ver=2, 	desc='��ս�ɹ��ĸ���id�б�', },
				
				{ type='SFightTodayHonor',	purename='todayHonor',	ver=118, 	desc='����Ĺ�ս����', },
			},
		},
		
		{
			type = 'struct',
			name = 'SInviteJoinAlliance',
			desc = '����ṹ',
			item = 
			{
				{ type='uint64', 	purename='allianceId', 	default='0', 	ver=15, 	desc='����id', },
				{ type='uint64', 	purename='roleId', 		default='0', 	ver=15, 	desc='������id', },
			},
		},
		
		--����
		{
			type = 'struct',
			name = 'STradingArea',
			desc = '���̽ṹ',
			item = 
			{
				{ type='uint32', 	purename='stopTime', 	default='0', 				ver=16, 	desc='����ֹͣʱ��', },
				{ type='int32', 	purename='count', 		default='0', 				ver=16, 	desc='Ŀ�����', },
				{ type='uint64', 	purename='roleIds', 		count='MAX_TRADING_ROLES_CNT', refer='count',		ver=16, 	desc='Ŀ���ɫid�б�', },
				{ type='int32', 	purename='todayTimes', 		default='0', 				ver=24, 	desc='�������ܵĴ���', },
				{ type='uint32', 	purename='refreshTime', 		default='0', 				ver=24, 	desc='ˢ��ʱ��', },
				{ type='uint16', 	purename='curTimes', 		default='1', 				ver=112, 	desc='��ǰ���̵Ĵ���', },
			},
		},
		
		-- ǧ����
		{
			type = 'struct',
			name = 'SActTower',
			desc = 'ǧ����',
			item = 
			{
				{ type='uint32', 	purename='todayEnterTimes', 	default='0', 	ver=18, 	desc='�������Ĵ���', },
				{ type='uint32', 	purename='todayRefreshTime', 	default='0', 	ver=18, 	desc='���������ˢ��ʱ��', },
				{ type='uint32', 	purename='maxLayer', 	default='0', 	ver=18, 	desc='��ǰ��Ҵ�������߲�', },
				{ type='uint32', 	purename='leftLifes', 	default='0', 	ver=18, 	desc='��ǰ�ؿ�ʣ�������', },
				{ type='uint32', 	purename='stopTime', 	default='0', 	ver=18, 	desc='ս����ȴ�Ľ���ʱ��', },
				{ type='uint32', 	purename='curLayer', 	default='0', 	ver=18, 	desc='��ǰ���ڹ����¥��', },
				{ type='uint32', 	purename='maxTime', 	default='0', 	ver=19, 	desc='ͨ��������ʱ��ʱ��', },
				{ type='uint32', 	purename='autoStartTime', 	default='0', 	ver=120, 	desc='�Զ���ս�Ŀ�ʼʱ��', },
				{ type='uint16', 	purename='autoToLayer', 	default='0', 	ver=121, 	desc='�Զ���ս�����޲���', },
			},
		},
		
		-- �㽫̨�ؿ�
		{
			type = 'struct',
			name = 'SActTerraceGate',
			desc = '�㽫̨�ؿ�',
			item = 
			{
				{ type='uint32', 	purename='gateId', 	default='0', 	ver=18, 	desc='�ؿ�id', },
				{ type='uint32', 	purename='subGateId', 	default='0', 	ver=18, 	desc='�ӹؿ�id', },
			},
		},
		
		-- �㽫̨
		{
			type = 'struct',
			name = 'SActTerrace',
			desc = '�㽫̨',
			item = 
			{
				{ type='uint32', 	purename='todayEnterTimes', 	default='0', 	ver=18, 	desc='�������Ĵ���', },
				{ type='uint32', 	purename='todayRefreshTime', 	default='0', 	ver=18, 	desc='���������ˢ��ʱ��', },
				{ type='SActTerraceGate', 	purename='maxGate', ver=18, 	desc='��ǰ��Ҵ�������߹ؿ�', },
				{ type='uint32', 	purename='leftLifes', 	default='0', 	ver=18, 	desc='��ǰ�ؿ�ʣ�������', },
				{ type='uint32', 	purename='stopTime', 	default='0', 	ver=18, 	desc='ս����ȴ�Ľ���ʱ��', },
				{ type='SActTerraceGate', 	purename='curGate', ver=18, 	desc='��ǰ���ڹ���Ĺؿ�', },
				{ type='int32', 	purename='countResults',  default='0', 	 ver=18, 	desc='ͨ���˵Ĺؿ��������б��С', },
				{ type='uint8', 	purename='results', count='MAX_ACT_TERRACE_COUNT', refer='countResults', ver=18, 	desc='�����б�', },
				{ type='uint32', 	purename='autoStartTime', 	default='0', 	ver=120, 	desc='�Զ���ս�Ŀ�ʼʱ��', },
				{ type='uint16', 	purename='autoToSubGateId', 	default='0', 	ver=121, 	desc='�Զ���ս�������ӹ�', },
			},
		},
		
		{
			type = 'struct',
			name = 'SForceLineupCfg',
			desc = '�佫�������ͱ���ṹ',
			item = 
			{
				{ type='uint32', 	purename='type', 		default='0', 				ver=29, 	desc='����', },
				{ type='uint32', 	purename='lineup', 		default='0', 				ver=29, 	desc='����', },
				{ type='int8', 	purename='heroCount', 		default='0', 				ver=29, 	desc='�佫����', },
				{ type='uint64', 	purename='heroIds', count='MAX_TEAM_HERO_CNT', refer='heroCount', ver=29, 	desc='�佫id�б�', },
			},
		},
		
		{
			type = 'struct',
			name = 'SHelpTip',
			desc = '���ְ�����ʾ',
			item = 
			{
				{ type='uint32', 	purename='id', 		default='0', 				ver=127, 	desc='id', },
				{ type='uint8', 	purename='times', 		default='0', 				ver=127, 	desc='�Ѿ���ʾ�Ĵ���', },
			},
		},
		
		{
			type = 'struct',
			name = 'SPlayerClientCfg',
			desc = '��ҿͻ��˵�����',
			item = 
			{
				{ type='int8', 	purename='forceCount', 		default='0', 				ver=29, 	desc='�佫���ָ���', },
				{ type='SForceLineupCfg', 	purename='forces', count='MAX_FORCELINEUPCFG_CNT', refer='forceCount', ver=29, 	desc='�佫����', },
				{ type='uint8', 	purename='toggleMap', 		count='MAX_CTLCFG_BTIMAP_CNT', 		ver=107, 	desc='�ͻ��˵�һЩ����bitλ', },
				{ type='int32', 	purename='gonggaoVer', 		default='0', ver=119, 	desc='���һ����ҿ����Ĺ���汾��', },
				{ type='int16', purename='helpTipCount', default='0', ver=127, desc='���ְ���tip�ĸ���'},
				{ type='SHelpTip', purename='helpTips', count='MAX_HELPTIP_CNT', refer='helpTipCount', ver=127, desc='���ְ���tipid���б�', },
			},
		},
		
		{
			type = 'struct',
			name = 'SBuyLimitItem',
			desc = '�������޵ĵ���',
			item = 
			{
				{ type='uint32', 	purename='resId', 		default='0', 				ver=106, 	desc='����id', },
				{ type='uint32', 	purename='number', 		default='0', 				ver=106, 	desc='����', },
			},
		},
		
		--vip�ṹ
		{
			type = 'struct',
			name = 'SVip',
			desc = 'vip����',
			item = 
			{
				{ type='uint8',	purename='level',	default='0', ver=110, 	desc='�ȼ�', },
			},
		},

		-- cd key
		{
			type = 'struct',
			name = 'SCDKey',
			desc = 'cd key',
			item = 
			{
				{ type='int32',	purename='count', default='0', ver=115, 	desc='�������cdkey', },
				{ type='int16',	purename='types', count='MAX_CDKEY_CNT', refer='count', ver=115,	desc='�Ѿ������type', },
			},
		},
		
		--����ṹ
		{
			type = 'struct',
			name = 'SMiscs',
			desc = '����ṹ',
			item = 
			{
				{ type='SPlayerClientCfg',	purename='clientCfg',	 ver=29, 	desc='��ҿͻ��˵�����', },
				{ type='string',		purename='applyAlliance',	count='MAX_ALLINAME_ARR_LEN',	ver=15, 	desc='���������������', },
				{ type='uchar',		purename='inviteJoinAllianceCount',	default='0', 	ver=15, 	desc='�����Ҽ������˵ĸ���', },
				{ type='SInviteJoinAlliance',	purename='inviteJoinAlliances',	count='MAX_INVITE_JOIN_ALLI_CNT', refer='inviteJoinAllianceCount',	ver=15, 	desc='�����Ҽ������˵��б�', },
				{ type='STradingArea',	purename='trading',	 ver=16, 	desc='���̽ṹ', },
				{ type='SActTower',	purename='actTower',	 ver=18, 	desc='ǧ����', },
				{ type='SActTerrace',	purename='actTerrace',	 ver=18, 	desc='�㽫̨', },
				
				{ type='uint32',	purename='buyLimitTime', default='0', ver=106, 	desc='�������޵��ߵ�ʱ��', },
				{ type='int32',	purename='buyLimitCount',	 default='0', ver=106, 	desc='�������޵��ߵĸ���', },
				{ type='SBuyLimitItem',	purename='buyLimitItems',	 count='MAX_BUY_ITEMS_CNT', 	refer='buyLimitCount', ver=106, 	desc='�������޵ĵ���', },
				{ type='SVip',	purename='vip', ver=110, 	desc='vip����', },
				{ type='SCDKey',	purename='cdkey', ver=115, 	desc='cd key', },
			},
		},
		
		--����ʿ���б�ṹ
		{
			type = 'struct',
			name = 'SSoldierList',
			desc = '����ʿ���б�ṹ',
			item = 
			{
				{ type='uchar',		purename='count',		default='0', 										ver=1, 	desc='ʿ�����͸���', },
				{ type='SSoldier',	purename='soldiers',		count='MAX_SLDS_CNT', refer='count',	ver=1, 	desc='ʿ�����;�������', },
			},
		},
		
		--����Ӣ��Я��ʿ���ṹ
		{
			type = 'struct',
			name = 'SCarrySoldier',
			desc = '����Ӣ��Я��ʿ���ṹ',
			item = 
			{
				{ type='uint32',		name='ResId',				default='0', 							ver=1, 	desc='ʿ����ԴID', },
				{ type='uint32',		name='Number',			default='0', 							ver=1, 	desc='ʿ������', },
			},
		},
		
		--����Ӣ��Я��ʿ���б�ṹ
		{
			type = 'struct',
			name = 'SCarrySoldierList',
			desc = '����Ӣ��Я��ʿ���б�ṹ',
			item = 
			{
				{ type='uchar',			name='Count',		default='0', 							ver=1, 	desc='ʿ�����͸���', },
				{ type='SCarrySoldier',	name='Soldiers',	count='MAX_SLDS_CNT', refer='Count',	ver=1, 	desc='ʿ�����;�������', },
			},	
		},
		
		--Ӣ������ֵ�б�
		{
			type = 'struct',
			name = 'SHeroAttrList',
			desc = 'Ӣ������ֵ�б�',
			item = 
			{
				{ type='uchar',		name='Count',		default='0', 	ver=1, 			desc='���Ը���', },
				{ type='SAttr',		name='Attrs',		count='MAX_HEROATTRS_CNT', 	refer='Count',	ver=1,	desc='����ֵ', },
			},
		},
		
		--��������ֵ�б�
		{
			type = 'struct',
			name = 'SItemAttrList',
			desc = '��������ֵ�б�',
			item = 
			{
				{ type='uchar',		name='Count',		default='0', 													ver=1, 	desc='���Ը���', },
				{ type='SAttr',		name='Attrs',		count='MAX_ITEM_ATTRS_CNT', 	refer='Count',	ver=1,	desc='����ֵ', },
			},
		},
		
		--��Ƕ��ʯ�б�
		{
			type = 'struct',
			name = 'SGemBesetList',
			desc = '��Ƕ��ʯ�б�',
			item = 
			{
				{ type='uchar',	name='Count',		default='0', 													ver=3, 	desc='��ʯ����', },
				{ type='uint32',	name='Gems',		count='MAX_GEMBESET_CNT', 	refer='Count',		ver=3,	desc='��ʯresid�б�', },
			},
		},
		
		--����
		{
			type = 'struct',
			name = 'SItem',
			desc = '���ߣ�������ͨ��Ʒ��װ������ʯ�ȣ�',
			item = 
			{
				{ type='uint64',				name='Id',				default='0', 	ver=1,		desc='����ID', },
				{ type='uchar',				name='Type',			default='0', 	ver=1, 		desc='��������', },
				{ type='uint32',				name='ResId',			default='0', 	ver=1,		desc='������ԴID', },
				{ type='ushort',				name='Number',		default='0', 	ver=1, 		desc='���߶ѵ�����', },
				{ type='uchar',				name='ForceLevel',	default='0', 	ver=3, 		desc='ǿ���ȼ�', },
				{ type='SItemAttrList',		name='Attrs', 								ver=1, 		desc='�����б�', },
				{ type='SGemBesetList',	name='Gems', 								ver=3, 		desc='��ʯ�б�', },
			},
		},
		
		--��������ֵ�б�(��)
		{
			type = 'struct',
			name = 'SItemAttrListEx',
			desc = '��������ֵ�б�',
			item = 
			{
				{ type='uchar',		purename='count',		default='0', 													ver=1, 	desc='���Ը���', },
				{ type='SAttrEx',	purename='attrs',			count='MAX_ITEM_ATTRS_CNT', 	refer='count',	ver=1,	desc='����ֵ', },
			},
		},
		
		--��Ƕ��ʯ�б�(��)
		{
			type = 'struct',
			name = 'SGemBesetListEx',
			desc = '��Ƕ��ʯ�б�',
			item = 
			{
				{ type='uchar',	purename='count',		default='0', 													ver=3, 	desc='��ʯ����', },
				{ type='uint32',	purename='gems',		count='MAX_GEMBESET_CNT', 	refer='count',	ver=3,	desc='��ʯresid�б�', },
			},
		},
		
		--����(��)
		{
			type = 'struct',
			name = 'SItemEx',
			desc = '���ߣ�������ͨ��Ʒ��װ������ʯ�ȣ�',
			item = 
			{
				{ type='uint64',					purename='id',				default='0', 	ver=1,		desc='����ID', },
				{ type='uchar',					purename='type',			default='0', 	ver=1, 		desc='��������', },
				{ type='uchar',					purename='isRaw',		default='0', 	ver=5, 		desc='�����Ƿ��ѱ�����', },
				{ type='uchar',					purename='isBind',		default='0', 	ver=6, 		desc='�����Ƿ��Ѱ�', },
				{ type='uint32',					purename='resId',			default='0', 	ver=1,		desc='������ԴID', },
				{ type='ushort',					purename='number',		default='0', 	ver=1, 		desc='���߶ѵ�����', },
				{ type='uchar',					purename='forceLevel',	default='0', 	ver=3, 		desc='ǿ���ȼ�', },
				{ type='SItemAttrListEx',		purename='attrs', 							ver=1, 		desc='�����б�', },
				{ type='SGemBesetListEx',	purename='gems', 							ver=3, 		desc='��ʯ�б�', },
			},
		},
		
		--����װ��
		{
			type = 'struct',
			name = 'SWear',
			desc = '����װ��',
			item = 
			{
				{ type='uchar',				purename='armPos',		default='0', 	ver=1,	desc='װ��λ��', },
				{ type='SItemEx',			purename='arm',								ver=1,	desc='װ��', },
			},
		},
		
		--����װ���б�
		{
			type = 'struct',
			name = 'SWearList',
			desc = '����װ���б�',
			item = 
			{
				{ type='uchar',		purename='count',		default='0', 	ver=1, 			desc='װ������', },
				{ type='SWear',		purename='wears',		count='MAX_HEROWEAR_CNT', 	refer='count',	ver=1,	desc='װ��', },
			},
		},
		
		--�����б�ṹ
		{
			type = 'struct',
			name = 'SItemListEx',
			desc = '�����б�ṹ',
			item = 
			{
				{ type='ushort',			purename='count',		default='0', 									ver=4, 	desc='���߸�����', },
				{ type='SItemEx',		purename='items',		count='MAX_ITEMS_CNT', refer='count',	ver=4, 	desc='�����б�ľ�������', },
			},
		},	
		
		--��ɫ�������еĵ���
		{
			type = 'struct',
			name = 'SAllItems',
			desc = '��ɫ�������еĵ���',
			item = 
			{
				{ type='uint32',			name='GiftGold',		ver=1, 	default='0',		desc='����', },
				{ type='uint32',			name='Gold',			ver=1, 	default='0',		desc='���', },
				{ type='ushort',			name='GridMaxCnt',	ver=1, 	default='0',		desc='���������', },
				{ type='SItemListEx',	name='Items',			ver=4, 						desc='�����е���Ʒ', },
				{ type='uint32',			purename='lastSalveTime',		ver=14, 	default='0',		desc='���һ��ˢ��ҩ���ʱ��', },
			},
		},
		
		--����
		{
			type = 'struct',
			name = 'SSkill',
			desc = '����',
			item = 
			{
				{ type='uint32',		name='ResId',			default='0', 	ver=1, 			desc='������ԴID', },
				{ type='uchar',		name='Level',		default='0', 	ver=1, 			desc='���ܵȼ�', },
				{ type='uint32',		name='Dex',		default='0', 	ver=1, 			desc='��ǰ��������', },
			},
		},
		
		--�����б�
		{
			type = 'struct',
			name = 'SSkillList',
			desc = '�����б�',
			item = 
			{
				{ type='uchar',		name='Count',		default='0', 	ver=1, 			desc='���ܸ���', },
				{ type='SSkill',		name='Skills',		count='MAX_HERO_SKILL_CNT', 	refer='Count',	ver=1,	desc='����', },
			},
		},
		
		--���߿��
		{
			type = 'struct',
			name = 'SSCut',
			desc = '���߿��',
			item = 
			{
				{ type='uchar',		name='CutPos',	default='0', 	ver=1, 			desc='���߿��λ��', },
				{ type='uint32',		name='ResId',		default='0', 	ver=1, 			desc='�����ĵ�����Դid', },
			},
		},
		
		--���߿���б�
		{
			type = 'struct',
			name = 'SSCutList',
			desc = '���߿���б�',
			item = 
			{
				{ type='uchar',		name='Count',		default='0', 	ver=1, 			desc='��ݸ���', },
				{ type='SSCut',		name='SCuts',		count='MAX_HERO_SCUT_CNT', 	refer='Count',	ver=1,	desc='���', },
			},
		},
		
		--Ӣ�������ṹ
		{
			type = 'struct',
			name = 'OSHeroSteel',
			desc = 'Ӣ�������ṹ',
			item = 
			{
				{ type='uchar',		name='SteelType',		default='0', 	ver=1, 			desc='��������', },
				{ type='uint32',		name='StartTime',		default='0', 	ver=1, 			desc='��ʼ����ʱ�䣨��λ�룩', },
				{ type='uint32',		name='LastTime',			default='0', 	ver=1, 			desc='���һ�μ�����µ�����ʱ�䣨��λ�룩', },
				{ type='uchar',		name='Hours',				default='0', 	ver=1, 			desc='������Сʱ��', },
				{ type='uint64',		name='Exp',				default='0', 	ver=1, 			desc='�Ѿ���õľ���', },
				{ type='uint32',		name='TakeGold',			default='0', 	ver=1, 			desc='�Ѿ���õľ���', },
			},
		},
		
		--Ӣ�������ṹ
		{
			type = 'struct',
			name = 'SHeroSteel',
			desc = 'Ӣ�������ṹ',
			item = 
			{
				{ type='uchar',		purename='steelType',		default='0', 	ver=12, 			desc='��������', },
				{ type='uint32',		purename='startTime',		default='0', 	ver=12, 			desc='��ʼ����ʱ�䣨��λ�룩', },
				{ type='uchar',		purename='quarters',			default='0', 	ver=12, 			desc='������15������', },
				{ type='uint32',		purename='quarterRes',		default='0', 	ver=12, 			desc='һ���ӿɻ�õľ���', },
				{ type='uint32',		purename='quarterMoney',	default='0', 	ver=12, 			desc='һ�������ĵ�Ǯ��', },
				{ type='uint32',		purename='hourGold',		default='0', 	ver=12, 			desc='һСʱ���ĵĽ��', },
				{ type='uchar',		purename='actMult',		default='1', 	ver=103, 		desc='��ӳɵı���', },
			},
		},
		
		--Ӣ�۽ṹ
		{
			type = 'struct',
			name = 'SOHero',
			desc = 'Ӣ�۽ṹ',
			item = 
			{
				{ type='uint64',					name='Id',			default='0', 								ver=1, 		desc='Ӣ��Id', },
				{ type='uint32',					name='ResId',		default='0', 								ver=1, 		desc='Ӣ��ResId', },
				{ type='string',					name='Name',		count='MAX_HERONAME_ARR_LEN',	ver=1, 		desc='Ӣ����', },
				{ type='uchar', 					name='Level', 		default='0', 								ver=1, 		desc='Ӣ�۵ȼ�', },
				{ type='uint32', 					name='Exp', 		default='0', 								ver=1, 		desc='Ӣ�۾���', },
				{ type='uchar', 					name='State', 		default='0', 								ver=1, 		desc='Ӣ��״̬', },
				{ type='uint32', 					name='CityId', 	default='0', 								ver=1, 		desc='Ӣ�۵�ǰ���ڳ���id', },
				{ type='uint32', 					name='CityPosX', default='0', 									ver=1, 		desc='Ӣ�۵�ǰ���ڳ���ˮƽ����', },
				{ type='uint32', 					name='CityPosY', default='0', 									ver=1, 		desc='Ӣ�۵�ǰ���ڳ��д�ֱ����', },
				{ type='uint8', 					name='Subjects', count='MAX_SUBJECT_CNT',			ver=1, 		desc='Ӣ�۱����б�', },
				{ type='SCarrySoldierList',	name='Soldiers', 													ver=1, 		desc='Я����ʿ���б�', },
				{ type='SHeroAttrList',			name='Attrs', 														ver=1, 		desc='�����б�', },
				{ type='SWearList',				name='Wears', 													ver=1, 		desc='����װ���б�', },
				{ type='SSkillList',				name='Skills', 														ver=1, 		desc='�����б�', },
				{ type='SSCutList',				name='SCuts', 													ver=1, 		desc='���߿���б�', },
				{ type='SHeroSteel',			name='Steel', 														ver=1, 		desc='Ӣ������', },
			},
		},
		
		--Ӣ�ۼ��������ṹ
		{
			type = 'struct',
			name = 'SSkillSteel',
			desc = 'Ӣ�ۼ��������ṹ',
			item = 
			{
				{ type='uint32',					name='ResId',		default='0', 								ver=1, 		desc='����ResId', },
				{ type='uint32',					name='Stoptime',		default='0', 								ver=1, 		desc='������������ʱ��', },
				{ type='uint32',					name='Durtime',		default='0', 								ver=1, 		desc='����������ʱ������λСʱ', },
			},
		},
		
		--Ӣ�۽ṹ
		{
			type = 'struct',
			name = 'SHero',
			desc = 'Ӣ�۽ṹ',
			item = 
			{
				{ type='uint64',					name='Id',					default='0', 								ver=1, 	desc='Ӣ��Id', },
				{ type='uchar',					name='Prof',				default='0', 								ver=1, 	desc='Ӣ��ְҵ', },
				{ type='string',					name='Name',				count='MAX_HERONAME_ARR_LEN',	ver=1, 	desc='Ӣ����', },
				{ type='uchar', 					name='Level', 				default='0', 								ver=1, 	desc='Ӣ�۵ȼ�', },
				{ type='uchar', 					name='SkeletonLevel',	default='0', 								ver=1, 	desc='Ӣ������ȼ�', },
				{ type='uint32', 					name='SSteelStopTime',default='0', 								ver=1, 	desc='Ӣ����������ʱ��', },
				{ type='uint32', 					name='Icon', 				default='0', 								ver=1, 	desc='Ӣ��ͷ��', },
				{ type='uchar', 					name='Sex', 				default='0', 								ver=1, 	desc='Ӣ���Ա�', },
				{ type='uchar', 					name='State', 				default='0', 								ver=1, 	desc='Ӣ��״̬', },
				{ type='uchar', 					name='Official', 			default='0', 								ver=1, 	desc='Ӣ�۹�ְ', },
				{ type='uchar', 					name='LockState', 		default='0', 								ver=1, 	desc='����״̬', },
				{ type='uint32', 					name='UnlockTime', 		default='0', 								ver=1, 	desc='��������ʱ��', },
				{ type='uchar', 					name='Subjects', 		count='MAX_SUBJECT_CNT',			ver=1, 	desc='Ӣ�۱����б�', },
				{ type='SHeroAttrList',		name='Attrs', 																ver=1, 	desc='�����б�', },
				{ type='SSoldier',				name='Soldier', 															ver=1, 	desc='Я����ʿ��', },
				{ type='SWearList',			name='Wears', 															ver=1, 	desc='����װ���б�', },
				{ type='SSkillList',				name='Skills', 																ver=1, 	desc='�����б�', },
				{ type='uint32',					name='CurTacticSkill', 	default='0',									ver=1, 	desc='��ǰװ����ս�Լ���', },
				{ type='SHeroSteel',			name='Steel', 																ver=1, 	desc='Ӣ������', },
				{ type='SSkillSteel',			name='SkillSteel', 														ver=1, 	desc='Ӣ�ۼ�������', },
			},
		},
		
		--�ƹ��е�Ӣ��
		{
			type = 'struct',
			name = 'SNewHero',
			desc = '�ƹ��е�Ӣ��',
			item = 
			{
				{ type='uint32',			name='Id',				default='0', 															ver=1, 	desc='Id', },
				{ type='uchar',			name='Prof',			default='0', 															ver=1, 	desc='Ӣ��ְҵ', },
				{ type='string',			name='Name',			count='MAX_HERONAME_ARR_LEN',								ver=1, 	desc='Ӣ����', },
				{ type='uchar', 			name='Level', 			default='0', 															ver=1, 	desc='Ӣ�۵ȼ�', },
				{ type='uint32', 			name='Icon', 			default='0', 															ver=1, 	desc='Ӣ��ͷ��', },
				{ type='uchar', 			name='Sex', 			default='0', 															ver=1, 	desc='Ӣ���Ա�', },
				{ type='uchar',			name='AttrCount',	default='0', 															ver=1, 	desc='���Ը���', },
				{ type='SAttr',			name='Attrs',			count='MAX_NEWHEROATTRS_CNT', 	refer='AttrCount',	ver=1,	desc='����ֵ', },
			},
		},
		
		--Ӣ���б�ṹ 
		{
			type = 'struct',
			name = 'SHeroList',
			desc = 'Ӣ���б�ṹ',
			item = 
			{
				{ type='uint32',		name='HeroAttrLastTime',	default='0', 													ver=1, 	desc='Ӣ������ˢ�µ��ϴ�ʱ��', },
				{ type='uchar',		name='Count',					default='0', 													ver=1, 	desc='Ӣ�۸���', },
				{ type='SHero',		name='Heros',					count='MAX_HERO_CNT', refer='Count',				ver=1, 	desc='Ӣ�۾�������', },
				{ type='uint32',		name='CanUseSSTime',		default='0', 													ver=1, 	desc='��ʹ�õļ�������ʱ��', },
				{ type='uint32',		name='NewHeroLastTime',	default='0', 													ver=1, 	desc='�ƹ���Ӣ��ˢ�µ��ϴ�ʱ��', },
				{ type='uchar',		name='NewCount',			default='0', 													ver=1, 	desc='�ƹ���Ӣ�۸���', },
				{ type='SNewHero',	name='NewHeros',			count='MAX_NEWHERO_CNT', refer='NewCount',	ver=1, 	desc='�ƹ���Ӣ�۾�������', },
			},	
		},
		
		--ս���ṹ
		{
			type = 'struct',
			name = 'SBulletin',
			desc = 'ս���ṹ',
			item = 
			{
			},
		},
		
		-- ս���ṹ�б�
		{
			type = 'struct',
			name = 'SBulletinList',
			desc = 'ս���ṹ�б�',
			item = 
			{
				{ type='uchar',		name='Count',		default='0', 								ver=1, 	desc='ս������', },
				{ type='SBulletin',	name='Bulletins',	count='MAX_BULLETINS_CNT', refer='Count',	ver=1, 	desc='ս����������', },
			},	
		},
		
		--���ѽṹ
		{
			type = 'struct',
			name = 'SBuddy',
			desc = '���ѽṹ',
			item = 
			{
				{ type='uchar',		purename='flag',		default='0',	ver=1, 	desc='�������ͱ�־', },
				{ type='uint64',		purename='roleId',	default='0',	ver=1, 	desc='��ɫid', },
			},
		},
		
		-- ���ѽṹ�б�
		{
			type = 'struct',
			name = 'SBuddyList',
			desc = '���ѽṹ�б�',
			item = 
			{
				{ type='ushort',	purename='count',				default='0', 										ver=1, 	desc='���Ѹ���', },
				{ type='SBuddy',	purename='buddys',				count='MAX_BUDDYS_CNT', 			refer='count',	ver=1, 	desc='���Ѿ�������', },
				{ type='ushort',	purename='applyCount',		default='0', 										ver=1, 	desc='�������', },
				{ type='uint64',	purename='applyRoleIds',	count='MAX_BUDDYS_APPLY_CNT', 	refer='applyCount',	ver=1, 	desc='�����б�', },
			},
		},
		
		-- ũ���ṹ�б�
		{
			type = 'struct',
			name = 'SFarm',
			desc = 'ũ���ṹ',
			item = 
			{
				{ type='uint32',	name='Id',							default='0', 				ver=1, 	desc='ũ��λ��Id', },
				{ type='uint32',	name='ResId',						default='0', 				ver=1, 	desc='ũ����ԴId', },
				{ type='uchar',	name='Level',						default='1', 				ver=1, 	desc='��Դ�ȼ�', },
				{ type='uchar',	name='State',						default='0', 				ver=1, 	desc='��Դ�ɳ�״̬', },
				{ type='uint32',	name='StartTime',					default='0', 				ver=1, 	desc='��Դ�ɳ�����ʼʱ��', },
				{ type='uint32',	name='StopTime',					default='0', 				ver=1, 	desc='��Դ��ʱ�ɳ����', },
				{ type='uint32',	name='TotalRes',					default='0', 				ver=1, 	desc='��Դ�ɳ���ɺ�ɲɼ����ܵ�����', },
				{ type='uint32',	name='LeftRes',						default='0', 				ver=1, 	desc='��Դ�ɳ���ɺ�ɲɼ���ʣ�������', },
				{ type='uchar',	purename='collectorCount',	default='0', 				ver=9, 	desc='�ɼ�������', },
				{ type='uint64',	purename='collectors',			count='MAX_COLLECTOR_CNT', 	refer='collectorCount', ver=9, desc='�ɼ���id�б�', },
				{ type='uint32',	purename='seqId',				default='0', 				ver=100, 	desc='ũ����ԴseqId', },				
				{ type='uint32',	purename='protectStopTime',				default='0', 				ver=110, 	desc='ũ����ԴseqId', },				
			},
		},
		
		-- ũ����¼�ṹ�б�
		{
			type = 'struct',
			name = 'SFarmLog',
			desc = 'ũ����¼�ṹ',
			item = 
			{
				{ type='uchar',	name='Type',		default='0', 								ver=1, 	desc='��¼����', },
				{ type='string',	name='RName',	count='MAX_ROLENAME_ARR_LEN',	ver=1, 	desc='��ɫ��', },
				{ type='uint32',	name='LogTime',	default='0', 								ver=1, 	desc='��¼��־��ʱ��', },
				{ type='uint32',	name='Param1',	default='0', 								ver=1, 	desc='��¼����1', },
				{ type='uint32',	name='Param2',	default='0', 								ver=1, 	desc='��¼����2', },
				{ type='uint32',	name='Param3',	default='0', 								ver=1, 	desc='��¼����3', },
				{ type='uint32',	name='Param4',	default='0', 								ver=1, 	desc='��¼����4', },
			},
		},
		
		-- ũ���ṹ�б�
		{
			type = 'struct',
			name = 'SFarmList',
			desc = 'ũ���ṹ�б�',
			item = 
			{
				{ type='uchar',			name='Count',			default='0', 													ver=1, 	desc='ũ������', },
				{ type='SFarm',			name='Farms',			count='MAX_FARM_CNT', 			refer='Count',		ver=1, 	desc='ũ����������', },
				
				{ type='uint32',			name='LogVer',			default='0', 													ver=1, 	desc='��¼��İ汾��', },
				{ type='uchar',			name='LogCount',		default='0', 													ver=1, 	desc='ũ��������¼����', },
				{ type='SFarmLog',	name='FarmLogs',		count='MAX_FARM_LOG_CNT', 	refer='LogCount',	ver=1, 	desc='ũ�������¼', },
				
				{ type='uint32',			purename='farmVer',	default='0', 													ver=9, 	desc='ũ���İ汾��', },
				{ type='uint32',			purename='lastSeqId',	default='0', 													ver=100, 	desc='�ؿ����һ�ε�seqId', },
			},
		},
		
		-- �Ƽ�
		{
			type = 'struct',
			name = 'SCulture',
			desc = '�Ƽ�',
			item = 
			{
				{ type='uchar',		purename='level',		default='0', 													ver=1, 	desc='�Ƽ��ȼ�', },
				{ type='uint32',		purename='id',			default='0', 													ver=1, 	desc='�Ƽ���Դid', },
			},
		},
		
		--�����о��ĿƼ�
		{
			type = 'struct',
			name = 'SLearningCulture',
			desc = '�����о��ĿƼ�',
			item = 
			{
				{ type='uint32',		purename='id',				default='0', 													ver=1, 	desc='�Ƽ�id', },
				{ type='uint32',		purename='stoptime',	default='0', 													ver=1, 	desc='ֹͣʱ��', },
			},
		},
		
		-- �Ƽ��б�
		{
			type = 'struct',
			name = 'SCultures',
			desc = '�Ƽ��б�',
			item = 
			{
				{ type='uchar',					purename='count',			default='0', 													ver=1, 	desc='�Ƽ�����', },
				{ type='SCulture',				purename='cultures',			count='MAX_CULTURE_CNT', 		refer='count',		ver=1, 	desc='�Ƽ���������', },
				{ type='SLearningCulture',	purename='learning',																				ver=1, 	desc='�����о��ĿƼ�', },
			},
		},
		
		----------------------------------
		-- SDBVar �Ķ���
		----------------------------------
		{
			type = 'struct',
			name = 'SDBVar',
			binddb = 'roles',
			desc = '��־û�����Ľ�ɫ����',
			item = 
			{
				{ type='uint64',			name='RoleId',		default='0', 								dbfield='roleid',		dbupd='key',		ver=1, 		desc='��ɫΨһid', },
				{ type='string',			name='UName',	count='MAX_USERNAME_ARR_LEN',	dbfield='uname',		dbupd='',		ver=1, 		desc='�û���', },
				{ type='string',			name='RName',	count='MAX_ROLENAME_ARR_LEN',	dbfield='rname',		dbupd='',		ver=1, 		desc='��ɫ��', },
				{ type='uchar',			name='Sex',		default='0', 								dbfield='sex',			dbupd='',		ver=1, 		desc='�Ա�', },
				{ type='SFixVar',			name='FixVar',														dbfield='bfixvars',		dbupd='val',		ver=1, 		desc='�־ò��������', },
				{ type='SBaseInfo',		name='BInfos',														dbfield='bbinfos',		dbupd='val',		ver=1, 		desc='��ɫ��һЩ��������', },
				{ type='SHeroList',		name='Heros',														dbfield='bheros',		dbupd='val',		ver=1, 		desc='Ӣ���б�', },
				{ type='SSoldierList',	purename='soldiers',												dbfield='bsoldiers',	dbupd='val',		ver=1, 		desc='ʿ���б�', },
				{ type='SCitys',			name='Citys',														dbfield='bcitys',		dbupd='val',		ver=1, 		desc='�����б�', },
				{ type='SFarmList',		name='Farms',														dbfield='bfarms',		dbupd='val',		ver=1, 		desc='ũ���б�', },
				{ type='SCultures',		purename='cultures',												dbfield='bcultures',	dbupd='val',		ver=1, 		desc='�Ƽ��б�', },
				{ type='SAllItems',		name='Items',														dbfield='bitems',		dbupd='val',		ver=1, 		desc='�����б�', },
				{ type='SStateList',		purename='states',												dbfield='bbuffs',		dbupd='val',		ver=1, 		desc='buff�б�', },
				{ type='SMilitary',		purename='military',												dbfield='bmilitary', 	dbupd='val',		ver=1, 		desc='������Ϣ', },
				{ type='STaskList',		purename='tasks',														dbfield='btasks',		dbupd='val',		ver=1, 		desc='�����б�', },
				{ type='SBulletinList',	name='Bulletins',													dbfield='bbulletins',	dbupd='val',		ver=1, 		desc='ս���б�', },
				{ type='SBuddyList',	purename='buddys',												dbfield='bbuddys', 	dbupd='val',		ver=1, 		desc='�����б�', },
				{ type='SMiscs',			name='Miscs',														dbfield='bmiscs',		dbupd='val',		ver=1, 		desc='����ṹ', },
				{ type='uint32',			purename='regTime',		default='0', 						dbfield='regtime',			dbupd='',		ver=23, 		desc='��ɫ����ʱ��', },
				{ type='uint32',			purename='lockToTime',		default='0', 				dbfield='locktotime',		dbupd='val',		ver=114, 	desc='��Ž�ֹʱ��', },
			},
		},
		

		----------------------------------
		-- SDBAlliVar �Ķ���
		----------------------------------
		{
			type = 'struct',
			name = 'SDBAlliVar',
			binddb = 'alliances',
			desc = '��־û��������������',
			item = 
			{
				{ type='uint64',		name='allianceId',		default='0', 									dbfield='allianceId', dbupd='key',		ver=1, 		desc='����Ψһid', },
			},
		},
	},
	
	--һЩconst�ַ��������
	const_str = 
	{
		{
			name = 'sc_lpszLoginSql',
			str = 'select * from roles where uname=\'%s\';',
		},
		
		{
			name = 'sc_lpszGetLastRoleAutoId',
			str = 'select id from roles order by id desc limit 1;',
		},
		
		{
			name = 'sc_lpszFindRoleNameExist',
			str = 'select id from roles where rname=\'%s\';',
		},
		
		{
			name = 'sc_lpszFindUserNameExist',
			str = 'select id from roles where uname=\'%s\';',
		},
		
		{
			name = 'sc_lpszGetAlliById',
			str = 'select id from alliances where uid=%I64u;',
		},
	},
	
	--�������ݿ⺯��
	outfun={
		{
			dbtablename='roles', 
			vardef='SDBVar*', 
			funname={getvar='RoleVarInitRoleFromDB', 
				convertvar='VarConvertRoleFieldToBlob', 
				updatevar='VarUpdateRoleIntoDB', 
				insertvar='VarInsertRoleIntoDB'}
		},
		{
			dbtablename='alliances', 
			vardef='SDBAlliVar*', 
			funname={getvar='AlliVarInitAlliFromDB', 
				convertvar='VarConvertAlliFieldToBlob', 
				updatevar='VarUpdateAlliIntoDB', 
				insertvar='VarInsertAlliIntoDB'}
		},
	},
}

--��������
if package.loaded['role_define'] == nil then
	require('lua_tool.tools_h')
	output_h(g_role, g_dbtb)
end