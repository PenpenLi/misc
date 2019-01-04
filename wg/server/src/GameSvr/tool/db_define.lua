-------------------------------------------
--�����������ݿ�ı�ṹ
-------------------------------------------
--[[
ALTER TABLE tablename ADD newfield bigint(20) unsigned NOT NULL DEFAULT 0 AFTER beforefieldname;
ALTER TABLE tablename DROP fieldname;
ALTER TABLE �������֡� CHANGE �������ơ����������ơ� int(10) unsigned NOT NULL


ALTER TABLE alliances ADD lastLevel int(10) unsigned NOT NULL DEFAULT 0 AFTER createTime;
ALTER TABLE alliances ADD lastHonour int(10) unsigned NOT NULL DEFAULT 0 AFTER lastLevel;
ALTER TABLE alliances ADD rank int(10) unsigned NOT NULL DEFAULT 0 AFTER lastHonour;

]]

--���ݿ��ֶζ���
g_dbtb = 
{
	zone_id = 1,
	
	----------------
	--��ɫ����
	{
		name = 'roles', -- role_table
		table_id = 0,
		table_name = 'roles',
		output_file = 'c:/myweb/sql/roles.sql',
		{
			field = 'id',
			attr = 'int(10) unsigned NOT NULL auto_increment',
			keytype = 'UNIQUE',
			desc = '�����ӵ�id',
			default_fill = {flag='const', fmt='\\"\\"'},
		},
		
		{
			field = 'roleid',
			attr = 'bigint(20) unsigned NOT NULL',
			keytype = 'UNIQUE',
			desc = '��ɫΨһid',
		},
		
		{
			field = 'uname',
			attr = 'varchar(32) NOT NULL',
			keytype = 'UNIQUE',
			desc = '�û���', 
		},
		
		{
			field = 'rname',
			attr = 'varchar(21) NOT NULL',
			keytype = 'PRIMARY',
			desc = '��ɫ��',
		},
		
		{
			field = 'sex',
			attr = 'tinyint(3) unsigned NOT NULL',
			desc = '�Ա�',
		},
		
		{
			field = 'bfixvars',
			attr = 'BLOB',
			desc = '�̶�����',
		},
		
		{
			field = 'bbinfos',
			attr = 'BLOB',
			desc = '�����ɱ�����',
		},
		
		{
			field = 'bmilitary',
			attr = 'BLOB',
			desc = '������Ϣ',
		},		
		
		{
			field = 'bheros',
			attr = 'BLOB',
			desc = 'Ӣ��',
		},
		
		{
			field = 'bsoldiers',
			attr = 'BLOB',
			desc = 'ʿ��',
		},
		
		{
			field = 'bcitys',
			attr = 'BLOB',
			desc = '�����б�',
		},
		
		{
			field = 'bfarms',
			attr = 'BLOB',
			desc = 'ũ��',
		},
		
		{
			field = 'bcultures',
			attr = 'BLOB',
			desc = '�Ƽ�',
		},

		{
			field = 'bitems',
			attr = 'BLOB',
			desc = '�����б�',
		},
		
		{
			field = 'bbuffs',
			attr = 'BLOB',
			desc = '�����б�',
		},
		
		{
			field = 'btasks',
			attr = 'BLOB',
			desc = '�����б�',
		},
		
		{
			field = 'bbulletins',
			attr = 'BLOB',
			desc = 'ս���б�',
		},
		
		{
			field = 'bbuddys',
			attr = 'BLOB',
			desc = '�����б�',
		},
		
		{
			field = 'bmiscs',
			attr = 'BLOB',
			desc = '��������',
		},
		
		{
			field = 'regtime',
			attr = 'int(10) unsigned NOT NULL',
			desc = 'ע��ʱ��',
		},
		
		{
			field = 'locktotime',
			attr = 'int(10) unsigned',
			desc = '�ý�ɫ����Ľ�ֹʱ��',
		},
	},
	
	---------------------
	--Ұ���ͼ���Ӷ���
	{
		name = 'mapgrids',
		table_name = 'mapgrids',
		output_file = 'c:/myweb/sql/mapgrids.sql',
		{
			field = 'gridId',
			attr = 'int(10) unsigned NOT NULL',
			keytype = 'PRIMARY',
			desc = '���ӱ��',
		},
		
		{
			field = 'objType',
			attr = 'tinyint(3) unsigned NOT NULL',
			desc = '�������ͣ���ҡ�Ұ�ء�npc�ǡ��յأ�',
		},
		
		{
			field = 'resId',
			attr = 'int(10) unsigned NOT NULL',
			desc = '����������Ұ�ء�npc��ʱ����Ӧ����Դid',
		},
		
		{
			field = 'modelId', --@modelId
			attr = 'int(10) unsigned NOT NULL',
			desc = '��Ӧ��ģ��id',
		},
		
		{
			field = 'subCitys', --@subCitys
			attr = 'varchar(30) NOT NULL',
			desc = '�ֳ�ID�б��ַ�������ʽ�磺 170001,170001,170001,170001 ',
		},
		
		{
			field = 'roleId',
			attr = 'bigint(20) unsigned NOT NULL',
			desc = '��ɫ��id',
		},
		
		{
			field = 'roleName',
			attr = 'varchar(21) NOT NULL',
			desc = '��ɫ����',
		},
		
		{
			field = 'userName',
			attr = 'varchar(32) NOT NULL',
			desc = '�û�����',
		},
		
		{
			field = 'icon',
			attr = 'tinyint(3) unsigned NOT NULL',
			desc = '��ɫͷ��',
		},
		
		{
			field = 'level',
			attr = 'tinyint(3) unsigned NOT NULL',
			desc = '�ȼ�',
		},
		
		{
			field = 'sex',
			attr = 'tinyint(3) unsigned NOT NULL',
			desc = '�Ա�',
		},
		
		{
			field = 'state',
			attr = 'tinyint(3) unsigned NOT NULL',
			desc = '����״̬',
		},
		
		{
			field = 'allianceId',
			attr = 'bigint(20) unsigned NOT NULL',
			desc = '����id',
		},
		
		{
			field = 'enemyAlliId',
			attr = 'bigint(20) unsigned NOT NULL',
			desc = '��������id',
		},
		
		{
			field = 'refreshTime',
			attr = 'int(10) unsigned NOT NULL',
			desc = '�ϴ�ˢ��ʱ��',
		},
		
		{
			field = 'alliName',
			attr = 'varchar(21) NOT NULL',
			desc = '��������',
		},
		
		{
			field = 'cityLevel',
			attr = 'tinyint(3) unsigned NOT NULL',
			desc = '�ǳصȼ�',
		},
		
		{
			field = 'buildCurVal',
			attr = 'int(10) unsigned NOT NULL',
			desc = '�����',
		},
		
		{
			field = 'roleRank',
			attr = 'int(10) unsigned NOT NULL',
			desc = '��ɫ����',
		},
		
		{
			field = 'introduction',
			attr = 'varchar(51) NOT NULL',
			desc = '���˼��',
		},
		
		{
			field = 'loginTime',
			attr = 'int(10) unsigned NOT NULL',
			desc = '�����¼ʱ��',
		},
		
		{
			field = 'misc',
			attr = 'BLOB',
			desc = '����',
		},		
	},
	
	---------------------------
	--����Ұ���ͼ���Ӷ���
	{
		name = 'exilegrids',
		table_name = 'exilegrids',
		output_file = 'c:/myweb/sql/exilegrids.sql',
		{
			field = 'gridId',
			attr = 'int(10) NOT NULL',
			desc = '����ʱ�ĸ��ӱ��',
		},
		
		{
			field = 'objType',
			attr = 'tinyint(3) unsigned NOT NULL',
			desc = '�������ͣ���ҡ�Ұ�ء�npc�ǡ��յأ�',
		},
		
		{
			field = 'resId',
			attr = 'int(10) unsigned NOT NULL',
			desc = '����������Ұ�ء�npc��ʱ����Ӧ����Դid',
		},
		
		{
			field = 'modelId', --@modelId
			attr = 'int(10) unsigned NOT NULL',
			desc = '��Ӧ��ģ��id',
		},
		
		{
			field = 'subCitys', --@subCitys
			attr = 'varchar(30) NOT NULL',
			desc = '�ֳ�ID�б��ַ�������ʽ�磺 170001,170001,170001,170001 ',
		},
		
		{
			field = 'roleId',
			attr = 'bigint(20) unsigned NOT NULL',
			keytype = 'PRIMARY',
			desc = '��ɫ��id',
		},
		
		{
			field = 'roleName',
			attr = 'varchar(21) NOT NULL',
			desc = '��ɫ����',
		},
		
		{
			field = 'userName',
			attr = 'varchar(32) NOT NULL',
			desc = '�û�����',
		},
		
		{
			field = 'icon',
			attr = 'tinyint(3) unsigned NOT NULL',
			desc = '��ɫͷ��',
		},
		
		{
			field = 'level',
			attr = 'tinyint(3) unsigned NOT NULL',
			desc = '�ȼ�',
		},
		
		{
			field = 'sex',
			attr = 'tinyint(3) unsigned NOT NULL',
			desc = '�Ա�',
		},
		
		{
			field = 'state',
			attr = 'tinyint(3) unsigned NOT NULL',
			desc = '����״̬',
		},
		
		{
			field = 'allianceId',
			attr = 'bigint(20) unsigned NOT NULL',
			desc = '����id',
		},
		
		{
			field = 'enemyAlliId',
			attr = 'bigint(20) unsigned NOT NULL',
			desc = '��������id',
		},
		
		{
			field = 'refreshTime',
			attr = 'int(10) unsigned NOT NULL',
			desc = '�ϴ�ˢ��ʱ��',
		},
		
		{
			field = 'alliName',
			attr = 'varchar(21) NOT NULL',
			desc = '��������',
		},
		
		{
			field = 'cityLevel',
			attr = 'tinyint(3) unsigned NOT NULL',
			desc = '�ǳصȼ�',
		},
		
		{
			field = 'buildCurVal',
			attr = 'int(10) unsigned NOT NULL',
			desc = '�����',
		},
		
		{
			field = 'roleRank',
			attr = 'int(10) unsigned NOT NULL',
			desc = '��ɫ����',
		},
		
		{
			field = 'introduction',
			attr = 'varchar(51) NOT NULL',
			desc = '���˼��',
		},
		
		{
			field = 'loginTime',
			attr = 'int(10) unsigned NOT NULL',
			desc = '�����¼ʱ��',
		},
		
		{
			field = 'misc',
			attr = 'varchar(2) NOT NULL', -- ����ֻ��� �г��ȼ�
			desc = '����',
		},	
	},	
	
	----------------
	--���ӱ��
	{
		name = 'armys',
		table_name = 'armys',
		output_file = 'c:/myweb/sql/armys.sql',
		{
			field = 'armyId',
			attr = 'bigint(20) unsigned NOT NULL',
			keytype = 'PRIMARY',
			desc = '��������ID',
		},
		
		{
			field = 'sourceId',
			attr = 'bigint(20) unsigned NOT NULL',
			desc = '������id',
		},
		
		{
			field = 'sourceType',
			attr = 'tinyint(3) unsigned NOT NULL',
			desc = '����������',
		},
		
		{
			field = 'targetId',
			attr = 'bigint(20) unsigned NOT NULL',
			desc = 'Ŀ��id',
		},
		
		{
			field = 'targetType',
			attr = 'tinyint(3) unsigned NOT NULL',
			desc = 'Ŀ��������',
		},
		
		{
			field = 'expedType',
			attr = 'tinyint(3) unsigned NOT NULL',
			desc = '��������',
		},
		
		{
			field = 'lineupId',
			attr = 'int(10) unsigned NOT NULL',
			desc = '����ID',
		},
		
		{
			field = 'simpleHeros',
			attr = 'BLOB  NOT NULL',
			desc = '����Ӣ�������б�',
		},
		
		{
			field = 'state',
			attr = 'tinyint(3) unsigned NOT NULL',
			desc = '����״̬',
		},
		
		{
			field = 'startTime',
			attr = 'int(10) unsigned NOT NULL',
			desc = '���ӿ�ʼʱ��',
		},
		
		{
			field = 'needTime',
			attr = 'int(10) unsigned NOT NULL',
			desc = '���ӳ�����Ҫ�Ļ���ʱ��',
		},		
		
		{
			field = 'stopTime',
			attr = 'int(10) unsigned NOT NULL',
			desc = '���ӽ���ʱ��',
		},
		
		{
			field = 'fighted',
			attr = 'tinyint(3) unsigned NOT NULL',
			desc = '�Ƿ�����ս��',
		},
		
		{
			field = 'buff',
			attr = 'BLOB  NOT NULL',
			desc = '�þ����е�buff',
		},
	},
	
	
	----------------
	--�ʼ����
	{
		name = 'mails',
		table_name = 'mails',
		output_file = 'c:/myweb/sql/mails.sql',
		{
			field = 'mailId',
			attr = 'bigint(20) unsigned NOT NULL',
			keytype = 'PRIMARY',
			desc = '�ʼ�ID',
		},
		
		{
			field = 'receiver',
			attr = 'varchar(21) NOT NULL',
			desc = '������',
		},	
		
		{
			field = 'sender',
			attr = 'varchar(21) NOT NULL',
			desc = '������',
		},
		
		{
			field = 'isSys',
			attr = 'tinyint(3) unsigned NOT NULL',
			desc = '�Ƿ�Ϊϵͳ�ʼ�',
		},		
		
		{
			field = 'isRead',
			attr = 'tinyint(3) unsigned NOT NULL',
			desc = '�Ƿ��Ѷ�',
		},
		
		{
			field = 'title',
			attr = 'varchar(45) NOT NULL',
			desc = '����',
		},	
		
		{
			field = 'tempId',
			attr = 'int(10) unsigned NOT NULL',
			desc = '�ʼ�����ģ��Id',
		},
		
		{
			field = 'bcontent',
			attr = 'BLOB',
			desc = '�ʼ�����',
		},
		
		{
			field = 'itemCount',
			attr = 'tinyint(3) unsigned NOT NULL',
			desc = '������������',
		},		
		
		{
			field = 'bpkg',
			attr = 'BLOB',
			desc = '�ʼ�����',
		},
		
		{
			field = 'addTime',
			attr = 'int(10) unsigned NOT NULL',
			desc = 'ʱ��',
		},	
	},
	
	----------------
	--���˱��
	{
		name = 'alliances',
		table_name = 'alliances',
		output_file = 'c:/myweb/sql/alliances.sql',
		{
			field = 'allianceId',
			attr = 'bigint(20) unsigned NOT NULL',
			keytype = 'PRIMARY',
			desc = '����ID',
		},
		
		{
			field = 'level',
			attr = 'tinyint(3) unsigned NOT NULL',
			desc = '�ȼ�',
		},
		
		{
			field = 'name',
			attr = 'varchar(21) NOT NULL',
			desc = '��������', 
		},
		
		{
			field = 'flagName',
			attr = 'varchar(3) NOT NULL',
			desc = '�������', 
		},
		
		{
			field = 'cityResId',
			attr = 'int(10) unsigned NOT NULL',
			desc = '�ݳ�resid',
		},

		{
			field = 'honour',
			attr = 'int(10) unsigned NOT NULL',
			desc = '����',
		},		
		
		{
			field = 'leader',
			attr = 'varchar(21) NOT NULL',
			desc = '����', 
		},

		{
			field = 'buildVal',
			attr = 'int(10) unsigned NOT NULL',
			desc = '����', 
		},
		
		{
			field = 'card',
			attr = 'int(10) unsigned NOT NULL',
			desc = '����', 
		},
		
		{
			field = 'qqGroup',
			attr = 'varchar(11) NOT NULL',
			desc = 'qqȺ', 
		},
		
		{
			field = 'introduction',
			attr = 'varchar(600) NOT NULL',
			desc = 'Ⱥ����', 
		},
		
		{
			field = 'bulletin',
			attr = 'varchar(600) NOT NULL',
			desc = 'Ⱥ�ڹ���', 
		},
		
		{
			field = 'member',
			attr = 'BLOB NOT NULL',
			desc = '���˳�Ա', 
		},
		
		{
			field = 'lawLight',
			attr = 'BLOB NOT NULL',
			desc = '����', 
		},
		
		{
			field = 'misc',
			attr = 'BLOB NOT NULL',
			desc = '��������',
		},
		
		{
			field = 'createTime',
			attr = 'int(10) unsigned NOT NULL',
			desc = 'ʱ��',
		},
		
		{
			field = 'lastLevel',
			attr = 'int(10) unsigned NOT NULL',
			desc = '���˵ȼ�',
		},
		{
			field = 'lastHonour',
			attr = 'int(10) unsigned NOT NULL',
			desc = '��������',
		},
		{
			field = 'rank',
			attr = 'int(10) unsigned NOT NULL',
			desc = '��������',
		},	
	},
	
	----------------
	--���˱��
	{
		name = 'allianceevents',
		table_name = 'allianceevents',
		output_file = 'c:/myweb/sql/allianceevents.sql',
		{
			field = 'id',
			attr = 'int(10) unsigned NOT NULL auto_increment',
			keytype = 'PRIMARY',
			desc = 'id',
		},
		
		{
			field = 'allianceId',
			attr = 'bigint(20) unsigned NOT NULL',
			desc = '����ID',
		},
		
		{
			field = 'event',
			attr = 'varchar(255) NOT NULL',
			desc = '����', 
		},

		{
			field = 'createTime',
			attr = 'int(10) unsigned NOT NULL',
			desc = 'ʱ��',
		},
	},
	

	----------------
	--ΨһID����
	{
		name = 'uuids', -- xsg_uuid_table
		table_name = 'uuids', -- 
		output_file = 'c:/myweb/sql/uuids.sql',
		{
			field = 'id',
			attr = 'int(10) unsigned NOT NULL auto_increment',
			keytype = 'UNIQUE',
			desc = '�����ӵ�id',
		},
		
		{
			field = 'name',
			attr = 'varchar(100) NOT NULL',
			keytype = 'PRIMARY',
			desc = 'ID������',
		},
		
		{
			field = 'uuid',
			attr = 'bigint(20) unsigned NOT NULL',
			desc = 'ΨһID',
		},
		
		append_sql = [[
			LOCK TABLES `uuids` WRITE;
			INSERT INTO uuids VALUES('', 'allianceId', '1');
			INSERT INTO uuids VALUES('', 'armyId', '1');
			INSERT INTO uuids VALUES('', 'itemId', '1');
			INSERT INTO uuids VALUES('', 'mailId', '1');
			UNLOCK TABLES;
		]]
	},
	
	----------------
	--Ŀ¼������
	--[[
	{
		name = 'dirs',
		table_id = 0,
		table_name = 'dirs',
		output_file = 'c:/myweb/sql/dirs.sql',
		{
			field = 'id',
			attr = 'int(10) unsigned NOT NULL',
			keytype = 'PRIMARY',
			desc = '������ΨһID',
		},
		
		{
			field = 'name',
			attr = 'varchar(21) NOT NULL',
			desc = '����������', 
		},
		
		{
			field = 'url',
			attr = 'varchar(100) NOT NULL',
			desc = '������url', 
		},
	},	
	]]
	
	-----------------------
	--��¼��Ϣ���ݿ�
	--[[
	{
		name = 'logins',
		table_id = 0,
		table_name = 'logins',
		output_file = 'c:/myweb/sql/logins.sql',
		{
			field = 'id',
			attr = 'int(10) unsigned NOT NULL',
			keytype = 'PRIMARY',
		},
		
		{
			field = 'uname',
			attr = 'varchar(32) NOT NULL',
			desc = '�û���', 
		},
		
		{
			field = 'lastsvr',
			attr = 'int(10) unsigned NOT NULL',
			desc = '�����¼������id', 
		},
		
		{
			field = 'regsvrs',
			attr = 'BLOB',
			desc = '���û���ע��ķ�����id�б�', 
		},
	},
	]]
	
	--��Ҽ��ս��״̬���ݿ�
	{
		name = 'fightstates',
		table_id = 0,
		table_name = 'fightstates',
		output_file = 'c:/myweb/sql/fightstates.sql',
		{
			field = 'id',
			attr = 'bigint(20) unsigned NOT NULL',
			desc = '�ؼ�id',
			keytype = 'PRIMARY',
		},
		{
			field = 'roleId1',
			attr = 'bigint(20) unsigned NOT NULL',
			desc = '��ɫ��id',
		},
		{
			field = 'roleId2',
			attr = 'bigint(20) unsigned NOT NULL',
			desc = '��ɫ��id',
		},
		{
			field = 'fightState',
			attr = 'tinyint(3) unsigned NOT NULL',
			desc = 'ս��״̬',
		},
		{
			field = 'stopTime',
			attr = 'int(10) unsigned NOT NULL',
			desc = '����ʱ��',
		},
	},
	
	--cdkey���ݿ�
	{
		name = 'cdkey',
		table_id = 0,
		table_name = 'cdkey',
		output_file = 'c:/myweb/sql/cdkey.sql',
		{
			field = 'cdkey',
			attr = 'varchar(21) NOT NULL',
			desc = 'cdkey',
			keytype = 'PRIMARY',
		},
		{
			field = 'type',
			attr = 'int(10) unsigned NOT NULL',
			desc = 'cdkey���',
		},
		{
			field = 'resid',
			attr = 'int(10) unsigned NOT NULL',
			desc = '���id',
		},
		{
			field = 'number',
			attr = 'int(10) unsigned NOT NULL',
			desc = '�������',
		},
		{
			field = 'createTime',
			attr = 'int(10) unsigned NOT NULL',
			desc = '����ʱ��',
		},
		{
			field = 'isUsed',
			attr = 'tinyint(3) unsigned NOT NULL',
			desc = '�Ƿ�ʹ��',
		},
	},
	
	--32wan������
	{
		name = 'wan32order',
		table_id = 0,
		table_name = 'wan32order',
		output_file = 'c:/myweb/sql/wan32order.sql',
		{
			field = 'orderno',
			attr = 'varchar(32) NOT NULL',
			desc = 'orderno',
			keytype = 'PRIMARY',
		},
		{
			field = 'name',
			attr = 'varchar(21) NOT NULL',
			desc = '��ɫ��',
		},
		{
			field = 'gold',
			attr = 'int(10) unsigned NOT NULL',
			desc = '���',
		},
	},
	
	-- ��ɫ����
	{
		name = 'rolerank',
		table_id = 0,
		table_name = 'rolerank',
		output_file = 'c:/myweb/sql/rolerank.sql',
		{
			field = 'roleid',
			attr = 'bigint(20) unsigned NOT NULL',
			keytype = 'PRIMARY',
			desc = '��ɫΨһid',
		},
		{
			field = 'roleName',
			attr = 'varchar(21) NOT NULL',
			keytype = 'UNIQUE',
			desc = '��ɫ��',
		},
		{
			field = 'lastWorldBossHurt',
			attr = 'int(10) unsigned NOT NULL',
			desc = '����boss�������˺�',
		},
		{
			field = 'curWorldBossHurt',
			attr = 'int(10) unsigned NOT NULL',
			desc = '����boss�Ľ����˺�',
		},
		{
			field = 'worldBossRank',
			attr = 'int(10) unsigned NOT NULL',
			desc = '����boss���˺���������',
		},
	},
	
	-- ��������
	{
		name = 'allirank',
		table_id = 0,
		table_name = 'allirank',
		output_file = 'c:/myweb/sql/allirank.sql',
		{
			field = 'alliid',
			attr = 'bigint(20) unsigned NOT NULL',
			keytype = 'PRIMARY',
			desc = '����Ψһid',
		},
		{
			field = 'alliName',
			attr = 'varchar(21) NOT NULL',
			desc = '��������',
		},
		{
			field = 'lastWorldBossHurt',
			attr = 'bigint(20) unsigned NOT NULL',
			desc = '����boss�������˺�',
		},
		{
			field = 'curWorldBossHurt',
			attr = 'bigint(20) unsigned NOT NULL',
			desc = '����boss�Ľ����˺�',
		},
		{
			field = 'worldBossRank',
			attr = 'int(10) unsigned NOT NULL',
			desc = '����boss���˺�����',
		},
	},
		
	-- ��������
	{
		name = 'countryrank',
		table_id = 0,
		table_name = 'countryrank',
		output_file = 'c:/myweb/sql/countryrank.sql',
		{
			field = 'id',
			attr = 'int(10) unsigned NOT NULL',
			keytype = 'PRIMARY',
			desc = 'id',
		},
		{
			field = 'country',
			attr = 'varchar(21) NOT NULL',
			desc = '��������',
		},
		{
			field = 'weekWorldBossHurt',
			attr = 'bigint(20) unsigned NOT NULL',
			desc = '����boss�������˺�',
		},
		{
			field = 'curWorldBossHurt',
			attr = 'bigint(20) unsigned NOT NULL',
			desc = '����boss�Ľ����˺�',
		},
		{
			field = 'lastWorldBossHurtTimes',
			attr = 'int(10) unsigned NOT NULL',
			desc = '����boss�����ܵĻ�ɱ����',
		},
		{
			field = 'curWorldBossHurtTimes',
			attr = 'int(10) unsigned NOT NULL',
			desc = '����boss�ı��ܵĻ�ɱ����',
		},
		{
			field = 'worldBossRank',
			attr = 'int(10) unsigned NOT NULL',
			desc = '����boss���˺�����',
		},
		
		append_sql = [[
			LOCK TABLES `countryrank` WRITE;
			INSERT INTO countryrank VALUES('9900001', 'wei', '0', '0', '0', '0', '0');
			INSERT INTO countryrank VALUES('9900002', 'shu', '0', '0', '0', '0', '0');
			INSERT INTO countryrank VALUES('9900003', 'wu', '0', '0', '0', '0', '0');
			UNLOCK TABLES;
		]],
	},
	
	-- ����ˢ��ʱ��
	{
		name = 'rankrefresh',
		table_id = 0,
		table_name = 'rankrefresh',
		output_file = 'c:/myweb/sql/rankrefresh.sql',
		{
			field = 'id',
			attr = 'int(10) unsigned NOT NULL auto_increment',
			keytype = 'PRIMARY',
			desc = 'jid',
		},
		{
			field = 'name',
			attr = 'varchar(21) NOT NULL',
			keytype = 'UNIQUE',
			desc = '��������',
		},
		{
			field = 'refreshTime',
			attr = 'int(10) unsigned NOT NULL',
			desc = '����ÿ��ˢ��ʱ��',
		},
		{
			field = 'sortTime',
			attr = 'int(10) unsigned NOT NULL',
			desc = '����ʱ��,�������������ֵ��refreshTime��ͬ', 
		},
		{
			field = 'sortTimes',
			attr = 'int(10) unsigned NOT NULL',
			desc = '�����Ĵ���', 
		},
	},
	
	-- gms
	{
		name = 'gms',
		table_id = 0,
		table_name = 'gms',
		output_file = 'c:/myweb/sql/gms.sql',
		{
			field = 'name',
			attr = 'varchar(33) NOT NULL',
			keytype = 'PRIMARY',
			desc = '�û���',
		},
		{
			field = 'flag',
			attr = 'int(10) unsigned NOT NULL',
			desc = '�����־',
		},
	},
	
	-- svrvar
	{
		name = 'svrvar',
		table_id = 0,
		table_name = 'svrvar',
		output_file = 'c:/myweb/sql/svrvar.sql',
		{
			field = 'name',
			attr = 'varchar(33) NOT NULL',
			keytype = 'PRIMARY',
			desc = '������',
		},
		{
			field = 'var',
			attr = 'int(10) unsigned NOT NULL',
			desc = '����ֵ',
		},
	},
	
	--guestsmap
	{
		name = 'guestsmap',
		table_id = 0,
		table_name = 'guestsmap',
		output_file = 'c:/myweb/sql/guestsmap.sql',
		{
			field = 'userName',
			attr = 'varchar(32) NOT NULL',
			keytype = 'PRIMARY',
			desc = '�û�����',
		},
		{
			field = 'guestName',
			attr = 'varchar(32) NOT NULL',
			desc = '�ο�����', -- ��serverʵ�ʵ�����
		},
	},
	
	--guests
	--����guestsmap��ӳ����ɺ���Ӹñ���ɾ��
	--��ʱ�����ñ�ɾ�������ߵ�
	{
		name = 'guests',
		table_id = 0,
		table_name = 'guests',
		output_file = 'c:/myweb/sql/guests.sql',
		{
			field = 'id',
			attr = 'int(10) unsigned NOT NULL auto_increment',
			keytype = 'UNIQUE',
			desc = '�����ӵ�id',
		},
		{
			field = 'guestName',
			attr = 'varchar(32) NOT NULL',
			keytype = 'PRIMARY',
			desc = '�ο�����',
		},
	},
	
	--for [users] db
	--userlogins
	{
		name = 'userlogins',
		table_id = 0,
		table_name = 'userlogins',
		output_file = 'c:/myweb/sql/userlogins.sql',
		{
			field = 'id',
			attr = 'int(10) unsigned NOT NULL auto_increment',
			keytype = 'UNIQUE',
			desc = '�����ӵ�id',
		},
		{
			field = 'user',
			attr = 'varchar(32) NOT NULL',
			keytype = 'PRIMARY',
			desc = '�û���',
		},
		{
			field = 'password',
			attr = 'varchar(32) NOT NULL',
			desc = '����',
		},
		{
			field = 'mail',
			attr = 'varchar(50) NOT NULL',
			desc = '����',
		},
		{
			field = 'regtime',
			attr = 'int(10) unsigned NOT NULL',
			desc = 'ע��ʱ��',
		},
	},
	
	--for [kzsg-dirs] db
	--dirs
	{
		name = 'dirs',
		table_id = 0,
		table_name = 'dirs',
		output_file = 'c:/myweb/sql/dirs.sql',
		{
			field = 'serverid',
			attr = 'int(10) unsigned NOT NULL',
			keytype = 'PRIMARY',
			desc = 'serverid',
		},
		{
			field = 'name',
			attr = 'varchar(32) NOT NULL',
			desc = '��������',
		},
		{
			field = 'url',
			attr = 'varchar(256) NOT NULL',
			desc = '·��',
		},
		{
			field = 'state',
			attr = 'tinyint(3) unsigned NOT NULL',
			desc = '״̬',
		},
		{
			field = 'recommendflag',
			attr = 'tinyint(3) unsigned NOT NULL',
			desc = '�Ƽ�',
		},
		{
			field = 'fulflag',
			attr = 'tinyint(3) unsigned NOT NULL',
			desc = '��������',
		},
		{
			field = 'newflag',
			attr = 'tinyint(3) unsigned NOT NULL',
			desc = '�·�����',
		},
	},
	
	--for [kzsg-dirs] db
	--lastlogins
	{
		name = 'lastlogins',
		table_id = 0,
		table_name = 'lastlogins',
		output_file = 'c:/myweb/sql/lastlogins.sql',
		{
			field = 'user',
			attr = 'varchar(32) NOT NULL',
			keytype = 'PRIMARY',
			desc = '�û���',
		},
		{
			field = 'lastserver1',
			attr = 'int(10) unsigned NOT NULL',
			desc = 'lastserver',
		},
		{
			field = 'lastserver2',
			attr = 'int(10) unsigned NOT NULL',
			desc = 'lastserver',
		},
		{
			field = 'lastserver3',
			attr = 'int(10) unsigned NOT NULL',
			desc = 'lastserver',
		},
		{
			field = 'lastserver4',
			attr = 'int(10) unsigned NOT NULL',
			desc = 'lastserver',
		},
		{
			field = 'lastserver5',
			attr = 'int(10) unsigned NOT NULL',
			desc = 'lastserver',
		},
		{
			field = 'lastserver6',
			attr = 'int(10) unsigned NOT NULL',
			desc = 'lastserver',
		},
	}
};

--��������
if package.loaded['db_define'] == nil then
	require('lua_tool.tools')
	output_dbsql(g_dbtb)
end
