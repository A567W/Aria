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
 * @file	KsUpdateList.h
 * @brief	�X�V���X�g����
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
 /************************************************************************************************/
#ifndef __KSUPDATELIST_H__
#define __KSUPDATELIST_H__

/*==============================================================================================*/
/*                                 << �C���N���[�h >>                                            */
/*==============================================================================================*/
#include "KsTaskCommon.h"
#include "KsUpdate.h"

/*==============================================================================================*/
/*                                     << ��` >>                                               */
/*==============================================================================================*/

/*==============================================================================================*/
/*                                     << �錾 >>                                               */
/*==============================================================================================*/
ksNS_KS_BEGIN

/************************************************************************************************/
/**
 * @class		KsUpdateList
 * @brief		�`��^�X�N���X�g
 * @date		2011/10/17
 * @since		2011/10/17
 * @version		1.0.0
 */
/************************************************************************************************/
class ksENGINE_API KsUpdateList
{
		friend class KsUpdate;
		friend class KsUpdateThread;

	public:
		/**
		 * �R���X�g���N�^
		 * @brief	0�ŏ����������
		 */
											KsUpdateList();

		/**
		 * �f�X�g���N�^
		 */
		virtual								~KsUpdateList();

		/**
		 * �`�悷�邩�ǂ������Z�b�g����
		 * @param		drawActive		�`�悷�邩�ǂ������Z�b�g����
		 */
		void								setActive( KsBool isActive ) { m_isActive = isActive; }

		/**
		 * �`�悷�邩�ǂ������擾����
		 * @return		�`�悷�邩�ǂ������擾����
		 */
		KsBool								isActive() const { return m_isActive; }
		
		/**
		 * �`��^�X�N��ǉ�����
		 * @param		pUpdate				�`��^�X�N
		 */
		void								add( KsUpdate* pUpdate );

		/**
		 * �`��^�X�N����菜��
		 * @param		pUpdate				�`��^�X�N
		 */
		void								remove( KsUpdate* pUpdate );

		/**
		 * �^�X�N��ǉ�����
		 * @param		pUpdate				�`��^�X�N
		 */
		void								update( void* pParam );

	protected:
		KsBool								m_isActive;			/**< �X�V�A�N�e�B�u�t���O		*/
		KsUpdate*							m_pUpdateRoot;		/**< �X�V���[�g				*/
		KsUpdate*							m_pUpdateLast;		/**< �X�V���X�g				*/
		KsUpdateThread*						m_pUpdateThread;	/**< �X�V�X���b�h				*/
};

ksNS_KS_END

#endif /* __KSUPDATELIST_H__ */

