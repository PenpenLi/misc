/*
 * DataProcessor.h
 *
 *  Created on: 2013-3-3
 *      Author: qujianbiao
 */

#ifndef DATAPROCESSOR_H_
#define DATAPROCESSOR_H_
#include <commhead.h>

namespace Net {

class DataProcessor {
public:

	/** ͨ���������һ������
	 @param type
	 �����㷨����
	 @param inBuf
	 ��Ҫ���ܵĻ�����
	 @param inBufLen
	 ����ܻ������ĳ���
	 @param key
	 ��������
	 @param outBuf
	 ��ż��ܺ�����ݻ�����
	 @param outBufLen
	 ���ܺ�����ݻ���������
	 @return
	 ����true��false
	 */
	static bool Encrypt(uchar type, const uchar* inBuf, int inBufLen,
			const uchar* key, uchar* outBuf, int *outBufLen);

	/** ͨ���������һ������
	 @param inBuf
	 �������ܵ�ԭʼ���ݻ���
	 @param inBufLen
	 �������ܵ�ԭʼ���ݻ���ĳ���
	 @param key
	 ����ʹ�õ���Կ
	 @param outBuf
	 �������ܵ�Ŀ�����ݻ���
	 @param outBufLen [I/O]
	 �������ܵ�Ŀ�����ݻ���ĳ���,
	 ����Ϊbuf����󳤶�,���Ϊ���ܺ����ݵ�ʵ�ʳ���
	 @return
	 ����true��false
	 */
	static bool Decrypt(const uchar* inBuf, int inBufLen, const uchar* key,
			uchar* outBuf, int *outBufLen);

	/** convert the hex chars to bins */
	static void HexCharsToBins(uchar* outBuf, int* outBufLen, const char *inBuf,
			int inBufLen);

	/** hash the buffer by md5, the out buffer length must be 16 bytes */
	static void Md5HashBuf(uchar* outBuf/*16bytes*/, const uchar *inBuf,
			int inBufLen);

	static int HashString(const char* str);
};

} /* namespace Net */
#endif /* DATAPROCESSOR_H_ */
