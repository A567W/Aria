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
 * @file	KsString.h
 * @brief	�����񑀍�
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
 /************************************************************************************************/
#ifndef __KSSTRING_H__
#define __KSSTRING_H__

/*==============================================================================================*/
/*                                 << �C���N���[�h >>                                            */
/*==============================================================================================*/
#include "KsCoreCommon.h"

/*==============================================================================================*/
/*                                     << ��` >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << �錾 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/**
 * @class		KsString
 * @brief		�����񑀍�
 * @author		A567W
 * @date		2004/03/30
 */
/************************************************************************************************/
class ksENGINE_API KsString
{
	public:
		/**
		 * �R���X�g���N�^
		 */
									KsString();

		/**
		 * �R���X�g���N�^
		 * @param		string		������N���X�̎Q��
		 */
									KsString( const KsString& string );

		/**
		 * �R���X�g���N�^
		 * @param		pString		������̃|�C���^
		 */
									KsString( const KsSChar* pString );

		/**
		 * �R���X�g���N�^
		 * @param		pString		������̃|�C���^
		 */
									KsString( const KsWChar* pString );

		/**
		 * �f�X�g���N�^
		 */
									~KsString();

		/**
		 * ������̒������擾����
		 * @return					������̒���
		 */
		KsUInt32					length() const { return m_length; }

		/**
		 * ������̃o�b�t�@�T�C�Y���擾����
		 * @return					�o�b�t�@�T�C�Y
		 */
		KsUInt32					size() const { return m_size; }

		/**
		 * ������̃o�b�t�@�擾
		 * @return					������̐擪�|�C���^
		 */
		const KsChar*				c_str() const { return m_pString; }

		/**
		 * �󂩂ǂ������`�F�b�N����
		 * @retval		ksTRUE		��ł�
		 * @retval		ksFALSE		��łȂ�
		 */
		KsBool						empty() const { return ( NULL == m_pString ); }

		/**
		 * �w��͈͂̕������폜����
		 * @param		top			����������̐擪
		 * @param		num			����������̐�
		 */
		void						erase( KsUInt32 top, KsUInt32 num );

		/**
		 * ��������N���A
		 */
		void						clear();

		/**
		 * �w��C���f�b�N�X�̕������擾����( operator )
		 * @param	index			�擾����C���f�b�N�X
		 * @return					����
		 */
		KsChar						operator []( KsUInt32 index )		{ return m_pString[ index ]; }
	
		/**
		 * �w��C���f�b�N�X�̕������擾����( operator )
		 * @param	index			�擾����C���f�b�N�X
		 * @return					����
		 */
		const KsChar				operator []( KsUInt32 index ) const { return m_pString[ index ]; }

		KsString&					operator=(const KsString& string );
		KsString&					operator=(const KsSChar* string );
		KsString&					operator=(const KsWChar* string );
		KsString&					operator=(const KsChar c );

		KsString&					operator+=(const KsString& string );
		KsString&					operator+=(const KsChar* string );
		KsString&					operator+=(const KsChar c );

		KsString					operator+(const KsString& string );
		KsString					operator+(const KsChar* pString );
		KsString					operator+(const KsChar c );

		KsBool						operator==( const KsChar* pString ) const { return ( 0 == ks_strcmp( m_pString, pString ) ); }
		KsBool						operator==( const KsString& string ) const { return ( 0 == ks_strcmp( m_pString, string.c_str() ) ); }
	
		KsBool						operator!=( const KsChar* pString ) const { return ks_strcmp( m_pString, pString ); }
		KsBool						operator!=( const KsString& string ) const { return ks_strcmp( m_pString, string.c_str() ); }

	private:
		KsChar*						m_pString;		/**< ������					*/
		KsUInt32					m_length;		/**< ������̒���				*/
		KsUInt32					m_size;			/**< ������o�b�t�@�̃T�C�Y		*/
};

/************************************************************************************************/
/*
 * ���C�h������(WCHAR*)���}���`�o�C�g������(char*)�ɕϊ�
 * @param	wStrW		�ϊ��O������
 * @param	pOut		�ϊ�������i�[�o�b�t�@
 */
/************************************************************************************************/
ksENGINE_API KsUInt32 ks_wcstombs( const KsWChar* wStrW, KsSChar* pOut, KsUInt32 len );

/************************************************************************************************/
/*
 * �}���`�o�C�g������(char*)�����C�h������(WCHAR*)�ɕϊ�
 * @param	wStrW		�ϊ��O������
 * @param	pOut		�ϊ�������i�[�o�b�t�@
 */
/************************************************************************************************/
ksENGINE_API KsUInt32 ks_mbstowcs( const KsSChar* sStr, KsWChar* pOut, KsUInt32 len );

ksNS_KS_END

#endif		/* __KSSTRING_H__ */

