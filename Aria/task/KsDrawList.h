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
 * @file	KsDrawList.h
 * @brief	�`�惊�X�g
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
 /************************************************************************************************/
#ifndef __KSDRAWLIST_H__
#define __KSDRAWLIST_H__

/*==============================================================================================*/
/*                                 << �C���N���[�h >>                                            */
/*==============================================================================================*/
#include "KsTaskCommon.h"
#include "KsDraw.h"

/*==============================================================================================*/
/*                                     << ��` >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << �錾 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/**
 * @class	KsDrawList
 * @brief	�`��^�X�N���X�g
 * @author	A567W
 */
/************************************************************************************************/
class ksENGINE_API KsDrawList
{
		friend class KsDraw;
		friend class KsDrawThread;

	public:
		/**
		 * �R���X�g���N�^
		 * @brief	0�ŏ����������
		 */
											KsDrawList();

		/**
		 * �f�X�g���N�^
		 */
		virtual								~KsDrawList();

		/**
		 * �`��^�X�N��ǉ�����
		 * @param		pDraw				�`��^�X�N
		 */
		void								add( KsDraw* pDraw );

		/**
		 * �`��^�X�N����菜��
		 * @param		pDraw				�`��^�X�N
		 */
		void								remove( KsDraw* pDraw );

		/**
		 * �`�揈��
		 * @param		pRenderContext		�`��R���e�L�X�g
		 */
		void								draw( KsRenderContext* pRenderContext );

	protected:
		KsBool								m_isActive;		/**< �`��A�N�e�B�u�t���O	*/
		KsDraw*								m_pDrawRoot;	/**< �`�惋�[�g			*/
		KsDraw*								m_pDrawLast;	/**< �`�惉�X�g			*/
		KsDrawThread*						m_pDrawThread;	/**< �`��X���b�h			*/
};

ksNS_KS_END

#endif /* __KSDRAWLIST_H__ */

