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
 * @file	KsStack.h
 * @brief	�X�^�b�N
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
 /************************************************************************************************/
#ifndef __KSSTACK_H__
#define __KSSTACK_H__

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
 * @class		KsStack
 * @brief		�X�^�b�N
 * @author		A567W
 * @date		2004/03/30
 * @version		1.0.0
 */
/************************************************************************************************/
template < typename T, KsUInt32 max > class KsStack
{
	public:
		typedef T						valueType;

	public:
		/**
		 * �R���X�g���N�^
		 */
										KsStack() : m_size( 0 ) {}
	
		/**
		 * �f�X�g���N�^
		 */
										~KsStack() {}

		/**
 		 * �X�^�b�N���󂩂ǂ������`�F�b�N����
		 * @retval		ksTRUE			��ł�
		 * @retval		ksFALSE			�󂶂�Ȃ�
		 */
		KsBool							empty() const { return ( m_size == 0 ); }

		/**
		 * �f�[�^���i�[���܂�
		 * @param		T				�i�[����f�[�^
		 */
		void							push( const T& data )
		{
			if( m_size < max ){
				m_buffer[ m_size++ ] = data;
			}
		}
	
		/**
		 * �f�[�^�����o���܂�
		 * @return						��O�i�[�����f�[�^
		 */
		T&								pop()
		{
			if( m_size > 0 ){
				--m_size;
				return m_buffer[ m_size ];
			}
			return m_buffer[ 0 ];
		}

		/**
		 * �f�[�^�����o���܂�
		 * @return						��O�i�[�����f�[�^
		 */
		const T&						pop() const 
		{
			if( m_size > 0 ){
				--m_size;
				return m_buffer[ m_size ];
			}
			return m_buffer[ 0 ];
		}

		/**
		 * �f�[�^�����o���܂�
		 * @return						��O�i�[�����f�[�^
		 */
		T&								top() 
		{
			if( m_size ){
				m_buffer[ m_size-1 ];
			}
			return m_buffer[ 0 ];
		}

		/**
		 * �f�[�^�����o���܂�
		 * @return						��O�i�[�����f�[�^
		 */
		const T&						top() const
		{
			if( m_size ){
				m_buffer[ m_size-1 ];
			}
			return m_buffer[ 0 ];
		}

		/**
		 * �ߋ��̃f�[�^���擾���܂��B
		 * @param  		num				�ߋ��̉��Ԗڂ��̃f�[�^�ԍ�
		 * @return						�ߋ��̃f�[�^
		 */
		T&								getData( KsUInt32 num )
		{
			KsUInt32	index = m_size - num -1;
		
			if( index ){
				return m_buffer[ index ];
			}
			return m_buffer[ 0 ];
		}

		/**
		 * �ߋ��̃f�[�^���擾���܂��B
		 * @param  		num				�ߋ��̉��Ԗڂ��̃f�[�^�ԍ�
		 * @return						�ߋ��̃f�[�^
		 */
		const T&						getData( KsUInt32 num ) const 
		{
			KsUInt32	index = m_size - num -1;
		
			if( index ){
				return m_buffer[ index ];
			}
			return m_buffer[ 0 ];
		}
	
		/**
		 * �w��C���f�b�N�X�̂̃f�[�^���擾���܂��B
		 * @param		index 			�ߋ��̉��Ԗڂ��̃f�[�^�ԍ�
		 * @return 						�ߋ��̃f�[�^
		 */
		T&								getDataIndex( KsUInt32 index )
		{
			if( index < max ){
				return m_buffer[ index ];
			}
			return m_buffer[ 0 ];
		}

		/**
		 * �w��C���f�b�N�X�̂̃f�[�^���擾���܂��B
		 * @param		index 			�ߋ��̉��Ԗڂ��̃f�[�^�ԍ�
		 * @return 						�ߋ��̃f�[�^
		 */
		const T&						getDataIndex( KsUInt32 index ) const 
		{
			if( index < max ){
				return m_buffer[ index ];
			}
			return m_buffer[ 0 ];
		}
	
		/**
		 * �l��ς���
		 * @param		index			����������f�[�^�̃C���f�b�N�X
		 * @param		data			�f�[�^
		 */
		void							swap( KsUInt32 index, const T& data )
		{
			if( index < max ){
				m_buffer[ index ] = data;
			}
		}
	
		/**
		 * �N���A�[����
		 */
		void							clear() { m_pos = 0; m_size = 0; }

		/**
		 * ���݊i�[����Ă���f�[�^�̐����擾
		 * @return						�i�[����Ă���f�[�^�̐�
		 */
		KsInt32							size()	const { return m_size;	}
	
		/**
		 * �i�[�ł���f�[�^�̐����擾
		 * @return						�i�[�ł���f�[�^�̐�
		 */
		KsInt32							getMax()	const { return max;	}

	private:
		T								m_buffer[ max ];	/**< �o�b�t�@					*/
		KsInt32							m_size;				/**< �i�[����Ă���f�[�^�̐�	*/
};

ksNS_KS_END

#endif	/* __KSSTACK_H__ */
