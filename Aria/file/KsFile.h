/*************************************************************************************************/
/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2014 A567W
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 * 
 * @file	KsFile.h
 * @brief	�t�@�C������N���X
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
/************************************************************************************************/
#ifndef __KSFILE_H__
#define __KSFILE_H__

/*===============================================================================================*/
/*                                 << �C���N���[�h >>                                             */
/*===============================================================================================*/
#include "KsFileObject.h"

/*===============================================================================================*/
/*                                     << ��` >>                                                */
/*===============================================================================================*/

/*===============================================================================================*/
/*                                     << �錾 >>                                                */
/*===============================================================================================*/
ksNS_KS_BEGIN

/*************************************************************************************************/
/**
 * @class	KsFile
 * @brief	�t�@�C���N���X
 * @author	A567W
 * @date	2003/11/30
 * @version	1.0.0
 */
/*************************************************************************************************/
class ksENGINE_API KsFile : public KsFileObject
{
	protected:
		FILE*						m_pFile;			/**< �t�@�C���|�C���^		*/

	public:

		/**
		 * �R���X�g���N�^
		 * @param	fullPath		�t�@�C���̃t���p�X
		 * @param	flags			�t�@�C���̃I�[�v���t���O
		 */
									KsFile( const KsString& fullPath, KsInt32 flags );
									
		/**
		 * �R���X�g���N�^
		 * @param	path			�t�@�C���̃p�X
		 * @param	fileName		�t�@�C����
		 * @param	flags			�t�@�C���̃I�[�v���t���O
		 * @param	bOpen			�I�[�v�����邩�ǂ����̃t���O(ksTRUE:���ƃI�[�v������, ksFALSE:���ƃp�X�ƃt�@�C�������Z�b�g���邾��)
		 */
									KsFile( const KsString& path = ksT(""), const KsString& fileName = ksT(""), KsInt32 flags = ksFILE_FLAG_DEFAULT, KsBool bOpen = ksFALSE );

		/**
		 * �f�X�g���N�^
		 * @brief					�t�@�C�����J����Ă��������
		 */
		virtual						~KsFile();
		
		/**
		 * �t�@�C�����J��
 		 * @param	fullPath		�t�@�C���̃t���p�X
		 * @param	flags			�t�@�C���̃I�[�v���t���O
		 * @retval	ksTRUE			����
		 * @retval	ksFALSE			���s
		 */
		virtual KsBool				open( const KsString& fullPath, KsInt32 flags, ksBYTE_ORDER byteOrder=ksLITTLEENDIAN );

		/**
		 * �t�@�C�����J��
		 * @param	path			�t�@�C���̃p�X
		 * @param	fileName		�t�@�C����
		 * @param	flags			�t�@�C���̃I�[�v���t���O
		 * @retval	ksTRUE			����
		 * @retval	ksFALSE			���s
		 */
		virtual KsBool				open( const KsString& path = ksT(""), const KsString& fileName = ksT(""), KsInt32 flags = ksNONE );

		/**
		 * �t�@�C�������
		 */
		virtual void				close();

		/**
		 * �t�@�C���|�C���^���擾����
		 * @return						�t�@�C���|�C���^
		 */
		virtual const void*			getFilePtr() const { return m_pFile; }

		/**
		 * �t�@�C�����J����ėL���ɂȂ��Ă��邩���`�F�b�N����
		 * @retval	ksTRUE			�t�@�C���͊J����Ă���
		 * @retval	ksFALSE			�t�@�C���͊J����Ă��Ȃ�
		 */
		virtual KsBool				isValid() { return ( m_pFile && ( m_state == ksOPEN ) ); }

		/**
		 * �t�@�C�� �|�C���^�̌��݈ʒu���擾����
		 * @return					�t�@�C���擪���猻�݈ʒu�܂ł̃I�t�Z�b�g�A�h���X
		 */
		virtual KsInt32				tell();

		/**
		 * �w�肳�ꂽ�ʒu�Ƀt�@�C�� �|�C���^���ړ�����
		 * @param	offset			�w��ʒu����̃o�C�g��
		 * @param	mode			�w��ʒu
		 * @return					����ɏ������ꂽ�ꍇ�A0 ��Ԃ��܂��B����ȊO�̏ꍇ�� 0 �ȊO�̒l��Ԃ��܂�
		 */
		virtual KsInt32				seek( KsInt32 offset, KsInt32 mode );

		/**
		 * �t�@�C�����畂�������_�̒l��ǂݍ���
		 * @return					���������_�̒l
		 */
		virtual KsReal				readReal();

		/**
		 * �t�@�C������32bit�����l��ǂݍ���
		 * @return					32bit�����l
		 */
		virtual KsInt32				readInt32();

