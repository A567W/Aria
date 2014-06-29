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
 * @file	KsRingBuffer.h
 * @brief	�����O�o�b�t�@
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
 /************************************************************************************************/
#ifndef __KSRINGBUFFER_H__
#define __KSRINGBUFFER_H__

/*==============================================================================================*/
/*                                 << �C���N���[�h >>                                           */
/*==============================================================================================*/
#include "KsCoreCommon.h"

/*==============================================================================================*/
/*                                     << �錾 >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << ��` >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/**
* @class		KsRingBuffer
* @brief		�����O�o�b�t�@�̃N���X
* @since		2008/02/06
* @author		A567W
*/
/************************************************************************************************/
template < typename T, KsInt32 order > class KsRingBuffer
{
	public:
		/**
		 * �f�[�^���i�[���܂�
		 * @param  T		�i�[����f�[�^
		 */
		void						push( T data )
		{
			m_buffer[ m_pos ] = data;
			if( ++m_pos > order-1 )
			{
				m_pos = 0;
			}
		};
	
		/**
		 * �f�[�^�����o���܂�
		 * @return ��O�i�[�����f�[�^
		 */
		T							pop()
		{
			if( --m_pos < 0 )
			{
				m_pos = order-1;
			}		
			return m_buffer[ m_pos ];
		};

		/**
		 * �w��ԍ��ɋ����I�Ƀf�[�^���i�[����
		 * @param  num		�f�[�^������w��ԍ�
		 * @retval ksTRUE	����
		 * @retval ksFALSE	���s
		 */
		KsBool						insert( KsInt32 num, T data )
		{
			if( num < order )
			{
				m_buffer[ num ] = data;
				return ksTRUE;
			}
			return ksFALSE;
		};
	
		/**
		 * �ߋ��̃f�[�^���擾���܂��B
		 * @param  num �ߋ��̉��Ԗڂ��̃f�[�^�ԍ�
		 * @return �ߋ��̃f�[�^
		 */
		T							getData( KsInt32 num )
		{
			if( num < order )
			{
				KsInt32 index = m_pos - num -1;
				if( index < 0 )
				{
					index += order;
				}
				return m_buffer[ m_pos ];
			}
			return m_buffer[ 0 ];
		};
	
		/**
		 * �R���X�g���N�^
		 */
									KsRingBuffer() : m_pos( 0 ) {}
	
		/**
		 * �f�X�g���N�^
		 */
									~KsRingBuffer() {}
	
		/**
		 * ���݂̃f�[�^�}���ʒu���擾����
		 * @return					�}���ʒu��Ԃ�
		 */
		KsInt32						getPos() { return m_pos; }

	private:
		T							m_buffer[ order ];		/**< �o�b�t�@		*/
		KsInt32						m_pos;					/**< �f�[�^�ʒu	*/
};

ksNS_KS_END

#endif		/* __KSRINGBUFFER_H__ */




