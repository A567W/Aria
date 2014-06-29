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
 * @file	KsMemoryFixedUnit.h
 * @brief	�Œ胁�����Ǘ����j�b�g
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
/************************************************************************************************/
#ifndef __KSMEMORYFIXEDUNIT_H__
#define __KSMEMORYFIXEDUNIT_H__

/*==============================================================================================*/
/*                                 << �C���N���[�h >>                                           */
/*==============================================================================================*/
#include "KsMemoryCommon.h"

/*==============================================================================================*/
/*                                     << ��` >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << �錾 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/**
 * @class		KsMemoryFixedUnit
 * @brief		�Œ胁�����[�}�l�[�W��
 * @since		2005/03/04
 * @author		A567W
 */
/************************************************************************************************/
class ksENGINE_API KsMemoryFixedUnit
{
	public:
		KsMemoryFixedUnit*				m_pPrev;		/**< �O�̃u���b�N�̃|�C���^		*/
		KsMemoryFixedUnit*				m_pNext;		/**< ���̃u���b�N�̃|�C���^		*/
		void*							m_pCurrentAddr;	/**< ���݂̃A�h���X			*/
		void*							m_pStartAddr;	/**< �ŏ��̃A�h���X			*/
		void*							m_pEndAddr;		/**< �I���A�h���X				*/
		KsUInt8							m_dummy[ 44 ];	/**< 64�o�C�g�ɂ��邽�߂̃_�~�[	*/
};

ksNS_KS_END

#endif		/* __KSMEMORYFIXEDUNIT_H__ */

