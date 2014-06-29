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
 * @file	KsMemoryFixedBlock.h
 * @brief	�Œ胁�����Ǘ��i�t���[���X�g�j
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
 /************************************************************************************************/
#ifndef __KSMEMORYFIXEDBLOCK_H__
#define __KSMEMORYFIXEDBLOCK_H__

/*==============================================================================================*/
/*                                 << �C���N���[�h >>                                            */
/*==============================================================================================*/
#include "KsMemoryFixedUnit.h"

/*==============================================================================================*/
/*                                     << ��` >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << �錾 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/**
 * @class		KsMemoryFixedBlock
 * @brief		�Œ胁�����[�}�l�[�W��(4�o�C�g�ȏ�łȂ��ƃ_��)
 * @since		2005/03/04
 * @author		A567W
 */
/************************************************************************************************/
class ksENGINE_API KsMemoryFixedBlock
{
	public:
		/**
		 * �R���X�g���N�^
		 */
										KsMemoryFixedBlock();

		/**
		 * �R���X�g���N�^(�u���b�N���X�g�𐶐�����)
		 * @param		elementSize		�v�f�̃T�C�Y
		 * @param		numElement		�v�f��
		 * @param		numBlock		�u���b�N��
		 */
										KsMemoryFixedBlock( KsUInt32 elementSize, KsUInt32 numElement, KsUInt32 numBlock=0 );

		/**
		 * �f�X�g���N�^
		 */
										~KsMemoryFixedBlock();

		/**
		 * �u���b�N���X�g�𐶐�����
		 * @param		elementSize		�v�f�̃T�C�Y
		 * @param		numElement		�v�f��
		 * @param		numBlock		�u���b�N��
		 */
		void							create( KsUInt32 elementSize, KsUInt32 numElement, KsUInt32 numBlock=0 );

		/**
		 * �v�f�����N���A����
		 */
		void							clear();
	
		/**
		 * �j������
		 */
		void							destroy();
	
		/**
		 * �������[�u���b�N�𐶐�����
		 */
		void							createMemoryBlock();
	
		/**
		 * �������[���u���b�N����m�ۂ���
		 */
		void*							alloc();
	
		/**
		 * ���̃��X�g�Ŋm�ۂ��ꂽ�������[���̃`�F�b�N
		 * @retval		ksTRUE			����Ŋm�ۂ��ꂽ������
		 * @retval		ksFALSE			����ȊO�Ŋm�ۂ��ꂽ������
		 */
		KsBool							isBlockListMemory( void* ptr );

	public:
		KsMemoryFixedUnit*				m_pTopBlock;		/**< �擪�u���b�N�̃|�C���^		*/
		KsMemoryFixedUnit*				m_pCurrentBlock;	/**< ���݂̃u���b�N�̃|�C���^	*/
		KsUInt32						m_elementSize;		/**< �v�f�̃T�C�Y				*/
		KsUInt32						m_blockSize;		/**< �u���b�N�T�C�Y			*/
};

ksNS_KS_END


#endif		/* __KSMEMORYFIXEDBLOCK_H__ */

