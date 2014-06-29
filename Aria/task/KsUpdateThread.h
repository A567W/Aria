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
 * @file	KsUpdateThread.h
 * @brief	�X�V�X���b�h����
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
 /************************************************************************************************/
#ifndef __KSUPDATETHREAD_H__
#define __KSUPDATETHREAD_H__

/*==============================================================================================*/
/*                                 << �C���N���[�h >>                                            */
/*==============================================================================================*/
#include "KsTaskCommon.h"
#include "KsUpdateList.h"

/*==============================================================================================*/
/*                                     << ��` >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << �錾 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/*************************************************************************************************/
/**
 * @class	KsUpdateThread
 * @brief	�X�V�X���b�h����
 * @author	A567W
 */
/*************************************************************************************************/
class ksENGINE_API KsUpdateThread
{
	public:
		/**
		 * �R���X�g���N�^
		 * @param	threadNo			�X�V�X���b�h�ԍ�
		 * @param	numOrder			�X�V�I�[�_�[��
		 * @param	numObject			�X�V�I�u�W�F�N�g��
		 */
										KsUpdateThread( KsUInt32 threadNo, KsUInt32 numOrder, KsUInt32 numObject );

		/**
		 * �f�X�g���N�^
		 */
		virtual							~KsUpdateThread();

		/**
		 * �X�V�X���b�h�ԍ����擾����
		 * @return		�X�V�X���b�h�ԍ�
		 */
		KsUInt32						getThreadNo() const { return m_threadNo; }

	protected:
		KsUInt32						m_threadNo;		/**< �X�V�X���b�h�ԍ�		*/
		//KsArray<KsUpdateList>			m_updates;		/**< �X�V�I�u�W�F�N�g�z�� */
};

ksNS_KS_END

#endif /* __KSUPDATETHREAD_H__ */

