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
 * @file	KsUpdateThreadManager.h
 * @brief	�X�V�X���b�h�Ǘ�����
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
 /************************************************************************************************/
#ifndef __KSUPDATETHREADMANAGER_H__
#define __KSUPDATETHREADMANAGER_H__

/*==============================================================================================*/
/*                                 << �C���N���[�h >>                                            */
/*==============================================================================================*/
#include "KsTaskCommon.h"
#include "KsUpdateThread.h"

/*==============================================================================================*/
/*                                     << ��` >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << �錾 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/*************************************************************************************************/
/**
 * @class	KsUpdateThreadManager
 * @brief	�X�V�X���b�h�Ǘ�
 * @author	A567W
 */
/*************************************************************************************************/
class ksENGINE_API KsUpdateThreadManager
{
	public:
		/**
		 * �R���X�g���N�^
		 * @param	threadNo			�X�V�X���b�h�ԍ�
		 * @param	numOrder			�X�V�I�[�_�[��
		 * @param	numObject			�X�V�I�u�W�F�N�g��
		 */
										KsUpdateThreadManager( KsUInt32 threadNo, KsUInt32 numOrder, KsUInt32 numObject );

		/**
		 * �f�X�g���N�^
		 */
		virtual							~KsUpdateThreadManager();

	protected:
		KsUInt32						m_threadNo;		/**< �X�V�X���b�h�ԍ�		*/
		KsArray<KsUpdateThread*>		m_pThreads;		/**< �X�V�I�u�W�F�N�g		*/
};

ksNS_KS_END

#endif /* __KSUPDATETHREADMANAGER_H__ */

