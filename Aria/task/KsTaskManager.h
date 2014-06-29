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
 * @file	KsTaskManager.h
 * @brief	�^�X�N�Ǘ�
 * @date	2014/04/12
 * @author	A567W
 * @version	1.0.0
 */
/************************************************************************************************/
#ifndef __KSTASKMANAGER_H__
#define __KSTASKMANAGER_H__

/*==============================================================================================*/
/*                                 << �C���N���[�h >>                                            */
/*==============================================================================================*/
#include "KsTaskCommon.h"
#include "KsUpdate.h"
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
 * @class		KsTaskManager
 * @brief		��{�^�X�N�}�l�[�W���N���X
 * @date		2004/10/17
 * @since		2004/10/17
 * @version		0.10
 * @note		�Ȃ�
 */
/************************************************************************************************/
class ksENGINE_API KsTaskManager : public KsSingleton< KsTaskManager >
{
		friend class KsUpdate;
		friend class KsDraw;
		friend class KsTask;

	public:
		/**
		 * �V���O���g���̎Q�Ƃ��擾
		 * @return							�V���O���g���̎Q��
		 */
		static KsTaskManager&				getInstance();
		
		/**
		 * �V���O���g���̃|�C���^���擾
		 * @return							�V���O���g���̃|�C���^
		 */
		static KsTaskManager*				getInstancePtr();

	public:
		/**
		 * �R���X�g���N�^
		 * @param		numUpdateList		�X�V���X�g��
		 * @param		numDrawList			�`�惊�X�g��
		 */
											KsTaskManager( KsUInt32 numUpdateList, KsUInt32 numDrawList );

		/**
		 * �f�X�g���N�^
		 */
		virtual								~KsTaskManager();

#if 0
		/**
		 * ���ׂĂ̏��������s
		 * @param		pParam				�����ł킽�����p�����[�^���^�X�N��execute��render�̈����ɓn��
		 *									�f�t�H���g�ł́ANULL���ݒ肳��Ă���B
		 */
		virtual void						run( void* pParam=NULL );

		/**
		 * �X�V����
		 * @param		pParam				�p�����[�^
		 */
		virtual void						execute( void* pParam );

		/**
		 * �`�揈��
		 * @param		pParam				�p�����[�^
		 */
		virtual void						render( void* pParam );

		/**
		 * 
		 */
		virtual void						addTask( KsTask* pTask );

		/**
		 * 
		 */
		virtual void						addUpdate( KsUpdate* pUpdate );

		/**
		 * 
		 */
		virtual void						addDraw( KsDraw* pDraw );


		virtual void						removeTask( KsTask* pTask );

		/**
		 * 
		 */
		virtual void						removeUpdate( KsUpdate* pUpdate );

		/**
		 * 
		 */
		virtual void						removeDraw( KsDraw* pDraw );

		virtual void						destroyTask( KsTask* pTask );

		/**
		 * 
		 */
		virtual void						destroyUpdate( KsUpdate* pUpdate );

		/**
		 * 
		 */
		virtual void						destroyDraw( KsDraw* pDraw );

		virtual void						destroyAll();
	protected:
		/**
		 * �`��J�n
		 */
		virtual void						begineRender();

		/**
		 * �`��I��
		 */
		virtual void						endRender();

	protected:
		KsUpdateThreadManager*				m_pUpdateThreadManager;	/**< �X�V���X�g	*/
		KsDrawThreadManager*				m_pDrawThreadManager;	/**< �`�惊�X�g	*/
#endif
};

ksNS_KS_END

#endif /* __KSTASKMANAGER_H__ */

