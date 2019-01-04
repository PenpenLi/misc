#ifndef _IFILEMANAGER_H_
#define _IFILEMANAGER_H_
#include "IInterface.h"

// {6179660C-1AA3-49c2-BF70-3A7521CD5352}
static const TQGUID IUID_IFILEMANAGER = { 0x6179660c, 0x1aa3, 0x49c2, { 0xbf,
		0x70, 0x3a, 0x75, 0x21, 0xcd, 0x53, 0x52 } };

namespace IO {
//tolua_begin

/** �ļ����ͱ�־ */
enum EFileFlag {
	/// ���е��ļ�
	FLAG_FILE_PACKAGE = 1,
	/// �ǰ��е��ļ�
	FLAG_FILE_RAW = 2,
};

/** �ļ��������ӿ�,Ŀǰ֧��UTF8
 */
class IFileManager: public IInterface {
public:
	/**������Ȼɢ��Ķ�ȡ���ȼ������,���ȶ���Ȼɢ����ļ���������ʱ�ٶ�pkg�е�
	 * Ĭ��ģʽ�����ȶ�ȡpkg�е��ļ�
	 */
	virtual void SetNatureFileImportant() = 0;

	/** �ڹ����������һ����
	 @param packageName
	 ����·������
	 @return
	 ����true��false
	 */
	virtual bool AddPackage(const char* packageName) = 0;

	/** ��һ���ļ�
	 @param fileName
	 �򿪵��ļ�����
	 @param mod
	 �򿪵�ģʽ
	 @return
	 �����ļ������NULL
	 */
	virtual IFile* OpenFile(const char* fileName, const char* mod) = 0;

	/** �ر��ļ�,ͬʱ�����ͷŸ��ļ�����
	 @param file
	 �ļ�����ָ���ָ��
	 */
	virtual void Close(IFile** file) = 0;

	/** �ж�һ���ļ��Ƿ����
	 @param pathName
	 Ҫ���ҵ��ļ�·����
	 @param flags
	 �ļ������ͱ�־
	 @return
	 ����true��ʾ����
	 */
	virtual bool IsFileExist(const char* pathName,
			unsigned int flags/*=FLAG_FILE_PACKAGE|FLAG_FILE_RAW*/) = 0;

	/** ���һ���ļ����޸�ʱ��
	 */
	virtual uint32 GetFileModifyTime(const char* pathName) = 0;

	/** ���ù���Ŀ¼
	 @param pathName
	 ��ǰ����Ŀ¼
	 */
	virtual void SetWorkPath(const char* pathName) = 0;
};

//tolua_end
}

#endif // _IFILEMANAGER_H_
