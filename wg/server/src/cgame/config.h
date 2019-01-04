#ifndef _CONFIG_H_
#define _CONFIG_H_ 
const ulong MAX_CFG_ZONE_CNT = 256;
const ulong MAX_PATH_LEN = 1024;

struct SConfig
{
	/// ���ݿ��ip
	std::string strDBHostIp;
	/// ���ݿ�Ķ˿�
	ushort usDBHostPort;
	/// ��¼���ݿ��û���
	std::string strDBUsername;
	/// ��¼���ݿ������
	std::string strDBPassword;
	/// ��¼�����ݿ�ľ�����
	std::string strDatabase;
	
	SConfig():usDBHostPort(0){}
};

#endif // _CONFIG_H_