		/**
		 * �t�@�C�����畄���Ȃ�32bit�����l��ǂݍ���
		 * @return					�����Ȃ�32bit�����l
		 */
		virtual KsUInt32			readUInt32();

		/**
		 * �t�@�C������16bit�����l��ǂݍ���
		 * @return					16bit�����l
		 */
		virtual KsInt16				readInt16();

		/**
		 * �t�@�C�����畄���Ȃ�16bit�����l��ǂݍ���
		 * @return					�����Ȃ�16bit�����l
		 */
		virtual KsUInt16			readUInt16();

		/**
		 * �t�@�C������8bit�����l��ǂݍ���
		 * @return					8bit�����l
		 */
		virtual KsInt8				readInt8();

		/**
		 * �t�@�C�����畄���Ȃ�8bit�����l��ǂݍ���
		 * @return					�����Ȃ�8bit�����l
		 */
		virtual KsUInt8				readUInt8();

		/**
		 * �t�@�C������ꕶ����ǂݍ���
		 * @return					�ꕶ�����̒l
		 */
		virtual KsChar				readChar();

		/**
		 * �t�@�C�����畄���Ȃ�8bit�����l��ǂݍ���
		 * @return					�����l
		 */
		virtual KsInt32				readByte();

		/**
		 * �t�@�C�����當�����ǂݍ���
		 * @return					������
		 */
		virtual KsString			readString();

		/**
		 * �G���R�[�h���ꂽ��������ǂݍ���
		 * @return					�ϒ��T�C�Y�̃G���R�[�h���ꂽ 32-bit ������������
		 */
		virtual KsUInt32			readEncodedU32();

		/**
		 * �o�b�t�@�Ɏw��o�C�g�����ǂݍ���
		 * @param	pBuffer			(OUT)�ǂݍ��ނ��߂̃o�b�t�@
		 * @param	count			�ǂݍ��ރo�C�g��
		 * @return					�ǂݍ��񂾃o�C�g��
		 */
		virtual KsSize				read( void *pBuffer, KsInt32 count );

		/**
		 * �t�@�C���ɒl����������
		 * @param	val				�������ޒl
		 * @return					�������񂾃o�C�g��
		 */
		virtual KsSize				writeReal( KsReal val );

		/**
		 * �t�@�C���ɒl����������
		 * @param	val				�������ޒl
		 * @return					�������񂾃o�C�g��
		 */
		virtual KsSize				writeInt32( KsInt32 val );

		/**
		 * �t�@�C���ɒl����������
		 * @param	val				�������ޒl
		 * @return					�������񂾃o�C�g��
		 */
		virtual KsSize				writeUInt32( KsUInt32 val );

		/**
		 * �t�@�C���ɒl����������
		 * @param	val				�������ޒl
		 * @return					�������񂾃o�C�g��
		 */
		virtual KsSize				writeInt16( KsInt16 val );

		/**
		 * �t�@�C���ɒl����������
		 * @param	val				�������ޒl
		 * @return					�������񂾃o�C�g��
		 */
		virtual KsSize				writeUInt16( KsUInt16 val );

		/**
		 * �t�@�C���ɒl����������
		 * @param	val				�������ޒl
		 * @return					�������񂾃o�C�g��
		 */
		virtual KsSize				writeInt8( KsInt8 val );

		/**
		 * �t�@�C���ɒl����������
		 * @param	val				�������ޒl
		 * @return					�������񂾃o�C�g��
		 */
		virtual KsSize				writeUInt8( KsUInt8 val );

		/**
		 * �t�@�C���ɒl����������
		 * @param	val				�������ޒl
		 * @return					�������񂾃o�C�g��
		 */
		virtual KsSize				writeChar( KsChar val );

		/**
		 * �t�@�C���ɒl����������
		 * @param	val				�������ޒl
		 * @return					�������񂾃o�C�g��
		 */
		virtual KsSize				writeByte( KsInt32 val );

		/**
		 * �o�b�t�@����t�@�C���ɒl����������
		 * @param	pBuffer			�������ރo�b�t�@
		 * @param	count			�������ރo�C�g��
		 * @return					�������񂾃o�C�g��
		 */
		virtual KsSize				write( const void *pBuffer, KsInt32 count );

	protected:

		/**
		 * �t���O����t�@�C�����[�h���擾����
		 * @param	flags			�t�@�C�����J�����[�h�t���O
		 * @return					�t�@�C�����J��������̃��[�h
		 */
		KsString					getFileMode( KsUInt32 flags );
};

ksNS_KS_END

#endif /* __KSFILE_H__ */


