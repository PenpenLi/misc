#ifndef _IFILE_H_
#define _IFILE_H_
#include "IInterface.h"


namespace IO {
//tolua_begin

/** �ļ��ӿ�,Ŀǰ֧��UTF8
 */
class IFile: public IInterface {
public:
	/** ���ļ�
	 @param fileName
	 �򿪵��ļ�����
	 @param mod
	 �򿪵�ģʽ
	 @return
	 ����true��false
	 */
	virtual bool Open() = 0;

	/** ��õ�ǰ�ļ��ĳ���
	 */
	virtual int GetLength() = 0;

	/** ��һ������
	 @param buf
	 ������ݵĻ�����
	 @param size
	 һ����¼��Ĵ�С
	 @param count
	 ��ȡ��¼��ĸ���
	 @return
	 ����ʵ�ʶ�ȡ�ĸ���
	 */
	virtual int Read(void* buf, int size, int count) = 0;

	/** дһ������
	 @param buf
	 ���ݻ�����
	 @param size
	 һ����¼��Ĵ�С
	 @param count
	 ��ȡ��¼��ĸ���
	 @return
	 ����ʵ��д��ĸ���
	 */
	virtual int Write(void* buf, int size, int count) = 0;

	/** д��һ��ʽ�ַ���
	 @param fmt
	 ��ʽ��
	 @param ...
	 �ɱ�����б�
	 @return
	 ����ʵ��д����ַ����������ĸ���
	 */
	virtual int Print(const char* fmt, ...) = 0;

	/** ��λ�ļ����α�λ��
	 @param offset
	 �������ʼ���ƫ����
	 @param origin
	 ��ʼ��λ��,������SEEK_SET,SEEK_CUR,SEEK_END
	 @return
	 �������0��ʾ�ɹ�
	 */
	virtual int Seek(long offset, int origin) = 0;

	/** ��ȡ��ǰ�ļ��α��λ��
	 @return
	 ���ص�ǰ�ļ��α�λ��
	 */
	virtual int Tell(void) = 0;

	/** ��ȡ��ǰ�ļ��α��Ƿ��ڽ�β
	 @return
	 �������Ϊ����ֵ��ʾ���ļ���β
	 */
	virtual int Eof(void) = 0;

	/** �رյ�ǰ�ļ�
	 */
	virtual void Close(void) = 0;

	/** ��ȡ�ļ����ͣ��ڲ�ʹ�ã�
	 */
	virtual int GetType() = 0;
};
//tolua_end

}

#endif // _IFILE_H_
